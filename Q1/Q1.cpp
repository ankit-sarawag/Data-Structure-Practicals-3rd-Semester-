// linked list and it's operations
// Q1 Write a program to implement a singly linked list as an ADT that supports the following operations
#include <iostream>
#include <stdio.h>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template <class T>
class SLL {
public:
    Node<T>* head;
    SLL() {
        head = NULL;
    }
    int i = 0;

    void insertAtBeg(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
        ++i;
    }

    void insertAtEnd(T val) {
        if (head == NULL) {
            insertAtBeg(val);
        }
        else {
            Node<T>* newNode = new Node<T>(val);
            Node<T>* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            ++i;
        }
    }

    void insertAtPos(T val, int pos) {
        if (pos == 1) {
            insertAtBeg(val);
        }
        else if (pos <= 0) {
            cout << "Given position is out of range " << endl;
        }
        else if (pos > i) {
            insertAtEnd(val);
        }
        else {
            Node<T>* newNode = new Node<T>(val);
            Node<T>* temp = head;
            for (int j = 0; j < (pos - 2); ++j) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            ++i;
        }
    }

    void updateAtPos(T val, int pos) {
        if (pos <= 0) {
            cout << "Given position is out of range " << endl;
        }
        else if (pos > i) {
            Node<T>* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->data = val;
        }
        else {
            Node<T>* temp = head;
            for (int j = 0; j < (pos - 1); ++j) {
                temp = temp->next;
            }
            temp->data = val;
        }
    }

    void updateAtEle(T val, T val1) {
        Node<T>* temp = head;
        while (temp != NULL) {
            if (temp->data == val1) {
                temp->data = val;
                return;
            }
            else {
                temp = temp->next;
            }
        }
        if (temp == NULL) {
            cout << "The given element " << val1 << " is not present in the linked " << endl;
        }
    }

    void deleteAtBeg() {
        Node<T>* temp = head;
        head = head->next;
        cout << "deleted element is " << temp->data << endl;
        delete(temp);
    }

    void deleteAtEnd() {
        Node<T>* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        Node<T>* temp1 = temp->next;
        temp->next = NULL;
        cout << "deleted element is " << temp1->data << endl;
        delete(temp1);
    }

    void deleteAtPos(int pos) {
        if (pos == 1) {
            deleteAtBeg();
        }
        else if (pos <= 0) {
            cout << "Given position is out of range " << endl;
        }
        else if (pos > i) {
            deleteAtEnd();
        }
        else {
            Node<T>* temp = head;
            for (int j = 0; j < (pos - 2); ++j) {
                temp = temp->next;
            }
            Node<T>* temp1 = temp->next;
            temp->next = temp1->next;
            cout << "deleted element is " << temp1->data << endl;
            delete(temp1);
        }
    }

    int search(T val) {
        int position = 0;
        Node<T>* temp = head;
        while (temp != NULL) {
            ++position;
            if (temp->data == val) {
                return position;
            }
            temp = temp->next;
        }
        return -1;
    }

    Node<T>* search1(T val) {
        Node<T>* temp = head;
        while (temp != NULL) {
            if (temp->data == val) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void reverseSll() {
        Node<T>* prev = NULL;
        Node<T>* current = head;
        Node<T>* Next;
        while (current != NULL) {
            Next = current->next;
            current->next = prev;
            prev = current;
            current = Next;
        }
        head = prev;
    }
    void mergeSLL(SLL sll2) {
      Node<T>* temp1 = head;
        if (temp1 == NULL) {
            head = sll2.head;
            return;
        }
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = sll2.head;
        sll2.head = NULL; 
        }

    void displayReverseSLL(Node<T>* head) {
        if (head == NULL) {
            return;
        }
        displayReverseSLL(head->next);
        cout << head->data << " -> ";
    }

    void displaySLL() {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


int main(){
    cout<<"program to implement a singly linked list and it's operations"<<endl;
    SLL <int>sll1;
    SLL <int>sll2;

    char ans='y';
    while(ans=='y' || ans=='Y'){
        cout<<"available linked list operations are:"<<endl;
        cout<<"add an element at the beginning of the linked list (1)"<<endl;
        cout<<"add an element at the end of the linked list (2)"<<endl;
        cout<<"add an element at the given position of the linked list (3)"<<endl;
        cout<<"delete an element from the beginning of the linked list (4)"<<endl;
        cout<<"delete an element from the end of the linked list (5)"<<endl;
        cout<<"delete an element from the specified position of the linked list (6)"<<endl;
        cout<<"update an element by its position in the linked list (7)"<<endl;
        cout<<"update an element by its value in the linked list (8)"<<endl;
        cout<<"reversing the linked list (9)"<<endl;
        
        cout<<"Traversing in reverse order(11)"<<endl;
        cout<<"searching for an element and returning it's position(12)"<<endl;
        cout<<"searching for an element and returning it's pointer(13)"<<endl;
        cout<<"display the linked the list (14)"<<endl;
        cout<<"merging the linked the list with other linked list (15)"<<endl;
        int choice;
        cout<<"enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int val1;
            cout<<"enter the element to add :";
            cin>>val1;
            sll1.insertAtBeg(val1);
            break;
        case 2:
            int val2;
            cout<<"enter the element to add :";
            cin>>val2;
            sll1.insertAtEnd(val2);
            break;
        case 3:
            int val3;
            cout<<"enter the element to add :";
            cin>>val3;
            int pos1;
            cout<<"enter the position :";
            cin>>pos1;
            sll1.insertAtPos(val3,pos1);
            break;
        case 4:
            sll1.deleteAtBeg();
            break;
        case 5:
            sll1.deleteAtEnd();
            break;
        case 6:
            int pos2;
            cout<<"enter the position :";
            cin>>pos2;
            sll1.deleteAtPos(pos2);
            break;
        case 7:
            int val4;
            cout<<"enter the element to add :";
            cin>>val4;
            int pos3;
            cout<<"enter the position of the element to update :";
            cin>>pos3;
            sll1.updateAtPos(val4,pos3);
            break;
        case 8:
            int val5;
            cout<<"enter the element to add :";
            cin>>val5;
            int val6;
            cout<<"enter the  element to update :";
            cin>>val6;
            sll1.updateAtEle(val5,val6);
            break;
        case 9:
            sll1.reverseSll();
            cout<<"linked list reversed"<<endl;
            break;
        
        case 11:
            sll1.displayReverseSLL(sll1.head);
            cout<<"NULL"<<endl;
            break;
        
        case 12:
            int val7;
            cout<<"enter the element to search :";
            cin>>val7;
            int position;
            position = sll1.search(val7);
            if(position == -1){
                cout<<"The element is not present in the linked list"<<endl;
            }
            else{
                cout<<"The position of the given element "<<val7<<" is "<<position<<endl;
            }
            break;
        case 13:
            int val8;
            cout<<"enter the element to search :";
            cin>>val8;
            Node<int>* pointer;
            pointer = sll1.search1(val8);
            if(pointer == NULL ){
                cout<<"The element is not present in the linked list"<<endl;
            }
            else{
                cout<<"The pointer of the given element "<<val8<<" is "<<pointer<<endl;
            }
            break;
        case 14:
            sll1.displaySLL();
            break;
        case 15:
            cout<<"how many elements do you want to add in the second linked list:";
            int len2;
            cin>>len2;
            for(int i=0;i<len2;++i){
                if(i==0){
                    cout<<"enter the element at the beginning of the second linked list:";
                    int  j;
                    cin>>j;
                    sll2.insertAtBeg(j);
                }
                else{
                    cout<<"enter the element at the end of the second linked list:";
                    int  j;
                    cin>>j;
                    sll2.insertAtEnd(j);
                }
            }
            sll1.mergeSLL(sll2);
            cout<<"linked list merged"<<endl;
            break;
        default:
            cout<<"invalid choice"<<endl;
            break;
        }
        do{
            cout<<endl<<"do you want to continue the program(Y/N): ";
            cin>>ans;   

        } while (ans!='n' && ans!='N' && ans!='y' && ans!='Y');
        cout<<endl;
    }
    if(ans=='n' || ans=='N'){
        cout<<"---------------*Program over*-----------------"<<endl;
    } 
    return 0;
}