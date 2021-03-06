//No.104 - AC
#include <iostream>
#include <cstdio>
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        	return 0;
        if(root->left == NULL && root->right == NULL)
        	return 1;

        int valLeft = maxDepth(root->left) + 1;
        int valRight = maxDepth(root->right) + 1;
        return (valLeft > valRight)?valLeft:valRight; 
    }
};

int main()
{
	return 0;
}