/*
 * Name - Sunay Bhoyar
 * Roll No. - 21110
 * Created on: -Dec-2022
 * Assignment - OOPs assignment- 6
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool sortname(vector<string>& v1,vector<string>& v2) {
     return v1[0] < v2[0];
}
bool sortdob(vector<string>& v1,vector<string>& v2) {
     return v1[0] < v2[0];
}
bool sortphone(vector<string>& v1,vector<string>& v2) {
     return v1[0] < v2[0];
}
int main(){
	vector<vector<string>> data ;
	while(1>0){
		int menu ;
		cout<<"**************MENU*************"<<endl;
		cout<<"Enter the option of the data you want to perform"<<endl<<"1)Insert"<<endl<<"2)Display"<<endl<<"3)Search"<<endl<<"4)Sort"<<endl<<"5)Delete"<<endl<<"0)Exit"<<endl;
		cin>>menu;
		if(menu == 0){
			break ;
		}
		else if(menu == 1){
			vector <string> temp ;
			string temp1 ;
			cout<<"enter the name"<<endl ;
			cin>>temp1;
			temp.push_back(temp1);
			cout<<"enter the DOB"<<endl ;
			cin>>temp1;
			temp.push_back(temp1);
			cout<<"enter the mobile number"<<endl ;
			cin>>temp1;
			temp.push_back(temp1);
			data.push_back(temp);
		}
		else if(menu == 2){
			for (int i =  0 ; i < data.vector::size();i++){
				cout<<i+1<<" "<<data[i][0]<<" "<<data[i][1]<<" "<<data[i][2]<<endl ;
			}
		}
		else if(menu == 3){
			vector <string> temp ;
			string temp1 ;
			cout<<"enter the name"<<endl ;
			cin>>temp1;
			temp.push_back(temp1);
			cout<<"enter the DOB"<<endl ;
			cin>>temp1;
			temp.push_back(temp1);
			cout<<"enter the mobile number"<<endl ;
			cin>>temp1;
			temp.push_back(temp1);
			if ( std::find(data.begin(), data.end(), temp) != data.end() )
			   cout<<"element found at location"<<endl;
			else
			   cout<<"element is not there in the database";

		}
		else if(menu == 4){
			int menu1;
			cout<<"Select the manner you want to sort data"<<endl<<"1)Name"<<endl<<"2)DOB"<<endl<<"3)phone"<<endl;
			cin>>menu1;
			if(menu1 == 1){
				sort(data.begin(), data.end(),sortname);
			}
			else if(menu1 == 2){
				sort(data.begin(), data.end(),sortdob);
			}
			else if(menu1 == 3){
				sort(data.begin(), data.end(),sortphone);
			}
			else{
				cout<<"enter a valid number"<<endl;
			}
		}
		else if(menu == 5){

		}
	}
}




