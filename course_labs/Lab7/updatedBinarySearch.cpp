/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <assert.h>

using namespace std;

struct Node {
  int key;
  int size;
  Node *left;
  Node *right;
  Node (int k) { key = k; size = 1; left = right = nullptr; }
};

void fix_size(Node *T)
{
  T->size = 1;
  if (T->left) T->size += T->left->size;
  if (T->right) T->size += T->right->size;
}

// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k)
{
  if (T == nullptr) return new Node(k);
  if (k < T->key) T->left = insert(T->left, k);
  else T->right = insert(T->right, k);
  fix_size(T);
  return T;
}

// returns a vector of key values corresponding to the inorder traversal of T (i.e., the contents of T in sorted order)
vector<int> inorder_traversal(Node *T)
{
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
Node *find(Node *T, int k)
{
  //Implement Node *find(Node *T, int k)
  if (T == NULL) return NULL;
  if (k == T->key) return T;
  if (k < T->key) return find(T->left, k);
  else return find(T->right, k); 
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
Node *join(Node *L, Node *R)
{
  // choose either the root of L or the root of R to be the root of the joined tree
  // (where we choose with probabilities proportional to the sizes of L and R)
  if (L == NULL) return R;
  if (R == NULL) return L;
  
  int r = rand() % (L->size + R->size); // Calculate probabilities
  // Choose the root of L as root of the joined tree and recur "join"
  if (r < L->size)
  {
    int s = (L->right) ? L->right->size : 0;
    L->right = join(L->right, R);
    L->size += L->right->size - s;
    return L;
  }
  // Choose the root of R as root of the joined tree and recur "join"
  else
  {
    int s = (R->left) ? R->left->size :0;
    R->left = join(L, R->left);
    R->size += R->left->size - s;
    return R;
  }
  //Implement Node *join(Node *L, Node *R)
}

// remove key k from T, returning a pointer to the resulting tree.
// it is required that k be present in T
Node *remove(Node *T, int k)
{
  assert (find(T,k) != NULL);
  if (T == NULL) return NULL;
  // Remove k when it is at the root
  if (k == T->key)
  {
    Node *n = join(T->left, T->right);
    delete T;
    return n;
  }
  // Recur "remove" for left subtree
  if (k < T->key)
    T->left = remove(T->left, k);
  // Recur "remove" for right subtree
  else
    T->right = remove(T->right, k);
  T->size--;
  return T;
  //Implement Node *remove(Node *T, int k)
}

// Split tree T on key k into tree L (containing keys <= k) and a tree R (containing keys > k)
void split(Node *T, int k, Node **L, Node **R)
{
  if (T == NULL)
  { 
    *L = NULL;
    *R = NULL;
    return;
  }
  // Recur "split" for left subtree
  if (k < T->key)
  {
    *R = T;
    Node *left_left, *left_right;
    split(T->left, k, &left_left, &left_right);
    *L = left_left;
    T->left = left_right;
    T->size -= (left_left != NULL) ? left_left->size : 0;
    return;
  }
  // Recur "split" for right subtree
  else
  {
    *L = T;
    Node *right_left, *right_right;
    split(T->right, k, &right_left, &right_right);
    *R = right_right;
    T->right = right_left;
    T->size -= (right_right != NULL) ? right_right->size : 0;
    return;
  }
  //Implement void split(Node *T, int k, Node **L, Node **R)
}

// insert key k into the tree T, returning a pointer to the resulting tree
Node *insert_random(Node *T, int k)
{
  // If k is the Nth node inserted into T, then:
  // with probability 1/N, insert k at the root of T
  // otherwise, insert_random k recursively left or right of the root of T
  if (T == NULL) return new Node(k);

  int r = rand() % (T->size + 1); // Calculate probabilities
  // Insert at the root
  if (r < 1)
  {    
    Node *L, *R;
    split(T, k, &L, &R);
    Node *n = new Node(k);
    n->left = L;
    n->right = R;
    n->size = T->size + 1;
    return n;
  }
  // Insert at subtrees
  else
  {
    if (k < T->key) 
      T->left = insert_random(T->left, k); // Insert at the left subtree
    else
      T->right = insert_random(T->right, k); // Insert at the right subtree

    T->size++;
    return T;    
  }
  //Implement Node *insert_random(Node *T, int k)
}

void printVector(vector<int> v)
{
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

int main(void)
{
  vector<int> inorder;
  vector<int> A(10,0);
  
  // put 0..9 into A[0..9] in random order
  for (int i=0; i<10; i++) A[i] = i;
  for (int i=9; i>0; i--) swap(A[i], A[rand()%i]);
  cout << "Contents of A (to be inserted into BST):\n";
  printVector(A);
  
  // insert contents of A into a BST
  Node *T = nullptr;
  for (int i=0; i<10; i++) T = insert(T, A[i]);
  
  // print contents of BST (should be 0..9 in sorted order)
  cout << "Contents of BST (should be 0..9 in sorted order):\n";
  inorder=inorder_traversal(T);
  printVector(inorder);

  // test select
  for (int i=0; i<10; i++) {
    Node *result = select(T, i);
    if (!result || result->key != i) cout << "Select test failed for select(" << i << ")!\n";
  }

  // test find: Elements 0..9 should be found; 10 should not be found
  cout << "Elements 0..9 should be found; 10 should not be found:\n";
  for (int i=0; i<11; i++) 
    if (find(T,i)) cout << i << " found\n";
    else cout << i << " not found\n";

  // test split
  Node *L, *R;
  split(T, 4, &L, &R);
  cout << "Contents of left tree after split (should be 0..4):\n";
  inorder=inorder_traversal(L);
  printVector(inorder);
  cout << "Left tree size " << L->size << "\n";
  cout << "Contents of right tree after split (should be 5..9):\n";
  inorder=inorder_traversal(R);
  printVector(inorder);
  cout << "Right tree size " << R->size << "\n";
    
  // test join
  T = join(L, R);
  cout << "Contents of re-joined tree (should be 0..9)\n";
  inorder=inorder_traversal(T);
  printVector(inorder);
  cout << "Tree size " << T->size << "\n";
  
  // test remove
  for (int i=0; i<10; i++) A[i] = i;
  for (int i=9; i>0; i--) swap(A[i], A[rand()%i]);
  for (int i=0; i<10; i++) {
    T = remove(T, A[i]);
    cout << "Contents of tree after removing " << A[i] << ":\n";
    inorder=inorder_traversal(T);
    printVector(inorder);
    if (T != nullptr)
      cout << "Tree size " << T->size << "\n";
  }

  // test insert_random
  cout << "Inserting 1 million elements in order; this should be very fast...\n";
  for (int i=0; i<1000000; i++) T = insert_random(T, i);
  cout << "Tree size " << T->size << "\n";
  cout << "Done\n";
  
  return 0;
}
