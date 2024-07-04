#include <iostream>
#include <map>
#include <string>

bool isAnagram(const std::string& first_word, const std::string& second_word) {
    if (first_word.length() != second_word.length()) {
        return false;
    }

    std::map<char, int> char_count;

    // Подсчет количества каждой буквы в первой строке
    for (char c : first_word) {
        char_count[c]++;
    }

    // Уменьшение счетчика на основе второй строки
    for (char c : second_word) {
        if (char_count[c] == 0) {
            return false; // Если буква встречается больше раз, чем в первой строке
        }
        char_count[c]--;
    }

    // Проверка, что все значения в map равны 0
    for (auto count : char_count) {
        if (count.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string first_word;
    std::cout << "Enter a first word: ";
    std::cin >> first_word;
    std::string second_word;
    std::cout << "Enter a second word: ";
    std::cin >> second_word;

    if (isAnagram(first_word, second_word)) {
        std::cout << "The words are anagrams.\n";
    }
    else {
        std::cout << "The words are not anagrams.\n";
    }

    return 0;
}
