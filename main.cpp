#include "pagalbines.h"

int main() {
    ifstream input("tekstas.txt");
    if (!input) {
        cerr << "Nepavyko atidaryti failo tekstas.txt\n";
        return 1;
    }

    map<string, int> word_count;
    string line, word;

    // Skaityti tekstą eilutė po eilutės
    while (getline(input, line)) {
        istringstream iss(line);
        while (iss >> word) {
            string normalized = normalize_word(word);
            if (!normalized.empty()) {
                word_count[normalized]++;
            }
        }
    }

    input.close();

    // Filtruoti ir išvesti žodžius, pasikartojančius daugiau nei 1 kartą
    ofstream output("rezultatai.txt");
    if (!output) {
        cerr << "Nepavyko sukurti failo rezultatai.txt\n";
        return 1;
    }

    for (const auto& [word, count] : word_count) {
        if (count > 1) {
            output << word << ": " << count << "\n";
        }
    }

    output.close();
    cout << "Rezultatai išsaugoti faile rezultatai.txt\n";

    // Sukurti kryžminės nuorodos lentelę
    create_cross_reference("tekstas.txt", "cross_reference.txt");

    return 0;
}
