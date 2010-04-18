#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fisherYatesShuffle(int str[])
{
    for(int n=6; n>0; n--)
    {
        int y=rand() % (n+1); //Picks a random number between 0 and n
        swap(str[y], str[n]); //swaps the randomly picks character with n
    }
}


int main()
{
    srand(time(0));//seed rand() to the amount of seconds since midnight
    int str[] = {1,2,3,4,5,6,7};
    fisherYatesShuffle(str);
    for(int n=0;n<7;n++)//print the string
    {
        cout << str[n];
    }
    return 0;
}
