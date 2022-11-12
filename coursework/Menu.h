#pragma once
#include <SFML/Graphics.hpp>
void menu(RenderWindow& window) 
{
	Texture menuTexture1, menuTexture2, menuTexture3, menuBackground;
	menuTexture1.loadFromFile("images/menu/1.png");
	menuTexture3.loadFromFile("images/menu/2.png");
	menuBackground.loadFromFile("images/menu/3.jpg");
	Sprite menu1(menuTexture1), menu3(menuTexture3), menuBg(menuBackground);
	bool isMenu = true;
	int menuNum = 0;
	menu1.setPosition(600, 360);
	menu3.setPosition(690, 420);
	menuBg.setPosition(0, 0);

	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(600, 360, 328, 59).contains(Mouse::getPosition(window))) { menu1.setColor(Color(128, 128, 128, 255)); menuNum = 1; }
		if (IntRect(690, 420, 148, 46).contains(Mouse::getPosition(window))) { menu3.setColor(Color(128, 128, 128, 255)); menuNum = 2; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			if (menuNum == 2) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu3);

		window.display();
	}
}