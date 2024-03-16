// implementation of binary search trees
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
// int cnt=0;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};
class BST{
    private:
        int cnt = 0;
    public:
    Node* root;
    BST(){
        root = NULL;
    }
    Node* insertIntoBST1(Node* root,int val){   //using recursion
        if(root == NULL){
            root = new Node(val);
            return root;
        }
        else{
            if(val < root->data){
                root->left = insertIntoBST1(root->left,val);
            }
            else{
                root->right = insertIntoBST1(root->right,val);
            }
        }
    }
    void insertIntoBST2(int val){          //using iteration
        if(root == NULL){
            root = new Node(val);    
        }
        else{
            Node *ptr1 = root, *ptr2;
            Node* newNode = new Node(val);
            while(ptr1 != NULL){
                ptr2 = ptr1;
                if(val < ptr1->data){
                    ptr1 = ptr1->left;
                }
                else{
                    ptr1 = ptr1->right;
                }
            }
            if(val < ptr2->data){
                ptr2->left = newNode;
            }
            else{
                ptr2->right = newNode;
            }
        }
    }
    
    int findMin(){
        Node* ptr1 = root, *ptr2;
        while(ptr1 != NULL){
            ptr2 = ptr1;
            ptr1 = ptr1->left;
        }
        return ptr2->data;
    }
    int findMax(){
        Node* ptr1 = root, *ptr2;
        while(ptr1 != NULL){
            ptr2 = ptr1;
            ptr1 = ptr1->right;
        }
        return ptr2->data;
    }
    Node* findMax1(Node* root){
        Node* ptr = root,*ptr2;
        while(ptr != NULL){
            ptr2 = ptr;
            ptr = ptr->right;
        }
        return ptr2;
    }
    Node* findMin1(Node* root){
        Node* ptr = root,*ptr2;
        while(ptr != NULL){
            ptr2 = ptr;
            ptr = ptr->left;
        }
        return ptr2;
    }
    
    Node* deleteBST(Node* root,int val){
        if(searchBST(root,val) == true){
            // main code to delete  the nodes of the tree
            // base case
            if(root == NULL){
                return root;
            }
            if(root->data == val){
                // 0 child
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    return NULL;
                }
                // 1 child
                // left child
                if(root->left != NULL && root->right == NULL){
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }
                // right child
                if(root->right != NULL && root->left == NULL){
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                // 2 child
                if(root->left != NULL && root->right != NULL){
                    int mini = findMin1(root->right)->data;
                    root->data = mini;
                    root->right = deleteBST(root->right,mini);
                }
            }
            else if(val < root->data){
                // val is smaller than root ka data move to left side
                root->left = deleteBST(root->left,val);
            }
            else{
                // val is greater than root ka data move to right side
                root->right = deleteBST(root->right,val);
            }
        }
        else{
            cout<<"the following node is not present in the binary search tree"<<endl;
        }
    }
    bool searchBST(Node* root,int val){
        if(root == NULL){
            return false;
        }
        else if(root->data == val){
            return true;
        }
        else{
            if(val < root->data){
                return searchBST(root->left,val);
            }
            else{
                return searchBST(root->right,val);
            }
        }
    }
    bool searchBST2(Node* root,int val){
        Node *ptr1 = root;
        while(ptr1 != NULL){
            if(val < ptr1->data){
                ptr1 = ptr1->left;
            }
            else if(val > ptr1->data){
                ptr1 = ptr1->right;
            }
            else{
                return true;
            }
        }
        return false;
    }

    int count(Node* root){
        
        if(root != NULL){
            ++cnt;
            count(root->left);
            count(root->right);
        }  
        return cnt;
    }
    void bfs(Node* root){
        queue<Node* > q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp == NULL){
                
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
    void preorder(Node* root){
        if(root != NULL){
            cout<<root->data<<" , ";
            preorder(root->left);
            preorder(root->right);
        }  
    }
    void inorder(Node* root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<" , ";
            inorder(root->right);
        }
        
    }
    void postorder(Node* root){
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" , ";
        }
    }
    void takeinput(){
        cout<<"enter the values of the node to be added in the tree consequently and press -1 to stop entering the elements "<<endl;
        int data;
        cin>>data;
        while(data != -1){
            insertIntoBST2(data);
            cin>>data;
        }
    }
};

int main(){
    cout<<"program for implementing a binary search tree and showing its various operations"<<endl;
    BST bst1;
    char ans='y';
    while(ans=='y' || ans=='Y'){
        cout<<"available operations are :"<<endl;
        cout<<"inserting a node in the tree (1)"<<endl;
        cout<<"searching a node in the tree (2)"<<endl;
        cout<<"finding the maximum node in the tree (3)"<<endl;
        cout<<"finding the minimum node in the tree (4)"<<endl;
        cout<<"Breadth First Searching or level order traversing of the tree (5)"<<endl;
        cout<<"preorder traversing of the tree (6)"<<endl;
        cout<<"inorder traversing of the tree (7)"<<endl;
        cout<<"postorder traversing of the tree (8)"<<endl;
        cout<<"counting the number of nodes in the tree (9)"<<endl;
        cout<<"deleting a node from the tree (10)"<<endl;
        int choice;
        cout<<"enter your choice: ";
        cin>>choice;
        switch (choice){
        case 1:
            bst1.takeinput();
            break;
        case 2:
            int val2;
            cout<<"enter the value of the node to be searched :";
            cin>>val2;
            if(bst1.searchBST2(bst1.root,val2) == true){
                cout<<"the given element "<<val2<<" is present in the binary search tree"<<endl;
            }
            else{
                cout<<"the given element "<<val2<<" is not present in the binary search tree"<<endl;
                
            }
            break;
        case 3:
            int max;
            max = bst1.findMax();
            cout<<"the maximum element present in the binary search tree is "<<max<<endl;
            break;
        case 4:
            int min;
            min = bst1.findMin();
            cout<<"the minimum element present in the binary search tree is "<<min<<endl;
            break;
        case 5:
            bst1.bfs(bst1.root);
            cout<<endl;
            break;
        case 6:
            bst1.preorder(bst1.root);
            break;
        case 7:
            bst1.preorder(bst1.root);
            break;
        case 8:
            bst1.preorder(bst1.root);
            break;
        case 9:
            int count;
            count = bst1.count(bst1.root);
            cout<<"the number of nodes present in the binary search tree is "<<count<<endl;
            break;
        case 10:
            int val3;
            cout<<"enter the value of the node to be deleted "<<endl;
            cin>>val3;
            bst1.deleteBST(bst1.root,val3);
            break;
        default:
            break;
        }
        do{
            cout<<"do you want to continue the program (Y/N): ";
            cin>>ans;
        } while (ans!='y' && ans!='Y' && ans!='n' &&ans!='Y');
        
    }
    if(ans == 'n' || ans == 'N'){
        cout<<"---------* program over *----------"<<endl;
    }
    return 0;
}

    