#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link ;
    };

struct node *header,*p, *new;
struct node create(struct node *create);
void printLL();

int main(){
    header = (struct node*) malloc(sizeof(struct node));
    header -> data  = (int)NULL;
    header -> link = (struct node*)NULL;
    p = header; 
    create(new);
    printf("\n");
    printLL(header);
    return 0;
}
struct node create(struct node *create){
    int n,ele;
    printf("Enter the Number of Linked list : ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        new = (struct node*) malloc(sizeof(struct node));
        printf("Enter the number : ");
        scanf("%d", &ele);
        new->data= ele;
        new->link = NULL;
        p->link = new;
        p = new; 
    }
}
void printLL(struct node *head){
    struct node *ptr = head-> link;
    printf("The elements are :\n");
    while(ptr!= NULL){
    printf("%d  ", ptr->data);
    ptr = ptr -> link;
}
}