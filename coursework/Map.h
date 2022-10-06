#pragma once
#include <SFML/Graphics.hpp>
const int HEIGHT_MAP = 33;//������ ����� ������
const int WIDTH_MAP = 60;//������ ����� ������ 

using namespace sf;
const std::string TileMap[HEIGHT_MAP] = {
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"000000000000000000000000000000000000000000000000000000000000",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
};

inline void drawMap(sf::RenderWindow& window);