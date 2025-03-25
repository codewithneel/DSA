// #include "treenode.h"
#include "treeset.h"
#include <iostream>
#include <vector>

/* Binary Tree contains: O(n) */
// bool contains(TreeNode* root, int val){
//     if(root != nullptr){
//         if(root->data == val){
//             return true;
//         }
//         if(contains(root->left, val) || contains(root->right, val)){
//             return true;
//         }
//     }
//     return false; 
// }

// int size(TreeNode* root){
//     if(root == nullptr){
//         return 0;
//     }
//     return 1 + size(root->left) + size(root->right);
// }

// 2 cases to think about: empty tree and non-empty tree
// void add(TreeNode*& root, int val){
//     if(root == nullptr){
//         root = new TreeNode(val);
//     } else {
//         TreeNode* p = nullptr;
//         TreeNode* cur = root;
//         while(cur != nullptr){
//             if(val == cur->data){
//                 return;
//             } else if(val < cur->data){
//                 p = cur;
//                 cur = cur->left;
//             } else {
//                 p = cur; 
//                 cur = cur->right;
//             }
//         }
//         if(val < p->data){
//             p->left = new TreeNode(val);
//         } else {
//             p->right = new TreeNode(val);
//         }
//     }
// }

void printVector(const std::vector<int>& elements){
  std::cout << "Inorder Traveral: {";
  for(int value: elements){
    std::cout << value << " ";
  }
  std::cout << "}\n";  
}

int main(){

    TreeSet set;
    set+=7777;
    set.add(55);
    set.add(87);
    set+=29;
    set.add(42);
    set.add(42);

    std::vector<int> ordered_set = set.inorder(); 
    printVector(ordered_set);
    std::cout << "Length before removal: " << set.length() << "\n\n";

    // std::cout << set.contains(87) << "\n";
    // std::cout << set.contains(60) << "\n";
    // std::cout << set.contains(63) << "\n";
    // std::cout << set.contains(42) << "\n";

    // set-=(29);
    set-=(87);
    // set.remove(42);
    // set.remove(7777);

    ordered_set = set.inorder();
    printVector(ordered_set);
    std::cout << "Length after removal: " << set.length() << "\n";

    /* Binary Tree
    
                  55
                /   \
             87      29
            / \     / \
          -3  42  60  60
    */
    // TreeNode* root = new TreeNode(55);
    // root->left = new TreeNode(87);
    // root->right = new TreeNode(29);
    // root->left->left = new TreeNode(-3);
    // root->left->right = new TreeNode(42);
    // root->right->left = new TreeNode(60);
    // root->right->right = new TreeNode(60);

    // std::cout << contains(root, 87) << std::endl;
    // std::cout << contains(root, 60) << std::endl;
    // std::cout << contains(root, 63) << std::endl;
    // std::cout << contains(root, 42) << std::endl;

    // std::cout << size(root) << std::endl;

    // TreeNode* root = nullptr;
    // add(root, 55);
    // add(root, 87);
    // add(root, 29);
    // add(root, 42);
    // add(root, 60);
    // add(root, 60);
    // add(root, -3);

    // const TreeNode* root = new TreeNode(99);
    // std::cout << root << std::endl;
    // delete root;
    // root = nullptr;
    // std::cout << root << std::endl;


}