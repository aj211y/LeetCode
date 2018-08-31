//No. 893 - AC
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int len, strLen, gID, groups[1010];
        string odd[1010], even[1010];

        len = A.size();
        strLen = A[0].length();

        for(int i=0; i<len; i++)
        {
        	groups[i] = -1;
        	odd[i] = "";
        	even[i] = "";
        	for(int j=0; j<strLen; j++)
        	{
        		if(j%2)
        			odd[i] += A[i][j];
        		else
        			even[i] += A[i][j];
        	}
        	sort(odd[i].begin(), odd[i].end());
        	sort(even[i].begin(), even[i].end());
        }
        gID = 0;
        for(int i=0; i<len; i++)
        {
        	if(groups[i]==-1)
        	{
        		groups[i] = ++gID;
	        	for(int j=i+1; j<len; j++)
	        	{
	        		if(odd[i] == odd[j] && even[i] == even[j])
	        		{
	        			groups[j] = groups[i];
	        		}
	        	}
        	}
        }

        return gID;
    }
};
int main()
{
	int n;
	string str;
	vector<string> A;
	Solution sol;

	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		cin >> str;
		A.push_back(str);
	}
	cout << sol.numSpecialEquivGroups(A) << endl;
	return 0;
}