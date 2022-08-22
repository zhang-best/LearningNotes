#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left,*right;
	TreeNode(int _val)
	{
		val = _val;
		left = nullptr;
		right = nullptr;
	}
};
void preorder1(TreeNode* root)//前序迭代方法一
{
	if (root == nullptr) return;
	stack<TreeNode*> stk;
}
void preorder1(TreeNode* root)//前序迭代方法二
{

}
int main()
{
	return 0;
}

