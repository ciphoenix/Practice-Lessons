#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool isPrimeNumber(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main()
{
    for (int i = 1; i < 10000; i++)
    {
        bool isPrime = isPrimeNumber(i);
        if (isPrime)
            cout << i << " is a prime number" << endl;
   }


    system("pause>0");

}
