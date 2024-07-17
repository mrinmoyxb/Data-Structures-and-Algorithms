#include <iostream>
#include <iterator>
#include <stack>
#include <vector>
using namespace std;

class QueueUsingStack{
    private:
    stack<int> input;
    stack<int> output;

    public:
    void push(int data){
        input.push(data);
    }

    void top(){
        cout<<"\nTop element: "<<input.top()<<endl;
    }

    int pop(){
        int elementToPop;
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            elementToPop = output.top();
            output.pop();
            while(!output.empty()){
                input.push(output.top());
                output.pop();
            }
        }
        return elementToPop;
    }

    int peek(){
        int top;
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            top = output.top();
            while(!output.empty()){
                input.push(output.top());
                output.pop();
            } 
        }
        return top;
    }

    void display(){
        vector<int> vec;
        while(!input.empty()){
            vec.push_back(input.top());
            input.pop();
        }
        cout<<"\nQueue :"<<endl;
        for(int i:vec){
            cout<<i<<" ";
        }

        for(int i=vec.size()-1; i>=0; i--){
            input.push(vec[i]);
        }
    }
};

int main(){
    QueueUsingStack q = QueueUsingStack();
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.display();
    q.display();

    cout<<"\nFront element: "<<q.peek();
    cout<<"\nFront element: "<<q.peek();

    cout<<"\nElement Popped: "<<q.pop()<<endl;
    q.display();
    return 0;
}
