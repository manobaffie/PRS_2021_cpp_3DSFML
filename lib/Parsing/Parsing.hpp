#include <vector>
#include <iostream>
#include <fstream>

class Parsing
{
    private:
    public:
        Parsing() = default;
        ~Parsing();

        static std::vector<std::string> SplitString(std::string str, std::string split);
};

