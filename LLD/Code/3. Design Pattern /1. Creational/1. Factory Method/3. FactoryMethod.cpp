#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;



class Notification {
public:
    virtual void send(const string& message) = 0;
    virtual ~Notification() {}
};

class EmailNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending email: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

class PushNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending push notification: " << message << endl;
    }
};



class NotificationCreator {
public:

    virtual Notification* createNotification() = 0;

    void send(const string& message) {
        Notification* notification = createNotification();
        notification->send(message);
        delete notification;
    }

    virtual ~NotificationCreator() {}
};


class EmailNotificationCreator : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new EmailNotification();
    }
};

class SMSNotificationCreator : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new SMSNotification();
    }
};

class PushNotificationCreator : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new PushNotification();
    }
};


// Now if we have to add 
// Slack Notification 
// then we can directly simply create a notification subclass.'

// Also while calling , we have to just 
// simply create subclass of creator ,  
// do not need to change in Factory code like 
// changing if else condition.

class SlackNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending SLACK: " << message << endl;
    }
};

class SlackNotificationCreator : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new SlackNotification();
    }
};


int main() {

    NotificationCreator* creator;

    // Send Email
    creator = new EmailNotificationCreator();
    creator->send("Welcome to our platform!");
    delete creator;

    // Send SMS
    creator = new SMSNotificationCreator();
    creator->send("Your OTP is 123456");
    delete creator;

    // Send Push Notification
    creator = new PushNotificationCreator();
    creator->send("You have a new follower!");
    delete creator;

    creator = new SlackNotificationCreator();
    creator->send("Standup in 10 minutes!");
    delete creator;

}

// Base* p = new Derived();
// delete p;
// This destroys the object.
// The memory allocated by new is returned to the heap
// p is just a variable (usually on stack)
// delete has no effect on it