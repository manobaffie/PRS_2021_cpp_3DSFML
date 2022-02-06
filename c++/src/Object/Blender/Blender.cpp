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
                Point<float> (
                    std::atof(splitLine[3].c_str()) * this->scale,
                    std::atof(splitLine[2].c_str()) * -this->scale,
                    std::atof(splitLine[1].c_str()) * this->scale
                )
            );
        }
        if (splitLine[0] == "vt") {
            this->Texture.push_back(
                Point<float> (
                    std::atof(splitLine[1].c_str()),
                    std::atof(splitLine[2].c_str())                    
                )
            );
        }
        if (splitLine[0] == "f") {
            std::vector<std::vector<size_t>> tmp0;
            for (size_t i = 1; i < splitLine.size(); i++) {
                std::vector<size_t> tmp1;
                tmp1.push_back(std::atoi(Parsing::SplitString(splitLine[i], "/")[0].c_str()));
                tmp1.push_back(std::atoi(Parsing::SplitString(splitLine[i], "/")[1].c_str()));
                tmp0.push_back(tmp1);
            }
            this->Links.push_back(tmp0);
        }
    }
    infile.close();
}

void Blender::LinkPoints()
{
    for (const std::vector<std::vector<size_t>> &link : this->Links) {

        std::vector<Point<float>> Shape3D = std::vector<Point<float>>(std::vector<Point<float>>(link.size()));
        std::vector<Point<float>> TexturesT = std::vector<Point<float>>(std::vector<Point<float>>(link.size()));

        for (size_t i = 0; i < link.size(); i++) {
            Shape3D[i] = this->Points3D[link[i][0] - 1];
            TexturesT[i] = this->Texture[link[i][1] - 1];
        }
        this->Oshape3D.push_back(Shape3D);
        this->Textures.push_back(TexturesT);
    }    
}
