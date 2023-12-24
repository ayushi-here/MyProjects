#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    int num=(rand()%50)+1;
    int guess=0;
    do
    {
        cout<<"Guess a number(1-50): ";
        cin>>guess;
        if(guess>num)
        cout<<"Guess lower!"<<endl;
        else if(guess<num)
        cout<<"Guess higher!"<<endl;
        else
        cout<<"You Won!"<<endl;

    }while(guess!=num);
    return 0;  
}