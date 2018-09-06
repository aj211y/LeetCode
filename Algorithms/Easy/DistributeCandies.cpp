//No.575 - AC
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int ret = candies.size()/2;
        set<int> kinds;
        for(int i=0; i<candies.size(); i++)
        {
        	
        	kinds.insert(candies[i]);
        }
        if(kinds.size()>=ret)
        	return ret;
        else
        	return kinds.size();
    }
};
int main()
{
	Solution sol;
	int n,c;
	vector<int> candies;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &c);
		candies.push_back(c);
	}
	cout << sol.distributeCandies(candies) << endl;
	return 0;
}