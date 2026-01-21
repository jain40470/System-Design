#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() = 0;
};

class VectorCircle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle as VECTORS" << endl;
    }
};

class RasterCircle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle as PIXELS" << endl;
    }
};

class VectorRectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle as VECTORS" << endl;
    }
};

class RasterRectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle as PIXELS" << endl;
    }
};


// Now there are two types of rendering vector and raster
// there are two type of shapes.
// Let say there are n shape and m rendering
// if new rendering type is added you need to create n new classes.


int main() {

    VectorCircle s1;
    RasterRectangle s2;

    s1.draw(); // Drawing Circle as VECTORS
    s2.draw(); // Drawing Rectangle as PIXELS

    return 0;

}

// g++ -std=c++17 main.cpp && ./a.out