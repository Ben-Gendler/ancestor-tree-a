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
static string recursiveRelation(node currRoot,string family_member_name,string relationString) //NOT DONE
{
	if (!currRoot)
		return "unknown relation";
	if(currRoot->name == family_member_name){

	}

	if(currRoot->mother)
	{
		relationString += "mother";
		recursiveRelation(currRoot->mother,family_member_name,"relationString");
	}
	return " ";
}

static string relationWrapper(node root,string family_member_name) //NOT DONE
{
	if(root->name == family_member_name)
		return "self";

	string relationString = "";
	string relationTypes[] = {"self", "mother","father","grandmother","grandfather","great-","unrelated"};
															//0        1       2          3            4            5        6

	return recursiveRelation(root,family_member_name,relationString); //NOT DONE
}

string Tree::relation(string family_member_name) //NOT DONE
{
	return relationWrapper(this->root,family_member_name);
}
