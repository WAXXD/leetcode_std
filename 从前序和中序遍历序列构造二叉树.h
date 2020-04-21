// 根据一棵树的前序遍历与中序遍历构造二叉树。
//
// 注意 :
// 你可以假设树中没有重复的元素。
// 例如，给出
//
// 前序遍历 preorder = [3, 9, 20, 15, 7]
// 中序遍历 inorder = [9, 3, 15, 20, 7]
// 返回如下的二叉树：
//
//     3
//    / \
//   9  20
//     / \
//    15  7
#include <unordered_map>
#include <stack>
#include <vector>
#include <deque>
#include <list>

#ifndef __TreeNode
#define __TreeNode;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class leetcode_105 {

public:
	/*
		递归法
		前序遍历可以确定根节点root 前序遍历: 根 | 根左子树 | 根右子树
		中序遍历可以通过前序中的根节点区分左右子树 中序遍历: 根左子树 | 根 | 根右子树
		这样区分开后根左子树和根右子树就可以分别当做独立的树再次递归调用
		build(前序树，中序树）
		此题的优化map是用来提高效率的。也可以用注释中的代码每次遍历找到根节点在中序遍历中的位置

	*/
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
		std::unordered_map<int,int> map;
		for (int i = 0; i < inorder.size(); i++)
		{
			map.insert(std::make_pair(inorder[i], i));
			// map.emplace(inorder[i],i);
		}
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, map);
	}

	TreeNode* build(std::vector<int>& preorder, int plow, int phigh, std::vector<int>& inorder, int ilow, int ihigh, std::unordered_map<int, int>& map)
	{
		if (plow > phigh || ilow > ihigh) return nullptr;
		TreeNode* root = new TreeNode(preorder[plow]);
		int rootin = map.at(preorder[plow]);
		//while (ilow <= ihigh && inorder[rootin] != preorder[plow])
		//{
		//	rootin++;
		//}
		// 这是左子树的元素个数
		int left_length = rootin - ilow;
		root->left = build(preorder, plow + 1, plow + left_length, inorder, ilow, rootin - 1,map);
		root->right = build(preorder, plow + 1 + left_length, phigh, inorder, rootin + 1, ihigh,map);
		return root;
	}
};
