#include "EngineCore.h"
//#include "EngineLevels.h"

//Global Definitions

Char* Player = new Char;

int main()
{	
	//Window Initialization
	sf::VideoMode VMode(800, 600, 32);
	sf::RenderWindow window(VMode, "MainWindow", sf::Style::Default);
	window.setFramerateLimit(60);

	//b2Vec2 Gravity(0.f, 9.8f);
    //b2World World(Gravity);

	//TEST LEVEL
	sf::Texture GroundTexture;
	sf::Texture BoxTexture;
	GroundTexture.loadFromFile("textures/ground.png");
	BoxTexture.loadFromFile("textures/box.png");

	//CreateGround(World, 400.f, 500.f);

	//Main Loop
	while(window.isOpen())
	{
		sf::Event WindowEvent;
		while(window.pollEvent(WindowEvent))
		{
			if(WindowEvent.type == sf::Event::Closed) 
				window.close();

			if(WindowEvent.type == sf::Event::KeyPressed && WindowEvent.key.code == sf::Keyboard::Escape) 
				window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
			int MouseX = sf::Mouse::getPosition(window).x;
            int MouseY = sf::Mouse::getPosition(window).y;
            //CreateBox(World, MouseX, MouseY);
        }

		/*World.Step(1/60.f, 8, 3);

		//TEST BEGINS HERE
		window.clear(sf::Color::White);
        for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
            if (BodyIterator->GetType() == b2_dynamicBody)
            {
                sf::Sprite Sprite;
                Sprite.setTexture(BoxTexture);
                Sprite.setOrigin(16.f, 16.f);
                Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
                Sprite.setRotation(BodyIterator->GetAngle() * 180/b2_pi);
                window.draw(Sprite);
            }
            else
            {
                sf::Sprite GroundSprite;
                GroundSprite.setTexture(GroundTexture);
                GroundSprite.setOrigin(400.f, 8.f);
                GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
                GroundSprite.setRotation(180/b2_pi * BodyIterator->GetAngle());
                window.draw(GroundSprite);
            }
        }
        window.display();
		//TEST ENDS HERE*/
		window.clear(sf::Color::White);
		Player->Think(window);
		window.display();
	}
    return 0;
}