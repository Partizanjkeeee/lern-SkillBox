#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
	std::map<std::string, std::string> phone_to_name;
	std::map<std::string, std::vector<std::string>> name_to_phones;

	std::string line;
	
	while (std::getline(std::cin, line)) {
		size_t space_pos = line.find(' ');
		if (space_pos != std::string::npos) {
			//Запрос типа 1: добавление номера и фамилии
			std::string phone = line.substr(0, space_pos);
			std::string name = line.substr(space_pos + 1);
			phone_to_name[phone] = name;
			name_to_phones[name].push_back(phone);
		}
		else if (isdigit(line[0])) {
			//Запрос типа 2: поиск фамилии по номеру
			if (phone_to_name.find(line) != phone_to_name.end()) {
				std::cout << phone_to_name[line] << std::endl;
			}
			else {
				std::cout << "Nomber is not found!";
			}
		}
		else {
			//Запрос типа 3: поиск ноиеров по фамилии
			if (name_to_phones.find(line) != name_to_phones.end()) {
				for (const std::string& phone : name_to_phones[line]) {
					std::cout << phone << " ";
				}
			}
			else {
				std::cout << "Surname is not found!";
			}
		}
	}
}