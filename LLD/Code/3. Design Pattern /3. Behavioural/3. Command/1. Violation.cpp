#include <iostream>
#include <string>

using namespace std;

class Light {
public:
    void on() {
        cout << "Light turned ON" << endl;
    }

    void off() {
        cout << "Light turned OFF" << endl;
    }
};

class Thermostat {
public:
    void setTemperature(int temp) {
        cout << "Thermostat set to " << temp << "°C" << endl;
    }
};

class SmartHomeControllerV1 {
private:

    Light* light;
    Thermostat* thermostat;

public:
    SmartHomeControllerV1(Light* light, Thermostat* thermostat) 
        : light(light), thermostat(thermostat) {}

    void turnOnLight() {
        light->on();
    }

    void turnOffLight() {
        light->off();
    }

    void setThermostatTemperature(int temperature) {
        thermostat->setTemperature(temperature);
    }
};

// Note that the
// SmartHome controller is tighly coupled to very device object
// like light , thermostat.
// Now if you have to add let say fan , you need to change
// whole class of SmartHomeControllerV1 i.e
// breaking OCP principle.

// Also you there is no check like the last function you 
// have performed and how u store this ? , all object belongs to diff class.
// in short how would you do UNDO ?.

// You can't go scheduling or queue.
// You can’t queue up what to do, 
// because actions are hardcoded into method calls 
// not represented as standalone objects.


int main() {

    Light* light = new Light();
    Thermostat* thermostat = new Thermostat();
    SmartHomeControllerV1* controller = new SmartHomeControllerV1(light, thermostat);

    controller->turnOnLight();
    controller->setThermostatTemperature(22);
    controller->turnOffLight();

    delete light;
    delete thermostat;
    delete controller;

    return 0;
}
