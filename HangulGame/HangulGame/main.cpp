#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
//#include "Box2dSimulation.h"
//#include "BSprite.h"
#include "Pikachu.h"


int main()
{	

	//Box2dSimulation simulation;
	// Render window settings
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	// Render window
	sf::RenderWindow window(sf::VideoMode(1280, 640), "SFML works!", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	//sf::View view1;
	//view1.setSize(1280, 720);
	//view1.setCenter(1280 / 2, 720 / 2);
	//view1.setViewport(sf::FloatRect(0, 0, 0.98F, 0.98F));
	////view1.zoom(0.5f);
	//window.setView(view1);
	//

	//sf::View minimap;
	//minimap.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));

	//view1.setViewport(sf::FloatRect(0.25f, 0.25f, 0.5f, 0.5f));

	//window.setView(view1);
	//window.setView(minimap);

	// background sprite
	sf::Texture texture;
	texture.loadFromFile("../resources/background.png");
	texture.setSmooth(true);
	sf::Sprite background;
	background.setTexture(texture);


	//sf::VertexArray triangle(sf::Triangles, 3);

	//// define the position of the triangle's points
	//triangle[0].position = sf::Vector2f(10, 10);
	//triangle[1].position = sf::Vector2f(100, 10);
	//triangle[2].position = sf::Vector2f(100, 100);

	//// define the color of the triangle's points
	//triangle[0].color = sf::Color::Red;
	//triangle[1].color = sf::Color::Blue;
	//triangle[2].color = sf::Color::Green;

	//std::vector<BSprite*>::iterator spriteIterator;

	Pikachu *p = new Pikachu();
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//float32 x = sf::Mouse::getPosition(window).x;
		//float32 y = sf::Mouse::getPosition(window).y;


		//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		//{
		//	float32 x = sf::Mouse::getPosition(window).x;
		//	float32 y = sf::Mouse::getPosition(window).y;

		//	simulation.add(0, x, y);
		//}
		/*if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			simulation.add(0, x, y);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			simulation.add(1, x, y);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			simulation.add(2, x, y);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			simulation.add(3, x, y);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			simulation.add(4, x, y);
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			simulation.add(5, x, y);

		simulation.step();
		std::vector<BSprite*> sprites = simulation.getBSprites();
*/
		window.clear();

		p->update(event, window);
		window.draw(background);
		window.draw((*p));
		//window.draw(triangle);

		/*for (spriteIterator = sprites.begin(); spriteIterator != sprites.end(); spriteIterator++)
		{
			(*spriteIterator)->update(event, window);
			window.draw((*(*spriteIterator)));
		}*/

		
		window.display();
	}

	return 0;
}