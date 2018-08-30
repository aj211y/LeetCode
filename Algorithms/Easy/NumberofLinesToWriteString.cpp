//No.806 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
    	vector<int> ret;
    	int lines=1, units=0,wID;
        for(int i=0; i<S.length(); i++)
        {
        	wID = S[i]-'a';
        	if(units + widths[wID] >100)
        	{
        		lines++;
        		units = widths[wID];
        	}
        	else
        	{
        		units += widths[wID];
        	}
        }
        ret.push_back(lines);
        ret.push_back(units);

        return ret;
    }
};
int main()
{
	vector<int> widths,Ans;
	int array[26]={4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
	string S;
	Solution sol;

	for(int i=0; i<26; i++)
		widths.push_back(array[i]);

	cin >> S;
	Ans = sol.numberOfLines(widths, S);
	cout << Ans[0] << " " << Ans[1] << endl;
	return 0;
}