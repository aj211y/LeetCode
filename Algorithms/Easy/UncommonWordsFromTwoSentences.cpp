//No.884 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
    	string word="";
    	map<string,int> listA, listB;
    	vector<string> ret;

        for(int i=0; i<A.length(); i++)
        {
        	if(A[i] == ' ')
        	{
        		if(listA.find(word) == listA.end())
        		{
        			listA[word] = 1;
        		}
        		else
        		{
        			listA[word]++;
        		}
        		word = "";
        	}
        	else
        	{
        		word += A[i];
        	}
        }
        if(listA.find(word) == listA.end())
		{
			listA[word] = 1;
		}
		else
		{
			listA[word]++;
		}
        word = "";
        for(int i=0; i<B.length(); i++)
        {
        	if(B[i] == ' ')
        	{
        		if(listB.find(word) == listB.end())
        		{
        			listB[word] = 1;
        		}
        		else
        		{
        			listB[word]++;
        		}
        		word = "";
        	}
        	else
        	{
        		word += B[i];
        	}
        }
        if(listB.find(word) == listB.end())
		{
			listB[word] = 1;
		}
		else
		{
			listB[word]++;
		}

        for(auto elem: listA)
        {
        	if(elem.second == 1 && listB.find(elem.first) == listB.end())
	        	ret.push_back(elem.first);
        }
        for(auto elem: listB)
        {
        	if(elem.second == 1 && listA.find(elem.first) == listA.end())
	        	ret.push_back(elem.first);
        }
        return ret;
    }
};

int main()
{
	string A, B;
	vector<string> Ans;
	Solution sol;

	getline(cin, A);
	getline(cin, B);

	Ans = sol.uncommonFromSentences(A,B);
	for(int i=0; i<Ans.size(); i++)
	{
		cout << Ans[i] << endl;
	}
	return 0;
}