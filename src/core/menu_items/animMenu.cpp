#include <globals.h>
#include "core/display.h"
#include "core/utils.h"
#include "animMenu.h"
#include "core/main_menu.h"
#include <globals.h>


bool homeScreen =1;

void animMenu::optionsMenu() {
    if(homeScreen) {
        options.clear();
        options.push_back({"Apps", gotoApps});
        options.push_back({"Animation Selection", selectAnim});
        options.push_back({"Exit", backToMenu});
        loopOptions(options, true, "animation");
    } else {
        options.clear();
        options.push_back({"Exit to home", gotoHome});
        loopOptions(options, true, "animation");
    }
}

void animMenu::drawIconImg() {
    if(homeScreen) {
        drawImg(*bruceConfig.themeFS(), bruceConfig.getThemeItemImg(bruceConfig.theme.paths.anim), 0, imgCenterY, true);
    } else {
        drawImg(*bruceConfig.themeFS(), bruceConfig.getThemeItemImg(bruceConfig.theme.paths.exit), imgCenterY, true);
    }
}

void animMenu::drawIcon(float scale) {
    clearIconArea();
    if (bruceConfig.animationThemes.empty()) {
        tft.drawString("No animations available", 100, 50, 1);
        return;
    }

    // Select a random animation theme from the list
    size_t randomIndex = random(0, bruceConfig.animationThemes.size());
    String randomAnimation = bruceConfig.animationThemes[randomIndex];

    // Attempt to draw the selected animation
    if (!drawImg(*bruceConfig.themeFS(), randomAnimation, 0, imgCenterY, true)) {
        tft.drawString("Failed to load animation", 100, 50, 1);
    }
}

inline void gotoApps() {
    homeScreen = 0;
}

void selectAnim() {
    FS* fs = nullptr;
    if (setupSdCard()) {
        options = {
            {"Add Animation", [&]() {
                options = {
                    {"SD Card", [&]() {
                        fs = &SD;
                        String filepath = loopSD(*fs, true, "JPG|GIF|PNG");
                        if (!filepath.isEmpty()) {
                            bruceConfig.addAnimationTheme(filepath);
                        }
                    }},
                    {"Internal FS", [&]() {
                        fs = &LittleFS;
                        String filepath = loopSD(*fs, true, "JPG|GIF|PNG");
                        if (!filepath.isEmpty()) {
                            bruceConfig.addAnimationTheme(filepath);
                        }
                    }},
                    {"Back", [&]() {}}
                };
                loopOptions(options);
                String filepath = loopSD(*fs, true, "JPG|GIF|PNG");
                if (!filepath.isEmpty()) {
                    bruceConfig.addAnimationTheme(filepath);
                }
            }},
            {"Remove Animation", [&]() {
                options.clear();
                for (const auto& path : bruceConfig.animationThemes) {
                    options.push_back({path, [&]() { bruceConfig.removeAnimationTheme(path); }});
                }
                options.push_back({"Back", [&]() {}});
                loopOptions(options);
            }},
            {"Default", [&]() { bruceConfig.animationThemes.clear(); bruceConfig.saveFile(); }},
            {"Main Menu", [&]() { fs = nullptr; }}
        };
        loopOptions(options);
    }
    if (fs == nullptr) return;
    bruceConfig.saveFile();
}

inline void gotoHome() {
    homeScreen = 1;
}

bool getHomeScreen() {
    return homeScreen;
}
