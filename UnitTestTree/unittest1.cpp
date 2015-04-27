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

			TreeNode<int> *a = tree1.Add(1);
			TreeNode<int> *b = tree1.Add(2, a);
			tree1.Add(3);

			tree1.PreOrderR
		}

	};
}