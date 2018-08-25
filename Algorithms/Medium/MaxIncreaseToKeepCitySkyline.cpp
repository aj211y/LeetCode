//No.807 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int> >& grid) {
       	int len = grid[0].size();
       	int tb[55],lr[55];
       	int M,ret=0,m;

       	//lr max
       	for(int row=0;row<len;row++)
       	{
       		M=0;
       		for(int col=0; col<len; col++)
       		{
       			if(M<grid[row][col])
       				M=grid[row][col];
       		}
       		lr[row]=M;
       	}
       	//tb max
       	for(int col=0;col<len;col++)
       	{
       		M=0;
       		for(int row=0; row<len; row++)
       		{
       			if(M<grid[row][col])
       				M=grid[row][col];
       		}
       		tb[col]=M;
       	}
       	//ans
       	for(int row=0;row<len;row++)
       	{
       		for(int col=0; col<len; col++)
       		{
       			if(lr[row] < tb[col])
       				m=lr[row];
       			else
       				m=tb[col];
       			ret+=m-grid[row][col];
       		}
       	}
       	return ret;
    }
};
int main()
{
	vector<vector <int> > grid;
	vector<int> g;
	Solution sol;
	int n, tmp;

	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		g.clear();
		for(int j=0; j<n; j++)
		{
			scanf("%d", &tmp);
			g.push_back(tmp);
		}
		grid.push_back(g);
	}
	printf("%d\n", sol.maxIncreaseKeepingSkyline(grid));

	return 0;
}