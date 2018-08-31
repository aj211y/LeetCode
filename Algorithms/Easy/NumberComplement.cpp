//No.476 - AC
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
    	//If use pow(2,n), the runtime will double or more.
        int ret = 0, digit, power = 1;
        while(num>0)
        {
        	digit = (num & 1);
        	if(!digit)
        	{
        		ret += power;
        	}
        	num = (num >> 1);
        	power = power*2;
        }
        return ret;
    }
};

int main()
{
	int num;
	Solution sol;
	scanf("%d", &num);

	cout << sol.findComplement(num) << endl; 
	return 0;
}