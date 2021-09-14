#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

#include <iostream>
#include <stack>


class TreeNode {

  private:
      const std::string value;    // contains node value
      TreeNode * lchild;   // reference to node's left child
      TreeNode * rchild;   // reference to node's right child

  public:
  TreeNode (std::string str) : value(str) , lchild(nullptr) , rchild(nullptr) { }

  void setLeft( TreeNode* l) { lchild = l; }
  void setRight( TreeNode* r) { rchild = r; }

  void postorder ( ) const;
  void preorder( ) const;

};

#endif // TREENODE_H_INCLUDED
