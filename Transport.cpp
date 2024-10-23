#include <iostream>

using namespace std;

class Transport {
protected:
    float l;
    int people;
    int cargo;
    float speed;
public:
    Transport(float l_i, int people_i, int cargo_i, float speed_i)
        : l{ l_i }, people{ people_i }, cargo{ cargo_i }, speed{ speed_i } {}
    virtual void Count() = 0;
    virtual ~Transport() {}
};

class Car : public Transport {
public:
    Car(float l_i, int people_i, int cargo_i, float speed_i)
        : Transport(l_i, people_i, cargo_i, speed_i) {}
    void Count() override {
        float time = (l / speed) * 60;
        float cost = (l * 0.5) + people * 5 + cargo * 3;
        cout << "Car\nTime = " << time << " minutes\nCost = " << cost << "$\n";
    }
};

class Bicycle : public Transport {
public:
    Bicycle(float l_i, int people_i, int cargo_i, float speed_i)
        : Transport(l_i, people_i, cargo_i, speed_i) {}
    void Count() override {
        float time = (l / speed) * 60;
        float cost = people * 4 + cargo * 0.5;
        cout << "Bycicle\nTime = " << time << " minutes\nCost = " << cost << "$\n";
    }
};

class Cart : public Transport {
public:
    Cart(float l_i, int people_i, int cargo_i, float speed_i)
        : Transport(l_i, people_i, cargo_i, speed_i) {}
    void Count() override {
        float time = (l / speed) * 60;
        float cost = people * 3 + cargo * 2;
        cout << "Car\nTime = " << time << " minutes\nCost = " << cost << "$\n";
    }
};

int main()
{
    Transport* car = new Car(95, 3, 15, 65);
    Transport* bicycle = new Bicycle(40, 1, 2, 17);
    Transport* cart = new Cart(120, 5, 35, 40);

    car->Count();
    bicycle->Count();
    cart->Count();

    delete car;
    delete bicycle;
    delete cart;

}