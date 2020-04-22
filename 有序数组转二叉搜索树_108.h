//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
//
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//
//示例 :
//
//给定有序数组: [-10, -3, 0, 5, 9] ,
//
//	一个可能的答案是：[0, -3, 9, -10, null, 5]，它可以表示下面这个高度平衡二叉搜索树：
//
//	      0
//	     / \
//	   -3   9
//	   /   /
//	  -10  5
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
//		著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <unordered_map>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#ifndef __TreeNode
#define __TreeNode;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class leetcode_108 {
public:
	TreeNode* sortedArrayToBST(std::vector<int>& nums) {
		if (nums.size() == 0)
		{
			return NULL;
		}
		return helper(nums, 0, nums.size() - 1);

	}

	TreeNode* helper(std::vector<int> & nums, int low, int high)
	{
		int len = high - low;
		TreeNode* root;
		if (len == 0)
		{
			root = new TreeNode(nums[high]);
			return root;
		}
		if (len == 1) {
			root = new TreeNode(nums[high]);
			root->left = new TreeNode(nums[low]);
			return root;
		}
		int mid = low + (high - low) / 2;
		root = new TreeNode(nums[mid]);
		root->left = helper(nums, low, mid - 1);
		root->right = helper(nums, mid + 1, high);
		return root;
	}
};