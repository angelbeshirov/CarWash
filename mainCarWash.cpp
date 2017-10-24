#include"CarWash.h"
using namespace std;
int main()
{
    CarWash m(15,15);
    Car a("666af",10,10,6);
    Car b("first",10,16,3);
    Car c("second",4,10,7);
    Car d("third",4,5,4);
    Car e("fourth",12,10,6);
    Car f("fifth",10,10,2);
    Car g("sixth",6,10,7);
    Car h("seventh",15,15,6);
    Car i("eighth",3,-3,6);
    Car j("ninth",14,-10,6);
    m.add(&a);
    m.add(&b);
    m.add(&c);
    m.add(&d);
    m.add(&e);
    m.add(&f);
    m.add(&g);
    m.add(&h);
    m.add(&i);
    m.add(&j);
    while(m.size() > 0){
        m.wash();
    }
}
