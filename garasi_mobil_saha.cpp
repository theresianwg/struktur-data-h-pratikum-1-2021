#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, int value);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, int value);
int  slist_front(SinglyList *list);
int  slist_back(SinglyList *list);
int  slist_getAt(SinglyList *list, int index);

/* Function definition below */

void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_insertAt(SinglyList *list, int index, int value)
{
    /* Kasus apabila posisinya melebihi batas */
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;
    }
    else if (index == 0 || index < 0) {
        slist_pushFront(list, value);
        return;
    }

    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {

        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size) {
            slist_popBack(list);
            return;
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }

        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}

bool isDobel(int arr[], int n)
{
    int i, j, ctr = 0;
    for(i = 0;i < n;i++) for(j = i+1;j < n;j++) if(arr[i] == arr[j]) ctr++;
    return (ctr > 0);
}

int MaxCounter(int *array, int size)
{
    int i, j, maxCount, count;
    maxCount = -100000;
    for (i = 0; i< size; i++)
    {
        count = 1;
        for(j = i+1; j < size; j++)
        {
            if(array[j] == array[i])
            {
                count++;
                if(count > maxCount) maxCount = count;
            }
        }
    }
    return maxCount;
}

int Counter(SinglyList *list, int n, int k)
{
    SListNode *temp = list->_head;
    int arr[101010] = {0}, counter = 0;
    bool done = 0;
    while(temp->next != NULL && !done){
        arr[counter] = temp->data;
        arr[counter+1] = temp->next->data;
        counter += 2;
        temp=temp->next->next;
        if (counter == n) {done = 1; break;}
    }
    if (n%2==1) {arr[counter] = slist_back(list); counter++;}
    return MaxCounter(arr, n);
}

int main() {
    
    int testcase, jumlah, kapasitas;
    scanf("%d\n", &testcase);
    while (testcase--) {
        scanf("%d %d", &jumlah, &kapasitas);
        
    int x[jumlah+10], y[jumlah+10]; 
    int total = 0; 
    bool bareng = 0; 
        for (int i = 1; i <= jumlah; i++) {
            scanf("%d %d", &x[i], &y[i]);
            if (x[i] == y[i]) 
            bareng = 1; 
            total += y[i]-x[i]; 
        }
 
        SinglyList nums; 
        slist_init(&nums);
        for (int j = 1; j <= jumlah; j++) 
        for (int i = x[j]; i < y[j]; i++) {
            slist_pushBack(&nums, i);
        } 
        
        if (isDobel(x, jumlah) || isDobel(y, jumlah) || Counter(&nums, total, kapasitas) > kapasitas || bareng) 
            printf("Hmm harus renovasi garasi nich\n"); 
        else 
            printf("Hore gausah renov garasi\n");
    }
    puts("");
    return 0;
}
