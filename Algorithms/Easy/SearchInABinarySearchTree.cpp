//No. 700 - AC
#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

    	if(root == NULL)
    		return NULL;
 		if(root->val == val)
 			return root;
 		if(root->val < val)
 		{
 			if(root->right != NULL)
	 			return searchBST(root->right, val);
	 		else
	 			return NULL;
 		}
 		if(root->val > val)
 		{
 			if(root->left != NULL)
 				return searchBST(root->left, val);
 			else
 				return NULL;
 		}
    }
};
int main()
{
	return 0;
}