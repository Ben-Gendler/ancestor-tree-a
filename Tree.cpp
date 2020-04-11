#include <iostream>
#include "FamilyTree.hpp"
using namespace family;

static node GetNewNode(string name, int depth, gender family_role)
{
	node newMember = new struct tree_node(depth + 1, family_role);
	newMember->name = name;
	newMember->mother = newMember->father = NULL;
	return newMember;
}

Tree::Tree(string name)
{
	root = GetNewNode(name, 0, SELF);
}

tree_node::tree_node(int depth, gender family_role)
{
	this->depth = depth;
	this->family_role = family_role;
}

static node findByName(node root, string name)
{
	if (!root)
		return NULL;

	if (root->name == name)
		return root;
	node temp = findByName(root->father, name);

	if (temp)
		return temp;

	return findByName(root->mother, name);

}

Tree Tree::addFather(string child, string father_name)
{
	node CurrRoot = findByName(this->root, child);
	CurrRoot->father = GetNewNode(father_name, CurrRoot->depth, FATHER);

	return * this;
}

Tree Tree::addMother(string child, string mother_name)
{
	node CurrRoot = findByName(this->root, child);
	CurrRoot->mother = GetNewNode(mother_name, CurrRoot->depth, MOTHER);

	return * this;
}

void prettyprint(node root)	//wrapper func
{
	if (!root)
		return;

	prettyprint(root->mother);

	for (int i = 0; i < root->depth - 1; i++)
		std::cout << "        ";

	std::cout << root->name << "\n\n";

	prettyprint(root->father);

}

void Tree::display()
{
	prettyprint(this->root);
}

static node findRelation(node root, string family_member_name)
{
	if (!root)
		return NULL;

	if (root->name == family_member_name)
		return root;

	node tempNode = findRelation(root->father, family_member_name);

	if (tempNode)
		return tempNode;

	return findRelation(root->mother, family_member_name);
}

static string nodeToString(node root)
{
	if (!root)
		return "unrelated";

	if (root->depth == 0)
		return "me";

	if (root->depth == 2)
	{
		if (root->family_role == FATHER)
			return "father";
		return "mother";
	}
	else
	{
		string greatSum = "grandmother";

		if (root->family_role == FATHER)
			greatSum = "grandfather";

		for (int i = 0; i <= root->depth - 3; i++)
			greatSum = "great-" + greatSum;

		return greatSum;
	}
}
string Tree::relation(string family_member_name)	//NOT DONE
{
	node temp = findRelation(this->root, family_member_name);

	return nodeToString(temp);
}

static void deleteSubTree(node CurrRoot)
{
	if (CurrRoot == NULL)
		return;

	//Delete above subtrees//
	deleteSubTree(CurrRoot->mother);
	deleteSubTree(CurrRoot->father);
	CurrRoot->mother = CurrRoot->father = NULL;
	//Delete the required node itself
	cout << "\n deleting " << CurrRoot->name << " from the tree\n";

	delete(CurrRoot);

}

void Tree::remove(string removeAbove)
{
	deleteSubTree(findByName(this->root, removeAbove));
}

node findByRole(node root, string family_role)
{
	if (!root)
		return NULL;

	if (nodeToString(root) == family_role)
		return root;

	node temp = findByRole(root->father, family_role);

	if (temp)
		return temp;

	temp = findByRole(root->mother, family_role);
	return temp;

}
static bool validate(string family_role)
{
	if(family_role == "uncle")
		return false;

	return true;

}
string Tree::find(string family_role)
{
	if(!validate(family_role))
		throw std::invalid_argument( "The tree cannot handle the '" +family_role+"' relation" );

	if(family_role == "me" && root)
		return this->root->name;

	node result = findByRole(this->root, family_role);
	if (result)
		return result->name;

	return "unrelated";
}
