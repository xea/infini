#ifndef XA_CONFIG_H
#define XA_CONFIG_H

#include <tuple>

using namespace std;

class Config {
private:
    static const int DEFAULT_SCREEN_WIDTH = 880;
    static const int DEFAULT_SCREEN_HEIGHT = 480;
    
    int screenWidth;
    int screenHeight;
public:
    /**
     * Create a new configuration with sensible default values
     */
    Config();

    /**
     * Return the size of the rendering windo   w
     */
    tuple<int, int> getResolution();
};

#endif // XA_CONFIG_H