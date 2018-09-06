//No.589 - AC
#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> preorder(Node* root) {
        vector<int> ret;
        stack<Node*> waitList;
        Node* head;

        if(root == NULL)
        	return ret;
        
        waitList.push(root);
        while(!waitList.empty())
        {
        	head = waitList.top();
        	waitList.pop();
        	ret.push_back(head->val);

        	for(int i=head->children.size()-1; i>=0; i--)
        	{
        		waitList.push(head->children[i]);
        	}
        }
        return ret;
    }
};
int main()
{
	return 0;
}