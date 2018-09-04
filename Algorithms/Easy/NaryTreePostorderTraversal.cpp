//No. 590 - AC
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
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
    vector<int> postorder(Node* root) {
        stack<Node*> waitingList;
        vector<int> ret;
        Node* head;
        if(root!=NULL)
	        waitingList.push(root);
        while(!waitingList.empty())
        {
        	head = waitingList.top();
        	waitingList.pop();
        	for(int i=0; i<head->children.size(); i++)
        	{
        		waitingList.push(head->children[i]);
        	}
        	ret.push_back(head->val);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
int main()
{
	Solution sol;
	vector<Node*> child;
	vector<int> Ans;
	Node* child_6 = new Node(6,child);
	Node* child_5 = new Node(5,child);
	Node* child_2 = new Node(2,child);
	Node* child_4 = new Node(4,child);
	child.push_back(child_5);
	child.push_back(child_6);
	Node* child_3 = new Node(3,child);
	child.clear();
	child.push_back(child_2);
	child.push_back(child_3);
	child.push_back(child_4);

	Node* root = new Node(1,child);
	Ans = sol.postorder(root);

	for(int i=0; i<Ans.size(); i++)
	{
		cout << Ans[i] << " ";
	}
}