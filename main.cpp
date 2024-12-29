#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>

// Funkcija normalizuoti žodžius (pašalina skyrybos ženklus, paverčia mažosiomis raidėmis)
std::string normalize_word(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (std::isalnum(c)) { // Palikti tik raidinius ir skaitmeninius simbolius
            result += std::tolower(c);
        }
    }
    return result;
}

// Papildoma funkcija: sukuria kryžminės nuorodos lentelę
void create_cross_reference(const std::string& input_filename, const std::string& output_filename) {
    std::ifstream input(input_filename);
    if (!input) {
        std::cerr << "Nepavyko atidaryti failo " << input_filename << "\n";
        return;
    }

    std::map<std::string, std::set<int>> word_lines;
    std::map<std::string, int> word_count;
    std::string line;
    int line_number = 0;

    // Skaityti tekstą eilutė po eilutės
    while (std::getline(input, line)) {
        line_number++;
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            std::string normalized = normalize_word(word);
            if (!normalized.empty()) {
                word_lines[normalized].insert(line_number);
                word_count[normalized]++;
            }
        }
    }

    input.close();

    // Išvesti kryžminę nuorodų lentelę į failą
    std::ofstream output(output_filename);
    if (!output) {
        std::cerr << "Nepavyko sukurti failo " << output_filename << "\n";
        return;
    }

    for (const auto& [word, lines] : word_lines) {
        if (word_count[word] > 1) { // Filtruoti tik tuos žodžius, kurie pasikartoja daugiau nei 1 kartą
            output << word << " (" << word_count[word] << " kartai): ";
            for (int line : lines) {
                output << line << " ";
            }
            output << "\n";
        }
    }

    output.close();
    std::cout << "Kryžminės nuorodos lentelė išsaugota faile " << output_filename << "\n";
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

    // Sukurti kryžminės nuorodos lentelę
    create_cross_reference("tekstas.txt", "cross_reference.txt");

    return 0;
}
