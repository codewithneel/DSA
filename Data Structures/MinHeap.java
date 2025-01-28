public class MinHeap {
    
    int capacity = 10;
    int size = 0; 
    int[] H = new int[capacity];

    private int getLeftChildIndex(int parentIndex){
        return (2*parentIndex) + 1; 
    }

    private int getRightChildIndex(int parentIndex){
        return (2*parentIndex) + 2; 
    }

    private int getParentIndex(int childIndex){
        return (childIndex-1)/2;
    }

    private boolean hasParent(int childIndex){
        return childIndex > 0 ? true : false;
    }

    private boolean hasLeftChild(int parentIndex){
        return getLeftChildIndex(parentIndex) < size ? true : false;
    }

    private boolean hasRightChild(int parentIndex){
        return getRightChildIndex(parentIndex) < size ? true : false;
    }

    private int getParent(int childIndex){
        return H[getParentIndex(childIndex)];
    }

    private int getLeftChild(int parentIndex){
        return H[getLeftChildIndex(parentIndex)];
    }

    private int getRightChild(int parentIndex){
        return H[getRightChildIndex(parentIndex)];
    }

    private void swap(int index1, int index2){
        int temp = H[index1];
        H[index1] = H[index2]; 
        H[index2] = temp;
    }

    private void ensureCapacity(){
        if(size == capacity){
            capacity *= 2;
            int[] temp = new int[capacity];
            for(int i = 0; i < H.length; i++){
                temp[i] = H[i];
            }
            H = temp;
        }
    }

    public int peek(){
        if(size == 0) throw new IllegalStateException();
        return H[0];
    }

    public int poll(){
        if(size == 0) throw new IllegalStateException();
        int key = H[0];
        H[0] = H[size-1];
        size--;
        heapifyDown();

        return key;
    }

    public void add(int item){
        ensureCapacity();
        H[size] = item;
        size++; 
        heapifyUp(); 
    }

    public void heapifyDown(){
        int index = 0;
        while(hasLeftChild(index)){
            int smallerChildIndex = getLeftChildIndex(index);
            if(hasRightChild(index) && getRightChild(index) < getLeftChild(index)){
                smallerChildIndex = getRightChildIndex(index);
            }
            if(H[index] < H[smallerChildIndex]){
                break; 
            } else {
                swap(index, smallerChildIndex);
                index = smallerChildIndex; 
            }
        }
    }

    public void heapifyUp(){
        int index = size-1; 
        while(hasParent(index) && getParent(index) > H[index]){
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }
}
