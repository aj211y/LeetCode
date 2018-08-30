//No.883 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int> >& grid) {
        int len = grid.size();
        int ret = 0, Mside = 0, Mfront = 0;

        for(int i=0; i<len; i++)
        {
        	Mside = 0;
        	Mfront = 0;
        	for(int j=0; j<len; j++)
        	{
        		//Top-Down
        		if(grid[i][j]>0)
        			ret++;
        		//Side
        		if(grid[i][j] > Mside)
        			Mside = grid[i][j];
        		//Front-Back
        		if(grid[j][i] > Mfront)
        			Mfront = grid[j][i];
        	}
        	ret += Mside + Mfront;
        }
        return ret;
    }
};
int main()
{
	int n,num;
	Solution sol;
	vector<vector<int> > grid;
	vector<int> line;

	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		line.clear();
		for(int j=0; j<n;j++)
		{
			scanf("%d", &num);
			line.push_back(num);
		}
		grid.push_back(line);
	}
	cout << sol.projectionArea(grid) << endl;
	return 0;
}