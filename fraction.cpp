#include <iostream>
using namespace std;
int HCF(int a,int b){
    if(a==b){
        return a;
    }
    else if(a>b){
        return HCF(a-b,b);
    }
    else if(a<b){
        return HCF(a,b-a);
    }
}
class Fraction{
    private:
        /*Our class has 2 properties numerator and denominator
            using these 2 can get fraction as
            (numerator/denominator)*/
        int numerator;
        int denominator;
    public:
        //Constructor for our class
        Fraction(int numerator=0,int denominator=1){
            /*So agar object banate time no parameters passed
                then by default fraction=0/1=0*/
            /*this keyword contains address of the current object.
                so, this->numerator se reach current object
                ke numerator attribute tak aur usko parameter 
                value se set.*/
            this->numerator=numerator;
            /*Agar denominator user nei 0 input diya then set
                denominator as 1*/
            if(denominator==0){
                cout<<"Denominator can't be 0 so we are setting denominator to 1."<<endl;
                this->denominator=1;
            }
            else{
                this->denominator=denominator;
            }
        }
        //Getter function
        int get_numerator(){
            /*No need of parameter mei object pass as this se
                already have object's address.*/
            return this->numerator;
        }
        int get_denominator(){
            return this->denominator;
        }
        //Setter function
        void set_numerator(int numerator){
            this->numerator=numerator;
        }
        void set_denominator(int denominator){
            /*Can't have denominator as 0 so set condition
                that agar user nei 0 pass as deno. then 
                error message display*/
            if(denominator==0){
                cout<<"Denominator of a fraction cannot be 0."<<endl;
            }
            else{
                this->denominator=denominator;
            }
        }
        //Function to simplyfy the fraction ie hcf se divide and all
        void simplyfy(){
            /*Agar numerator aur denominator dono negative then
                a/b=(-a)/(-b) eg.->(-6/-7)=6/7*/
            if(this->numerator<0 && this->denominator<0){
                this->numerator*=-1;
                this->denominator*=-1;
            }
            /*Now HCF se divide when both positive so dono ka
                mod lele aur hcf find then usse divide*/
            int positive_numerator=(this->numerator<0)?(-1)*(this->numerator):this->numerator; //tertiary expression
            int positive_denominator=(this->denominator<0)?(-1)*(this->denominator):this->denominator;
            int hcf=HCF(positive_numerator,positive_denominator);
            this->numerator/=hcf;
            this->denominator/=hcf;
        }
        //Function for printing fraction
        void print(){
            this->simplyfy();//print karne se pehle simplyfy kar lenge
            if(this->numerator>0 && this->denominator>0){
                cout<<this->numerator<<"/"<<this->denominator<<endl;
            }
            /*ie. -7/9 or 7/-9 dono ko -7/9 print karenge*/
            else{
                int positive_numerator=(this->numerator<0)?(-1)*(this->numerator):this->numerator; //tertiary expression
                int positive_denominator=(this->denominator<0)?(-1)*(this->denominator):this->denominator;
                cout<<"-"<<positive_numerator<<"/"<<positive_denominator<<endl;
            }
        }
        void add(const Fraction &f2){
            /*this has address of f1 so no need to pass 2 
                fractions as parameter
                Also, const taaki iss function ke local variable 
                ko joh reference variable banaya taaki copy
                constructor call karke copy na karna padhe usse
                can't change original object f2*/
            /*Here we are doing f1=f1+f2*/
            /*a/b + c/d= (a*d+b*c)/(b*d)*/
            this->numerator=(this->numerator)*(f2.denominator)+(this->denominator)*(f2.numerator);
            this->denominator=this->denominator*f2.denominator;
            //at last simplyfy also
            this->simplyfy();
        }
        /*Operator overloading mei :
            a+b kiya in main aur overloaded + operator then 
            this->points on a ie pre operand
            aur parameter mei b pass karna aisa....*/
        Fraction operator+(const Fraction &f2){
            /*So, f3=f1+f2 in main=>this is address of f1 aur 
                f2 is parameter.*/
            Fraction f3;
            f3.numerator=(this->numerator)*(f2.denominator)+(this->denominator)*(f2.numerator);
            f3.denominator=this->denominator*f2.denominator;
            //at last simplyfy also
            f3.simplyfy();
            return f3;
        }
        //checks if fractions are equal or not
        bool operator==(Fraction &f2){
            /*f1==f2 matlab denominator aur numerator dono same
                hona chahiye.*/
            /*Pehle simplfy karna jaruri as 3/7==6/14*/
            /*this->simplyfy();
            //f2.simplyfy(); can't do as constant object so normal function can't call
            //so made f2 as reference object hi not const reference
            f2.simplyfy();
            if(this->numerator==f2.numerator && this->denominator==f2.denominator){
                return true;
            }
            else{
                return false;
            }*/
            /*above poore process se better ki a/b==c/d when (a*d)/(b*c)=1*/
            if(this->numerator*f2.denominator==this->denominator*f2.numerator){
                return true;
            }
            else{
                return false;
            }
        }
        //product operator yeh 
        Fraction operator*(const Fraction &f2){
            Fraction f3;
            f3.numerator=this->numerator*f2.numerator;
            f3.denominator=this->denominator*f2.denominator;
            f3.simplyfy();
            return f3;
        }
        //++f1 ie. pre increment operator yeh
        Fraction& operator++(){
            /*return type Fraction& as want ki joh content return 
                woh copy create na kare in buffer of whole 
                content but wahi memory block return ho jaaye
                this walli.*/
            this->numerator+=this->denominator;
            this->simplyfy();
            /*Joh bhi update in current object uska content hi 
                return.*/
            return *this;
        }
        //f1++ ie. post increment operator yeh
        Fraction operator++(int){
            /*want ki return purana fraction aur 
                incremented fraction this walla bann jaye*/
            /*Here (f++)++ not valid so nesting no tension*/
            Fraction f(this->numerator,this->denominator);
            this->numerator+=this->denominator;
            this->simplyfy();
            f.simplyfy();
            return f;
        }
        //Overloading += operator
        Fraction& operator+=(const Fraction &f2){
            /*Did f1=f1+f2*/
            this->numerator=(this->numerator*f2.denominator)+(this->denominator*f2.numerator);
            this->denominator*=f2.denominator;
            this->simplyfy();
            return *this;
        } 
};
int main(){
    int t;
    cout<<"Enter number of test cases : ";
    cin>>t;
    for(int i=0;i<t;i++){
        int f1_numerator,f1_denominator,f2_numerator,f2_denominator;
        cout<<"Enter the numerator and denominator of 1st Fraction : ";
        cin>>f1_numerator>>f1_denominator;
        Fraction f1(f1_numerator,f1_denominator);
        cout<<"Enter the numerator and denominator of 2nd Fraction : ";
        cin>>f2_numerator>>f2_denominator;
        Fraction f2(f2_numerator,f2_denominator);
        cout<<"First Fraction : ";
        f1.print();
        cout<<"Second Fraction : ";
        f2.print();
        Fraction f3=f1+f2;
        cout<<"New Fraction after adding : ";
        f3.print();
        Fraction f4=f1*f2;
        cout<<"New Fraction after multiplying : ";
        f4.print();
        if(f1==f2){
            cout<<"Both the fractions are equal."<<endl;
        }
        else{
            cout<<"Both the fractions are not equal."<<endl;
        }
        Fraction f5=++(++(++f1));
        cout<<"Did ++f1 3 times so f1 new is : ";
        f1.print();
        cout<<"Did f5=new f1 se new f5 is : ";
        f5.print();
        Fraction f6=(f1+=f2)+=f2;
        cout<<"f1 naya yeh banega : ";
        f1.print();
        cout<<"Aur naya fraction f6 is : ";
        f6.print();
    }
}