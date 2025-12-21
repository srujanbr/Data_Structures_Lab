#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void insert();
void delete();
void display();

int main()
{
    int ch;

    for (;;)
    {
        printf("\n IMPLEMENTATION OF CIRCULAR QUEUE USING ARRAY");
        printf("\n 1 : INSERT");
        printf("\n 2 : DELETE");
        printf("\n 3 : DISPLAY");
        printf("\n 4 : EXIT");
        printf("\n\n Enter your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}

void insert()
{
    int item;

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\n CIRCULAR QUEUE OVERFLOW\n");
    }
    else
    {
        if (front == -1)
            front = rear = 0;
        else if (rear == MAX - 1)
            rear = 0;
        else
            rear = rear + 1;

        printf("\n Enter the element : ");
        scanf("%d", &item);
        cq[rear] = item;
    }
}

void delete()
{
    int item;

    if (front == -1)
    {
        printf("\n CIRCULAR QUEUE UNDERFLOW (QUEUE EMPTY)\n");
    }
    else
    {
        item = cq[front];
        printf("\n Deleted element is %d\n", item);

        if (front == rear)
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\n CIRCULAR QUEUE IS EMPTY\n");
    }
    else
    {
        printf("\n Elements in the Circular Queue are:\n");

        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                printf("\t%d\n", cq[i]);
        }
        else
        {
            for (i = front; i < MAX; i++)
                printf("\t%d\n", cq[i]);
            for (i = 0; i <= rear; i++)
                printf("\t%d\n", cq[i]);
        }
    }
}
