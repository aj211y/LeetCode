//No.762 - AC
#include <iostream>
#include <set>
using namespace std;

bool p[50];
class Solution {
public:
	void primeNum()
	{
		for(int i=2; i<50; i++)
		{
			p[i] = true;
		}
		p[1] = false;
		for(int i=2; i<50; i++)
		{
			if(p[i])
			{
				for(int j=i+i; j<50; j=j+i)
				{
					p[j] = false;
				}
			}
		}
	}
    int countPrimeSetBits(int L, int R) {
        int digit[50], tmp, ret=0, Rcnt=0, cnt;
        primeNum();
        
        tmp = R;
        for(int i=0; tmp>0; i++)
        {
        	digit[i] = (tmp&1);
        	if(digit[i]==1)
        		Rcnt++;
        	tmp = tmp >> 1;
        }
        if(p[Rcnt])
        	ret++;

        for(int i = L; i<R; i++)
        {
        	tmp = i^R;
        	cnt = Rcnt;
        	for(int j=0; tmp>0; j++)
        	{
        		if((tmp&1)==1)
        		{
        			if(digit[j])
        				cnt--;
        			else
        				cnt++;
        		}
        		tmp = tmp >> 1;
        	}
        	if(p[cnt])
        		ret++;
        }
        return ret;
    }
};
int main()
{
	Solution sol;
	int L, R;
	scanf("%d %d", &L, &R);

	cout << sol.countPrimeSetBits(L,R) << endl;
	return 0;
}