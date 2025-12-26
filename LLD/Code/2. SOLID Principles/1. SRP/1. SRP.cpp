#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
 

class Employee {
private:
    string name;
    string email;
    double baseSalary;

public:
    Employee(const string& name, const string& email, double baseSalary)
        : name(name), email(email), baseSalary(baseSalary) {}

    string getName() const {
        return name;
    }

    string getEmail() const {
        return email;
    }

    double getBaseSalary() const {
        return baseSalary;
    }
};

// Responsibility 1
class PayrollCalculator {
public:
    double calculateNetPay(const Employee& employee) {
        double base = employee.getBaseSalary();
        double tax = base * 0.2;  // Sample tax logic
        double benefits = 1000;   // Fixed benefit deduction
        return base - tax + benefits;
    }
};


// Responsibility 2
class EmployeeRepository {  
public:
    void save(const Employee& employee) {
        cout << "Saving employee " << employee.getName() << " to database..." << endl;
    }
}; 
// so here if we want to save in db then have to change the logic in class  
// but if we care of ocp then we have it as abstract class and then create its child 
// doing work for that.


// Responsibility 3
class PayslipGenerator {
public:
    string generatePayslip(const Employee& employee, double netPay) {
        string payslip = "Payslip for: " + employee.getName() + "\n";
        payslip += "Email: " + employee.getEmail() + "\n";
        payslip += "Net Pay: ₹" + to_string(netPay) + "\n";
        payslip += "----------------------------\n";
        return payslip;
    }
};

// Responsibility 4
class EmailService {
public:
    void sendPayslip(const Employee& employee, const string& payslip) {
        cout << "Sending payslip to: " << employee.getEmail() << endl;
        cout << payslip;
    }
};


int main(){
    

}

