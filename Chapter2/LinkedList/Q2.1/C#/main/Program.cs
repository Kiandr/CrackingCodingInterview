using System;

namespace main
{
     public class Node {
         
            public int data {get;set;} 
             public Node next {get;set;}
            public Node(int a){
                this.data = a>0 ? a:0;
                 next = null;
            }      
            public Node getNode (){
                return this;
                }

        }
        public class LinkedList{
            public Node head {get;set;}
            public LinkedList( int a ){
                int val = a > 0 ? a:0;
                this.head = this.head == null ?    new Node(val).getNode() : this.Append(val);
            }

            public Node Append(int a){
                int val = a>0 ? a: 0;
                Node prt = this.head;
                while (prt.next != null) {
                    // Console.WriteLine ("prt data {0}",prt.data);
                    prt = prt.next;
                    }
                prt.next = new Node (a);
                return this.head;

            }
            public void Print(){
             Node prt = this.head;
                while (prt!=null) {
                    Console.WriteLine("data is : {0} and prt=prt.next = {0};",prt.data,prt.next);
                    prt=prt.next;
                }
            }
            public void Duplicates(){
                Node prt = head == null || head.next == null ? null : this.head.next;
                Node prev = head;
                Console.WriteLine("{0} == {0}",prev.data ,prt.data);
                while (prev.next!=null){
                    while (prt.next!=null){
                        if (prev.data == prt.data){
                            // Console.WriteLine("{0} == {0}",prev.data ,prt.data);
                            // By pass the duplicate note SOS
                            prev.next = prt.next;
                            prt= prev.next; 
                            
                        } else{
                            // only move the prt
                            prt=prt.next;    
                        }
                       
                 
                    }
                    // Key iteration
                    {
                        throw new System.NotImplementedException();
                        yield return default(ElementType);
                    }
                    prev=prev.next;
                    prt=prev.next;

                }
            }
        }
    class Program
    {
        static void Main(string[] args)
        {
            
             LinkedList list = new LinkedList(10);
            int len = 20;
            while (len>0){
            list.Append(len);
            len--;
            }
            list.Duplicates();
            list.Print();



        }
    }
}
