#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
 

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() = default;
};


class CreditCardPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processing credit card payment of $" << amount << endl;
        // Complex logic for credit card processing
    }
};

class PayPalPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal payment of $" << amount << endl;
        // Logic for PayPal processing
    }
};

class UPIPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processing UPI payment of ₹" << amount * 80 << endl;
        // Logic for UPI processing
    }
};


class PaymentProcessor {
public:
    void process(PaymentMethod* paymentMethod, double amount) {
        // No more if-else! The processor doesn't care about the specific type.
        // It just knows it can call processPayment.      
        paymentMethod->processPayment(amount);
    }
};


class CheckoutService {
public:
    void processPayment(PaymentMethod* method, double amount) {
        PaymentProcessor processor;
        processor.process(method, amount);
    }
};



int main(){
    
    CheckoutService* checkout;

    CreditCardPayment* credit;
    PayPalPayment* paypal;
    UPIPayment* upi;

    checkout->processPayment(credit, 100.00);
    checkout->processPayment(paypal, 100.00);
    checkout->processPayment(upi, 100.00);
 
}

