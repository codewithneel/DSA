#ifndef _treenode_h
#define _treenode_h

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int data){
        this->data = data;
        left = nullptr; 
        right = nullptr;
    }
};

#endif