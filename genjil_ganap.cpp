#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
struct SListNode 
{
    int data;
    SListNode *next;
}; 

struct SinglyList
{
    SListNode *_head;
    unsigned _size;

    void init() {
        _head = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL);
    }

void push(int value){
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
	if (value%2==0){
        
        if (newNode) {
            _size++;
            newNode->data = value;
        
            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _head;
            _head = newNode;
        	
    	}
    }
	if (value%2!=0){
        
        if (newNode) {
            _size++;
            newNode->data = value;
            newNode->next = NULL;
        }
            if (isEmpty()) 
                _head = newNode;
            else {
                SListNode *temp = _head;
                while (temp->next != NULL) 
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }

    int getAt(int index) {
        if (!isEmpty()) {
            SListNode *temp = _head;
            int _i = 0;
            while (temp->next != NULL && _i < index) {
                temp = temp->next;
                _i++;
            }
            return temp->data;
        }
        else exit(-1);
    }
};
	


int main () {
	
	
    SinglyList myList;
    myList.init();
    
	int testcase, N;
    cin >> testcase;
        for (int i=0; i<testcase; i++) {
        	cin >> N;
        	myList.push(N);   
        }

    cout <<  "Urutan Mobil Roy : ";
    for (int i = 0; i < myList._size; i++) {
        printf("%d ", myList.getAt(i));
    }
    printf("\n");
    
    return 0;
}

