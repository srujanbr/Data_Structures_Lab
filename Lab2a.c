 #include <stdio.h>
#include <stdlib.h>

#define MAX 5

int q[MAX];
int front = -1, rear = -1;

void insert();
void delete();
void display();

int main()
{
    int ch;

    for (;;)
    {
        printf("\n IMPLEMENTATION OF QUEUE USING ARRAY");
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

    if (rear == MAX - 1)
    {
        printf("\n QUEUE OVERFLOW\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        printf("\n Enter the element : ");
        scanf("%d", &item);

        rear = rear + 1;
        q[rear] = item;
    }
}

void delete()
{
    int item;

    if (front == -1 || front > rear)
    {
        printf("\n QUEUE UNDERFLOW (QUEUE EMPTY)\n");
    }
    else
    {
        item = q[front];
        printf("\n Deleted element is %d\n", item);
        front = front + 1;
    }
}

void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("\n QUEUE IS EMPTY\n");
    }
    else
    {
        printf("\n Elements in the Queue are:\n");
        for (i = front; i <= rear; i++)
            printf("\t%d\n", q[i]);
    }
}
