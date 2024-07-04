#include <iostream>
#include <map>
#include <string>
#include <algorithm>

struct Registry {
	std::map<std::string, int> surnameCount; //Значение int для того что бы корректно обрабатывать одинаковые фамилии.
	int order; //ПОрядок поступления пациетнов

	Registry() :order(0) {}

	//Добавление пациента
	void add_patient(const std::string& surname) {
		surnameCount[surname]++;
	}

	//Обработка запроса Next
	void next_patient() {
		if (surnameCount.empty()) {
			std::cout << "No patients in the queue" << std::endl;
			return;
		}
		auto it = surnameCount.begin();
		std::cout << "Next patiens: " << it->first << std::endl;

		if (it->second == 1) {
			surnameCount.erase(it);
		}
		else
			it->second--;
	}

	bool end_day(std::string& exit) {
		if (exit == "Exit" || exit == "exit") {
			return true;
		}
		return false;
	}
};

void show_patients(const std::map<std::string, int>& registry) {
	std::cout << "All patients who stay in queue: " << std::endl;
	for (const auto& entry : registry) {
		for (int i = 0; i < entry.second; ++i) {
			std::cout << "\n";
			std::cout << entry.first << std::endl;
		}
	}
	std::cout << std::endl;
}

int main() {
	Registry registry;
	std::string command;
	std::cout << "Enter a 'Next' to find out a who going in registry" << std::endl;
	std::cout << "Enter a 'Exit' to end programm." << std::endl;
	std::cout << "Enter a 'Show' to show a patients." << std::endl;
	std::cout << "Enter a name patient in queue" << std::endl;
	while (std::cin >> command) {
		// Приведение команды к нижнему регистру для единообразия
		std::string lower_command = command;
		std::transform(lower_command.begin(), lower_command.end(), lower_command.begin(), ::tolower);

		if (registry.end_day(command) == true) {
			std::cout << "The working day is over.";
			return 1;
		}
		if (lower_command == "next") {
			registry.next_patient();
		}
		else if (lower_command == "show") {
			show_patients(registry.surnameCount);
		}
		else {
			registry.add_patient(command);
		}
	}
}