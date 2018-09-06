//No.566 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
        int rowOri = nums.size(), colOri = nums[0].size();
        vector<vector<int> > ret;
        vector<int> list;
        queue<int> items;
        
        if(rowOri*colOri != r*c)
        	return nums;

        for(int i=0; i<rowOri; i++)
        {
        	for(int j=0; j<colOri; j++)
        		items.push(nums[i][j]);
        }
        for(int i=0; i<r; i++)
        {
        	list.clear();
        	for(int j=0; j<c; j++)
        	{
        		list.push_back(items.front());
        		items.pop();
        	}
        	ret.push_back(list);
        }
        return ret;
    }
};
int main()
{
	vector<int> list;
	vector<vector<int> > nums,Ans;
	int r, c, row, col,tmp;
	Solution sol;

	scanf("%d %d %d %d",&row, &col, &r, &c);
	for(int i=0; i<row; i++)
	{
		list.clear();
		for(int j=0; j<col; j++)
		{
			scanf("%d", &tmp);
			list.push_back(tmp);
		}
		nums.push_back(list);
	}
	Ans = sol.matrixReshape(nums, r, c);


	for(int i=0; i<Ans.size(); i++)
	{
		for(int j=0; j<Ans[0].size(); j++)
		{
			cout << Ans[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}