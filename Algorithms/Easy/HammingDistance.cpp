//No.461 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret=0, tmp, bit;
        tmp = (x ^ y);
        for(int i=0; i<32; i++)
        {
        	bit = 1 << i;
        	if((bit & tmp) > 0)
        		ret++;
        }
        return ret;
    }
};

int main()
{
	int x,y;
	Solution sol;
	scanf("%d %d",&x, &y);
	printf("%d\n", sol.hammingDistance(x,y));
	return 0;
}