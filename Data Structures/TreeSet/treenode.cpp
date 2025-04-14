#include "treenode.h"
#include "treeset.h"
#include <stdexcept>
#include <iostream>
#include <vector>

TreeSet::TreeSet(){
    root = nullptr;
    size = 0; 
}

/*Time complexity: O(n)*/
//delete children before deleting parent
TreeSet::~TreeSet(){
    deleteTree(root);
}


//helper function for destructor
void TreeSet::deleteTree(TreeNode* node){
    if(node != nullptr){
        deleteTree(node->left);
        deleteTree(node->right);
        delete node; 
    }
}

/*Time complexity: O(logn) on average*/
//single path walk from root
void TreeSet::add(int value){
    addHelper(root, value);
}

void TreeSet::addHelper(TreeNode*& node, int value){
    if(node == nullptr){
        //location of where to insert value secured
        node = new TreeNode(value);
        size++;
    }else if(node->data > value){
        addHelper(node->left, value);
    }else if(node->data < value){
        addHelper(node->right, value);
    }//else{
        //node->data == value: value is a duplicate. Do nothing!
    // }
}

/*Time complexity: O(logn) on average*/
void TreeSet::remove(int value){
    if(removeHelper(root, value)){
        size--;
    }
}

bool TreeSet::removeHelper(TreeNode*& node, int value){
    //find value
    if(node == nullptr){
        //do nothing, value does not exist in tree
        return false;
    }else if(node->data > value){
        return removeHelper(node->left, value);
    }else if(node->data < value){
        return removeHelper(node->right, value);
    }else{
        //found value, remove value
        //case 1: leaf
        if(node->left == nullptr && node->right == nullptr){
            delete node; 
            node = nullptr;
            return true;
        }else if(node->right == nullptr){
            //case 2: node has only left child
            TreeNode* trash = node; 
            node = node->left;
            delete trash;
            return true;
        } else if(node->left == nullptr){
            //case 3: node has only right child
            TreeNode* trash = node; 
            node = node->right;
            delete trash;
            return true;
        } else {
            //case 4: node has 2 children
            /* 1. Replace value of node we want to delete with the min value of the node's right subtree
             * 2. Delete node we stole the value from (this node will have at most a right child)
             */
            int minValue = getMinHelper(node->right);
            node->data = minValue;
            return removeHelper(node->right, minValue);
        }
    }
}

/*Time complexity: O(logn) on average*/
int TreeSet::getMin() const{
    if(size == 0) throw std::runtime_error("Set is empty!");
    return getMinHelper(root);
}

int TreeSet::getMinHelper(TreeNode* node) const{
    if(node->left == nullptr){
        return node->data;
    } else {
        return getMinHelper(node->left);
    }
}

/*Time complexity: O(logn) on average*/
bool TreeSet::contains(int value) const{
    return containsHelper(root, value);
}

bool TreeSet::containsHelper(TreeNode* node, int value) const{
    if(node == nullptr){
        //value does not exist in tree
        return false;
    } else if(node->data == value){
        return true;
    } else if(node->data > value){
        return containsHelper(node->left, value);
    } else {
        return containsHelper(node->right, value);
    }
}

bool TreeSet::isEmpty() const{
    return size == 0;
}

int TreeSet::length() const{
    return size;
}

/*Time complexity: O(n)*/
std::vector<int> TreeSet::inorder() const{
    std::vector<int> output;
    inorderHelper(root, output);
    return output;
}

void TreeSet::inorderHelper(TreeNode* node, std::vector<int>& out) const{
    if(node != nullptr){
        inorderHelper(node->left, out);
        out.push_back(node->data);
        inorderHelper(node->right, out);
    }
}

void operator +=(TreeSet& set, int value){
    set.add(value);
}
void operator -=(TreeSet& set, int value){
    set.remove(value);
}