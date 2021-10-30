#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int summation(int number)
{
    int total = 1;
    for (int i = 1; i < number; i++)
    {
        total += (i + 1);
    }
    return total;
}

int main()
{

    int number;
    cout << "Enter a whole number: ";
    cin >> number;
    cout << summation(number);
}
