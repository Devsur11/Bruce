#include "main_menu.h"
#include "display.h"
<<<<<<< HEAD

bool homeScreenLocal = getHomeScreen();

MainMenu::MainMenu() {
    //_menuItems.clear();
    //if(getHomeScreen()) {
    //    _menuItems.clear();
    //    _menuItems = {
    //        &AnimMenu,
    //    };
    //}
    //else{
=======
#include <globals.h>

MainMenu::MainMenu() {
    _menuItems = {
        &wifiMenu,
        &bleMenu,
#if !defined(REMOVE_RF_MENU)
        &rfMenu,
#endif
#if !defined(REMOVE_RFID_MENU)
        &rfidMenu,
#endif
        &irMenu,
#if defined(FM_SI4713)
        &fmMenu,
#endif
        &fileMenu,
        &gpsMenu,
#if !defined(REMOVE_NRF_MENU)
        &nrf24Menu,
#endif
#if !defined(LITE_VERSION)
        &scriptsMenu,
#endif
        &othersMenu,
        &clockMenu,
        &connectMenu,
        &configMenu,
    };
>>>>>>> 61b1da2630e8dccbc98c6ba2029f5685ee48ced2

}

MainMenu::~MainMenu() {}

void MainMenu::begin(void) {
<<<<<<< HEAD

    _menuItems.clear();
    _menuItems = {
        &AnimMenu,
    };
    if (!getHomeScreen()) {
        _menuItems.push_back(&wifiMenu);
        _menuItems.push_back(&bleMenu);
    #if !defined(REMOVE_RF_MENU)
        _menuItems.push_back(&rfMenu);
    #endif
    #if !defined(REMOVE_RFID_MENU)
        _menuItems.push_back(&rfidMenu);
    #endif
        _menuItems.push_back(&irMenu);
    #if defined(FM_SI4713)
        _menuItems.push_back(&fmMenu);
    #endif
        _menuItems.push_back(&fileMenu);
        _menuItems.push_back(&gpsMenu);
    #if !defined(REMOVE_NRF_MENU)
        _menuItems.push_back(&nrf24Menu);
    #endif
    #if !defined(LITE_VERSION)
        _menuItems.push_back(&scriptsMenu);
    #endif
        _menuItems.push_back(&othersMenu);
        _menuItems.push_back(&clockMenu);
        _menuItems.push_back(&connectMenu);
        _menuItems.push_back(&configMenu);
    }
    //}


    _totalItems = _menuItems.size();

=======
    returnToMenu = false;
>>>>>>> 61b1da2630e8dccbc98c6ba2029f5685ee48ced2
    options = {};

    std::vector<String> l = bruceConfig.disabledMenus;
    for (int i = 0; i < _totalItems; i++) {
        String itemName = _menuItems[i]->getName();
        if (find(l.begin(), l.end(), itemName) == l.end()) { // If menu item is not disabled
            options.push_back({                              // selected lambda
                               _menuItems[i]->getName(),
                               [=]() { _menuItems[i]->optionsMenu(); },
                               false,                                  // selected = false
                               [](void *menuItem, bool shouldRender) { // render lambda
                                   if (!shouldRender) return false;
                                   drawMainBorder(false);

                                   MenuItemInterface *obj = static_cast<MenuItemInterface *>(menuItem);
                                   float scale = float((float)tftWidth / (float)240);
                                   if (bruceConfig.rotation & 0b01)
                                       scale = float((float)tftHeight / (float)135);
                                   obj->draw(scale);
#if defined(HAS_TOUCH)
                                   TouchFooter();
#endif
                                   return true;
                               },
                               _menuItems[i]
            });
        }
    }
    _currentIndex = loopOptions(options, MENU_TYPE_MAIN, "Main Menu", _currentIndex);
};
