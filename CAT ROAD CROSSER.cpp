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
        sprite.setTexture(texture);
        sprite.setScale(scale, scale);
        sprite.setPosition(700, 550);
<<<<<<<<< Temporary merge branch 1
    }
=========
    }
    void moveLeft() { sprite.move(-speed, 0); }
    void moveRight() { sprite.move(speed, 0); }
    void draw(RenderWindow& window) const { window.draw(sprite); }
    FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); }
    Vector2f getPosition() const { return sprite.getPosition(); }
    void setPosition(const Vector2f& position) { sprite.setPosition(position); }

    FloatRect getRefinedBounds() const {
        FloatRect bounds = sprite.getGlobalBounds();
        return FloatRect(bounds.left + 10, bounds.top + 8, bounds.width - 2 * 10, bounds.height - 2 * 8);
    }
};

>>>>>>>>> Temporary merge branch 2
