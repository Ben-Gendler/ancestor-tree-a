#include <iostream>
//class: default private
//struct: default public
using namespace std;
namespace family{
  typedef struct tree_node
  {
    string name;
    struct tree_node* mother;
    struct tree_node* father;
  } *node;

    class Tree
    {
      node root;

    public:
      Tree(string name);
      Tree addFather(string name,string father_name);
      Tree addMother(string name,string mother_name);
      string relation(string family_member_name);
      string find(string family_role); //returns name
      void display(); //displays from root above
      void remove(string family_member_name); //remove root+all parents//find family_member_name node and remove it's child's node
    };


}
