#pragma once
using namespace std;

class UserBase {
public:
	UserBase();
	UserBase(char* username, char* password);
	char* getUsername();
	char* getPassword();
	void setUsername(char* username);
	void setPassword(char* password);
private:
	char* username;
	char* password;
};
