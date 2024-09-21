#include <iostream>
using namespace std ;

class Stack{
    public:
    char data[20];
    int top = -1 ;
    void input(char val){
        if(top== 19){
            cout<<"Stackoverflow"<<endl;
        }
        else{
            top ++ ; 
            data[top] = val ;
        }
    }
    int getTop(){
        return top ;
    }
    void popTop(){
        if(top == -1){
            cout<<"Stack is empty"<<endl ; 
        }
        else {
            top -- ;
        }
    }
    int isfull()
    {
        if(top==19)
            return 1;
        else
            return 0;
    }
    
    int isempty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
};

int main(){
    Stack S;
    string data ;
    cout<<"\nEnter the expression \n";
    cin>>data;
    if((data[0]==')')||(data[0]==']')||(data[0]=='}'))
    {
        cout<<"\n Invalid Expression\n";
        return 0;
    }
    else
    {   int i = 0;
        while(data[i]!='\0')
        {
            if(data[i] == '(' || data[i] == '{' || data[i] == '['){
                S.input(data[i]);
            }
            else if (data[i] == ')' ){
                if(data[S.getTop()]=='('){
                    S.popTop();
                }
                else{
                    cout<<"Not Valid";
                    break ;
                }
            }
            else if (data[i] == '}'){
                if(data[S.getTop()]=='{'){
                    S.popTop();
                }
                else{
                    cout<<"Not Valid";
                    break ;
                }
            }
            else if (data[i] == ']' ){
                if(data[S.getTop()]=='['){
                    S.popTop();
                }
                else{
                    cout<<"Not Valid";
                    break ;
                }
            }
            i=i+1;
        }
    }
    if(S.isempty())
    {
        cout<<"\nValid\n";
    }
    else{
        cout<<"Not Valid";
    }
    return 0;

}