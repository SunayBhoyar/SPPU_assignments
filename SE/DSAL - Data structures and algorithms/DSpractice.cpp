// Created by Suany Bhoyar (21110 SE)
// ## imp please enter the name less than 10 chars, division single letter , year less than 10 , department in 4 digit initials max

#include<iostream>
#include<iostream>
#include<fstream>
#include<string>
using namespace std ;
string padString(const string& inputString, int targetLength) {
    string paddedString = inputString;

    if (paddedString.length() < targetLength) {
        paddedString.resize(targetLength, ' ');
    }

    return paddedString;
}

class Student{
    string name = ""; 
    int roll = 0 ;
    char div  = 'A';
    int year = 1 ;
    string department = "COMP";
public:
    void createEntry(string name_ = "", int roll_ = 0, char div_ = 'A', int year_ = 1, string department_ = "COMP" ){
        if (name_ == ""){
            cout<<"enter the name of the student -  ";
            cin >> name_ ;
            cout<<"enter the Roll number of the student -  ";
            cin >> roll_;
            cout<<"enter the division of the student -  ";
            cin >> div_ ;
            cout<<"enter the year of the student -  ";
            cin >> year_ ;
            cout<<"enter the Department of the student -  ";
            cin >> department_ ;
        }
        name = padString(name_,10) ;
        roll = roll_ ;
        div = div_ ;
        year = year_ ;
        department = padString(department_,4) ;
    }
    string retriveEntry(){
        string s =  "Roll : " + to_string(roll) +"\nName : " + name + " Div : " + div + " Year : " + to_string(year) + " Department : " + department; 
        return s ; 
    }


};

int main(){
    string buffer;
    fstream myFile;
    Student* StudentPtr ;    
        int menu ; 
        while (true){
            cout<<"\nSelect from the following options \n1) Create new student \n2) Print Whole Database\n3) Upadte a entry\n4) Search a entry\n5) Delete All Records\n0) Exit"<<endl ;
            cin >> menu ;
            if(menu == 1){
                myFile.open("File3.txt" , ios::app );
                if(!myFile){
                    cout<<"\n\n There is an error Opening the file....";
                }else{
                    StudentPtr = new Student();
                    StudentPtr -> createEntry();
                    myFile <<  StudentPtr -> retriveEntry()<<endl ;  
                    cout<<"The Entry added successfully"<<endl ;
                }
                myFile.close();
            }
            else if(menu == 2){
                myFile.open("File3.txt" , ios::in );
                while (getline(myFile, buffer)) {
                    cout << buffer<<endl;
                }
                myFile.close();
            }
            else if(menu == 3){
                int loc = 0 ;
                string name = ""; 
                char div  = 'A';
                int year = 1 ;
                string department = "COMP";
                myFile.open("File3.txt" , ios::in );
                string roll_ ;
                cout<<"Enter the roll number whose data you want to upadte - ";
                cin >> roll_ ;
                roll_ = "Roll : "+ roll_ ;
                if(!myFile){
                    cout<<"dwad";
                } 
                while (getline(myFile, buffer)) {
                    if(buffer == roll_ ){
                        myFile.close();
                        myFile.open("File3.txt");
                        myFile.seekg(loc);
                        cout<<"enter the updated name of the student -  ";
                        cin >> name ;
                        cout<<"enter the updatd division of the student -  ";
                        cin >> div ;
                        cout<<"enter the updated year of the student -  ";
                        cin >> year ;
                        cout<<"enter the updated Department of the student -  ";
                        cin >> department ;
                        name = padString(name,10) ;
                        department = padString(department,4) ;
                        myFile<< roll_ +"\nName : " + name + " Div : " + div + " Year : " + to_string(year) + " Department : " + department; 
                        break ;
                    }
                    loc+=buffer.length()+1 ;
                }

                myFile.close();
            }
            else if(menu == 4){
                int loc = 0 ;
                myFile.open("File3.txt" , ios::in );
                string roll_ ;
                cout<<"Enter the roll number whose data you want to upadte - ";
                cin >> roll_ ;
                roll_ = "Roll : "+ roll_ ;
                if(!myFile){
                    cout<<"error openining File";
                } 
                while (getline(myFile, buffer)) {
                    if(buffer == roll_ ){
                        cout<<"data found\n";
                        getline(myFile, buffer);
                        cout<<buffer<<endl;
                        break ;
                    }
                    loc+=buffer.length()+1 ;
                }

                myFile.close();
            }
            else if(menu == 5){
                string delCommand ;
                cout<<"type ' DELETE ' to delete the file - ";
                cin >> delCommand ;
                if(delCommand == "DELETE"){
                    remove("myFile");
                    cout<<"The Database was successfully deleted"<<endl ;
                }
                else {
                    cout<<"sorry the command didn't match so the database not deleted"<<endl ;
                }            
            }
            else if(menu == 0 ){
                
                break  ;
            }
            else {
                cout<<"\n Enter valid input \n";
            }
        }
        return 0 ;

    }
