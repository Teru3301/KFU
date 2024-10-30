#include <iostream>
#include "json.hpp"
using json = nlohmann::json;

// Ваш код здесь







int main(){
    double x, y;
    std::cin >> x >> y;

    Point p(x, y);
    json moves;
    std::cin >> moves;
    
    for(auto& move : moves){
        std::string ort = move["ort"];
        double value = move["value"];
        if (ort == "x") p.set_x(p.get_x() + value);
        else if (ort == "y") p.set_y(p.get_y() + value);
        else if (ort == "r") p.set_r(p.get_r() + value);
        else p.set_a(p.get_a() + value);
        std::cout << round(p.get_x()*(1E+5))/(1E+5) << ' ' << round(p.get_y()*(1E+5))/(1E+5) << std::endl;    
    }
}
