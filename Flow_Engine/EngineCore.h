#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <string>
#include <iostream>

//VARIABLES
static float speed = 1;

class Char
{
	private:
		int health;
		bool isVisible;
		sf::Sprite sprite;
		float weight;
	public:
		Char() //Constructor
		{
			static sf::Texture img;
			if(!img.loadFromFile("textures/player.png")) 
				std::cout<<"Texture Load Failed - Object: Player"<<std::endl;
			sprite.setTexture(img);
			sprite.setPosition(20,20);
			sprite.setScale(0.4, 0.4);
			
			health = 10;
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
			
			target.draw(sprite);
		}
};