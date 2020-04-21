#pragma once
#include <algorithm>

// 给定一个二叉树，判断它是否是高度平衡的二叉树。
// 本题中，一棵高度平衡二叉树定义为：
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
// 示例 1:
//
// 给定二叉树[3, 9, 20, null, null, 15, 7]
//
//    3
//   / \
//   9  20
//  / \
// 15  7
// 返回 true 。

// 示例 2:
// 给定二叉树[1, 2, 2, 3, 3, null, null, 4, 4]
//      1
//     / \
//    2   2
//   / \
//   3   3
//  / \
// 4   4
// 返回 false 。

#ifndef __TreeNode
#define __TreeNode
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		// if(root == NULL) return true;
		// return abs(height(root->left) - height(root->right)) < 2 && 
		//         isBalanced(root->left) && isBalanced(root->right);

		if (root == NULL) return true;
		int height;
		return isBalancedHelper(root, height);
	}

	int height(TreeNode * node)
	{
		if (node == NULL) return -1;
		return 1 + std::max(height(node->left), height(node->right));
	}

	bool isBalancedHelper(TreeNode * node, int& height)
	{
		if (node == NULL)
		{
			height = -1;
			return true;
		}

		int left_h, right_h;
		if (isBalancedHelper(node->left, left_h)
			&& isBalancedHelper(node->right, right_h)
			&& abs(left_h - right_h) < 2)
		{
			height = std::max(left_h, right_h) + 1;
			return true;
		}
		return false;
	}
};