#include "pch.h"
#include "Person.h"


Person::Person(char* username, char* password) : Customer(username, password) {
}

char* Person::getName() {
	return this->name;
}

char* Person::getSurname() {
	return this->surname;
}

char* Person::getIdentity() {
	return this->identity;
}

void Person::setName(char* name) {
	this->name = name;
}

void Person::setSurname(char* surname) {
	this->surname = surname;
}

void Person::setIdentity(char* identity) {
	this->identity = identity;
}

Order Person::placeOrder()
{
	Order order("placeholder");
	return order;
}

