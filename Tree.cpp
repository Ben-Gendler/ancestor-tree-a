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

string findDepth(node root, string family_member_name, string relation)
{
	if (!root)
			return "";

	if (root->name == family_member_name)
			return relation;

string tempDepth = findDepth(root->father,family_member_name,"father");

	if(tempDepth != "")
	{
			return "grand-" + tempDepth;
	}

tempDepth = findDepth(root->mother,family_member_name,"mother");

	if(tempDepth != "")
	{
			return "grand-" + tempDepth;
	}

return "";
}//func

string Tree::relation(string family_member_name) //NOT DONE
{
	if(this->root->name==family_member_name)
		return "self";

	string result = findDepth(this->root->father,family_member_name,"father");
	string result1 = findDepth(this->root->mother,family_member_name,"mother");

if(result!="")
	return result;

if(result1!="")
	return result1;

return "not related";

//makeoneRower
	// return result;
	// return relationWrapper(this->root,family_member_name);
}
