//根据一棵树的中序遍历与后序遍历构造二叉树。
//
//注意 :
//你可以假设树中没有重复的元素。
//
//例如，给出
//
//中序遍历 inorder =   [4, 2, 5, 1, 6, 3, 7]
//后序遍历 postorder = [4, 5, 2, 6, 7, 3, 1]
//返回如下的二叉树：
//
//   4 2 5 1 6 3 7
//   4 5 2 6 7 3 1
//         1
//        / \
//       2   3
//      / \ / \
//	   4  5 6  7
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

class leetcode_106 {
public:
	TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
		std::unordered_map<int, int> map;
		for (int i = 0; i < inorder.size(); i++) {
			map.emplace(inorder[i], i);
		}
		TreeNode* root = build(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1, map);
		return root;
	}
private:
	TreeNode* build(std::vector<int>& inorder, int il, int ih, std::vector<int>& postorder, int post_len, std::unordered_map<int, int>& map)
	{
		if (il > ih || post_len < 0) return nullptr;
		post_len = post_len;
		TreeNode* root = new TreeNode(postorder[post_len]);
		int rootin_idx = map.at(root->val);
		int ill = il;
		int ilh = rootin_idx - 1;
		int irl = rootin_idx + 1;
		int irh = ih;
		if (irl <= irh)
		{
			post_len -= 1;
			root->right = build(inorder, irl, irh, postorder, post_len, map);
		}

		if (ill <= ilh)
		{
			post_len = irh - irl > 0 ? post_len - (irh - irl) - 1 : post_len - 1;
			root->left = build(inorder, ill, ilh, postorder, post_len, map);
		}
		return root;
	}

};

