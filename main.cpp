#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

std::string normalize_word(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (std::isalnum(c)) { // Palikti tik raidinius ir skaitmeninius simbolius
            result += std::tolower(c);
        }
    }
    return result;
}

int main() {
    std::ifstream input("tekstas.txt");
    if (!input) {
        std::cerr << "Nepavyko atidaryti failo tekstas.txt\n";
        return 1;
    }

    std::map<std::string, int> word_count;
    std::string line, word;

    // Skaityti tekstą eilutė po eilutės
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        while (iss >> word) {
            std::string normalized = normalize_word(word);
            if (!normalized.empty()) {
                word_count[normalized]++;
            }
        }
    }

    input.close();

    // Filtruoti ir išvesti žodžius, pasikartojančius daugiau nei 1 kartą
    std::ofstream output("rezultatai.txt");
    if (!output) {
        std::cerr << "Nepavyko sukurti failo rezultatai.txt\n";
        return 1;
    }

    for (const auto& [word, count] : word_count) {
        if (count > 1) {
            output << word << ": " << count << "\n";
        }
    }

    output.close();

    std::cout << "Rezultatai išsaugoti faile rezultatai.txt\n";
    return 0;
}
