#include <iostream>
using namespace std;
class DynamicArray{
    private:
        int *Data; //pointer to the first element of our dynamic array
        int capacity; //at any time kitne elements array can store agar kam padhe then double the capacity
        int next_index; //so that can get trace of naya element insert toh kaunse index mei insert kare
    public:
        //Constructor
        DynamicArray(){
            this->capacity=5;//initialize 5 se kar
            this->next_index=0;
            this->Data=new int[capacity];
        }
        //Copy Constructor
        DynamicArray(const DynamicArray &A){
            /*copy contents of A in this new array ie. this mei 
                content of A copy*/
            /*So copied all content of A in this ie. new object*/
            this->Data=new int[A.next_index-1];
            for(int i=0;i<A.next_index-1;i++){
                (this->Data)[i]=(A.Data)[i];
            }
            this->next_index=A.next_index;
            this->capacity=A.capacity;
        }
        //Function to add a new element
        void add(int element){
            if(this->next_index==capacity){
                /*so increase capacity and then data ko naye made
                    array mei point karwa*/
                this->capacity*=2;
                /*Take a pointer to the previous data so that can copy
                    previous ke saare data.*/
                int *copy_previous=this->Data;
                this->Data=new int[this->capacity];
                for(int i=0;i<this->next_index-1;i++){
                    this->Data[i]=copy_previous[i];
                }
            }
            /*Now add element at the end.*/
            this->Data[this->next_index++]=element;
        }
        void operator=(const DynamicArray &A){
            //copied content of copy constructor as ussi jaisa
            this->Data=new int[A.next_index-1];
            for(int i=0;i<A.next_index-1;i++){
                (this->Data)[i]=(A.Data)[i];
            }
            this->next_index=A.next_index;
            this->capacity=A.capacity;
        }
};