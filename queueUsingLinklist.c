#include<stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue *next;
};
struct queue *font=NULL;
struct queue *rear=NULL;
void insert();
void delete();
void display();
void (*call[])()={insert, delete, display};
int main(){
    int option;
    do{
        printf("\n -  MAIN MENU  -");
        printf("\n 0: insert");
        printf("\n 1: delete");
        printf("\n 2: display");
        printf("\n 3: exit");
        printf("\n choose option : ");
        scanf("%d", &option);
        call[option]();
    }while(option!=3);
    return 0;
}//        display
void display(int *que){
    struct queue *ptr=font;
    while(ptr!=NULL){
        printf("|_%d_|", ptr->data);
        ptr=ptr->next;
    }
    printf("\t that's the queue.");
}
//         delete
void delete(){   
    if(font==NULL){
        printf("\n underflow !!");
        exit(0);
    }
    struct queue *ptr=font;
    font=font->next;
    free(ptr);
    printf("\t data deleted.");
}
//          insert
void insert(){
    struct queue *newNode=(struct queue *)malloc(sizeof(struct queue));
    int val;
    printf("\n put the data : ");
    scanf("%d", &val);
    newNode->data=val;
    if(rear==NULL){
        font=newNode;
        newNode->next=NULL;
        rear=newNode;
    }
    else if(font->next==NULL&&rear->next==NULL){
        font->next=newNode;
        newNode->next=NULL;
        rear=newNode;
    }
    else{
        rear->next=newNode;
        newNode->next=NULL;
        rear=newNode;
    }
    printf("\t data is inserted");
}