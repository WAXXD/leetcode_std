// ����һ������ǰ�������������������������
//
// ע�� :
// ����Լ�������û���ظ���Ԫ�ء�
// ���磬����
//
// ǰ����� preorder = [3, 9, 20, 15, 7]
// ������� inorder = [9, 3, 15, 20, 7]
// �������µĶ�������
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
		�ݹ鷨
		ǰ���������ȷ�����ڵ�root ǰ�����: �� | �������� | ��������
		�����������ͨ��ǰ���еĸ��ڵ������������� �������: �������� | �� | ��������
		�������ֿ�����������͸��������Ϳ��Էֱ������������ٴεݹ����
		build(ǰ��������������
		������Ż�map���������Ч�ʵġ�Ҳ������ע���еĴ���ÿ�α����ҵ����ڵ�����������е�λ��

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
		// ������������Ԫ�ظ���
		int left_length = rootin - ilow;
		root->left = build(preorder, plow + 1, plow + left_length, inorder, ilow, rootin - 1,map);
		root->right = build(preorder, plow + 1 + left_length, phigh, inorder, rootin + 1, ihigh,map);
		return root;
	}
};
