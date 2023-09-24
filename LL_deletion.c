#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node *header, *ptr, *next, *trv;

void printLL(struct node *header, int n); //function to print the LL
struct node travs(struct node *header, struct node *trv, int n); //fuction to travars to nth element
struct node delnode(struct node *header);


int main(){
    header = (struct node*) malloc(sizeof(struct node));
    header->data = (int)NULL;
    header->link = NULL;
    ptr = header;
    int i,n, ele, eleD;
    printf("Enter the number of Elements you want to add in Linked List : ");
    scanf("%d", &n);
        for(i=1; i<=n; i++){
        printf("Enter the Element : "); 
        scanf("%d", &ele);
        next = (struct node*) malloc(sizeof(struct node));
        next->data = ele;
        next->link = NULL;
        ptr->link= next;
        ptr=next ;
    }
    printLL(header, n);

    delnode(header);
    printLL(header, n-1);

    return 0;
}
void printLL(struct node *header, int n){
    struct node* temp =(struct node*) malloc(sizeof(struct node));
    printf("\nThe Linked List is : \n");
    temp =header->link;
    for(int i=1; i<=n; i++){
        printf("%d ", temp->data);
        temp =temp->link;
    } 
    printf("\n");
}
struct node travs(struct node *header, struct node *trv,int n){ 
    trv =(struct node*) malloc(sizeof(struct node));
    trv = header->link;
    for(int i=1; i<=n; i++){
        trv = trv->link;
    }
    return *trv;
}
struct node delnode(struct node* header){
    int eleD, index=1;
    struct node *del, *delNxt;
    printf("Enter the Element you want to delete : ");
    scanf("%d", &eleD);
    del = header->link;
    while(del->data != eleD){
        del=del->link;
        index ++;
    }
    delNxt= del->link;
    struct node *final;
    final= header->link;
    for(int i=1; i<index-1; i++){
        final =final->link;
    } 
    final->link = delNxt;
    free(del);
}

