//No. 771 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
    	int ret=0;
        for(int i=0; i<J.length(); i++)
        {
        	ret += count(S.begin(),S.end(),J[i]);
        }
        return ret;
    }
};

int main()
{
	string J,S;
	Solution sol;
	cin >> J >> S;
	cout << sol.numJewelsInStones(J,S) << endl;
	return 0;
}