//No.872 - AC
//Two binary tree are considered "leaf-similar" if their leaf value sequence is the same;
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
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
	void leafNodes(TreeNode* root, int leaf[], int& ID)
	{
		if(root->left!=NULL)
			leafNodes(root->left, leaf, ID);
		if(root->right!=NULL)
			leafNodes(root->right, leaf, ID);
		if(root->left == NULL && root->right == NULL)
		{
			//This node is a leaf
			leaf[ID++] = root->val;
		}
	}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        int leafOne[105], leafTwo[105];
        int lenOne = 0, lenTwo = 0;

        for(int i=0;i<105;i++)
        {
        	leafOne[i] = -1;
        	leafTwo[i] = -1;
        }

        leafNodes(root1, leafOne, lenOne);
        leafNodes(root2, leafTwo, lenTwo);

        if(lenOne!=lenTwo)
        {
        	return false;
        }
        else
        {	
	    	for(int i=0; i<lenOne; i++)
	    	{
	    		if(leafOne[i]!=leafTwo[i])
	    			return false;
	    	}
	    	return true;
	    }
    }
    //Run too slow
	// void leafNodes(TreeNode* root, vector<int>& leaf)
	// {
	// 	if(root->left!=NULL)
	// 		leafNodes(root->left, leaf);
	// 	if(root->right!=NULL)
	// 		leafNodes(root->right, leaf);
	// 	if(root->left == NULL && root->right == NULL)
	// 	{
	// 		//This node is a leaf
	// 		leaf.push_back(root->val);
	// 	}
	// }
 //    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
 //        vector<int> leafOne, leafTwo;
 //        int lenOne, lenTwo;

 //        leafNodes(root1, leafOne);
 //        leafNodes(root2, leafTwo);

 //        lenOne = leafOne.size();
 //        lenTwo = leafTwo.size();

 //        if(lenOne!=lenTwo)
 //        {
 //        	return false;
 //        }
 //        else
 //        {
 //        	for(int i=0; i< lenOne; i++)
 //        	{
 //        		if(leafOne[i]!=leafTwo[i])
 //        			return false;
 //        	}
 //        	return true;
 //        }
 //    }
};

int main()
{

	return 0;
}