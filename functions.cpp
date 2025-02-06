#include "GUI.h"
#include "functions.h"
#include "stats.h"

std::string convert_string_to_lowercase(std::string& word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

void add_item() {
    std::cout << "* adding item...\n";
    int item_choice;

    // Prompt User to Enter Item's Category
    while (true) {
        // Display List of Categories
        Stats::display_categories();
        // Prompt User to Enter Category of Choice
        std::cout << ">> ";
        std::cin >> item_choice;
    }
    // Prompt User to Enter Item's Name
    // Prompt User to Enter Item's Price
}

void add_items() {
    std::cout << "* adding items...\n";
}

void remove_item() {
    std::cout << "* removing item...\n";
}

void remove_items() {
    std::cout << "* removing items...\n";
}

void manage_items() {
    std::cout << "* managing items...\n";
    std::string choice;
    std::string add_or_remove, item_or_items;
    bool valid_choice;

    do {
        valid_choice = true;
        // Prompt User to Enter Command According to Format
        std::cout << "Format: add/remove item/s\n";
        std::cout << ">> ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, choice);
        choice = convert_string_to_lowercase(choice); // Only Accept Lowercase Input

        // Separate Words to Check Validity of Command
        std::istringstream ss(choice);
        ss >> add_or_remove >> item_or_items;

        if (add_or_remove == "add") {
            if (item_or_items == "items") {
                add_items();
            } else if (item_or_items == "item") {
                add_item();
            } else { valid_choice = false; }
        } else if (add_or_remove == "remove") {
            if (item_or_items == "items") {
                remove_items();
            } else if (item_or_items == "item") {
                remove_item();
            } else { valid_choice = false; }
        } else { valid_choice = false; }

        if (!valid_choice) { clear_screen(); std::cerr << "[ ERROR | Invalid Command ]\n"; }
    } while (!valid_choice);
}

void add_category() {
    std::string input_category;
    bool unique_category;

    while (true) {
        unique_category = true;
        // Prompt User to Enter Category Name
        std::cout << "Category: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, input_category);

        for (const auto& category : categories_list) {
            if (category.second == input_category) {
                unique_category = false;
                std::cerr << "[ ERROR | Category already exists ]\n";
                break;
            }
        }

        if (unique_category) break;
    }

    categories_list[++category_count] = input_category;
    std::cout << "* category added\n";
}

void remove_category() {
    // Prompt User to Enter Category Name
}

void manage_categories() {
    std::cout << "* managing categories...\n";
    display_header();
    int choice;
    std::string add_or_remove;
    bool valid_choice;

    while (true) {
        valid_choice = true;
        // Prompt User to Enter Command According to Format
        Stats::display_categories();
        std::cout << "[1] | Add\n";
        std::cout << "[2] | Remove\n";
        display_format(20);
        std::cout << ">> ";
        std::cin.ignore();
        std::cin >> choice;

        if (choice == 1 || choice == 2) break;
        clear_screen();
        std::cin.clear();
        std::cin.ignore();
        std::cerr << "[ ERROR | Invalid Number ]\n";
    }

    clear_screen();
    Stats::display_categories();
    if (choice == 1) { add_category(); }
    else { remove_category(); }
}

void view_tables() {
    std::cout << "* viewing tables...\n";
    display_header();
}

void display_statistics() {
    std::cout << "* displaying statistics...\n";
    display_header();
}

void exit_main_menu() {
    char choice;
    std::cout << "* exiting main menu...\n";
    display_header();

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