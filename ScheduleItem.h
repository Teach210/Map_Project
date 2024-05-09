#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <utility>

class ScheduleItem {
private:
    std::string subject;
    std::string catalog;
    std::string section;
    std::string component;
    std::string session;
    int units;
    int totEnrl;
    int capEnrl;
    std::string instructor;

public:
    // Constructor with default parameters
    ScheduleItem(std::string subj = "", std::string cat = "", std::string sec = "", std::string comp = "", std::string sess = "",
        int units = 0, int totEnrl = 0, int capEnrl = 0, std::string instr = "") :
        subject(subj), catalog(cat), section(sec), component(comp), session(sess),
        units(units), totEnrl(totEnrl), capEnrl(capEnrl), instructor(instr) {}

    // Get functions
    std::string getSubject() const { return subject; }
    std::string getCatalog() const { return catalog; }
    std::string getSection() const { return section; }
    std::string getComponent() const { return component; }
    std::string getSession() const { return session; }
    int getUnits() const { return units; }
    int getTotEnrl() const { return totEnrl; }
    int getCapEnrl() const { return capEnrl; }
    std::string getInstructor() const { return instructor; }

    // Overloading comparison operators
    bool operator==(const ScheduleItem& other) const {
        return (subject == other.subject && catalog == other.catalog && section == other.section);
    }

    bool operator!=(const ScheduleItem& other) const {
        return !(*this == other);
    }

    bool operator>=(const ScheduleItem& other) const {
        return (subject >= other.subject && catalog >= other.catalog && section >= other.section);
    }

    // Print function
    void print() const {
        std::cout << subject << "\t" << catalog << "\t" << section << "\t" << component << "\t"
            << session << "\t" << units << "\t" << totEnrl << "\t" << capEnrl << "\t"
            << instructor << std::endl;
    }
};