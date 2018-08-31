//No.557 - AC
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
    	string ret="", rev="";
        for(int i=0; i<s.length(); i++)
        {
        	if(s[i] == ' ')
        	{
        		/* Same runtime in two ways */
        		// reverse(rev.begin(),rev.end());
	        	// ret += rev + s[i];
	        	for(int j=rev.length()-1; j>=0; j--)
        			ret += rev[j];
        		ret += " ";
	        	rev = "";  		
        	}
        	else
        	{
        		rev += s[i];
        	}
        }
     //    reverse(rev.begin(),rev.end());
	    // ret += rev;
		for(int j=rev.length()-1; j>=0; j--)
        	ret += rev[j];        
        return ret;
    }
};
int main()
{
	string s;
	Solution sol;
	getline(cin, s);
	cout << sol.reverseWords(s) << endl;
	return 0;
}