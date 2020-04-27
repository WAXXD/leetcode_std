//#include <deque>
//给定一个二叉树，原地将它展开为链表。
//
//例如，给定二叉树
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
//将其展开为：
//
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
class leetcode_114 {
public:
	/*
	  这道题有点类似改变结构的morris前序遍历
	  首先把左子树移动到右子树
	  把右子树移动到左子树的最右右子树的右子树(这句有点拗口)
	  上一句如果是平衡二叉树的话其实可以说将右子树移动到它的前驱节点
	*/
	void flatten(TreeNode* root) {
		if (root == NULL) return;

		while (root != NULL)
		{
			if (root->left != NULL) {
				TreeNode* cur = root->left;
				TreeNode* pred = root->left;
				while (cur->right != NULL)
				{
					pred = cur->right;
					cur = cur->right;
				}
				pred->right = root->right;
				root->right = root->left;
			}
			root->left = NULL;
			root = root->right;
		}
	}
};