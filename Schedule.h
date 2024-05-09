#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iterator>
#include <utility>
#include <string>
#include <stdexcept>

class Schedule {
private:
    std::map<std::string, ScheduleItem> scheduleMap;

public:
    // Function to initialize schedule from file
    void initSchedule(std::ifstream& file) {
        // Skip header line
        std::string header;
        std::getline(file, header);

        // Read data and insert into map
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string subj, cat, sec, comp, sess, instr, minUnits, units, totEnrl, capEnrl, acadOrg;
            // Read data from stringstream using comma as delimiter
            if (std::getline(iss, subj, ',') &&
                std::getline(iss, cat, ',') &&
                std::getline(iss, sec, ',') &&
                std::getline(iss, comp, ',') &&
                std::getline(iss, sess, ',') &&
                std::getline(iss, minUnits, ',') &&
                std::getline(iss, units, ',') &&
                std::getline(iss, totEnrl, ',') &&
                std::getline(iss, capEnrl, ',') &&
                std::getline(iss, acadOrg, ',')) {
                // Read the instructor name directly without quotes
                std::getline(iss, instr, '"');
                std::getline(iss, instr, '"');

                // Remove surrounding quotes from instructor name if present
                if (!instr.empty() && instr.front() == '"' && instr.back() == '"') {
                    instr = instr.substr(1, instr.size() - 2);
                }
                // Create ScheduleItem object
                ScheduleItem item(subj, cat, sec, comp, sess, stoi(units), stoi(totEnrl), stoi(capEnrl), instr);
                // Insert into map
                scheduleMap[subj + "_" + cat + "_" + sec] = item;
            }
            else {
                std::cerr << "Error reading line from file." << std::endl;
            }

        }
    }


    // Function to print schedule
    void print() const {
        // Iterate through the map and print each item
        for (auto const& pair : scheduleMap) {
            pair.second.print();
        }
    }

    // Function to find and print all records with a target subject
    void findBySubject(const std::string& targetSubject) const {
        for (auto const& pair : scheduleMap) {
            if (pair.second.getSubject() == targetSubject) {
                pair.second.print();
            }
        }
    }

    // Function to find and print all records with a target subject and catalog number
    void findBySubjectAndCatalog(const std::string& targetSubject, const std::string& targetCatalog) const {
        for (auto const& pair : scheduleMap) {
            if (pair.second.getSubject() == targetSubject && pair.second.getCatalog() == targetCatalog) {
                pair.second.print();
            }
        }
    }

    // Function to find and print all records given the instructor’s last name
    void findByInstructor(const std::string& instructorLastName) const {
        for (auto const& pair : scheduleMap) {
            std::string instructor = pair.second.getInstructor();
            size_t found = instructor.find_last_of(",");
            if (found != std::string::npos && instructor.substr(0, found) == instructorLastName) {
                pair.second.print();
            }
        }
    }
};