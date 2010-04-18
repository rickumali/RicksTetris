#include <iostream>//for cout, cin and swap()
#include <string>//for string and length()
#include <cstdlib>//for srand() and rand()
#include <ctime>//for time()
using namespace std;

void fisherYatesShuffle(string &str)//return by reference
{
    for(int n=str.length()-1; n>1; n--)//str.length is the number of characters in your string - 1 because length does not check for the null terminator
    {
        int y=rand() % (n+1);//Picks a random number between 0 and n
        swap(str[y], str[n]);//swaps the randomly picks character with n
    }
}


int main()//implementation
{
    srand(time(0));//seed rand() to the amount of seconds since midnight
    // string str = ("Fixed.");
    string str = ("1234567");
    fisherYatesShuffle(str);
    for(int n=0;n<str.length();n++)//print the string
    {
        cout << str[n];
    }
    return 0;
}
