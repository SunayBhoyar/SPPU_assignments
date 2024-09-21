//  <-------------------------------------------------------->
// Created by -  Sunay Bhoyar 
// Roll No. - 21110
// Course - SE (sem 3) DSL CE (SPPU 2019)
// <-------------------------------------------------------->

#include<iostream>
#include<string>
using namespace std ;

// <-------------------------------------------------------->
// this queue class is defined here
class queue{
public :
    char data[20] ; 
    int front = -1; 
    int back = -1;

    void add(char job){
        if(front ==-1){
            front ++ ;
            back ++ ; 
            data[front] = job ;
        }
        else{
            back ++ ; 
            data [ back ] = job ; 
        }
    }

    void display (){
        for (int i = front ; i <= back ; i++ ){
            cout << data [ i ] << endl ;
        }
    }

    void delete_job(){
        if(front > back){
            cout<<"there are no jobs to delete"<<endl ; 
        }
        else {
            front ++ ;
        }
    }
}; 
// <-------------------------------------------------------->
int main(){
    queue Q ;
    while(1>0){
        cout<<"Enter the option you want to perform \n1)Add Job\n2)Remove job\n3)display all jobs\n0)Exit"<<endl ;
        int menu ; 
        cin >> menu ; 
        if(menu == 0 ){
            break ;
        }
        else if(menu == 1){
            cout<<"enter the new job name"<<endl ;
            char new_job ; 
            cin >> new_job ; 
            Q.add(new_job) ; 
        }
        else if(menu == 2){
            Q.delete_job();
        }
        else if(menu == 3){
            Q.display();
        }
        else {
            cout<<"enter a valid option "<<endl ;
        }
    }
    return 1 ; 
}
// <-------------------------------------------------------->