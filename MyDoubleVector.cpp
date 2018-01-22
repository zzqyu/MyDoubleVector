#include <cassert>
#include <cstdlib>
#include <iostream>
#include "MyDoubleVector.h"

using namespace std;

namespace hw1{
	MyDoubleVector::MyDoubleVector(){
	// Precondition: --
	// Postcondition: private member �ʱ�ȭ  
		used = 0;
		cap = 64;
		data = new double[cap];
	}
	MyDoubleVector::MyDoubleVector(const MyDoubleVector& v){
	// Precondition: const MyDoubleVector& ��ü  
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
	// Precondition: const MyDoubleVector& ��ü  
	// Postcondition: deep copy, ������ member�� ������ �ʱ�ȭ �� �ش� . 
	// copy()�Լ��� algorithm�� include���־�� ��  
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
	// Precondition: const MyDoubleVector& ��ü  
	// Postcondition: RHS�� LHS�� �����Ϳ� �߰�   
	// copy()�Լ��� algorithm�� include���־�� ��  
		if (used + v.size() > cap)
            reserve(used + v.size());
        copy(v.data , v.data + v.used, data + used);
		used += v.size();
	}
	double& MyDoubleVector::operator[](const int idx) { 
	// Precondition: ��� integer , index < used
	// Postcondition: reference ������ return �� �־�� �ϰ�, 
	// precondition������ ������Ű�� ������ �޽��� ���  
		if (idx <0 || idx >= used) {
			cout << "index <0 or index >= size !!" << idx << endl;
			double a;
			return a;
		}
		return data[idx]; 
		
	}
	double& MyDoubleVector::operator[](const int idx) const { 
	// Precondition: ��� integer , index < used
	// Postcondition: reference ������ return �� �־�� �ϰ�, 
	// precondition������ ������Ű�� ������ �޽��� ���  
		if (idx <0 || idx >= used) {
			cout << "index <0 or index >= size !!" << idx << endl;
			double a;
			return a;
		}
		return data[idx]; 	
	}
	MyDoubleVector MyDoubleVector::operator +(const MyDoubleVector& v){
	// Precondition: size�� ���� const MyDoubleVector& ��ü  
	// Postcondition: �� �׸��� ���Ѵ�. 
		MyDoubleVector result = *this;
		assert(result.size()== v.size());
		for(int i = 0; i < result.size(); i++){
			result[i] += v[i];
		}
		return result;
	}
	MyDoubleVector MyDoubleVector::operator -(const MyDoubleVector& v){
	/// Precondition: size�� ���� const MyDoubleVector& ��ü  
	// Postcondition: �� �׸��� ����. 
		MyDoubleVector result = *this;
		assert(result.size()== v.size());
		for(int i = 0; i < result.size(); i++){
			result[i] -= v[i];
		}
		return result;
	}
	double MyDoubleVector::operator *(const MyDoubleVector& v){
	/// Precondition: size�� ���� const MyDoubleVector& ��ü  
			// Postcondition: �� �׸��� ���ؼ� ���Ѵ�. 
		MyDoubleVector left = *this;
		double result = 0;
		assert(left.size()== v.size());
		for(int i = 0; i < left.size(); i++){
			result+=(left[i] * v[i]);
		}
		return result;
	}
	MyDoubleVector MyDoubleVector::operator -(){
	// Precondition: size�� ���� const MyDoubleVector& ��ü  
	// Postcondition: �� �׸� -1�� ���Ѵ�. 
		MyDoubleVector result = *this;
		for(int i = 0; i < result.size(); i++){
			result[i] *= -1;
		}
		return result;
	}
	bool MyDoubleVector::operator ==(const MyDoubleVector& v){
	// Precondition: const MyDoubleVector& ��ü  
	// Postcondition: �� ��ü�� ����� ũ�Ⱑ ��ġ�ϰ�, 
	//�׸��� ���ڰ� ��� ��ġ�ϸ� true �ƴϸ� false  
		assert(used== v.size());
		for(int i=0; i<used; i++){
			for(int j=0;v[j]!=data[i];j++) {
		   		if(j==v.size()) return false;
			}
		}
		return true;
	}
	MyDoubleVector MyDoubleVector::operator()(double x){
	// Precondition: �Ǽ�  
	// Postcondition: ����Ʈ�� ��� �׸��� �޾ƿ� �Ǽ��� �����Ѵ�.	
		MyDoubleVector result = *this;
		for(size_t i = 0; i<used; i++){
			result[i] = x;
		}
		return result;
	}
	double MyDoubleVector::pop_back( ){
	// Precondition: -  
	// Postcondition: ����Ʈ�� ������ �׸��� �������ְ� size�� 1 ���� ��Ų��. 
		return data[--used];
	}
	void MyDoubleVector::push_back(double entry){
	// Precondition: �Ǽ�  
	// Postcondition: ����Ʈ�� ��� �׸��� �޾ƿ� �Ǽ��� �����Ѵ�.	
		data[used] = entry;
		used++;
	}
	void MyDoubleVector::reserve(size_t n){
	// Precondition: �缳���� ������(���) 
	// Postcondition: n��  
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
	// Postcondition: ����Ʈ�� ����ִ��� Ȯ���ϰ�, ������� true�� ����  
		bool result =false;
		if(used== 0) result = true;
		return result;  
	}
	void MyDoubleVector::clear( ){
	// Precondition: -  
	// Postcondition: ����Ʈ�� ������� ������ ���� �ʱ�ȭ  
		used=0;
		delete[] data;
		data = new double[cap];
	}
}
