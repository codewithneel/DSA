package Algorithms;

public class PrintAllBinary{

    /*
     * Prints every binary number with n (digits) bits
     * Runtime: O(2^n)
     */
    public static void printAllBinary(int digits){
        printAllBinaryHelper("", digits);
    }

    /*
     * Decision tree solution: Permutation + exhaustive search 
     * Choices: {0, 1}
     */
    private static void printAllBinaryHelper(String s, int digits){
        if(digits == 0){
            System.out.println(s);
            return;
        }

        for(char bit = '0'; bit <= '1'; bit++){
            printAllBinaryHelper(s + bit, digits - 1);
        }
    }

    public static void main(String[] args){
        System.out.println("printAllBinary(3):");
        printAllBinary(3);
    }

}