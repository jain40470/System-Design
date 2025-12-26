#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
 

// Product class representing any items of any Ecommerce.
class Product{
public : 
    string name;
    double price;
    Product(string name,double price){
        this->name = name;
        this->price = price;
    }
};


// OCP Followed : 
// To add features , we are not making changes in class only.
// we ar extending the class using inheritance.


class ShoppingCart{
    
private : 
    vector<Product*> products;

public : 

    void addProduct(Product* Product){
        this->products.push_back(Product);
    }

    const vector<Product*>&  getProducts(){   
        return products;
    }

    double CalculateTotal(){
        double totalprice = 0;
        for(auto product : products){
            totalprice = totalprice + (product->price);
        }
        return totalprice;
    }

};

class CartStorage{
public:
    virtual void saveToDB(ShoppingCart* cart) = 0;
};

class CartMongoDBStorage : public CartStorage{

public :

    void saveToDB(ShoppingCart* cart) override {
        cout << ("shoping cart save to Mongo db successfully") << "\n";
    }
};

class CartFileDBStorage : public CartStorage{

public :

    void saveToDB(ShoppingCart* cart) override{
        cout << ("shoping cart save to File db successfully") << "\n";
    }
};

class CartDynamoDBStorage : public CartStorage{
public :
    void saveToDB(ShoppingCart* cart) override{
        cout << ("shoping cart save to Dynamo db successfully") << "\n";
    }
};


class CartInvoice{
private:
    ShoppingCart* cart;
public:
    
    CartInvoice(ShoppingCart* cart){
        this->cart = cart;
    }
    
    void printInvoice(){
        cout << "Shopping Cart" << "\n";
        for(auto it : cart->getProducts() ){
            cout << (it -> name) << " " << (it->price) << "\n";
        }
        cout << "Total price" << " " << cart->CalculateTotal() << "\n";
    }

};




int main(){
    

    ShoppingCart* cart = new ShoppingCart();
    CartInvoice* invoice = new CartInvoice(cart);

    Product* p1 = new Product("A" , 1000);
    Product* p2 = new Product("B" , 1000);

    cart->addProduct(p1);
    cart->addProduct(p2);

    invoice->printInvoice();

    CartStorage* storage1 = new CartMongoDBStorage();
    storage1->saveToDB(cart);
    
    CartStorage* storage2 = new CartFileDBStorage();
    storage2->saveToDB(cart);
    
 
}

//   g++ main.cpp && ./a.out