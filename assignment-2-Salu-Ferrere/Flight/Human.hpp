#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>

/*
The Human class is a base class for all other subclasses. It defines the interface
which Human must implement, and provides some basic functionality all Human classes will need.
*/
class Human {
private:
protected:
	std::string name;
public:
	Human(const std::string &name);
    virtual ~Human();
    virtual std::string getName() const;
};

#endif
