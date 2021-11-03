#include "math.hpp"

matrix::matrix(std::vector<std::vector<float>> m) : value(m)
{
}

matrix::~matrix()
{
}

matrix matrix::operator+(matrix &a)
{
    std::vector<std::vector<float>> value = {};
    for (int i = 0; i < (int)this->value.size(); i++) {
        std::vector<float> tmp = {};
        for (int j = 0; j < (int)this->value[i].size(); j++) {
            tmp.push_back(this->value[i][j] + a.getValue()[i][j]);
        }
        value.push_back(tmp);
    }
    return (value);
}

matrix matrix::operator-(matrix &a)
{
    std::vector<std::vector<float>> value = {};
    for (int i = 0; i < (int)this->value.size(); i++) {
        std::vector<float> tmp = {};
        for (int j = 0; j < (int)this->value[i].size(); j++) {
            tmp.push_back(this->value[i][j] - a.getValue()[i][j]);
        }
        value.push_back(tmp);
    }
    return (value);
}

matrix matrix::operator*(matrix &a)
{
    if (this->value[0].size() != a.value.size())
        return ((std::vector<std::vector<float>>){{}});
    std::vector<std::vector<float>> value = {};
    for (int j = 0; j < (int)this->value.size(); j++) {
        std::vector<float> v_tmp = {};
        for (int k = 0; k < (int)a.value.size(); k++) {
            float i_tmp = 0;
            for (int i = 0; i < (int)a.value.size(); i++) {
                i_tmp += (this->value[j][i] * a.value[i][k]);
            }
            v_tmp.push_back(i_tmp);
        }
        value.push_back(v_tmp);
    }
    return (value);
}

void matrix::swap()
{
    std::vector<std::vector<float>> swap = {};
    for (auto i : this->value) {
        std::vector<float> tmp = {};
        for (auto j : i) {
            tmp.push_back(j);
        }
        swap.push_back(tmp);
    }
    this->value.clear();
    this->value.shrink_to_fit();
    for (int i = 0; i < (int)swap[0].size(); i++) {
        std::vector<float> tmp = {};
        for (int j = 0; j < (int)swap.size(); j++) {
            tmp.push_back(swap[j][i]);
        }
        this->value.push_back(tmp);
    }
}

std::vector<std::vector<float>> &matrix::getValue()
{
    return (this->value);
}

void matrix::Mprint()
{
    for (auto &i : this->value) {
        for (auto &j : i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }
}



math::math()
{
}

math::~math()
{
}
