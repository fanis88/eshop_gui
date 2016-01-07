#include "pch.h"
#include "Availability.h"

Availability::Availability() {
}

Availability::Availability(ProductBase product, int quantity){
	this->product = product;
	this->quantity = quantity;
}

int Availability::getQuantity() {
	return this->quantity;
}

ProductBase Availability::getProduct() {
	return this->product;
}