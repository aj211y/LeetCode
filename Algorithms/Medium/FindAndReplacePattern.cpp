//No.890 - AC
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        int len,words_len;
        string w;
        char change,rep;
        len = pattern.length();

        change='A';

        for(int i=0; i<len; i++)
        {
        	if(pattern[i]>='A' && pattern[i] <= change)
        	{
        		continue;
        	}
        	else
        	{
        		rep = pattern[i];
        		replace(pattern.begin(),pattern.end(),rep,change);
        		change+=1;
        	}
        }

        words_len = words.size();
        for(int j=0; j<words_len; j++)
        {
  			w = words[j];
        	change='A';

	        for(int i=0; i<len; i++)
	        {
	        	if(w[i]>='A' && w[i] <= change)
	        	{
	        		continue;
	        	}
	        	else
	        	{
	        		rep = w[i];
	        		replace(w.begin(),w.end(),rep,change);
	        		change+=1;
	        	}
	        }
	        if(w==pattern)
	        	ret.push_back(words[j]);
        }
        return ret;
    }
};
int main()
{
	int n;
	vector<string> words, Ans;
	Solution sol;
	string str, pattern;

	scanf("%d", &n);
	while(n--)
	{
		cin >> str;
		words.push_back(str);
	}
	cin >> pattern;
	Ans = sol.findAndReplacePattern(words, pattern);

	cout << endl;
	for(int i=0; i<Ans.size(); i++)
	{
		cout << Ans[i] << endl;
	}

	return 0;
}