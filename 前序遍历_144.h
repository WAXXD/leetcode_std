#pragma once
// 给定一个二叉树，返回它的 前序 遍历。
// 示例 :
// 输入: [1, null, 2, 3]
//	1
//	 \
//	  2
//	 /
//	3
//
// 输出: [1, 2, 3]
// 前序遍历：根，左，右
#include <vector>
#include <stack>
#ifndef __TreeNode
#define __TreeNode
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class leetcode_144 {
public:
	/*
	* 迭代法
	*/
	std::vector<int> preorderTraversal_iterator(TreeNode* root) {
		std::vector<int> values;
		if (root == NULL)
		{
			return values;
		}
		std::stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode* temp = s.top();
			s.pop();
			values.push_back(temp->val);
			if (temp->right != NULL)
			{
				s.push(temp->right);
			}
			if (temp->left != NULL)
			{
				s.push(temp->left);
			}
		}
		return values;
	}
	/*
	* 递归
	*/
	std::vector<int> preorderTraversal_recursion(TreeNode* root) 
	{
		std::vector<int> values;
		dlr(root,values);
		return values;
	}
	void dlr(TreeNode* node, std::vector<int>& v)
	{
		if(node != nullptr)
		{
			v.push_back(node->val);
			dlr(node->left, v);
			dlr(node->right,v);
		}

	}

	/*
	* 树转链表
	*/
	std::vector<int> preorderTraversal_tree2list(TreeNode* root)
	{
		std::vector<int> v;
		TreeNode* max_right;
		while (root != nullptr) 
		{
			if (root->left != nullptr) 
			{
				// 当前节点的左节点不为空
				// 把左节点移动到右节点
				// 把右节点移动左子节点的最大右节点的右子节点;
				max_right = root->left;
				while (max_right->right != nullptr)
				{
					max_right = max_right->right;
				}
				root->right = root->left;
				max_right->right = root->right;
				root->left = nullptr;
			} 
			else
			{
				// 当前节点的左子节点为空
				v.push_back(root->val);
				root = root->right;
			}
		}
		return v;
	}
	/*
	* 树转链表
	*/
	std::vector<int> preorderTraversal_tree2list1(TreeNode* root)
	{
		std::vector<int> v;
		TreeNode* max_right;
		while (root != nullptr)
		{
			if (root->left != nullptr)
			{
				max_right = root->left;
				while (max_right->right != nullptr)
				{
					max_right = max_right->right;
				}

				v.push_back(root->val);
				max_right->right = root->right;
				root = root->left;
				//if (max_right->right == nullptr)
				//{
				//	v.push_back(root->val);
				//	max_right->right = root->right;
				//	root = root->left;
				//}
				//else {
				//	root = root->right;
				//	max_right->right = nullptr;
				//}

			}
			else
			{
				// 当前节点的左子节点为空
				v.push_back(root->val);
				root = root->right;
			}
		}
		return v;
	}

};