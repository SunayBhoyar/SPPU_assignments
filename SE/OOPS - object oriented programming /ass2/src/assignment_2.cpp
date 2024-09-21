#include<iostream>
using namespace std;

class students {
public :
	string Name ,  BloodGroup ,ContactAddress;
	int  DateOfBirth , Height , Weight , InsurancePolicy, TelephoneNumber ,DrivingLicence ;
	long long int Number ;
//	this are public member functions

	static int total;
//	this is default constructor
	students (){
		cout<<"Defaut construstor is called"<<endl ; 
		total ++;
	}
//	this is parametised constructor
	students(string Name_ ,string BloodGroup_ ="Not Given",string ContactAdress_= "Not given", int DateOfBirth_ = 0, int Height_ = 0, int Weight_ = 0, int InsurancePolicy_ =0, long long int Number_ = 0, int TelephoneNumber_ = 0, int DrivingLicence_= 0){
		this-> Name = Name_;
		this-> BloodGroup = BloodGroup_;
		this-> ContactAddress = ContactAdress_ ;
		this-> DateOfBirth = DateOfBirth_ ;
		this-> Height = Height_ ;
		this-> Weight = Weight_ ;
		this-> InsurancePolicy = InsurancePolicy_;
		this-> Number = Number_ ;
		this-> TelephoneNumber = TelephoneNumber_  ;
		this-> DrivingLicence = DrivingLicence_ ;
		total ++;
	}

//	this is copy constructor
	students(students &obj){
		this-> Name = obj.Name;
		this-> BloodGroup = obj.BloodGroup;
		this-> ContactAddress = obj.ContactAddress;
		this-> DateOfBirth = obj.DateOfBirth;
		this-> Height = obj.Height ;
		this-> Weight = obj.Weight ;
		this-> InsurancePolicy = obj.InsurancePolicy;
		this-> Number = obj.Number ;
		this-> TelephoneNumber = obj.TelephoneNumber ;
		this-> DrivingLicence = obj.DrivingLicence ;
		cout<<"copy constructor is called"<<endl;
		total ++ ;
	}
//	this is member function
	void printData(){
		cout<<"Name - "<< Name <<endl;
		cout<<"Blood Group - "<<BloodGroup <<endl;
		cout<<"Contact Adress - "<< ContactAddress <<endl;
		cout<<"DOB - "<< DateOfBirth <<endl ;
		cout<<"Height - "<< Height <<endl ;
		cout<< "Weight - "<<Weight <<endl;
		cout<<"Insurance Policy number - - "<< InsurancePolicy <<endl;
		cout<<"Number - "<< Number <<endl ;
		cout<<"Telephone Number - "<< TelephoneNumber <<endl ;
		cout<<"Driving Licence - "<< DrivingLicence<<endl ;
	}

//	//	this is inline function
	inline void TotalMembers (){
		cout<<total<<endl;
	}

//	this is destructor
	~students(){
		cout<<"the object is destroyed"<<endl;
	}


	
};

int students::total=0;

int main (){
//	here dynamic memory allocation
	students *def[1];
	def[0] = new students("nam","AB+","mamas home",06032003,170,82,4269,8007077161,2020,4269);
	def[0] -> printData();
//	Here the dynamic object is destroyed
	delete def[0];

	cout<<endl;
//	here a normal object is created
	students s1("Sunay","AB+","mamas home",06032003,170,82,4269,8007077161,2020,4269);
	s1.printData();

	cout<<endl;
//	here copy constructor is called
	students s2(s1);
	s2.printData();

//	here inline function is called
	s2.TotalMembers();

	return 0 ;
}



