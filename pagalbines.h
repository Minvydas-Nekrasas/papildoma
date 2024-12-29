#ifndef PAGALBINES_H
#define PAGALBINES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string normalize_word(const string& word);
void create_cross_reference(const string& input_filename, const string& output_filename);

#endif