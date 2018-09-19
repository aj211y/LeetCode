//No. 338 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ones;
        int tmp;

        ones.push_back(0); // n = 0

        if(num>0)
	    {
			ones.push_back(1);	//n = 1
			for(int i=2, pre=1; i<=num; i++)
			{
				if(i==pre*2)
				{
					ones.push_back(1);
					pre = i;
				}
				else
				{
					tmp = ones[pre] + ones[i-pre];
					ones.push_back(tmp);
				}
			}		    	
	    }
	    return ones;
    }
};
int main()
{
	int n;
	Solution sol;
	vector<int> Ans;
	scanf("%d", &n);

	Ans = sol.countBits(n);
	for(int i=0; i<Ans.size(); i++)
		cout << Ans[i] << endl;
	return 0;
}