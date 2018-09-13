//No.824 - AC
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        string ret="", word="", firstW="";
        int round=1;
        set<char> vowels;
        bool vowStart;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');

        if(vowels.find(S[0])!=vowels.end())
        {
        	vowStart = true;
        	word+=S[0];
        }
        else
        {
        	vowStart = false;
        	firstW = S[0];
        }
        for(int i=1; i<=S.length(); i++)
        {
        	if(S[i]==' ' || i == S.length())//new word
        	{
        		if(!vowStart)
        		{
        			word+=firstW;
        		}
        		word+="ma";

        		for(int j=0; j<round; j++)
        		{
        			word+="a";
        		}
        		if(i!=S.length())
	        		word+=" ";

        		ret+=word;

        		word = "";
        		firstW = "";
        		round++;
        		if(i!=S.length())
        		{
        			i++;
        			if(vowels.find(S[i])!=vowels.end())
			        {
			        	vowStart = true;
			        	word+=S[i];
			        }
			        else
			        {
			        	vowStart = false;
			        	firstW = S[i];
			        }
        		}
        	}
        	else
        	{
        		word+=S[i];
        	}
        }
        return ret;
    }
};
int main()
{
	string line;
	Solution sol;
	getline(cin, line);
	cout << sol.toGoatLatin(line) << endl;
	return 0;
}