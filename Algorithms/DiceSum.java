package Algorithms;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class DiceSum {

    /* 
     * Returns all possible outcomes of rolling the given number of dice that add up to the target
     * Runtime: O(n*6^n)
     */
    public static List<List<Integer>> diceSum(int dice, int target){
        List<List<Integer>> sol = new ArrayList<List<Integer>>();
        diceSumHelper(dice, target, new Stack<Integer>(), sol);
        return sol; 
    } 

    /*
     * Decision tree solution: Permutation + exhaustive search 
     * Choices: {1-6}
     */
    public static void diceSumHelper(int dice, int target, Stack<Integer> curr, List<List<Integer>> sol){
        if(dice == 0){
            if(target == 0){
                sol.add(new ArrayList<Integer>(curr));
            }
        } else if(target >= dice * 1 && target <= dice * 6){ //Optimization step (trim branches): if target is not within the bounds of possible values for the number of dice left to roll, then withdraw from path
            for(int i = 1; i <= 6; i++){
                curr.push(i);
                diceSumHelper(dice-1, target-i, curr, sol);
                curr.pop();
            }
        }

    }

    public static void main(String[] args){
        System.out.println("diceSum(3, 7)");
        System.out.println(diceSum(3,7));
    }
}
