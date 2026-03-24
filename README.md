# Open the file Miniproject.c with a C code editor/runner in order to run the program

# Full code explanation
Farras Al Ghifari - 5025251006
## Stack 

 char stack[MAX][50]; int top = -1; 

### Explanation

The declaration for stack.

## Queue

 char queue[MAX][50]; int front = 0, rear = -1; 

### Explanation

The declaration for queue.

## Deque

 char deque[MAX][50]; int dfront = -1, drear = -1; 

### Explanation

The declaration for Deque

## Stack function

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

### Explanation

The push() function adds a new string to the stack: it first checks whether the stack is full (top == MAX - 1), and if it is, it prints "Stack full!" and returns; otherwise it prompts the user with "Enter item: "The pop() function removes and displays the top element: it checks if the stack is empty (top == -1), and if so prints "Stack empty!" and returns; otherwise it prints "Removed: "

## Queue function

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

### Explanation

The enqueue() function adds a new item to the back of the queue: it first checks whether the queue is full (rear == MAX - 1), and if so prints "Queue full!" and returns; otherwise it prompts "Enter item:" The dequeue() function removes an item from the front: it checks if the queue is empty by testing whether front > rear, and if so prints "Queue empty!" and returns; otherwise it prints "Removed: "

## Deque Function

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

### Explanation

The insertFront() function adds a new item to the front of the deque by decreasing the dfront index, while insertRear() adds an item to the rear by increasing the drear index.he deleteFront() function removes and prints the item at the front, then moves dfront forward, while deleteRear() removes the item at the rear and moves drear backward. If after deletion only one element was present, both pointers are reset to -1 to mark the deque as empty.

## Showing the list Function

 void showAll() {
    printf("\nStack: ");
    for (int i = 0; i <= top; i++) printf("%s ", stack[i]);

    printf("\nQueue: ");
    for (int i = front; i <= rear; i++) printf("%s ", queue[i]);

    printf("\nDeque: ");
    for (int i = dfront; i <= drear && dfront != -1; i++) printf("%s ", deque[i]);

    printf("\n");
}

### Explanation 

It first prints the stack by looping from index 0 up to top, showing all items in the order they were added. Then it prints the queue by looping from front to rear, displaying elements in FIFO order. After that, it prints the deque by looping from dfront to drear, but only if the deque is not empty

## Main

 int main() {
    char choice[20];

    while (1) {
        printf("\nType: push pop enqueue dequeue insertFront insertRear deleteFront deleteRear show exit\n");
        printf("Choice: ");
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

### Explanation

The program then compares the input with predefined command keywords like "push", "pop", "enqueue" using strcmp, and calls the corresponding function for each data structure operation. If the user types "exit", the loop breaks and the program terminates; otherwise, if the input does not match any valid command, it prints an “Invalid input” message.

## Example input

push
apple
push
banana
pop
enqueue
milk
enqueue
bread
dequeue
insertFront
A
insertRear
B
deleteFront
deleteRear
show
exit

## Expected output 

Removed: banana
Removed: milk
Removed: A
Removed: B

Stack: apple
Queue: bread
Deque:


