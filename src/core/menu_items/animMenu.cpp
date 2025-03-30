#include <globals.h>
#include "core/display.h"
#include "core/utils.h"
#include "animMenu.h"
#include "core/main_menu.h"

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
        drawImg(*bruceConfig.themeFS(), bruceConfig.getThemeItemImg(bruceConfig.theme.paths.wifi), imgCenterY, true);
    }
}

void animMenu::drawIcon(float scale) {
    clearIconArea();
    tft.drawString("Theme not found", 100, 100, 1);
}

void gotoApps() {
    homeScreen = 0;
}

void selectAnim(){

}

void gotoHome() {
    homeScreen = 1;
}

bool getHomeScreen() {
    return homeScreen;
}
