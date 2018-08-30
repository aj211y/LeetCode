//No.561 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
    	int ret = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i=i+2)
        {
        	ret += nums[i];
        }
        return ret;
    }
};
int main()
{
	int n,tmp;
	vector<int> nums;
	Solution sol;

	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &tmp);
		nums.push_back(tmp);
	}
	cout << sol.arrayPairSum(nums) << endl;
	return 0;
}