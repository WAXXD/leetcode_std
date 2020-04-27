#include <stack>
#include <vector>
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
class leetcode_112 {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		std::stack<TreeNode*> s_node;
		std::stack<int> s_sum;
		int path_sum = 0;
		while (!s_node.empty() || root != NULL)
		{
			while (root != NULL)
			{
				s_node.push(root);
				s_sum.push(path_sum + root->val);
				path_sum = s_sum.top();
				if (root->left != NULL)
				{
					root = root->left;
				}
				else if (root->right != NULL)
				{
					root = root->right;
				}
				else
				{
					break;
				}
			}
			if (path_sum == sum && s_node.top()->left == NULL && s_node.top()->right == NULL) return true;
			s_sum.pop();
			s_node.pop();
			if (s_sum.empty()) root = NULL;
			while (!s_sum.empty())
			{
	
				root = s_node.top();
				s_node.pop();
				path_sum = s_sum.top();
				s_sum.pop();
				root = root->right;
				if (root != NULL) {
					break;
				} 
			}

		}
		return false;
	}
};