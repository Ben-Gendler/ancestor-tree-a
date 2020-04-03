#include <iostream>
#include "FamilyTree.hpp"
using namespace family;
#define SPACES 10

static node GetNewNode(string name)
{
	node newMember = new struct tree_node();
	newMember->name = name;
	newMember->mother = newMember->father = NULL;
	return newMember;
}

Tree::Tree(string name)
{
  root = GetNewNode(name);
}

static node findByName(node root, string name)
{
	if (root == NULL)
		return NULL;

  if (root->name == name)
  {
    return root;
  }

	if(root->father!=NULL)
	{
		return findByName(root->father,name);
	}

	if(root->mother!=NULL)
	{
		return findByName(root->mother,name);
	}

  return NULL;
}

Tree Tree::addFather(string child, string father_name)
{
  node CurrRoot = findByName(this->root, child);
  CurrRoot->father = GetNewNode(father_name);
  return *this;
}

Tree Tree::addMother(string child, string mother_name)
{
  node CurrRoot = findByName(this->root, child);
  CurrRoot->mother = GetNewNode(mother_name);
  return *this;
}

void actualprint(node root,int spaceAmount)
{
	if (root == NULL)
        return;

spaceAmount += SPACES;
actualprint(root->mother, spaceAmount);

cout<<endl;

for (int i = SPACES; i < spaceAmount; i++)
	cout<<" ";

cout<<root->name<<"\n";

actualprint(root->father,spaceAmount);

}

void prettyprint(node root) //wrapper
{
	actualprint(root,0);
}

void Tree::display()
{
		prettyprint(this->root);
}
