#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node* header;

void createLL(struct node *header, int n){
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
void sortLL(struct node *header){
    struct node *p, *r;
    p = header->link;
    while(p!=NULL){
        r = p->link;
        while(r!=NULL){
        if(p->data > r->data){
            int swap=0;
            swap = p->data;
            p->data = r->data;
            r->data = swap;
        }
            r=r->link;
        }
        p=p->link;
    }
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
    header = (struct node*)malloc(sizeof(struct node));
    header->link=NULL;
    header->data=0;

    int n;
    printf("Enter the number of 1st Linked List : ");
    scanf("%d", &n);
    createLL(header,n);
    printLL(header);
    printf("\n");
    sortLL(header);
    
    printLL(header);

    return 0;
    
}