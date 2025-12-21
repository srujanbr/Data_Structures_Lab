#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertFront(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the front.\n", value);
}

void deleteFront() {
    if (head == NULL)
        printf("List is empty!\n");
    else {
        struct node *temp = head;
        head = head->next;
        printf("Deleted %d from front.\n", temp->data);
        free(temp);
    }
}

void deleteEnd() {
    if (head == NULL)
        printf("List is empty!\n");
    else if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        printf("Deleted %d from end.\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void deletePosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position! Position must be >= 1.\n");
        return;
    }

    int length = 0;
    struct node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    if (pos > length) {
        printf("Invalid position! List currently has %d nodes.\n", length);
        return;
    }

    if (pos == 1) {
        struct node *delNode = head;
        head = head->next;
        printf("Deleted %d from position 1.\n", delNode->data);
        free(delNode);
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    struct node *delNode = temp->next;
    temp->next = delNode->next;
    printf("Deleted %d from position %d.\n", delNode->data, pos);
    free(delNode);
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Delete Front\n");
        printf("3. Delete End\n");
        printf("4. Delete at Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertFront(value);
            break;

        case 2:
            deleteFront();
            break;

        case 3:
            deleteEnd();
            break;

        case 4:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePosition(pos);
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
