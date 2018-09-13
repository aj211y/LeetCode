//No.763 - AC
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
    	vector<int> ret;
    	set<int> list;

    	int first = 0, last = S.find_last_of(S[0]), tmp;
    	list.insert(S[0]);
    	for(int i=0; i<=last; i++)
    	{
    		if(i == last)
    		{
    			ret.push_back(last - first + 1);
    			first = last + 1;
    			last = S.find_last_of(S[first]);
    			list.clear();
    			list.insert(S[first]);
    		}
    		else
    		{
    			if(list.find(S[i]) == list.end())
    			{
	    			tmp = S.find_last_of(S[i]);
	    			if(tmp > last)
	    				last = tmp;
    			} 
    		}
    	}
    	return ret;
    }
};
int main()
{
	string S = "abcabcdefef";
	Solution sol;
	vector<int> Ans;

	Ans = sol.partitionLabels(S);

	for(int i=0; i<Ans.size(); i++)
	{
		cout << Ans[i] << " ";
	}
	return 0;
}