package Algorithms.Backtracking;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class PowerSet {

    /*
     * Return all possible subsets of a list of numbers
     * Runtime: O(2^n), n is the size of the list
     */

    public static List<List<Integer>> powerSet(int[] nums){
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Stack<Integer> current = new Stack<Integer>();

        backtracking(0, current, result, nums);
        return result;
    }

    /*
     * Decision tree solution
     * Decision space: add and don't add
     */
    private static void backtracking(int i, Stack<Integer> curr, List<List<Integer>> res, int[] nums){
        if(i == nums.length){
            res.add(new ArrayList<>(curr));
            return;
        }

        // Add
        curr.push(nums[i]);
        backtracking(i+1, curr, res, nums);

        // Don't add
        curr.pop();
        backtracking(i+1, curr, res, nums);

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
        // int[] nums = {3,6,9};
        int[] nums = {2,4};
        System.out.println(powerSet(nums));

    }
    
}
