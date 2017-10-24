#include<string.h>
#include "Car.h"

Car::Car(const char* _ID, double _Height, double _Width, int _DirtLevel) {
    ID = new char[strlen(_ID) + 1];
    strcpy(ID, _ID);

    setHeight(_Height);
    setWidth(_Width);
    setDirtLevel(_DirtLevel);
};

Car::Car(const Car& _car) {
    ID = new char[strlen(_car.getID()) + 1];
    strcpy(ID, _car.getID());

    Height = _car.getHeight();
    Width = _car.getWidth();
    DirtLevel = _car.getDirtLevel();
};

Car& Car::operator=(const Car& _car) {
    if(this != &_car) {
        delete[] ID;
        Height = _car.getHeight();
        Width = _car.getWidth();
        DirtLevel = _car.getDirtLevel();
    }
    return *this;
};

Car::~Car() {
    delete[] ID;
};

void Car::setID(const char* _ID) {
    ID = new char[strlen(_ID) + 1];
    strcpy(ID, _ID);
};

void Car::setHeight(double _Height) {
    if(_Height > 0) {
        Height = _Height;
    } else {
        Height = 1;
    }
};

void Car::setWidth(double _Width) {
    if(_Width > 0) {
        Width = _Width;
    } else {
        Width = 1;
    }
};

void Car::setDirtLevel(int _DirtLevel) {
    if(_DirtLevel >= 1 &&  _DirtLevel <= 10) {
        DirtLevel = _DirtLevel;
    } else {
        DirtLevel = 1;
    }
};

const char* Car::getID() const {
    return ID;
};

double Car::getHeight() const {
    return Height;
};

double Car::getWidth() const {
    return Width;
};

int Car::getDirtLevel() const {
    return DirtLevel;
};
