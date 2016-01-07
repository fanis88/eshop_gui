#include "pch.h"
#include "ProductDAO.h"

ProductDAO::ProductDAO(sqlite3* database) {
	db = database;
}

int ProductDAO::insertProductInDB(PC product, int productType, int availability) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "insert into products (TYPE, PRICE, MODEL, MANUFACTURER, " \
		"PHOTOURL, DESCRIPTION, RAM, CPU, DISKTYPE, DISKSPACE, GPU, SCREENSIZE" \
		"BATTERYLIFE, CANRECORD4K, CANSHOW3D)" \
		"values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ? )";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int index = 1;
		sqlite3_bind_int(stmt, index++, 0);
		sqlite3_bind_double(stmt, index++, product.getPrice());
		sqlite3_bind_text(stmt, index++, product.getModel(), strlen(product.getModel()), 0);
		sqlite3_bind_text(stmt, index++, product.getManufacturer(), strlen(product.getManufacturer()), 0);
		sqlite3_bind_text(stmt, index++, product.getPhotoUrl(), strlen(product.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, index++, product.getDescription(), strlen(product.getDescription()), 0);
		sqlite3_bind_int(stmt, index++, product.getRam());
		sqlite3_bind_double(stmt, index++, product.getCpu());
		sqlite3_bind_text(stmt, index++, product.getDiskType(), strlen(product.getDiskType()), 0);
		sqlite3_bind_int(stmt, index++, product.getDiskSpace());
		sqlite3_bind_text(stmt, index++, product.getGpu(), strlen(product.getGpu()), 0);

		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::insertProductInDB(Smartphone product, int productType, int availability) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "insert into products (TYPE, PRICE, MODEL, MANUFACTURER, " \
		"PHOTOURL, DESCRIPTION, RAM, CPU, DISKTYPE, DISKSPACE, GPU, SCREENSIZE" \
		"BATTERYLIFE, CANRECORD4K, CANSHOW3D)" \
		"values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ? )";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int index = 1;
		sqlite3_bind_int(stmt, index++, 1);
		sqlite3_bind_double(stmt, index++, product.getPrice());
		sqlite3_bind_text(stmt, index++, product.getModel(), strlen(product.getModel()), 0);
		sqlite3_bind_text(stmt, index++, product.getManufacturer(), strlen(product.getManufacturer()), 0);
		sqlite3_bind_text(stmt, index++, product.getPhotoUrl(), strlen(product.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, index++, product.getDescription(), strlen(product.getDescription()), 0);
		//Skip PC product properties
		index = 13;
		sqlite3_bind_double(stmt, index++, product.getScreenSize());
		sqlite3_bind_int(stmt, index++, product.getBatteryLife());
		sqlite3_bind_int(stmt, index++, product.getCanRecord4k());

		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::insertProductInDB(TV product, int productType, int availability) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "insert into products (TYPE, PRICE, MODEL, MANUFACTURER, " \
		"PHOTOURL, DESCRIPTION, RAM, CPU, DISKTYPE, DISKSPACE, GPU, SCREENSIZE" \
		"BATTERYLIFE, CANRECORD4K, CANSHOW3D)" \
		"values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ? )";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int index = 1;
		sqlite3_bind_int(stmt, index++, 2);
		sqlite3_bind_double(stmt, index++, product.getPrice());
		sqlite3_bind_text(stmt, index++, product.getModel(), strlen(product.getModel()), 0);
		sqlite3_bind_text(stmt, index++, product.getManufacturer(), strlen(product.getManufacturer()), 0);
		sqlite3_bind_text(stmt, index++, product.getPhotoUrl(), strlen(product.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, index++, product.getDescription(), strlen(product.getDescription()), 0);
		//Skip PC product properties
		index = 13;
		sqlite3_bind_double(stmt, index++, product.getScreenSize());
		//Skip Smartphone product properties
		index = 16;
		sqlite3_bind_int(stmt, index++, product.getCanShow3d());

		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::updateProductInDB(PC updatedProduct) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "update products set PRICE = ?, MODEL = ?, " \
		"MANUFACTURER = ?, PHOTOURL = ?, DESCRIPTION = ?, RAM = ?, CPU = ?, " \
		"DISKTYPE = ?, DISKSPACE = ?, GPU = ? WHERE SERIAL = ?";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int index = 1;
		sqlite3_bind_double(stmt, index++, updatedProduct.getPrice());
		sqlite3_bind_text(stmt, index++, updatedProduct.getModel(), strlen(updatedProduct.getModel()), 0);
		sqlite3_bind_text(stmt, index++, updatedProduct.getManufacturer(), strlen(updatedProduct.getManufacturer()), 0);
		sqlite3_bind_text(stmt, index++, updatedProduct.getPhotoUrl(), strlen(updatedProduct.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, index++, updatedProduct.getDescription(), strlen(updatedProduct.getDescription()), 0);
		sqlite3_bind_int(stmt, index++, updatedProduct.getRam());
		sqlite3_bind_double(stmt, index++, updatedProduct.getCpu());
		sqlite3_bind_text(stmt, index++, updatedProduct.getDiskType(), strlen(updatedProduct.getDiskType()), 0);
		sqlite3_bind_int(stmt, index++, updatedProduct.getDiskSpace());
		sqlite3_bind_text(stmt, index++, updatedProduct.getGpu(), strlen(updatedProduct.getGpu()), 0);
		sqlite3_bind_int(stmt, index++, updatedProduct.getSerial());
		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::updateProductInDB(Smartphone updatedProduct) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "update products set PRICE = ?, MODEL = ?, " \
		"MANUFACTURER = ?, PHOTOURL = ?, DESCRIPTION = ?, SCREENSIZE = ?, " \
		"BATTERYLIFE = ?, CANRECORD4K = ? WHERE SERIAL = ?";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int index = 1;
		sqlite3_bind_double(stmt, index++, updatedProduct.getPrice());
		sqlite3_bind_text(stmt, index++, updatedProduct.getModel(), strlen(updatedProduct.getModel()), 0);
		sqlite3_bind_text(stmt, index++, updatedProduct.getManufacturer(), strlen(updatedProduct.getManufacturer()), 0);
		sqlite3_bind_text(stmt, index++, updatedProduct.getPhotoUrl(), strlen(updatedProduct.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, index++, updatedProduct.getDescription(), strlen(updatedProduct.getDescription()), 0);
		sqlite3_bind_double(stmt, index++, updatedProduct.getScreenSize());
		sqlite3_bind_int(stmt, index++, updatedProduct.getBatteryLife());
		sqlite3_bind_int(stmt, index++, updatedProduct.getCanRecord4k());
		sqlite3_bind_int(stmt, index++, updatedProduct.getSerial());
		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::updateProductInDB(TV updatedProduct) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "update products set PRICE = ?, MODEL = ?, " \
		"MANUFACTURER = ?, PHOTOURL = ?, DESCRIPTION = ?, " \
		"SCREENSIZE = ?, CANSHOW3D = ? WHERE SERIAL = ?";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int index = 1;
		sqlite3_bind_double(stmt, index++, updatedProduct.getPrice());
		sqlite3_bind_text(stmt, index++, updatedProduct.getModel(), strlen(updatedProduct.getModel()), 0);
		sqlite3_bind_text(stmt, index++, updatedProduct.getManufacturer(), strlen(updatedProduct.getManufacturer()), 0);
		sqlite3_bind_text(stmt, index++, updatedProduct.getPhotoUrl(), strlen(updatedProduct.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, index++, updatedProduct.getDescription(), strlen(updatedProduct.getDescription()), 0);
		sqlite3_bind_double(stmt, index++, updatedProduct.getScreenSize());
		sqlite3_bind_int(stmt, index++, updatedProduct.getCanShow3d());
		sqlite3_bind_int(stmt, index++, updatedProduct.getSerial());
		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::updateProductItemsInDB(int serial, int availability) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "update in products set AVAILABILITY = ? where SERIAL = ?";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int index = 1;
		sqlite3_bind_int(stmt, index++, availability);
		sqlite3_bind_int(stmt, index++, serial);
		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::removeProductItemsFromDB(int serial, int removedItems) {
	int productAvailability = getProductAvailabilityFromDB(serial);
	productAvailability -= removedItems;
	int res = updateProductItemsInDB(serial, productAvailability);

	return res;
}

int ProductDAO::addProductItemsInDB(int serial, int addedItems) {
	int productAvailability = getProductAvailabilityFromDB(serial);
	productAvailability += addedItems;
	int res = updateProductItemsInDB(serial, productAvailability);

	return res;
}

int ProductDAO::getProductAvailabilityFromDB(int serial) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "select AVAILABILITY from products where SERIAL = ?";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(stmt, 1, serial);
		int res = 0;

		res = sqlite3_step(stmt);
		if (res == SQLITE_ROW) {
			int availability = sqlite3_column_int(stmt, 1);
			sqlite3_finalize(stmt);
			return availability;
		}
		else if (res == SQLITE_DONE) {
			fprintf(stderr, "No product with given serial number.");
			return res;
		}
		else {
			fprintf(stderr, "Database error while fetching product.");
			return res;
		}
	}
	return 0;
}

Availability ProductDAO::fetchProductBySerialFromDB(int serial) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		Availability avail;
		return avail;
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "SELECT * from products where serial=:serial";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(stmt, 1, serial);
		int res = 0;

		res = sqlite3_step(stmt);
		if (res == SQLITE_ROW) {
			if (sqlite3_column_int(stmt, 2) == 0)			//Product type: PC
			{
				int index = 3;
				PC fetchedProduct = PC();
				fetchedProduct.setPrice(sqlite3_column_double(stmt, index++));
				fetchedProduct.setModel((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setRam(sqlite3_column_int(stmt, index++));
				fetchedProduct.setCpu(sqlite3_column_double(stmt, index++));
				fetchedProduct.setDiskType((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setDiskSpace(sqlite3_column_int(stmt, index++));
				fetchedProduct.setGpu((char*)sqlite3_column_text(stmt, index++));
				int availability = sqlite3_column_int(stmt, 17);
				sqlite3_finalize(stmt);
				Availability avail(fetchedProduct, availability);
				return avail;
			}
			else if (sqlite3_column_int(stmt, 2) == 1) {	//Product type: Smartphone
				int index = 3;
				Smartphone fetchedProduct = Smartphone();
				fetchedProduct.setPrice(sqlite3_column_double(stmt, index++));
				fetchedProduct.setModel((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, index++));
				//Skip PC product properties
				index = 13;
				fetchedProduct.setScreenSize(sqlite3_column_double(stmt, index++));
				fetchedProduct.setBatteryLife(sqlite3_column_int(stmt, index++));
				fetchedProduct.setCanRecord4k(sqlite3_column_int(stmt, index++));
				int availability = sqlite3_column_int(stmt, 17);
				sqlite3_finalize(stmt);
				Availability avail(fetchedProduct, availability);
				return avail;
			}
			else {											//Product type: TV
				int index = 3;
				TV fetchedProduct = TV();
				fetchedProduct.setPrice(sqlite3_column_double(stmt, index++));
				fetchedProduct.setModel((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, index++));
				//Skip PC product properties
				index = 13;
				fetchedProduct.setScreenSize(sqlite3_column_double(stmt, index++));
				//Skip Smartphone product properties
				index = 16;
				fetchedProduct.setCanShow3d(sqlite3_column_int(stmt, index++));
				int availability = sqlite3_column_int(stmt, 17);
				sqlite3_finalize(stmt);
				Availability avail(fetchedProduct, availability);
				return avail;
			}
		}
		else if (res == SQLITE_DONE) {
			fprintf(stderr, "No product with given serial number.");
			Availability avail;
			return avail;
		}
		else {
			fprintf(stderr, "Database error while fetching product.");
			ProductBase product;
			Availability avail;
			return avail;
		}
	}
	Availability avail;
	return avail;
}

vector<Availability> ProductDAO::fetchAllProductsFromDB() {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return vector<Availability>();
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;
	vector <Availability> products;

	szSQL = "SELECT * from products";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int res = 0;

		while (1) {
			res = sqlite3_step(stmt);
			if (res == SQLITE_ROW) {
				if (sqlite3_column_int(stmt, 2) == 0)			//Product type: PC
				{
					int index = 3;
					PC fetchedProduct = PC();
					fetchedProduct.setPrice(sqlite3_column_double(stmt, index++));
					fetchedProduct.setModel((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setRam(sqlite3_column_int(stmt, index++));
					fetchedProduct.setCpu(sqlite3_column_double(stmt, index++));
					fetchedProduct.setDiskType((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setDiskSpace(sqlite3_column_int(stmt, index++));
					fetchedProduct.setGpu((char*)sqlite3_column_text(stmt, index++));
					int availability = sqlite3_column_int(stmt, 17);
					sqlite3_finalize(stmt);
					Availability avail(fetchedProduct, availability);
					products.push_back(avail);
				}
				else if (sqlite3_column_int(stmt, 2) == 1) {	//Product type: Smartphone
					int index = 3;
					Smartphone fetchedProduct = Smartphone();
					fetchedProduct.setPrice(sqlite3_column_double(stmt, index++));
					fetchedProduct.setModel((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, index++));
					//Skip PC product properties
					index = 13;
					fetchedProduct.setScreenSize(sqlite3_column_double(stmt, index++));
					fetchedProduct.setBatteryLife(sqlite3_column_int(stmt, index++));
					fetchedProduct.setCanRecord4k(sqlite3_column_int(stmt, index++));
					int availability = sqlite3_column_int(stmt, 17);
					sqlite3_finalize(stmt);
					Availability avail(fetchedProduct, availability);
					products.push_back(avail);
				}
				else {											//Product type: TV
					int index = 3;
					TV fetchedProduct = TV();
					fetchedProduct.setPrice(sqlite3_column_double(stmt, index++));
					fetchedProduct.setModel((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, index++));
					fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, index++));
					//Skip PC product properties
					index = 13;
					fetchedProduct.setScreenSize(sqlite3_column_double(stmt, index++));
					//Skip Smartphone product properties
					index = 16;
					fetchedProduct.setCanShow3d(sqlite3_column_int(stmt, index++));
					int availability = sqlite3_column_int(stmt, 17);
					sqlite3_finalize(stmt);
					Availability avail(fetchedProduct, availability);
					products.push_back(avail);
				}
			}
			if (res == SQLITE_DONE || res == SQLITE_ERROR)
			{
				break;
			}
		}
	}
	return products;
}

vector<Availability> ProductDAO::fetchAllPCsFromDB() {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return vector<Availability>();
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;
	vector <Availability> products;

	szSQL = "SELECT * from products where TYPE=0";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int res = 0;

		while (1) {
			res = sqlite3_step(stmt);
			if (res == SQLITE_ROW) {
				int index = 3;
				PC fetchedProduct = PC();
				fetchedProduct.setPrice(sqlite3_column_double(stmt, index++));
				fetchedProduct.setModel((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setRam(sqlite3_column_int(stmt, index++));
				fetchedProduct.setCpu(sqlite3_column_double(stmt, index++));
				fetchedProduct.setDiskType((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setDiskSpace(sqlite3_column_int(stmt, index++));
				fetchedProduct.setGpu((char*)sqlite3_column_text(stmt, index++));
				int availability = sqlite3_column_int(stmt, 17);
				sqlite3_finalize(stmt);
				Availability avail(fetchedProduct, availability);
				products.push_back(avail);
			}
			if (res == SQLITE_DONE || res == SQLITE_ERROR)
			{
				break;
			}
		}
	}
	return products;
}

vector<Availability> ProductDAO::fetchAllSmartphonesFromDB() {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return vector<Availability>();
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;
	vector <Availability> products;

	szSQL = "SELECT * from products where TYPE=1";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int res = 0;

		while (1) {
			res = sqlite3_step(stmt);
			if (res == SQLITE_ROW) {
				int index = 3;
				Smartphone fetchedProduct = Smartphone();
				fetchedProduct.setPrice(sqlite3_column_double(stmt, index++));
				fetchedProduct.setModel((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, index++));
				//Skip PC product properties
				index = 13;
				fetchedProduct.setScreenSize(sqlite3_column_double(stmt, index++));
				fetchedProduct.setBatteryLife(sqlite3_column_int(stmt, index++));
				fetchedProduct.setCanRecord4k(sqlite3_column_int(stmt, index++));
				int availability = sqlite3_column_int(stmt, 17);
				sqlite3_finalize(stmt);
				Availability avail(fetchedProduct, availability);
				products.push_back(avail);
			}
			if (res == SQLITE_DONE || res == SQLITE_ERROR)
			{
				break;
			}
		}
	}
	return products;
}

vector<Availability> ProductDAO::fetchAllTVsFromDB() {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return vector<Availability>();
	}

	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;
	vector <Availability> products;

	szSQL = "SELECT * from products where TYPE=1";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int res = 0;

		while (1) {
			res = sqlite3_step(stmt);
			if (res == SQLITE_ROW) {
				int index = 3;
				TV fetchedProduct = TV();
				fetchedProduct.setPrice(sqlite3_column_double(stmt, index++));
				fetchedProduct.setModel((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, index++));
				fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, index++));
				//Skip PC product properties
				index = 13;
				fetchedProduct.setScreenSize(sqlite3_column_double(stmt, index++));
				//Skip Smartphone product properties
				index = 16;
				fetchedProduct.setCanShow3d(sqlite3_column_int(stmt, index++));
				int availability = sqlite3_column_int(stmt, 17);
				sqlite3_finalize(stmt);
				Availability avail(fetchedProduct, availability);
				products.push_back(avail);
			}
			if (res == SQLITE_DONE || res == SQLITE_ERROR)
			{
				break;
			}
		}
	}
	return products;
}