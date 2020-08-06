#include<iostream>
#include<string.h>
using namespace std;

void dec2bin(int D)
{
    int bin=1;
    while(D)
    {
        cout<<D%2;
        
        D/=2;
    }

}

//count number of set bits in Input
void func2()
{
    string bin; int i=0, c=0;
    cin>>bin;
    while(bin[i]!='\0')
    {
        if(bin[i]=='0') c++;
    }
    cout<<c;
}

int main()
{
    string s1="do you have a car", s2="no i dont have a star";
    string s3 = s1+s2;
    char s4[]="gamer";  
    cout<<strlen(s4);
    
    cout<<strstr(s4, "m")<<strchr(s4, 'm');

    return 0;
}