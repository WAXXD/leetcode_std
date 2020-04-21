#include <stack>
#include <vector>
#ifndef __TreeNode
#define __TreeNode
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class leetcode_94 {
public:
	/*
	* 迭代法
	* 先将通过双层循环先将所有的左节点压入栈
	* 弹出最后一个左节点，打印。这个最后一个左节点其实也可以理解为中节点
	* 然后最后一个左节点的右节点入站
	*/
	std::vector<int> inorderTraversal_iterator(TreeNode* root) {
		std::stack<TreeNode*> s;
		std::vector<int> v;
		TreeNode* cur = root;
		while (cur != NULL || !s.empty())
		{
			while (cur != NULL) {
				s.push(cur);
				cur = cur->left;
			}
			
			cur = s.top();
			s.pop();
			v.push_back(cur->val);
			cur = cur->right;
		}
		return v;
	}

	/*
	* 递归法
	*/
	std::vector<int> inorderTraversal_recursion(TreeNode* root) {
		std::vector<int> v;
		ldr(root, v);
		return v;
	}

	void ldr(TreeNode* node, std::vector<int> &v)
	{
		if (node == nullptr)
		{
			return;
		}
		ldr(node->left, v);
		v.push_back(node->val);
		ldr(node->right, v);
	}
};