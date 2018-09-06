//No.496 - AC
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int> nextG;
        vector<int> ret;

        for(int i=0; i<nums.size(); i++)
        {
         	nextG[nums[i]] = -1;
        	for(int j=i+1; j<nums.size(); j++)
        	{
        		if(nums[i]<nums[j])
        		{
        			nextG[nums[i]] = nums[j];
        			break;
        		}
        	}
        }

        for(int i=0; i<findNums.size(); i++)
        {
        	ret.push_back(nextG[findNums[i]]);
        }
        return ret;
    }
};
int main()
{
	int n1, n2, tmp;
	vector<int> findNums, nums, Ans;
	Solution sol;

	scanf("%d %d", &n1, &n2);
	for(int i=0; i<n1; i++)
	{
		scanf("%d", &tmp);
		findNums.push_back(tmp);
	}
	for(int i=0; i<n2; i++)
	{
		scanf("%d", &tmp);
		nums.push_back(tmp);
	}
	Ans = sol.nextGreaterElement(findNums, nums);
	for(int i=0; i<Ans.size(); i++)
	{
		cout << Ans[i] << " ";
	}
	return 0;
}