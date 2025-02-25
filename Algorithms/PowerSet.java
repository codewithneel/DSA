package Algorithms;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class PowerSet {
    /*
     * Returns all possible subsets of a list of UNIQUE numbers
     * Runtime: O(n * 2^n), n is the size of the list
     */

    public static List<List<Integer>> powerSet(int[] nums){
        List<List<Integer>> sol = new ArrayList<List<Integer>>();
        
        powerSetHelper(0, nums, sol, new Stack<Integer>());
        return sol;
    }

    /*
     * Combination + exhaustive search
     * Decision space: add and don't add
     * Choices: nums
     */
    private static void powerSetHelper(int i, int[] nums, List<List<Integer>> sol, Stack<Integer> curr){
        if(i == nums.length){
            sol.add(new ArrayList<>(curr));
            return;
        }

        // Add
        curr.push(nums[i]);
        powerSetHelper(i+1, nums, sol, curr);

        // Don't add
        curr.pop();
        powerSetHelper(i+1, nums, sol, curr);

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
        System.out.println(powerSet(nums));
    }
}