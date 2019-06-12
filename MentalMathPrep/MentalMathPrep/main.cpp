//
//  main.cpp
//  MentalMathPrep
//
//  Created by Sarvesh Bhatnagar on 28/05/19.
//  Copyright © 2019 introtoalgo.com. All rights reserved.
//

#include <iostream>
#include <random>
#include <ctime>
#define cout std::cout
#define endl std::endl
#define cin std::cin



//A class for handling UI.
class UI{
    int choice;
    int option;//1 integer , 2 float
    int range;
    
    void setOption(int select); // used to set option 1 for int and 2 for float.
    void set(int select);//We will pass the choice to set.
    void display();//will display the UI options
    void checkError(int n);//Responsible to check if proper value is selected.
    void chooseOption();//sets option value.
    void chooseRange();//Gets range for number generator obj.
public:
    int getCurrentRange(){return range;}//Returns range.
    int getCurrentChoice(){return choice;} // used to get choice i.e. 1, 2 , 3 or exit.
    int getCurrentOption(){return option;} // used to get option i.e. 1 for int and 2 for float.
    UI() : choice(0) , range(10){}
    void run(); //used to run
}UIObj;




//A class to generate random numbers in a given range.
class NumberGenerator{
    std::random_device rd;
    
    int num1;
    int num2;
    float fnum1;
    float fnum2;
public:
    NumberGenerator(){} //If required in future , just in case declaration.
    void setInt(int a=10); // set 2 integer between 0 to a if a is provided else 0-10
    void setFloat(int a=1); // set a float between 0 to a if a is provided else 0-1
    int getNum(int n); // Returns num1, num2 for n = 1 , 2 respectively.
    float getNumf(int n); // Returns fnum1 , fnum2 for n =  1, 2 respectively.
}NGObj;



//Functions such as addition , subtraction and multiplication are defined in this class.
class Functions{
    int ans;
    float ansf;
    void addition(); // if addition operation is defined call this
    void subtraction(); // if subtraction operation is defined call this
    void multiplication(); // if multiplication operation is defined call this.
    std::random_device rd;
    int a;
public:
    Functions() : a(0){}
    void run(); // Uses UIObj.choice , to perform suitable operation. (add multiply or divide).
    int getAns(); // Used to get integer answer.
    float getAnsf(); // Used to get floating point answer.
}FUNObj;


// used to get users input and verify the input.
class MentalMath{
    int t1;
    float t2;
public:
    void takeInput();//Take input from the use , i.e Answer.
    bool verifyInput(); //Returns true if user response matches with the answer , otherwise returns false.
    
}MMObj;

class Time{
    int timesCalled;
    time_t start,stop;
    bool timeflag;
    long int timeSum;
    
    //auxiliary
    void startTimer(){
        time(&start);
    }
    
    //auxiliary function for timer to set a stop point
    void stopTimer(){
        time(&stop);
    }
    
    double timerDifference(){
        return difftime(stop, start);
    }

public:
    Time(): start(NULL) , stop(NULL),timeflag(true),timesCalled(0),timeSum(0){}
    
    //Alternatively sets start and stop time when called.
    void timer(){
        if (timeflag) {
            startTimer();
            timeflag=false;
        }else{
            stopTimer();
            timeflag=true;
            timesCalled += 1;
            timeSum += timerDifference();
        }
    }
    
    float average(){
        return (float)timeSum/timesCalled;
    }
    
}TIMEObj;

//Method definations for UI

void UI::run(){
    display();
    chooseOption();
    chooseRange();
}

void UI::display(){
    cout<<"Please Select one of the following skills you want to hone :"<<endl
    <<"1. Addition"<<endl
    <<"2. Subtraction"<<endl
    <<"3. Multiplication"<<endl
    <<"4. Random"<<endl
    <<"9. Exit"<<endl;
    int n(-1);
    cin>>n;
    checkError(n);
}

void UI::chooseOption(){
    cout<<"What kind of numbers do you want to practice with"<<endl
    <<"1. Integers"<<endl
    <<"2. Floating Points"<<endl;
    int n(-1);
    cin>>n;
    if (n == 1) {
        n = 5;
    }else if (n == 2){n=6;}else{n = -1;}
    checkError(n);
}

void UI::chooseRange(){
    cout<<"Enter max number which you want to include"<<endl;
    cin>>range;
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
            set(4);
        case 5:
            setOption(1);
            break;
        case 6:
            setOption(2);
            break;
        case 9:
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

void UI::setOption(int select){
    option = select;
}


//Functions class definations


void Functions::addition(){
    switch (UIObj.getCurrentOption()) {
        case 1:
            //Integer
            cout<<NGObj.getNum(1)<<" + "<<NGObj.getNum(2)<<endl;
            ans = NGObj.getNum(1) + NGObj.getNum(2);
            break;
        case 2:
            //Float
            cout<<NGObj.getNumf(1)<<" + "<<NGObj.getNumf(2)<<endl;
            ansf = NGObj.getNumf(1) + NGObj.getNumf(2);
            break;
            
        default:
            cout<<"Invalid selection , please select again."<<endl;
            exit(2);
            break;
    }
}

void Functions::subtraction(){
    switch (UIObj.getCurrentOption()) {
        case 1:
            //Integer
            cout<<NGObj.getNum(1)<<" - "<<NGObj.getNum(2)<<endl;
            ans = NGObj.getNum(1) - NGObj.getNum(2);
            break;
        case 2:
            //Float
            cout<<NGObj.getNumf(1)<<" - "<<NGObj.getNumf(2)<<endl;
            ansf = NGObj.getNumf(1) - NGObj.getNumf(2);
            break;
            
        default:
            cout<<"Invalid selection , please select again."<<endl;
            exit(2);
            break;
    }
}


void Functions::multiplication(){
    switch (UIObj.getCurrentOption()) {
        case 1:
            //Integer
            cout<<NGObj.getNum(1)<<" * "<<NGObj.getNum(2)<<endl;
            ans = NGObj.getNum(1) * NGObj.getNum(2);
            break;
        case 2:
            //Float
            cout<<NGObj.getNumf(1)<<" * "<<NGObj.getNumf(2)<<endl;
            ansf = NGObj.getNumf(1) * NGObj.getNumf(2);
            break;
            
        default:
            cout<<"Invalid selection , please select again."<<endl;
            exit(2);
            break;
    }
}


void Functions::run(){
    switch (UIObj.getCurrentChoice()) {
        case 1:
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            a = rd()%3;
            switch (a) {
                case 0:
                    addition();
                    break;
                case 1:
                    subtraction();
                    break;
                case 2:
                    multiplication();
                    break;
                default:
                    cout<<"Functions : Invalid random number generated"<<endl;
                    break;
            }
            break;
            
        default:
            cout<<"Functions : Invalid Current Choice "<<endl;
            break;
    }
}


int Functions::getAns(){
    return ans;
}

float Functions::getAnsf(){
    return ansf;
}






//Method definations for NumberGenerator


void NumberGenerator::setInt(int a){
    num1 = rd()%a;
    num2 = rd()%a;
    if (num1 == 0) {
        num1=1;
    }else if (num2 == 0){num2=1;}
}

void NumberGenerator::setFloat(int a){
    fnum1 = rd()% (a*100);
    fnum2 = rd()% (a*100);
    fnum1 = fnum1/100;
    fnum2 = fnum2/100;
}

int NumberGenerator::getNum(int n){
    if (n == 1) {
        return num1;
    }else if(n == 2){
        return num2;
    }
    return -1;
}


float NumberGenerator::getNumf(int n){
    switch (n) {
        case 1:
            return fnum1;
            break;
        case 2:
            return fnum2;
            break;
        default:
            cout<<"NumberGenerator : Error in Selection"<<endl;
            exit(2);
            break;
    }
}



//Method Definations for MentalMath


void MentalMath::takeInput(){
    if (UIObj.getCurrentOption()==1) {
        cin>>t1;
    }else if (UIObj.getCurrentOption() == 2){
        cin>>t2;
    }else{
        cout<<"Error Occured : Invalid Option"<<endl;
        exit(2);
    }
}

bool MentalMath::verifyInput(){
    if (UIObj.getCurrentOption()==1) {
        //Integer/
        //Verify
        if (t1 == FUNObj.getAns()) {
            return true;
        }else{
            return false;
        }
    }else{
        if (t2 == FUNObj.getAnsf()) {
            return true;
        }else{
            return false;
        }
    }
    return true;
}


void completeRun(int n){
    int score = 0;
    UIObj.run(); // chose options and choice.
    for (int i =0; i<n; i++) {
        NGObj.setInt(UIObj.getCurrentRange());
        NGObj.setFloat(UIObj.getCurrentRange());
        FUNObj.run();
        TIMEObj.timer();
        MMObj.takeInput();
        if (MMObj.verifyInput()) {
            score += 1;
            cout<<"Correct"<<endl;
        }else{
            cout<<"WRONG"<<endl;
        }
        TIMEObj.timer();
    }
    cout<<"Time taken on average : "<<TIMEObj.average()<<" Seconds per question"<<endl;
    cout<<"Total Score : "<<score<<" / "<<n<<endl;
}


int main() {
    
    completeRun(100);
    
    return 0;
}
