//No.637 - AC
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> nextLevel, tmpList;
        double avgLevel, cnt;
        TreeNode* head;

        nextLevel.push(root);
        avgLevel = 0;
        cnt = 0;
        while(!nextLevel.empty())
        {
        	head = nextLevel.front();
        	nextLevel.pop();

        	avgLevel += head->val;
        	cnt++;

        	if(head->left != NULL)
        		tmpList.push(head->left);
        	if(head->right != NULL)
        		tmpList.push(head->right);
        	if(nextLevel.empty())
        	{
        		ret.push_back(avgLevel/cnt);
        		while(!tmpList.empty())
        		{
        			nextLevel.push(tmpList.front());
        			tmpList.pop();
        		}
        		avgLevel = 0;
        		cnt = 0;
        	}
        }
        return ret;
    }
};
int main()
{
	Solution sol;
	vector<double> Ans;
	TreeNode* node_9 = new TreeNode(9);
	TreeNode* node_20 = new TreeNode(20);
	TreeNode* node_15 = new TreeNode(15);
	TreeNode* node_7 = new TreeNode(7);
	TreeNode* root = new TreeNode(3);
	node_20->left = node_15;
	node_20->right = node_7;
	root->left = node_9;
	root->right = node_20;

	Ans = sol.averageOfLevels(root);

	for(int i=0; i<Ans.size(); i++)
	{
		cout << Ans[i] << ' ' ;
	}
	return 0;
}