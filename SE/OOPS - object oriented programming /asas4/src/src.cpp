/*
	Name : Sunay Bhoyar
	Class: SE1
	Batch: E1
	Roll Number : 21110
	Subject : OOP Lab
*/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Student{

public:

	string name ;
	int rollNumber ;

	Student(){
		name = "none";
		rollNumber = 0;
	}

	void accept(string name_ , int rollNumber_){
		name = name_;
		rollNumber = rollNumber_ ;
	}
	void write(fstream &dataEntryFile){
		dataEntryFile << "name - " << name <<endl;
		dataEntryFile << "roll number - " << rollNumber <<endl;
	}
	void read(fstream &dataRetriveFile){
		string line ;
		while( getline(dataRetriveFile,line)){
			cout<<line<<endl;
		}
	}
};

int main(){
	fstream file,retrive;
	file.open("File.txt",ios::out);

	Student s1,s2,s3 ;
	s1.accept("kishan",1);
	s2.accept("abhishek",2);
	s3.accept("jehtalal",3);
	s1.write(file);
	s2.write(file);
	s3.write(file);
	file.close();

	Student sample;
	retrive.open("File.txt",ios::in);
	sample.read(retrive);
	return 0;
}

