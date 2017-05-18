#include <engine/Config.h>


Config::Config() {
    screenWidth = DEFAULT_SCREEN_WIDTH;
    screenHeight = DEFAULT_SCREEN_HEIGHT;
}

tuple<int, int> Config::getResolution() {
    return { screenWidth, screenHeight }; //make_tuple(screenWidth, screenHeight);
}