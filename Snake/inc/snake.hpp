#ifndef SNAKE_HPP
#define SNAKE_HPP
#include<SFML/Graphics.hpp>
#include <vector>

class Snake: public sf::Drawable
{   friend class food;
	public:

		Snake();
        Snake(const Snake& snake) = default;
        Snake(Snake&& snake) = delete;
        Snake& operator=(const Snake& snake) = delete;
        Snake& operator=(Snake&& snake) = delete;
		~Snake() override = default;

        void snake_controller_interface();
		void snake_moveUp();
		void snake_moveDown();
		void snake_moveLeft();
		void snake_moveRight();

        bool is_selfBiting();
        bool is_wallhit();
		void snake_updatePos();


		void generate_snakePart();

		void draw(sf::RenderTarget& target, sf::RenderStates state) const override;


	private:

        const float snake_speed{3.f};
		sf::Vector2f snake_vector{0.f,0.f};
        std::vector<sf::RectangleShape> snake_parts;





};

#endif // SNAKE_HPP
