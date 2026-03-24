#include <stdio.h>
#include <string.h>

#define MAX 5


char stack[MAX][50];
int top = -1;


char queue[MAX][50];
int front = 0, rear = -1;


char deque[MAX][50];
int dfront = -1, drear = -1;


void push() {
    if (top == MAX - 1) {
        printf("Stack full!\n");
        return;
    }
    char item[50];
    printf("Enter item: ");
    scanf(" %[^\n]", item);
    strcpy(stack[++top], item);
}

void pop() {
    if (top == -1) {
        printf("Stack empty!\n");
        return;
    }
    printf("Removed: %s\n", stack[top--]);
}


void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue full!\n");
        return;
    }
    char item[50];
    printf("Enter item: ");
    scanf(" %[^\n]", item);
    strcpy(queue[++rear], item);
}

void dequeue() {
    if (front > rear) {
        printf("Queue empty!\n");
        return;
    }
    printf("Removed: %s\n", queue[front++]);
}


void insertFront() {
    if (dfront == 0 && drear == MAX - 1) {
        printf("Deque full!\n");
        return;
    }
    char item[50];
    printf("Enter item: ");
    scanf(" %[^\n]", item);

    if (dfront == -1) {
        dfront = drear = 0;
    } else {
        dfront--;
    }

    strcpy(deque[dfront], item);
}

void insertRear() {
    if (drear == MAX - 1) {
        printf("Deque full!\n");
        return;
    }
    char item[50];
    printf("Enter item: ");
    scanf(" %[^\n]", item);

    if (dfront == -1) {
        dfront = drear = 0;
    } else {
        drear++;
    }

    strcpy(deque[drear], item);
}

void deleteFront() {
    if (dfront == -1) {
        printf("Deque empty!\n");
        return;
    }
    printf("Removed: %s\n", deque[dfront]);
    if (dfront == drear) {
        dfront = drear = -1;
    } else {
        dfront++;
    }
}

void deleteRear() {
    if (dfront == -1) {
        printf("Deque empty!\n");
        return;
    }
    printf("Removed: %s\n", deque[drear]);
    if (dfront == drear) {
        dfront = drear = -1;
    } else {
        drear--;
    }
}


void showAll() {
    printf("\nStack: ");
    for (int i = 0; i <= top; i++) printf("%s ", stack[i]);

    printf("\nQueue: ");
    for (int i = front; i <= rear; i++) printf("%s ", queue[i]);

    printf("\nDeque: ");
    for (int i = dfront; i <= drear && dfront != -1; i++) printf("%s ", deque[i]);

    printf("\n");
}

int main() {
    char choice[20];

    while (1) {
        printf("\nType: push pop enqueue dequeue insertFront insertRear deleteFront deleteRear show exit\n");
        scanf("%s", choice);

        if (strcmp(choice, "push") == 0) push();
        else if (strcmp(choice, "pop") == 0) pop();
        else if (strcmp(choice, "enqueue") == 0) enqueue();
        else if (strcmp(choice, "dequeue") == 0) dequeue();
        else if (strcmp(choice, "insertFront") == 0) insertFront();
        else if (strcmp(choice, "insertRear") == 0) insertRear();
        else if (strcmp(choice, "deleteFront") == 0) deleteFront();
        else if (strcmp(choice, "deleteRear") == 0) deleteRear();
        else if (strcmp(choice, "show") == 0) showAll();
        else if (strcmp(choice, "exit") == 0) break;
        else printf("Invalid input\n");
    }

    return 0;
}