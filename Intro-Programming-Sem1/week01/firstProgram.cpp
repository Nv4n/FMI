#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "I <3 FMI" << endl;
    int favNum;
    cin>>favNum;
    cout<<"Your favourite number is "<<favNum<<endl;
    int input1,input2;
    cin>>input1>>input2;
    cout<<"Sum: "<<input1+input2<<endl;
    cout<<"Difference: "<<input1-input2<<endl;
    cout<<"Product: "<<input1*input2<<endl;
    double width,height;
    cin>>width>>height;
    cout<<ceil(4*width*height/3)<<endl;

}