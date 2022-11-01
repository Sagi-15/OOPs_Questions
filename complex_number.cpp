#include <iostream>
using namespace std;
class ComplexNumbers{
    private:
        int real_part;
        int imaginary_part;
    public:
        ComplexNumbers(int real_part=0,int imaginary_part=0){
            this->real_part=real_part;
            this->imaginary_part=imaginary_part;
        }
        /*(a+ib)+(c+id)=(a+c)+i(b+d)*/
        void plus(const ComplexNumbers &c2){
            this->real_part=this->real_part+c2.real_part;
            this->imaginary_part=this->imaginary_part+c2.imaginary_part;
        }
        /*(a+ib)*(c+id)=(ac-bd)+i(ad+bc)*/
        void multiply(const ComplexNumbers &c2){
            this->real_part=((this->real_part)*(c2.real_part))-((this->imaginary_part)*(c2.imaginary_part));
            this->imaginary_part=((this->real_part)*(c2.imaginary_part))+((this->imaginary_part)*(c2.real_part));
        }
        void print(){
            cout<<this->real_part<<" + i"<<this->imaginary_part<<endl;
        }
};