#include <iostream>
#include <map>
#include <vector>
#ifndef STATS_H
#define STATS_H

// Public Statistics
static std::map<int, std::string> categories_list;
static int category_count = 0;

class Stats {
    // Attributes
    int total_items_added;
    double total_sales;
public:
    // Constructors
    Stats();
    Stats(int total_items_added, double total_sales);
    // Getters
    int get_total_items_added() const;
    double get_total_sales() const;
    // Setters
    void add_items(int n);
    void add_sales(double amount);
    void add_category(std::string& category);
    // Methods
    void display_stats() const;
    static void display_categories();
};

#endif //STATS_H
