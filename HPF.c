
#include "headers.h"

// after making all the other things needed just wrap everything here in a big function so you can just call it in the sceduler process.

// info of the priority queue
#define MAXSIZE 100
int curSize = 0;
process_par heap[MAXSIZE];


// priority queue functions

// auxiliary fucnctions
    
int parent(int i) 
{
    return (i-1)/2;
}

int left(int i)
{
    return 2*i+1;
}

int right(int i)
{
    return 2*i+2;
}

// 1--> 1 > 2
// 0--> 1 == 2
// -1--> 1 < 2
int compare(int idx1, int idx2)
{
    int val1 = heap[idx1].priority;
    int val2 = heap[idx2].priority;

    if (val1 > val2) return 1;
    if (val1 == val2) return 0;
    if (val1 < val2) return -1;
}

void heapify(int root)
{
    int l = left(root), r = right(root);
    int mn = root;
    if (l < curSize && compare(l, root) == -1) mn = l;
    if (r < curSize && compare(r, root) == -1) mn = r;

    if (mn != root) {
        process_par tmp = heap[root];
        heap[root] = heap[mn];
        heap[mn] = tmp;
        heapify(mn);
    }
}

// main functions

process_par top()
{
    return heap[0];
}

void pop()
{
    if (curSize == 1) {
        curSize--;
        return;
    }
    heap[0] = heap[curSize-1];
    curSize--;
    heapify(0);
}

void push(process_par newP)
{
    curSize++;
    heap[curSize-1] = newP;
    int pos = curSize-1;
    while(pos > 0 && compare(pos, parent(pos)) == -1) {
        process_par tmp = heap[parent(pos)];
        heap[parent(pos)] = heap[pos];
        heap[pos] = tmp;
        pos = parent(pos);
    }
}

int main()
{
    // this is just temporary we need to update
    // it later to make it recieve the processes
    // from some where not to read them by itself.
     FILE *input_file;

    input_file = fopen("processes.txt","r");
    if (!input_file) {
        printf("couldn't open the input file \"processes.txt\"\n");
        exit(-1);
    }
        fscanf(input_file,"%*[^\n]\n");

     process_par p;

    while (fscanf(input_file, "%d %d %d %d", &p.process_id, &p.arrival_time, &p.runtime, &p.priority) == 4) {
        printf("%d %d %d %d\n",p.process_id,p.arrival_time,p.runtime,p.priority);
        push(p);
        printf("\n");
    }

    // that's not the real logic the real logic will be like:
    // 1: get the top of the PQ if exists
    // 2: execute it
    // 3: check for if any processes has arrived and push them to the PQ
    // 4: repeat this whole sequence


    // just checking that every thing is okey.
    while(curSize > 0) {        
        p = top();
        pop();
        // call the function that will execute the process here.

        printf("%d %d %d %d\n",p.process_id,p.arrival_time,p.runtime,p.priority);
        // call the function that will execute the process hear.

        // check if any process has come ans put it in the PQ
        // ofcourse its not the real implementation of the logic but
        // it's just temporary and will be replaced later.

    }

    fclose(input_file);
    return 0;
}
