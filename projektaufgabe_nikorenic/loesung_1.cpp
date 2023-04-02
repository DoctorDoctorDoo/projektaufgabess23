#include "loesung_1.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

Histogram::Histogram() {}

void Histogram::insert(double x) {
    data_.push_back(x);
}

unsigned int Histogram::size() const {
    return data_.size();
}

double Histogram::min() const {
    return *std::min_element(data_.begin(), data_.end());
}

double Histogram::max() const {
    return *std::max_element(data_.begin(), data_.end());
}

void Histogram::print(unsigned int bin_count) {
    double range = max() - min();
    double bin_size = range / bin_count;
    std::vector<int> bins(bin_count, 0);

    for (double value : data_) {
        int bin_index = std::min(static_cast<int>(std::floor((value - min()) / bin_size)), static_cast<int>(bin_count - 1));
        bins[bin_index]++;
    }

    std::cout << "Histogram of " << size() << " entries, min = " << min() << ", max = " << max() << std::endl;
    for (int i = 0; i < bin_count; i++) {
        double bin_start = min() + i * bin_size;
        double bin_end = bin_start + bin_size;
        std::cout << bin_start << " -- " << bin_end << ": " << bins[i] << std::endl;
    }
}

void Histogram::print_normalized(unsigned int bin_count) {
    double range = max() - min();
    double bin_size = range / bin_count;
    std::vector<int> bins(bin_count, 0);

    for (double value : data_) {
        int bin_index = std::min(static_cast<int>(std::floor((value - min()) / bin_size)), static_cast<int>(bin_count - 1));
        bins[bin_index]++;
    }

    int sum = std::accumulate(bins.begin(), bins.end(), 0);

    std::cout << "Histogram of " << size() << " entries, min = " << min() << ", max = " << max() << std::endl;
    for (int i = 0; i < bin_count; i++) {
        double bin_start = min() + i * bin_size;
        double bin_end = bin_start + bin_size;
        double normalized_value = static_cast<double>(bins[i]) / sum;
        std::cout << bin_start << " -- " << bin_end << ": " << normalized_value << std::endl;
    }
}
