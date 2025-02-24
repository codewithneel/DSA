package Algorithms;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class DiceSum {
    static int calls = 0;
    /* 
     * Returns all possible outcomes of rolling the given number of dice that add up to the target
     * dice: number of dice to roll
     * target: desired sum of all die values
     */
    public static List<List<Integer>> diceSum(int dice, int target){
        List<List<Integer>> sol = new ArrayList<List<Integer>>();
        diceSumHelper(dice, target, new Stack<Integer>(), sol);
        System.out.println(calls);
        return sol; 
    } 

    public static void diceSumHelper(int dice, int target, Stack<Integer> curr, List<List<Integer>> sol){
        calls++;
        if(dice == 0){
            if(target == 0){
                sol.add(new ArrayList<Integer>(curr));
            }
        } else if(target >= dice * 1 && target <= dice * 6){
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
