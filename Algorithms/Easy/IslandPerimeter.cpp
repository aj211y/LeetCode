//No.463 - AC
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
    	int ROW = grid.size(), COL = grid[0].size(), ret = 0;

        for(int r=0; r<ROW; r++)
        {
        	for(int c=0; c<COL; c++)
        	{
        		if(grid[r][c] == 1)
        		{
        			if(r == 0 || grid[r-1][c] == 0)
        				ret++;
        			if(r == ROW-1 || grid[r+1][c] == 0)
        				ret++;
        			if(c == 0 || grid[r][c-1] == 0)
        				ret++;
        			if(c == COL-1 || grid[r][c+1] == 0)
        				ret++;
        		}
        	}
        }
        return ret;
    }
};
int main()
{
	vector<vector<int> > grid;
	vector<int> row;
	Solution sol;

	row.push_back(0);
	row.push_back(1);
	row.push_back(0);
	row.push_back(0);
	grid.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(0);
	grid.push_back(row);

	row.clear();
	row.push_back(0);
	row.push_back(1);
	row.push_back(0);
	row.push_back(0);
	grid.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(1);
	row.push_back(0);
	row.push_back(0);
	grid.push_back(row);

	cout << sol.islandPerimeter(grid) << endl;
	return 0;
}