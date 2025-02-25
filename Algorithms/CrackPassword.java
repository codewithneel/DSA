package Algorithms;

public class CrackPassword {

    /*
     * Returns password if login is successful
     * Password consists of only lowercase letters (a-z), special symbols (!, ?, .), and numbers (0,9) 
     * len: length of password
     * Runtime: O(39^n), n = len of password and base 39 represents the number of choices
     */
    public static String crackPassword(int len){
        return crackPasswordHelper(len, "");
    } 

    private static String crackPasswordHelper(int len, String output){
        
        //base case: when length of set (length of string) is equal to the length of the password
        if(len == 0){
            System.out.println(output);     //print all attempts
            if(login(output)){              //if login successful, return password
                return output;
            } else {                        //invalid login attempt, backtrack
                return "";
            }
        }else{
            //choices {a-z}
            for(char c = 'a'; c <= 'z'; c++){
                if(crackPasswordHelper(len-1, output+c) != "") return output;
            }

            //choices {0-9}
            for(char c = '0'; c <= '9'; c++){
                if(crackPasswordHelper(len-1, output+c) != "") return output;
                }

            //choices {., !, ?}
            if(crackPasswordHelper(len-1, output+'.') != "" || crackPasswordHelper(len-1, output+'!') != "" || crackPasswordHelper(len-1, output+'?') != "") {
                return output;                
            }
        }
        return "";
    }

    private static boolean login(String passcode){
        return "2.np".equals(passcode);
    }

    public static void main(String[] args){
        crackPassword(4);
    }
}
