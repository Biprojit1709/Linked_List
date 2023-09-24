#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *header, *ptr, *new;

void createLL(struct node *header, int n){    //Function to create a Linked list
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
void printLL(struct node *header){    //Function to Print the linked list
    struct node* prnt;
    prnt = header->link;
    while(prnt!=NULL){
        printf("[%d] -> ", prnt->data);
        prnt= prnt->link;
    }
    printf("NULL\n");
}
struct node* insert(int ele, int pos){ //Function for Insertion
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
void insertion_LL(){   // Insert a node in Linked list
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
}
struct node* delnode(struct node* header){  //Function for delete
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
    return header;
}
void deletion_LL(){       //Delete a node in Linked list 
    int i,n, ele, eleD;
    header = (struct node*) malloc(sizeof(struct node));
    header->data = (int)NULL;
    header->link = NULL;
    printf("Enter the number of Elements you want to add in Linked List : ");
    scanf("%d", &n);
    createLL(header, n);
    printLL(header);

    header = delnode(header);
    printLL(header);
}
struct node *reverseLL(struct node *header){ //Function for reversal
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
void reversal_LL(){  //Reverse a Linked List
    int n;
    header = (struct node *)malloc(sizeof(struct node));
    header->link=NULL;
    header->data=(int)NULL;
    printf("Enter the number of Elements you want to add in Linked List : ");
    scanf("%d", &n);
    createLL(header, n);
    printf("Before the reversal, The Linked List is : \n");
    printLL(header);

    header = reverseLL(header);

    printf("\nAfter the Reversal, The Linked List is : \n");
    printLL(header);
}

void search_LL(){   //Search in Linked List
    int n, ele,i,key, found =0 ,index=1;
    header = (struct node*)malloc(sizeof(struct node));
    header->link=NULL;
    header->data=0;
    printf("Enter the number of Elements you want to add in Linked List : ");
    scanf("%d", &n);
    createLL(header, n);
    printf("Enter the Element you want to search : ");
    scanf("%d", &key);
    struct node *search;
    search=header->link;
    while(search!=NULL && found==0){
        if(search->data==key){
            found= 1;
        }else{
            search=search->link;
            index ++;
        }
    }
    if(found==0){
        printf("The The Element is not found .\n");
    }else{
    printf("The Element %d is present at %d position.\n", key, index);
    }
}

void travarsal_LL(){   //Travarsal in Linked List
    int n;
    header = (struct node *)malloc(sizeof(struct node));
    header->link=NULL;
    header->data=(int)NULL;
    printf("Enter the number of Elements you want to add in Linked List : ");
    scanf("%d", &n);
    createLL(header, n);
    printf("\n The Linked List is : ");
    printLL(header);
}
struct node* sortLL(struct node *header){ //Function for Sorting
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
    return header;
}
void sort_LL(){   //Sort Linked List    
    header = (struct node*)malloc(sizeof(struct node));
    header->link=NULL;
    header->data=0;

    int n;
    printf("Enter the number of Linked List : ");
    scanf("%d", &n);
    createLL(header,n);
    printLL(header);
    printf("\n");
    printf("Original Linked List is : \n");
    printLL(header);
    header = sortLL(header);
    printf("Sorted Linked List is : \n");
    printLL(header);
}
struct node* concat(struct node *header1, struct node *header2){
    struct node *concat;    //Function For Concatination
    concat=header1->link;
    while(concat->link!=NULL){
        concat=concat->link;
    }
    concat->link= header2->link;
    free(header2);
    return header1;
}
void concat_LL(){   //Concatination in Linked List
    int n1, n2;
    struct node* header1 = (struct node*)malloc(sizeof(struct node));
    struct node* header2 = (struct node*)malloc(sizeof(struct node));
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
}
struct node* mergeLL(struct node* header1, struct node *header2){                                                           
    struct node *ptr1, *ptr2, *ptr3,*header3, *new;    //Function for Merge
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
void merge_LL(){   //Merge in Linked List
    struct node *header1, *header2, *header3;
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
}


int main(){
    int key;
    printf("Enter 1 for Travarsal. \nEnter 2 for Insertion. \nEnter 3 for Deletion.");
    printf("\nEnter 4 for Reversal .");
    printf("\nEnter 5 for Searching. \nEnter 6 for Sorting. \nEnter 7 for Concatination.");
    printf("\nEnter 8 for Merge Linked List . \n");
    printf("\nEnter Your Option :  ");
    scanf("%d", &key);
    switch(key){
        case 1: 
        travarsal_LL();
        break;

        case 2: 
        insertion_LL();
        break;

        case 3:
        deletion_LL();
        break;

        case 4: 
        reversal_LL();
        break;

        case 5 :
        search_LL();
        break;

        case 6 : 
        sort_LL();
        break;

        case 7 : 
        concat_LL();
        break;

        case 8 :
        merge_LL();
        break;

        default:
        printf("Error ! Enter the Right Value .\n");
        main();
    }
    int st;
    printf("Enter 1 for Continue And 0 for Exit : ");
    scanf("%d", &st);
    printf("\n");
    if(st==1){
        main();
    }else{
        printf("\n               Thanks              \n");
        printf("____________________________________________________");
        return 0;
    }
    return 0;
}