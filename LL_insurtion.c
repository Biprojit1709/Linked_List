#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node* header, *ptr, *new;
void createLL(struct node *header, int n){    //Function to create a Linked list
    struct node *ptr, *new;
    int ele,i;
    ptr = header;
    for(i=1;i<=n;i++){
        printf("Enter the Element : ");
        scanf("%d", &ele);
        new =(struct node*)malloc(sizeof(struct node));
        new->link=NULL;
        new->data= ele;
        ptr->link= new;
        ptr=new;
    }
}
void printLL(struct node *header){    //Print the linked list
    struct node* prnt;
    prnt = header->link;
    while(prnt!=NULL){
        printf("%d -> ", prnt->data);
        prnt= prnt->link;
    }
    printf("NULL\n");
}
struct node* insert(int ele, int pos){
    int i;
    struct node* ins = (struct node*)malloc(sizeof(struct node));
    ins->data = ele;
    ptr = header->link;
    for(i=1; i<pos-1; i++){
        ptr = ptr->link;
    }
    new = ptr->link;
    ptr->link = ins;
    ins->link=new;
    return header;
}


int main(){
    int num, element,pos;
    header = (struct node*)malloc(sizeof(struct node));
    header->link= NULL;
    header->data= 0;
    printf("Enter the Number of Elements : ");
    scanf("%d", &num);
    createLL(header, num);

    printf("\nEnter the Element you want to insert: ");
    scanf("%d", &element);
    printf("Enter the position you want to insert the Element : ");
    scanf("%d",&pos);
    header = insert(element, pos);
    printf("The linked list is : ");
    printLL(header);

return 0;
}