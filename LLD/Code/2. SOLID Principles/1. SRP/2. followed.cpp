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

// SRP Violation 
// Cart is handling too many responsibilities.

class ShoppingCart{
    
private : 
    vector<Product*> products;

public : 

    void addProduct(Product* Product){
        this->products.push_back(Product);
    }

    const vector<Product*>&  getProducts(){   // here u are passing as reference but not allow modification in vector
        return products;
    }

    // Responsibility
    // 1.
    double CalculateTotal(){
        double totalprice = 0;
        for(auto product : products){
            totalprice = totalprice + (product->price);
        }
        return totalprice;
    }

};

// Responsibility
class ShoppingCartStorage{
private:
    ShoppingCart* cart;
public:

    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }
    void CartSavetoDB(){
        cout << ("shoping cart save to db successfully") << "\n";
    }
};

// Responsibility
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
    ShoppingCartStorage* storage = new ShoppingCartStorage(cart);
    CartInvoice* invoice = new CartInvoice(cart);

    Product* p1 = new Product("A" , 1000);
    Product* p2 = new Product("B" , 1000);

    cart->addProduct(p1);
    cart->addProduct(p2);

    invoice->printInvoice();
    storage->CartSavetoDB();
 
}

//   g++ main.cpp && ./a.out