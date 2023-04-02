#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>  /
#include <iomanip>
#include <unordered_map>

std::string sanitize_word(const std::string& word) {
    std::string sanitized;
    std::transform(word.begin(), word.end(), std::back_inserter(sanitized), [](char c) {
        if (std::isalpha(c)) {
            return std::toupper(c);
        }
        return 0;
    });
    sanitized.erase(std::remove_if(sanitized.begin(), sanitized.end(), isspace), sanitized.end());
    return sanitized;
}

std::map<std::string, int> get_frequencies() {
    std::map<std::string, int> frequency_map;
    std::string word;

    while (std::cin >> word) {
        word = sanitize_word(word);
        if (word.empty()) {
            continue;
        }
        frequency_map[word]++;
    }

    return frequency_map;
}

int main() {
    std::map<std::string, int> frequency_map = get_frequencies();

    std::cout << "Häufigkeiten:\n";
    for (const auto& [word, count] : frequency_map) {
        std::cout << word << ": " << count << "\n";
    }

    return 0;
}
void print_frequencies(const std::map<std::string, int>& frequencies) {
    int total_count = 0;
    for (const auto& [word, count] : frequencies) {
        total_count += count;
    }

    std::cout << "Wort\tRelative Häufigkeit\n";
    for (const auto& [word, count] : frequencies) {
        double relative_frequency = static_cast<double>(count) / total_count;
        std::cout << word << "\t" << std::fixed << std::setprecision(4) << relative_frequency << "\n";
    }
}

