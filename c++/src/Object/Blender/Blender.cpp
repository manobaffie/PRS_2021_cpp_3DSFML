#include "Blender.hpp"

Blender::Blender(const std::string &id, const std::string &path) :
Object(id), Path(path)
{
    this->scale = 100.0;

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
        const std::vector<std::string> splitLine = Parsing::SplitString(line, " ");
        if (splitLine[0] == "v") {
            this->Points3D.push_back (
                Point3D_s::Create (
                    std::atof(splitLine[3].c_str()) * this->scale,
                    std::atof(splitLine[2].c_str()) * -this->scale,
                    std::atof(splitLine[1].c_str()) * this->scale
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

        Shape3D_s Shape3D = Shape3D_s::Create(std::vector<Point3D_s>(link.size()));

        for (size_t i = 0; i < link.size(); i++) {
            Shape3D.Shape3D[i] = this->Points3D[link[i] - 1];
            Shape3D.id = this->getId() + std::to_string(j);
        }
        this->Oshape3D.push_back(Shape3D);
        j++;
    }    
}
