#include "GameMap.h"

void GameMap::setMine(int mineNum)
{
	m_mineNum = mineNum;
	for (int i = 0; i < mineNum; i++)
	{
		int x, y;
		do
		{
			x = rand() % m_width;
			y = rand() % m_height;
		}while (m_map[y][x].getTileNum() == MINE);
		updateTile(x, y);
	}
}

void GameMap::updateTile(int x, int y)
{
	for (int curY = y - 1; curY <= y + 1; curY++)
	{
		for (int curX = x - 1; curX <= x + 1; curX++)
		{
			if (curX<0 || curX>m_width - 1 || curY<0 || curY>m_height - 1)
				continue;
			if (curX == x && curY == y)
				m_map[curY][curX].setTileNum(MINE);
			else
			{
				int tileNum = m_map[curY][curX].getTileNum();
				if (tileNum != MINE)
					m_map[curY][curX].setTileNum(tileNum + 1);
			}
		}
	}
}

void GameMap::openAllTile()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			m_map[y][x].setTileOpen(true);
		}
	}
}

int GameMap::openTile(int x, int y)
{
	Tile& curTile = m_map[y][x];
	int dirY[4] = { -1,1,0,0 };
	int dirX[4] = { 0,0,-1,1 };
	int X = x;
	int Y = y;

	if (curTile.getTileNum() == MINE)
	{
		openAllTile();
		return -1;
	}
	else if(!curTile.isTileOpen())
	{
		curTile.setTileOpen(true);
		m_openTileNum++;
	}

	if (curTile.getTileNum() == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			X = x + dirX[i];
			Y = y + dirY[i];
			if (X >= 0 && Y >= 0 && X < m_width && Y < m_height)
			{
				Tile& nowTile = m_map[Y][X];
				if (!nowTile.isTileOpen() && nowTile.getTileNum() !=MINE)
				{
					nowTile.setTileOpen(true);
					m_openTileNum++;
					MapNextQ.push(make_pair(X, Y));
				}
			}
		}
	}

	if (!MapNextQ.empty())
	{
		int x = MapNextQ.front().first;
		int y = MapNextQ.front().second;
		MapNextQ.pop();
		openTile(x,y);
	}
	else
		return m_openTileNum;
}

void GameMap::draw()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			m_map[y][x].draw();
		}
	}
}