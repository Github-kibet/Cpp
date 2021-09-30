#include "GameMap.h"
#include "util.h"
#include "gameCursor.h"
#include <conio.h>
int main()
{
	int height, width;
	int mineindex;

	cout << "가로 블럭: ";
	cin >> width;
	cout << "세로 블럭: ";
	cin >> height;
	cout << "지뢰 개수: ";
	cin >> mineindex;

	GameMap gameMap(width, height);
	gameMap.setMine(mineindex);

	gameCursor cursor(5, 5);

	ScreenInit();
	bool isContinue = true;
	bool isSuccess = true;
	int openTileNum = 0;

	while (isContinue)
	{
		ScreenClear(gameMap.getWidth(), gameMap.getHeight());

		gameMap.draw();
		cursor.draw();

		int nKey;
		int cursorX;
		int cursorY;
		if (_kbhit())
		{
			nKey = _getch();
			cursorX = cursor.getX();
			cursorY = cursor.getY();

			switch (nKey)
			{
			case UP:
				if (cursorY - 1 >= 0)
					cursor.up();
				break;
			case DOWN:
				if (cursorY + 1 < gameMap.getHeight())
					cursor.down();
				break;
			case LEFT:
				if (cursorX - 1 >= 0)
					cursor.left();
				break;
			case RIGHT:
				if (cursorX + 1 < gameMap.getWidth())
					cursor.right();
				break;
			case SPACE:
				openTileNum = gameMap.openTile(cursorX, cursorY);
				break;
			}
		}

		if (openTileNum == -1)
		{
			isSuccess = false;
			isContinue=false;
		}
		else if (openTileNum == gameMap.getHeight() * gameMap.getWidth()-gameMap.getMinNum())
		{
			isContinue = false;
		}

		ScreenFlipping();
	}

	ScreenRelease();

	if (isSuccess)
		cout << "성공";
	else
		cout << "실패";
	return 0;
}