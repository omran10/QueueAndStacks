#include<iostream>
using namespace std;

struct queue {
int front;
int rear;
int arr[100];
};

void init(queue &q){
q.front=-1;
q.rear=-1;///////////////////
}

void add(queue &q,int x){
    if(q.rear>=99){//////////////////
        cout<<"queue is over flow";
        return;
    }
    if(q.front==-1){
        q.front=0;
    }
    q.arr[++q.rear]=x;
}
void remove(queue &q,int &x,bool &empty){
    if(q.front==-1 ||q.front>q.rear){
        cout<<"the queue is empty can't remove elemnt";
        empty=true;
        return;
    }
    x=q.arr[q.front++];
    empty=(q.front>q.rear);
}

void print(queue &q){
    queue t;
    init(t);
    bool empty=false;
    int x;
    while(!empty){
        remove(q,x,empty);
        cout<<x<<"\t";
        add(t,x);
    }
    empty=false;
    while(!empty){
        remove(t,x,empty);
        add(q,x);
    }    
}

struct Stack {
    int arr [100];
    int top;
};
void initialize (Stack &s) {
    s.top = -1;
}
void push(Stack &s, int x) {
    if (s.top >= 99) {
        cout << "Stack Overflow" << endl;
        return;
    }
    s.arr[++s.top] = x;
}
void pop (Stack &s, int &X, bool &empty) {
    if (s.top == -1) {
        cout << "Stack Underflow" << endl;
        empty = true;
        return;
    }
    X = s.arr[s. top--];
    empty = (s.top == -1);
}

void revrse(queue &q){
   Stack s;
   initialize(s);
   int x;
   bool empty=false;
   while(!empty){
       remove(q,x,empty);
       push(s,x);
   }
   empty=false;
   while(!empty){
       pop(s,x,empty);
       add(q,x);
   }
}
void dele(queue&q,int target){
    queue t;
    init(t);
    int x;
    int count=0;
    bool empty=false;
    while(!empty){
        remove(q,x,empty);
        count++;
        if(count!=target){
            add(t,x);
        }
    }
    empty=false;
    while(!empty){
        remove(t,x,empty);
        add(q,x);
    }    
}

void reverse_two_element(queue &q){
        Stack s1, s2;
        initialize(s1);
        initialize(s2);
        
        int x, count = 0;
        bool empty = false;
    

        queue t;
        init(t);
        while (!empty) {
            remove(q, x, empty);
            add(t, x);
            count++;
        }
    
        empty = false;
        while (!empty) {
            remove(t, x, empty);
            add(q,x);
        }
    

        for (int i = 0; i < count; i++) {
            remove(q, x, empty);
            push(s1, x);
        }
    

        int last1, last2;
        pop(s1, last1, empty);
        pop(s1, last2, empty);
    

        while (!empty) {
            pop(s1, x, empty);
            push(s2, x);
        }

        int first1, first2;
        pop(s2, first1, empty);
        pop(s2, first2, empty);
    

        add(q, last1);
        add(q, last2);
    

        while (!empty) {
            pop(s2, x, empty);
            add(q, x);
        }
    

        add(q, first2);
        add(q, first1);
    }
    

int main(){
    queue q;
    init(q);
    add(q,5);
    add(q,24);
    add(q,543);
    add(q,352);
    add(q,3886);
    add(q,72);
    add(q,67);
/////////////reverse
    revrse(q);
    print(q);
///////////////delete target
    dele(q,3);
    print(q);
////////////////revese first tow element
reverse_two_element(q);
print(q);
}