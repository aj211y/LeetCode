//No.821 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len[10010];
        vector<int> ret, cPos;
        int sLen = S.length();
        for(int i=0; i<sLen; i++)
        {
        	if(S[i] == C)
        	{
        		len[i] = 0;
        		cPos.push_back(i);
        	}
        	else
        	{
        		len[i] = -1;
        	}
        }
        for(int i=0; i<cPos.size(); i++)
        {
        	for(int idLeft = cPos[i]-1, idRight = cPos[i]+1;idLeft>=0 || idRight<sLen;)
        	{
        		if(idLeft>=0)
        		{
        			if(len[idLeft] == 0)
        			{
        				idLeft = -1;
        			}
        			else if(len[idLeft] == -1)
        			{
        				len[idLeft] = len[idLeft+1] + 1;
        				idLeft--;
        			}
        			else
        			{
        				len[idLeft] = (len[idLeft] < len[idLeft+1] + 1)?len[idLeft]:(len[idLeft+1] + 1);
        				idLeft--;
        			}
        		}

        		if(idRight<sLen)
        		{
        			if(len[idRight] == 0)
        			{
        				idRight = sLen;
        			}
        			else if(len[idRight] == -1)
        			{
        				len[idRight] = len[idRight-1] + 1;
        				idRight++;
        			}
        			else
        			{
        				len[idRight] = (len[idRight] < len[idRight-1] + 1)?len[idRight]:(len[idRight - 1] + 1);
        				idRight++;
        			}
        		}
        	}
        }
        for(int i=0; i<sLen; i++)
	    {
	    	ret.push_back(len[i]);
	    }
	    return ret;
    }
};
int main()
{
	vector<int> Ans;
	Solution sol;
	string S;
	char C;

	cin >> S >> C;
	Ans = sol.shortestToChar(S, C);

	for(int i=0; i<Ans.size(); i++)
	{
		cout << Ans[i] << " ";
	}
	return 0;
}