#pragma once
enum TILETYPE{ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, MINE};
class Tile
{
	int m_x;
	int m_y;
	int m_num;
	bool m_isOpen;
public:
	Tile() {}
	~Tile() {}
	Tile(int x, int y) : m_x(x), m_y(y), m_num(0), m_isOpen(true) {}

	int getTileNum() { return m_num; }
	int getX() { return m_x; }
	int getY() { return m_y; }
	bool isTileOpen() { return m_isOpen; }

	void setTileNum(int num) { m_num = num; }
	void setTileOpen(bool bOpen) { m_isOpen = bOpen; }
	void setXY(int x, int y) { m_x = x; m_y = y; }



	void initTile(int x, int y);
	void draw();
};