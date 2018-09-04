//No.766 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int> >& matrix) {
        queue<int> element;
        bool ret=true;
        int row = matrix.size(), col = matrix[0].size();

        for(int i=col-1; i>=0; i--)
        {
        	element.push(matrix[0][i]);
        }

        for(int i=1; i<row; i++)
        {
        	element.pop();
        	element.push(matrix[i][0]);
        	for(int j=col-1; j>=0; j--)
        	{
        		if(element.front() == matrix[i][j])
        		{
        			element.push(matrix[i][j]);
        			element.pop();
        		}
        		else
        		{
        			ret = false;
        			break;
        		}
        	}
        	if(!ret)
        		break;
        }
        return ret;
    }
};
int main()
{
	int R,C,item;
	vector<int> list;
	vector<vector<int> > matrix;
	Solution sol;
	scanf("%d %d", &R, &C);
	for(int r=0; r<R; r++)
	{
		list.clear();
		for(int c=0; c<C; c++)
		{
			scanf("%d", &item);
			list.push_back(item);
		}
		matrix.push_back(list);
	}

	if(sol.isToeplitzMatrix(matrix))
		cout << "True" ;
	else
		cout << "False" ;
	return 0;
}