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
class leetcode_145 {
public:
	/*
	 基础方法递归
	*/
	std::vector<int> postorderTraversal_recursion(TreeNode* root)
	{
		std::vector<int> v;
		lrd(v,root);
		return v;
	}

	void lrd(std::vector<int>& v, TreeNode* node) {
		if (node == nullptr)
		{
			return;
		}
		lrd(v,node->left);
		lrd(v,node->right);
		v.push_back(node->val);
	}
	/*
	  迭代法之双端队列
	  思路是从根右左加入双端队列，然后将队列从前到后添加到vector
	  自然就是从左到右了
	 */
	std::vector<int> postorderTraversal_iterator_deque(TreeNode* root) 
	{
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

	/*
	  迭代法之纯迭代
	  里面利用了nullptr节点进行标识分层
	  当栈顶为nullptr的时候就将nullptr弹出，然后把下一个元素也弹出加入栈
	  跳出当前循环
	 */
	std::vector<int> postorderTraversal_iterator(TreeNode * root)
	{
		std::vector<int> v;
		if (root == nullptr)
		{
			return v;
		}
		std::stack<TreeNode*> s;
		s.push(root);
		TreeNode* temp;
		while (!s.empty())
		{
			temp = s.top();
			if (temp == nullptr)
			{
				s.pop();
				temp = s.top();
				v.push_back(temp->val);
				s.pop();
				continue;
			}
			s.push(nullptr);
			if (temp->right != nullptr) s.push(temp->right);
			if (temp->left != nullptr) s.push(temp->left);
		}

		return v;
	}

	/*
	  采用了list迭代
	  和中序前序不同的是，现在是添加到队首
	  思路分析:
			前序遍历: 根左右，
					1、先把左节点全部压入栈，并且加入v，直到nullptr然后弹栈。
					2、对当前弹栈的节点的右节点做1同样的事情。
			后序遍历: 左右根，可由前序遍历逆推来
					分析：前序：根左右 -> 右左根 (通过将元素添加到队首来实现）
							   右左根 -> 左右根 (先把右节点全部压入栈来实现)
	  此思路和双端队列类似

	 */
	std::vector<int> postorderTraversal_iterator_list(TreeNode * root)
	{
		std::vector<int> v;
		std::list<int> l;

		if (root == nullptr)
		{
			return v;
		}
		std::stack<TreeNode*> s;
		s.push(root);
		TreeNode* temp = root;
		while (!s.empty())
		{
			if (temp != nullptr)
			{
				l.push_front(temp->val);
				s.push(temp);
				temp = temp->right;
			}
			else
			{
				temp = s.top()->left;
				s.pop();
			}
		}
		v.assign(l.begin(), l.end());
		return v;
	}
};
