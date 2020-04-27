//#include <deque>
//����һ����������ԭ�ؽ���չ��Ϊ����
//
//���磬����������
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
//����չ��Ϊ��
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
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
	  ������е����Ƹı�ṹ��morrisǰ�����
	  ���Ȱ��������ƶ���������
	  ���������ƶ�����������������������������(����е��ֿ�)
	  ��һ�������ƽ��������Ļ���ʵ����˵���������ƶ�������ǰ���ڵ�
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