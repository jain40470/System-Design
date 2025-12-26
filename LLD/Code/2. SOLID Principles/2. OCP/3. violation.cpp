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


// OCP Violation : 
// To add features , we are making changes in class only.


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

class ShoppingCartStorage{
private:
    ShoppingCart* cart;
public:

    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }
    void savetoMongoDB(){
        cout << ("shoping cart save to mongo db successfully") << "\n";
    }

    // new added features
    void savetoFileDB(){
        cout << ("shoping cart save to File db successfully") << "\n";
    }
    void savetoDynamoDB(){
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
    ShoppingCartStorage* storage = new ShoppingCartStorage(cart);
    CartInvoice* invoice = new CartInvoice(cart);

    Product* p1 = new Product("A" , 1000);
    Product* p2 = new Product("B" , 1000);

    cart->addProduct(p1);
    cart->addProduct(p2);

    invoice->printInvoice();
    storage->savetoMongoDB();
    storage->savetoFileDB();
    storage->savetoDynamoDB();
 
}

//   g++ main.cpp && ./a.out