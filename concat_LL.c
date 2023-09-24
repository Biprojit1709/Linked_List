#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;    
};

struct node *header1, *header2, *ptr, *new;
void createLL(struct node* header, int n){
    ptr = header;
    int i,ele;
    for(i=1; i<=n; i++){
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the Element %d : ", i);
        scanf("%d", &ele);
        new->link=NULL;
        new->data = ele;
        ptr->link = new;
        ptr = new;
    }
}
struct node* concat(struct node *header1, struct node *header2){
    struct node *concat;
    concat=header1->link;
    while(concat->link!=NULL){
        concat=concat->link;
    }
    concat->link= header2->link;
    free(header2);
    return header1;
}
void printLL(struct node *header){
    struct node* prnt;
    prnt = header->link;
    while(prnt!=NULL){
        printf("%d -> ", prnt->data);
        prnt= prnt->link;
    }
    printf("NULL\n");
}
int main(){
    int n1, n2;
    header1 = (struct node*)malloc(sizeof(struct node));
    header2 = (struct node*)malloc(sizeof(struct node));
    header1->link=NULL;
    header2->link=NULL;
    header1->data=0;
    header2->data=0;

    printf("Enter the number of 1st elements : ");
    scanf("%d", &n1);
    createLL(header1, n1);
    printf("\nEnter the number of 2nd elements : ");
    scanf("%d", &n2);
    createLL(header2, n2);
    printf("\nOriginal Lined list 1 : ");
    printLL(header1);
    printf("\nOringinal Linked list 2 :");
    printLL(header2);

    header1 = concat(header1, header2);

    printf("\nAfter the Concatination, The linked List is : \n");
    printLL(header1);

    return 0; 
}
