# include<iostream>
#include <map>
#include "map.hpp"
#include "bidirectional_iterator.hpp"
// using namespace std;
 
// An AVL tree node
// class Node
// {
//     public:
//     int key;
//     Node *left;
//     Node *right;
//     int height;
// };
 
// // A utility function to get maximum
// // of two integers
// int max(int a, int b);
 
// // A utility function to get the
// // height of the tree
// int height(Node *N)
// {
//     if (N == NULL)
//         return 0;
//     return N->height;
// }
 
// // A utility function to get maximum
// // of two integers
// int max(int a, int b)
// {
//     return (a > b)? a : b;
// }
 
// /* Helper function that allocates a
//    new node with the given key and
//    NULL left and right pointers. */
// Node* newNode(int key)
// {
//     Node* node = new Node();
//     node->key = key;
//     node->left = NULL;
//     node->right = NULL;
//     node->height = 1; // new node is initially
//                       // added at leaf
//     return(node);
// }
 
// // A utility function to right
// // rotate subtree rooted with y
// // See the diagram given above.
// Node *rightRotate(Node *y)
// {
//     Node *x = y->left;
//     Node *T2 = x->right;
 
//     // Perform rotation
//     x->right = y;
//     y->left = T2;
 
//     // Update heights
//     y->height = max(height(y->left),
//                     height(y->right)) + 1;
//     x->height = max(height(x->left),
//                     height(x->right)) + 1;
 
//     // Return new root
//     return x;
// }
 
// // A utility function to left
// // rotate subtree rooted with x
// // See the diagram given above.
// Node *leftRotate(Node *x)
// {
//     Node *y = x->right;
//     Node *T2 = y->left;
 
//     // Perform rotation
//     y->left = x;
//     x->right = T2;
 
//     // Update heights
//     x->height = max(height(x->left),   
//                     height(x->right)) + 1;
//     y->height = max(height(y->left),
//                     height(y->right)) + 1;
 
//     // Return new root
//     return y;
// }
 
// // Get Balance factor of node N
// int getBalance(Node *N)
// {
//     if (N == NULL)
//         return 0;
//     return height(N->left) - height(N->right);
// }
 
// // Recursive function to insert a key
// // in the subtree rooted with node and
// // returns the new root of the subtree.
// Node * minValueNode(Node* node)
// {
//     Node* current = node;
 
//     /* loop down to find the leftmost leaf */
//     while (current->left != NULL)
//         current = current->left;
 
//     return current;
// }


// Node* insert(Node* node, int key)
// {
//     /* 1. Perform the normal BST insertion */
//     if (node == NULL)
//         return(newNode(key));
 
//     if (key < node->key)
//         node->left = insert(node->left, key);
//     else if (key > node->key)
//         node->right = insert(node->right, key);
//     else // Equal keys are not allowed in BST
//         return node;
 
//     /* 2. Update height of this ancestor node */
//     node->height = 1 + max(height(node->left),
//                         height(node->right));
 
//     /* 3. Get the balance factor of this ancestor
//         node to check whether this node became
//         unbalanced */
//     int balance = getBalance(node);
 
//     // If this node becomes unbalanced, then
//     // there are 4 cases
 
//     // Left Left Case
//     if (balance > 1 && key < node->left->key)
//         return rightRotate(node);
 
//     // Right Right Case
//     if (balance < -1 && key > node->right->key)
//         return leftRotate(node);
 
//     // Left Right Case
//     if (balance > 1 && key > node->left->key)
//     {
//         node->left = leftRotate(node->left);
//         return rightRotate(node);
//     }
 
//     // Right Left Case
//     if (balance < -1 && key < node->right->key)
//     {
//         node->right = rightRotate(node->right);
//         return leftRotate(node);
//     }
 
//     /* return the (unchanged) node pointer */
//     return node;
// }
 
// // A utility function to print preorder
// // traversal of the tree.
// // The function also prints height
// // of every node
// void preOrder(Node *root)
// {
//     if(root != NULL)
//     {
//         cout << root->key << " ";
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }
 
// // Driver Code
// void print2DUtil(Node *root, int space)
// {
//     // Base case
//     if (root == NULL)
//         return;
 
//     // Increase distance between levels
//     space += 10;
 
//     // Process right child first
//     print2DUtil(root->left, space);
 
//     // Print current node after space
//     // 10
//     cout<<endl;
//     for (int i = 10; i < space; i++)
//         cout<<" ";
//     cout<<root->key<<"\n";
 
//     // Process left child
//     print2DUtil(root->right, space);
// }



// Node* deleteNode(Node* root, int key)
// {
     
//     // STEP 1: PERFORM STANDARD BST DELETE
//     if (root == NULL)
//         return root;
 
//     // If the key to be deleted is smaller
//     // than the root's key, then it lies
//     // in left subtree
//     if ( key < root->key )
//         root->left = deleteNode(root->left, key);
 
//     // If the key to be deleted is greater
//     // than the root's key, then it lies
//     // in right subtree
//     else if( key > root->key )
//         root->right = deleteNode(root->right, key);
 
//     // if key is same as root's key, then
//     // This is the node to be deleted
//     else
//     {
//         // node with only one child or no child
//         if( (root->left == NULL) ||
//             (root->right == NULL) )
//         {
//             Node *temp = root->left ?
//                          root->left :
//                          root->right;
 
//             // No child case
//             if (temp == NULL)
//             {
//                 temp = root;
//                 root = NULL;
//             }
//             else // One child case
//             *root = *temp; // Copy the contents of
//                            // the non-empty child
//             free(temp);
//         }
//         else
//         {
//             // node with two children: Get the inorder
//             // successor (smallest in the right subtree)
//             Node* temp = minValueNode(root->right);
 
//             // Copy the inorder successor's
//             // data to this node
//             root->key = temp->key;
 
//             // Delete the inorder successor
//             root->right = deleteNode(root->right,
//                                      temp->key);
//         }
//     }
 
//     // If the tree had only one node
//     // then return
//     if (root == NULL)
//     return root;
 
//     // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
//     root->height = 1 + max(height(root->left),
//                            height(root->right));
 
//     // STEP 3: GET THE BALANCE FACTOR OF
//     // THIS NODE (to check whether this
//     // node became unbalanced)
//     int balance = getBalance(root);
 
//     // If this node becomes unbalanced,
//     // then there are 4 cases
 
//     // Left Left Case
//     if (balance > 1 &&
//         getBalance(root->left) >= 0)
//         return rightRotate(root);
 
//     // Left Right Case
//     if (balance > 1 &&
//         getBalance(root->left) < 0)
//     {
//         root->left = leftRotate(root->left);
//         return rightRotate(root);
//     }
 
//     // Right Right Case
//     if (balance < -1 &&
//         getBalance(root->right) <= 0)
//         return leftRotate(root);
 
//     // Right Left Case
//     if (balance < -1 &&
//         getBalance(root->right) > 0)
//     {
//         root->right = rightRotate(root->right);
//         return leftRotate(root);
//     }
 
//     return root;
// }


// int main()
// {
//     Node *root = NULL;
     
//     /* Constructing tree given in
//     the above figure */
//     root = insert(root, 1);
//     root = insert(root, 2);
//     root = insert(root, 3);
//     root = insert(root, 4);
//     root = insert(root, 0);

     
//     /* The constructed AVL Tree would be
//             30
//             / \
//             20 40
//             / \ \
//             10 25 50
//     */
//     print2DUtil(root, 1);

//     root = deleteNode(root,  2);


//     print2DUtil(root, 1);
//     cout << "Preorder traversal of the "
//             "constructed AVL tree is \n";
//     preOrder(root);
     
//     return 0;
// }

int     main()
{

{  std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  std::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  }
    std::cout << "helloooo\n";
  {
  ft::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( ft::pair<char,int>('a',100) );
  mymap.insert ( ft::pair<char,int>('z',200) );

  ft::pair<ft::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( ft::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  ft::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  ft::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  }
/* -------------clear test------------------ */

/*{  std::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;
  mymap.clear();

  std::cout << "mymap contains:\n";
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
    }
    std::cout << "hoooooo\n";
  {  ft::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;
  mymap.clear();

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';}*/
/* -------------erase and find test------------------ */
/*
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';


}

{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';

  return 0;
}*/

/*  {std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  }
  std::cout << "heeeey\n";
{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}*/
/* -------------Swap test------------------ */
/*{  std::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}
std::cout << "------------------------------\n";
  { 
    
  ft::map<char,int> bar;
  ft::map<char,int> foo;
  foo['x'] = 100;
  foo['y']= 200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);


  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;}*/
}