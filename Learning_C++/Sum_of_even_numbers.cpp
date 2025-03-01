// this is the programe for the sum of even numbers 

#include <iostream>
using namespace std;
 
int main()
{
    int n;
    int sum = 0; //initilizing the sum to zero 
    cout << "enter the last number" << endl;
    cin >> n ;
    
//starting the counter

    for (int i = 0; i <=  n; i = i+2)
        sum = sum + i;
    cout<< "the sum of even numbers is :" <<sum<< endl;
}