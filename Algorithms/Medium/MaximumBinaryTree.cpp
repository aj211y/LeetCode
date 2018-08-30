// No.654 - AC
/*
    複習pointer
    new object才不會隨著function結束就不見了。

    pointer要拿物件要用箭頭->
    object拿物件用點.

    example:
    TreeNode T(10);
    cout << T.val;

    TreeNode* TPointer = new TreeNode(10);
    cout << TPointer->val;

    指標的好處：不知道資料量大小的情況下，需要動態配置記憶體空間
    在JAVA中，new物件以後，不需用delete指令。因為JVM會控管記憶體，程式結束時會自動回收記憶體空間。
    但在C++中，要使用delete回收。照理說好的OS會在程序結束後，全部回收記憶體空間，但是OS也有可能有leak，沒辦法解構物件，所以釋放不了記憶體。
    所以在C++中還是要自己delete比較好。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* MBT(int startID, int endID, vector<int>& nums)
    {
        int MID=startID;

        if(startID > endID)
            return NULL;
        else if(startID == endID)
        {
            TreeNode* curNode = new TreeNode(nums[MID]);

            return curNode;
        }
        else
        {
            for(int i=startID;i<=endID;i++)
            {
                if(nums[i]>nums[MID])
                    MID=i;
            }

            TreeNode* curNode = new TreeNode(nums[MID]);

            curNode->left = MBT(startID,MID-1, nums);
            curNode->right = MBT(MID+1, endID, nums);

            return curNode;
        }
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* ret;
        int startID=0, endID=nums.size()-1;

        ret = MBT(startID, endID, nums);
        
        return ret;
    }
};
int main()
{
	vector<int> nums;
	Solution sol;
	TreeNode* ans;

	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(6);
	nums.push_back(0);
	nums.push_back(5);
	ans = sol.constructMaximumBinaryTree(nums);

    cout << ans << endl;
	cout << ans->val << endl;
    cout << (ans->left)->val << endl;
    
	return 0;
}