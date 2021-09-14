#include <iostream>
#include "TreeNode.h"

int main() {
      // Create tree by hand here.
     TreeNode * t1 = new TreeNode("A");
     TreeNode * t2 = new TreeNode("B");
     TreeNode * t3 = new TreeNode("C");
     TreeNode * t4 = new TreeNode("D");
     TreeNode * t5 = new TreeNode("E");
     TreeNode * t6 = new TreeNode("F");
     TreeNode * t7 = new TreeNode("G");

     t1->setLeft(t2);
     t1->setRight(t3);
     t2->setLeft(t4);
     t2->setRight(t5);
     t3->setLeft(t6);
     t3->setRight(t7);

     std::cout << "Postorder should be DEBFGCA" << std::endl;
     t1->postorder( );
     std::cout << "Preorder should be ABDECFG" << std::endl;
     t1->preorder( );

     delete t1;
     delete t2;
     delete t3;
     delete t4;
     delete t5;
     delete t6;
     delete t7;
     return 0;
}



