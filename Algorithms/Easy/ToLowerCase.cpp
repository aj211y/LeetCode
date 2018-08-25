//No. 709 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
    	string ret="";
        for(int i=0; i<str.length(); i++)
        {
        	if(str[i]>=65 && str[i] <=90)
        	{
        		ret+=(str[i]+32);
        	}
        	else
        	{
        		ret+=str[i];
        	}
        }
        return ret;
    }
};

int main()
{
	Solution sol;
	string str;
	cin >> str;
	cout << sol.toLowerCase(str) << endl;
	return 0;
}