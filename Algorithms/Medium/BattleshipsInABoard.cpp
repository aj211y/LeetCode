//No.419 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        int rowLen = board.size(), colLen = board[0].size();
        int ret = 0;

        for(int r=0; r<rowLen; r++)
        {
        	for(int c=0; c<colLen; c++)
        	{
        		if(board[r][c]=='X')
        		{
        			if(((r+1) == rowLen || board[r+1][c]=='.') && ((c+1) == colLen || board[r][c+1]=='.'))
        			{
        				ret++;
        			}
        		}
        	}
        }
        return ret;
    }
};
int main()
{
	int n,m;
	char c;
	vector<char> row;
	vector<vector<char> > board;
	Solution sol;

	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++)
	{
		getchar();
		row.clear();
		for(int j=0; j<m; j++)
		{
			scanf("%c", &c);
			row.push_back(c);
		}
		board.push_back(row);
	}

	cout << sol.countBattleships(board) << endl;
	return 0;
}