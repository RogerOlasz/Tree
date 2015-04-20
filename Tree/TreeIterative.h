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
		DNode<TreeNode*> *item = children.getFirst();

		for (; item != NULL; item = item->next)
		{
			item->value->PreOrderR(list);
		}
	}

	void PostOrderR(DList<TreeNode<TYPE>*> *list)
	{
		DNode<TreeNode*> *item = children.getFirst();

		for (item; item != NULL; item = item->next)
		{
			item->value->PostOrderR(list);
		}

		list->add(this);
	}

	void InOrderR(DList<TreeNode<TYPE>*> *list)
	{
		unsigned int mid = ceil((float)children.count() / 2.0f); //Rounds x upward, returning the smallest integral value that is not less than x.
		DNode<TreeNode*> *item = children.getFirst();

		for (unsigned int i = 0; i < mid; i++)
		{
			item->value->InOrderR(list);
			item = item->next;
		}

		list->add(this);

		for (; item != NULL; item = item->next)
		{
			item->value->InOrderR(list);
		}
	}
};

template<class TYPE>
class Tree
{
private:
	TreeNode<TYPE> *root_node;

public:

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



	void PreOrderR(DList<TreeNode<TYPE>*> *list)
	{
		root_node.PreOrderR(list);
	}

	void PostOrderR(DList<TreeNode<TYPE>*> *list)
	{
		root_node.PostOrderR(list);
	}

	void InOrderR(DList<TreeNode<TYPE>*> *list)
	{
		root_node.InOrderR(list);
	}

};

#endif __Tree_H__