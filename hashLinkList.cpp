#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct DataItem {
    int data;
    int key;
    struct DataItem* next;
};

struct DataItem* hashArray[SIZE];
struct DataItem* item;
/*------------------------------------------------------*/
int hashCode(int key) {
    return key % SIZE;
}
/*------------------------------------------------------*/
struct DataItem* search(int key) {
    int hashIndex = hashCode(key);
    struct DataItem* temp = hashArray[hashIndex];
    while (temp)
    {
        if (temp->key == key)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
/*------------------------------------------------------*/
struct DataItem* Delete(int key)
{
    //get the hash 
    int hashIndex = hashCode(key);
    struct DataItem* temp = hashArray[hashIndex];
    struct DataItem* res = hashArray[hashIndex];
    if (!res)
        return NULL;
    if (res->key == key)
    {
        hashArray[hashIndex] = res->next;
        return res;
    }
    while (temp)
    {
        if (temp->next->key == key)
        {
            res = temp->next;
            temp->next = res->next;//temp->next = temp->next->next

            return res;
        }
        temp = temp->next;
    }
    return NULL;
  
}
/*------------------------------------------------------*/
void insert(int key, int data) {
    struct DataItem* item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    //get the hash 
    int hashIndex = hashCode(key);

    item->next = hashArray[hashIndex];
    hashArray[hashIndex] = item;
   
}
/*------------------------------------------------------*/
void display() {
    int i = 0;
    for (i = 0; i < SIZE; i++) {
        printf("[%d]=", i);
        struct DataItem* temp = hashArray[i];
        while (temp)
        {
            printf("(%d,%d)->", temp->key, temp->data);
            temp = temp->next;
        }
           
     
            printf("||\n");
    }
    printf("\n");
}
/*------------------------------------------------------*/
int main() 
{
       int op;
    for (;;)
    {
        printf("\033[1;33m");
        printf("1:Insert\n");
        printf("2:Search\n");
        printf("3:Delete\n");
        printf("4:Display\n");
        printf("9:Exit\n");
        printf("\n");
        printf("\033[1;34m");
        scanf_s("%d", &op);
        char c = getchar();

        switch (op)
        {
        case 1:
        {int a, b;
        printf("Please enter the key and data to insert...i.e: 12,20\n");
        scanf_s("%d,%d", &a,&b);
        char c = getchar();
        insert(a, b);
        
        break;
        }
        case 2:
        {   int a;
            printf("Please enter the data key to search:\n");
            scanf_s("%d", &a);
            char c = getchar();
            item = search(a);

        if (item != NULL) {
            printf("Element found: (%d,%d)\n",item->key ,item->data);
        }
        else {
            printf("Element not found\n");
        }
            break;
        }
        case 3:
        {   
            int a;
            printf("Please enter the data key to Delete:\n");
            scanf_s("%d", &a);
            char c = getchar();

            //item = search(a);
             Delete(a);
             break;
        }
        case 4:display();
            break;
        case 9: return 0;
            break;
        default:
            break;
        }
    }
}