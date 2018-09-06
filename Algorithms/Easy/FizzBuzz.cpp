//No.412 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;

        for(int i=1; i<=n; i++)
        {
        	if(i%15 == 0)
	        	ret.push_back("FizzBuzz");
	        else if(i%5 == 0)
	        	ret.push_back("Buzz");
	        else if(i%3 == 0)
	        	ret.push_back("Fizz");
	        else
	        	ret.push_back(to_string(i));
        }
        return ret;
    }
};
int main()
{
	int n;
	vector<string> Ans;
	Solution sol;

	scanf("%d", &n);
	Ans = sol.fizzBuzz(n);
	for(int i=0 ;i < Ans.size(); i++ )
	{
		cout << Ans[i] << endl;
	}
	return 0;
}