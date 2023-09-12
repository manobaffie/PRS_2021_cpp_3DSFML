#include "MyGame/Instance/Visual/Visual.hpp"

void test1()
{
    Game::Instance::Base *visual = new MyGame::Instance::Visual();

    delete static_cast<MyGame::Instance::Visual *>(visual);
}

int main(int ac, char *av[])
{
    test1();

    return (0);
}
