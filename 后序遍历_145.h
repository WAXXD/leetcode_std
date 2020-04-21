
// 给定一个二叉树，返回它的 后序 遍历。
// 示例 :
// 输入: []
//		a
//	   / \
//	  b   c
//   / \  /\
//	d   ef
// 输出 debfca
#include <stack>
#include <vector>
#include <deque>
#ifndef __TreeNode
#define __TreeNode
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif
class leetcode_145 {
public:
	/*
	 * 迭代法之双端队列
	 * 思路是从根右左加入双端队列，然后将队列从前到后添加到vector
	 * 自然就是从左到右了
	 * 
	 */
	std::vector<int> postorderTraversal_iterator_deque(TreeNode* root) {
		std::vector<int> v;
		if (root == NULL)
		{
			return v;
		}
		std::stack<TreeNode*> s;
		std::deque<int> d;
		s.push(root);
		while (!s.empty())
		{
			root = s.top();
			s.pop();
			if (root->left != NULL) s.push(root->left);
			if (root->right != NULL) s.push(root->right);
			d.push_front(root->val);
		}
		for (int i : d)
		{
			v.push_back(i);
		}
		return v;
	}
};
