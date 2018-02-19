#include <iostream>
using namespace std;
struct complex_t {
     float real;
    float imag;
    complex_t(){
        real=0.0f;
        imag=0.0f;
        
    }
   
complex_t add(complex_t other)const{ 
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
std::ostream & write( std::ostream & stream) {
      stream<<"("<<real<<","<<imag<<")";
    return stream;
}
   
};

int main() {
    char op;
    complex_t comp1,comp2;
    
    if(comp1.read(cin)&&(cin>>op)&&comp2.read(cin)){
    switch(op){
        case '+':
            (comp1.add(comp2)).write(cout);
            break;
        case '-':
           (comp1.sub(comp2)).write(cout);
            break;
        case '*':
           (comp1.mul(comp2)).write(cout);
            break;
        case '/':
            (comp1.div(comp2)).write(cout);

            break;
        default: cout<<"\nAn error has occured while reading input data"; break;
    }}else{  cout<<"\nAn error has occured while reading input data";}
    return 0;
}
