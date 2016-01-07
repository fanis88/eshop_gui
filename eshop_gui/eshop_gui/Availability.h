#pragma once
#include "ProductBase.h"

class Availability
{
public:
	Availability();
	Availability(ProductBase product, int quantity);
	int getQuantity();
	ProductBase getProduct();
private:
	ProductBase product;
	int quantity;
};

