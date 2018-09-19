//No.7 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isNeg;
        int ret = 0, tmp;
        if(x<0)
        {
        	isNeg = true;
        	x = -x;
        }
        else
        {
        	isNeg = false;
        }

        while(x>0)
        {
        	tmp = ret*10;
        	// cout << ret << " ";
        	
        	if(tmp/10 != ret)
        	{
        		ret=0;
        		break;
        	}
        	else{
        		tmp = x%10;
	        	ret = ret*10 + tmp;
        	}
        	// cout << ret << endl;
        	x = x/10;
        }
        if(isNeg && ret!=0)
        	ret = -ret;

        return ret;
    }
};

int main()
{
	int x;
	Solution sol;

	scanf("%d", &x);
	cout << sol.reverse(x) << endl;
	return 0;
}