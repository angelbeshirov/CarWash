#include<iostream>
#include"lstack.h"
using namespace std;
int main()
{
    lstack<int> c;
    c.push(1);
    c.push(2);
    c.push(3);
    c.push(4);
    c.push(5);
    cout<<c;
}
