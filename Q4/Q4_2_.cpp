// program to evaluate a prefix or a postfix expression
#include <iostream>
#include <stdio.h> 
#include <stack> 
#include <cmath>
using namespace std;
int postfixEvaluation(string expression){
    stack <int> stack1;
    int len=expression.length();
    for(int i=0;i<len;++i){
        if(expression[i]>='0' && expression[i]<='9'){
            stack1.push(expression[i]-'0');
        }
        else{
            int a=stack1.top();
            stack1.pop();
            int b=stack1.top();
            stack1.pop();

            switch (expression[i])
            {
            case '+':
                stack1.push(b+a);
                break;
            case '-':
                stack1.push(b-a);
                break;
            case '*':
                stack1.push(b*a);
                break;
            case '/':
                stack1.push(b/a);
                break;
            case '$':
                stack1.push(pow(b,a));
                break;
            default:
                break;
            }
        }
    }
    return stack1.top();
}
int prefixEvaluation(string expression){
    stack <int> stack2;
    int len=expression.length();
    for(int i=len-1;i>=0;--i){
        if(expression[i]>='0' && expression[i]<='9'){
            stack2.push(expression[i]-'0');
        }
        else{
            int a=stack2.top();
            stack2.pop();
            int b=stack2.top();
            stack2.pop();

            switch (expression[i])
            {
            case '+':
                stack2.push(b+a);
                break;
            case '-':
                stack2.push(b-a);
                break;
            case '*':
                stack2.push(b*a);
                break;
            case '/':
                stack2.push(b/a);
                break;
            case '$':
                stack2.push(pow(b,a));
                break;
            default:
                break;
            }
        }
    }
    return stack2.top();
}
int main(){
    cout<<"program to evaluate the given postfix or a prefix expression"<<endl;
    int choice;
    cout<<"which expression do you want to evaluate prefix(1) or postfix(2):";
    cin>>choice;
    if(choice==1){
        cout<<"enter the postfix expression:";
        string prefixExpression;
        cin>>prefixExpression;
        cout<<"the value of the given postfix expression "<<prefixExpression<<" is:";
        cout<<prefixEvaluation(prefixExpression);
    }
    else{
        cout<<"enter the postfix expression:";
        string postfixExpression;
        cin>>postfixExpression;
        cout<<"the value of the given postfix expression "<<postfixExpression<<" is:";
        cout<<postfixEvaluation(postfixExpression);
    }
    return 0;
}