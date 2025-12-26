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


class ShippingCostCalculatorNaive {
public:
    double calculateShippingCost(const Order& order, const string& strategyType) {
        double cost = 0.0;
        if (strategyType == "FLAT_RATE") {
            cout << "Calculating with Flat Rate strategy." << endl;
            cost = 10.0;
        }
        else if (strategyType == "WEIGHT_BASED") {
            cout << "Calculating with Weight-Based strategy." << endl;
            cost = order.getTotalWeight() * 2.5;
        }
        else if (strategyType == "DISTANCE_BASED") {
            cout << "Calculating with Distance-Based strategy." << endl;
            if (order.getDestinationZone() == "ZoneA") {
                cost = 5.0;
            } else if (order.getDestinationZone() == "ZoneB") {
                cost = 12.0;
            } else {
                cost = 20.0; // fallback
            }
        }
        else if (strategyType == "THIRD_PARTY_API") {
            cout << "Calculating with Third-Party API strategy." << endl;
            // Simulated external call
            cost = 7.5 + (order.getOrderValue() * 0.02);
        }
        else {
            throw invalid_argument("Unknown shipping strategy: " + strategyType);
        }
        
        cout << "Calculated Shipping Cost: $" << cost << endl;
        return cost;
    }
};


void ecommerceAppV1() {
    
    ShippingCostCalculatorNaive calculator;
    Order order1;
    
    cout << "--- Order 1 ---" << endl;
    calculator.calculateShippingCost(order1, "FLAT_RATE");
    calculator.calculateShippingCost(order1, "WEIGHT_BASED");
    calculator.calculateShippingCost(order1, "DISTANCE_BASED");
    calculator.calculateShippingCost(order1, "THIRD_PARTY_API");
    
    // What if we want to try a new "PremiumZone" strategy?
    // We have to go modify this calculator class again...
}

int main() {

    cout << "=== Naive Approach ===" << endl;
    ecommerceAppV1();
        
    return 0;
}

