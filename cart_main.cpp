#include <iostream>
#include <vector>
#include <cstdlib> // Include for NULL
#include "datamodel.h"

using namespace std; // Avoid using namespace in header files

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(2, "mango", 12),
    Product(3, "banana", 24),
    Product(4, "orange", 20),
    Product(5, "pear", 30),
    Product(6, "grape", 15),
    Product(7, "kiwi", 18),
    Product(8, "plum", 22),
    Product(9, "watermelon", 28)};

Product *chooseProduct()
{
    string productList;
    cout << "Available Products " << endl;
    for (auto product : allProducts)
    {
        productList.append(product.getDisplayName());
    }
    cout << productList << endl;
    cout << "------------------------------" << endl;
    string choice;
    cin >> choice;
    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getShortName() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "Product not found!" << endl;
    return NULL;
}
bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    int total=cart.getTotal();
    cout<<"Pay in Cash";
    int paid;
    cin>>paid;
    if(paid>=total){
        cout<<"Change "<<paid-total<<endl;
        cout<<"Thankyou for Shopping!";
        return true;
    }else{
        cout<<"Not enough Cash...";
        return false;
    }
}
int main()
{
    char action;
    Cart cart;
    while (true)
    {
        cout << "Select an action - (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action; // Update action variable
        if (action == 'a')
        {
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Added to the cart " << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        }
        else if (action == 'v')
        {
            cout<<"--------------------------"<<endl;
            cout<<cart.viewCart();
            cout<<"--------------------------"<<endl;
        }
        else
        {
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }
    return 0;
}
