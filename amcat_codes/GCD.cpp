#include <iostream>
#include<algorithm>
#include <cstring>
#include <string.h>
#include <math.h>
using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

void isPrime(int N)
{
    for(int i=2; i<=(N/2); i++)
    {
        if(N%i == 0)
        {
            cout<<"NON PRIME : "<<N<<endl; return;
            // return -1;
        }
    }
    cout<<"PRIME : "<<N<<endl;
    // return 1;
}

void isLeapYear(int year)
{
    if(year%4 != 0) cout<<"Not Leap Year : "<<year<<endl;
    else if(year%4 == 0)
    {
        if(year%100 != 0) cout<<"Leap Year : "<<year<<endl;
        else if(year%100 == 0)
        {
            if(year%400 != 0) cout<<"Not Leap Year : "<<year<<endl;
            else if(year%400 == 0) cout<<"Leap Year : "<<year<<endl;      
        }     
    }  
}

void isPallindromeNumber()
{
    int N, reverse = 0, last, number;
    cout<<"Enter number to check pallindrome : "; cin>>N; cout<<endl;
    number = N;
    //reverse the number
    while(N)
    {
        last = N%10;
        reverse = reverse*10 + last;
        N/=10;
    }
    cout<<"Reverse : "<<reverse<<endl;
    if(reverse == number) cout<<"pallindrome"<<endl;
    else cout<<"not pallindrome"<<endl;
}
void isPallindromeString()
{
    char str1[20]; int lenn;
    cout<<"Enter string to check pallindrome : "; cin>>str1; cout<<endl;
    lenn = strlen(str1); // str1.length();
    //
    for(int i=0; i<(lenn/2); i++)
    {
        if( str1[i] != str1[lenn-1-i] )
        {
            cout<<"not pallindrome"<<endl; return;
        }
    }
    cout<<"pallindrome"<<endl;
}
void fibonacci()
{
    int a=0, b=1, c;
    cout<<a<<" ";
    for(int i=0; i<10; i++)
    {
        // c=b, b=a+b; a=c;  cout<<a<<" ";
        b=a+b; a=b-a;  cout<<a<<" ";
    }
}
void binary2dec()
{
    int bn, dn=0, last, i=0;
    cout<<"Enter binary : "; cin>>bn; cout<<endl;

    while(bn)
    {
        last = bn%10;
        dn += last*pow(2,i);
        i++;
        bn/=10;
    }

    cout<<"Decimal : "<<dn;
}
void dec2bin()
{
    int bn[32], dn=0, last, i=0;
    cout<<"Enter dec : "; cin>>dn; cout<<endl;

    while(dn)
    {
        if(dn%2==0) bn[i++] = 0;
        else bn[i++] = 1;
        dn/=2;
    }

    cout<<"Binary : ";

    for (int j = i - 1; j >= 0; j--) 
        cout << bn[j];
}
void removeVowel()
{
    char str1[20], str2[20], flag=0, i2=0;
    cout<<"Enter string : "; cin>>str1; cout<<endl;

    char vow[] = {'a', 'e', 'i', 'o', 'u'};

    for(int i=0; i<strlen(str1); i++)
    {
        flag=0;
        for(int j=0; j<5; j++)
        {
            if(str1[i]==vow[j])
            {
                flag=1; break;
            }
        }
        if(flag==0) str2[i2++] = str1[i];
    }

    for(int j=0; j<i2; j++)
    {
        cout<<str2[j];
    }

}

int main()
{
    int x=98, y=56;
    // cout<<"GCD : "<<__gcd(x,y)<<endl;
    // cout<<"gcd : "<<gcd(x,y)<<endl;

    // cout<<"lcm : "<<lcm(15, 6)<<endl;
    
    // for(int i=1; i<=20; i++) isPrime(i);


    removeVowel2();
    return 0;
}

