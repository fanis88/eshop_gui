#pragma once
#include "ProductBase.h"

class PC : public ProductBase {
public:
	int getRam() const;
	double getCpu() const;
	char* getDiskType() const;
	int getDiskSpace() const;
	char* getGpu() const;
	void setRam(int ram);
	void setCpu(double cpu);
	void setDiskType(char* diskType);
	void setDiskSpace(int diskSpace);
	void setGpu(char* gpu);
private:
	int ram;
	double cpu;
	char* diskType;
	int diskSpace;
	char* gpu;
};
