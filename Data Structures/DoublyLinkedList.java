import java.util.Iterator;

public class DoublyLinkedList<T> implements Iterable<T> {

    private class Node<T>{
        public T data; 
        public Node<T> next; 
        public Node<T> prev;

        public Node(T data, Node<T> prev, Node<T> next){
            this.data = data;
            this.prev = prev; 
            this.next = next;
        }
    }

    private int size = 0; 
    private Node<T> head = null;
    private Node<T> tail = null; 

    public DoublyLinkedList(){}

    public int size(){
        return size; 
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public void addLast(T e){
        if (size == 0){
            head = tail = new Node<T>(e, null, null);
        } else {
            tail.next = new Node<T>(e, tail, null);;
            tail = tail.next;
        }
        size++; 
    }

    public void addFirst(T e){
        if(size == 0){
            head = tail = new Node<T>(e, null, null);
        } else {
            head.prev = new Node<T>(e, null, head);
            head = head.prev;
        } 
        size++;
    }

    public void addAt(int index, T e) throws Exception{
        if(index < 0 || index > size){
            throw new Exception("Illegal Index");
        }

        if(index == 0){
            addFirst(e);
        } else if(index == size){
            addLast(e);
        } else {
            Node<T> curr = head;
            int i = 1;
            while(i != index){
                curr = curr.next;
                i++;
            }
            curr.next.prev = new Node<T>(e, curr, curr.next);
            curr.next = curr.next.prev;
            size++;
        }
    }

    public T peekFirst(){
        if (size == 0) throw new RuntimeException("Empty List");
        return head.data;
    }

    public T peekLast(){
        if (size == 0) throw new RuntimeException("Empty List");
        return tail.data;
    }

    public T removeFirst(){
        if(size == 0) throw new RuntimeException("Empty List");
        T item = head.data; 
        head = head.next;
        size--; 

        if(size == 0){
            tail = null; 
        } else {
            head.prev = null; 
        }
        return item;
    }

    public T removeLast(){
        if(size == 0) throw new RuntimeException("Empty List");
        T e = tail.data; 
        tail = tail.prev;
        size--; 
        if(size == 0){
            head = null;
        } else {
            tail.next = null; 
        }
        return e;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {

            private Node<T> itr = head; 

            @Override
            public boolean hasNext() {
                return itr != null;
            }

            @Override
            public T next() {
                T item = itr.data;
                itr = itr.next;
                return item;
            }
        };
    }
}