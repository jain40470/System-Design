#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
 

// To communicate between high module and low module there shoule be  an intercae 


// Low level Module
class GmailClient {
public:
    void sendGmail(const string& toAddress, const string& subjectLine, const string& emailBody) {
        cout << "Connecting to Gmail SMTP server..." << endl;
        cout << "Sending email via Gmail to: " << toAddress << endl;
        cout << "Subject: " << subjectLine << endl;
        cout << "Body: " << emailBody << endl;
        // ... actual Gmail API interaction logic ...
        cout << "Gmail email sent successfully!" << endl;
    }
};

// High level Module
class EmailService {
private:

    GmailClient* gmailClient;
public:
    
    EmailService( GmailClient* Client) : gmailClient(Client) {}

    void sendWelcomeEmail(const string& userEmail, const string& userName) {
        string subject = "Welcome, " + userName + "!";
        string body = "Thanks for signing up to our awesome platform. We're glad to have you!";
        gmailClient->sendGmail(userEmail, subject, body);
    }

    void sendPasswordResetEmail(const string& userEmail) {
        string subject = "Reset Your Password";
        string body = "Please click the link below to reset your password...";
        gmailClient->sendGmail(userEmail, subject, body);
    }

};

int main() {

    cout << "--- Using Gmail ---" << endl;
    
    GmailClient* gmail = new GmailClient();
    EmailService* gmailService = new EmailService(gmail);
    gmailService -> sendWelcomeEmail("test@example.com", "Welcome to SOLID principles!");

    return 0;
}

//   g++ main.cpp && ./a.out