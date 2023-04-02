#include <iostream>
#include <vector>
class Histogram
{
public:
    Histogram();
    void insert(double x);
    unsigned int size() const;
    double min() const;
    double max() const;
    void print(unsigned int bin_count);
    void print_normalized(unsigned int bin_count);

private:
    std::vector<double> data_;
};
