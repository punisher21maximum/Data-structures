#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class Test
{
    int a;
    char name[20];
    public:
    void get(int a, char name[])
    {
        cin>>a; cin>>name;
    }
    void show()
    {
        cout<<"ID name  :  "<<a<<name;
    }
};

int main()
{
    Test t; t.get(1, "ram"); t.show();
    fstream File; 
    File.open("stu.dat");
    File.write((char*)&t, sizeof(t));
    File.close();
    File.open("stu.dat");
    Test t1;
    File.read((char*)&t1, sizeof(t1));
    t1.show();

    return  0;
}