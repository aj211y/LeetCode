//No.559 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
    	int ret=0, depth;
    	if(root == NULL)
    		return 0;
    	//leaf node
        if(root->children.size() == 0)
        {
        	return 1;
        }

        for(int i=0; i<root->children.size(); i++)
        {
        	depth = maxDepth(root->children[i])+1;
        	ret = (ret > depth)?ret:depth;
        }
        return ret;
    }
};

int main()
{
	return 0;
}