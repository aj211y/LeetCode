//No.896 - AC
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
    	bool allSame = true;
    	for(int i=0; i<A.size()-1; i++)
    	{
    		if(A[i]!=A[i+1])
    		{
    			allSame = false;
    			if(A[i]>A[i+1])
    				reverse(A.begin(), A.end());
    			break;
    		}
    	}

    	if(allSame)
    		return true;

        for(int i=0; i<A.size()-1; i++)
        {
        	if(A[i]>A[i+1])
        		return false;
        }
        return true;
    }
};
int main()
{
	int n, tmp;
	Solution sol;
	vector<int> A;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &tmp);
		A.push_back(tmp);
	}

	if(sol.isMonotonic(A))
		cout << "True" << endl;
	else
		cout << "No" << endl;
	return 0;
}