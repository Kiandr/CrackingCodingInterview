public class main {

    public static class Node{
        public int data;
        public Node next;
        public Node (int a){
            this.data = a;
            this.next = null;
        }
    }
    public static class LinkedList{
        public Node head;
        public LinkedList( int a ){
           head = a>0 ? new Node(a) : new Node(0);
        }
        public void Append( int a ){
            Node prt = head == null ? new Node(a):this.head;
            while (prt.next != null) prt = prt.next;
            prt.next = new Node(a);
        }
        public void Print(){
            Node prt = head;
            while (prt !=null) {
                System.out.println(prt.data);
                prt = prt.next;
            }
        }
        public void Duplicates(){
            Node prt = this.head.next;
            Node prev = this.head;
            while (prev.next != null){
                
                while (prt.next != null){
                    
                    if (prt.data == prev.data){
                        prev.next = prt.next;
                        prt = prev.next;
                    }
                    else {prt = prt.next;}
                    
                }
                prev = prev.next;
                prt = prev.next;
            }
        }

    }

    public static  void main(String[] args) {
        LinkedList header = new LinkedList(10);

        int l = 20;
        while (l-- > 0) header.Append(l);

        header.Duplicates();
        header.Print();
        
    }

}