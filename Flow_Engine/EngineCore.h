#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <string>
#include <iostream>

//VARIABLES

const float speed = 1;
const float pi = 3.14;

float DegreesToRadians(float degrees) {return pi*degrees/180;}
float RadiansToDegrees(float radians) {return 180*radians/pi;}

enum STATE
{
	STAND,
	WALK,
	RUN,
	JUMP
};

class Char
{
	private:
		int health;
		bool isVisible;
		sf::Sprite sprite;
		float weight;
		int xcenter, ycenter;
		STATE state;
	public:
		Char() //Constructor
		{
			static sf::Texture img;
			if(!img.loadFromFile("textures/test.png")) 
				std::cout<<"Texture Load Failed - Object: Player"<<std::endl;
			sprite.setTexture(img);
			sprite.setPosition(200,200);
			sprite.setScale(0.4, 0.4);

			health = 10;
			state = STAND;
			isVisible = true; //ONLY FOR TESTING
		}
		sf::Sprite getSprite() {return sprite;}
		void Think(sf::RenderWindow &target)
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				sprite.move(0,-speed);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				sprite.move(0,speed);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				sprite.move(-speed,0);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				sprite.move(speed,0);

			if(isVisible) target.draw(sprite);
		}
};