//  <-------------------------------------------------------->
// Created by -  Sunay Bhoyar 
// Roll No. - 21110
// Course - SE (sem 3) DSL CE (SPPU 2019)
// <-------------------------------------------------------->

#include<iostream>
#include<string>
using namespace std ;

// <-------------------------------------------------------->
// this stack class is defined here
class Stack{                                                            // the stack class is defined here
public:
    char data[20];
    int top = -1 ;

    // this is the function to add the element in the stack
    void push(char val){
        if(top== 19){
            cout<<"Stackoverflow"<<endl;
        }
        else{
            top ++ ; 
            data[top] = val ;
        }
    }

    // this is the function which returns the top value of the stack
    int getTop(){
        return data[top];
    }

    // this is the function which pops the top element of the stack
    void pop(){
        if(top == -1){
            cout<<"Stack is empty"<<endl ; 
        }
        else {
            top -- ;
        }
    }

};
// <-------------------------------------------------------->

                                                                                        //main function starts here
int main(){

    Stack S;                            
    string given_data , res="";

    cout<<"Enter the infix equationand "<<endl ;
    cin >>given_data ; 

    for ( int i = 0 ; i <given_data.size();i++){

        // if opening bracket occurs
        if(given_data[i] =='('){
            S.push(given_data[i]);
        }

        // if closing bracket occurs
        else if(given_data[i]==')'){
            while(S.getTop()!='('){
                res += S.getTop();
                S.pop();
            }
            S.pop();
        }

        // for the the multiplication and the division 
        else if(given_data[i] == '*' ||given_data[i] == '/' ){
            while((S.getTop() == '*' && S.getTop() == '/')||(S.getTop()!='('&& S.getTop()!='+' && S.getTop()!='-')){
                res += S.getTop();
                S.pop();
            }
            S.push(given_data[i]);
        }

        // for the the addition and the substraction  
        else if(given_data[i] == '+' ||given_data[i] == '-' ){
            while((S.getTop() == '*' && S.getTop() == '/'&& S.getTop()=='+' && S.getTop()=='-')||(S.getTop()!='(')){
                res += S.getTop();
                S.pop();
            }
            S.push(given_data[i]);
        }

        else{
            res += given_data[i];
        }
    }

    cout<<res ;         // output for result 
}
// <-------------------------------------------------------->