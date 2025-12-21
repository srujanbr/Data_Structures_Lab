#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

int s[MAX], top = -1;

void push();
void pop();
void display();

int main()
{
    int ch;
    char str[30];

    for (;;)
    {
        printf("\n IMPLEMENTATION OF STACK OF INTEGERS USING ARRAY \n");
        printf("\n 1 : PUSH");
        printf("\n 2 : POP");
        printf("\n 3 : DISPLAY");
        printf("\n 4 : EXIT");
        printf("\n\n Enter your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}

void push()
{
    int item;
    if (top == MAX - 1)
        printf("\n STACK OVERFLOW \n");
    else
    {
        printf("\n Enter the Element : ");
        scanf("%d", &item);
        top = top + 1;
        s[top] = item;
    }
}

void pop()
{
    int item;
    if (top == -1)
        printf("\n STACK UNDERFLOW \n");
    else
    {
        item = s[top];
        printf("\n The Deleted Element is %d\n", item);
        top = top - 1;
    }
}

void display()
{
    int i;
    if (top == -1)
        printf("\n The Stack is Empty \n");
    else
    {
        printf("\n The Elements present in Stack are \n");
        for (i = top; i >= 0; i--)
            printf("\t %d \n", s[i]);
    }
}
