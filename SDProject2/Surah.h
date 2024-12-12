#ifndef SURAH_H
#define SURAH_H

#include <iostream>
#include <string>

class Surah
{
private:
    std::string name;
    std::string path;
    std::string type;

public:

    Surah(const std::string& name, const std::string& path, const std::string& type)
        : name(name), path(path), type(type) {
    }

    std::string getName() const
    {
        return name;
    }
    std::string getPath() const
    {
        return path;
    }
    std::string getType() const
    {
        return type;
    }

    void display() const
    {
        std::cout << "Name: " << getName() << ", Path: " << getPath() << ", Type: " << getType() << std::endl;
    }
};

#endif // SURAH_H
