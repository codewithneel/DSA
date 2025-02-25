package Algorithms;

public class PrintAllDecimal {
    
    /*
     * Prints every decimal number with n digits
     * Runtime: O(10^n)
     */
    public static void printAllDecimal(int digits){
        printAllDecimalHelper("", digits);
    }

    /*
     * Permutation + exhaustive search 
     * Choices: {0-9}
     */
    private static void printAllDecimalHelper(String s, int digits){
        if(digits == 0){
            System.out.println(s);
            return; 
        }

        for(char dec = '0'; dec <= '9'; dec++){
            printAllDecimalHelper(s + dec, digits - 1);
        } 
        /*
         * Alternative to the for loop ->
         * 
         * printAllDecimalHelper(s + '0', digits - 1);
         * printAllDecimalHelper(s + '1', digits - 1);
         * printAllDecimalHelper(s + '2', digits - 1);
         * printAllDecimalHelper(s + '3', digits - 1);
         * printAllDecimalHelper(s + '4', digits - 1);
         * printAllDecimalHelper(s + '5', digits - 1);
         * printAllDecimalHelper(s + '6', digits - 1);
         * printAllDecimalHelper(s + '7', digits - 1);
         * printAllDecimalHelper(s + '8', digits - 1);
         * printAllDecimalHelper(s + '9', digits - 1);
         */
    }

    public static void main(String[] args){
        System.out.println("printAllDecimal(2):");
        printAllDecimal(2);
    }
}
