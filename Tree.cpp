#include <iostream>
#include "FamilyTree.hpp"
using namespace family;
#define SPACES 8

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
	if (!root)
		return NULL;

  if (root->name == name)
    return root;

	if(root->father)
		return findByName(root->father,name);

	if(root->mother)
		return findByName(root->mother,name);

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
	if (!root)
        return;

spaceAmount += SPACES;
if(root->mother)
	actualprint(root->mother, spaceAmount);

cout<<endl;

for (int i = SPACES; i < spaceAmount; i++)
	cout<<" ";

cout<<root->name<<endl;

if(root->father)
	actualprint(root->father,spaceAmount);

}

void prettyprint(node root) //wrapper func
{
	actualprint(root,0);

}

void Tree::display()
{
		prettyprint(this->root);
}

string findDepth(node root, string family_member_name, string pathString)
{
	if(!root)
		return "-1";

	if(root->name == family_member_name)
			return pathString;

	if(root->father || root->mother)
	{
		if(root->father && findByName(root->father, family_member_name))
		{
			if(root->father->name == family_member_name)
				return pathString + "1";

			else
				return findDepth(root->father,family_member_name,pathString + "1");
		}

		if(root->mother && findByName(root->mother, family_member_name))
		{
			if(root->mother->name == family_member_name)
				return pathString + "0";

			else
				return findDepth(root->mother,family_member_name,pathString + "0");
		}

	}
	else
		return "-1";
}//func

string Tree::relation(string family_member_name) //NOT DONE
{
	if(this->root->name==family_member_name)
		return "self";

	string result = findDepth(this->root,family_member_name,"");
//makeoneRower
	return result;
	// return relationWrapper(this->root,family_member_name);
}
