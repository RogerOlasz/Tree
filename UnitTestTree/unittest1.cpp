#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Tree/Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTree
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(PreOrderReiterative)
		{
			Tree<int> tree1;
			DList<TreeNode<int>*> my_tree;

			TreeNode<int> *a = tree1.Add(1);
			TreeNode<int> *b = tree1.Add(2, a);
			TreeNode<int> *c = tree1.Add(4, a);
			tree1.Add(3);

			tree1.PreOrderR(&my_tree);

			Assert::IsTrue(my_tree.Count() == 5);		
			
		}
		
		TEST_METHOD(PostOrderReiterative)
		{
			Tree<int> tree1;
			DList<TreeNode<int>*> my_tree;

			TreeNode<int> *a = tree1.Add(1);
			TreeNode<int> *b = tree1.Add(2, a);
			TreeNode<int> *c = tree1.Add(4, a);
			tree1.Add(3);

			tree1.PostOrderR(&my_tree);

			Assert::IsTrue(my_tree.Count() == 5);
		}

	};
}