#include "sfml.hpp"

int dist(std::vector<int> a, std::vector<int> b)
{
    return (sqrt(pow(b[0] - a[0], 2) + pow(b[1] - a[1], 2)));
}

int angle(std::vector<int> o, std::vector<int> a, std::vector<int> b)
{
    int da = dist(o, a);
    int db = dist(o, b);
    int dc = dist(a, b);

    return (acos((pow(da, 2) + pow(db, 2) - pow(dc, 2)) / (2 * da * db)));
}

std::vector<int> center(std::vector<std::vector<int>> Obj)
{
    std::vector<int> c = {};

    for (int i = 0; i < (int)Obj.size(); i++) {
        for (int j = 0; j < (int)Obj[i].size(); j++) {
            if ((int)c.size() <= j) {
                c.push_back(Obj[i][j]);
            } else {
                c[j] += Obj[i][j];
            }
        }
    }
    for (auto &i : c)
        i /= Obj.size();
    return (c);
}

int main()
{
    sfml s(500, 500, "test-3D");

    std::vector<int> base = {150, 150};

    std::string name0 = "1";
    std::vector<std::vector<int>> points0 = {{100, 100}, {200, 100}, {200, 200}, {100, 200}};
    s.convex(name0, {255, 0, 0, 70}, 4);
    s.setConvex(name0, points0);

    std::string name1 = "center";
    std::vector<int> a = center({{100, 100}, {200, 100}, {200, 200}, {100, 200}});
    std::vector<std::vector<int>> points1 = {{0, a[0] - 2, a[1] - 2}, {1, a[0] + 2, a[1] - 2}, 
                                            {2,  a[0] + 2, a[1] + 2}, {3,  a[0] - 2, a[1] + 2}};

    s.convex(name1, {0, 255, 0, 70}, 4);
    s.setConvex(name1, points1);

    s.startClock("time");

    while (s.isOpen()) {

        if (s.getClock("time") > 1) {
            s.restartClock("time");

            // points1[2][1]++;
            // points1[1][1]++;

            // s.setConvex(name0, points1);
        }

        s.clear();
        s.event();
        s.drawConvex(name0);
        s.drawConvex(name1);

        s.display();
    }

    return (0);
}
