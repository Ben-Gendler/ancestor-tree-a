#include <iostream>
#include "FamilyTree.hpp"
using namespace family;

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

//bfs dfs and duplications
static node findByName(node root, string name)
{
  if (root->name == name)
  {
    return root;
  }
  //TODO
  return NULL;
}

Tree Tree::addFather(string name, string father_name)
{
  node relative = findByName(root, name);
  relative->father = GetNewNode(father_name);
  return *this;
}
