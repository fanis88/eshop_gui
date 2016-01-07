#pragma once
using namespace std;

class ProductBase
{
public:
	ProductBase();
	int getSerial() const;
	char* getModel();
	char* getManufacturer();
	char* getPhotoUrl();
	char* getDescription();
	double getPrice();
	void setSerial(int serial);
	void setModel(char* model);
	void setManufacturer(char* manufacturer);
	void setPhotoUrl(char* photoUrl);
	void setDescription(char* description);
	void setPrice(double price);
	bool operator== (const ProductBase &p2) const;
	bool operator< (const ProductBase &p2) const;
	bool operator> (const ProductBase &p2) const;
private:
	int serial;
	char* model;
	char* manufacturer;
	char* photoUrl;
	char* description;
	double price;
};

