#include <iostream>
#include <stack>


#include "leetcode_100.h"
#include "前序遍历_144.h"
#include "中序遍历_94.h"
#include "后序遍历_145.h"
#include <iostream>
using namespace std;

void print_vector(const vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
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
	p_4->left = p_8;
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
	
}


int main()
{

	test_100();
	system("pause");
	return 0;

}