#include "headers.h"

void clearResources(int);


struct process
{
    int id;
    int arrival;
    int runTime;
    int remainingTime;
    int priority;
};

// info of the priority queue
enum compBy {Priority, remainingTime};
#define MAXSIZE 100000

enum compBy cmp;
int curSize = 0;
struct process heap[MAXSIZE];

int parent(int);
int left(int);
int right(int);
int compare(int, int);
void heapify(int);
struct process top();
void pop();
void push(struct process);



int main(int argc, char * argv[])
{
    signal(SIGINT, clearResources);
    // TODO Initialization
    // 1. Read the input files.
    // 2. Ask the user for the chosen scheduling algorithm and its parameters, if there are any.
    // 3. Initiate and create the scheduler and clock processes.
    // 4. Use this function after creating the clock process to initialize clock
    initClk();
    // To get time use this
    int x = getClk();
    printf("current time is %d\n", x);
    // TODO Generation Main Loop
    // 5. Create a data structure for processes and provide it with its parameters.
    // 6. Send the information to the scheduler at the appropriate time.
    // 7. Clear clock resources
    destroyClk(true);
}

void clearResources(int signum)
{
    //TODO Clears all resources in case of interruption
}


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
    int val1 = cmp == Priority ? heap[idx1].priority : heap[idx1].remainingTime;
    int val2 = cmp == Priority ? heap[idx2].priority : heap[idx2].remainingTime;

    if (val1 > val2) return 1;
    if (val1 == val2) return 0;
    if (val1 < val2) return -1;
}

void heapify(int root)
{
    int l = left(root), r = right(root);
    int mn = root;
    if (l < curSize && compare(l, root) == 1) mn = l;
    if (r < curSize && compare(r, root) == 1) mn = r;

    if (mn != root) {
        struct process tmp = heap[root];
        heap[root] = heap[mn];
        heap[mn] = tmp;
        heapify(mn);
    }
}

// main functions

struct process top()
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

void push(struct process newP)
{
    curSize++;
    heap[curSize-1] = newP;
    int pos = curSize-1;
    while(pos > 0 && compare(pos, parent(pos)) == 1) {
        struct process tmp = heap[parent(pos)];
        heap[parent(pos)] = heap[pos];
        heap[pos] = tmp;
        pos = parent(pos);
    }
}
