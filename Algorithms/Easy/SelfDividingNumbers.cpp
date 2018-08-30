//No.728 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
  		vector<int> ret;
  		int tmpNum,digit, nDigit;
  		bool selfDivNum;

  		for(int num=left; num<=right; num++)
  		{
  			tmpNum = num;
  			selfDivNum=true;
  			nDigit=-1;
  			while(tmpNum>0)
  			{
  				nDigit++;
  				digit = tmpNum%10;
  				tmpNum=tmpNum/10;
  				if(digit==0 || num%digit!=0)
  				{
  					selfDivNum=false;
  					if(digit == 0)
  					{
  						while(nDigit>0)
  						{
	  						tmpNum=tmpNum*10+1;
	  						nDigit--;
  						}
  						num=tmpNum*10;
  					}
  					break;
  				}
  			}
  			if(selfDivNum)
  				ret.push_back(num);
  		}
  		return ret;
  	}
};

int main()
{
	int left, right;
	vector<int> Ans;
	Solution sol;
	scanf("%d %d", &left, &right);
	Ans = sol.selfDividingNumbers(left, right);
	for(int i=0; i<Ans.size();i++)
	{
		cout << Ans[i] << " ";
	}
	return 0;
}