/*
 * Name: Julio Reyes
 * Date Submitted: 11/05/2020
 * Lab Section: 004
 * Assignment Name: Binary Search Trees
 */

#include "binarySearchTree.h"




void fix_size(Node *T) {

  T->size = 1;
  if (T->left) T->size += T->left->size;
  if (T->right) T->size += T->right->size;

}






// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k) {

  if (T == nullptr) return new Node(k);
  if (k < T->key) T->left = insert(T->left, k);
  else T->right = insert(T->right, k);
  fix_size(T);
  
  return T;
}







// returns a vector of key values corresponding to the inorder traversal of T (i.e., the contents of T in sorted order)
vector<int> inorder_traversal(Node *T) {

  vector<int> inorder;
  vector<int> rhs;
  if (T == nullptr) return inorder;
  inorder=inorder_traversal(T->left);
  inorder.push_back(T->key);
  rhs=inorder_traversal(T->right);
  inorder.insert(inorder.end(), rhs.begin(), rhs.end());
  
return inorder;
}







// return a pointer to the node with key k in tree T, or nullptr if it doesn't exist
Node *find(Node *T, int k) {

    if (T == NULL){
      return NULL;
    }
    else if (T->key == k){
      return T;
    }
    else if (T->key > k){
      *find(T->left, k);          //  Searching through either left or right 
    }                             // depending on value of node
    else if (T->key < k){
      *find(T->right, k);
    }

}




// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
Node *select(Node *T, int r) {
  assert(T != nullptr && r >= 0 && r < T->size);

  int rank = (T->left != NULL) ? T->left->size : 0;

    if (r == rank){
      return T;
    } 
    if (r < rank){
      return select(T->left, r);
    }    
    else{ 
      return select(T->right, r - rank - 1);
    }
}




// Join trees L and R (with L containing keys all <= the keys in R)
// Return a pointer to the joined tree.  
Node *join(Node *L, Node *R) {

  if (L == NULL){
    return R;                             // Returning L or R depending on if one 
  }                                       // is NULL
  if (R == NULL){ 
    return L;
  }

  int r = rand() % (L->size + R->size);   // Generating our random value


    if (r < L->size) {                   

      int m = (L->right) ? L->right->size : 0;
      L->right = join(L->right, R);
      L->size += L->right->size - m;
      return L;

    }
    else {

      int m = (R->left) ? R->left->size :0;
      R->left = join(L, R->left);
      R->size += R->left->size - m;
      return R;

    }
}




// remove key k from T, returning a pointer to the resulting tree.
// it is required that k be present in T
Node *remove(Node *T, int k) {

  assert(T != nullptr);

    if (T == NULL){ 
      return NULL;
    } 
  
    if (k == T->key) {

      Node *n = join(T->left, T->right);
      delete T;
      return n;

    }

    if (k < T->key){
      T->left = remove(T->left, k);
    }

    else{
      T->right = remove(T->right, k);
    }

  T->size--;
  fix_size(T);
return T;
}







// Split tree T on key k into tree L (containing keys <= k) and a tree R (containing keys > k)
void split(Node *T, int k, Node **L, Node **R) {

  if (T == NULL) { 
    
    *L = NULL;
    *R = NULL;
    return;

  }
  
  if (k < T->key) {

    *R = T;
    Node *left_left;
    Node *left_right;
    split(T->left, k, &left_left, &left_right);
    *L = left_left;
    T->left = left_right;
    T->size -= (left_left != NULL) ? left_left->size : 0;
    return;

  }

  else  {
    
    *L = T;
    Node *right_left, *right_right;
    split(T->right, k, &right_left, &right_right);
    *R = right_right;
    T->right = right_left;
    T->size -= (right_right != NULL) ? right_right->size : 0;
    return;
  
  }

}






// insert key k into the tree T, returning a pointer to the resulting tree
Node *insert_random(Node *T, int k) {

  if (T == NULL){
    return new Node(k);  
  } 

  int r = rand() % (T->size + 1);

    if (r < 1) { 

      Node *L, *R;
      split(T, k, &L, &R);
      Node *p = new Node(k);
      p->left = L;
      p->right = R;
      p->size = T->size + 1;
      return p;
      
    }
    else {

        if (k < T->key){ 
          T->left = insert_random(T->left, k);        // Insert left subtree
        }
        else{
          T->right = insert_random(T->right, k);      // Insert right subtree
        }
      
      T->size++;
      fix_size(T);

      return T;

    }
}



void printVector(vector<int> v) {

    for (int i=0; i<v.size(); i++) {
        cout << v[i] << endl;
    }

}

