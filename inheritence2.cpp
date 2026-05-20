// inheritence2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, g#include <iostream>
#include <vector>
using namespace std;

class Engine {
    string engine_no;
    string company;
    double volume;

public:
    Engine() {}

    Engine(string engine_no, string company, double volume) {
        this->engine_no = engine_no;
        this->company = company;
        this->volume = volume;
    }

    void show() {
        cout << "Engine No : " << engine_no << endl;
        cout << "Company   : " << company << endl;
        cout << "Volume    : " << volume << endl;
    }
};



class Vehicle {
protected:
    int id;
    string model;
    string vendor;
    Engine engine;

public:
    Vehicle() {}

    Vehicle(int id, string model,
        string vendor, Engine engine) {

        this->id = id;
        this->model = model;
        this->vendor = vendor;
        this->engine = engine;
    }

    virtual void show() {
        cout << "Id      : " << id << endl;
        cout << "Model   : " << model << endl;
        cout << "Vendor  : " << vendor << endl;

        engine.show();
    }
};



class Car : public Vehicle {
    bool hasSpoiler;

public:
    Car() {}

    Car(int id, string model,
        string vendor,
        Engine engine,
        bool hasSpoiler)

        : Vehicle(id, model, vendor, engine) {

        this->hasSpoiler = hasSpoiler;
    }

    void show() override {

        cout << "\n===== CAR =====" << endl;

        Vehicle::show();

        cout << "Has Spoiler : ";

        if (hasSpoiler)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
};



class Ship : public Vehicle {
    bool hasSail;

public:
    Ship() {}

    Ship(int id, string model,
        string vendor,
        Engine engine,
        bool hasSail)

        : Vehicle(id, model, vendor, engine) {

        this->hasSail = hasSail;
    }

    void show() override {

        cout << "\n===== SHIP =====" << endl;

        Vehicle::show();

        cout << "Has Sail : ";

        if (hasSail)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
};



class Airplane : public Vehicle {
    int engineCount;
    int passengersCapacity;

public:
    Airplane() {}

    Airplane(int id, string model,
        string vendor,
        Engine engine,
        int engineCount,
        int passengersCapacity)

        : Vehicle(id, model, vendor, engine) {

        this->engineCount = engineCount;
        this->passengersCapacity = passengersCapacity;
    }

    void show() override {

        cout << "\n===== AIRPLANE =====" << endl;

        Vehicle::show();

        cout << "Engine Count : "
            << engineCount << endl;

        cout << "Passengers Capacity : "
            << passengersCapacity << endl;
    }
};



class VehicleDepo {
public:
    vector<Car> cars;
    vector<Ship> ships;
    vector<Airplane> airplanes;

    void showAllVehicle() {

        for (Car c : cars) {
            c.show();
        }

        for (Ship s : ships) {
            s.show();
        }

        for (Airplane a : airplanes) {
            a.show();
        }
    }
};



int main() {

    Engine e1("ENG100", "BMW", 3.0);
    Engine e2("ENG200", "Yamaha", 5.5);
    Engine e3("ENG300", "Boeing", 12.8);


    Car c1(1, "M5", "BMW", e1, true);

    Ship s1(2, "Titanic", "Oceanic", e2, true);

    Airplane a1(3, "747", "Boeing",
        e3, 4, 660);


    VehicleDepo depo;

    depo.cars.push_back(c1);
    depo.ships.push_back(s1);
    depo.airplanes.push_back(a1);


    depo.showAllVehicle();


    return 0;
}o to File > Open > Project and select the .sln file
