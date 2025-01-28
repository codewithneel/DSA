public class DynamicArray<T> {

    private int size = 0;
    private int capacity; 
    private T[] array;

    public DynamicArray(){
        capacity = 10; 
        array = (T[]) new Object[capacity]; 
    }

    public DynamicArray(int initialCapacity){
        if(initialCapacity < 0) throw new IllegalArgumentException();
        capacity = initialCapacity;
        array = (T[]) new Object[capacity];
    }

    public int size(){
        return size;
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public boolean contains(T e){
        for(int i = 0; i < size; i++){
            if(array[i].equals(e)) return true;
        }
        return false;
    }

    public int indexOf(T e){
        for(int i = 0; i < size; i++){
            if(array[i].equals(e)) return i;
        }
        return -1;
    }

    private void validateIndex(int index){
        if(index < 0 || index >= size) throw new IndexOutOfBoundsException();
    }

    public T get(int index){
        validateIndex(index);
        return array[index];
    }

    public void set(int index, T e){
        validateIndex(index);
        array[index] = e;
    }

    private void resize(){
        if(capacity == 0) capacity = 10;
        else capacity *= 2;
        T[] new_arr = (T[]) new Object[capacity];
        for(int i = 0; i < size; i++){
            new_arr[i] = array[i];
        }
        array = new_arr; 
    }

    public void add(T e){
        if(size+1 > capacity) resize();
        array[size++] = e; 
    }

    public void add(int index, T e){
        if(index < 0 || index > size) throw new IndexOutOfBoundsException();
        if(size+1 > capacity) resize();
        if(index == size){ 
            array[size++] = e; 
        } else{
            for(int i = size-1; i >= index; i--){
                array[i+1] = array[i];
            }
            array[index] = e;
            size++;
        } 
    }

    public T removeAt(int index){
        validateIndex(index);
        T elementRemoved = array[index]; 
        for(int i = index+1; i < size; i++){
            array[i-1] = array[i];
        }
        size--;
        return elementRemoved; 
    }

    public boolean remove(T e){
        for(int i = 0; i < size; i++){
            if(array[i] == e){
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    public void clear(){
        for(int i = 0; i < size; i++){
            array[i] = null;
        }
        size = 0; 
    }

    @Override
    public String toString() {
        if(size == 0) return "[]"; 
        StringBuilder sb = new StringBuilder("[");
        for(int i = 0; i < size-1; i++){
            sb.append(array[i] + ", ");
        }
        return sb.append(array[size-1] + "]").toString();
    }
}