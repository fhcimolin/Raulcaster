#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

constexpr static auto SCREEN_WIDTH = 640;
constexpr static auto SCREEN_HEIGHT = 480;
constexpr static auto TEX_WIDTH = 64;
constexpr static auto TEX_HEIGHT = 64;

struct Point {
    double x, y;

    friend auto operator+(const Point& p1, const Point& p2) {
        return Point{p1.x + p2.x, p1.y + p2.y};
    }

    friend auto operator-(const Point& p1, const Point& p2) {
        return Point{p1.x - p2.x, p1.y - p2.y};
    }

    auto& operator+=(const Point& other) {
        *this = *this + other;

        return *this;
    }

    auto& operator-=(const Point& other) {
        *this = *this - other;

        return *this;
    }
};

namespace tex
{
    class TextureLoader
    {
    public:
        static constexpr auto TILE_SIZE = 64;

        static sf::Image getImage(std::string name);

        static sf::Texture getTexture(std::string name);
        
        static sf::Sprite getTileFromTexture(sf::Sprite sprite, int position);

        static sf::Sprite getTileFromTextureMatrix(sf::Sprite sprite, int row, int cell);

        static std::vector<unsigned int> getImageAsVectorStripe(sf::Image image);
    };
}

namespace pi
{
    class Text
    {
    private:
        int currentChar;
        int framesSinceTrigger;

        std::string textContent;

        sf::Text text;
        sf::Font font;
    public:
        Text(std::string inputText, sf::Color color, int size);

        bool isTextPrinted();

        void move(float x, float y);
        void setPosition(float x, float y);
        void setText(std::string inputText);
        
        void restartText();

        sf::Text getText();
        sf::Text getTextSpelled(size_t frameDelay);
    };

    class TextPusher
    {
    private:
        int readIndex;
        int framesActive;
        
        std::vector<pi::Text*> textQueue;
        std::vector<pi::Text*> textShown;

        Point origin;
        
        void pushAllTexts();
        void enforceLineLimit();
        void clearAfterTimeLimit();
        void clear();
    public:
        TextPusher();
        ~TextPusher();

        void setOrigin(float x, float y);
        void sendText(std::string inputText);
        void update();

        std::vector<pi::Text*> getTexts();
    };

    class Texture
    {
        private:
            std::map<std::string, sf::Texture> textureMap;
        public:
            Texture();

            sf::Texture getTexture(std::string);
    };
}