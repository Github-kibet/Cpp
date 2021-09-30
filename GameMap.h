#pragma once
#include "Tile.h"
#include <queue>
#include <iostream>
using namespace std;

class GameMap
{
	Tile** m_map;
	int m_width;
	int m_height;
	int m_openTileNum;
	int m_mineNum;
	queue<pair<int, int>> MapNextQ;
public:
	GameMap(){}
	~GameMap() {}
	GameMap(int w, int h) :m_width(w), m_height(h), m_openTileNum(0), m_mineNum(0)
	{
		m_map = new Tile * [h];
		for (int i = 0; i < h; i++)
		{
			m_map[i] = new Tile[w];
		}
		
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				m_map[y][x].initTile(x, y);
			}
		}

	}

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	int getMinNum() { return m_mineNum; }
	int getTileNum(int x, int y) { return m_map[y][x].getTileNum(); }

	void setMine(int mineNum);
	void updateTile(int x, int y);

	void openAllTile();
	int openTile(int x,int y);

	void draw();
};