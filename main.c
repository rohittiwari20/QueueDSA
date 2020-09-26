#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct queue
{
    int front;
    int rear;
    int items[MAX];
};
void enQueue(struct queue *q,int newitem)
{
    if(q->rear==MAX-1)
    {
        printf("Queue is Full\n ");
        exit (0);
    }
    else
    {
        if(q->front==-1)
        {
            q->front++;
            q->rear++;
            q->items[q->rear]=newitem;
        }
        else
        {
            q->rear++;
            q->items[q->rear]=newitem;
        }
    }
    printf("\n");
}
void deQueue(struct queue *q)
{
    if(q->front==-1&&q->rear==-1)
    {
        printf("Queue is Empty\n");
        exit (0);
    }
    else
    {
        if(q->front==q->rear)
        {
            printf("item dequeued =%d",q->items[q->front]);
            q->front=-1;
            q->rear=-1;
        }
        else
        {
            printf("Item dequeued=%d",q->items[q->front]);
            q->front++;
            
        }
    }
    printf("\n");
}
void printQueue(struct queue *q)
{
    printf("Queue: - ");
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d - ",q->items[i]);
    }
    printf("\n");
}
int main()
{
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    //creating an empty Queue
    q->front=-1;
    q->rear=-1;
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    printQueue(q);
    deQueue(q);
    printQueue(q);
    exit (0);
}