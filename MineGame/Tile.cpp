#include "Tile.h"

void Tile::initTile(int x, int y)
{
	m_x = x;
	m_y = y;
	m_num = 0;
	m_isOpen = false;
}

#include "util.h"
void Tile::draw()
{
	const wchar_t* tileimg[]{ L"¡Û", L"¨ç" ,L"¨è" ,L"¨é" ,L"¨ê" ,L"¨ë",L"¨ì",L"¨í",L"¨î",L"¡Ø",L"¡Ü" };
	if (m_isOpen)
		ScreenPrint(m_x, m_y, tileimg[m_num]);
	else
		ScreenPrint(m_x, m_y, tileimg[10]);
}
