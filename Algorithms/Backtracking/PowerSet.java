package Algorithms.Backtracking;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class PowerSet {

    private int[] nums;
    private List<List<Integer>> res;
    private Stack<Integer> curr;

    /*
     * Return all possible subsets of a list of numbers
     * Runtime: O(2^n), n is the size of the list
     */

    public List<List<Integer>> powerSet(int[] nums){
        this.nums = nums;
        this.res = new ArrayList<List<Integer>>();
        this.curr = new Stack<Integer>();

        backtracking(0);
        return res;
    }

    /*
     * Decision tree solution
     * Decision space: add and don't add
     */
    private void backtracking(int i){
        if(i == nums.length){
            res.add(new ArrayList<>(curr));
            return;
        }

        // Add
        curr.push(nums[i]);
        backtracking(i+1);

        // Don't add
        curr.pop();
        backtracking(i+1);

    }

    /*
     * nums = [3,6,9]
     * 
     *              []
     *  i=0        /
     *           [3]
     *  1       /   \
     *       [3,6]  [3]
     *  2    /   \
     *   [3,6,9] [3,6]
     * 
     */

    public static void main(String[] args){
        int[] nums = {3,6,9};
        // int[] nums = {2,4};
        PowerSet ps = new PowerSet();
        System.out.println(ps.powerSet(nums));
    }
}