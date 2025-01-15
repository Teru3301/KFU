
---

Дана лямбда-функция на языке С++. Какой её тип возвращаемого значения?

    [](int a, int b){return a > b;};

Ответы:
- [ ]
    double
- [ ]
    Никакого, т.к. тип не задан явно
- [x]
    bool
- [ ]
    int

---

Язык С++. Что из нижеперечисленного приведёт к объявлению структуры?

Ответы:
- [ ]
    struct a_struct int a;
- [x]
    struct a_struct{
    int a;
};
- [ ]
    struct a_struct {
    int a;
}
- [ ]
    struct {
    int a;
}
- [x]
    struct {
    int a;
} s;

---

Дан фрагмент кода на языке С++. Что выведется на экран в результате его работы?

enum Color {
    YELLOW,
    BLACK,
    PINK,
    GREEN
};

Color color = Color::BLACK;
std::cout << color;

Ответы:
- [ ]
    Строка BLACK
- [x]
    1
- [ ]
    Какое-то "мусорное" значение, т.к. для BLACK НЕ указано значение явно
- [ ]
    Ошибка. Для Color не определён оператор <<
- [ ]
    0

---

Дан фрагмент кода на С++. Что будет содержать переменная container после его выполнения?

    std::map<int, int> container{{1, 2}, {3, 2}};
container[-1] = 5;

Ответы:
- [x]
    Пары: -1:5, 1:2, 3:2
- [ ]
    Пары: 1:2, 3:2, 5:-1
- [ ]
    Ошибка компиляции - недопустимый тип
- [ ]
    Ошибка доступа - указанного элемента не существует
- [ ]
    Пары: 1:2, 3:2, -1:5
Moodle Question Extractor.user.js:57 
---

Язык Go. Что из нижеперечисленного приведёт к объявлению структуры?

Ответы:
- [x]
    type Mail = struct {
    Address string
    Message string
    Code int
}
- [ ]
    john := Person {
    Name: "John Doe",
    Age:  30,
}
- [x]
    var Address struct {
    Name    string
    City    string
    Pincode int
}
- [x]
    type Employee struct {
    name string
    age int
}
- [x]
    pizza := struct {
    address string 
    name string
    cost int
}{
    address: "address",
    name:    "Pizza",
    cost:    100,
}

---

Дан фрагмент кода на С++. Что будет содержать переменная container после его выполнения?

std::set<int> container{1, 2, 3, 4};
container.insert(container.begin(), 4);

Ответы:
- [ ]
    1, 2, 3, 4, 4
- [ ]
    4, 1, 2, 3, 4
- [x]
    1, 2, 3, 4
- [ ]
    1, 2, 3, 4 но в порядке зависящем от хэш-функции
---

Дан фрагмент кода на Go. Что будет содержать переменная container после его выполнения?

var container map[int]int
container[-1] = 1

Ответы:
- [ ]
    Ошибка во время исполнения - попытка доступа к несуществующему ключу
- [ ]
    Ключ: -1 со значением: 1
- [ ]
    Ошибка компиляции - недопустимый тип
- [x]
    Ошибка во время исполнения - под словарь не выделена память
- [ ]
    Ключ: -1 со значением: 0
---

Дан фрагмент кода на С++. Что будет содержать переменная container после его выполнения?

std::vector<int> container{1, 2, 3, 4};
container.insert(container.begin(), 4);

Ответы:
- [ ]
    1, 2, 3, 4 но в порядке зависящем от хэш-функции
- [ ]
    1, 2, 3, 4
- [ ]
    1, 2, 3, 4, 4
- [x]
    4, 1, 2, 3, 4
---

Дан фрагмент кода на С++ и класс MyClass объявленный как:

class MyClass{};

Выберите все верные варианты, которые являются допустимыми объявлениям.

Ответы:
- [ ]
    double operator+ (double a, double b);
- [ ]
    MyClass operator+ (double a, double b);
- [x]
    double operator+ (MyClass a, MyClass b);
- [x]
    double operator+ (MyClass a, double b);
- [x]
    double operator+ (double a, MyClass b);
---

Язык Go. Какие поля могут быть в структурном типе?

Ответы:
- [ ]
    Не константные поля;
- [ ]
    Поля-ссылки;
- [x]
    Константные поля;
- [x]
    Анонимные поля;
- [ ]
    Статические поля;
---

Дан кода на Go. Что будет выведено на экран в результате его выполнения:

package main
import "fmt"

func change(abc []int) {
    for i := range abc {
        abc[i] = 4
    }
    fmt.Println(abc)
}

func main() {
    abc := []int{1, 2, 3}
    change(abc)
    fmt.Println(abc)
}

Ответы:
- [ ]
    [1 2 3][1 2 3]
- [ ]
    [4 4 4][1 2 3]
- [x]
    [4 4 4][4 4 4]
- [ ]
    [1 2 4][1 2 3]
---

Язык С++. Что будет напечатано в результате исполнения следующего кода?

#include <iostream>

class A{
public:
    void get(){
        std::cout << 'A';
    }
};

class B: public A{
public:
    void get(){
        std::cout << 'B';
    }
};

class C: public B{
public:
    void get(){
        std::cout << 'C';
    }
};

int main(){
    A* obj = new C;
    obj->get();
}

Ответы:
- [ ]
    C
- [x]
    A
- [ ]
    Ошибка
- [ ]
    B

---

Язык Go. Дан фрагмент кода:

    type A struct{
    value int
}

type Printer interface{
    print()
}

func main() {
    var obj A
    p := Printer(&obj)
    p.print()
}

Что нужно добавить, чтобы он стал рабочим?

Ответы:
- [ ]
    Ничего. Код уже рабочий
- [x]
    func (a *A) print(){
    fmt.Print(a.value)
}
- [ ]
    func Printer(a *A){
    fmt.Print(a.value)
}
- [ ]
    func print(a *A){
    fmt.Print(a.value)
}
- [ ]
    func (a *A) Printer{
    fmt.Print(a.value)
}

---

Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?

class Point{ 
};
 
int main(){
    Point p;
    std::cout << sizeof(p);
}

Ответы:
- [ ]
    Ошибка. Отсутствует конструктор по умолчанию
- [ ]
    2
- [ ]
    0
- [x]
    1
- [ ]
    4
- [ ]
    8
---

Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?

class SomeClass{
public:
    int value = 1;
    void method(int value){
        value = value;
    }
} s;

s.method(5);
std::cout << s.value;

Ответы:
- [ ]
    5
- [x]
    1
- [ ]
    Ошибка

---

Язык Go. Что будет выведено на экран в результате работы этого кода?

package main
import "fmt"

type Data struct{
    i int
}

func (d Data) method(){
    d.i = 1
}

func main() {
    var d *Data = &Data{}
    d.method()
    fmt.Print(d.i)
}

Ответы:
- [ ]
    1
- [ ]
    Ошибка
- [ ]
    Мусорное значение
- [x]
    0

---

Дан фрагмент кода на С++.

class SomeClass{
    int value = 0;
public:
    void method() const{
        value = 1;
        std::cout << value;
    }
};

int main(){
    const SomeClass s;
    s.method();
}

Что нужно добавить в код, чтобы код стал рабочим?

Ответы:
- [x]
    Добавить ключевое слово mutable к объявлению method;
- [ ]
    Добавить ключевое слово mutable к объявлению value;
- [ ]
    Добавить ключевое слово public к объявлению value;
- [ ]
    Ничего добавлять не нужно. Код и так рабочий;
- [ ]
    В константных методах нельзя менять значения полей и это изменить невозможно.
---

Дан фрагмент кода на С++. Каким образом можно получить доступ к полю  x переменной p?

    struct Point{
    double x, y;
} p;

Ответы:
- [ ]
    p->x;
- [ ]
    p<-x;
- [ ]
    p-x;
- [ ]
    p>x;
- [ ]
    p~x;
- [x]
    p.x;

---

Дан фрагмент кода на С++. Что будет содержать переменная container после его выполнения?

    std::map<std::string, int> container{{"1", 2}, {"3", 2}};
container[-1] = 5;

Ответы:
- [x]
    Ошибка компиляции - недопустимый тип
- [ ]
    Пары: 1:2, 3:2, 5:-1
- [ ]
    Ошибка доступа - указанного элемента не существует
- [ ]
    Пары: -1:5, 1:2, 3:2
- [ ]
    Пары: 1:2, 3:2, -1:5

---

Дан фрагмент кода на Go. Каким образом можно получить доступ к полю x переменной var p Point = Point{}?

    type Point struct{
    x float64
    y float64
}

Ответы:
- [ ]
    fmt.Print( p->x )
- [ ]
    fmt.Print( *p.x )
- [ ]
    fmt.Print( &p.x )
- [ ]
    fmt.Print( (*p).x )
- [x]
    fmt.Print( (&p).x )
- [x]
    fmt.Print( p.x )

---

Дан фрагмент кода на С++. Что будет содержать переменная container после его выполнения?

std::unordered_set<int> container{1, 2, 3, 4};
container.insert(container.begin(), 4);

Ответы:
- [x]
    1, 2, 3, 4 но в порядке зависящем от хэш-функции
- [ ]
    1, 2, 3, 4
- [ ]
    4, 1, 2, 3, 4
- [ ]
    1, 2, 3, 4, 4
---

Дан фрагмент кода на С++. Что будет содержать переменная container2 после его выполнения?

std::set<int> container1{4, 3, 2, 1, 2, 3, 4};
std::vector<int> container2(container1.begin(), container1.end());

Ответы:
- [ ]
    4, 3, 2, 1, 2, 3, 4
- [ ]
    1, 2, 3, 4 но в порядке зависящем от хэш-функции
- [x]
    1, 2, 3, 4
- [ ]
    4, 3, 2, 1, 2, 3, 4 но в порядке зависящем от хэш-функции
- [ ]
    4, 3, 2, 1
---

Дан фрагмент кода на С++ и класс MyClass объявленный как:

class MyClass{};

Выберите все верные варианты, которые являются допустимыми объявлениям.

Ответы:
- [ ]
    double operator# (MyClass a, double b);
- [ ]
    double operator** (MyClass a, double b);
- [x]
    double operator+ (MyClass a, double b);
- [x]
    double operator/ (MyClass a, double b);
- [x]
    double operator- (MyClass a, double b);
---

Дан фрагмент кода на языке С++. Что выведется на экран в результате его работы?

enum class Color {
    YELLOW,
    BLACK,
    PINK,
    GREEN
};

Color color = Color::BLACK;
std::cout << color;

Ответы:
- [ ]
    Какое-то "мусорное" значение, т.к. для BLACK НЕ указано значение явно
- [x]
    Ошибка. Для Color не определён оператор <<
- [ ]
    1
- [ ]
    Строка BLACK
- [ ]
    0
---

Дан кода на Go. Что будет выведено на экран в результате его выполнения:

package main
import "fmt"

func change(abc []int) {
    abc = append(abc, 4)
    for i := range abc {
        abc[i] = 4
    }
    fmt.Println(abc)
}

func main() {
    abc := []int{1, 2, 3}
    change(abc)
    fmt.Println(abc)
}

Ответы:
- [x]
    [4 4 4 4]
[1 2 3]
- [ ]
    [4 4 4 4]
[4 4 4 4]
- [ ]
    [4 4 4 4]
[1 2 3 4]
- [ ]
    [1 2 3]
[4 4 4 4]
---

Дан фрагмент кода на Go. Что будет содержать переменная container после его выполнения?

    var container map[string]int
container[-1] = 1

Ответы:
- [x]
    Ошибка компиляции - недопустимый тип
- [ ]
    Ключ: -1 со значением: 1
- [ ]
    Ключ: -1 со значением: 0
- [ ]
    Ошибка во время исполнения - под словарь не выделена память
- [ ]
    Ошибка во время исполнения - попытка доступа к несуществующему ключу
