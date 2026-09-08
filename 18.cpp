// Write a cppp to create and display a linked list
#include<iostream>
using namespace std;
class Linkedlist{
    struct node{
        int data;
        node *link;
    } *start,*newnode,*temp;                //structure variables
    public:
        Linkedlist();                       //default constructor
        void insert();                      //function prototype
        void display();
};
void Linkedlist(){
    start  = NULL;
}
void Linkedlist()::insert(){
    int num;
    char ch = 'y';
    do{
        cout<<"Enter the number: ";
        cin>>num;
        newnode = new node;
        newnode->data=num;  
        newnode->link=NULL;
        if(start=NULL){
            start = temp = newnode;
        }else{
            temp->link=newnode;
            temp = newnode;
        }
        cout<<"Do you wanna continue: ";
        cin>>ch;
    }while(ch=='y');
}
void Linkedlist()::display(){
    temp = start;
    if(start==NULL){
        cout<<"Linked list is empty\n";
    }else{
        while(temp!=NULL){
            cout<<temp->data<<"\n";
            temp = temp->link;
        }
        cout<<"END";
    }
}



