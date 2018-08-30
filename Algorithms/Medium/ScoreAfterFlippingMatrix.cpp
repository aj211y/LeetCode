//No.861 - AC
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int> >& A) {
		int row, col, zero[25],ret;

		row = A.size();
		col = A[0].size();

		for(int i=0; i<25; i++)
		{
			//initialize
			zero[i]=0;	//the number of zeros in column i
		}

		for(int r=0; r<row; r++)
		{
			for(int c=1; c<col; c++)
			{
				if(!A[r][0])
				{
					A[r][c] = (A[r][c] ^ 1);
				}
				if(!A[r][c])
					zero[c]++;
			}	
			A[r][0] = 1;			
		}
		ret = pow(2, col-1)*row;
		for(int c=1; c<col; c++)
		{
			if(row-zero[c] < zero[c])
			{
				ret += pow(2, col-c-1)*zero[c];
				// for(int r=0; r<row; r++)
				// {
				// 	A[r][c] = (A[r][c] ^ 1);
				// }
			}
			else
			{
				ret += pow(2, col-c-1)*(row-zero[c]);
			}
		}
		return ret;    
    }
};
int main()
{
	Solution sol;
	int row,col,num;
	vector<int> list;
	vector<vector<int> > A;

	scanf("%d %d",&row, &col);
	for(int r=0; r<row; r++)
	{
		list.clear();
		for(int c=0;c<col; c++)
		{
			scanf("%d", &num);
			list.push_back(num);
		}
		A.push_back(list);
	}
	cout << sol.matrixScore(A) << endl;
	return 0;
}