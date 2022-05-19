/* Project: C++ program to find factorial of given number*
 *In mathematics, the factorial of a non-negative integer n,
 *is the product of all positive integers less than or equal to n
 *
 *Author: Wesley Yu-Wei Huang
 *School: Jianguo Senior High School
 *Date: 11/11/2021
 */
#include <iostream>
using namespace std;
 
// function to find factorial of given number
unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
// Driver code
/*
* main: the program main function
*/
int main()
{
    int num ;
    cin >> num;
    cout << "Factorial of "
         << num << " is " << factorial(num) << endl;
    return 0;
}



