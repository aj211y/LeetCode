//No.852 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int len = A.size(), ret;
        
        for(int i=0, j=len-1; i<=j ;i++, j--)
        {
        	if(A[i]>A[i+1])
        	{
        		ret = i;
        		break;
        	}
        	if(A[j]>A[j-1])
        	{
        		ret = j;
        		break;
        	}
        }
        return ret;
    }
};

int main()
{
	Solution sol;
	int n,tmp;
	vector<int> A;

	scanf("%d" ,&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &tmp);
		A.push_back(tmp);
	}
	cout << sol.peakIndexInMountainArray(A) << endl;

	return 0;
}