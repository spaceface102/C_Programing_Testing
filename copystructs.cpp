#include <SFML/Graphics.hpp>
#include <vector>

struct Outer
{
    struct
    {
        unsigned width;
        unsigned height;
        unsigned cell_size;
    } core_settings;
    
    sf::RectangleShape block;
    struct
    {
        sf::Color alive;
        sf::Color dead;
    } block_settings;

    sf::RenderWindow* window;
};

class Dumb
{
private:
    Outer test;

public:
    Dumb(const Outer testy) : test(testy) {}
};

int main(void)
{
    Outer a, b;
    
    a = b;

    return 0;
}