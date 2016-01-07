#pragma once
#include "UserBase.h"
#include "ProductBase.h"

class Customer : public UserBase
{
public:
	Customer();
	Customer(char* username, char* password);
	char* getAfm();
	char* getPhoneNumber();
	char* getAddress();
	void setAfm(char* afm);
	void setPhoneNumber(char* phoneNumber);
	void setAddress(char* address);
	void addProductToCart(ProductBase product, int quantity);
	void updateProductItemsInCart(ProductBase product, int newQuantity);
	void removeProductFromCart(ProductBase product);
private:
	char* afm;
	char* phoneNumber;
	char* address;
	map<ProductBase, int> cart;
};

