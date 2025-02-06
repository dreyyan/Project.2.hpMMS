#include "GUI.h"
#include "functions.h"

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void display_format(size_t length) {
    for (size_t i = 0; i < length; ++i) {
        std::cout << '-';
    } std::cout << '\n';
}

void display_header() {
    std::cout << "------[ HAPPY PILL ]------\n";
    std::cout << "[ MENU MANAGEMENT SYSTEM ]\n";
    display_format(26);
}

void return_to_menu() {
    char choice;
    std::cout << "Return to Menu[y]?: ";
    std::cin >> std::ws;
    std::cin.get(choice);

    if (choice == 'y') {
        clear_screen(); return;
    } else { std::cout << "exiting program..."; exit(0); };
}

void display_main_menu() {
    while (true) {
        int choice;
        display_header();
        std::cout << "[1] || Manage Items\n";
        std::cout << "[2] || Manage Categories\n";
        std::cout << "[3] || View Table/s\n";
        std::cout << "[4] || Statistics\n";
        std::cout << "[5] || Exit\n";
        display_format(26);

        // Prompt User to Enter Choice
        std::cout << ">> ";
        std::cin >> choice;

        // ERROR: Input Failure
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cerr << "[ ERROR | Invalid Number ]\n";
        }

        clear_screen(); // Clear Screen Before Invoking Function/s
        // Invoke Function Based on Choice
        switch (choice) {
            case 1: manage_items(); break;
            case 2: manage_categories(); break;
            case 3: view_tables(); break;
            case 4: display_statistics(); break;
            case 5: exit_main_menu(); break;
            default: std::cerr << "[ ERROR | Invalid Number ]\n"; break;
        } return_to_menu();
    }
}
