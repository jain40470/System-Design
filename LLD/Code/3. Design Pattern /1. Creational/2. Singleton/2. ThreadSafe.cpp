#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


class ThreadSafeSingleton {
private:
    static ThreadSafeSingleton* instance;
    static mutex lock;

    ThreadSafeSingleton() {}

public:
    static ThreadSafeSingleton* getInstance() {
        lock_guard<mutex> guard(lock);
        if (instance == nullptr) {
            instance = new ThreadSafeSingleton();
        }
        return instance;
    }
};


// Although this approach is straightforward, using synchronized 
// can cause substantial overhead and reduce performance, which 
// can be a bottleneck if called frequently.


class DoubleCheckedSingleton {
private:
    static DoubleCheckedSingleton* instance;
    static mutex lock;

    DoubleCheckedSingleton() {}

public:
    static DoubleCheckedSingleton* getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> guard(lock);
            if (instance == nullptr) {
                instance = new DoubleCheckedSingleton();
            }
        }
        return instance;
    }
};

// this method is a bit complex to implement,
// but it can drastically reduce the performance overhead.



int main(){

    


}
