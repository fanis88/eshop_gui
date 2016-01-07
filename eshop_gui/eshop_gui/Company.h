#pragma once
#include "Customer.h"
#include "Order.h"

class Company : public Customer
{
public:
	Company(char* username, char* password);
	char* getCompanyName();
	char* getResponsibleName();
	char* getResponsibleSurname();
	double getDiscount();
	char* getFax();
	void setCompanyName(char* companyName);
	void setResponsibleName(char* responsibleName);
	void setResponsibleSurname(char* responsibleSurname);
	void setDiscount(double discount);
	void setFax(char* fax);
	Order placeOrder();
private:
	char* companyName;
	char* responsibleName;
	char* responsibleSurname;
	double discount;
	char* fax;
};

