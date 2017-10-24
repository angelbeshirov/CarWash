#include "lqueue.h"
#include "Car.h"

#ifndef CARWASH_H
#define CARWASH_H

class CarWash
{
    public:
        CarWash(double _Height = 10, double _Width = 10);
        bool canBeAdded(Car*) const;
        void add(Car*);
        void wash();

        int size() const;


    private:
        double Height;
        double Width;
        lqueue<Car*> cars;
};
#endif
