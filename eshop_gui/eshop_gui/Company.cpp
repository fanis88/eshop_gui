#include "pch.h"
#include "Company.h"

Company::Company(char* username, char* password) : Customer(username, password) {
}

char* Company::getCompanyName()
{
	return this->companyName;
}

char* Company::getResponsibleName()
{
	return this->responsibleName;
}

char* Company::getResponsibleSurname()
{
	return this->responsibleSurname;
}

double Company::getDiscount()
{
	return this->discount;
}

char* Company::getFax()
{
	return this->fax;
}

void Company::setCompanyName(char* companyName)
{
	this->companyName = companyName;
}

void Company::setResponsibleName(char* responsibleName)
{
	this->responsibleName = responsibleName;
}

void Company::setResponsibleSurname(char* responsibleSurname)
{
	this->responsibleSurname = responsibleSurname;
}

void Company::setDiscount(double discount)
{
	this->discount = discount;
}

void Company::setFax(char* fax)
{
	this->fax = fax;
}

Order Company::placeOrder()
{
	Order order("placeholder");
	return order;
}

