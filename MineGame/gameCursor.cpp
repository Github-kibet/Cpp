#include "gameCursor.h"
#include "util.h"
void gameCursor::draw()
{
	const wchar_t* img = L"��";
	SetColor(10);
	ScreenPrint(m_x, m_y, img);
	SetColor(15);
}