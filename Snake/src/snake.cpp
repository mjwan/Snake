#include "snake.hpp"
#include "gamebody.hpp"


Snake::Snake()
	{
		sf::RectangleShape snake_head;

		snake_head.setPosition(sf::Vector2f(GameBody::SCREEN_WIDTH / 2, GameBody::SCREEN_HEIGHT / 2));
        snake_head.setSize(sf::Vector2f(GameBody::FOOD_SIZE,GameBody::FOOD_SIZE));
        snake_head.setOrigin(GameBody::FOOD_SIZE/2, GameBody::FOOD_SIZE/2);

		snake_head.setFillColor(sf::Color::Yellow);

		snake_parts.push_back(snake_head);
	}

void Snake::snake_moveUp()
	{
		snake_vector.y = -snake_speed;
        snake_vector.x = 0;
	}
void Snake::snake_moveDown()
	{
		snake_vector.y = snake_speed;
        snake_vector.x = 0;
	}
void Snake::snake_moveLeft()
	{
		snake_vector.x = -snake_speed;
        snake_vector.y = 0;
	}
void Snake::snake_moveRight()
	{
		snake_vector.x = snake_speed;
        snake_vector.y = 0;
}

bool Snake::is_selfBiting()
{
    const sf::Vector2f head_pos_after_movementl = snake_parts[0].getPosition() + snake_vector;
    const sf::Vector2f *bodyparts;

    for(unsigned int i = 1; i < snake_parts.size(); i++)
        {
            bodyparts = &snake_parts[i].getPosition();
            if(head_pos_after_movementl == *bodyparts)
                {
                    return true;
                }
        }
    return false;


}

bool Snake::is_wallhit()
{
    if(snake_parts[0].getPosition().x > GameBody::SCREEN_WIDTH - 2 || snake_parts[0].getPosition().x < snake_parts[0].getSize().x - 3 ||
            snake_parts[0].getPosition().y > GameBody::SCREEN_HEIGHT - 2 || snake_parts[0].getPosition().y < snake_parts[0].getSize().x - 3)
    {
        return true;
    }
    return false;

}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates state) const
	{
		for(auto it = snake_parts.begin(); it != snake_parts.end(); it++)
			{
				target.draw(*it, state);
			}
	}
void Snake::snake_controller_interface()
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				snake_moveUp();
			}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				snake_moveDown();
			}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				snake_moveLeft();
			}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				snake_moveRight();
			}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				generate_snakePart();
			}
	}

void Snake::generate_snakePart()
	{
        sf::RectangleShape bodyPart;
        bodyPart.setSize(sf::Vector2f(GameBody::FOOD_SIZE,GameBody::FOOD_SIZE));
        bodyPart.setOrigin(GameBody::FOOD_SIZE/2, GameBody::FOOD_SIZE/2);
        bodyPart.setFillColor(sf::Color::Yellow);

        snake_parts.push_back(bodyPart);
	}
void Snake::snake_updatePos()
	{
		snake_controller_interface();
		sf::Vector2f prevPos = snake_parts[0].getPosition();
		snake_parts[0].move(snake_vector);
		for(auto it = (snake_parts.begin()+1); it != snake_parts.end(); it++)
			{
				sf::Vector2f tmp_pos = it->getPosition();
				it->setPosition(prevPos);
				prevPos = tmp_pos;
			}
	}
