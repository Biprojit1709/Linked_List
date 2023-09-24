#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node* header1, *header2,*header3;

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

struct node* mergeLL(struct node* header1, struct node *header2){
    
    struct node *ptr1, *ptr2, *ptr3,*header3, *new;
    header3 = (struct node*)malloc(sizeof(struct node));
    header3->link=NULL;
    header3->data=0;
    ptr1 = header1->link;
    ptr2 = header2->link;
    ptr3 = header3;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data < ptr2->data){
            new = (struct node*)malloc(sizeof(struct node));
            new->data= ptr1->data;
            new->link = NULL;
            ptr3->link = new;
            ptr3=new;
            ptr1=ptr1->link;

        }else if(ptr1->data == ptr2->data){
            new = (struct node*)malloc(sizeof(struct node));
            new->data= ptr1->data;
            new->link = NULL;
            ptr3->link = new;
            ptr3=new;
            ptr2= ptr2->link;
            ptr1 = ptr1->link;
        }else{
            new = (struct node*)malloc(sizeof(struct node));
            new->data= ptr2->data;
            new->link = NULL;
            ptr3->link = new;
            ptr3=new;
            ptr2=ptr2->link;
        }
    } 
    while(ptr1!=NULL){
        new =  (struct node*)malloc(sizeof(struct node));
        new->data = ptr1->data;
        ptr3->link = new;
        ptr3=new;
        ptr1= ptr1->link;
    }
    while(ptr2!=NULL){
        new = (struct node*)malloc(sizeof(struct node));
        new->data = ptr2->data;
        ptr3->link = new;
        ptr3=new;
        ptr2= ptr2->link;
    }
    return header3;
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
    header1 = (struct node*)malloc(sizeof(struct node));
    header1->link=NULL;
    header1->data=0;

    header2 = (struct node*)malloc(sizeof(struct node));
    header2->link=NULL;
    header2->data=0;

    int n1,n2;
    printf("Enter the number of 1st Linked List : ");
    scanf("%d", &n1);
    createLL(header1,n1);
    printLL(header1);
    

    printf("Enter the number of 2nd Linked List : ");
    scanf("%d", &n2);
    createLL(header2, n2);
    printLL(header2);

    sortLL(header1);
    sortLL(header2);

    header3 = mergeLL(header1, header2);
    printf("\nThe Merged Linked List is : \n");
    printLL(header3);

    return 0;
}