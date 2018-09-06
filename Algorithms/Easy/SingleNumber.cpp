//No.136 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i=i+2)
        {
        	if(nums[i]!=nums[i+1])
        	{
        		ret = nums[i];
        		break;
        	}
        }
        return ret;
    }
};
int main()
{
	int n, tmp;
	Solution sol;
	vector<int> nums;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &tmp);
		nums.push_back(tmp);
	}
	cout << sol.singleNumber(nums) << endl;
	return 0;
}