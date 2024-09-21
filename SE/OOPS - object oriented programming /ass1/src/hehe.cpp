
#include <iostream>
using namespace std;

class complex{
	float r , i ;
	public:
	complex(float a = 0 ,float b = 0){
			r = a;
			i = b;
		}
	complex operator + (complex a) {
	    complex res;
	    res.r = r + a.r;
	    res.i = i + a.i;
	    return res;
	    }
	complex operator - (complex a) {
		    complex res;
		    res.r = r - a.r;
		    res.i = i - a.i;
		    return res;
		    }
	complex operator * (complex m){
		complex res;
		res.r = (r*m.r) - (i*m.i);
		res.i = (r*m.i) + (i*m.i);
		return res;
		}
	friend ostream &operator << (ostream &out,complex &c){
		out<<"================================================"<<endl<<c.r<<" + "<<c.i<<"i"<<endl;
		return out;
	}
	friend istream &operator >> (istream &in,complex &c){
		cout<<"Enter the real part";
		in>>c.r;
		cout<<"Enter the imaginary part";
		in>>c.i;
		return in;
	}
};

int main() {
	while (1>0){
		int menu;
		cout<<"Enter 1 to proceed and enter data or press 0 to exit the code";
		cin>>menu;
		if (menu == 0){
			break;
		}
		else{
			cout<<"Enter the first complex number data";
			complex c1,c2;
			cin>>c1>>c2;
			while (1>0){
			int menu1;
			cout<<"================================================"<<endl<<"Enter the option of the menu you want to do - "<<endl<<"1)Addition"<<endl<<"2)multiplication"<<endl<<"3)show the numbers"<<endl<<"0)Exit"<<endl;
			cin>>menu1;
			if (menu1 == 1){
				complex c3;
				c3 = c1 + c2;
				cout<<c3;
				}
			else if (menu1 == 2){
				complex c3;
				c3 = c1 * c2 ;
				cout<<c3;
				}
			else if (menu1 == 3){
				cout<<c1<<c2;
				}
			else if (menu1 == 0) {
				break;
			}
			else {
				cout<<"enter vaild option";
			}
			}
		}
	}
	return 0;
}
