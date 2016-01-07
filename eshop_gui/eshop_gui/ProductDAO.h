#pragma once
#include <vector>
#include "sqlite3.h"
#include "ProductBase.h"
#include "PC.h"
#include "Smartphone.h"
#include "TV.h"
#include "Availability.h"

class ProductDAO
{
public:
	ProductDAO(sqlite3* database);
	int insertProductInDB(PC product, int productType, int availability);
	int insertProductInDB(Smartphone product, int productType, int availability);
	int insertProductInDB(TV product, int productType, int availability);
	int updateProductInDB(PC updatedProduct);
	int updateProductInDB(Smartphone updatedProduct);
	int updateProductInDB(TV updatedProduct);
	int updateProductItemsInDB(int serial, int availability);
	int removeProductItemsFromDB(int serial, int removedItems);
	int addProductItemsInDB(int serial, int addedItems);
	int getProductAvailabilityFromDB(int serial);
	Availability fetchProductBySerialFromDB(int serial);
	vector<Availability> fetchProductsByManufacturer(string manufacturer);
	vector<Availability> fetchProductsByType(int type);
	vector<Availability> fetchAllProductsFromDB();
	vector<Availability> fetchAllPCsFromDB();
	vector<Availability> fetchAllSmartphonesFromDB();
	vector<Availability> fetchAllTVsFromDB();
private:
	sqlite3* db;
};

