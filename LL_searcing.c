#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *header, *ptr, *new;
int main(){
    int n, ele,i,key, found =0 ;
    header = (struct node*)malloc(sizeof(struct node));
    header->link=NULL;
    header->data=0;
    ptr = header;
    printf("Enter the number of Nodes : ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        printf("Enter the Element : ");
        scanf("%d", &ele);
        new = (struct node*)malloc(sizeof(struct node));
        new->link=NULL;
        new->data=ele;
        ptr->link=new;
        ptr=new ;
    }
    int index=1;
    printf("Enter the Element you want to search : ");
    scanf("%d", &key);
    struct node *search;
    search=header->link;
    while(search != NULL && found==0){
        if(search->data==key){
            found= 1;
            break;
        }else{
            search=search->link;
            index ++;
        }
    }
    if(found==0){
        printf("The The Element is not found .\n");
    }else{
    printf("The Element %d is present at %d position.", key, index);
    }
    return 0;
}