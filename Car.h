#ifndef CAR_H
#define CAR_H


class Car
{
    public:
        //Big 4
        Car(const char* _id = "", double _Height = 0, double _Width = 0, int _DirtLevel = 1);
        Car(const Car&);
        Car& operator=(const Car&);
        ~Car();

        //setters
        void setID(const char*);
        void setHeight(double);
        void setWidth(double);
        void setDirtLevel(int);

        //getters
        const char* getID() const;
        double getHeight() const;
        double getWidth() const;
        int getDirtLevel() const;


    private:
        char* ID;
        double Height;
        double Width;
        int DirtLevel;
};

#endif // CAR_H

