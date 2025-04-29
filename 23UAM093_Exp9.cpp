#include<iostream>
using namespace std;
template<typename T>
T findMax(T a,T b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}
template<typename T>
class Calculator{
	T a,b;
	public:
		Calculator(T x=0,T y=0):a(x),b(y){}
		T add(){
			return a+b;
		}
		T subt(){
			return a-b;
		}
		T mult(){
			return a*b;
		}
		T div(){
			try{
				if(b==0)
					throw b;
				float r=a/b;	
			}
			catch(float e){
				cout<<"Infinity"<<endl;
			}
		}
		void display(){
			cout<<"Integer Operations:"<<endl;
			
		}
};
int main(){
	cout<<"Max of 5 and 10 is:"<<findMax<int>(5,10)<<endl;
	Calculator<int> c1(5,10);
	cout<<"Integer Operations:"<<endl;
	cout<<"5 + 10 = "<<c1.add()<<endl;
	cout<<"5 - 10 = "<<c1.subt()<<endl;
	cout<<"5 * 10 = "<<c1.mult()<<endl;
	cout<<"5 / 10 = "<<c1.div()<<endl;
	
	cout<<""<<endl;
	
	Calculator<float> c2(3.5,2.0);
	cout<<"float Operations:"<<endl;
	cout<<"3.5 + 2.0 = "<<c1.add()<<endl;
	cout<<"3.5 - 2.0 = "<<c1.subt()<<endl;
	cout<<"3.5 * 2.0 = "<<c1.mult()<<endl;
	cout<<"3.5 / 2.0 = "<<c1.div()<<endl;
	
	cout<<""<<endl;
	
	Calculator<double> c3(7.777,1.81818);
	cout<<"float Operations:"<<endl;
	cout<<"7.777 + 1.81818 = "<<c1.add()<<endl;
	cout<<"7.777 - 1.81818 = "<<c1.subt()<<endl;
	cout<<"7.777 * 1.81818 = "<<c1.mult()<<endl;
	cout<<"7.777 / 1.81818 = "<<c1.div()<<endl;
}





