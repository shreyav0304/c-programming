#include<stdio.h>
#define MAX 5
char queue[MAX];
int front=-1,rear=-1;
void insert(char c){
    if((rear+1)%MAX==front)
    printf("overflow\n");
    else queue[rear=(rear+1)%MAX]=c;
}
char delete(){
    if(front==-1)printf("underflow\n");
    else return queue[front=(front+1)%MAX];
}
void display(){
    if(front==-1)printf("empty\n");
    else;
    int i=front;
    while(i!=rear)printf("%c",queue[i]),i=(i+1)%MAX;
    printf("%c\n",queue[rear]);
}
int main(){
    int choice;
    char c;
    while(1){
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:scanf("%c",&c),insert(c);
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:return 0;
            default:printf("invalid choice\n");
        }
    }
}

