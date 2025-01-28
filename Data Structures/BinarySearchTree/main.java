package BinarySearchTree;

public class main {
    public static void main(String[] args){
        BinarySearchTree BST = new BinarySearchTree();
        BST.insert(100);
        BST.insert(50);
        BST.insert(75);
        BST.insert(175);
        BST.insert(200);
        BST.insert(195);
        BST.insert(0);
        // System.out.println(BST.treeMinimum());
        BST.delete(175);
        BST.delete(100);
        // System.out.println(BST.successor(100));
        // System.out.println(BST.predecessor(0));
        // System.out.println(BST.isEmpty());
        System.out.println(BST);
    }
}
