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

    // std::vector<int> base = {150, 150};

    std::vector<bind> all;

    all.push_back({"1", {{100, 100}, {200, 100}, {200, 200}, {100, 200}}, {255, 0, 0, 40}});
    std::vector<int> a = center(all[0].p);
    all.push_back({"center", {{a[0] - 2, a[1] - 2}, {a[0] + 2, a[1] - 2}, {a[0] + 2, a[1] + 2}, {a[0] - 2, a[1] + 2}}, {0, 255, 0, 100}});

    for (auto &i : all) {
        s.convex(i.name, i.color, i.p.size());
    }

    s.startClock("time");

    while (s.isOpen()) {
        s.clear();
        s.event();

        if (s.getClock("time") > 1) {
            s.restartClock("time");

            std::vector<int> a = center(all[0].p);
            all[1].p = {{a[0] - 2, a[1] - 2}, {a[0] + 2, a[1] - 2}, {a[0] + 2, a[1] + 2}, {a[0] - 2, a[1] + 2}};

            // all[0].p[2][0] += 10;

            for (auto &i : all) {
                s.setConvex(i.name, i.p);
            }
        }
        for (auto &i : all) {
            s.drawConvex(i.name);
        }
        s.display();
    }
    return (0);
}
