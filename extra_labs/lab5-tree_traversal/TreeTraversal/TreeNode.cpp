#include "TreeNode.h"


//Preorder Function
//------------------------------------------------------------------------------
//This function traverses the tree using preorder traversal. A stack of treenode
//pointers are used for this process, as opposed to using recursion
//------------------------------------------------------------------------------

void TreeNode::preorder() const {


    if (this == NULL){                                      // If the object being called upon
        return;                                             // is empty, the function will end
    }

    std::stack <const TreeNode*> nodeStack;                 // Creating a stack of TreeNode pointers
    nodeStack.push(this);                                   // that we will push our object into


        while (nodeStack.empty() == false){                 // While our stack contains values...

            const TreeNode *treePtr = nodeStack.top();      // Creating a new object point equal
                                                            // to whatever value is at the top of
                                                            // the stack, so we can display our
                                                            // updated values


            std::cout << treePtr->value << std::endl;       // Display the treePtr value, then
            nodeStack.pop();                                // pop from stack

            if (treePtr->rchild){                           // if the tree contains a right child
                nodeStack.push(treePtr->rchild);            // push it into the stack
            }
            if (treePtr->lchild){                           // if the tree contains a left child
                nodeStack.push(treePtr->lchild);            // push it onto the stack. We push the
            }                                               // right child onto the stack first,
                                                            // so that the left child can be pushed
        }                                                   // on top and displayed first



}

//------------------------------------------------------------------------------


//Postorder Function
//------------------------------------------------------------------------------
//This function traverses the tree using postorder traversal. Recursion is used
//to traverse through the left subtree, then the right, and finally the root
//------------------------------------------------------------------------------

void TreeNode::postorder() const {


    if (this == NULL){                      // If the object being called upon is empty
        return;                             // the function will return
    }

    this->lchild->postorder();              // Calling the postorder function upon the
                                            // left child of our current node

    this->rchild->postorder();              // Calling the postorder function upon the
                                            // right child of our current node


    std::cout << this->value << std::endl;  // Printing out our current value


}

//------------------------------------------------------------------------------










