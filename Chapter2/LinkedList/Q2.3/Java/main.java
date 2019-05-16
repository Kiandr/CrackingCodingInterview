import  java.lang.System.*;

public class main {
    
    public static class Node {
        public int data;
        public Node next;
        public Node(int a){
            data = a;
            next = null;
        }
    }
    
    public static class List {
    public Node HEAD = null; 
    public List(int a){
        HEAD = HEAD != null ? new Node (a>0 ? a:0) : HEAD;
    }
    public Node removeNthFromEnd(Node head, int n) {
        Node dummy = new Node(0);
        dummy.next = head;
        int length  = 0;
        Node first = head;
        while (first != null) {
            length++;
            first = first.next;
        }
        length -= n;
        first = dummy;
        while (length > 0) {
            length--;
            first = first.next;
        }
        first.next = first.next.next;
        return dummy.next;
    }
    public void AppendToTail( int a ){
       // if (a<0) return;
       // if (prt.next != null ) 
       // Object prt = new Object();
        // while (prt.next != null) 
        //     prt = prt.next;
        // prt.next = new Node(a);
    }
    public void Print(){
        Node prt = HEAD;
        while (!prt.next.equals(null)){ 
            System.out.println(prt.toString());
            prt = prt.next;
        }
        
    }
    public void RemoveDuplicates(){}
    public void GetKthNode(int a){
        Node prt = HEAD;
        // while ( prt== null  && a>0) {
System.out.println(prt.toString());



    }
}
    public static  void main(String[] args) {
        List myList = new List(15);
        myList.removeNthFromEnd(new Node(10), 30);
        
        

        // for (int i = 16; i<=20;i++) 
            // myList.AppendToTail(i);
        //  myList.Print();
        // myList.AppendToTail(15);
        // myList.RemoveDuplicates();
        // myList.Print();
    }

}