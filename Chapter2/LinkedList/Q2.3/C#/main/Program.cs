using System;

namespace main
{
    // In C# classes are null, set null struct and data types
    public class Node
    {
        public int? data;
        public Node next;
        public Node() { }
        public Node(int a)
        {
            this.data = a > 0 ? a : 0;
            this.next = null;
        }
    }

    public class List
    {
        public Node HEAD;
        public List() { }
        public List(int a)
        {
            HEAD = Equals(HEAD, null) ? new Node(a > 0 ? a : 0) : HEAD;
        }
        public void Append(int a)
        {
            if (Equals(HEAD, null))
                HEAD = new Node(a > 0 ? a : 0);
            else
            {
                Node prt = HEAD;
                while (!Equals(prt.next, null))
                {
                    prt = prt.next;
                }
                prt.next = new Node(a > 0 ? a : 0);
            }
        }
        public void Print()
        {
            Node prt = HEAD;
            while (!Equals(prt, null))
            {
                Console.WriteLine(prt.data);
                prt = prt.next;
            }
        }
        public void getKthNode(int a)
        {
            int l = 0;
            Node prt = HEAD;
            while (prt != null && l < a)
            {
                prt = prt.next;
                l++;
            }
            if (l == a) Console.WriteLine("==={0}==",prt.data.ToString());
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List myList = new List(20);
            int len = 0;
            while (len < 10) myList.Append(len++);
            myList.Print();
            for (int i=0;i<10;i++) myList.getKthNode(i);
           // Console.WriteLine(Equals(myList.HEAD, null));
        }
    }

}