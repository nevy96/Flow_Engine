#include "EngineCore.h"

//Global Definitions
Char* Player = new Char;

int main()
{	
	//Window Initialization
	sf::VideoMode VMode(1024, 768, 32);
	sf::RenderWindow window(VMode, "MainWindow", sf::Style::Default);
	window.setVerticalSyncEnabled(true);

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
		window.clear();
		Player->Think(window);
		window.display();
	}
    return 0;
}