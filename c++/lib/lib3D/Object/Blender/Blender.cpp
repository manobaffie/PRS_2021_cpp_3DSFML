#include "Blender.hpp"

Blender::Blender(const std::string &path)
{
    this->load(path);

    // for (vec::vector3d i : this->points) {
    //     std::cout << i << std::endl;
    // }
    // std::cout << " ==== ==== " << std::endl;

    // for (std::vector<int> i : this->links) {
    //     for (int j : i)
    //         std::cout << j << "\t";
    //     std::cout << std::endl << "---" << std::endl;
    // }
}

Blender::~Blender()
{
}

void Blender::load(const std::string &path)
{
    std::ifstream infile(path);

    if (infile.fail()) {
        std::cerr << "[Error] -> can't open Blender File" << std::endl;
        return;
    }
    std::cout << "Blender object : " << path << std::endl;

    std::string line;
    while (std::getline(infile, line)) {
        const std::vector<std::string> splitLine = Parsing::SplitString(line, " ");

        if (splitLine[0] == "v")
            this->setPoints(splitLine);
        if (splitLine[0] == "f")
            this->setLinks(splitLine);
    }
    infile.close();
}

void Blender::setPoints(const std::vector<std::string> &splitLine)
{
    this->points.push_back({
        .x = std::atof(splitLine[3].c_str()),
        .y = std::atof(splitLine[2].c_str()),
        .z = std::atof(splitLine[1].c_str())
    });
}

void Blender::setLinks(const std::vector<std::string> &splitLine)
{
    std::vector<int> shape;
    for (size_t i = 1; i < splitLine.size(); i++) {
        shape.push_back(std::atoi(Parsing::SplitString(splitLine[i], "/")[0].c_str()));
    }
    this->links.push_back(shape);
}
