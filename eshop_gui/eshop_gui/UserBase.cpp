#include "pch.h"
#include "UserBase.h"

UserBase::UserBase() {
}

UserBase::UserBase(char* username, char* password) {
	this->username = username;
	this->password = password;
}

char* UserBase::getUsername() {
	return username;
}

char* UserBase::getPassword() {
	return password;
}

void UserBase::setUsername(char* username) {
	this->username = username;
}

void UserBase::setPassword(char* password) {
	this->password = password;
}