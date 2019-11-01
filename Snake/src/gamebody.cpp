#include "gamebody.hpp"
#include "snake.hpp"
#include <memory>
GameBody::GameBody()
	{
        _snake = std::make_unique<Snake>();
        _food = std::make_unique<food>();
        _window = std::make_unique<sf::RenderWindow>();
        _background = std::make_unique<sf::Sprite>();

        game_initialize();

	}

void GameBody::run_game()
	{

        game_initialize();


        while(_window->isOpen())
			{
                while(_window->pollEvent(event))
					{
                        if(event.type == sf::Event::Closed)
							{
                                _window->close();
							}
					}

                _window->clear(sf::Color::Black);
                _window->draw(*_background);
                _food->generate_food_position(*_snake);
                _window->draw(*_food);
                _snake->snake_updatePos();
                _window->draw(*_snake);
                _window->display();
                if(isEnd() == true) break;
        }
}

bool GameBody::isEnd()
{
    if(_snake->is_selfBiting() || _snake->is_wallhit())
    {
        return true;
    }

    return false;
}

void GameBody::game_initialize()
{
    _window->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake");
    _window->setPosition(sf::Vector2i(400,50));
    _window->setVerticalSyncEnabled(true);

    window_texture.loadFromFile("/home/student/Pulpit/Projekt/Snake/Textures/window.jpg");
    _background->setTexture(window_texture);

}
