#include<iostream>
#include<string>
using namespace std;

void rev_num(int N)
{
    //N%10 -> Last digit
    //N/10 -> N w/o last digit
    int rev=N%10; 
    N/=10;
    while(N)
    {
        rev = rev*10 + N%10;
        N/=10;
    }
    cout<<rev;
}

int main()
{
    int N=12345;
    char s[] = "124.65";
    int n = atoi(s); float f = atof(s);
    string s2 = to_string(N);  cout<<s2;
    
    return 0;
}