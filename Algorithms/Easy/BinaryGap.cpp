//No. 868 - AC
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        int ret = 0, preID = N+1, ID = 1;

        while(N>0)
        {
        	// cout << (N&1) << endl;
        	if((N&1) == 1)
        	{
        		//the first 1 shows up
        		//if(ID-preID < 0)
        		
        		//not the first 1 shows up
        		if(ID-preID > 0)
        		{
        			ret = ((ID-preID)>ret)?(ID-preID):ret;
        			preID = ID;
        		}
        		preID = ID;
        	}
        	N = N >>1;
        	ID++;
        }
        return ret;
    }
};
int main()
{
	int n;
	Solution sol;
	scanf("%d", &n);
	cout << sol.binaryGap(n) << endl;
	return 0;
}