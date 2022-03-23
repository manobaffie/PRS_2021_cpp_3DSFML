#include "Blender.hpp"

Blender::Blender(const std::string &path, const vec::vector3f origine, const vec::vector2i res, const float fov) :
resolution(res), fov(fov)
{
    this->Z0 = (res.x / 2.0) / std::tan((fov / 2.0) * PI / 180.0);
    // this->Z0 = 500;
    this->scale = 10.0;
    // std::cout << "Z0 : " << Z0 << " x : " << origine.x << " y : " << origine.y << " z : " << origine.z << std::endl;
    this->position = {
        .x = new float(origine.x),
        .y = new float(origine.y /*+ 200*/),
        .z = new float(origine.z)
        // .z = new float(origine.z - this->Z0)
    };

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
        // .x = float(std::atof(splitLine[3].c_str())) * this->scale,
        // .y = float(std::atof(splitLine[2].c_str())) * -this->scale,
        // .z = float(std::atof(splitLine[1].c_str())) * this->scale

        .x = float(std::atof(splitLine[3].c_str())) * this->scale + (*this->position.x),
        .y = float(std::atof(splitLine[2].c_str())) * -this->scale + (*this->position.y),
        .z = float(std::atof(splitLine[1].c_str())) * this->scale + (*this->position.z)
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
            // (*this->vertices2f[i][j].x) = (
            //     ((this->vertices3f[i][j].x /*+ (*this->position.x)*/) * this->Z0) /
            //     (this->Z0 + (this->vertices3f[i][j].z /*+ (*this->position.z)*/)) +
            //     (this->resolution.x / 2.f)
            // );
            // (*this->vertices2f[i][j].y) = (
            //     ((this->vertices3f[i][j].y /*+ (*this->position.y)*/) * this->Z0) /
            //     (this->Z0 + (this->vertices3f[i][j].z /*+ (*this->position.z)*/)) +
            //     (this->resolution.y / 2.f)
            // );

            (*this->vertices2f[i][j].x) = (
                ((this->vertices3f[i][j].x) * this->Z0) /
                (this->Z0 + (this->vertices3f[i][j].z)) +
                (this->resolution.x / 2.f)
            );
            (*this->vertices2f[i][j].y) = (
                ((this->vertices3f[i][j].y) * this->Z0) /
                (this->Z0 + (this->vertices3f[i][j].z)) +
                (this->resolution.y / 2.f)
            );
        }
    }
};

std::vector<vec::vpvector2f> *Blender::getVertices2d()
{
    return (&this->vertices2f);
}

vec::pvector3f *Blender::getPosition()
{
    return (&this->position);
}

void Blender::setMoove(const vec::vector3f &moov)
{
    for (vec::vvector3f &i : this->vertices3f) {
        for (vec::vector3f &k : i) {
            k.x += moov.x;
            k.y += moov.y;
            k.z += moov.z;
        }
    }
}

void Blender::rotation(const vec::vector3f &angl, vec::vector3f &origine)
{
    for (vec::vvector3f &i : this->vertices3f) {
        for (vec::vector3f &k : i) {
            if (angl.x) {
                k = {
                    .x = float((cos(angl.x) * k.x) + ((-sin(angl.x)) * k.y) + (0 * k.z)),
                    .y = float(sin(angl.x) * k.x + cos(angl.x) * k.y + (0 * k.z)),
                    .z = float((0 * k.x) + (0 * k.y) + (1 * k.z))
                };
            }
            if (angl.y) {
                k = {
                    .x = float((1 * k.x) + (0 * k.y) + (0 * k.z)),
                    .y = float((0 * k.x) + (cos(angl.y) * k.y) + ((-sin(angl.y)) * k.z)),
                    .z = float((0 * k.x) + (sin(angl.y) * k.y) + (cos(angl.y) * k.z))
                };
            }
            if (angl.z) {
                k = {
                    .x = float((cos(angl.z) * k.x) + (0 * k.y) + (sin(angl.z) * k.z)),
                    .y = float((0 * k.x) + (1 * k.y) + (0 * k.z)),
                    .z = float(((-sin(angl.z)) * k.x) + (0 * k.y) + (cos(angl.z) * k.z))
                };
            }
        }
    }
}
