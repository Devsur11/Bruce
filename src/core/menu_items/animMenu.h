#include <MenuItemInterface.h>

class animMenu : public MenuItemInterface {
public:
    animMenu() : MenuItemInterface("animation") {}

    void optionsMenu(void);
    void drawIcon(float scale);
    void drawIconImg();
    bool getTheme() { return bruceConfig.theme.ble; }
};
void selectAnim();
void gotoApps();
void gotoHome();
bool getHomeScreen();
