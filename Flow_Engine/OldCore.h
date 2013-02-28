#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

//Global Variables
std::string PlayerTexture="texture\player.png";

//Main Window


//Manager obiektów
class Object
{
	private:
		sf::Sprite* obj;
		sf::Texture* objTex;
		std::string texpath;
	public:
		Object(std::string tex);
		void createSprite()
		{
			objTex = new sf::Texture();
			(*objTex).loadFromFile(texpath);
			obj = new sf::Sprite(*objTex);
		}
		void drawObject(sf::RenderWindow& target)
		{
			target.draw(*obj);
		}
};

Object::Object(std::string tex)
	: texpath(tex)
{
	void createSprite();
}

//std::vector<Object>::iterator ObjectsIt = Objects.begin();

//Gracz


