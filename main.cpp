#include <iostream>
#include <stack>


#include "leetcode_100.h"
#include "前序遍历_144.h"
#include "中序遍历_94.h"
#include "后序遍历_145.h"
#include "从中序和后序遍历序列构造二叉树_106.h"
#include "leetcode_99恢复二叉搜索树.h"
#include "leetcode_114二叉树展开为链表.h"
#include "leetcode_112路径总和.h"
#include <iostream>
using namespace std;

void print_vector(const vector<int>& v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
}
/*
	根据层序遍历数组构建二叉树
*/
TreeNode* createTree(int* node_arr, int length)
{
	int idx = 0;
	TreeNode* root = new TreeNode(node_arr[idx++]);
	deque<TreeNode*> d;
	d.push_front(root);
	while (!d.empty() && idx < length)
	{
		TreeNode* temp = d.front();
		d.pop_front();
		int i = idx;
		if (idx < length)
		{
			if (node_arr[idx++] != NULL)
			{
				temp->left = new TreeNode(node_arr[i++]);
				d.push_back(temp->left);
			}
			else
			{
				i++;
				temp->left = NULL;
			}

		}
		else
		{
			break;
		}
		if (idx < length)
		{
			if (node_arr[idx++] != NULL)
			{
				temp->right = new TreeNode(node_arr[i++]);
				d.push_back(temp->right);
			}
			else
			{
				temp->right = NULL;
			}
		}
		else
		{
			break;
		}
	}
	return root;
}

void test_100()
{


	TreeNode* p_11 = new TreeNode(11);
	TreeNode* p_10 = new TreeNode(10);
	TreeNode* p_9 = new TreeNode(9);
	TreeNode* p_8 = new TreeNode(8);
	TreeNode* p_7 = new TreeNode(7);
	TreeNode* p_6 = new TreeNode(6);
	TreeNode* p_5 = new TreeNode(5);
	TreeNode* p_4 = new TreeNode(4);
	TreeNode* p_3 = new TreeNode(3);
	TreeNode* p_2 = new TreeNode(2);
	TreeNode* p_1 = new TreeNode(1);
	p_1->left = p_2;
	p_1->right = p_3;
	p_2->left = p_4;
	p_2->right = p_5;
	p_3->left = p_6;
	p_3->right = p_7;
	//p_4->left = p_8;
	//p_4->right = p_9;
	//p_5->left = p_10;
	//p_5->right = p_11;

	//leetcode_144 l_144;
	//vector<int> v = l_144.preorderTraversal_tree2list1(p_1);

	//vector<int> v = l_145.postorderTraversal_iterator_deque(p_1);
	//vector<int> v1 = l_145.postorderTraversal_iterator(p_1);
	//vector<int> v2 = l_145.postorderTraversal_iterator_list(p_1);
	//vector<int> v3 = l_145.postorderTraversal_recursion(p_1);
	leetcode_94 l_94;
	vector<int> v = l_94.inorderTraversal_iterator(p_1);
	leetcode_144 l_144;
	vector<int> v1 = l_144.preorderTraversal_iterator(p_1);
	leetcode_145 l_145;
	vector<int> v2 = l_145.postorderTraversal_iterator(p_1);
	print_vector(v1);
	print_vector(v);
	print_vector(v2);
	//print_vector(v1);
	//print_vector(v2);
	//print_vector(v3);

	leetcode_106 l_106;
	vector<int> in = { 2,1 };
	vector<int> post = { 2,1 };
	TreeNode* root = l_106.buildTree(in, post);
	vector<int> v3 = l_94.inorderTraversal_iterator(root);
	vector<int> v4 = l_145.postorderTraversal_iterator(root);
	print_vector(v3);
	print_vector(v4);
	cout << 5 / 2 << endl;

	leetcode_99 l_99;
	TreeNode* p_31 = new TreeNode(3);
	TreeNode* p_21 = new TreeNode(2);
	TreeNode* p_111 = new TreeNode(1);
	TreeNode* p_41 = new TreeNode(4);
	p_111->left = p_31;
	p_31->right = p_21;

	//p_41->left = p_21;
	//l_99.recoverTree(p_31);
	l_99.recoverTree_morris(p_111);
	print_vector(v4);

	cout << "----------------------------------" << endl;

	vector<int> v_m = l_94.inorderTraversal_morris(p_1);
	vector<int> v_r = l_94.inorderTraversal_recursion(p_1);
	print_vector(v_m);
	print_vector(v_r);

	//leetcode_114 l_114;
	//l_114.flatten(p_1);

	leetcode_112 l_112;
	int node_arr[] = { 1 };
	createTree(node_arr, 1);
	l_112.hasPathSum(createTree(node_arr, 1), 0);

	
}


int main()
{

	test_100();


	system("pause");
	return 0;

}