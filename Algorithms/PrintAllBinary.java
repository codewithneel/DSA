package Algorithms;

public class PrintAllBinary{

    /*
     * Prints every binary number with n (digits) bits
     * Runtime: O(2^n)
     */
    public static void printAllBinary(int digits){
        dfs("", digits);
    }

    /*
     * Decision tree solution: Permutation + exhaustive search 
     * Choices: {0, 1}
     */
    private static void dfs(String s, int digits){
        if(digits == 0){
            System.out.println(s);
            return;
        }

        for(char c = '0'; c <= '1'; c++){
            dfs(c + s, digits - 1);
        }
    }

    public static void main(String[] args){
        System.out.println("printAllBinary(4):");
        PrintAllBinary.printAllBinary(4);
    }

}