#ifndef GAMEBODY_HPP
#define GAMEBODY_HPP

#include<SFML/Graphics.hpp>
#include "snake.hpp"
#include "food.hpp"


class GameBody
{
	public:
    GameBody();
    GameBody(const GameBody& window) = delete;
    GameBody(GameBody&& window) = delete;
    GameBody& operator=(const GameBody& window) = delete;
    GameBody& operator=(GameBody&& window) = delete;
    ~GameBody() = default;


		void run_game();

		static const int SCREEN_WIDTH = 800;
		static const int SCREEN_HEIGHT = 600;
        static const int FOOD_SIZE = 20;


	private:
        std::unique_ptr<sf::RenderWindow> _window;
        std::unique_ptr<Snake> _snake;
        std::unique_ptr<food> _food;
        sf::Event event;
        sf::Texture window_texture;
        std::unique_ptr<sf::Sprite> _background;


        bool isEnd();
        bool isSnake_drawn();
        void game_initialize();

};

#endif // GAMEBODY_HPP
