//No.905 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ret;
        vector<int> odd;

        for(int i=0; i<A.size(); i++)
        {
        	if(A[i]%2==0)
        		ret.push_back(A[i]);
        	else
        		odd.push_back(A[i]);
        }
        ret.insert(ret.end(),odd.begin(), odd.end());

        return ret;
    }
};
int main()
{
	int n, tmp;
	Solution sol;
	vector<int> A, Ans;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &tmp);
		A.push_back(tmp);
	}
	Ans = sol.sortArrayByParity(A);

	for(int i=0; i<n; i++)
		cout << Ans[i] << endl;
	return 0;
}