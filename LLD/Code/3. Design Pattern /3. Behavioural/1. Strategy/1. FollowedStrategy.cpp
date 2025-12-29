#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


class Order{

private : 

    double value = 0;
    string destination = "";
    double weight = 0;

public :

    double getOrderValue() const{
        return this->value;
    }
    double getTotalWeight() const{
        return this->weight;
    }
    string getDestinationZone() const{
        return this->destination;
    }

};

class ShippingStrategy {
public:
    virtual double calculateCost(const Order& order) = 0;
    virtual ~ShippingStrategy() {}
};


class FlatRateShipping : public ShippingStrategy {
private:
    double rate;
public:
    FlatRateShipping(double r) : rate(r) {}
    double calculateCost(const Order& order) override {
        cout << "Calculating with Flat Rate strategy ($" << rate << ")" << endl;
        return rate;
    }
};

class WeightBasedShipping : public ShippingStrategy {
private:
    double ratePerKg;

public:
    WeightBasedShipping(double rateKg) : ratePerKg(rateKg) {}
    
    double calculateCost(const Order& order) override {
        cout << "Calculating with Weight-Based strategy ($" << ratePerKg << "/kg)" << endl;
        return order.getTotalWeight() * ratePerKg;
    }
};

class DistanceBasedShipping : public ShippingStrategy {
private:
    double ratePerKm;

public:
    DistanceBasedShipping(double rateKm) : ratePerKm(rateKm) {}
    
    double calculateCost(const Order& order) override {
        cout << "Calculating with Distance-Based strategy for zone: " << order.getDestinationZone() << endl;
        
        if (order.getDestinationZone() == "ZoneA") {
            return ratePerKm * 5.0;
        } else if (order.getDestinationZone() == "ZoneB") {
            return ratePerKm * 7.0;
        } else {
            return ratePerKm * 10.0;
        }
    }
};

class ThirdPartyApiShipping : public ShippingStrategy {
private:
    double baseFee;
    double percentageFee;

public:
    ThirdPartyApiShipping(double base, double percentage) 
        : baseFee(base), percentageFee(percentage) {}
    
    double calculateCost(const Order& order) override {
        cout << "Calculating with Third-Party API strategy." << endl;
        // Simulate API call
        return baseFee + (order.getOrderValue() * percentageFee);
    }
};

class ShippingCostService {
private:
    ShippingStrategy* strategy;

public:
    ShippingCostService(ShippingStrategy* s) : strategy(s) {}
    
    void setStrategy(ShippingStrategy* s) {
        cout << "ShippingCostService: Strategy changed" << endl;
        strategy = s;
    }
    
    double calculateShippingCost(const Order& order) {
        if (strategy == nullptr) {
            throw invalid_argument("Shipping strategy not set.");
        }
        
        double cost = strategy->calculateCost(order);
        cout << "ShippingCostService: Final Calculated Shipping Cost: $" << cost << endl;
        return cost;
    }
};

void ecommerceAppV2() {

    Order order1;
    
    // Create different strategy instances
    FlatRateShipping flatRate(10.0);
    WeightBasedShipping weightBased(2.5);
    DistanceBasedShipping distanceBased(5.0);
    ThirdPartyApiShipping thirdParty(7.5, 0.02);
    
    // Create context with an initial strategy
    ShippingCostService shippingService(&flatRate);
    
    cout << "--- Order 1: Using Flat Rate (initial) ---" << endl;
    shippingService.calculateShippingCost(order1);
    
    cout << "\n--- Order 1: Changing to Weight-Based ---" << endl;
    shippingService.setStrategy(&weightBased);
    shippingService.calculateShippingCost(order1);
    
    cout << "\n--- Order 1: Changing to Distance-Based ---" << endl;
    shippingService.setStrategy(&distanceBased);
    shippingService.calculateShippingCost(order1);
    
    cout << "\n--- Order 1: Changing to Third-Party API ---" << endl;
    shippingService.setStrategy(&thirdParty);
    shippingService.calculateShippingCost(order1);
    
    // Adding a NEW strategy is easy:
    // 1. Create a new class implementing ShippingStrategy (e.g., FreeShippingStrategy)
    // 2. Client can then instantiate and use it:
    //    FreeShippingStrategy freeShipping;
    //    shippingService.setStrategy(&freeShipping);
    //    shippingService.calculateShippingCost(primeMemberOrder);
    // No modification to ShippingCostService is needed!

}

int main() {
    
    cout << "\n\n=== Strategy Pattern Approach ===" << endl;
    ecommerceAppV2();

}