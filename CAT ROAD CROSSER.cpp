#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Cat {
private:
    Sprite sprite;
    Texture texture;
    float speed;

public:
    Cat(const string& textureFile, float speed, float scale) : speed(speed) {
        if (!texture.loadFromFile(textureFile)) {
            cerr << "Error loading Cat texture" << endl;
        }
