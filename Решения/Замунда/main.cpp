#include<iostream>
#include<string>
#include"Zamunda.h"
using std::cin;
using std::cout;
using std::string;

int main() {
	
	Zamunda site;
	
	string command;
	
	while (command != "bye") {
		cin >> command;

		if (command == "login")
			site.login();

		else if (command == "logout")
			site.logout();

		else if (command == "download")
			site.download();
		
		else if (command == "upload")
			site.upload();
		
		else if (command == "remove")
			site.remove_banana();
		
		else if (command == "register")
			site.register_user();
		
		else if (command == "bye")
			cout << "Closing site.\n";
		
		else
			cout << "Invalid command.\n";
	}
	
	return 0;
}