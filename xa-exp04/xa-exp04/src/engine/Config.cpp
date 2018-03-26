#include <engine/Config.h>


Config::Config() {
    screenWidth = DEFAULT_SCREEN_WIDTH;
    screenHeight = DEFAULT_SCREEN_HEIGHT;
    maximiseWindow = false;
}

tuple<int, int> Config::getResolution() {
    return { screenWidth, screenHeight }; //make_tuple(screenWidth, screenHeight);
}

bool Config::isMaximiseWindow() {
    return maximiseWindow;
}
