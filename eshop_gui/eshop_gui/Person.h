#pragma once
#include "Customer.h"
#include "Order.h"

class Person : public Customer
{
public:
	Person(char* username, char* password);
	char* getName();
	char* getSurname();
	char* getIdentity();
	void setName(char* name);
	void setSurname(char* surname);
	void setIdentity(char* identity);
	Order placeOrder();
private:
	char* name;
	char* surname;
	char* identity;
};