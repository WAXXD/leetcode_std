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
	* ������
	* �Ƚ�ͨ��˫��ѭ���Ƚ����е���ڵ�ѹ��ջ
	* �������һ����ڵ㣬��ӡ��������һ����ڵ���ʵҲ�������Ϊ�нڵ�
	* Ȼ�����һ����ڵ���ҽڵ���վ
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
	* �ݹ鷨
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