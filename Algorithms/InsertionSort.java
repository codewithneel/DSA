package Algorithms;

/*
 * Runtime: O(n^2), more efficent than merge sort for small input sizes because of constant.
 * 
 * Visual: imagine you want to sort a pile of cards. Your left hand will contain the sorted cards.
 * To begin the sort, you pick up the first card from the pile with your right hand (card to sort).
 * You place the card in your left hand (sorted list) without comparison because it is the only card in the list.
 * Now, the following cards you pick from the pile will need to be compared with the sorted list (in your left hand) from right to left. 
 * If the current card (j), from sorted list, is greater than the card (A[i] or key )in the right hand, 
 * shift position of current card (j) to right (j+1); else, place card (A[i]) to the right (j+1) of the current card (j).
 * Remember! When you pick up a card from the pile, you are increasing the size of the sorted list by 1, so it is ok to shift.
 */
public class InsertionSort{
    public static void insertionSort(int[] A){
        for(int i = 1; i < A.length; i++){
            int key = A[i]; 
            int j = i-1;
            while(j >= 0 && A[j] > key){
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = key;
        }
    }
}