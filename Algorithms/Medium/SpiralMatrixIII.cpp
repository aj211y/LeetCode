//No. 885 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int> > ret;
        vector<int> coordinate;
        bool visit[R][C];
        int r = r0, c = c0, empty=0;
        int direction = 1; //right = 1, down = 2, left = 3, up = 4
        int times=1, curTimes=1;

        for(int i=0; i<R; i++)
        {
        	for(int j=0; j<C; j++)
        	{
        		visit[i][j]=false;
        	}
        }

        while(curTimes--)
        {
        	// cout << "r: " << r << " " << "c: " << c << endl;
        	// cout << curTimes << endl;
        	if(r>=0 && c>=0 && r<R && c<C && !visit[r][c])
        	{
        		visit[r][c] = true;

	        	coordinate.clear();
	        	coordinate.push_back(r);
	        	coordinate.push_back(c);
	        	ret.push_back(coordinate);
	        }

        	switch(direction){
    			case 1:
    				if(r>=0 && r<R && (c+1)<C)
    				{
    					c=c+1;
    					empty=0;
    				}
    				else
    				{
    					c=c+curTimes+1;
    					curTimes=0;
    					empty++;
    				}
    				break;
        		case 2:
        			if(c>=0 && c<C && (r+1)<R)
        			{
        				r=r+1;
        				empty=0;
        			}
        			else
        			{
        				r=r+curTimes+1;
        				curTimes = 0;
        				empty++;
        			}
        			break;
        		case 3:
        			if(r>=0 && r<R && (c-1)>=0)
        			{
        				c=c-1;
        				empty=0;
        			}
        			else
        			{
        				c=c-curTimes-1;
        				curTimes = 0;
        				empty++;
        			}
        			break;
        		case 4:
        			if(c>=0 && c<C && (r-1)>=0)
        			{
        				r=r-1;
        				empty=0;
        			}
        			else
        			{
        				r=r-curTimes-1;
        				curTimes = 0;
        				empty++;
        			}
        			break;
        		default:
        			break;
    		}

        	if(empty==5)
        		break;
        	if(curTimes==0)//switch direction
        	{
        		switch(direction){
        			case 1:
        				direction = 2;
	        			break;
	        		case 2:
	        			direction = 3;
	        			times++;
	        			break;
	        		case 3:
	        			direction = 4;
	        			break;
	        		case 4:
	        			direction = 1;
	        			times++;
	        			break;
	        		default:
	        			break;
        		}
       			curTimes = times;
        	}
        }
        return ret;
    }
};
int main()
{
	vector<vector<int> > ans;
	Solution sol;

	int R, C, r0, c0;
	scanf("%d %d %d %d", &R, &C, &r0, &c0);

	ans = sol.spiralMatrixIII(R, C, r0, c0);

	for(int i=0; i<ans.size(); i++)
	{
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
	return 0;
}