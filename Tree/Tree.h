#ifndef __Tree_H__
#define __Tree_H__

#include "DList.h"
#include "StackArray.h"

template<class TYPE>
struct TreeNode
{
	TYPE data;
	TreeNode<TYPE> *parent;
	DList<TreeNode*> children;

	void PreOrderR(DList<TreeNode<TYPE>*> *list)
	{
		list->add(this);

		doubleNode<TreeNode*> *item = children.getFirst();

		for (; item != NULL; item = item->next)
		{
			item->value->PreOrderR(list);
		}
	}

	void PostOrderR(DList<TreeNode<TREEDATA>*> *list)
	{
		doubleNode<TreeNode*> *item = children.getFirst();

		for (item; item != NULL; item = item->next)
		{
			item->value->PostOrderR(list);
		}

		list->add(this);
	}

	void inOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		unsigned int middle = ceil((float)children.count() / 2.0f);

		doubleNode<TreeNode*> *item = children.getFirst();

		for (unsigned int i = 0; i < middle; i++)
		{
			item->value->inOrderRecursive(list);
			item = item->next;
		}

		list->add(this);
		printf("%c", data);

		for (; item != NULL; item = item->next)
		{
			item->value->inOrderRecursive(list);
		}
	}
};

template<class TYPE>
class Tree
{
public:
	TreeNode<TYPE> *root_node;

	Tree()
	{
		root_node = new TreeNode<TYPE>;
	}

	~Tree(){}

	TreeNode<TYPE>* Add(const TYPE& new_data)
	{
		TreeNode<TYPE> *new_node = new TreeNode<TYPE>;

		root_node->children.Add(new_node);
		new_node->data = new_data;
		new_node->parent = root_node;

		return new_node;
	}

	TreeNode<TYPE>* Add(const TYPE& new_data, TreeNode<TYPE> *parent)
	{
		TreeNode<TYPE> *new_node = new TreeNode<TYPE>;

		parent->children.Add(new_node);
		new_node->data = new_data;
		new_node->parent = parent;

		return new_node;
	}
	
	

	void VisitAllNodes(DList<TYPE> list) const
	{
		root_node->VisitAll(list);
	}
};

#endif __Tree_H__