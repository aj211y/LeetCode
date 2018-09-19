//No.888 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int sumA=0, sumB=0, dif, ans;
        bool findAns;
        vector<int> ret;

        for(int i=0; i<A.size(); i++)
        	sumA += A[i];
        for(int i=0; i<B.size(); i++)
        	sumB += B[i];

		findAns = false;
        if(sumA>sumB)
        {
        	dif = (sumA-sumB)/2;
        	for(int b=0; b<B.size(); b++)
        	{
        		ans = B[b] + dif;
        		for(int a=0; a<A.size(); a++)
        		{
        			if(ans == A[a])
        			{
        				ret.push_back(A[a]);
        				ret.push_back(B[b]);
        				findAns = true;
        				break;
        			}
        			if(ans < A[a])
        			{
        				break;
        			}
        		}
        		if(findAns)
        			break;
        	}
        }
        else
        {
        	dif = (sumB-sumA)/2;
        	for(int a=0; a<A.size(); a++)
        	{
        		ans = A[a] + dif;
        		for(int b=0; b<B.size(); b++)
        		{
        			if(ans == B[b])
        			{
        				ret.push_back(A[a]);
        				ret.push_back(B[b]);
        				findAns = true;
        				break;
        			}
        			if(ans < B[b])
        			{
        				break;
        			}
        		}
        		if(findAns)
        			break;
        	}
        }

        return ret;
    }
};
int main()
{
	int n,m, tmp;
	vector<int> A, B, Ans;
	Solution sol;
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
	{
		scanf("%d", &tmp);
		A.push_back(tmp);
	}
	for(int i=0; i<m; i++)
	{
		scanf("%d", &tmp);
		B.push_back(tmp);
	}

	Ans = sol.fairCandySwap(A, B);
	
	cout << Ans[0] << " " << Ans[1] << endl;
	
	return 0;
}