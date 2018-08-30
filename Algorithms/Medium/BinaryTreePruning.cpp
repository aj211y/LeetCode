//No.814 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
    	if(root->left != NULL)
    		root->left = pruneTree(root->left);
    	if(root->right != NULL)
    		root->right = pruneTree(root->right);
    	if(root->left == NULL && root->right == NULL)
    	{
    		if(root->val)
    			return root;
    		else
    			return NULL;
    	}

        return root;
    }
};

int main()
{
	return 0;
}