#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *head2 = NULL;

void insertFront(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertFront2(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head2;
    head2 = newNode;
}

void display(struct node *h) {
    if (h == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (h != NULL) {
        printf("%d -> ", h->data);
        h = h->next;
    }
    printf("NULL\n");
}

void sortList() {
    if (head == NULL || head->next == NULL) {
        printf("List too short to sort!\n");
        return;
    }
    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

void reverseList() {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully.\n");
}

void concatenateLists() {
    if (head == NULL) {
        head = head2;
        head2 = NULL;
        printf("Concatenation done.\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    head2 = NULL;
    printf("Concatenation done.\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert Front (List 1)\n");
        printf("2. Insert Front (List 2)\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 2 to List 1\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront2(value);
            break;
        case 3:
            display(head);
            break;
        case 4:
            display(head2);
            break;
        case 5:
            sortList();
            break;
        case 6:
            reverseList();
            break;
        case 7:
            concatenateLists();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}
