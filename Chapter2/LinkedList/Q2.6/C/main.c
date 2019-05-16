//
//  main.cpp
//  tester
//
//  Created by Kian Davoudi-Rad on 2019-04-07.
//  Copyright © 2019 Kian Davoudi-Rad. All rights reserved.
//
// Remove the middle node in the list.
#include "stdio.h"
#include "stdlib.h"


struct Node{
    int data;
    struct Node *next;
}Node;

struct List{
    // Header
    struct Node* Header;
    
    // Initializer
    struct Node* init(int a){
        int val = (a >= 0) ? a:0;
        Header = (struct Node*)malloc(sizeof(struct Node));
        Header->data = val;
        Header->next = NULL;
        return Header;
    }
    
    // New Node
    struct Node *New( int a){
        struct Node *node = (struct Node *) malloc(sizeof(Node));
        node->data = a;
        node->next = NULL;
        return ((struct Node*) node);
    }
    // Append to List
    void Append (int a){
        
        int val = a;
        struct Node *prt = Header;
        
        if ((struct Node*)Header== NULL){
            Header = init(a);
        }
        
        else {
        if (a>0)
            val = a;
        if ((struct Node*)Header!= NULL){
            while (prt->next != NULL){ prt = prt->next;}
            prt->next = New(a);
        }
        }
    }
    // Print
    void Print(){
        if (Header== NULL) return;
        if (Header->data <= 0)
            printf("Node Empty!");
        if (Header == NULL ) return;
        struct Node *prt = Header;
        while (prt!= NULL){
            printf("%d", prt->data);
            prt = prt->next;
        }
        printf("\n");
    }
    // Remove
    // return kth Element
    struct Node * kthElement(int val){
        if (val <= 0) return 0;
        if (Header == NULL || Header->next == NULL) return 0;
        struct Node * prt = Header;
        while (prt != NULL && val-- >=0 ){
            prt= prt->next;
        }
        return prt;
    }
    // get middle index
    int findMiddleIndex(){
        if (Header == NULL || Header->next == NULL) return 0;
        int len = 0;
        struct Node *prt = Header;
        while (prt !=NULL) {
            prt = prt->next;
            len++;
        }
        return len/2;
    }
    // return middle Element
    struct Node * middleElement(){
        int val = findMiddleIndex();
        if (val <= 0) return 0;
        if (Header == NULL || Header->next == NULL) return 0;
        struct Node * prt = Header;
        while (prt != NULL && val-- !=0 ){
            prt= prt->next;
        }
        return prt;
    }
    // SumUp:
    struct Node * SumUp( struct Node* a, struct Node* b){
        struct Node *prtA = (a!=NULL) ? a: NULL;
        struct Node *prtB= (b!=NULL) ? b: NULL;
        
        while (prtA!= NULL && prtB !=NULL){
           Append(prtA->data+prtB->data);
            prtA= prtA->next;
            prtB= prtB->next;
        }
        
        return Header;
    }
    // Reverse LinkedList()
    struct Node *ReverseAndCloneLinkedlist( struct Node * node){
        // if node is empty return null
        if (node == NULL || node->next == NULL) return node;
    }
}List;

void Tester(){
    
    struct List *ListA= (struct List*) malloc(sizeof(struct List));
    struct List *ListB= (struct List*) malloc(sizeof(struct List));
    struct List *ListC= (struct List*) malloc(sizeof(struct List));
    int ArrayA[] = {1,5};
    int ArrayB[] = {9,1};
    int len = 2;
    
    
    
    for ( int i = 0; i < len; i++)
    {
        ListA->Append(ArrayA[i]);
        ListB->Append(ArrayB[i]);
    }
    
    ListA->Print();
    ListB->Print();
    
    ListC->SumUp(ListA->Header, ListB->Header);
    ListC->Print();
    
//
//    if(expectedValue == myList->middleElement()->data){
//        std::cout<<"Success";
//        std::cout<<myList->middleElement()->data;
//        std::cout<<expectedValue;
//    };
};


int main() {
    
    Tester();
    return 0;

}



