import java.util.LinkedList;

public class Stack<T> {

    LinkedList<T> list = new LinkedList<>();

    public Stack(){}

    public boolean isEmpty(){
        return list.isEmpty();
    }

    public T peek(){
        return list.peekLast();
    }

    public T pop(){
        return list.removeLast();
    }

    public void push(T data){
        list.addLast(data);
    }

    public int search(T data){
        return list.lastIndexOf(data);
    }
}
