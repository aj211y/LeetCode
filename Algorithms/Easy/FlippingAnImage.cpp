//No.832 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
    	vector<vector <int> > ret;
    	vector<int> ret_Tmp;
    	int tmp;
    	int len = A[0].size();

    	for(int i=0; i<len; i++)
    	{
    		ret_Tmp.clear();
    		for(int j=len-1; j>=0; j--)
    		{
    			tmp = (A[i][j] ^ 1);
    			ret_Tmp.push_back(tmp);
    		}

    		ret.push_back(ret_Tmp);
    	}
    	return ret;
    }
};
int main()
{
	int n,a;
	vector<vector<int> > A,Ans;
	vector<int> A_tmp;
	Solution sol;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		A_tmp.clear();
		for(int j=0; j<n; j++)
		{
			scanf("%d", &a);
			A_tmp.push_back(a);
		}
		A.push_back(A_tmp);
	}
	Ans = sol.flipAndInvertImage(A);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ", Ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}