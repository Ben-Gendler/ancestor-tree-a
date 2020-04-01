#include <iostream>
using namespace std;
namespace family{
    void Tree(string root);
    void addFather(string root,string father_name);
    void addMother(string root,string mother_name);
    string relation(string family_member_name);
    string find(family_role); //returns name
    void display(string root); //displays from root above
    void remove(string family_member_name); //remove root+all parents

    struct tree_node
  {
    string name;
    node *left;
    node *right;
  };
Tree(string name){
tree_node* root;
root==NULL;
root->name == name;
}
}
