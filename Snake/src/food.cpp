#include "food.hpp"
#include <cstdlib>
#include<time.h>
#include"gamebody.hpp"
#include"snake.hpp"
food::food()
	{

}

void food::generate_food_position(Snake& snake)
    {
        bool is_valid = true;
        srand(time(nullptr));
        food_piece.setSize(sf::Vector2f(GameBody::FOOD_SIZE,GameBody::FOOD_SIZE));
        food_piece.setFillColor(sf::Color::Red);
        food_piece.setOrigin(sf::Vector2f(GameBody::FOOD_SIZE/2,GameBody::FOOD_SIZE/2));
        while(is_valid == true)
        {
            sf::Vector2f food_coordinates(rand()%GameBody::SCREEN_WIDTH - 10,rand()%GameBody::SCREEN_HEIGHT - 10);

            //food_piece.setPosition(food_coordinates);
            for(auto it = snake.snake_parts.begin(); it != snake.snake_parts.end(); it++)
            {
                if((*it).getPosition() == food_coordinates)
                {
                    break;
                }
                food_piece.setPosition(food_coordinates);
                if(it == snake.snake_parts.end() - 1)
                {
                    is_valid = false;
                }
           }

        }


}

void food::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    target.draw(food_piece);
}

