#include <iostream>
#ifndef STATS_H
#define STATS_H
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
    // Methods
    void display_stats() const;
};
#endif //STATS_H
