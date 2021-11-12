#include "Blender.hpp"

Blender::Blender(const std::string &id, const std::string &path) :
Object(id), Path(path)
{
    this->parsing();
    this->LinkPoints();

    this->setObject();
}

Blender::~Blender()
{
}

void Blender::parsing()
{

    std::ifstream infile(this->Path);

    if (infile.fail()) {
        std::cerr << "[Error] -> can't open Blender File" << std::endl;
    }
    std::cout << "file : " << this->Path << std::endl;

    std::string line;


    while (std::getline(infile, line)) {
        std::vector<std::string> splitLine = Parsing::SplitString(line, " ");
        if (splitLine[0] == "v") {
            this->Points3D.push_back (
                Point3D_s::Create (
                    std::atof(splitLine[3].c_str()) * 100,
                    std::atof(splitLine[2].c_str()) * -100,
                    std::atof(splitLine[1].c_str()) * 100
                )
            );
        }
        if (splitLine[0] == "f") {
            std::vector<size_t> tmp;
            for (size_t i = 1; i < splitLine.size(); i++) {
                tmp.push_back(std::atoi(Parsing::SplitString(splitLine[i], "/")[0].c_str()));
            }
            this->Links.push_back(tmp);
        }
    }
    infile.close();
}

void Blender::LinkPoints()
{
    size_t j = 0;
    for (const std::vector<size_t> &link : this->Links) {
        for (size_t i = 0; i < link.size(); i++) {
            // std::cout << j << " - " << link[i] << std::endl;
            // std::cout << this->Points3D[link[i]] << std::endl;
            this->Oshape3D.push_back (
                Line3D_s::Create (
                    this->Points3D[link[i] - 1],
                    this->Points3D[(i + 1 < link.size()) ? link[i + 1] - 1 : link[0] - 1],
                    this->getId() + std::to_string(j)
                )
            );
            j++;
        }
    }    
}
