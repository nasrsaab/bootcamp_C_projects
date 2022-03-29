#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10


struct node
{
    int data;
    char name[20];
    int times;
    struct node* next;
};
struct node* head;
struct node* tail;

void beginsert(int, char*);
void lastinsert(int, char*);
void midinsert(int, char*);

void Insert() {
    char name[20];
    int num;

    printf("please enter a name: ");
    fgets(name, sizeof(name), stdin);
    //avoid new line when getting string
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
        name[len - 1] = '\0';
    printf("please enter a number: ");
    scanf_s("%d", &num);
    getchar();

    if (head == NULL)
        beginsert(num, name);
    else
        if (head->data > num)
            beginsert(num, name);
        else
            if (tail->data < num)
                lastinsert(num, name);
            else
                midinsert(num, name);
}

void Delete() {
    int num;
    if (head == NULL) {
        printf("No list. nothing to delete\n");
        return;
    }
    printf("please enter a number: ");
    scanf_s("%d", &num);
    getchar();
    if (head->data == num) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct node* temp = head;
    struct node* prev = head;
    while (temp) {
        if (num == temp->data) {
            prev->next = temp->next;
            free(temp);
            return;
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    printf("not found!!!\n");
}

void printList() {
    struct node* temp;
    temp = head;
    while (temp) {
        printf("%s,%d,%d", temp->name, temp->data, temp->times);
        if (temp->next)
            printf("->");
        else
            printf("-||\n");
        temp = temp->next;
    }
}

void main() {
    char op[20];



    for (int i = 0; i < SIZE; i++)
    {
        printf("What do you want to do: (insert, delete, exit)");
        fgets(op, sizeof(op), stdin);
        if (strcmp(op, "insert\n") == 0) Insert();
        if (strcmp(op, "delete\n") == 0) Delete();
        if (strcmp(op, "exit\n") == 0) return;

        printList();
    }

}

void midinsert(int num, char* str) {
    struct node* temp = head;
    if (temp->data == num) {
        temp->times = temp->times + 1;
    }
    else {
        while (temp->next->data < num) {
            temp = temp->next;
        }
        if (temp->next->data == num) {
            temp->next->times++;
        }
        else {
            struct node* ptr1 = (struct node*)malloc(sizeof(struct node));
            if (ptr1 == NULL)
            {
                printf("\nOVERFLOW\n");
            }
            ptr1->data = num;
            strcpy_s(ptr1->name, str);
            ptr1->times = 1;
            ptr1->next = temp->next;
            temp->next = ptr1;
        }
    }
}

void beginsert(int num, char* str) {
    int emptyList = 0;
    struct node* ptr1 = (struct node*)malloc(sizeof(struct node));
    if (ptr1 == NULL)
    {
        printf("\nOVERFLOW\n");
    }

    else {
        if (head == NULL) {
            emptyList = 1;
        }
        ptr1->data = num;
        strcpy_s(ptr1->name, str);
        ptr1->next = head;
        ptr1->times = 1;
        head = ptr1;
        if (emptyList)
            tail = head;
    }
}

void lastinsert(int num, char* str) {
    struct node* ptr2 = (struct node*)malloc(sizeof(struct node));

    if (ptr2 == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else {
        ptr2->data = num;
        strcpy_s(ptr2->name, str);
        ptr2->times = 1;
        if (head == NULL) {
            ptr2->next = head;
            head = ptr2;
            tail = head;
        }
        else {
            ptr2->next = NULL;
            tail->next = ptr2;
            tail = ptr2;
        }
    }
}