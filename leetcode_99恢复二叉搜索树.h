#include <stack>
#include <vector>
#include <deque>
#include <list>
#ifndef __TreeNode
#define __TreeNode
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif
class leetcode_99 {
public:
	void recoverTree(TreeNode* root) {
		if (root == NULL) return;
		std::stack<TreeNode*> s;
		TreeNode * cur = root, *x = NULL,*y = NULL, *pred = NULL;
		while (!s.empty() || cur != NULL)
		{
			while (cur != NULL)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			if (pred != NULL && pred->val > cur->val)
			{
				y = cur;
				if (x == NULL) {
					x = pred;
				}
				else {
					break;
				}
			}
			pred = cur;
			s.pop();
			if (cur != nullptr) {
				// 这个判断没什么卵用，只是编译器这里绿线看着不舒服强迫症
				cur = cur->right;
			}

		}
		if (x != NULL) {
			int temp = x->val;
			x->val = y->val;
			y->val = temp;
		}
		int ii = 0;
	}

	void recoverTree_morris(TreeNode* root) {
		TreeNode *x = NULL, *y = NULL, *pred = NULL,*pre = NULL;
		while (root != nullptr)
		{
			if (root->left != nullptr)
			{
				pred = root->left;
				while (pred->right != nullptr && pred->right != root)
				{
					pred = pred->right;
				}
				if (pred->right == root)
				{
					if (pre != nullptr && pre->val > root->val)
					{
						y = root;
						if (x == nullptr)
						{
							x = pre;
						}
						else
						{
							break;
						}
					}
					pre = root;
					pred->right = nullptr;
					root = root->right;
				}
				else if (pred->right == nullptr)
				{
					pred->right = root;
					root = root->left;
				}
			}
			else
			{
				if (pre != nullptr && pre->val > root->val)
				{
					y = root;
					if (x == nullptr)
					{
						x = pre;
					}
					else
					{
						break;
					}
				}
				pre = root;
				root = root->right;
			}
		}
		if (x != NULL) {
			int temp = x->val;
			x->val = y->val;
			y->val = temp;
		}
	}
};