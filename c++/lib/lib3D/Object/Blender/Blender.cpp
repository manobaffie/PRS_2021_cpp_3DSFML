#include "Blender.hpp"

Blender::Blender(const vec::vector2i &res, const float &fov, const std::string &path) :
res(res), fov(fov)
{
    this->Z0 = (res.x / 2.0) / std::tan((fov / 2.0) * PI / 180.0);
    this->origine = {new float(0), new float(0), new float(0)};
    this->scale = 10.0;
    this->load(path);
    this->mapping();
    this->render2d();
}

Blender::~Blender()
{
    for (size_t i = 0; i < this->vertices2f.size(); i++) {
        for (size_t j = 0; j < this->vertices2f[i].size(); j++) {
            delete this->vertices2f[i][j].x;
            delete this->vertices2f[i][j].y;
        }
    }
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
        .x = float(std::atof(splitLine[3].c_str())) * this->scale,
        .y = float(std::atof(splitLine[2].c_str())) * -this->scale,
        .z = float(std::atof(splitLine[1].c_str())) * this->scale
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

void Blender::mapping()
{
    this->vertices2f = std::vector<vec::vpvector2f>(this->links.size());
    for (size_t i = 0; i < this->links.size(); i++) {
        this->vertices2f[i] = vec::vpvector2f(this->links[i].size());
        vec::vvector3f shape;
        for (size_t j = 0; j < this->links[i].size(); j++) {
            this->vertices2f[i][j].x = new float(0);
            this->vertices2f[i][j].y = new float(0);
            shape.push_back(this->points[this->links[i][j] - 1]);
        }
        this->vertices3f.push_back(shape);
    }
}

void Blender::render2d()
{
    for (size_t i = 0; i < this->vertices3f.size(); i++) {
        for (size_t j = 0; j < this->vertices3f[i].size(); j++) {
            (*this->vertices2f[i][j].x) = (
                ((this->vertices3f[i][j].x + (*this->origine.x)) * this->Z0) /
                (this->Z0 + (this->vertices3f[i][j].z + (*this->origine.z))) +
                (this->res.x / 2.f)
            );
            (*this->vertices2f[i][j].y) = (
                ((this->vertices3f[i][j].y + (*this->origine.y)) * this->Z0) /
                (this->Z0 + (this->vertices3f[i][j].z + (*this->origine.z))) +
                (this->res.y / 2.f)
            );
        }
    }
};

std::vector<vec::vpvector2f> *Blender::getVertices2d()
{
    return (&this->vertices2f);
}

vec::pvector3f *Blender::getOrigine()
{
    return (&this->origine);
}

void Blender::rotation(const vec::vector3f &r)
{
    for (vec::vvector3f &i : this->vertices3f) {
        for (vec::vector3f &j : i) {
            if (r.x) {
                j = {
                    .x = float(cos(r.x) * j.x + (-sin(r.x)) * j.y),
                    .y = float(sin(r.x) * j.x + cos(r.x) * j.y),
                    .z = float(j.z)
                };
            }
            if (r.y) {
                j = {
                    .x = float(j.x),
                    .y = float(cos(r.y) * j.y + (-sin(r.y)) * j.z),
                    .z = float(sin(r.y) * j.y + cos(r.y) * j.z)
                };
            }
            if (r.z) {
                j = {
                    .x = float(cos(r.z) * j.x + sin(r.z) * j.z),
                    .y = float(j.y),
                    .z = float((-sin(r.z)) * j.x + cos(r.z) * j.z)
                };
            }
        }
    }
}
