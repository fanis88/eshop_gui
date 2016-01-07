#pragma once
#include "ProductBase.h"

class Smartphone : public ProductBase {
public:
	double getScreenSize() const;
	int getBatteryLife() const;
	bool getCanRecord4k() const;
	void setScreenSize(double screenSize);
	void setBatteryLife(int batteryLife);
	void setCanRecord4k(bool canRecord4k);
private:
	double screenSize;
	int batteryLife;
	bool canRecord4k;
};
