#include <iostream>
using namespace std;
struct complex_t {
    
    complex_t(){
        real=0.0f;
        imag=0.0f;
        
    }
    ~complex(){
       
        
    }
    complex_t add(complex_t other)const{ //this - complex * const
complex_t result;
    result.real=real+other.real;
    result.imag=imag+other.imag;
    return result;
}
complex_t sub(complex_t other)const{
    complex_t result;
    result.real=real-other.real;
    result.imag=imag-other.imag;
    return result;
}
complex_t mul(complex_t rhs,complex_t lhs)const{
    complex_t result;
    result.real=rhs.real*lhs.real-rhs.imag*lhs.imag;
    result.imag=rhs.imag*lhs.real+rhs.real*lhs.imag;
    return result;
}
complex_t div(complex_t rhs,complex_t lhs)const{
  complex_t result;
    result.real=(rhs.real*lhs.real+rhs.imag*lhs.imag)/(lhs.real*lhs.real+lhs.imag*lhs.imag);
    result.imag=(rhs.imag*lhs.real-rhs.real*lhs.imag)/(lhs.real*lhs.real+lhs.imag*lhs.imag);
    return result;
}
std::istream & read( std::istream & stream ){
    char f1,f2,f3;
    float xreal;
    float ximag;
    if (stream>>f1 && f1=='(' && stream>>real && stream>>f2 && f2 == ',' && stream>>imag && stream>> f3 && f3 == ')') {
        real = xreal;
        imag = ximag;
    }
    else {
        stream.setstate(std::ios::failbit);
    }

    return stream;
}
std::ostream & write( std::ostream & stream) const{
      stream<<"("<<real<<","<<imag<<")";
    return stream;
}
    float real;
    float imag;
};

int main() {
    char op;
    complex_t comp1,comp2;
    
    if(read(cin,comp1)&&(cin>>op)&&read(cin,comp2)){
    switch(op){
        case '+':
            write(cout,add(comp1,comp2));
            break;
        case '-':
            write(cout,sub(comp1,comp2));
            break;
        case '*':
            write(cout,mul(comp1,comp2));
            break;
        case '/':
            write(cout,div(comp1,comp2));

            break;
        default: cout<<"\nAn error has occured while reading input data"; break;
    }}else{  cout<<"\nAn error has occured while reading input data";}
    return 0;
}
