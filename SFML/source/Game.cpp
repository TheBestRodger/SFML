#include "Game.hpp"
int Start()
{
    gm::Game game;
    game.run();
    return 0;
}
namespace gm{


    Game::Game()
    : mWindow(sf::VideoMode(640, 480), "SFML Application")
    , mPlayer()
    , PlayerSpeed(10.1f)
    {
        mPlayer.setRadius(40.f);
        mPlayer.setPosition(100.f, 100.f);
        mPlayer.setFillColor(sf::Color::Cyan);
    }

    void Game::run()
    {
        sf::Time TimePerFrame = sf::seconds(1.f/60.f);
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while(mWindow.isOpen())
        {
            processEvents();
            timeSinceLastUpdate += clock.restart();
            while(timeSinceLastUpdate > TimePerFrame)
            {
                timeSinceLastUpdate -= TimePerFrame;
                processEvents();
                update(TimePerFrame);
            }

            render();
        }
    }
    void Game::processEvents()
    {
        sf::Event event;
        while(mWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
            }
            if(event.type == sf::Event::Closed)
                mWindow.close();
        }
    }
    void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
    {
        if(key == sf::Keyboard::W)
            mIsMovingUp = isPressed;
        else if (key == sf::Keyboard::S)
            mIsMovingDown = isPressed;
        else if (key == sf::Keyboard::A)
            mIsMovingLeft = isPressed;
        else if (key == sf::Keyboard::D)
            mIsMovingRight = isPressed;
    }
    void Game::update(sf::Time deltaTime)
    {
        sf::Vector2f movement(0.f, 0.f);
        if(mIsMovingUp)
            movement.y -= PlayerSpeed;
        if(mIsMovingDown)
            movement.y += PlayerSpeed;
        if(mIsMovingLeft)
            movement.x -= PlayerSpeed;
        if(mIsMovingRight)
            movement.x += PlayerSpeed;

        mPlayer.move(movement * deltaTime.asSeconds());
    }

    void Game::render()
    {
        mWindow.clear();
        mWindow.draw(mPlayer);
        mWindow.display();
    }

}