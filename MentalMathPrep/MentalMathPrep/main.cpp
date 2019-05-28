//
//  main.cpp
//  MentalMathPrep
//
//  Created by Sarvesh Bhatnagar on 28/05/19.
//  Copyright © 2019 introtoalgo.com. All rights reserved.
//

#include <iostream>
#include <random>
#define cout std::cout
#define endl std::endl
#define cin std::cin

class UI{
    int choice;
    
    void set(int select);//We will pass the choice to set.
    void display();//will display the UI options
    void checkError(int n);//Responsible to check if proper value is selected.
public:
    UI() : choice(0){}
    void run();
}UIObj;

class NumberGenerator{
    std::random_device rd;
    int num1;
    int num2;
    float fnum1;
    float fnum2;
public:
    NumberGenerator(){} //If required in future , just in case declaration.
    void getInt(int a=10); // Get 2 integer between 0 to a if a is provided else 0-10
    void getFloat(int a=1); // Get a float between 0 to a if a is provided else 0-1
    
}NGObj;

void UI::run(){
    display();
//    cout<<NGObj.getInt()<<endl;
}

void UI::display(){
    cout<<"Please Select one of the following skills you want to hone :"<<endl
    <<"1. Addition"<<endl
    <<"2. Subtraction"<<endl
    <<"3. Multiplication"<<endl
    <<"4. Exit"<<endl;
    int n(-1);
    cin>>n;
    checkError(n);
}


void UI::checkError(int n){
    switch (n) {
        case 1:
            set(1);
            break;
        case 2:
            set(2);
            break;
        case 3:
            set(3);
            break;
        case 4:
            exit(0);
        default:
            cout<<"Invalid selection , please select again."<<endl;
            display();
            break;
    }
}

void UI::set(int select){
    choice=select;
}

void NumberGenerator::getInt(int a){
    num1 = rd()%a;
    num2 = rd()%a;
}

void NumberGenerator::getFloat(int a){
    fnum1 = rd()%a;
    fnum2 = rd()%a;
}


int main() {
    
    UIObj.run();
    
    return 0;
}
