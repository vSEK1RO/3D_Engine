#include "src/include/SFML/Graphics.hpp"
#include "cpp/window.h"

int main(){
    sf::Thread window(windowf);
    window.launch();
}