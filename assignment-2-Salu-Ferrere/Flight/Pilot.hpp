#ifndef PILOT_HPP
#define PILOT_HPP

#include "Employee.hpp"

class Pilot : public Employee {
public:
    enum Level {
        CO_PILOT,
        CAPTAIN
    };

    Pilot(const std::string &name, int ID);
    Level getLevel() const;
    bool promote();
    bool demote();
    Level level;

private:
    Pilot& operator=(const Pilot& other);
    Pilot(const Pilot& other);
};

#endif
