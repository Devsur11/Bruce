#ifndef ANIM_MENU_H
#define ANIM_MENU_H

#include <MenuItemInterface.h>

class animMenu : public MenuItemInterface {
public:
    animMenu() : MenuItemInterface("animation") {}

    void optionsMenu(void);
    void drawIcon(float scale);
    void drawIconImg();
    bool getTheme() { return bruceConfig.theme.ble; }
};
bool getHomeScreen();

#endif // ANIM_MENU_H
void gotoApps();
void gotoHome();
bool getHomeScreen();
void selectAnim();
