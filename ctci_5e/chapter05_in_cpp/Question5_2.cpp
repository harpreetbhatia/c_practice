/*
by: Harpreet Bhatia
*/

#include<iostream>
#include<string>
using namespace std;

string decimalToBinary(double a){
    if(a<0 || a>= 1)
        return "ERROR!";
    string result="";
    result = result + "0.";
    while(a>0){
        if(result.length()>32){
            return "ERROR!";
        }
        a *=2;
        if(a>=1){
            result =result+"1";
            a -=1.0;
        }
        else{
            result = result+"0";
        }
    }
    return result;
}

int main(){

    double a = 0.125;
    cout<<decimalToBinary(a)<<'\n';
    a = 0.625;
    cout<<decimalToBinary(a)<<'\n';
    a = -0.2;
    cout<<decimalToBinary(a)<<'\n';
    a = 1.2;
    cout<<decimalToBinary(a)<<'\n';
    return 0;
}
