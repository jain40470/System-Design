#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

// Simple factory method 
// You create a separate class (a “factory”) 
// whose only job is to centralize and encapsulate object creation.

// The notification creator no longer needs to know which concrete 
// class to instantiate. 
// It simply asks the factory for the right type of notification.


class Notification {
public:
    virtual void send() = 0;
    virtual ~Notification() {}
};

class EmailNotification : Notification {
public:
    void send() {
        cout << "Sending an Email notification..." << endl;
    }
};
class SMSNotification : Notification  {
public:
    void send() {
        cout << "Sending an SMS notification..." << endl;
    }
};
class PUSPNotification : Notification {
public:
    void send() {
        cout << "Sending an PUSH notification..." << endl;
    }
};


class SimpleNotificationFactory {
public:
    static Notification* createNotification(const string& type) {
        if (type == "EMAIL") {
            return new EmailNotification();
        } else if (type == "SMS") {
            return new SMSNotification();
        } else if (type == "PUSH") {
            return new PushNotification();
        } else {
            throw invalid_argument("Unknown type");
        }
    }
};

class NotificationCreator {
public:
    void sendNotification(const string& type, const string& message) {
        Notification* notification = nullptr;
        notification = SimpleNotificationFactory::createNotification(type);
        notification->send(message);
        delete notification;
    }
};


// But what if here one more type 
// Slack is added , in that case you need 
// You simply inhert the Notification class and
// create it.

class SlackNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending SLACK: " << message << endl;
    }
};

// But when we have to intiate
// We have to modify the SimpleNotificationFactory class 
// and modify if else there
// which breaks OCP


int main() {


  
}

