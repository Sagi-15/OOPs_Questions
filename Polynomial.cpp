#include <iostream>
using namespace std;
class Polynomial{
    private:
        int *degCoeff;
        int capacity;
    public:
        //Default constructor
        Polynomial(){
            /*Initialised capacity to 5*/
            this->capacity=5;
            this->degCoeff=new int[capacity];
            /*Now initialising all values to 0*/
            for(int i=0;i<capacity;i++){
                this->degCoeff[i]=0;
            }
        }
        //Copy Constructor
        Polynomial(const Polynomial &p){
            /*Copied content of p to this*/
            this->capacity=p.capacity;
            this->degCoeff=new int[this->capacity];
            for(int i=0;i<capacity;i++){
                this->degCoeff[i]=p.degCoeff[i];
            }
        }
        //Overloading = operator
        void operator=(const Polynomial &p){
            /*Same functionality as copy constructor*/
            this->capacity=p.capacity;
            this->degCoeff=new int[this->capacity];
            for(int i=0;i<capacity;i++){
                this->degCoeff[i]=p.degCoeff[i];
            }
        }
        void setCoefficient(int degree,int coefficient){
            if(degree>=this->capacity){
                int previous_capacity=this->capacity;//so that for loop mei copy kar ske
                int *copy_previous=this->degCoeff;
                this->capacity*=2;
                //naya degree coeff array bann
                this->degCoeff=new int[capacity];
                for(int i=0;i<previous_capacity;i++){
                    this->degCoeff[i]=copy_previous[i];
                }
                /*pehle peechle sab content copy kar liya
                    then baaki 2nd half ko 0 se need to initialise*/
                for(int i=previous_capacity;i<this->capacity;i++){
                    this->degCoeff[i]=0;
                }
            }
            this->degCoeff[degree]=coefficient;
        }
        void print(){
            for(int i=0;i<this->capacity;i++){
                if(this->degCoeff[i]!=0){
                    /*Agar coefficient not 0 tabhi print karenge.*/
                    cout<<this->degCoeff[i]<<"x"<<i<<" ";
                }
            }
            cout<<endl;
        }
        Polynomial operator+(Polynomial &p){
            /*Pehle capacity increase kar of smaller capacity walla
                to bigger capacity*/
            Polynomial P_Result;
            if(this->capacity>p.capacity){
                int *previous_poly=p.degCoeff;
                p.degCoeff=new int[this->capacity];
                for(int i=0;i<p.capacity;i++){
                    p.degCoeff[i]=previous_poly[i];
                }
                for(int i=p.capacity;i<this->capacity;i++){
                    p.degCoeff[i]=0;
                }
            }
            else if(this->capacity<p.capacity){
                int *previous_poly=this->degCoeff;
                this->degCoeff=new int[p.capacity];
                for(int i=0;i<this->capacity;i++){
                    this->degCoeff[i]=previous_poly[i];
                }
                for(int i=this->capacity;i<p.capacity;i++){
                    this->degCoeff[i]=0;
                }
            }
            /*Now add corresponding coefficients*/
            for(int i=0;i<p.capacity;i++){
                int coefficient=p.degCoeff[i]+(this->degCoeff)[i];
                P_Result.setCoefficient(i,coefficient);
            }
            return P_Result;
        }
        Polynomial operator-(Polynomial &p){
            /*Pehle capacity increase kar of smaller capacity walla
                to bigger capacity*/
            Polynomial P_Result;
            if(this->capacity>p.capacity){
                int *previous_poly=p.degCoeff;
                p.degCoeff=new int[this->capacity];
                for(int i=0;i<p.capacity;i++){
                    p.degCoeff[i]=previous_poly[i];
                }
                for(int i=p.capacity;i<this->capacity;i++){
                    p.degCoeff[i]=0;
                }
            }
            else if(this->capacity<p.capacity){
                int *previous_poly=this->degCoeff;
                this->degCoeff=new int[p.capacity];
                for(int i=0;i<this->capacity;i++){
                    this->degCoeff[i]=previous_poly[i];
                }
                for(int i=this->capacity;i<p.capacity;i++){
                    this->degCoeff[i]=0;
                }
            }
            /*Now add corresponding coefficients*/
            for(int i=0;i<p.capacity;i++){
                int coefficient=p.degCoeff[i]-(this->degCoeff)[i];
                P_Result.setCoefficient(i,coefficient);
            }
            return P_Result;
        }
        Polynomial operator*(Polynomial &p){
            Polynomial P_Result;
            /*as 3 terms*2 terms=>6 terms ans max*/
            P_Result.capacity=(this->capacity)*(p.capacity);
            P_Result.degCoeff=new int[P_Result.capacity];
            for(int i=0;i<P_Result.capacity;i++){
                P_Result.degCoeff[i]=0;
            }
            for(int i=0;i<this->capacity;i++){
                for(int j=0;j<p.capacity;j++){
                    int degree=i+j;
                    int coefficient=this->degCoeff[i]*p.degCoeff[j];
                    P_Result.degCoeff[degree]+=coefficient;
                }
            }
            return P_Result;
        }
};
int main(){
    Polynomial P1,P2;
    P1.setCoefficient(2,3);
    P1.setCoefficient(5,4);
    P1.setCoefficient(7,-1);
    P1.print();
    P2.setCoefficient(2,7);
    P2.setCoefficient(8,4);
    P2.setCoefficient(9,-4);
    P2.print();
    Polynomial P3=P1+P2;
    P3.print();
    Polynomial P4=P1-P2;
    P4.print();
    Polynomial P5=P1*P2;
    P5.print();
}