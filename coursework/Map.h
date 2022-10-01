#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Map
{
protected:
	 int width;
	 int height;
public:
	virtual void GenerateMap() = 0;
	Map(int width1, int height1) 
	{
		width = width1;
		height = height1;

	}



};

