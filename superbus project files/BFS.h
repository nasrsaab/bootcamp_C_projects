#pragma once
// BFS algorithm in C

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define IN 999999

struct queue {
    int items[ARRAYSIZE];
    int front;
    int rear;
};

struct bfsVertex {
    int parent;
    int distance = INT_MAX;
    bool visit=false;
};


struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
    if (q->rear == ARRAYSIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
           // printf("Resetting queue ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Print the queue
void printQueue(struct queue* q) {
    int i = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty");
    }
    else {
        printf("\nQueue contains \n");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
    }
}
/********************************/
//Breadth First Search
int BFS(int sorc, int des)
{
    int adjVertex = 0;
    struct queue* q = createQueue();

    struct bfsVertex bfsInfo[ARRAYSIZE];

    //Check the first station is visited
    bfsInfo[searchByStationNumber(sorc)->stIndex].visit = 1;

    // set the first station in the queue
    enqueue(q, sorc);
    bfsInfo[searchByStationNumber(sorc)->stIndex].distance = 0;
    bfsInfo[searchByStationNumber(sorc)->stIndex].parent = -1;

    while (!isEmpty(q)) {
       // printQueue(q);
        int currentVertex = dequeue(q);
        if (bfsInfo[searchByStationNumber(currentVertex)->stIndex].parent == -1)
            bfsInfo[searchByStationNumber(currentVertex)->stIndex].distance = 0;
        else
        {
            bfsInfo[searchByStationNumber(currentVertex)->stIndex].distance = bfsInfo[searchByStationNumber(bfsInfo[searchByStationNumber(currentVertex)->stIndex].parent)->stIndex].distance + 1;
        }
        //print the path
        if (currentVertex == des)
        {
            printf("\033[1;33m");
            int counter = 0;
            int pathlinght = 0;
            printf("%d",des);
            pathlinght++;
           
            while (bfsInfo[searchByStationNumber(currentVertex)->stIndex].distance != 0 && bfsInfo[searchByStationNumber(currentVertex)->stIndex].distance != INT_MAX)
            {
                counter += searchByStationNumber(currentVertex)->distance;
                pathlinght++;
                printf(" <-- %d", bfsInfo[searchByStationNumber(currentVertex)->stIndex].parent);
                currentVertex = bfsInfo[searchByStationNumber(currentVertex)->stIndex].parent;
                
            }
            printf("\033[1;32m");
            printf("\npathlinght= %d\n", pathlinght);
            printf("the distance between the start and the end= %d\n\n", counter);
            return 1;
        }
        struct node* temp = neighborsArray[searchByStationNumber(currentVertex)->stIndex];
        
        while (temp ) {
            adjVertex = temp->NeighborNum;

            if (bfsInfo[searchByStationNumber(adjVertex)->stIndex].visit == 0)
            {
                bfsInfo[searchByStationNumber(adjVertex)->stIndex].visit = 1;
                bfsInfo[searchByStationNumber(adjVertex)->stIndex].parent = currentVertex;
               // bfsInfo[searchByStationNumber(adjVertex)->stIndex].distance = searchByStationNumber(adjVertex)->distance;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
       

    }
    return 0;
}//end bfs
/****************************************/
/*
int dijsktra( int source, int target)
{
    int dist[ARRAYSIZE], prev[ARRAYSIZE], selected[ARRAYSIZE] = { 0 };
    int i, m, min, start, d, j;
    char path[ARRAYSIZE];

    for (i = 1; i < ARRAYSIZE; i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start] = 1;
    dist[start] = 0;
    while (selected[target] == 0)
    {
        min = IN;
        m = 0;
        for (i = 1; i < ARRAYSIZE; i++)
        {
            d = dist[start] + cost[start][i];
            if (d < dist[i] && selected[i] == 0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if (min > dist[i] && selected[i] == 0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while (start != -1)
    {
        path[j++] = start + 65;
        start = prev[start];
    }
    path[j] = '\0';
    strrev(path);
    printf("%s", path);
    return dist[target];
}
*/
/*
void FinalSolution(int dist[], int n)
{
    // This function prints the final solution
    printf("\nVertex\tDistance from Source Vertex\n");
    int i;

    for (i = 0; i < n; ++i) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void BellmanFord( int source, int target)
{
   // int V = graph->V;

   // int E = graph->E;

   int StoreDistance[ARRAYSIZE];

    int i, j;

    // This is initial step that we know , we initialize all distance to infinity except
    //  source.
   // We assign source distance as 0(zero)

    for (i = 0; i < ARRAYSIZE; i++)
        StoreDistance[i] = INT_MAX;

    StoreDistance[searchByStationNumber(source)->stIndex] = 0;

    //The shortest path of graph that contain V vertices, never contain "V-1" edges. 
    //So we do here "V-1" relaxations

    for (i = 1; i <= ARRAYSIZE; i++)
    {
        for (j = 0; j < ARRAYSIZE; j++)
        {
            int u = searchByStationNumber(source)->stationNum;

            int v = searchByStationNumber(source)->distance;

            int weight = searchByStationNumber(source)->distance;

            if (StoreDistance[searchByStationNumber(source)->stIndex] + weight < StoreDistance[searchByStationNumber(source)->stIndex])
                StoreDistance[searchByStationNumber(source)->stIndex] = StoreDistance[searchByStationNumber(source)->stIndex] + weight;
        }
    }

    // Actually upto now shortest path found. But BellmanFord checks for negative edge cycle. In this step we check for that
    // shortest distances if graph doesn't contain negative weight cycle.

    // If we get a shorter path, then there is a negative edge cycle.
    for (i = 0; i < HASHSIZE; i++)
    {
        int u = searchByStationNumber(source)->stationNum;

        int v = searchByStationNumber(source)->distance;

        int weight = searchByStationNumber(source)->distance;

        if (StoreDistance[u] + weight < StoreDistance[v])
            printf("This graph contains negative edge cycle\n");
    }

    FinalSolution(StoreDistance, HASHSIZE);

    return;
}
*/