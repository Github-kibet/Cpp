#pragma once
class gameCursor
{
	int m_x;
	int m_y;
public :
	gameCursor(int x = 0, int y = 0) :m_x(x), m_y(y) {}
	~gameCursor() {}

	int getX() { return m_x; }
	int getY() { return m_y; }

	void setXY(int x, int y) { m_x = x; m_y = y; }

	void up() { m_y--; }
	void down() { m_y++; }
	void left() { m_x--; }
	void right() { m_x++; }

	void draw();
};