#include "../stdafx.h"

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

*/

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					mark(grid, i, j);
					count++;
				}
			}
		}
		return count;
	}

	void mark(vector<vector<char>>& grid, int row, int col)
	{
		grid[row][col] = '-';
		if (row < grid.size() - 1 && grid[row + 1][col] == '1')
			mark(grid, row + 1, col);
		if (row > 0 && grid[row - 1][col] == '1')
			mark(grid, row - 1, col);
		if (col < grid[row].size() - 1 && grid[row][col + 1] == '1')
			mark(grid, row, col + 1);
		if (col > 0 && grid[row][col - 1] == '1')
			mark(grid, row, col - 1);
	}

};