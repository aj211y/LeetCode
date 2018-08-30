// No. 657 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;


class Solution {
public:
    bool judgeCircle(string moves) {
        int R=0, L=0, U=0, D=0;
        for(int i=0;i<moves.length();i++)
        {
        	switch(moves[i])
        	{
        		case 'R':
        			R++;
        			break;
        		case 'L':
        			L++;
        			break;
        		case 'U':
        			U++;
        			break;
        		case 'D':
        			D++;
        			break;
        		default:
        			break;
        	}
        }
        if(R==L && U==D)
        	return true;
        else
        	return false;
    }
};
int main()
{
	string str;
	Solution sol;

	cin >> str;
	if(sol.judgeCircle(str))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}