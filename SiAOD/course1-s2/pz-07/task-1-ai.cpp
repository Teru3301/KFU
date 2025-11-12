
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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



class Way {
public:
    std::vector<int> way;
    
    Way(int count)
    {
        for (int i = 0; i < count; i++)
            way.push_back(i);
        // перемешивание
        std::random_device rd;  // Источник случайных чисел
        std::mt19937 gen(rd()); // Генератор Mersenne Twister
        std::shuffle(way.begin() + 1, way.end(), gen);
        way.push_back(0);
    }
    Way(){}

    void print (const std::vector<Point>& city)
    {
        for (int i = 0; i < way.size(); i++)
        {
            if (i != 0) std::cout << " - " << city[way[i-1]].distance[way[i]] << " - ";
            std::cout << Point().name(way[i]);
        }
    }
};


double calc_distance(const Way& way, const std::vector<Point>& city)
{
    double distance = 0;

    for (int i = 0; i < way.way.size() - 1; i++)
        distance += city[way.way[i]].distance[way.way[i + 1]];

    return distance;
}


Way crossesngover(const std::vector<Way>& ways)
{
    Way child = ways[rand() % (ways.size() / 10)];

    for (int i = 0; i < (rand() % (child.way.size() - 2) / 2); i++)
    {
        int p1 = (rand() % (child.way.size() - 2)) + 1;
        int p2 = (rand() % (child.way.size() - 2)) + 1;

        double tmp = child.way[p1];
        child.way[p1] = child.way[p2];
        child.way[p2] = tmp;
    }

    return child;
}


int main ()
{
    int count = 10;
    std::vector<Point> city(count); //  города
    std::vector<Way> ways;     //  номера городов в оптимальном пути
    double best_distance = 100000000;

//  заполнение дорог между городами случайными расстояниями
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            city[i].distance.push_back(0);
            if (i == j) continue;
            city[i].distance[j] = double(rand() % 100 + 1);
        }
    }

//  генерация начальных случайных путей
    for (int i = 0; i < 100; i++)
    {
        Way way(count);
        ways.push_back(way);
    }

//  что бы посмотреть заданные растояния
    for (auto p : city)
        p.print();

//  построение маршрута
    

    int try_cross = 1000;
    for(int iter = 0; iter < 1000000; ++iter)
    {

        std::sort(ways.begin(), ways.end(), 
            [&city](const Way& a, const Way& b)
                { return (calc_distance(a, city) < calc_distance(b, city));}
            );

        for (int i = ways.size() / 10; i < ways.size(); i++)
            ways[i] = crossesngover(ways);


        double curent_distance = calc_distance(ways[0], city);
        if (best_distance != curent_distance)
        {
            std::cout << "Результат улучшен. Итерация: " << iter <<
                "\tДлина текуще оптимального маршрута: " << curent_distance << std::endl;
            best_distance = curent_distance;
            try_cross = 1000;
            continue;
        }
        try_cross--;
        if (!try_cross)
        {
            std::cout << "Не удаётся улучшить результат." << std::endl;
            break;
        }
    }



//  готовый путь
    std::cout << "Оптимизированный путь:" << std::endl;
    ways[0].print(city);
    std::cout << std::endl;
    std::cout << "Расстояние: " << calc_distance(ways[0], city);
    std::cout << std::endl;


    return 0;
}



