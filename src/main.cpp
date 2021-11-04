#include "core/core.hpp"
#include "../lib/math/matrix/matrix.hpp"

int main(int ac, char *av[])
{
    // core c();

    matrix2D_s m = matrix2D_s::Create(5, 5);
    m.matrix[0][3] = 10;

    matrix2D_s n = matrix2D_s::Create(5, 5);
    n.matrix[4][3] = 13;

    std::cout << " m  : \n" << m << std::endl;
    std::cout << " n  : \n" << n << std::endl;

    matrix2D_s r;

    r = (m * n);

    std::cout << " m * n  : \n" << r << std::endl;

    return (0);
}
