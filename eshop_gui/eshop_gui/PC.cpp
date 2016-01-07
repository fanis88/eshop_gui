#include "pch.h"
#include "PC.h"

int PC::getRam() const {
	return this->ram;
}

double PC::getCpu() const {
	return this->cpu;
}

char* PC::getDiskType() const {
	return this->diskType;
}

int PC::getDiskSpace() const {
	return this->diskSpace;
}

char* PC::getGpu() const {
	return this->gpu;
}

void PC::setRam(int ram) {
	this->ram = ram;
}

void PC::setCpu(double cpu) {
	this->cpu = cpu;
}

void PC::setDiskType(char* diskType) {
	this->diskType = diskType;
}

void PC::setDiskSpace(int diskSpace) {
	this->diskSpace = diskSpace;
}

void PC::setGpu(char* gpu) {
	this->gpu = gpu;
}