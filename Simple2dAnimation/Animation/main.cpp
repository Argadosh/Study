#include "SFML/Graphics.hpp"
#include <Windows.h>

#define HEIGTH_WINDOW 500
#define WIDTH_WINDOW 500

int main() {
	sf::RenderWindow window(sf::VideoMode(HEIGTH_WINDOW, WIDTH_WINDOW), "symple 2d animation", sf::Style::Titlebar | sf::Style::Close);

	sf::Texture manTexture;
	manTexture.loadFromFile("1.png");
	sf::Sprite man(manTexture);

	man.setPosition(10, WIDTH_WINDOW / 2);

	int i = 0;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}

		i++;
		switch (i){
		case 1:
			manTexture.loadFromFile("1.png");
			break;
		case 2:
			manTexture.loadFromFile("2.png");
			break;
		case 3:
			manTexture.loadFromFile("3.png");
			break;
		case 4:
			manTexture.loadFromFile("4.png");
			break;
		case 5:
			manTexture.loadFromFile("5.png");
			break;
		case 6:
			manTexture.loadFromFile("6.png");
			break;
		case 7:
			manTexture.loadFromFile("7.png");
			break;
		case 8:
			manTexture.loadFromFile("8.png");
			break;
		case 9:
			manTexture.loadFromFile("9.png");
			break;
		case 10:
			manTexture.loadFromFile("10.png");
			break;
		default:
			i = 0;
			break;
		}

		Sleep(100);
		
		window.clear(sf::Color::White);
		window.draw(man);
		window.display();
	}

	return 0;
}