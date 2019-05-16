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
#include <iostream>

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
        int val = a;
        struct Node *node = (struct Node *) malloc(sizeof(Node));
        node->data = a;
        node->next = NULL;
        return ((struct Node*) node);
    }
    // Append to List
    void Append (int a){
        
        int val = a;
        
        if ((struct Node*)Header== NULL){
            Header = init(a);
        }
        struct Node *prt = Header;
        
        if (a>0)
            val = a;
        if ((struct Node*)Header!= NULL){
            while (prt->next != NULL){ prt = prt->next;}
            prt->next = New(a);
        }
    }
    // Print
    void Print(){
        if (Header->data <= 0)
            printf("Node Empty!");
        if (Header == NULL ) return;
        struct Node *prt = Header;
        while (prt!= NULL){
            printf("%d\n", prt->data);
            prt = prt->next;
        }
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
}List;

void Tester(struct List *list){
    
    struct List *myList= list;
    int myArray[] = {10,11,12,13,14,15,16,17,18,19,20,21,22};
    
    int expectedValue = 16;
    
    for ( int i = 0; i < (sizeof (myArray)/sizeof(int)); i++)
    {
        myList->Append(myArray[i]);
        std::cout<<(i);
    }
    myList->Print();
    
    if(expectedValue == myList->middleElement()->data){
        std::cout<<"Success";
        std::cout<<myList->middleElement()->data;
        std::cout<<expectedValue;
    };
};


int main() {
    struct List *myList = (struct List*) malloc(sizeof(struct List));
    Tester(myList);
    return 0;

}



