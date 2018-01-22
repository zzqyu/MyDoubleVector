#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;
namespace hw1{
	class MyDoubleVector{
		public:
			
			MyDoubleVector();
			MyDoubleVector(const MyDoubleVector& v);
			~MyDoubleVector();
			void operator = (const MyDoubleVector& v);
			void operator +=(const MyDoubleVector& v);
			double& operator[](const int idx) ;
			double& operator[](const int idx) const;
			MyDoubleVector operator +(const MyDoubleVector& v);
			MyDoubleVector operator -(const MyDoubleVector& v);
			double operator *(const MyDoubleVector& v);
			MyDoubleVector operator -();
			bool operator ==(const MyDoubleVector& v);
			MyDoubleVector operator()(double x);
			double pop_back( );
			void push_back(double entry);
			size_t capacity( ) const{return cap;}
			size_t size( ) const{return used;}
			void reserve(size_t n);
			bool empty( ) const;
			void clear( );
			
		private:
			double *data;
			int used;
			int cap;
	};
}
