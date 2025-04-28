#include <iostream>
#include <cstdlib>
#include <string>


class Student{
    private:
        std::string name;
        int numClasses;
        std::string *classList;
        void res();
    public:
        Student();
        ~Student();
        void InputData();
        void OutputData();
        void ResetClasses();
        Student& operator=(const Student& rightSide);
};

Student::Student(){
    numClasses=0;
    classList = NULL;
    name = "";
}

Student::~Student(){
    if(classList != NULL)
        delete [] classList;
}

void Student::res(){
    if (classList == nullptr){
        delete[] classList;
        classList = nullptr;
    }
}

void Student::ResetClasses()
{
    if(classList != NULL){
            delete [] classList;
            classList = NULL;
    }
    numClasses = 0;
}


void Student::InputData(){
    ResetClasses();
    std::cout<<"Enter student name."<< std::endl;
    std::getline(std::cin,name);
    std::cout<<"Enter number of classes."<< std::endl;
    std::cin>>numClasses;
    std::cin.ignore(2,'\n');

    if(numClasses>0){
        classList = new std::string[numClasses];
        for(int i = 0;i<numClasses;i++){
            std::cout << "Enter name of class" << (i+1) << std::endl;
            std::getline(std::cin,classList[i]);
        }
    }
    std::cout<<std::endl;
}

void Student::OutputData(){
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Number of classes: "<<numClasses<<std::endl;

    for(int i=0;i<numClasses;i++)
        std::cout<<"  Class "<<(i+1)<<":"<<classList[i]<<std::endl;
    std::cout<<std::endl;
}

Student& Student::operator=(const Student& rightSide){
    if(this->classList==rightSide.classList)
        return *this;
    ResetClasses();
    name=rightSide.name;
    numClasses=rightSide.numClasses;

    if(numClasses>0){
        classList=new std::string[numClasses];
        for(int i=0;i<numClasses;i++)
            classList[i] = rightSide.classList[i];
    }
    return *this;
}

int main()
{
    Student s1,s2;
    s1.InputData();
    std::cout<<"Student 1's data:"<<std::endl;
    s1.OutputData();

    std::cout<<std::endl;

    s2=s1;
    std::cout<<"Student 2's data after assignment from student 1:"<<std::endl;
    s2.OutputData();

    s1.ResetClasses();
    std::cout<<"Student 1's data after reset:"<<std::endl;
    s1.OutputData();

    std::cout<<"Student 2's data,should still same:"<<std::endl;
    s2.OutputData();

    std::cout<<std::endl;
    return 0;
}