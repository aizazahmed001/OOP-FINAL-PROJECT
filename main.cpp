#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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

    void moveLeft() { sprite.move(-speed, 0); }
    void moveRight() { sprite.move(speed, 0); }
    void moveUp() {
        if (sprite.getPosition().y > 0)
        {
            sprite.move(0, -speed);
        }
    }
    void moveDown() {
        if (sprite.getPosition().y + sprite.getGlobalBounds().height < 700)
        {
            sprite.move(0, speed);
        }
    }


    void setSpeed(float newSpeed) { speed = newSpeed; }
    void draw(RenderWindow& window) const { window.draw(sprite); }
    FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); }
    Vector2f getPosition() const { return sprite.getPosition(); }
    void setPosition(const Vector2f& position) { sprite.setPosition(position); }

    FloatRect getRefinedBounds() const {
        FloatRect bounds = sprite.getGlobalBounds();
        return FloatRect(bounds.left + 10, bounds.top + 8, bounds.width - 2 * 10, bounds.height - 2 * 8);
    }
};

class Car {
private:
    Sprite sprite;
    Texture texture;
    float speed;

public:
    Car(const string& textureFile, float x, float y, float speed, float scale) : speed(speed) {
        if (!texture.loadFromFile(textureFile)) {
            cerr << "Error loading car texture" << endl;
        }
        sprite.setTexture(texture);
        sprite.setScale(scale, scale);
        sprite.setPosition(x, y);
    }

    float getSpeed() const { return speed; }
    void move(float dt) { sprite.move(0, speed * dt); }
    void draw(RenderWindow& window) const { window.draw(sprite); }
    FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); }
    void setPosition(const Vector2f& position) { sprite.setPosition(position); }
    Vector2f getPosition() const { return sprite.getPosition(); }

    FloatRect getRefinedBounds() const {
        FloatRect bounds = sprite.getGlobalBounds();
        return FloatRect(bounds.left + 20, bounds.top + 15, bounds.width - 2 * 20, bounds.height - 2 * 15);
    }
};

class Menu {
private:
    Font font;
    Text title;
    RectangleShape startButton, restartButton, quitButton, easyButton, mediumButton, hardButton;
    Text startButtonText, restartButtonText, quitButtonText, easyButtonText, mediumButtonText, hardButtonText;

    Sprite backgroundSprite;
    Texture backgroundTexture;

public:
    Menu() {
        if (!font.loadFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/font/BungeeSpice-Regular.ttf")) {
            cerr << "Error loading font" << endl;
        }
        if (!backgroundTexture.loadFromFile("C:/Users/Aizaz Khan/Downloads/MENUBG.jpg")) {
            cerr << "Error loading menu background texture" << endl;
        }
        backgroundSprite.setTexture(backgroundTexture);

        Vector2u windowSize(825, 700);
        Vector2u textureSize = backgroundTexture.getSize();
        backgroundSprite.setScale(
            static_cast<float>(windowSize.x) / textureSize.x,
            static_cast<float>(windowSize.y) / textureSize.y
        );
        float windowWidth = 825;
        float windowHeight = 700;
        float buttonWidth = 150;
        float buttonHeight = 60;
        float gap = 20;
        float startY = windowHeight / 2 - (buttonHeight + gap) * 2;




        title.setFont(font);
        title.setString("Cat Road Crosser");
        title.setCharacterSize(50);
        title.setFillColor(Color::White);
        title.setPosition(150, 100);


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


        restartButton.setSize(Vector2f(200, 80));
        restartButton.setFillColor(Color::White);
        restartButton.setOutlineThickness(7);
        restartButton.setOutlineColor(Color::Black);
        restartButton.setPosition(300, 300);

        restartButtonText.setFont(font);
        restartButtonText.setString("  Restart");
        restartButtonText.setCharacterSize(22);
        restartButtonText.setFillColor(Color::Black);
        restartButtonText.setPosition(333, 330);


        quitButton.setSize(Vector2f(200, 80));
        quitButton.setFillColor(Color::White);
        quitButton.setOutlineThickness(7);
        quitButton.setOutlineColor(Color::Black);
        quitButton.setPosition(300, 400);

        quitButtonText.setFont(font);
        quitButtonText.setString("Quit");
        quitButtonText.setCharacterSize(22);
        quitButtonText.setFillColor(Color::Black);
        quitButtonText.setPosition(370, 430);

        easyButton.setSize(Vector2f(buttonWidth, buttonHeight));
        easyButton.setFillColor(Color::White);
        easyButton.setOutlineThickness(6);
        easyButton.setOutlineColor(Color::Black);
        easyButton.setPosition((windowWidth - 3 * buttonWidth - 2 * gap) / 2, startY);

        easyButtonText.setFont(font);
        easyButtonText.setString("Easy");
        easyButtonText.setCharacterSize(20);
        easyButtonText.setFillColor(Color::Black);
        easyButtonText.setPosition(
            easyButton.getPosition().x + (buttonWidth - easyButtonText.getLocalBounds().width) / 2,
            easyButton.getPosition().y + (buttonHeight - easyButtonText.getLocalBounds().height) / 2 - 5);



        mediumButton.setSize(Vector2f(buttonWidth, buttonHeight));
        mediumButton.setFillColor(Color::White);
        mediumButton.setOutlineThickness(6);
        mediumButton.setOutlineColor(Color::Black);
        mediumButton.setPosition(easyButton.getPosition().x + buttonWidth + gap, startY);


        mediumButtonText.setFont(font);
        mediumButtonText.setString("Medium");
        mediumButtonText.setCharacterSize(20);
        mediumButtonText.setFillColor(Color::Black);
        mediumButtonText.setPosition(
            mediumButton.getPosition().x + (buttonWidth - mediumButtonText.getLocalBounds().width) / 2,
            mediumButton.getPosition().y + (buttonHeight - mediumButtonText.getLocalBounds().height) / 2 - 5);


        hardButton.setSize(Vector2f(buttonWidth, buttonHeight));
        hardButton.setFillColor(Color::White);
        hardButton.setOutlineThickness(6);
        hardButton.setOutlineColor(Color::Black);
        hardButton.setPosition(mediumButton.getPosition().x + buttonWidth + gap, startY);


        hardButtonText.setFont(font);
        hardButtonText.setString("Hard");
        hardButtonText.setCharacterSize(20);
        hardButtonText.setFillColor(Color::Black);
        hardButtonText.setPosition(
            hardButton.getPosition().x + (buttonWidth - hardButtonText.getLocalBounds().width) / 2,
            hardButton.getPosition().y + (buttonHeight - hardButtonText.getLocalBounds().height) / 2 - 5);

    }

    void drawMenu(RenderWindow& window) const {
        window.draw(backgroundSprite);
    }
    void draw(RenderWindow& window) const {
        window.draw(backgroundSprite);
        window.draw(title);
        window.draw(startButton);
        window.draw(startButtonText);
        window.draw(quitButton);
        window.draw(quitButtonText);
    }
    void drawDifficultyMenu(RenderWindow& window) const {
        window.draw(backgroundSprite);
        window.draw(easyButton);
        window.draw(easyButtonText);
        window.draw(mediumButton);
        window.draw(mediumButtonText);
        window.draw(hardButton);
        window.draw(hardButtonText);
        window.draw(quitButton);
        window.draw(quitButtonText);
    }



    void drawGameOver(RenderWindow& window) const {
        window.draw(backgroundSprite);

        window.draw(restartButton);
        window.draw(restartButtonText);
        window.draw(quitButton);
        window.draw(quitButtonText);
    }

    bool isStartButtonClicked(const Vector2i& mousePos) const {
        return startButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos));
    }

    bool isRestartButtonClicked(const Vector2i& mousePos) const {
        return restartButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos));
    }

    bool isQuitButtonClicked(const Vector2i& mousePos) const {
        return quitButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos));
    }
    bool isEasyButtonClicked(const Vector2i& mousePos) const {
        return easyButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos));
    }

    bool isMediumButtonClicked(const Vector2i& mousePos) const {
        return mediumButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos));
    }

    bool isHardButtonClicked(const Vector2i& mousePos) const {
        return hardButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos));
    }

};

class Raindrop {
private:
    CircleShape raindrop;
    float speed;

public:
    Raindrop(float x, float y, float speed) : speed(speed) {
        raindrop.setRadius(2);
        raindrop.setFillColor(Color::White);
        raindrop.setPosition(x, y);
    }

    void move(float dt) {
        raindrop.move(0, speed * dt);
        if (raindrop.getPosition().y > 700) {
            raindrop.setPosition(raindrop.getPosition().x, -10);
        }
    }

    void draw(RenderWindow& window) const {
        window.draw(raindrop);
    }
};


class Game {
private:
    enum class GameState { MENU, SELECT_DIFFICULTY, RUNNING, GAME_OVER };
    enum class Difficulty { EASY, MEDIUM, HARD };
    Difficulty difficulty = Difficulty::MEDIUM;


    RenderWindow window;
    Cat Cat;
    Car cars[3];
    Texture newCarTextures[3];
    bool carTexturesChanged;
    Texture backgroundTexture;
    Texture roadBackgroundTexture;
    Sprite backgroundSprite;
    bool roadBackgroundActive;
    Menu menu;
    GameState gameState;
    Font font;
    Text gameOverText;
    int score;
    int highScore = 0;
    Text scoreText;
    Image icon;
    vector<Raindrop> raindrops;
    bool raining = false;
    Texture catTexture;
    Music backgroundMusic;
    SoundBuffer collisionBuffer;
    Sound collisionSound;


public:
    Game() : window(VideoMode(825, 700), "Cat Road Crosser"),
        Cat("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/cat1.png", 8.0f, 0.30f),
        cars{
            Car("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/car1.png", 100, 0, 350.0f, 0.3f),
            Car("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/car1.png", 300, -200, 325.0f, 0.3f),
            Car("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/car1.png", 500, -400, 375.0f, 0.3f)
        },


        gameState(GameState::MENU), score(0), roadBackgroundActive(false), carTexturesChanged(true) {
        if (!newCarTextures[0].loadFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/car2.png") ||
            !newCarTextures[1].loadFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/car2.png") ||
            !newCarTextures[2].loadFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/car2.png")) {
            cerr << "Error loading new car textures" << endl;
        }
        for (int i = 0; i < 100; ++i) {
            float x = rand() % 825;
            float y = rand() % 700;
            float speed = 100.0f + rand() % 150;
            raindrops.emplace_back(x, y, speed);
        }

        window.setFramerateLimit(60);
        loadHighScore();

        if (!backgroundMusic.openFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Audio/background_music.ogg")) {
            cerr << "Error loading background music" << endl;
        }
        backgroundMusic.setLoop(true);
        backgroundMusic.play();

        if (!collisionBuffer.loadFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Audio/collision.wav")) {
            cerr << "Error loading collision sound" << endl;
        }
        collisionSound.setBuffer(collisionBuffer);


        if (!icon.loadFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/icon.png")) {
            cerr << "Error loading window icon" << endl;
        }
        else {
            window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
        }

        if (!backgroundTexture.loadFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/Background1.jpg")) {
            cerr << "Error loading background image" << endl;
        }
        if (!roadBackgroundTexture.loadFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/Background2.jpg")) {
            cerr << "Error loading road background image" << endl;
        }
        backgroundSprite.setTexture(backgroundTexture);
        Vector2u windowSize = window.getSize();
        Vector2u textureSize = backgroundTexture.getSize();
        backgroundSprite.setScale(static_cast<float>(windowSize.x) / textureSize.x,
            static_cast<float>(windowSize.y) / textureSize.y);

        if (!font.loadFromFile("C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/font/BungeeSpice-Regular.ttf")) {
            cerr << "Error loading font" << endl;
        }



        gameOverText.setFont(font);
        gameOverText.setCharacterSize(30);
        gameOverText.setFillColor(Color::White);
        gameOverText.setPosition(153, 250);


        scoreText.setFont(font);
        scoreText.setCharacterSize(30);
        scoreText.setFillColor(Color::Yellow);
        scoreText.setOutlineThickness(2);
        scoreText.setOutlineColor(Color::Black);
        scoreText.setPosition(20, 20);
        scoreText.setString("Score: 0");
    }

    void loadHighScore() {
        ifstream file("highscore.txt");
        if (file.is_open()) {
            file >> highScore;
            file.close();
        }
        else {
            highScore = 0;
        }
    }

    void saveHighScore() {
        ofstream file("highscore.txt");
        if (file.is_open()) {
            file << highScore;
            file.close();
        }
    }

    void run() {
        Clock clock;
        while (window.isOpen()) {
            Time deltaTime = clock.restart();
            handleEvents();
            update(deltaTime.asSeconds());
            render();
        }
    }

private:
    void handleEvents() {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (gameState == GameState::MENU) {
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (menu.isStartButtonClicked(Mouse::getPosition(window))) {
                        gameState = GameState::SELECT_DIFFICULTY;
                    }
                    else if (menu.isQuitButtonClicked(Mouse::getPosition(window))) {
                        window.close();
                    }
                }
            }

            if (gameState == GameState::SELECT_DIFFICULTY) {
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (menu.isEasyButtonClicked(Mouse::getPosition(window))) {
                        difficulty = Difficulty::EASY;
                        gameState = GameState::RUNNING;
                    }
                    else if (menu.isMediumButtonClicked(Mouse::getPosition(window))) {
                        difficulty = Difficulty::MEDIUM;
                        gameState = GameState::RUNNING;
                    }
                    else if (menu.isHardButtonClicked(Mouse::getPosition(window))) {
                        difficulty = Difficulty::HARD;
                        gameState = GameState::RUNNING;
                    }
                    else if (menu.isQuitButtonClicked(Mouse::getPosition(window))) {
                        window.close();
                    }
                }
            }
            if (gameState == GameState::RUNNING) {
                if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
                    Cat.moveLeft();
                if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
                    Cat.moveRight();
                if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
                    Cat.moveUp();
                if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
                    Cat.moveDown();
            }

            else if (gameState == GameState::GAME_OVER) {
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (menu.isRestartButtonClicked(Mouse::getPosition(window))) {
                        restartGame();
                    }
                    else if (menu.isQuitButtonClicked(Mouse::getPosition(window))) {
                        window.close();
                    }
                }
            }
        }
    }

    void update(float dt) {
        if (gameState == GameState::RUNNING) {
            float speedMultiplier = 1.0f;
            switch (difficulty) {
            case Difficulty::EASY: speedMultiplier = 0.5f; break;
            case Difficulty::MEDIUM: speedMultiplier = 0.75f; break;
            case Difficulty::HARD: speedMultiplier = 1.0f; break;
            }

            for (auto& car : cars) {
                car.move(dt * speedMultiplier);
                if (car.getPosition().y > 600)
                    car.setPosition(Vector2f(car.getPosition().x, -50));
                if (Cat.getRefinedBounds().intersects(car.getRefinedBounds())) {
                    if (score > highScore) {
                        highScore = score;
                        saveHighScore();
                    }
                    gameOverText.setString(
                        " Game Over!\n"
                        "HIGH SCORE: " + to_string(highScore) + "\n" +
                        "YOUR SCORE: " + to_string(score)
                    );

                    FloatRect textBounds = gameOverText.getLocalBounds();
                    gameOverText.setOrigin(textBounds.width / 2, textBounds.height / 2);
                    gameOverText.setPosition(window.getSize().x / 2, 200);

                    gameState = GameState::GAME_OVER;
                }
            }
        }
        if (Cat.getPosition().x <= 0) {
            score++;
            scoreText.setString("Score: " + to_string(score));

            Cat.setPosition(Vector2f(window.getSize().x - Cat.getGlobalBounds().width, 550));
        }
        if (score >= 5 && !roadBackgroundActive) {
            backgroundSprite.setTexture(roadBackgroundTexture);
            roadBackgroundActive = true;
        }
        if (score >= 5 && !carTexturesChanged) {
            for (int i = 0; i < 3; i++) {
                string textureFile = "C:/Users/Aizaz Khan/Documents/CAT ROAD CROSSER/Textures/car2.png" + to_string(i + 1) + ".png";
                cars[i] = Car(textureFile, cars[i].getPosition().x, cars[i].getPosition().y, cars[i].getSpeed(), 0.3f);
            }
            carTexturesChanged = true;
        }
        if (score >= 10) {
            raining = true;
        }

        if (raining) {
            for (auto& raindrop : raindrops) {
                raindrop.move(dt);
            }
        }
    }
    void render() {
        window.clear();
        window.draw(backgroundSprite);

        if (gameState == GameState::MENU) {
            menu.draw(window);
        }
        else if (gameState == GameState::SELECT_DIFFICULTY) {
            menu.drawDifficultyMenu(window);
        }
        else if (gameState == GameState::RUNNING) {
            Cat.draw(window);
            for (const auto& car : cars)
                car.draw(window);
            window.draw(scoreText);
        }
        else if (gameState == GameState::GAME_OVER) {
            window.draw(gameOverText);
            menu.drawGameOver(window);
        }
        if (raining) {
            for (const auto& raindrop : raindrops) {
                raindrop.draw(window);
            }
        }
        window.display();
    }

    void restartGame() {
        gameState = GameState::SELECT_DIFFICULTY;
        score = 0;
        scoreText.setString("Score: 0");
        Cat.setPosition(Vector2f(700, 550));

        backgroundSprite.setTexture(backgroundTexture);
        roadBackgroundActive = false;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    Game game;
    game.run();
    return 0;
}