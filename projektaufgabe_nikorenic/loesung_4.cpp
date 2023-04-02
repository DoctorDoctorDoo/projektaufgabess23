#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iomanip>

template <typename Map>
void print_frequencies_sorted(const Map& map) {
    std::vector<std::pair<typename Map::key_type, typename Map::mapped_type>> pairs(map.begin(), map.end());

    std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2) {
        return p1.second > p2.second;
    });
    //Gesamtanzahl
    typename Map::mapped_type total_count = 0;
    for (const auto& [key, count] : map) {
        total_count += count;
    }

    std::cout << "Eintrag\tRelative Häufigkeit\n";
    for (const auto& [key, count] : pairs) {
        double relative_frequency = static_cast<double>(count) / total_count;
        std::cout << key << "\t" << std::fixed << std::setprecision(4) << relative_frequency << "\n";
    }
}