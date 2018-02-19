#include <iostream>
using namespace std;
struct complex_t {
     float real;
    float imag;
    complex_t(){
        real=0.0f;
        imag=0.0f;
        
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
complex_t mul(complex_t other)const{
    complex_t result;
    result.real=real*other.real-imag*other.imag;
    result.imag=imag*other.real+real*other.imag;
    return result;
}
complex_t div(complex_t other)const{
  complex_t result;
    result.real=(real*other.real+imag*other.imag)/(other.real*other.real+other.imag*other.imag);
    result.imag=(imag*other.real-real*other.imag)/(other.real*other.real+other.imag*other.imag);
    return result;
}
std::istream & read( std::istream & stream ){
    char f1,f2,f3;
    float xreal;
    float ximag;
    if (stream>>f1 && f1=='(' && stream>>xreal && stream>>f2 && f2 == ',' && stream>>ximag && stream>> f3 && f3 == ')') {
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
