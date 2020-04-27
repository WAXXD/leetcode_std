//给定一个二叉树，返回它的中序 遍历。
//
//示例 :
//
// 输入: [1, null, 2, 3]
//	 1
//	  \
//	  2
//	 /
//	3
//
//	输出: [1, 3, 2]
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/binary-tree-inorder-traversal
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
	std::vector<int> inorderTraversal_recursion(TreeNode* root) 
	{
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
	/*
	  morris方法可以显著的节约内存。不需要栈只需要一个pred变量。
	*/
	std::vector<int> inorderTraversal_morris(TreeNode* root)
	{
		std::vector<int> v;
		// 用以保存当前节点的前驱节点
		// 前驱节点表示小于当前节点的最大节点
		TreeNode* pred;
		while (root != nullptr) 
		{
			if (root->left != nullptr)
			{
				pred = root->left;
				while(pred->right != nullptr && pred->right != root)
				{
					pred = pred->right;
				}
				if (pred->right == root)
				{
					v.push_back(root->val);
					pred->right = nullptr;
					root = root->right;

				} 
				else if(pred->right == nullptr)
				{
					pred->right = root;
					root = root->left;
				}
	
			} 
			else
			{
				v.push_back(root->val);
				root = root->right;
			}	
		}
		return v;
	}
};