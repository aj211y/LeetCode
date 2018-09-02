//No. 500 - AC
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    				//   A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
        int alpha[26] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        int ID, row;
        vector<string> ret;
        bool sameRow;

        for(int i=0; i<words.size(); i++)
        {
        	sameRow = true;
        	if(words[i][0]>='A' && words[i][0] <='Z')
        		ID = words[i][0] - 'A';
        	else
        		ID = words[i][0] - 'a';
        	row = alpha[ID];
          	for(int j=1; j<words[i].size(); j++)
        	{
	        	if(words[i][j]>='A' && words[i][j] <='Z')
	        		ID = words[i][j] - 'A';
	        	else
	        		ID = words[i][j] - 'a';

        		if(alpha[ID] != row)
        		{
        			sameRow=false;
        			break;
        		}
        	}
        	if(sameRow)
        		ret.push_back(words[i]);
        }
        return ret;
    }
};
int main()
{
	int n;
	string str;
	vector<string> words, Ans;
	Solution sol;

	scanf("%d", &n);
	while(n--)
	{
		cin >> str;
		words.push_back(str);
	}
	Ans = sol.findWords(words);
	for(int i=0; i<Ans.size(); i++)
	{
		cout << Ans[i] << endl;
	}

	return 0;
}