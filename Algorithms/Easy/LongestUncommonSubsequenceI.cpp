//No.521 - AC
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
    	if(a == b)
    		return -1;
        return (a.length()>b.length())?a.length():b.length();
    }
};
int main()
{
	string a,b;
	Solution sol;
	cint >> a >> b;
	cout << sol.findLUSlength(a,b) << endl;
	return 0;
}