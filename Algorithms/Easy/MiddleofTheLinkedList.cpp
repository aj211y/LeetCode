//No.876 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	int count(ListNode* head)
	{
		int ret = 1;
		if(head->next==NULL)
			return ret;
		else
			return ret+count(head->next);
	}
    ListNode* middleNode(ListNode* head) {
        ListNode* ret = head;
        int cnt = count(head);

		cnt = cnt/2;
        while(cnt--)
        {
        	ret = ret->next;
        }

        return ret;
    }
};
ListNode* buildList(int ID,int num, int array[])
{
	if(ID==num)
	{
		return NULL;
	}

	ListNode* node = new ListNode(array[ID]);
	node->next = buildList(ID+1, num, array);
	
	return node;
}
void printList(ListNode* head)
{
	cout << head->val << endl;
	if(head->next != NULL)
	{
		printList(head->next);
	}

}
int main()
{
	int n,array[105];
	ListNode *head = NULL, *Ans=NULL;
	Solution sol;

	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &array[i]);
	}
	head = buildList(0,n,array);
	Ans = sol.middleNode(head);
	printList(Ans);

	return 0;
}