#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
 

// To communicate between high module and low module there is an intercae 

// Interface
class EmailClient {
public:
    virtual void sendEmail(const string& to, const string& subject, const string& body) = 0;
    virtual ~EmailClient() = default;
};

// Low level Module
class GmailClientImpl : public EmailClient {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        cout << "Connecting to Gmail SMTP server..." << endl;
        cout << "Sending email via Gmail to: " << to << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
        cout << "Gmail email sent successfully!" << endl;
    }
};

class OutlookClientImpl : public EmailClient {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        cout << "Connecting to Outlook Exchange server..." << endl;
        cout << "Sending email via Outlook to: " << to << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
        cout << "Outlook email sent successfully!" << endl;
    }
};


// High level Module

class EmailService {
private:
    
    EmailClient* emailClient;

public:

    EmailService(EmailClient* client) : emailClient(client) {}

    void sendWelcomeEmail(const string& userEmail, const string& userName) {
        string subject = "Welcome, " + userName + "!";
        string body = "Thanks for signing up to our awesome platform. We're glad to have you!";
        emailClient->sendEmail(userEmail, subject, body);
    }

    void sendPasswordResetEmail(const string& userEmail) {
        string subject = "Reset Your Password";
        string body = "Please click the link below to reset your password...";
        emailClient->sendEmail(userEmail, subject, body);
    }

};

int main() {

    cout << "--- Using Gmail ---" << endl;
    
    EmailClient* gmail = new GmailClientImpl();
    EmailService* gmailService = new EmailService(gmail);
    gmailService -> sendWelcomeEmail("test@example.com", "Welcome to SOLID principles!");

    cout << "\n--- Using Outlook ---" << endl;

    EmailClient* outlook = new OutlookClientImpl();
    EmailService* outlookService = new EmailService(outlook);
    outlookService -> sendWelcomeEmail("test@example.com", "Welcome to SOLID principles!");

    return 0;
}

//   g++ main.cpp && ./a.out