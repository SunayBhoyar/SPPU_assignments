//  <-------------------------------------------------------->
// Created by -  Sunay Bhoyar 
// Roll No. - 21110
// Course - SE (sem 3) DSL CE (SPPU 2019)
// <-------------------------------------------------------->

#include<iostream>
#include<string>
using namespace std ;

// <-------------------------------------------------------->
class DQueue{
public:
    int data [20];
    int front ; 
    int back ;

    DQueue(){
        front = -1; 
        back = -1;
    }
    bool full(){
        if((front == 0 && back == 19) || (front == back +1 )){
            return true ;
        }
        return false;
    }
    bool empty(){
        if(front == -1){
            return true ;
        }
        return false ;
    }

    void insertf(int val){
        if(full()){
            cout<<"Queue is full\n";
        }
        if(front == -1){
            front = 0 ;
            back = 0 ;
        }
        else if(front == 0 ){
            front = 19;
        }
        else {
            front -- ;
        }
        data[front] = val ;
    }

    void insertr(int val){
        if(full()){
            cout<<"Queue is full\n";
            return ;
        }
        if(front == -1){
            front = 0 ;
            back = 0 ;
        }
        else if(back == 19 ){
            back = 0;
        }
        else {
            back ++ ;
        }
        data[back] = val ;
    }

    int deletef(){
        if(empty()){
            cout<<"Queue is empty"<<endl ;
            return -1 ;
        }
        int temp = data[front];
        if(front == back){
            front = back = - 1;
        }
        else if(front == 19){
            front = 0 ;
        }
        else {
            front ++ ;
        }
        return temp ;
    }

    int deleter(){
        if(empty()){
            cout<<"Queue is empty"<<endl ;
            return -1 ;
        }
        int temp = data[back];
        if(front == back){
            front = back = - 1;
        }
        else if(back == 0){
            back = 19;
        }
        else {
            back -- ;
        }
        return temp ;
    }

    void display(){
        int temp = front ;
        if(empty()){
            cout<<"Queue is empty"<<endl ;
            return ;
        }
        else if(front <= back ){
            for (int i = temp ; i <= back ; i++){
                cout<<data[i]<<" ";
            }
            cout<<endl ;
            return ;
        }
        else if(front > back){
            while(front != 19){
                cout<<data[temp]<<" ";
            }
            cout<<endl ;
            return ;
        }
    }
};

int main(){
    DQueue Q ;
    Q.insertf(1);
    Q.insertr(2);
    Q.insertr(3);
    Q.display();
    Q.deletef();
    Q.display();
    Q.deleter();
    Q.display();
}