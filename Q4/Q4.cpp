#include <iostream>
#include <stdio.h>
using namespace std;
const int stackSize=5;
template <class T>
class stack{
    private:
        int top=-1;
        T stack[stackSize];
    public:
        bool isStackEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isStackFull(){
            if(top==(stackSize-1)){
                return true;
            }
            else{
                return false;
            }
        }
        void push(T element){
            if(isStackFull()!=true){
                top++;
                stack[top]=element;
            }
            else{
                cout<<"Overflow error"<<endl;
            }
        }
        void pop(){
            if(isStackEmpty()!=1){
                stack[top]=0;
                top--;
            }
            else{
                cout<<"Underflow error"<<endl;
            }
        }
        void display(){
            if(isStackEmpty()!=1){
                cout<<"[ ";
                for(int i=0;i<=top;++i){
                    cout<<stack[i]<<", ";
                }
                cout<<"]"<<endl;
            }
            else{
                cout<<"the stack is empty"<<endl;
                cout<<"so no element to display"<<endl;
            }
        }
        T getTop(){
            if(isStackEmpty()!=1){
                return stack[top];
            }
            else{
                cout<<"the stack is empty"<<endl;
                return -1;
            }
        }
};

int main(){
    cout<<"Program to implement the stack and it's various operations"<<endl;
    stack<int> stackObject1;
    char ans='y';
    while (ans=='y' || ans=='Y')
    {
        cout<<"Available stack operations are :"<<endl<<endl;
        cout<<"Check whether the stack is empty or not(1)"<<endl;
        cout<<"Check whether the stack is full or not(2)"<<endl;
        cout<<"Add an element at the top of the stack(3)"<<endl;
        cout<<"Remove a element from the stack(4)"<<endl;
        cout<<"Display the topmost element of the stack(5)"<<endl;
        cout<<"Display the stack(6)"<<endl<<endl;
        cout<<"which operation do you want to perform ->";
        char operation;
        cin>>operation;
        switch (operation)
        {
        case '1':
            if(stackObject1.isStackEmpty()){
                cout<<"The stack is empty"<<endl;
            }
            else{
                cout<<"The stack is not empty"<<endl;
            }
            break;
        case '2':
            if(stackObject1.isStackFull()){
                cout<<"The stack is full"<<endl;
            }
            else{
                cout<<"The stack is not full"<<endl;
            }
            break;
        case '3':
            int element;
            cout<<"enter the element you want to add:";
            cin>>element;
            stackObject1.push(element);
            break;
        case '4':
            stackObject1.pop();
            break;
        case '5':
            if(stackObject1.getTop()!=-1){
                cout<<"top element is "<<stackObject1.getTop()<<endl;
            }
            break;
        case '6':
            stackObject1.display();
            break;
        
        default:
            cout<<"invalid stack operation"<<endl;
            break;
        }
    do
        {
            cout<<"do you want to continue the program(Y/N):";
            cin>>ans;
        } while (ans!='n' && ans!='N' && ans!='y' && ans!='Y');
        cout<<endl;
        
    }
    if(ans=='n' || ans=='N'){
        cout<<"-----------*Program Over*------"<<endl;
    }
    return 0;
}