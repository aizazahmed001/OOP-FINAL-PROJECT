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

    }
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


class Menu {
private:
    Font font;
    Text title;
    RectangleShape startButton;
    Text startButtonText;
    RectangleShape restartButton;
    Text restartButtonText;
    RectangleShape quitButton;
    Text quitButtonText;

public:
    Menu() {
        if (!font.loadFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/font/BungeeSpice-Regular.ttf")) {
            cerr << "Error loading font" << endl;
        }

        // Title settings
        title.setFont(font);
        title.setString("Cat Road Crosser");
        title.setCharacterSize(50);
        title.setFillColor(Color::White);
        title.setPosition(150, 100);

        // Start button settings
        startButton.setSize(Vector2f(200, 80));
        startButton.setFillColor(Color::White);
        startButton.setOutlineThickness(7);
        startButton.setOutlineColor(Color::Black);
        startButton.setPosition(300, 300);

        startButtonText.setFont(font);
        startButtonText.setString("Start Game");
        startButtonText.setCharacterSize(20);
        startButtonText.setFillColor(Color::Black);
        startButtonText.setPosition(335, 330);

        // Restart button settings
        restartButton.setSize(Vector2f(230, 80));
        restartButton.setFillColor(Color::White);
        restartButton.setOutlineThickness(7);
        restartButton.setOutlineColor(Color::Black);
        restartButton.setPosition(300, 300);

        restartButtonText.setFont(font);
        restartButtonText.setString("Restart Game");
        restartButtonText.setCharacterSize(20);
        restartButtonText.setFillColor(Color::Black);
        restartButtonText.setPosition(333, 330);

        // Quit button settings
        quitButton.setSize(Vector2f(200, 80));
        quitButton.setFillColor(Color::White);
        quitButton.setOutlineThickness(7);
        quitButton.setOutlineColor(Color::Black);
        quitButton.setPosition(300, 400);

        quitButtonText.setFont(font);
        quitButtonText.setString("Quit");
        quitButtonText.setCharacterSize(20);
        quitButtonText.setFillColor(Color::Black);
        quitButtonText.setPosition(370, 430);
    }
