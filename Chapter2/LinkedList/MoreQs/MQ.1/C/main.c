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
    
    void removeKthFromLast(int a){
        
        struct Node *prt = this->head;
        int l = 0;
        while (prt!=NULL){ prt=prt->next; l++;}
        l = l-a;
        while  (prt != NULL && l-- >= 0)
            prt=prt->next;
        prt = this->head;
        
        if (prt != NULL)
            prt->next = prt->next->next;
        
    }
}List;

int main(){
    struct List *myList = (struct List*) malloc(sizeof(struct List));
    myList->init(1);
    for ( int i=2;i<6;i++)
        myList->appendNodeToTail(i);
    myList->Print();
    myList->removeKthFromLast(0);
    myList->Print();
    return 0;
}
