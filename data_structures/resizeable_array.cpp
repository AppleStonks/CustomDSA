#include <iostream>

class CustomArray {
public:
    int* array;
    int numberOfElements;
    int capacity;

    CustomArray(){
        array = new int[2];
        capacity = 2;
        numberOfElements = 0;
    }

    ~CustomArray(){
        delete[] array;
    }

    int returnCapacity(){
        return capacity;
    }

    int size(){
        return numberOfElements;
    }

    int operator[](int index) const{
        if (index > numberOfElements -1){
            std::cout << "Index out of range";
            throw std::out_of_range("Index out of range");;
        }
        return array[index];
    }

    void push_back(int v){
        if(numberOfElements == capacity){
            int* new_array = new int[2*capacity];

            for(int i = 0; i < capacity; i++){
                new_array[i] = array[i];
            }
            
            delete[] array;
            array = new_array;
            capacity = 2*capacity;

        }

        array[numberOfElements] = v;
        numberOfElements++;

    }

    int pop_back(){
        if (numberOfElements == 0) throw std::out_of_range("pop_back on empty array");
        int element = *(array + numberOfElements-1);
        numberOfElements--;
        return element;
    }

};

int main(){

    CustomArray a;
    a.push_back(10);
    a.push_back(11);
    a.push_back(12);

    std::cout << a[0] << a[1] << a[2] << std::endl;

    int x = a.pop_back();
    std::cout << x;

    return 0;
}