//  <-------------------------------------------------------->
// Created by -  Sunay Bhoyar 
// Roll No. - 21110
// Course - SE (sem 3) DSL CE (SPPU 2019)
// <-------------------------------------------------------->

#include<iostream>
#include<string>
using namespace std ;

// <-------------------------------------------------------->
class Node{
    public:
    int data;
    int priority;
    Node *next ;

    Node (int data_ = 0 , int priority_ = 0){
        data = data_;
        priority = priority_ ;
    }
};
class PQueue{
    public:
    Node *front ;
    Node *back;

    PQueue(){
        front = NULL ;
        back = NULL ;
    }

    void push(int data_ , int priority_){
        if (front == NULL){
            Node *temp1 = new Node(data_,priority_);
            front = temp1 ;
            back = temp1 ;
            return ;
        }
        
        Node *prev = front ;
        Node *temp = front->next ;
        if(priority_ >= front -> priority){
            Node *temp1 = new Node(data_,priority_);
            temp1->next = front;
            front = temp1 ;
        }
        else if(priority_ <= back -> priority){
            Node *temp1 = new Node(data_,priority_);
            back->next = temp1;
            back = temp1 ;
        }
        else{
            while (priority_ < temp->priority){
                prev = temp ;
                temp = temp->next ;
            }
            Node *temp1 = new Node(data_,priority_);
            back->next = temp;
            back->next = temp1 ;
        }
    }

    void display(){
        if(front == NULL){
            cout<<"the queue is empty"<<endl ;
            return ; 
        }
        Node *temp = front ;
        while(temp -> next != NULL){
            cout<<temp->data<<" ";
            temp = temp ->next ;
        }
        cout<<temp->data<<" ";
        cout<<endl ;
    }
};

int main(){
    PQueue Q ;
    Q.push(1,1);
    Q.push(100 ,2);
    Q.push(10 ,5);
    Q.push(11 ,1);
    Q.display();
    return 1 ;
}

