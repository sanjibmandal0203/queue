// WAP to implement a circular queue
// this coding is not appropriate
#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int que[MAX];
int front=-1, rear=-1;
void insert(int que[]);
void delete(int que[]);
void display(int que[]);
void (*call[])(int que[])={insert, delete, display, NULL};
int main(){
    int op;
    do{
        printf("\n   MAIN MENU\n 0-> insert.\n 1-> delete.\n 2-> display.\n 3-> exit.");
        printf("\n choose a option : ");
        scanf("%d", &op);
        call[op](que);
    }while(op!=3);
    return 0;
}
void display(int que[]){
    if(front==-1 && rear==-1){
        printf("\t empty que");
        printf("\t\t f->%d, r->%d", front, rear);
        return;
    }
    else{
        if(front>rear){
            int i=front;
            while(i<MAX){
                printf("\t%d", que[i]);
                i++;
            }
            i=0;
            while(i<front){
                printf("\t%d", que[i]);
                i++;
            }
        }
        else{
            int j=front;
            while(j<=rear){
                printf("\t%d,", que[j]);
                j++;
            }
        }
    }
    printf("\t\t f->%d, r->%d", front, rear);
}
void delete(int que[]){
    if(front==-1 && rear==-1){
        printf("\t underflow");
        printf("\t\t f->%d, r->%d", front, rear);
        return;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        if(front<rear){
            --front;
        }
        else{
            if(front==MAX-1)
                front=0;
            else
                --front;
        }
    }
    printf("\t deleted");
    printf("\t\t f->%d, r->%d", front, rear);
}
void insert(int que[]){
    int val;
    if(front==0 && rear==MAX-1){
        printf("\t overflow");
        printf("\t\t f->%d, r->%d", front, rear);
        return;
    }
    else{
        printf("\n put the data : ");
        scanf("%d", &val);
        if(front==-1 && rear==-1){
            front=rear=0;
            que[rear]=val;
        }
        else if(rear!=MAX-1){
            que[++rear]=val;
        }
        else if(front!=0 && rear==MAX-1){
            rear=0;
            que[rear]=val;
        }
        else if(front>rear){
            que[++rear]=val;
        }
        printf("\t inserted.");
    }
    printf("\t\t f->%d, r->%d", front, rear);
}