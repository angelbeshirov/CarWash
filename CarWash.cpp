#include<string.h>
#include "CarWash.h"
CarWash::CarWash(double _Height, double _Width) {
    Height = _Height;
    Width = _Width;
};

bool CarWash::canBeAdded(Car* _car) const {
    const char* ID = _car->getID();
    if(strlen(ID) >= 3 && ID[0] == '6' && ID[1] == '6' && ID[2] == '6') {
        return false;
    }
    if(this->Height < _car->getHeight() || this->Width < _car->getWidth()) {
        return false;
    }
    if(_car->getDirtLevel() < 5) {
        return false;
    }

    return true;
};

int CarWash::size() const {
    return cars.size();
};

void CarWash::add(Car* _car) {
    if(canBeAdded(_car)) {
        cars.push(_car);
    }
};

void CarWash::wash() {
    if(!cars.isEmpty()) {
        cars.front()->setDirtLevel(1);
        std::cout<<"Car with ID:"<<cars.front()->getID() << " is being washed\n";
        cars.pop();
    }
};
