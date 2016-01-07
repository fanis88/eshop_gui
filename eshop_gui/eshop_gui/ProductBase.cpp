#include "pch.h"
#include "ProductBase.h"

ProductBase::ProductBase() {
}

int ProductBase::getSerial() const {
	return serial;
}

char* ProductBase::getModel() {
	return model;
}

char* ProductBase::getManufacturer() {
	return manufacturer;
}

char* ProductBase::getPhotoUrl() {
	return photoUrl;
}

char* ProductBase::getDescription() {
	return description;
}

double ProductBase::getPrice() {
	return price;
}

void ProductBase::setSerial(int serial) {
	this->serial = serial;
}

void ProductBase::setModel(char* model) {
	this->model = model;
}

void ProductBase::setManufacturer(char* manufacturer) {
	this->manufacturer = manufacturer;
}

void ProductBase::setPhotoUrl(char* photoUrl) {
	this->photoUrl = photoUrl;
}

void ProductBase::setDescription(char* description) {
	this->description = description;
}

void ProductBase::setPrice(double price) {
	this->price = price;
}

bool ProductBase::operator==(const ProductBase &p2) const {
	return (this->getSerial() == p2.getSerial());
}

bool ProductBase::operator<(const ProductBase &p2) const {
	return (this->getSerial() < p2.getSerial());
}

bool ProductBase::operator>(const ProductBase &p2) const {
	return (this->getSerial() > p2.getSerial());
}