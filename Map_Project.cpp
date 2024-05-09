#include <iostream>
#include "ScheduleItem.h"
#include "Schedule.h"

int main()
{
    // Declare Schedule object
    Schedule schedule;
    // Open data file
    std::ifstream file("STEM - Summer 2022 Schedule of Classes as of 05-02-22(1).csv");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    // Initialize schedule from file
    schedule.initSchedule(file);
    file.close();

    // Menu loop
    int choice;
    do {
        std::cout << "\n1. Print schedule\n"
            "2. Find by subject\n"
            "3. Find by subject and catalog\n"
            "4. Find by instructor's last name\n"
            "5. Exit\n"
            "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            schedule.print();
            break;
        case 2: {
            std::string subject;
            std::cout << "Enter subject: ";
            std::cin >> subject;
            schedule.findBySubject(subject);
            break;
        }
        case 3: {
            std::string subject, catalog;
            std::cout << "Enter subject: ";
            std::cin >> subject;
            std::cout << "Enter catalog: ";
            std::cin >> catalog;
            schedule.findBySubjectAndCatalog(subject, catalog);
            break;
        }
        case 4: {
            std::string lastName;
            std::cout << "Enter instructor's last name: ";
            std::cin >> lastName;
            schedule.findByInstructor(lastName);
            break;
        }
        case 5:
            std::cout << "Exiting...";
            break;
        default:
            std::cout << "Invalid choice. Please try again.";
        }
    } while (choice != 5);

    return 0;
}
