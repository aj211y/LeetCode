//No.344 - AC
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(),s.end());
        return s;
    }
};

int main()
{
	string s;
	Solution sol;
	getline(cin, s);
	cout << sol.reverseString(s) << endl;
	return 0;
}