/*
*
*   пиломатериалы   - х1    (2.5 м³)
*   фанера          - х2    (100 м²)
*
*   ель             - a     (1 м^3)
*   пихта           - b     (1 м^3)
*
*
*   Дано:
*   a - 80
*   b - 180
*
*   x1 = 2.5a + 7.5b
*   x2 = 5a + 10b
*
*   x1 - 160 * 2.5 руб  - 400 руб
*   x2 - 600  * 1  руб  - 600 руб
*
*
*   Необходимо
*       x1 >= 4
*       x2 >= 12
*
*/



#include <iostream>


int make_x1(int& x1, double& a, double& b)
{
    if (a >= 2.5 && b >= 7.5) {
        x1++;
        a -= 2.5;
        b -= 7.5;
        return 400;
    }
    return 0;
}

int make_x2(int& x2, double& a, double& b)
{
    if (a >= 5.0 && b >= 10.0) {
        x2++;
        a -= 5.0;
        b -= 10.0;
        return 600;
    }
    return 0;
}


int main()
{
    int x1 = 0;         //  пиломатериалы
    int x2 = 0;         //  фанера
    double a = 80;      //  ель
    double b = 180;     //  пихта
    double money = 0;   //  доход

    //  Доход на единицу сырья
    double profit1 = 400.0 / (2.5 + 7.5);   //  за пиломатериалы
    double profit2 = 600.0 / (5.0 + 10.0);  //  за фанеру

    //  Выполнение плана
    for (int i = 0; i < 4; i++)  money += make_x1(x1, a, b);
    for (int i = 0; i < 12; i++) money += make_x2(x2, a, b);

    //  Расход оставшихся ресурсов
    while(true)
    {
        double tmp_money = money;
        if (profit1 > profit2)
        {
            money += make_x1(x1, a, b);
            if (money == tmp_money)
                money += make_x2(x2, a, b);
        }
        else 
        {
            money += make_x2(x2, a, b);
            if (money == tmp_money)
                money += make_x1(x1, a, b);
        }
        if (money == tmp_money) break;
    }


    std::cout << "Максимальный доход: " << money << " руб." << std::endl;
    std::cout << "Оптимальный план производства:" << std::endl;
    std::cout << "- Пиломатериалы (комплекты): " << x1 << std::endl;
    std::cout << "- Фанера (листы по 100 м²): " << x2 << std::endl;
    std::cout << "Остаток:" << std::endl;
    std::cout << "Ель  : " << a << std::endl;
    std::cout << "Пихта: " << b << std::endl;

    std::cout << x1 * 400 + x2 * 600;

    return 0;
}

