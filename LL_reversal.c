#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
void createLL();
struct node *reverseLL(struct node *header);
void printLL(struct node* header);

struct node *header, *ptr, *next;

int main(){
    header = (struct node *)malloc(sizeof(struct node));
    header->link=NULL;
    header->data=(int)NULL;
    ptr =  header;
    
    createLL();
    printf("Before the reversal, The Linked List is : \n");
    printLL(header);

    header = reverseLL(header);

    printf("\nAfter the Reversal, The Linked List is : \n");
    printLL(header);

    return 0;
}

void createLL(){
    int n,i,ele;
    printf("Enter the number of Linked List : ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        printf("Enter the Element : ");
        scanf("%d", &ele);
        next = (struct node *)malloc(sizeof(struct node));
        next->link=NULL;
        next->data=ele;
        ptr->link=next;
        ptr=next;
    }
}
struct node *reverseLL(struct node *header){
    struct node *pnode, *cnode, *nnode;
    pnode=NULL;
    cnode= header->link;
    nnode=cnode;
    while(cnode != NULL){
        nnode=nnode->link;
        cnode->link= pnode;
        pnode=cnode;
        cnode=nnode;
    }
    header->link = pnode; 
    return header;       
}

void printLL(struct node * header){
    struct node *print;
    print= header->link;
    while(print!=NULL){
        printf("%d -> ", print->data);
        print=print->link;
    }
    printf("NULL");
}