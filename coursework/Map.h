#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Map
{
private:
	int height = 32;//размер карты высота
	int width = 32;//размер карты ширина 
	const std::string tileMap[32] = {
	"1                              1",
	"1                              1",
	"111111  11      1111111111111yu1",
	"1       11      111i        1rt1",
	"1       11      11i         1we1",
	"1       11      1i          1111",
	"1    111111111111            o11",
	"1   1                         o1",
	"1   1                          1",
	"1 221                          1",
	"1   1           1111111111111111",
	"1   1                          1",
	"111      1                     1",
	"1 1      1        11           1",
	"1 1      1   11   11           1",
	"1 1      1   11  211    111    1",
	"1 11111111   11   11111111111111",
	"1        1   11                1",
	"1        1   112               1",
	"1        1ppp11             1  1",
	"1        111111111111111111112 1",
	"111                        1   1",
	"11i  1 2                   1   1",
	"11   1              1111   1  21",
	"111111              1      1   1",
	"1i        2      2  1      1   1",
	"100q                1      1   1",
	"1789   2            1  1111111 1",
	"1569              111  1111111 1",
	"1349              1            1",
	"1111111111111111111            1",
	"11111111111111111111111111111111"
	};
	Texture mapTexture;
	Sprite mapSprite;

public:
	Map();
	int getHeight();
	int getWidth();
	char getTileMap(int i, int j);
	void Draw(RenderWindow& window);


};

