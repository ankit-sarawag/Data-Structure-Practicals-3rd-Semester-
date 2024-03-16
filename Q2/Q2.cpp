// doubly linked list and it's operations
// Q2 Write a program to implement a doubly linked list as an ADT that supports the following operations
#include <iostream>
#include <stdio.h>
using namespace std;
template <class T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    Node(T data) {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

template <class T>
class DLL {
public:
    Node<T>* head;
    Node<T>* tail;
    DLL() {
        head = NULL;
        tail = NULL;
    }

    void insertAtBeg(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPos(int pos, T val) {
        if (pos == 1) {
            insertAtBeg(val);
        } else if (pos <= 0) {
            cout << "Invalid position" << endl;
        } else {
            Node<T>* newNode = new Node<T>(val);
            Node<T>* temp = head;
            for (int i = 0; i < (pos - 2) && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Invalid position" << endl;
                return;
            }
            newNode->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            newNode->prev = temp;
            temp->next = newNode;
            if (temp == tail) {
                tail = newNode;
            }
        }
    }

    void deleteAtBeg() {
        if (head == NULL) {
            cout << "Empty list" << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        cout << "Deleted element is " << temp->data << endl;
        delete temp;
    }

    void deleteAtEnd() {
        if (tail == NULL) {
            cout << "Empty list" << endl;
            return;
        }
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        cout << "Deleted element is " << temp->data << endl;
        delete temp;
    }

    void deleteAtPos(int pos) {
        if (pos <= 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1) {
            deleteAtBeg();
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; i < (pos - 1) && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp == tail) {
            cout << "Invalid position" << endl;
            return;
        }
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        cout << "Deleted element is " << temp->data << endl;
        delete temp;
    }

    int search(T val) {
        Node<T>* temp = head;
        int pos = 0;
        while (temp != NULL) {
            pos++;
            if (temp->data == val) {
                return pos;
            }
            temp = temp->next;
        }
        return -1;
    }

    void reverse() {
        Node<T>* current = head;
        Node<T>* temp = NULL;
        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != NULL) {
            head = temp->prev;
        }
    }

    void display() {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayReverse() {
        Node<T>* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};
int main(){
    cout<<"Program to implement the doubly linked list and it's operations"<<endl;
    DLL<int> dll1;
    
    
    char ans = 'y';
    while(ans == 'Y' || ans == 'y'){
        cout<<"available operations are :"<<endl;
        cout<<"insert an element at the beginning of the dll (1)"<<endl;
        cout<<"insert an element at the ending of the dll (2)"<<endl;
        cout<<"insert an element at the given position of the dll (3)"<<endl;
        cout<<"delete an element at the beginning of the dll (4)"<<endl;
        cout<<"delete an element at the ending of the dll (5)"<<endl;
        cout<<"delete an element at the given position of the dll (6)"<<endl;
        cout<<"search an element in the dll(7)"<<endl;
        cout<<"display the dll(8)"<<endl;
        cout<<"display the reverse dll(9)"<<endl;
        cout<<"reverse the dll(10)"<<endl;
        int choice;
        cout<<"which operation you want to use :";
        cin>>choice;
        switch (choice){
        case 1:
            int num1;
            cout<<"enter the element you want to add:";
            cin>>num1;
            dll1.insertAtBeg(num1);
            break;
        case 2:
            int num2;
            cout<<"enter the element you want to add:";
            cin>>num2;
            dll1.insertAtEnd(num2);
            break;
        case 3:
            int num3,pos1;
            cout<<"enter the element you want to add:";
            cin>>num3;
            cout<<"enter the position where you want to add the element: ";
            cin>>pos1;
            dll1.insertAtPos(pos1,num3);
            break;
        case 4:
            dll1.deleteAtBeg();
            break;
        case 5:
            dll1.deleteAtEnd();
            break;
        case 6:
            int pos2;
            cout<<"enter the position from where you want to delete the element: ";
            cin>>pos2;
            dll1.deleteAtPos(pos2);
            break;
        case 7:
            int num4;
            cout<<"enter the element to search :";
            cin>>num4;
            int position;
            position = dll1.search(num4);
            if(position == -1){
                cout<<"The element is not present in the linked list"<<endl;
            }
            else{
                cout<<"The position of the given element "<<num4<<" is "<<position<<endl;
            }
            break;
        case 8:
            dll1.display();
            break;
        case 9:
            dll1.displayReverse();
            break;
        case 10:
            cout<<"linked list reversed"<<endl;
            dll1.reverse();
            break;
        default:
            cout<<"invalid choice"<<endl;
            break;
        }
        do{
            cout<<"do you want to continue the program (Y/N) :";
            cin>>ans;
        }while(ans!='y' && ans!='y' && ans!='n' && ans!='N');
        cout<<endl;
    }
    if(ans=='n' || ans=='N'){
        cout<<"---------**Program Over**--------"<<endl;
    }
    return 0;
}