#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hash_Arr_Linked.h"
//#include "bussGraph.h"
#include "BFS.h"


int main()
{    /*------------------------------------------*/
       //initalization hash table
        initHashTable();

        //set station number ditales in hash table
        if (setStationNum())
        {
            printf("*** Station number is full in the Hash Table ***\n");
        }
        else
            printf("*** Hash Table is empty***\n");
    /*------------------------------------------*/

        //initalization Neighbors Array
        initNeighborsArray();

        //set neighbors number in neighbors array
        if (insertNeighbors())
        {
            printf("*** Station Neighbors number is full in the Neighbors Array ***\n");
        }
        else
            printf("*** Neighbors Array is empty***\n");
    /*------------------------------------------*/

   printf("\n");
    int op;
    
    for (;;)
    {
        printf("\033[1;33m");
        printf("\t***** Super Bus Company *****\n");
        printf("\t1: Print all the cities\n");
        printf("\t2: Print all Station in one city\n");
        printf("\t3: The shortest route by stations (BFS) \n");
        printf("\t4: Search by Station Number\n");
        printf("\t5: Search by Nighbor Array index\n");
        printf("\t6: Display **HASH TABLE** Details\n");
        printf("\t7: print nighbors about some station\n");
        printf("\t8: Display **Nighbors Array** Details\n");
        printf("\t9: exit \n");
        
        printf("\n");
        printf("\033[1;34m");

        scanf_s("%d", &op);
        char c = getchar();

        switch (op)
        {
            case 1:
            {     
                   cities(); //print all the cities that found in the excel file
                    break;
            }
            case 2:
            {
                char cityName[50];
                
                printf("Please enter the city name\n");
                fgets(cityName, 50, stdin);
                cityName[strlen(cityName) - 1] = '\0';
                //print all the station ditails about some city
                searchByCityName(cityName);

                break;
            }

            case 3:
            {
                printf("Enter the start Station Number\n");
                int a;
                scanf_s("%d", &a);
                char c2 = getchar();
                printf("Enter the end Station Number\n");
                int b;
                scanf_s("%d", &b);
                char c1 = getchar();
                //search the short path form Start point to the End point 
                BFS(a,b);
                break;
            }
            case 4:
            {   printf("Enter Station Number\n");
                struct bussStation* item1;
                int a;
                scanf_s("%d", &a);
                 char c = getchar();
                //print ditales about some station number
                item1 = searchByStationNumber(a);
      
                if (item1 != NULL)
                    {
                    printf("\n\nStation Number: %d  \n", item1->stationNum);
                    printf("bus line: %d\n", item1->line);
                    printf("Station name: %s\n", item1->stationName);
                    printf("City name: %s\n", item1->cityName);
                    printf("Distance from previous station: %d\n", item1->distance);
                    printf("Have index: %d\n", item1->stIndex);;
                    }
                else
                    {
                        printf("Station Number not found\n");
                    }
                break;
            }
            case 5:
            {   printf("Enter Index Number\n");
                struct bussStation* item2;
                int a;
                scanf_s("%d", &a);
                char c1 = getchar();
                //print station detailes that conetcted to the spacific index
                item2 = searchByIndex(a);

                if (item2 != NULL) {
                    printf("\n\nStation Number: %d  \n", item2->stationNum);
                    printf("bus line: %d\n", item2->line);               
                    printf("Station name: %s\n", item2->stationName);
                    printf("City name: %s\n", item2->cityName);                
                    printf("Distance from previous station: %d\n", item2->distance);
                    printf("Have index: %d\n", item2->stIndex);
                }
                else {
                    printf("Station Number not found\n");
                }
                break;
            }
            
            case 6:
                displayHashTable();
                break;

            case 7:
                printf("Enter Station Number:\n");
                int stn;
                scanf_s("%d", &stn);
              //print nieghbors that conetcted to the spacific station
                searchAboutNighbor(stn);
                break;

            case 8:
                printNighborArray();
                break;
            case 9:
                 return 0;
                break;
       
            default:
                break;
        }
    }
    return 1;
}