#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC


#include <SFML/Graphics.hpp>
#include <json.h>
#include "MouseManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	//NOTES:
	//MOUSE COLOUR DEVICE TYPES:
	//rgb-1-zone
	//rgb-2-zone

	MouseManager* mouseManager = new MouseManager();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		mouseManager->SetMouseValues(100);
		//window.draw(shape);
		window.display();
	}

	return 0;
}