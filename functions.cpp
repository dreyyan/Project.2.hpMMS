#include "GUI.h"
#include "functions.h"

void add_items() {
    std::cout << "* adding items...\n";
}

void remove_items() {
    std::cout << "* removing items...\n";
}

void view_tables() {
    std::cout << "* viewing tables...\n";
}

void display_statistics() {
    std::cout << "* displaying statistics...\n";
}

void exit_main_menu() {
    char choice;
    std::cout << "* exiting main menu...\n";

    // Ask User for Confirmation to Exit
    std::cout << "are you sure you want to exit[y/n]?: ";
    std::cin >> std::ws;
    std::cin.get(choice);

    clear_screen();
    if (choice == 'y') {
        std::cout << "program exited successfully.";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        exit(0);
    } else {
        std::cout << "aborting exit...\n";
    }
}