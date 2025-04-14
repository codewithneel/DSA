#ifndef _treeset_h
#define _treeset_h

#include "treenode.h"
#include <vector>

/*ADT Set implemented using a binary search tree.
 *Contains, add, and remove run on average O(logn) time 
 */
class TreeSet{
public:
    //constructor, destructor
    TreeSet();
    ~TreeSet();

    /*Inserts value to BST*/
    void add(int value);

    /*Removes value from BST*/
    void remove(int value);

    /*Returns true if value is found; otherwise, false*/
    bool contains(int value) const;

    /*Returns min value in BST*/
    int getMin() const;

    /*Returns a vector of elements in ascending order*/
    std::vector<int> inorder() const;

    bool isEmpty() const;
    int length() const;

private:
    TreeNode* root;
    int size;

    void deleteTree(TreeNode* node);
    void addHelper(TreeNode*& node, int value);
    bool removeHelper(TreeNode*& node, int value);
    int getMinHelper(TreeNode* node) const;
    bool containsHelper(TreeNode* node, int value) const;
    void inorderHelper(TreeNode* node, std::vector<int>& out) const;
};

void operator +=(TreeSet& set, int value);
void operator -=(TreeSet& set, int value);

#endif