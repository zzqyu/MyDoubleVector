#include <cassert>
#include <cstdlib>
#include <iostream>
#include "MyDoubleVector.h"

using namespace std;

namespace hw1{
	MyDoubleVector::MyDoubleVector(){
	// Precondition: --
	// Postcondition: private member 초기화  
		used = 0;
		cap = 64;
		data = new double[cap];
	}
	MyDoubleVector::MyDoubleVector(const MyDoubleVector& v){
	// Precondition: const MyDoubleVector& 객체  
	// Postcondition: deep copy

        data = new double[v.capacity()];
        cap = v.capacity();
        used = v.size();
        copy(v.data, v.data + used, data);
	}
	MyDoubleVector::~MyDoubleVector(){
	// Precondition: -
	// Postcondition: All the elements of the vector are dropped,
	//and then they are removed from the vector container,
	//leaving the container with a size of 0.
		used=0;
		delete[] data;
	}
	void MyDoubleVector::operator = (const MyDoubleVector& v){
	// Precondition: const MyDoubleVector& 객체  
	// Postcondition: deep copy, 복사할 member를 가져와 초기화 해 준다 . 
	// copy()함수는 algorithm를 include해주어야 함  
		double *new_data;
		if (this == &v)
				return;
		if (cap != v.capacity())
		{ 
			new_data = new double[v.capacity()];
			clear();
			data = new_data;
			cap = v.capacity();
		}
		used = v.size();
		copy(v.data, v.data+ used, data);
	}
	void MyDoubleVector::operator +=(const MyDoubleVector& v){
	// Precondition: const MyDoubleVector& 객체  
	// Postcondition: RHS를 LHS의 데이터에 추가   
	// copy()함수는 algorithm를 include해주어야 함  
		if (used + v.size() > cap)
            reserve(used + v.size());
        copy(v.data , v.data + v.used, data + used);
		used += v.size();
	}
	double& MyDoubleVector::operator[](const int idx) { 
	// Precondition: 양수 integer , index < used
	// Postcondition: reference 형으로 return 해 주어야 하고, 
	// precondition조건을 만족시키지 않으면 메시지 출력  
		if (idx <0 || idx >= used) {
			cout << "index <0 or index >= size !!" << idx << endl;
			double a;
			return a;
		}
		return data[idx]; 
		
	}
	double& MyDoubleVector::operator[](const int idx) const { 
	// Precondition: 양수 integer , index < used
	// Postcondition: reference 형으로 return 해 주어야 하고, 
	// precondition조건을 만족시키지 않으면 메시지 출력  
		if (idx <0 || idx >= used) {
			cout << "index <0 or index >= size !!" << idx << endl;
			double a;
			return a;
		}
		return data[idx]; 	
	}
	MyDoubleVector MyDoubleVector::operator +(const MyDoubleVector& v){
	// Precondition: size가 같은 const MyDoubleVector& 객체  
	// Postcondition: 각 항목을 더한다. 
		MyDoubleVector result = *this;
		assert(result.size()== v.size());
		for(int i = 0; i < result.size(); i++){
			result[i] += v[i];
		}
		return result;
	}
	MyDoubleVector MyDoubleVector::operator -(const MyDoubleVector& v){
	/// Precondition: size가 같은 const MyDoubleVector& 객체  
	// Postcondition: 각 항목을 뺀다. 
		MyDoubleVector result = *this;
		assert(result.size()== v.size());
		for(int i = 0; i < result.size(); i++){
			result[i] -= v[i];
		}
		return result;
	}
	double MyDoubleVector::operator *(const MyDoubleVector& v){
	/// Precondition: size가 같은 const MyDoubleVector& 객체  
			// Postcondition: 각 항목을 곱해서 더한다. 
		MyDoubleVector left = *this;
		double result = 0;
		assert(left.size()== v.size());
		for(int i = 0; i < left.size(); i++){
			result+=(left[i] * v[i]);
		}
		return result;
	}
	MyDoubleVector MyDoubleVector::operator -(){
	// Precondition: size가 같은 const MyDoubleVector& 객체  
	// Postcondition: 각 항목에 -1을 곱한다. 
		MyDoubleVector result = *this;
		for(int i = 0; i < result.size(); i++){
			result[i] *= -1;
		}
		return result;
	}
	bool MyDoubleVector::operator ==(const MyDoubleVector& v){
	// Precondition: const MyDoubleVector& 객체  
	// Postcondition: 두 객체의 사이즈가 크기가 일치하고, 
	//항목의 숫자가 모두 일치하면 true 아니면 false  
		assert(used== v.size());
		for(int i=0; i<used; i++){
			for(int j=0;v[j]!=data[i];j++) {
		   		if(j==v.size()) return false;
			}
		}
		return true;
	}
	MyDoubleVector MyDoubleVector::operator()(double x){
	// Precondition: 실수  
	// Postcondition: 리스트의 모든 항목을 받아온 실수로 변경한다.	
		MyDoubleVector result = *this;
		for(size_t i = 0; i<used; i++){
			result[i] = x;
		}
		return result;
	}
	double MyDoubleVector::pop_back( ){
	// Precondition: -  
	// Postcondition: 리스트의 마지막 항목을 리턴해주고 size를 1 감소 시킨다. 
		return data[--used];
	}
	void MyDoubleVector::push_back(double entry){
	// Precondition: 실수  
	// Postcondition: 리스트의 모든 항목을 받아온 실수로 변경한다.	
		data[used] = entry;
		used++;
	}
	void MyDoubleVector::reserve(size_t n){
	// Precondition: 재설정할 사이즈(양수) 
	// Postcondition: n이  
		double *larger_array;
        if (n == cap)
            return; 
        if (n < used)
            n = used; 
        larger_array = new double[n];
        copy(data, data + used, larger_array);
        delete [ ] data;
        data = larger_array;
        cap = n;
	}
	bool MyDoubleVector::empty( ) const{
	// Precondition: -  
	// Postcondition: 리스트가 비어있는지 확인하고, 비어있음 true를 리턴  
		bool result =false;
		if(used== 0) result = true;
		return result;  
	}
	void MyDoubleVector::clear( ){
	// Precondition: -  
	// Postcondition: 리스트의 사이즈와 데이터 영역 초기화  
		used=0;
		delete[] data;
		data = new double[cap];
	}
}
