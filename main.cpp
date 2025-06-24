#include <iostream>
#include <vector>
#include <limits>
#include "Mystring.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getIntInput(const std::string &prompt, int min = 0, int max = std::numeric_limits<int>::max()) {
    int n;
    while (true) {
        std::cout << prompt;
        if (std::cin >> n && n >= min && n <= max) {
            clearInput();
            return n;
        } else {
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
            clearInput();
        }
    }
}

void printMenu() {
    std::cout << "\n=== Mystring Operations Menu ===\n"
              << "1. Add new string\n"
              << "2. List all strings\n"
              << "3. Convert a string to lowercase (-s)\n"
              << "4. Convert a string to uppercase (+s)\n"
              << "5. Concatenate two strings (new string)\n"
              << "6. Append one string to another (s1 += s2)\n"
              << "7. Repeat a string N times (new string)\n"
              << "8. Repeat a string N times in place (s *= N)\n"
              << "9. Compare two strings (==, !=, <, >)\n"
              << "10. Pre-increment a string (++s)\n"
              << "11. Post-increment a string (s++)\n"
              << "12. Delete a string\n"
              << "13. Quit\n"
              << "Choose an option: ";
}

void listStrings(const std::vector<Mystring> &vec) {
    std::cout << "\nStored strings:\n";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "[" << i << "]: " << vec[i] << " (length: " << vec[i].get_length() << ")\n";
    }
    if (vec.empty()) std::cout << "No strings stored yet.\n";
}

int main() {
    std::vector<Mystring> strings;
    bool running = true;

    while (running) {
        printMenu();
        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 13.\n";
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1: {
                std::cout << "Enter a new string: ";
                Mystring new_str;
                std::cin >> new_str;
                strings.push_back(new_str);
                std::cout << "String added. Total strings: " << strings.size() << "\n";
                break;
            }
            case 2: {
                listStrings(strings);
                break;
            }
            case 3: {
                if (strings.empty()) {
                    std::cout << "No strings to modify.\n";
                    break;
                }
                int idx = getIntInput("Enter index of string to convert to lowercase: ", 0, strings.size() - 1);
                strings[idx] = -strings[idx];
                std::cout << "Modified string: " << strings[idx] << "\n";
                break;
            }
            case 4: {
                if (strings.empty()) {
                    std::cout << "No strings to modify.\n";
                    break;
                }
                int idx = getIntInput("Enter index of string to convert to uppercase: ", 0, strings.size() - 1);
                strings[idx] = +strings[idx];
                std::cout << "Modified string: " << strings[idx] << "\n";
                break;
            }
            case 5: {
                if (strings.size() < 2) {
                    std::cout << "Need at least two strings to concatenate.\n";
                    break;
                }
                int idx1 = getIntInput("Enter index of first string: ", 0, strings.size() - 1);
                int idx2 = getIntInput("Enter index of second string: ", 0, strings.size() - 1);
                Mystring result = strings[idx1] + strings[idx2];
                std::cout << "Result of concatenation: " << result << "\n";
                break;
            }
            case 6: {
                if (strings.size() < 2) {
                    std::cout << "Need at least two strings to append.\n";
                    break;
                }
                int idx1 = getIntInput("Enter index of string to append to (s1): ", 0, strings.size() - 1);
                int idx2 = getIntInput("Enter index of string to append (s2): ", 0, strings.size() - 1);
                strings[idx1] += strings[idx2];
                std::cout << "After appending, s1: " << strings[idx1] << "\n";
                break;
            }
            case 7: {
                if (strings.empty()) {
                    std::cout << "No strings to repeat.\n";
                    break;
                }
                int idx = getIntInput("Enter index of string to repeat: ", 0, strings.size() - 1);
                int n = getIntInput("Enter repeat count: ", 0);
                Mystring result = strings[idx] * n;
                std::cout << "Repeated string: " << result << "\n";
                break;
            }
            case 8: {
                if (strings.empty()) {
                    std::cout << "No strings to repeat.\n";
                    break;
                }
                int idx = getIntInput("Enter index of string to repeat in place: ", 0, strings.size() - 1);
                int n = getIntInput("Enter repeat count: ", 0);
                strings[idx] *= n;
                std::cout << "After repeating in place: " << strings[idx] << "\n";
                break;
            }
            case 9: {
                if (strings.size() < 2) {
                    std::cout << "Need at least two strings to compare.\n";
                    break;
                }
                int idx1 = getIntInput("Enter index of first string: ", 0, strings.size() - 1);
                int idx2 = getIntInput("Enter index of second string: ", 0, strings.size() - 1);
                std::cout << std::boolalpha;
                std::cout << "s1 == s2: " << (strings[idx1] == strings[idx2]) << "\n";
                std::cout << "s1 != s2: " << (strings[idx1] != strings[idx2]) << "\n";
                std::cout << "s1 < s2: " << (strings[idx1] < strings[idx2]) << "\n";
                std::cout << "s1 > s2: " << (strings[idx1] > strings[idx2]) << "\n";
                break;
            }
            case 10: {
                if (strings.empty()) {
                    std::cout << "No strings to increment.\n";
                    break;
                }
                int idx = getIntInput("Enter index of string for pre-increment (++s): ", 0, strings.size() - 1);
                ++strings[idx];
                std::cout << "After pre-increment: " << strings[idx] << "\n";
                break;
            }
            case 11: {
                if (strings.empty()) {
                    std::cout << "No strings to increment.\n";
                    break;
                }
                int idx = getIntInput("Enter index of string for post-increment (s++): ", 0, strings.size() - 1);
                Mystring old_val = strings[idx]++;
                std::cout << "Value before post-increment: " << old_val << "\n";
                std::cout << "Value after post-increment: " << strings[idx] << "\n";
                break;
            }
            case 12: {
                if (strings.empty()) {
                    std::cout << "No strings to delete.\n";
                    break;
                }
                int idx = getIntInput("Enter index of string to delete: ", 0, strings.size() - 1);
                strings.erase(strings.begin() + idx);
                std::cout << "String deleted. Total strings: " << strings.size() << "\n";
                break;
            }
            case 13: {
                std::cout << "Exiting program.\n";
                running = false;
                break;
            }
            default:
                std::cout << "Invalid choice, please select 1-13.\n";
        }
    }

    return 0;
}
