#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
struct StackNode {
    int data;
    StackNode *next;
};

struct Stack
{
    StackNode *_top;
    unsigned _size;

    void init() 
    {
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty() {
        return (_top == nullptr);
    }


  void pop()
    {
        if (!isEmpty()) {
            StackNode *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }

 void push(int value)
    {
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            newNode->data = value;

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
        }
    }
    
    int top()
    {
        if (!isEmpty())
            return _top->data;
        exit(-1);
    }
};
   
    
    
    
int main () {
    Stack myStack;      
    myStack.init();
    
 int testcase, N,M;
    cin >> testcase;
        for (int i=0; i<testcase; i++) {
        cin >> N;

            for (int i=0; i<N; i++) {
            cin >> M;
            if (myStack.isEmpty()){
                myStack.push(M);
            }
            else {
                while (!myStack.isEmpty()){
                int top = myStack.top();
                if (M>top){
                    myStack.pop();
                }
                else{
                    break;
                }
            }
        myStack.push(M);
    }      
    
   }
    Stack temp;
    temp.init();
    while(!myStack.isEmpty()) {
        temp.push (myStack.top());        
        myStack.pop();                  
    }   

        cout<<"Susunan blok yang disusun Nadut dan Cayo adalah : ";
        while(!temp.isEmpty()) {         
            printf("%d ", temp.top());      
            temp.pop();                  
        }
        cout << endl;
    }
    return 0;
}
