//No.693 - AC
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
    	int cur = (n&1);

    	n = n >> 1;
        while(n>0)
        {
        	if((n & 1)==cur)
        		return false;
        	else
        		cur = (n & 1);
        	n = n >> 1;
        }
        return true;
    }
};
int main()
{
	int n;
	Solution sol;

	scanf("%d", &n);
	if(sol.hasAlternatingBits(n))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}