//No.867 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > transpose(vector<vector<int> >& A) {
    	int rowLen = A.size();
    	int colLen = A[0].size();
    	vector<int> list;
    	vector<vector<int> > ret;

        for(int c=0; c<colLen; c++)
        {
        	list.clear();
        	for(int r=0; r<rowLen; r++)
        	{
        		list.push_back(A[r][c]);
        		// cout << A[r][c] << endl;
        	}
        	ret.push_back(list);
        }
        return ret;
    }
};
int main()
{
	int r,c,tmp;
	vector<vector<int> > A,Ans;
	vector<int> list;
	Solution sol;

	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++)
	{
		list.clear();
		for(int j=0; j<c; j++)
		{
			scanf("%d", &tmp);
			list.push_back(tmp);
		}
		A.push_back(list);
	}
	Ans = sol.transpose(A);
	for(int i=0; i<c; i++)
	{
		for(int j=0; j<r; j++)
		{
			cout << Ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}