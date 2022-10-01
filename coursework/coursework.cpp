#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	Clock clock;
	float CurrentFrame = 0;


	setlocale(LC_ALL, "ru");

	RenderWindow window(sf::VideoMode(640, 480), "sfml");

	Texture herotexture;
	herotexture.loadFromFile("images/hero.png");

	Sprite herosprite;
	herosprite.setPosition(100, 100);
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(64, 0, 36, 57));
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		


		if (Keyboard::isKeyPressed(Keyboard::A)) 
		{ 
			float dx = 1;
			if (Keyboard::isKeyPressed(Keyboard::LShift)) dx = 2;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			herosprite.move(-0.1*time*dx, 0); 
			herosprite.setTextureRect(IntRect(64 * int(CurrentFrame), 62, 36, 57));
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) { 
			float dx = 1;
			if (Keyboard::isKeyPressed(Keyboard::LShift)) dx = 2;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			herosprite.move(0.1*time*dx, 0); 
			herosprite.setTextureRect(IntRect(64 * int(CurrentFrame), 127, 36, 57));
		}


		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}