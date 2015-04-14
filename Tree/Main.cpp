#include "Tree.h"

int main(int argc, char** argv)
{
	Tree<int> tree1;

	TreeNode<int> *a = tree1.Add(15);

	tree1.Add(30, a);
	tree1.Add(50, a);

	return 0;
}