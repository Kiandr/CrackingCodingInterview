//
//  main.cpp
//
//  Created by Kian Davoudi-Rad on 2019-02-17.
//  Copyright © 2019 Kian Davoudi-Rad. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"

struct Node{
    int data;
    struct Node *next;
}Node;

struct List{
    
    struct Node *head;
    
    void init(int a){
        int headVal = a>0 ? a:0;
        this->head = (struct  Node*) malloc(sizeof(struct Node));
        this->head->data = headVal;
        this->head->next = NULL;
        
    }
    
    struct Node *newNode( int a){
        int val = a>0 ? a:0;
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        n->data = val;
        n->next = NULL;
        return n;
    }
    
    void appendNodeToTail( int a){
        int val = a>0 ? a:0;
        struct Node *prt = this->head;
        if (head == NULL){
            printf("header is empty!");
        }
        else{
            while (prt->next!=NULL)
                prt = prt->next;
            prt->next = (struct Node*) malloc(sizeof(struct Node));
            prt->next->data = val;
            prt->next->next = NULL;
        }
    }

    void Print(){
        if (head == NULL || head->next == NULL) {
            printf("header is the onl node");
            return;
        }
        struct Node *prt = this->head;
        while(prt) {
            printf("%d\n", prt->data);
            prt= prt->next;
        }  
    } 
struct Node *getKth(int a){
    
    struct Node* prt = this->head;
    
    if (prt->next == NULL || a==0) {
        printf("Header is empty or a is 0!");
        return this->head;
    }
    
    while (prt->next!= NULL && a-- > 0) {
        prt = prt->next;
    }
    return prt;
}
}List;

int main(){
    struct List *myList = (struct List*) malloc(sizeof(struct List)); //(struct List*)malloc(sizeof(struct List));
    
    myList->init(10);
    
    for ( int i=11;i<20;i++)
        myList->appendNodeToTail(i);
    
    myList->Print();
    
    for ( int i=0;i<10;i++)
    printf("data is %d\n", myList->getKth(i)->data);

    for ( int i=10;i>0;i--)
    printf("data is %d\n", myList->getKth(i)->data);
    
    
    return 0;
    }
