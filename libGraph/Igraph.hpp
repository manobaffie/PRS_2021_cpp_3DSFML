#include <vector>

#include <iostream>

struct Points_s {
    int x;
    int y;
};

class Igraph
{
    public:
        Igraph(int x, int y, std::string name);
        Igraph() = default;
        virtual ~Igraph() = default;

        virtual void setWindow(int fps, std::string title, std::vector<int> size) = 0;

        virtual void pollEvent() = 0;

        virtual void display() = 0;
        virtual bool isOpen() = 0;
        virtual void clear() = 0;

        virtual void setConvexShape(std::string id, std::vector<Points_s> Points) = 0;
        virtual void setLineShape(std::string id, size_t size, Points_s Points1, Points_s Points2) = 0;

        virtual void drawShape(std::string id) = 0;
        virtual void delShape(std::string id) = 0;



};
