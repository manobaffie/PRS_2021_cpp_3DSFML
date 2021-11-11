#include "Parsing.hpp"

std::vector<std::string> Parsing::SplitString(std::string str, std::string split)
{
    std::vector<std::string> output;
    size_t pos = 0;

    while ((pos = str.find(split)) != std::string::npos) {
        output.push_back(str.substr(0, pos));
        str.erase(0, pos + split.length());
    }
    output.push_back(str);

    return (output);
}