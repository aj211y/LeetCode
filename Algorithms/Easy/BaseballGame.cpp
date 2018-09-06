//No.682 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ret = 0, num = 0, tmp = 0;
        bool isNeg = false;
        stack<int> list;

        for(int i=0; i<ops.size(); i++)
        {
        	if(ops[i] == "D")
        	{
        		if(!list.empty())
        		{
	        		num = list.top()*2;
	    			list.push(num);
	    			ret += num;        			
        		}

        	}
        	else if(ops[i] == "C")
        	{
        		if(!list.empty())
        		{
		    		num = list.top();
					list.pop();
					ret -= num;        			
        		}
        	}
        	else if(ops[i] == "+")
        	{
        		if(list.size()>=2)
        		{
	        		tmp = list.top();
	        		list.pop();
	        		num = tmp + list.top();
	        		list.push(tmp);
	        		list.push(num);
	    			ret += num;
        		}
        	}
        	else
        	{
        		//number
    			num = 0;
    			isNeg = false;
    			for(int j=0; j<ops[i].length(); j++)
    			{
    				if(ops[i][j] == '-')
    				{
    					isNeg = true;
    				}
    				else
    				{
    					num = num*10 + (ops[i][j] - '0');
    				}
    			}
    			if(isNeg)
    				num = 0 - num;
    			list.push(num);
    			ret += num;
        	}
        }
        return ret;
    }
};
int main()
{
	int n;
	string str;
	vector<string> ops;
	Solution sol;

	scanf("%d", &n);

	while(n--)
	{
		cin >> str;
		ops.push_back(str);
	}
	cout << sol.calPoints(ops) << endl;
	return 0;
}