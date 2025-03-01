// this is the programe for the sum of odd numbers 

#include <iostream>
using namespace std;
 
int main()
{
    int n;
    int sum = 0; //initilizing the sum to zero 
    cout << "enter the last number" << endl;
    cin >> n ;

    for (int i = 1; i <=  n; i = i+2)
        sum = sum + i;
    cout<< "the sum of odd numbers is :" <<sum<< endl;
}