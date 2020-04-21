#pragma once
// 给定两个二叉树，编写一个函数来检验它们是否相同。
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
// 示例 1 :
// 输入:  1     1
//	     / \   / \
//	    2  3  2  3
//	[1, 2, 3], [1, 2, 3]
//	输出: true
//	示例 2 :
//	输入 : 1          1
//	      /           \
//	     2            2
//
//	[1, 2], [1, null, 2]
//	输出: false
//	示例 3 :
//	输入 : 1     1
//	      / \   / \
//	     2   1  1  2
//	[1, 2, 1], [1, 1, 2]
//	输出: false

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


class Leetcode_100 {

public:
	/*
	 * 迭代法
	 */
	bool isSameTree_iterate(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		if (!check(p, q)) return false;
		std::stack<TreeNode*> s1;
		std::stack<TreeNode*> s2;
		s1.push(p);
		s2.push(q);
		while (!s1.empty())
		{
			p = s1.top();
			q = s2.top();
			s1.pop();
			s2.pop();
			if (!check(p, q)) return false;
			if (p != NULL)
			{
				if (!check(p->left, q->left)) return false;
				if (p->left != NULL)
				{
					s1.push(p->left);
					s2.push(q->left);
				}

				if (!check(p->right, q->right)) return false;

				if (p->right != NULL)
				{
					s1.push(p->right);
					s2.push(q->right);
				}

			}
		}
		return true;
	}

	/*
	 * 函数返回值：当同为null或者节点相等的时候返回1 其它返回0
	 * 这样就可以判断其中一个节点是否为null从而判断两个节点是否为null；
	 */
	bool check(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL) return true;
		if (p == NULL || q == NULL) return false;
		return p->val == q->val;
	}

	/*
	 * 递归法
	 */
	bool isSameTree_recursion(TreeNode* p, TreeNode* q)
	{
		if (p == nullptr && q == nullptr) return true;
		if (p == nullptr || q == nullptr) return false;
		if (p->val != q->val) 
		{
			return false;
		}
		return isSameTree_recursion(p->left, q->left) && isSameTree_recursion(p->right, q->right);
		//return (p != NULL && q != NULL) ? p->val == q->val && isSameTree_iterate(p->left, q->left) && isSameTree_iterate(p->right, q->right) : p == NULL && q == NULL;

	}
};