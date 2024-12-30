#include "pagalbines.h"

// Funkcija normalizuoti žodžius (pašalina skyrybos ženklus, paverčia mažosiomis raidėmis)
string normalize_word(const string& word) {
    string result;
    for (char c : word) {
        if (isalnum(c)) { // Palikti tik raidinius ir skaitmeninius simbolius
            result += tolower(c);
        }
    }
    return result;
}

// Papildoma funkcija: sukuria kryžminės nuorodos lentelę
void create_cross_reference(const string& input_filename, const string& output_filename) {
    ifstream input(input_filename);
    if (!input) {
        cerr << "Nepavyko atidaryti failo " << input_filename << "\n";
        return;
    }

    map<string, set<int>> word_lines;
    map<string, int> word_count;
    string line;
    int line_number = 0;

    // Skaityti tekstą eilutė po eilutės
    while (getline(input, line)) {
        line_number++;
        istringstream iss(line);
        string word;

        while (iss >> word) {
            string normalized = normalize_word(word);
            if (!normalized.empty()) {
                word_lines[normalized].insert(line_number);
                word_count[normalized]++;
            }
        }
    }

    input.close();

    // Išvesti kryžminę nuorodų lentelę į failą
    ofstream output(output_filename);
    if (!output) {
        cerr << "Nepavyko sukurti failo " << output_filename << "\n";
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
    cout << "Kryžminės nuorodos lentelė išsaugota faile " << output_filename << "\n";
}
// Funkcija URL'ų paieškai tekste
vector<string> find_urls(const string& text) {
    vector<string> urls;
    // Reguliarioji išraiška URL atpažinimui
    regex url_pattern(R"((https?://[^\s/$.?#].[^\s]*)|((www\.)?[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})(/[^ \n]*)?)");
    sregex_iterator current_match(text.begin(), text.end(), url_pattern);
    sregex_iterator last_match;

    while (current_match != last_match) {
        smatch match = *current_match;
        urls.push_back(match.str());
        current_match++;
    }

    return urls;
}

// Funkcija rasti URL failo turinyje ir išvesti į kitą failą
void extract_urls_from_file(const string& input_filename, const string& output_filename) {
    ifstream input(input_filename);
    if (!input) {
        cerr << "Nepavyko atidaryti failo " << input_filename << "\n";
        return;
    }

    ostringstream buffer;
    buffer << input.rdbuf(); // Perskaityti visą failo turinį į eilutę
    string text = buffer.str();
    input.close();

    // Rasti URL adresus
    vector<string> urls = find_urls(text);

    // Išvesti URL adresus į failą
    ofstream output(output_filename);
    if (!output) {
        cerr << "Nepavyko sukurti failo " << output_filename << "\n";
        return;
    }

    for (const string& url : urls) {
        output << url << "\n";
    }

    output.close();
    cout << "URL adresai išsaugoti faile " << output_filename << "\n";
}