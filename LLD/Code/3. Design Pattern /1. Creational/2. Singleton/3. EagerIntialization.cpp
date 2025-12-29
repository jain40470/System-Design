#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


class EagerSingleton {
private:
    static EagerSingleton* instance;

    EagerSingleton() {}

public:
    static EagerSingleton* getInstance() {
        return instance;
    }
};

EagerSingleton* EagerSingleton :: instance = new EagerSingleton();


class BillPughSingleton {
private:
    BillPughSingleton() {}

public:

    static BillPughSingleton* getInstance() {
        static BillPughSingleton instance;
        return &instance;
    }

    static BillPughSingleton_2* getInstance() {
        static BillPughSingleton* instance = new BillPughSingleton() ;
        return instance;
    }

};

// No eager initialization , only when reqd.

// Case A 
// static BillPughSingleton instance;
// return instance;
// There is no pointer involved here.
// instance is an actual object, not a pointer.
// Lifetime: entire program
// Destructor runs automatically at program exit
// Memory is released by the C++ runtime / OS when the program ends.
// So no pointer remains because there is no pointer at all.

// Case : B
// static BillPughSingleton* instance = new BillPughSingleton();
// return instance;
// instance is a pointer to a heap object.
// Lifetime of heap object = until delete is called
// Pointer itself (instance) has static lifetime (exists until program ends)
// If you never call delete:
// Object is never destroyed → memory leak
// Pointer still exists (points to memory that is technically 
// “freed” by OS at program exit, but destructor never ran)

// note : local static variables are initialized the first time the 
// function is called (lazy initialization).


int main(){

    


}
