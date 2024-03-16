// doubly linked list and it's operations
// Q3 Write a program to implement a circular linked list as an ADT that supports the following operations
#include <iostream>
#include <stdio.h>
using namespace std;
int len=0;
template <class T>
class Node{
    public:
    T data;
    Node* next;
    Node(T data){
        this->data = data;
        next = NULL;
    }
};
template <class T>
class CLL{
    public:
    Node<T>* head;
    
    CLL(){
        head = NULL;

    }

    // inserting elements in the linked list
    // inserting elements in the beginning of the linked list
    void insertAtBeg(T val){
        Node<T>* newNode = new Node<T>(val);
        if(head==NULL){
            head = newNode;
            head->next = head;    
        }
        else{
            newNode->next = head;
            Node<int>* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        }
        ++len;
    }
    // inserting elements in the end of the linked list
    void insertAtEnd(T val){
        Node<T>* newNode = new Node<T>(val); 
        if(head == NULL){
            head = newNode;
            head->next = head;
        }
        else{
            Node<int>* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        ++len;
    }
    // inserting elements in the end of the linked list
    void insertAtPos(T val, T pos){
        if(pos<=0){
            cout<<"invalid position to add an element"<<endl;
        } 
        else if(pos == 1){
            insertAtBeg(val);
        }
        else if(pos>len){
            insertAtEnd(val);
        }
        else{
            Node<int>* newNode = new Node<T>(val);
            Node<int>* temp = head;
            for(int i=0;i<(pos-2);++i){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            ++len;
        } 
    }
    
    void updateByPos(T val,int pos){
        if(pos <= 0){
            cout<<"given position is out of range "<<endl;
        }
        else if(pos > len){
            Node<int>* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->data = val;
        }
        else{
            Node<int>* temp = head;
            for(int i=0;i<(pos-1);++i){
                temp = temp->next;
            }
            temp->data = val;
        }
    }
    int updateByEle(T val1,T val2){
        Node<int>* temp = head;
        do{
            if(temp->data == val2){
                temp->data = val1;
                return 1;
            }
            else{
                temp = temp->next;
            }
        } while (temp!=head);
        if(temp == head){
            return -1;
        }
    }
    // deleting elements from the linked list
    void deleteAtBeg(){
        if(head == NULL){
            cout<<"no element to delete"<<endl;
        }
        else{
            Node<int>* temp = head;
            Node<int>* temp1 = head;
            while(temp1->next !=head){
                temp1 = temp1->next;
            }
            head = head->next;
            temp1->next = head;
            cout<<"deleted element is "<<temp->data<<endl;
            delete(temp);
        }
        --len;
    }
    void deleteAtEnd(){
        if(head == NULL){
            cout<<"no element to delete"<<endl;
        }
        else{
            Node<int>* temp = head;
            while(temp->next->next != head){
                temp = temp->next;
            }
            Node<int>* temp1 = temp->next;
            temp->next = head;
            cout<<"deleted element is "<<temp1->data<<endl;
            delete(temp1);
        }
        --len;
    }
    void deleteAtPos(int pos){
        if(pos <= 0){
            cout<<"given position is out of range"<<endl;
        }
        else if(pos == 1){
            deleteAtBeg();
        }
        else if(pos>len){
            deleteAtEnd();
        }
        else{
            Node<int>* temp = head;
            for(int i=0;i<(pos-2);++i){
                temp = temp->next;
            }
            Node<int>* temp1 = temp->next;
            temp->next = temp1->next;
            cout<<"deleted element is "<<temp1->data<<endl;
            delete(temp1);
            --len;
        }
        
    }
    int search(T val){
        Node<int>* temp = head;
        int pos=0;
        do{
          if(temp->data == val){
            return pos;
          }  
          else{
            ++pos;
            temp = temp->next;
          }
        } while (temp!=head);
        if(temp!=head){
            return -1;
        }
    }
    Node<int>* search1(T val){
        Node<int>* temp = head;
        do{
          if(temp->data == val){
            return temp;
          }  
          else{
            temp = temp->next;
          }
        } while (temp!=head);
        if(temp!=head){
            return NULL;
        }
    }
    // displaying the elements of the cll
    void display(){
        Node<int>* temp = head;
        do{
            cout<<temp->data<<" -> ";
            temp = temp->next;
        } while (temp != head);
        cout<<endl;   
    }

};

int main(){
    cout<<"Program to implement the different functions of the circular linked list";
    char ans='y';
    CLL<int> cll1;
    while(ans=='y' || ans=='Y'){
        cout<<"availble operations are:"<<endl;
        cout<<"enter an element at the beginning (1)"<<endl;
        cout<<"enter an element at the end (2)"<<endl;
        cout<<"enter an element at the kth position (3)"<<endl;
        cout<<"delete an element at the beginning (4)"<<endl;
        cout<<"delete an element at the end (5)"<<endl;
        cout<<"delete an element at the kth position (6)"<<endl;
        cout<<"display the linked list (7)"<<endl;
        cout<<"update an element in the linked list by it's position (8)"<<endl;
        cout<<"update an element in the linked list by it's value (9)"<<endl;
        cout<<"search an element and return it's position (10)"<<endl;
        cout<<"search an element and return it's pointer (11)"<<endl;
        int choice;
        cout<<"which operations you want to perform :";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int val1;
            cout<<"enter the value to add :";
            cin>>val1;
            cll1.insertAtBeg(val1);
            break;
        case 2:
            int val2;
            cout<<"enter the value to add :";
            cin>>val2;
            cll1.insertAtEnd(val2);
            break;
        case 3:
            int val3;
            cout<<"enter the value to add :";
            cin>>val3;
            int pos1;
            cout<<"enter the position where you want to add the element :";
            cin>>pos1;
            cll1.insertAtPos(val3,pos1);
            break;
        case 4:
            cll1.deleteAtBeg();
            break;
        case 5:
            cll1.deleteAtEnd();
            break;    
        case 6:
            int pos2;
            cout<<"enter the position where you want to delete the element :";
            cin>>pos2;
            cll1.deleteAtPos(pos2);
            break;
        case 7:
            cll1.display();
            break;
        case 8:
            int val4;
            cout<<"enter the value to update :";
            cin>>val4;
            int pos3;
            cout<<"enter the position where you want to update the element :";
            cin>>pos3;
            cll1.updateByPos(val4,pos3);
            break;
        case 9:
            int val5;
            cout<<"enter the value you want to update :";
            cin>>val5;
            int val6;
            cout<<"enter the value you want to update it with :";
            cin>>val6;
            cll1.updateByEle(val5,val6);
            break;
        case 10:
            int val7;
            cout<<"enter the value you want to search :";
            cin>>val7;
            int loc;
            loc = cll1.search(val7);
            if(loc == -1){
                cout<<"element is not present in the linked list"<<endl;
            }
            else{
                cout<<"position of the element "<<val7<<" in the linked list is "<<++loc<<endl; 
            }
            break;
        
        case 11:
            int val8;
            cout<<"enter the value you want to search :";
            cin>>val8;
            Node<int>* loc1;
            loc1 = cll1.search1(val8);
            if(loc1 == NULL){
                cout<<"element is not present in the linked list"<<endl;
            }
            else{
                cout<<"pointer of the element "<<val8<<" in the linked list is "<<loc1<<endl; 
            }
            break;
        
        default:
            cout<<"invalid choice"<<endl;
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