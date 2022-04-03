#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int font=-1;
int rear=-1;
int que[MAX];
void insert(int *que);
void delete(int *que);
void display(int *que);
void (*call[])(int *que)={insert, delete, display};
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
        call[option](que);
    }while(option!=3);
    return 0;
}//        display
void display(int *que){
    int i=font;
    do{
        printf("\t %d", que[i]);
        i++;
    }while(i<=rear);
    //printf("\t %d", que[i]);
    printf("\t that's the queue.");
}
//         delete
void delete(int *que){
    if(font>rear||font==-1)
        exit(0);
    font++;
    printf("\t %d data deleted.", que[font-1]);
}
//          insert
void insert(int *que){
    if(rear==MAX-1)
        printf("\n overflow !");
    if(font==-1&&rear==-1){
        int val;
        printf("\n put the data : ");
        scanf("%d", &val);
        font++;
        rear++;
        que[rear]=val;
    }
    else{
        int val;
        printf("\n put the data : ");
        scanf("%d", &val);
        que[++rear]=val;
    }
    printf("\t data inserted.");
}