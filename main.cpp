#include<iostream>
#include<string>
#include<vector>
#include "MyDoubleVector.h"
using namespace std;
using namespace hw1;

void printV(MyDoubleVector v, string name){
	cout << name<<" = [";
		for(size_t i=0; i<v.size(); i++)
			cout << v[i] << ", ";
	cout << "\b\b]" << endl;
}
int main(){
	
	MyDoubleVector v1, v2, v3;//기본 생성자로 선언 
	cout << "MyDoubleVector 변수  v1, v2, v3 기본 생성자로 선언" <<endl;
	v1.push_back(1.2); 
	v1.push_back(2.4); 
	v1.push_back(3.6); 
	printV(v1,"v1");
	printV(v2,"v2");
	printV(v3,"v3");
	MyDoubleVector v4(v1);
	cout << "MyDoubleVector 변수  v4 카피 생성자로 선언" <<endl;
	printV(v4,"v4");
	v2=v1; 
	cout << "v2=v1" <<endl;
	printV(v2,"v2");
	cout << "v1+=v2" <<endl;
	v1+=v2;
	printV(v1,"v1");
	cout << "v1[" << 2 << "] = " << v1[2] <<endl;
	v3.push_back(5); 
	v3.push_back(6); 
	v3.push_back(7); 
	printV(v2,"v2");
	printV(v3,"v3");
	printV(v2+v3,"v2+v3");	
	printV(v2-v3,"v2-v3");	
	cout << "v2*v3 = " <<v2*v3 <<endl;
	printV(-v3,"-v3");
	printV(v3(5),"v3(5)");	
	cout << "v2==v3 " <<((v2==v3) ?"true":"false")<<endl;
	cout << "v2==v4 " <<((v2==v4) ?"true":"false")<<endl;
	
	cout << "v1" << "의 용량은 " << v1.capacity() << endl; 
	cout << "v1.reserve(v1.capacity()+30)" <<endl;
	v1.reserve(v1.capacity()+30);
	cout << "v1" << "의 용량은 " << v1.capacity() << endl; 
	cout << "v1.clear();" <<endl;
	v1.clear();
	
	cout << "v1.empty(); " <<((v1.empty()) ?"true":"false")<<endl;
	
	cout << "MyDoubleVector 포인터변수  a 선언" <<endl;
	MyDoubleVector *a = new MyDoubleVector();
	//delete[] a;
	cout << "a->empty(); " <<((a->empty()) ?"true":"false")<<endl;
	return 0;
}
