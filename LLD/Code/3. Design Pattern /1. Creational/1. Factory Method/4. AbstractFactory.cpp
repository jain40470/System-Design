#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


// Product A
class Notification {
public:
    virtual ~Notification() = default;
    virtual void send(string msg) = 0;
};
// Product B 
class MessageFormatter {
public:
    virtual ~MessageFormatter() = default;
    virtual string format(string msg) = 0;
};


// Concrete Products (Email family)
class EmailNotification : public Notification {
public:
    void send(string msg) override {
        cout << "Email: " << msg << endl;
    }
};
class EmailFormatter : public MessageFormatter {
public:
    string format(string msg) override {
        return "[EMAIL FORMAT] " + msg;
    }
};


// Concrete Products (SMS family)
class SMSNotification : public Notification {
public:
    void send(string msg) override {
        cout << "SMS: " << msg << endl;
    }
};
class SMSFormatter : public MessageFormatter {
public:
    string format(string msg) override {
        return "[SMS FORMAT] " + msg;
    }
};



class Factory {
public:
    virtual ~Factory() = default;
    virtual Notification* createNotification() = 0;
    virtual MessageFormatter* createFormatter() = 0;
};


class EmailFactory : public Factory {
public:
    Notification* createNotification() override {
        return new EmailNotification();
    }

    MessageFormatter* createFormatter() override {
        return new EmailFormatter();
    }
};

class SMSFactory : public Factory {
public:
    Notification* createNotification() override {
        return new SMSNotification();
    }

    MessageFormatter* createFormatter() override {
        return new SMSFormatter();
    }
};


class Service{

public :

    Factory* factory;

    void setService(Factory* factory){
        this->factory = factory;
    }

};


// Now lets say there is one more thing 
// XYZ , you need to just craeet n[ist notificaion and formatter
// and factory subclass for it .
// so there is extension not modification in written code.


int main(){

    Service* service =  new Service();
    service->setService(new EmailFactory());

    Notification* notification = service->factory->createNotification();
    MessageFormatter* formatter = service->factory->createFormatter();
    notification->send(formatter->format("Welcome!"));

    delete notification;
    delete formatter;

    service->setService(new SMSFactory());

    notification = service->factory->createNotification();
    formatter = service->factory->createFormatter();
    notification->send(formatter->format("Welcome!"));


}

// Abstract Factory uses composition because the client holds a 
// reference to a factory object and delegates the creation of 
// related objects to it, instead of inheriting from a creator class.