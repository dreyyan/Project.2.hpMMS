#include "stats.h"

// Default Constructor
Stats::Stats() : total_items_added(0), total_sales(0) {}
// Parameterized Constructor
Stats::Stats(int total_items_added, double total_sales)
    : total_items_added(total_items_added), total_sales(total_sales) {}

// Getters
int Stats::get_total_items_added() const {
    return total_items_added;
}
double Stats::get_total_sales() const {
    return total_sales;
}
// Setters
void Stats::add_items(int n) {
    total_items_added += n;
}

void Stats::add_sales(double amount) {
    total_sales += amount;
}

void Stats::display_stats() const {
    std::cout << "Total Items: " << total_items_added << '\n';
    std::cout << "Total Sales: $" << total_sales << '\n';
}