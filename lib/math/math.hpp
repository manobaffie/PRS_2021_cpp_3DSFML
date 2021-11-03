#include <cmath>
#include <iostream>
#include <vector>

class matrix
{
    private:
        std::vector<std::vector<float>> value;

    public:
        matrix() = default;
        matrix(std::vector<std::vector<float>> m);
        ~matrix();

        matrix operator+(matrix &a);
        matrix operator-(matrix &a);
        matrix operator*(matrix &a);
        matrix operator/(matrix &a);

        void swap();

        void Mprint();
        std::vector<std::vector<float>> &getValue();
};

class math
{
    private:
    public:
        math();
        ~math();
};
