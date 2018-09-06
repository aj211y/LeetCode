//No.897 - AC
#include <iostream>
#include <stack>
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
	TreeNode* increasingBST(TreeNode* root)
	{
		TreeNode* ret=root , *tmp;
		if(root == NULL)
			return root;

		if(root->left == NULL && root->right == NULL)
			return root;
		
        if(root->right != NULL)
		{
			root->right = increasingBST(root->right);
		}
        if(root->left != NULL)
		{
			ret = increasingBST(root->left);
            tmp = root->left;
            while(tmp->right != NULL)
            {
                tmp = tmp->right;                
            }
            tmp->right = root;
			ret->left = NULL;
    		root->left = NULL;
		}
		return ret;
	}
	//TLE
	// void buildBST(TreeNode* root, stack<TreeNode*>& wait)
	// {
	// 	if(root->left == NULL && root->right == NULL)
	// 	{
	// 		wait.push(root);
	// 	}
	// 	else
	// 	{
	// 		if(root->right != NULL)
	// 		{
	// 			buildBST(root->right, wait);
	// 		}
	// 		wait.push(root);
	// 		if(root->left != NULL)
	// 		{
	// 			buildBST(root->left, wait);
	// 		}
	// 	}
	// }
    // TreeNode* increasingBST(TreeNode* root) {
    // 	stack<TreeNode*> wait;
    // 	TreeNode *ret, *head;

    //     if(root == NULL)
    //     	return root;
    //     buildBST(root, wait);

    //     ret = wait.top();
        
    //     head = wait.top();
    //     wait.pop();
    //     while(!wait.empty())
    //     {
    //     	head->left = NULL;
    //     	head->right = wait.top();
    //     	head = wait.top();
    //     	wait.pop();
    //     }
    //     return ret;
    // }
};
int main()
{
	Solution sol;
	TreeNode* ans;
	TreeNode* root = new TreeNode(379);
	TreeNode* node_826 = new TreeNode(826);
	root->right = node_826;
	ans = sol.increasingBST(root);
	cout << ans->val;
	return 0;
}