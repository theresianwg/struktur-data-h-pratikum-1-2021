#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct StackNode{
    int data;
    char str[100];
    StackNode *next;
};

struct Stack{
    StackNode *_top;
    unsigned _size;

    void init(){
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty(){
        return (_top == nullptr);
    }

    void push(int value, char buku[]){
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode){
            _size++;
            newNode->data = value;
            strcpy(newNode->str, buku);

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
        }
    }

    void pop(){
        if (!isEmpty()){
            StackNode *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }

    int top(){
        if (!isEmpty())
            return _top->data;
        exit(-1);
    }

    void tumpuk(){
        StackNode *temp=_top;
        if(temp==NULL){
            return;
        }
        int i=0;
        int min=999999999;
        StackNode *X;
        while(temp!=NULL){
            if(temp->data<min){
                min=temp->data;
                X=temp;
            }
            temp=temp->next;
        }

        StackNode *temp1;
        temp=_top;
        while(temp!=X){
            temp1=temp;
            temp=temp->next;
            free(temp1);
            i++;
        }

        if(temp->next!=NULL){
            _top=temp->next;
        }else{
            _top=NULL;
        }
        cout<<i<<" "<<X->str<<endl;
        free(temp);
    }
};

int main(){
    Stack myStack;
    myStack.init();
    
    int testcase, N;
    char buku [20];
    cin>>testcase;
		for(int i=1; i<=testcase; i++){
        	cin>>N;
        	if(N!=-1){
            	cin>>buku;
            if(N==0){
                continue;
            }
            myStack.push(N, buku);
        }else{
            myStack.tumpuk();
        }
    }
    return 0;
}
