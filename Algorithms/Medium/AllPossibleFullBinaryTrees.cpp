//No.894 - AC
#include <iostream>
#include <vector>
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
	void FullBinaryTreePath(int N, vector<TreeNode*> allPath[])
	{
		int L, R, LID, RID, allPathID, L_len, R_len;
		vector<TreeNode*> L_ans, R_ans;


		for(L=1; L<=N-2; L=L+2)
		{
			R = N-1-L;

			//left
			LID = L/2;
			if(allPath[LID].size() == 0)
			{
				FullBinaryTreePath(L, allPath);
			}
			L_len = allPath[LID].size();

			//right
			RID = R/2;
			if(allPath[RID].size() == 0)
			{
				FullBinaryTreePath(R, allPath);
			}
			R_len = allPath[RID].size();

			//all possible paths
			allPathID = N/2;
			for(int i=0; i<L_len; i++)
			{
				for(int j=0; j<R_len; j++)
				{
					TreeNode* root = new TreeNode(0);
					root->left = allPath[LID][i];
					root->right = allPath[RID][j];

					allPath[allPathID].push_back(root);
				}
			}
		}
	}
    vector<TreeNode*> allPossibleFBT(int N) {
    	vector<TreeNode*> allPath[15];
    	TreeNode* T_single = new TreeNode(0);
    	TreeNode* T_triangle = new TreeNode(0);
    	int allPathID = N/2;
    	T_triangle->left = T_single;
    	T_triangle->right = T_single;

        if(N % 2 == 0)
        	return allPath[0];
        
        cout << "$" << allPathID << endl;
    	allPath[0].push_back(T_single); //one node
    	allPath[1].push_back(T_triangle); // three node
    	FullBinaryTreePath(N, allPath);

        return allPath[allPathID];
    }
};
int main()
{
	int n;
	Solution sol;
	vector<TreeNode*> Ans;
	scanf("%d", &n);
	Ans = sol.allPossibleFBT(n);
	return 0;
}