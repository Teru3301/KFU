# Список вопросов 4 теста Чабанова

Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
class Point{
    char i;
public:
    ~Point(char val){}
};
 
int main(){
    Point p;
    std::cout << sizeof(p);
}
```

Ответ:
- [ ] 0
- [ ] 1
- [ ] 2
- [ ] 4
- [ ] 8
- [x] Ошибка. У деструктора не может быть параметра

---


Есть ли в языке С++ механизм перегрузки функций?

Ответ:
- [x] Да
- [ ] Нет

---


Есть ли в языке Go механизм перегрузки функций?

Ответ:
- [ ] Да
- [x] Нет

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
template<typename T>
void print(T a){
    std::cout << "T";
}

template<typename T>
void print(std::vector<T> a){
    std::cout << "vector<T>";
}

int main()
{
    std::vector<std::vector<int> > i;
    print(i);
}
```

Ответ:
- [ ] ```T```
- [x] ```vector<T>```
- [ ] ```vector<vector<T>>```
- [ ] Ошибка компиляции

---


Язык С++. Какой модификатор доступа у some_field?
```cpp
class SomeClass{
    int some_field;
};
```

Ответ:
- [ ] public
- [x] private
- [ ] protected
- [ ] published

---


Код на С++. Сколько деструкторов может быть у класса?

Ответ:
- [x] Только 1
- [ ] Только 2
- [ ] Только 3
- [ ] Сколько угодно

---


Выберите все перегрузки функции void print(double a);

Ответ:
- [ ] ```void print(double b);```
- [ ] ```void print_d(double a);```
- [ ] ```double print(double a);```
- [x] ```void print(float a);```
- [x] ```void print(double a, int b);```
- [x] ```void print(std::vector<double> a);```

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
void print(short a){
    std::cout << a;
}

void print(int a){
    std::cout << 2*a;
}

void print(double a){
    std::cout << 3*a;
}

int main()
{
    int i = 10;
    print(i);
}
```

Ответ:
- [ ] 10
- [x] 20
- [ ] 30
- [ ] Ничего
- [ ] Ошибка компиляции

---


Язык Go. Выберите все ключевые слова которые являются квалификаторами доступа.

Ответ:
- [ ] public
- [ ] private
- [ ] protected
- [ ] published
- [x] В Go нет ключевых слов-квалификаторов доступа

---


Есть ли в языке С++ возможность указать параметру значение по умолчанию?

Ответ:
- [x] Да
- [ ] Нет

---


Есть ли в языке Go возможность указать параметру значение по умолчанию?

Ответ:
- [ ] Да
- [x] Нет

---


Язык С++. Член класса расположен в секции с модификатором доступа public. Этот член класса:

Ответ:
- [x] Можно использовать в коде не относящихся к классу функций
- [x] Можно использовать в коде методов наследников
- [x] Можно использовать в коде методов класса
- [ ] Нельзя использовать нигде

---


Язык С++. Какой модификатор доступа у some_field?
```cpp
struct SomeClass{
    int some_field;
};
```

Ответ:
- [x] public
- [ ] private
- [ ] protected
- [ ] published

---




Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
void print(short a){
    std::cout << a;
}

void print(int a){
    std::cout << 2*a;
}

void print(double a){
    std::cout << 3*a;
}

int main()
{
    float i = 10;
    print(i);
}
```

Ответ:
- [ ] 10
- [ ] 20
- [x] 30
- [ ] Ничего
- [ ] Ошибка компиляции

---


Язык С++. Член класса расположен в секции с модификатором доступа private. Этот член класса:

Ответ:
- [x] Можно использовать в коде методов класса
- [ ] Можно использовать в коде методов наследников
- [ ] Можно использовать в коде не относящихся к классу функций
- [ ] Нельзя использовать нигде

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
void print(int a){
    std::cout << a;
}

void print(std::string a){
    std::cout << 99;
}

int main()
{
    double i = 0.5;
    print(i);
}
```

Ответ:
- [x] 0
- [ ] 0.5
- [ ] 99
- [ ] Ошибка компиляции

---


Язык С++. Член класса расположен в секции с модификатором доступа protected. Этот член класса:

Ответ:
- [x] Можно использовать в коде методов класса
- [x] Можно использовать в коде методов наследников
- [ ] Можно использовать в коде не относящихся к классу функций
- [ ] Нельзя использовать нигде

---


Дан фрагмент кода на С++. Какой прототип соответствует созданной по шаблону функции?
```cpp
template<typename T, typename U>
U sum(T a, U b){
    auto res = a + b;
    return res;
}

int main(){
    auto i = sum(3, 0.1415);
    std::cout << i;
}
```

Ответ:

- [x] ```double sum(int a, double b);```
- [ ] ```double sum(double a, int b);```
- [ ] ```double sum(double a, double b);```
- [ ] ```int sum(int a, double b);```
- [ ] ```int sum(int a, int b);```
- [ ] ```int sum(double a, double b);```

---


Дана функция на языке С++. Выберите всё варианты, которые являются допустимым объявлением этой функции:
```cpp
void print(int x, int y){
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
```

Ответ:
- [x] ```void print(int x, int y=5);```
- [x] ```void print(int x, int y=10);```
- [x] ```void print(int, int=10);```
- [x] ```void print(int x=10, int y=10);```
- [x] ```void print(int, int);```
- [x] ```void print(int x, int y);```
- [ ] ```void print(int x=10, int y);```

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
void print(int a){
    std::cout << -a;
}

void print(double a){
    std::cout << a;
}

void print(bool a);

int main()
{
    bool i = 10;
    print(i);
}
```

Ответ:
- [ ] -1
- [ ] 1
- [ ] 10
- [ ] -10
- [x] Ошибка компиляции

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
void print(int a){
    std::cout << -a;
}

void print(double a){
    std::cout << a;
}

int main()
{
    bool i = 10;
    print(i);
}
```

Ответ:
- [x] -1
- [ ] 1
- [ ] 10
- [ ] -10
- [ ] Ошибка компиляции

---


Код на С++. Требуется запретить доступ к деструктору класса Point из внешнего кода, как это можно сделать?

Ответ:
- [ ] ~Point();
- [x] private ~Point();
- [ ] private: ~Point();
- [ ] explicit ~Point();
- [ ] __~Point__();
- [ ] Никак

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
template<typename T>
T sum(T a, T b){
    auto res = a + b;
    return res;
}

int main()
{
    std::cout << sum(3.0, 0.1415);
}
```

Ответ:
- [x] 3.1415
- [ ] 0.1415
- [ ] 3
- [ ] 0.1415

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
void print(int a){
    std::cout << a;
}

void print(double& a){
    std::cout << 99;
}

int main()
{
    double i = 0.5;
    print(i);
}
```

Ответ:
- [ ] 0
- [ ] 0.5
- [x] 99
- [ ] Ошибка компиляции

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
void print(short a){
    std::cout << a;
}

void print(int a){
    std::cout << 2*a;
}

void print(double a){
    std::cout << 3*a;
}

int main()
{
    unsigned int i = 10;
    print(i);
}
```

Ответ:
- [ ] 10
- [ ] 20
- [ ] 30
- [ ] Ничего
- [x] Ошибка компиляции

---


Язык С++. Что из перечисленного может быть использовано в качестве объявления деструктора для класса SomeClass?

Ответ:
- [x] ~SomeClass(){}
- [x] ~SomeClass() = default;
- [ ] ~SomeClass(int a) = default;
- [ ] default ~SomeClass(){}
- [ ] ~SomeClass(int a){}
- [ ] ~SomeClass(int a=0, int b=0){}

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
void print(const int  a){
    std::cout << -a;
}

void print(int a){
    std::cout << a;
}

int main()
{
    int i = 10;
    print(i);
}
```

Ответ:
- [ ] -10
- [ ] 10
- [ ] Ничего
- [x] Ошибка компиляции

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
template<typename T>
T sum(T a, T b){
    int res = a + b;
    return res;
}

int main()
{
    std::cout << sum(3.0, 0.1415);
}
```

Ответ:
- [x] 3
- [ ] 3.1415
- [ ] 0.1415
- [ ] Ошибка компиляции

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
template<typename T>
void print(T a){
    std::cout << a;
}

void print(int a){
    std::cout << a;
}

void print(float a){
    std::cout << 99;
}

int main()
{
    double i = 0.5;
    print(i);
}
```

Ответ:
- [ ] 0
- [x] 0.5
- [ ] 99
- [ ] Ошибка компиляции

---


Дана функция на языке С++. Выберите всё варианты, которые являются допустимым объявлением этой функции:
```cpp
void print(int x, int y=10){
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
```

Ответ:
- [x] ```void print(int x, int y);```
- [x] ```void print(int, int);```
- [ ] ```void print(int x=10, int y=10);```
- [ ] ```void print(int x, int y=5);```
- [ ] ```void print(int x, int y=10);```
- [ ] ```void print(int x=10, int y);```
- [ ] ```void print(int, int=10);```

---


Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?
```cpp
class Point{
    ~Point(){}
};
 
int main(){
    Point p;
    std::cout << sizeof(p);
}
```

Ответ:
- [ ] 0
- [ ] 1
- [ ] 2
- [ ] 4
- [ ] 8
- [x] Ошибка. Не доступен деструктор

---


Дан фрагмент кода на С++. Как инстанцировать данный шаблон?
```cpp
template<typename T>
T foo(T a, T b){
    auto res = a + b;
    return res;
}
```

Ответ:
- [x] ```foo(3, 0.1415);```
- [ ] ```foo(3.0, 0.1415);```
- [ ] ```foo(3.0, 0);```
- [x] ```foo(3, 0);```
- [ ] ```foo<double>(3, 0.1415);```
- [x] ```foo<double, double>(3.0, 0.1415);```
- [x] ```foo<int>(3.0, 0.1415);```
- [ ] ```foo<double, double, double>(3.0, 0.1415);```







