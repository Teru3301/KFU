
#include <iostream>
#include <vector>

class Point {
public:
    int id;
    std::vector<int> distance;

    Point()
    {
        id = count++;
    };

    void print ()
    {
        for (int i = 0; i < distance.size(); i++)
            if (i != id)
                std::cout << name(id) << " -> " << name(i) << " = " << distance[i] << std::endl;
    }

    std::string name ()
    {
        return name(id);
    }
    std::string name(int id)
    {
        std::string n = "";
        n += char(65 + id);
        return n;
    }

private:
    static int count;
};
int Point::count = 0;


std::vector<int> avaibles(const std::vector<int>& way, const std::vector<Point>& city)
{
    std::vector<int> avaible;

    for (int i = 0; i < city.size(); i++)
    {
        avaible.push_back(i);
        for (int j = 0; j < way.size(); j++)
            if (way[j] == i)
            {
                avaible.pop_back();
                break;
            }
    }

    if (way.size() == city.size())
        avaible.push_back(way[0]);

    return avaible;
}


double calc_distance(const std::vector<int>& way, const std::vector<Point>& city)
{
    double distance = 0;

    for (int i = 0; i < way.size() - 1; i++)
        distance += city[way[i]].distance[way[i + 1]];

    return distance;
}


std::vector<int> f(double &dist, std::vector<int> way, std::vector<Point> city)  // dist передаётся по ссылке
{
    std::vector<int> avaible_ways = avaibles(way, city);
    std::vector<int> local_best_way = way;  // Инициализируем текущим путём

    if (avaible_ways.size() != 0)
    {
        for (int i = 0; i < avaible_ways.size(); i++)
        {
            way.push_back(avaible_ways[i]);
            std::vector<int> local_way = f(dist, way, city);
            double local_dist = calc_distance(local_way, city);
            if (local_dist <= dist)
            {
                dist = local_dist;
                local_best_way = local_way;
            }
            way.pop_back();
        }
    }
    dist = calc_distance(local_best_way, city);

    return local_best_way;
}


int main ()
{
    int count = 5;
    std::vector<Point> city(count); //  города
    std::vector<int> way({0});      //  номера городов в оптимальном пути

//  заполнение случайными расстояниями
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            city[i].distance.push_back(0);
            if (i == j) continue;
            city[i].distance[j] = double(rand() % 100 + 1);
        }
    }

//  что бы посмотреть заданные растояния
    for (auto p : city)
        p.print();

//  построение маршрута
    double d = 10000;
    way = f(d, way, city);

//  готовый путь
    for (int i = 0; i < way.size(); i++)
    {
        if (i != 0) std::cout << " - " << city[way[i-1]].distance[way[i]] << " - ";
        std::cout << Point().name(way[i]);
    }
    std::cout << std::endl;

    std::cout << "Длинна маршрута: " << calc_distance(way, city) << std::endl;



    return 0;
}





















