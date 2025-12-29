#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


class EmailNotification {
public:
    void send() {
        cout << "Sending an Email notification..." << endl;
    }
};

class NotificationCreator {
public:
    void sendNotification(const string& type, const string& message) {
        if (type == "EMAIL") {
            EmailNotification email;
            email.send(message);
        } else if (type == "SMS") {
            SMSNotification sms;
            sms.send(message);
        }
    }
};


// Now if you have to add new , notification type 
// you have to modify the creator class .
// To solve this problem .

// Simple factory method 
// You create a separate class (a “factory”) 
// whose only job is to centralize and encapsulate object creation.

// The notification service no longer needs to know which concrete 
// class to instantiate. 
// It simply asks the factory for the right type of notification.

int main() {


  
}

