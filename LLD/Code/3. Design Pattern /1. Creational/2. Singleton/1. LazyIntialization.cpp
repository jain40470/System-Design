#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


class LazySingleton {
private:

    static LazySingleton* instance;
    LazySingleton() {}

public:
    static LazySingleton* getInstance() {
        if (instance == nullptr) {
            instance = new LazySingleton();
        }
        return instance;
    }
};



// This approach creates the singleton instance only when it is needed, 
//saving resources if the singleton is never used in the application.

// But...
// This implementation is not thread-safe. If multiple threads 
// call getInstance() simultaneously when instance is null, 
// it's possible to create multiple instances.


int main(){




}
