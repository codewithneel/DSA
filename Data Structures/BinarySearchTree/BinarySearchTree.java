/*
 * BST tree implementation constraint -> stores distinct, positive integers (0 - infinity).
 * Operations run in O(h) time, h is the height of the tree.
 * Both, iterative and recursive implementation of methods can be found at the bottom of the file, iterative implementations are commented out.
 */


package BinarySearchTree;
import java.util.ArrayList;

public class BinarySearchTree{

    private TreeNode root = null; 
    private int size = 0; 

    private class TreeNode{
        public int key;
        public TreeNode left;
        public TreeNode right;
        public TreeNode parent;

        public TreeNode(int key, TreeNode left, TreeNode right, TreeNode parent){
            this.key = key;
            this.left = left;
            this.right = right;
            this.parent = parent; 
        }
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public boolean search(int key){
        if(root == null) throw new RuntimeException("Tree is empty");
        return recursiveSearch(root, key) != null;
    }

    public int treeMinimum(){
        if(root == null) throw new RuntimeException("Tree is empty");
        return recursiveTreeMinimum(root).key;
    }

    public int treeMaximum(){
        if(root == null) throw new RuntimeException("Tree is empty");
        return recursiveTreeMaximum(root).key;
    }

    /*
     * The predecessor of node x is the node that comes before node x in the inorder tree walk.
     * 
     * If key is the minimum element in the tree, return -1.
     * Otherwise, return predecessor of key.
     */
    public int predecessor(int key){
        if(root == null) throw new RuntimeException("Tree is empty");
        
        // Ensure key exists in the tree
        TreeNode x = recursiveSearch(root, key);
        if(x == null) throw new RuntimeException("Key does not exist in the tree");

        // Call predecessor(TreeNode) method (found on line 174ish) -> method overloading
        TreeNode res = predecessor(x);
        if(res != null) return res.key;
        else return -1;

    }

    /*
     * The successor of node x is the node that comes after node x in the inorder tree walk.
     * 
     * If key is the maximum element in the tree, return -1.
     * Otherwise, return successor of key.
     */
    public int successor(int key){
        if(root == null) throw new RuntimeException("Tree is empty");

        // Ensure key exists in the tree
        TreeNode x = recursiveSearch(root, key);
        if(x == null) throw new RuntimeException("Key does not exist in the tree");

        // Call successor(TreeNode x) method (found on line)
        TreeNode res = successor(x);
        if(res != null) return res.key;
        else return -1;
    }

    /*
     * Insert key in its correct position by tracing down from the root to parent node following BST property
     * 
     * If key already exists, return false.
     * Otherwise, insert key and return true.
     */
    public boolean insert(int key){
        // If tree is empty, set root to new node.
        if(root == null){
            root = new TreeNode(key, null, null, null);
            size++;
            return true;
        }

        // Trailing pointer y will point to the parent of new node x once x reaches null.
        TreeNode x = root;
        TreeNode y = null; 
        while(x != null){
            if(x.key == key){
                return false;
            }
            y = x; 
            if(key < x.key){
                x = x.left;
            } else {
                x = x.right;
            }
        }

        // Set parent left or right pointer to new node based on key comparison
        TreeNode newNode = new TreeNode(key, null, null, y);
        if(key < y.key){
            y.left = newNode;
        } else {
            y.right = newNode;
        }
        size++;
        return true;
    }

    /*
     * Deleting a key (node x) has 3 cases: 
     * 1. x has no children
     * 2. x has 1 child
     * 3. x has 2 children
     *   - If x.right is the successor of x
     *   - Else, y.right (y is the successor of x) will shift to y's position and y will replace x
     * 
     * Transplant is a helper function
     */
    public void delete(int key){
        if(root == null) throw new RuntimeException("Tree is empty");

        // Ensure key exists
        TreeNode x = recursiveSearch(root, key);
        if(x == null) throw new RuntimeException("Key does not exist in the tree");

        // If x does not have a left child, elevate right child. 
        if(x.left == null){
            transplant(x, x.right);
        // If x does not have a right child, elevate left child.
        } else if(x.right == null){
            transplant(x, x.left);
        // x has two children
        } else{
            TreeNode y = recursiveTreeMinimum(x.right);
            // If the right child is not the successor of x, replace y with y.right and set correct right pointer for y and parent pointer for y.right
            if(x.right != y){
                transplant(y, y.right);
                y.right = x.right;
                y.right.parent = y;
            }
            // Replace x with y and set correct left child of y and the parent of y's left child
            transplant(x, y);
            y.left = x.left;
            y.left.parent = y;
        }
    }

    /*
     * HELPER FUNCTION 
     * Transplant sets child parent pointer and parent left/right child pointer
     * z is the node being replaced by v
     */
    private void transplant(TreeNode z, TreeNode v){
        // If z is the root
        if(z.parent == null){
            root = v;
        // Check if z is the left or right child of its parent and have it point to v
        } else if(z.parent.left == z){
            z.parent.left = v;
        } else {
            z.parent.right = v;
        }

        // If v is not null, have it point to its parent 
        if(v != null){
            v.parent = z.parent;
        }
    }

    public String toString(){
        ArrayList<Integer> output = new ArrayList<Integer>(size);
        inorderTraversal(root, output);
        return output.toString();
    }

    private TreeNode recursiveSearch(TreeNode x, int target){
        if(x == null) return null;

        if(x.key == target){
            return x; 
        } else if(target < x.key){
            return recursiveSearch(x.left, target);
        } else {
            return recursiveSearch(x.right, target);
        }
    }

    private TreeNode recursiveTreeMinimum(TreeNode x){
        // Follow left child pointer until x.left is null.
        if(x.left == null) return x; 
        return recursiveTreeMinimum(x.left);
    }

    private TreeNode recursiveTreeMaximum(TreeNode x){
        // Follow right child pointer until x.right is null.
        if(x.right == null) return x;
        return recursiveTreeMaximum(x.right); 
    }

    /*
     * Finding the predecessor has 2 cases:
     * 1. If x has left subtree, find max of left subtree.
     * 2. Otherwise, find the lowest ancestor of x that has a right child that is also an ancestor of x.
     */
    private TreeNode predecessor(TreeNode x){
        if(x.left != null){
            return recursiveTreeMaximum(x.left);
        } else {
            TreeNode y = x.parent;
            while(y != null && y.left == x){
                x = y;
                y = y.parent;
            }
            if(y == null){
                return null;
            } else {
                return y;
            }
        }
    }

    /*
     * Finding the successor has 2 cases:
     * 1. If x has right subtree, find min of right subtree.
     * 2. Otherwise, find the lowest ancestor of x that has a left child that is also an ancestor of x.
     */
    private TreeNode successor(TreeNode x){
        if(x.right != null){
            return recursiveTreeMinimum(x.right);
        } else {
            TreeNode y = x.parent;
            while(y != null && y.right == x){
                x = y;
                y = y.parent;
            }
            if(y == null){
                return null;
            } else {
                return y;
            }
        }
    }

    private void inorderTraversal(TreeNode x, ArrayList<Integer> output){
        if(x == null) return;
        inorderTraversal(x.left, output);
        output.add(x.key);
        inorderTraversal(x.right, output);

    }

    // private TreeNode iterativeSearch(int key){
    //     TreeNode x = root; 
    //     while(x != null){
    //         if(x.key == key){
    //             return x;
    //         } else if(key < x.key){
    //             x = x.left;
    //         } else {
    //             x = x.right;
    //         }
    //     }
    //     return null;
    // }

    // private TreeNode iterativeTreeMinimum(TreeNode x){
    //     while(x.left != null){
    //         x = x.left;
    //     }
    //     return x;
    // }

    // private TreeNode iterativeTreeMaximum(TreeNode x){
    //     while(x.right != null){
    //         x = x.right;
    //     }
    //     return x;
    // }
}
