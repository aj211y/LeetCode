//No.292 - AC
#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0)
        	return false;
        else
        	return true;
    }
};
int main()
{
	int n;
	scanf("%d", &n);
	Solution sol;
	if(sol.canWinNim(n))
		cout <<"Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}