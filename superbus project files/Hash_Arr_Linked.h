#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEPATH1 "E:\\SuperbasProject\\important\\bus3333.csv"
#define HASHSIZE 66000
#define ARRAYSIZE 2820
FILE* CSV3;

struct bussStation {
	int stIndex; //index the station in neighborsArray
	int stationNum;
	int distance;
	int line;
	char stationName[60];
	char cityName[50];
};

struct node
{
	int NeighborNum;
	struct node* next;
};

struct node* neighborsArray[ARRAYSIZE];

struct bussStation* hashArray[HASHSIZE];


/*------------------------------------------------------*/
void initHashTable()
{
	for (int i = 0; i < HASHSIZE; i++)
	{
		hashArray[i] = NULL;
	}
}
/*------------------------------------------------------*/
int hashcode(int stNum) {
	return stNum % HASHSIZE;
}



/*---------------------Search in hash Array by station number---------------------*/
void searchByCityName(char* cityName)
{
	int counter = 0;
	if(strcmp(hashArray[480]->cityName,cityName)==0)
	{
		printf("\n\nStation Number: %d  \n", hashArray[480]->stationNum);
		printf("bus line: %d\n", hashArray[480]->line);
		printf("Station name: %s\n", hashArray[480]->stationName);
		printf("City name: %s\n", hashArray[480]->cityName);
		printf("Distance from previous station: %d\n", hashArray[480]->distance);
		printf("Have index: %d\n", hashArray[480]->stIndex);
		printf("-------------------------------------------\n");
		counter++;
		
	}
	int i = 5427;

	while (i < 6213)
	{
		
		if (hashArray[i]!=NULL && strcmp(hashArray[i]->cityName, cityName) == 0)
		{
			counter++;
			printf("\n\nStation Number: %d  \n", hashArray[i]->stationNum);
			printf("bus line: %d\n", hashArray[i]->line);
			printf("Station name: %s\n", hashArray[i]->stationName);
			printf("City name: %s\n", hashArray[i]->cityName);
			printf("Distance from previous station: %d\n", hashArray[i]->distance);
			printf("Have index: %d\n", hashArray[i]->stIndex);
			printf("-------------------------------------------\n");
			
		}
		i++;
		
	}
	int j = 20059;

	while (j < 65410)
	{

		if (hashArray[j] != NULL && strcmp(hashArray[j]->cityName, cityName) == 0)
		{
			counter++;
			printf("\n\nStation Number: %d  \n", hashArray[j]->stationNum);
			printf("bus line: %d\n", hashArray[j]->line);
			printf("Station name: %s\n", hashArray[j]->stationName);
			printf("City name: %s\n", hashArray[j]->cityName);
			printf("Distance from previous station: %d\n", hashArray[j]->distance);
			printf("Have index: %d\n", hashArray[j]->stIndex);
			printf("-------------------------------------------\n");
			
		}
		j++;
	}
	printf("counter=%d\n",counter);
}
/*------------------------------------------------------*/
struct bussStation* searchByStationNumber(int stNumber) {
	//get the hash 
	int hashindex = hashcode(stNumber);

	//move in array until an empty 
	while (hashArray[hashindex] != NULL)
	{
		if (hashArray[hashindex]->stationNum == stNumber)
		{
			return hashArray[hashindex];
		}
		++hashindex;
		//wrap around the table
		hashindex %= HASHSIZE;
	}
	return NULL;
}
/*------------------------------------------------------*/
struct bussStation* searchByIndex(int ind) 
{	
	for (int i = 0; i < HASHSIZE; i++)
	{
		if (hashArray[i]!=NULL && hashArray[i]->stIndex == ind)
		{
			return hashArray[i];
		}
		
		
	}
	return NULL;
}
/*------------------------------------------------------*/
int insertToHashTable(int stNumber,int Dis,int line,char* stName, char* city,int Index)
{
	struct bussStation* temp = (struct bussStation*)malloc(sizeof(struct bussStation));
	
	temp->stIndex = Index;
	temp->stationNum = stNumber;
	temp->distance = Dis;
	temp->line = line;
	strcpy_s(temp->stationName,stName);
	strcpy_s(temp->cityName, city);

	if (searchByStationNumber(stNumber))
	{
		//printf("its found\n");
		return 0;
	}
	else
	{
		//get the hash 
		int hashindex = hashcode(stNumber);

		//move in array until an empty or deleted cell
		while (hashArray[hashindex] != NULL &&
			hashArray[hashindex]->stationNum != -1)
		{
			//go to next cell
			++hashindex;
			//wrap around the table
			hashindex %= HASHSIZE;
		}
		hashArray[hashindex] = temp;
		//free(temp);
	}
	return 1;
}
/*------------------------------------------------------*/
void displayHashTable() 
{
	printf("\n[hashcode]=(stationNum,line,cityName,stationName,distance,stIndex)\n");
	int cunterOfStation = 0;
	for (int i = 0; i < HASHSIZE; i++)
	{
		if (hashArray[i] != NULL)
		{
			printf("[%d]=  (%d,  %d  ,  %s  ,  %s  ,  %d  , %d)\n", i, hashArray[i]->stationNum, hashArray[i]->line, hashArray[i]->cityName, hashArray[i]->stationName, hashArray[i]->distance, hashArray[i]->stIndex);
			cunterOfStation++;
		}
	}
	printf("\n[hashcode]=(stationNum,line,cityName,stationName,distance,stIndex)\n");
	printf("cunterOfStation= %d\n", cunterOfStation);
}
/*------------------------------------------------------*/
int getColumnNum(char* title)
{
	char buffer[1024];
	char buff[1024];
	int column = 0;

	printf("\033[1;34m");

	fopen_s(&CSV3, FILEPATH1, "r");
	if (CSV3 == NULL)
	{
		printf("error! opening file to read\n");
		return 0;
	}
	else
	{
		while (fgets(buffer, 1024, CSV3)) //read the second line
		{
			column = 0;

			// if found space in the buff set char 'x'
			int j = 0;
			bool schar = false;
			for (int i = 0; i < strlen(buffer); i++)
			{
				if (buffer[i] == '"' && buffer[i + 1] != ',')
					schar = true;
				if (buffer[i] == ',' && buffer[i + 1] == ',')
				{
					buff[j] = buffer[i];
					j++;
					buff[j] = 'x';
					j++;
				}
				else if (buffer[i] == ',' && buffer[i + 1] == ' ' && schar) {
					buff[j] = ';';
					j++;
					schar = false;
				}
				else
				{
					buff[j] = buffer[i];
					j++;
				}
			}//end for
			buff[j] = '\0';

			// splitting the data
			char* value = strtok(buff, ",");

			while (value) {

				if (strcmp(value, title) == 0)//colmn which i need
				{
					return column; //return column number

				}//end if
				value = strtok(NULL, ",");
				column++;
			}//end while


		}//endwhile

		// close the file
		fclose(CSV3);
	}//end else

	return -1;
}
/*------------------------------------------------------*/
int cities()
{
	char array[200][50];
	char buffer[1024];
	char buff[1024];
	int counter = 0;
	int row = 0;
	int column = 0;

	printf("\033[1;34m");

	fopen_s(&CSV3, FILEPATH1, "r");

	if (CSV3 == NULL) {
		printf("Error! opening file to read\n");
		return 0;
	}

	else
	{
		int n = 0;
		bool ok = false;

		fgets(buffer, 1024, CSV3); //read first line

		while (fgets(buffer, 1024, CSV3)) //read the second line
		{
			column = 0;
			row++;
			// if found space in the buff set char 'x'
			int j = 0;
			bool sChar = false;
			for (int i = 0; i < strlen(buffer); i++)
			{
				if (buffer[i] == '"' && buffer[i + 1] != ',')
					sChar = true;
				if (buffer[i] == ',' && buffer[i + 1] == ',')
				{
					buff[j] = buffer[i];
					j++;
					buff[j] = 'x';
					j++;
				}
				else if (buffer[i] == ',' && buffer[i + 1] == ' ' && sChar) {
					buff[j] = ';';
					j++;
					sChar = false;
				}
				else
				{
					buff[j] = buffer[i];
					j++;
				}
			}//end for
			buff[j] = '\0';


			// splitting the data
			char* value = strtok(buff, ",");

			while (value) {
				if (column == 26)//colmn which i need
				{
					counter++;
					for (int i = 0; i <= n; i++)
					{
						if (strcmp(array[i], value) == 0)
						{
							ok = true;
							break;
						}//endif

					}//endfor
					if (!ok)
					{
						strcpy_s(array[n], value);
						n++;
						break;
					}//endif
					else
						ok = false;

				}//end if
				value = strtok(NULL, ",");
				column++;
			}//end while


		}//endwhile
		for (int i = 0; i < n; i++)
		{

			printf("%s\n", array[i]);
		}
		printf("number of cities in the file =%d\n", n);
		printf("Excel(CSV) File row = %d\n", row);
		printf("test number in the city column = %d\n", counter);
		// close the file

	}//end else
	fclose(CSV3);
	return 0;
}
/*------------------------------------------------------*/
int setStationNum()
{
	char clTitle[] = "Station number";
	int stationNum = getColumnNum(clTitle);

	char clTitle2[] = "Station name";
	int stationName = getColumnNum(clTitle2);

	char clTitle3[] = "City";
	int cityClum = getColumnNum(clTitle3);

	char clTitle4[] = "Distance from previous station";
	int distance = getColumnNum(clTitle4);

	char clTitle5[] = "line";
	int line = getColumnNum(clTitle5);

	int stNum = 0;
	int dis = 0;
	int lline = 0;
	char stname[60];
	char cityName[50];
	char buffer[1024];
	char buff[1024];
	int counter = 0;
	int row = 0;
	int column = 0;
	int indexToNighborArray = 1;

	printf("\033[1;34m");
	fopen_s(&CSV3, FILEPATH1, "r");

	if (CSV3 == NULL) {
		printf("Error! opening file to read\n");
		return 0;
	}

	else
	{
		fgets(buffer, 1024, CSV3); //read first line
		row++;
		while (fgets(buffer, 1024, CSV3)) //read the second line
		{
			column = 0;
			row++;
			// if found space in the buff set char 'x'
			int j = 0;
			bool sChar = false;
			for (int i = 0; i < strlen(buffer); i++)
			{
				if (buffer[i] == '"' && buffer[i + 1] != ',')
					sChar = true;
				if (buffer[i] == ',' && buffer[i + 1] == ',')
				{
					buff[j] = buffer[i];
					j++;
					buff[j] = '0';
					j++;
				}
				else if (buffer[i] == ',' && buffer[i + 1] == ' ' && sChar) {
					buff[j] = ';';
					j++;
					sChar = false;
				}
				else
				{
					buff[j] = buffer[i];
					j++;
				}
			}//end for
			buff[j] = '\0';

			// splitting the data
			char* value = strtok(buff, ",");

			while (value)
			{
				counter++;
				if (column == line)//colmn which i need
				{

					char str11[6];
					strcpy_s(str11, value);
					lline = atoi(str11);

				}
				
				if (column == stationNum)//colmn which i need
				{

					char str1[6];
					strcpy_s(str1, value);
					stNum = atoi(str1);

				}//end if

				if (column == stationName)
				{
					strcpy_s(stname, value);

				}

				if (column == distance)
				{
					char str2[10];
					strcpy_s(str2, value);
					//char str3[] = "x";
					//if (strcmp(str2, "x") != 0)
						dis = atoi(str2);

				}
				if (column == cityClum)
				{
					strcpy_s(cityName, value);

					if (insertToHashTable(stNum, dis,lline, stname, cityName, indexToNighborArray))
						indexToNighborArray++;
				}

				value = strtok(NULL, ",");
				column++;
			}//end while


		}//endwhile


		// close the file

	}
	fclose(CSV3);
	return 1;
}
/*------------------------------------------------------*/





/*----------------------Neighbors Array--------------------------------*/
void initNeighborsArray()
{
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		neighborsArray[i] = NULL;
	}
}
/*------------------------------------------------------*/
int insertToNighborArray(int stNighborNum,int stIndex)
{

	int emptyList = 0;
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	struct node* ptrFound = neighborsArray[stIndex];
	if (ptr == NULL)
	{
		printf("\nOVERFLOW\n");
	}

	else
	{
		while (ptrFound)
		{
			if (ptrFound->NeighborNum == stNighborNum)
				return 0;
			ptrFound = ptrFound->next;
		}

		ptr->NeighborNum = stNighborNum;
		ptr->next = neighborsArray[stIndex];

		neighborsArray[stIndex] = ptr;


	}
	return 1;
}
/*------------------------------------------------------*/
void printNighborArray() {
	
	int i = 0;
	for (i = 0; i < ARRAYSIZE; i++)
	{
		printf("[%d]=", i);
		struct node* temp = neighborsArray[i];
		while (temp)
		{
			printf("(%d)->", temp->NeighborNum);
			temp = temp->next;
		}


		printf("||\n");
	}
	printf("\n");
}
/*------------------------------------------------------*/
int searchAboutNighbor(int stationNum)
{
	struct bussStation* s = (struct bussStation*)malloc(sizeof(struct bussStation));
	
	s = searchByStationNumber(stationNum);
	if (s == NULL)
	{
		printf("station number isn't found!!!\n");
		return 0;
	}
	printf("(%d,  %d  ,  %s  ,  %s  ,  %d  , %d)\n", s->stationNum, s->line, s->cityName,s->stationName,s->distance, s->stIndex);
	printf("\nthe neighbors is:\n");
	struct node* temp = neighborsArray[s->stIndex];
	while (temp)
	{
		printf("(%d)->", temp->NeighborNum);
		temp = temp->next;
	}


	printf("||\n");
	return 1;
}
/*------------------------------------------------------*/
int insertNeighbors()
{
	char title[] = "Station arrangements";
	int prevCol = getColumnNum(title);
	
	int StArrangements;
	int stNumber;
	int prevStNumber=0;
	
	char buffer[1024];
	char buff[1024];
	int counter = 0;
	int row = 0;
	int column = 0;
	

	printf("\033[1;34m");
	fopen_s(&CSV3, FILEPATH1, "r");

	if (CSV3 == NULL) {
		printf("Error! opening file to read\n");
		return 0;
	}

	else
	{
		fgets(buffer, 1024, CSV3); //read first line
		row++;
		while (fgets(buffer, 1024, CSV3)) //read the second line
		{
			column = 0;
			row++;
			// if found space in the buff set char 'x'
			int j = 0;
			bool sChar = false;
			for (int i = 0; i < strlen(buffer); i++)
			{
				if (buffer[i] == '"' && buffer[i + 1] != ',')
					sChar = true;
				if (buffer[i] == ',' && buffer[i + 1] == ',')
				{
					buff[j] = buffer[i];
					j++;
					buff[j] = 'x';
					j++;
				}
				else if (buffer[i] == ',' && buffer[i + 1] == ' ' && sChar) {
					buff[j] = ';';
					j++;
					sChar = false;
				}
				else
				{
					buff[j] = buffer[i];
					j++;
				}
			}//end for
			buff[j] = '\0';

			// splitting the data
			char* value = strtok(buff, ",");
			
			
			//column++;
			while (value) {

				
				if (column == prevCol)//station arrangement
				{
					StArrangements = atoi(value);
					value = strtok(NULL, ",");
					column++;
					stNumber = atoi(value);//set station number in stNumber
					if (StArrangements != 1)
					{
						struct bussStation* item;
						item = searchByStationNumber(prevStNumber);//return in the search...arrayindex
						
						insertToNighborArray(stNumber, item->stIndex); //insert the neghbor
					}
					prevStNumber = stNumber;
					//printf("prevCol=%d\n", prevCol);


				}//end if

				value = strtok(NULL, ",");

				column++;
			}//end while

		}//endwhile
	}
	// close the file
	fclose(CSV3);
	return 1;
}
/*------------------------------------------------------*/