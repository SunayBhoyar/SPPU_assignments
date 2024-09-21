#include<iostream>
#include<string>
using namespace std;

class Publictions {
public :
	string Title ;
	float price ;
};

class Book : public Publictions{
public :
	int pageCount ;
	Book (){
		Publictions::Title = "None";
		Publictions::price = '0';
		pageCount = 0;
	}
	void getBookData(){
		cout<<"Enter the title of the Book";
		cin>>Publictions::Title;
		cout<<"Enter the price of the Book";
		cin>>Publictions::price;
		cout<<"Enter page number of the book";
		cin>>pageCount;
	}
	void showBookData(){
		cout<<"The title of the Book - ";
		cout<<Publictions::Title<<endl;
		cout<<"The price of the book - ";
		cout<<Publictions::price<<endl;
		cout<<"The page number of the book - ";
		cout<<pageCount<<endl;
	}
};

class Tape : public Publictions {
public :
	float playTime ;
	Tape (){
		Publictions::Title = "None";
		Publictions::price = '0';
		playTime = 0;
	}
	void getTapeData(){
		cout<<"Enter the title of the tape";
		cin>>Publictions::Title;
		cout<<"Enter the price of the tape";
		cin>>Publictions::price;
		cout<<"Enter play time of the tape";
		cin>>playTime;
	}
	void showTapeData(){
		cout<<"The title of the Tape - ";
		cout<<Publictions::Title<<endl;
		cout<<"The price of the Tape - ";
		cout<<Publictions::price<<endl;
		cout<<"The play time of the tape - ";
		cout<<playTime<<endl;
	}

};

int main(){
	int menu ;
	Book book ;
	Tape tape ;
	while (1>0){
		cout<<"Select the menu"<<endl<<"1)Enter book record"<<endl<<"2)Enter tape record"<<endl<<"3)View book record"<<endl<<"4)View tape record"<<endl<<"0)Exit"<<endl;
		cin>>menu;
		if(menu == 0){
			break;
		}
		else if(menu == 1) {
			book.getBookData();
		}
		else if(menu == 2) {
			tape.getTapeData();
		}
		else if (menu == 3){
			book.showBookData();
		}
		else if (menu == 4){
			tape.showTapeData();
		}
		else{
			cout<<"Enter valid number"<<endl;
		}


	}
	return 0 ;
}
