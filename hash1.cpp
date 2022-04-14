//#include <stdio.h>
//#include <stdlib.h>
//
//#define SIZE 20
//
//struct DataItem {
//    int data;
//    int key;
//};
//
//struct DataItem* hashArray[SIZE];
//struct DataItem* dummyItem;
//struct DataItem* item;
///*------------------------------------------------------*/
//int hashCode(int key) {
//    return key % SIZE;
//}
///*------------------------------------------------------*/
//struct DataItem* search(int key) {
//    //get the hash 
//    int hashIndex = hashCode(key);
//
//    //move in array until an empty 
//    while (hashArray[hashIndex] != NULL) {
//        if (hashArray[hashIndex]->key == key)
//            return hashArray[hashIndex];
//        //go to next cell
//        ++hashIndex;
//        //wrap around the table
//        hashIndex %= SIZE;
//    }
//    return NULL;
//}
///*------------------------------------------------------*/
//struct DataItem* Delete(struct DataItem* item) 
//{
//    dummyItem = (struct DataItem*)malloc(sizeof(struct DataItem));
//    dummyItem->data = -1;
//    dummyItem->key = -1;
//
//    int key = item->key;
//
//    //get the hash 
//    int hashIndex = hashCode(key);
//
//    //move in array until an empty 
//    while (hashArray[hashIndex] != NULL) {
//        if (hashArray[hashIndex]->key == key) {
//            struct DataItem* temp = hashArray[hashIndex];
//            //assign a dummy item at deleted position
//            hashArray[hashIndex] = dummyItem;
//            return temp;
//        }
//        //go to next cell
//        ++hashIndex;
//        //wrap around the table
//        hashIndex %= SIZE;
//    }
//    return NULL;
//}
///*------------------------------------------------------*/
//void insert(int key, int data) {
//    struct DataItem* item = (struct DataItem*)malloc(sizeof(struct DataItem));
//    item->data = data;
//    item->key = key;
//
//    //get the hash 
//    int hashIndex = hashCode(key);
//
//    //move in array until an empty or deleted cell
//    while (hashArray[hashIndex] != NULL &&
//        hashArray[hashIndex]->key != -1) {
//        //go to next cell
//        ++hashIndex;
//        //wrap around the table
//        hashIndex %= SIZE;
//    }
//    hashArray[hashIndex] = item;
//}
///*------------------------------------------------------*/
//void display() {
//    int i = 0;
//    for (i = 0; i < SIZE; i++) {
//        if (hashArray[i] != NULL)
//            printf("[%d]= (%d,%d)\n",i, hashArray[i]->key, hashArray[i]->data);
//        else
//            printf("[%d]= (~~,~~)\n",i);
//    }
//    printf("\n");
//}
///*------------------------------------------------------*/
//int main() 
//{
//       int op;
//    for (;;)
//    {
//        printf("\033[1;33m");
//        printf("1:Insert\n");
//        printf("2:Search\n");
//        printf("3:Delete\n");
//        printf("4:Display\n");
//        printf("9:Exit\n");
//        printf("\n");
//        printf("\033[1;34m");
//        scanf_s("%d", &op);
//        char c = getchar();
//
//        switch (op)
//        {
//        case 1:
//        {int a, b;
//        printf("Please enter the key and data...i.e: 12,20\n");
//        scanf_s("%d,%d", &a,&b);
//        char c = getchar();
//        insert(a, b);
//        
//        break;
//        }
//        case 2:
//        {   int a;
//            printf("Please enter the data key to search:\n");
//            scanf_s("%d", &a);
//            char c = getchar();
//            item = search(a);
//
//        if (item != NULL) {
//            printf("Element found: %d\n", item->data);
//        }
//        else {
//            printf("Element not found\n");
//        }
//            break;
//        }
//        case 3:
//        {   
//            int a;
//            printf("Please enter the data key to Delete:\n");
//            scanf_s("%d", &a);
//            char c = getchar();
//
//            item = search(a);
//             Delete(item);
//             break;
//        }
//        case 4:display();
//            break;
//        case 9: return 0;
//            break;
//        default:
//            break;
//        }
//    }
//}