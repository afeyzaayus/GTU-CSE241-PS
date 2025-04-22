#include <iostream>
#include <cmath>

class MyInteger {
    private:
        int num;

    public:
        MyInteger();
        MyInteger(int new_int);
        void setInt(int new_int);
        int getInt() const{
            return num;
        }
        int operator[](int index);
};

MyInteger::MyInteger() : num(0) {}

MyInteger::MyInteger(int new_int){
    num = new_int;
}

void MyInteger::setInt(int new_int){
    num = new_int;
}

int MyInteger::operator[](int index){
    int temp;
    if (index < 0) {
        std::cout << "Invalid index num" << std::endl;
        return -1;
    }
    else if (pow(10, index) > num){
        std::cout << "Index num exceeds." << std::endl;
        return -1;
    } 
    else {
        temp = (int) (num / pow(10, index));
        return temp % 10;
    }
}

int main()
{
    MyInteger num(418);

    std::cout << num[0] << " " << num[1] << " " << num[2] << std::endl;
    std::cout << num[3] << std::endl;
    std::cout << num[-1] << std::endl;
    return 0;
}
