#include <SFML/Graphics.hpp>
namespace gm{

class Game 
{
public:
            Game();
    void    run();
private:
    void    processEvents();
    void    handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void    update(sf::Time deltaTime);
    void    render();
private:
    sf::RenderWindow mWindow;
    sf::CircleShape  mPlayer;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
    float PlayerSpeed;
};
}
int Start();