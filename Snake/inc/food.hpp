#ifndef FOOD_HPP
#define FOOD_HPP
#include<SFML/Graphics.hpp>
#include"snake.hpp"

class food: public sf::Drawable
{
	public:
        food();
        food(const food& food) = delete;
        food(food&& food) = delete;
        food& operator=(const food& food) = delete;
        food& operator=(food&& food) = delete;
        ~food() = default;

        void generate_food_position(Snake& snake);
        void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
      private:
        sf::RectangleShape food_piece;
        bool is_genereated_in_window();




};

#endif // FOOD_HPP
