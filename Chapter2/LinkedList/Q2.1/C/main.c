#include "stdio.h"
#include "stdlib.h"
#include <time.h>
struct  Node {
struct Node *next;
int data;
} Node;

static struct Node * header;

struct Node *New(int a){
    int val = 0;
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    if (a>0){
        val = a;
    }
    node->data = val;
    node->next = NULL;
    return node;

}
struct Node* Append( struct Node *head ,int a){
int val = 0;
struct Node *prt = head;
if (a>0)
    val = a;
    if ((struct Node*)head!= NULL){
        while (prt->next != NULL){ prt = prt->next;}
        prt->next = New(a);
    }
    return head;
};
/* 
TODO: 
Sort linked list
Run this script

OR 
Run this for length of linked list 
*/
void RemoveDuplicates(struct Node *header){
    // considering corner case, when header is null, or header next is null
 if (header == NULL || header->next == NULL) return;
 struct Node *prt = header->next;
    struct Node *prev = header;
    while (prev->next != NULL){
        while(prt->next != NULL){
            // printf("%d == %d -> %d\n", prev->data, prt->data,prev->data == prt->data);
            if (prev->data == prt->data)
            {
                prev->next = prt->next;
                prt = prev->next;
                // printf("==REPLACED===\n");
            }
            else {
                prt =prt->next;
            }
        }
        // Key interation component
        prev=prev->next;
        prt=prev->next;
    }
}

void Print( struct Node *node){
    if (!node)
    printf("Node Empty!");
    
    if (node == NULL )
        return;

    struct Node *prt = node; 

    while (node!= NULL){
        printf("%d\n", node->data);
        node = node->next;
    }
    
}

int main(){
    header = New(10);
    Append(header, 5);
    Append(header, 5);
    Append(header, 5);
    Append(header, 5);
    Append(header, 5);
    int len = 5;
    while (len){
        Append(header,len--);
    }
    
    RemoveDuplicates(header);
    Print(header);
    

return 0;
    
}