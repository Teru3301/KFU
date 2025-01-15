
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
- [x]
    Не константные поля;
- [ ]
    Поля-ссылки;
- [ ]
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
- [ ]
    Добавить ключевое слово mutable к объявлению method;
- [x]
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
    [4 4 4 4][1 2 3]
- [ ]
    [4 4 4 4][4 4 4 4]
- [ ]
    [4 4 4 4][1 2 3 4]
- [ ]
    [1 2 3][4 4 4 4]
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
---

Язык С++. Что будет напечатано в результате исполнения следующего кода?

#include <iostream>

class A{
public:
    virtual void get(){
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
- [x]
    C
- [ ]
    Ошибка
- [ ]
    B
- [ ]
    A

---

Язык Go. Дан фрагмент кода:

type A struct{
    value int
}

func (a A) get() int{
    return a.value
}

func (a A) set(val int){
    a.value = val
}

type Accessor interface{
    get() int
    set(val int)
}

func main() {
    var obj A
    g := Accessor(obj)
    g.set(10)
    
    fmt.Print(obj.get())
}

Что будет выведено в результате его работы?

Ответы:
- [x]
    0
- [ ]
    Ошибка
- [ ]
    10

---

Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?

class Point{
    Point(){}
};
 
int main(){
    Point p;
    std::cout << sizeof(p);
}

Ответы:
- [ ]
    8
- [ ]
    0
- [ ]
    2
- [x]
    Ошибка. Не доступен конструктор по умолчанию
- [ ]
    4
- [ ]
    1
---

Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?

class SomeClass{
    int value = 1;
    void method(int value){
        value = value;
    }
} s;

s.method(5);
std::cout << s.value;

Ответы:
- [x]
    Ошибка
- [ ]
    1
- [ ]
    5
---

Язык Go. Что будет выведено на экран в результате работы этого кода?

package main
import "fmt"

type Data struct{
    i int
}

func (d *Data) method(){
    d.i = 1
}

func main() {
    var d Data = Data{}
    d.method()
    fmt.Print(d.i)
}

Ответы:
- [x]
    1
- [ ]
    Ошибка
- [ ]
    Мусорное значение
- [ ]
    0

---

Какое, из перечисленных, ключевых слов нужно использовать при объявлении структуры в С++?

Ответы:
- [ ]
    record
- [ ]
    object
- [ ]
    structure
- [ ]
    Struct
- [ ]
    Record
- [x]
    struct

---

Дан код на языке Go:

#include <iostream>
#include <map>

void add(std::map<int, int> c, int value){
    c[c.size()] = value;
}

int main(){
    std::map<int, int> container;
    add(container, 10);
    std::cout << container.size();
}

В результате его исполнения:

Ответы:
- [ ]
    Переменная container изменится;
- [x]
    Переменная container не изменится;

---

Дан фрагмент кода на Go. Каким образом можно получить доступ к полю x переменной var p *Point = &Point{}?

    type Point struct{
    x float64
    y float64
}

Ответы:
- [ ]
    fmt.Print( p->x )
- [ ]
    fmt.Print( (&p).x )
- [ ]
    fmt.Print( *p.x )
- [x]
    fmt.Print( p.x )
- [ ]
    fmt.Print( &p.x )
- [x]
    fmt.Print( (*p).x )
---

Дан фрагмент кода на С++. Что будет содержать переменная container2 после его выполнения?

    std::vector<int> container1{4, 3, 2, 1, 2, 3, 4};
std::set<int> container2(container1.begin(), container1.end());

Ответы:
- [ ]
    4, 3, 2, 1, 2, 3, 4 но в порядке зависящем от хэш-функции
- [ ]
    4, 3, 2, 1, 2, 3, 4
- [ ]
    1, 2, 3, 4 но в порядке зависящем от хэш-функции
- [x]
    1, 2, 3, 4
- [ ]
    4, 3, 2, 1
---

Дан фрагмент кода на С++. Что будет содержать переменная container2 после его выполнения?

std::vector<int> container1{4, 3, 2, 1, 2, 3, 4};
std::vector<int> container2(container1.begin(), container1.end());

Ответы:
- [ ]
    1, 2, 3, 4
- [ ]
    1, 2, 3, 4 но в порядке зависящем от хэш-функции
- [ ]
    4, 3, 2, 1
- [x]
    4, 3, 2, 1, 2, 3, 4
- [ ]
    4, 3, 2, 1, 2, 3, 4 но в порядке зависящем от хэш-функции
---

Дан фрагмент кода на С++ и класс MyClass объявленный как:

class MyClass{};

Выберите все верные варианты, которые являются допустимыми объявлениям.

Ответы:
- [x]
    void operator/ (MyClass a, double b);
- [x]
    double operator/ (MyClass a, double b);
- [ ]
    double operator/ (MyClass a, MyClass b, double c);
- [ ]
    double operator/ (MyClass a, double b, MyClass c);
- [ ]
    double operator/ (MyClass a);

---

Дан фрагмент кода на языке С++. Что выведется на экран в результате его работы?

enum Color {
    YELLOW,
    BLACK,
    PINK,
    GREEN
};

int BLACK = 0;
Color color = Color::BLACK;
std::cout << color;

Ответы:
- [x]
    Ошибка. Повторное определение имени BLACK
- [ ]
    Ошибка. Для Color не определён оператор <<
- [ ]
    0
- [ ]
    1
- [ ]
    Строка BLACK

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
    abc = append(abc, 4)
    fmt.Println(abc)
}

Ответы:
- [ ]
    [4 4 4 4][4 4 4 4]
- [ ]
    [1 2 3][4 4 4 4 4]
- [ ]
    [1 2 3 4][4 4 4 4]
- [x]
    [4 4 4 4][1 2 3 4]

---

Дан фрагмент кода на Go. Что будет содержать переменная container после его выполнения?

    var container map[int]int = make(map[int]int)
container[-1] = 1

Ответы:
- [ ]
    Ошибка компиляции - недопустимый тип
- [ ]
    Ошибка во время исполнения - попытка доступа к несуществующему ключу
- [ ]
    Ключ: -1 со значением: 0
- [ ]
    Ошибка во время исполнения - под словарь не выделена память
- [x]
    Ключ: -1 со значением: 1

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
    virtual void get(){
        std::cout << 'B';
    }
};

class C: public B{
public:
    virtual void get(){
        std::cout << 'C';
    }
};

int main(){
    A* obj = new C;
    obj->get();
}

Ответы:
- [ ]
    Ошибка
- [x]
    A
- [ ]
    B
- [ ]
    C

---

Язык Go. Дан фрагмент кода:

type A struct{
    value int
}

func (a *A) get() int{
    return a.value
}

func (a *A) set(val int){
    a.value = val
}

type Accessor interface{
    get() int
    set(val int)
}

func main() {
    var obj A
    g := Accessor(&obj)
    g.set(10)
    
    fmt.Print(obj.get())
}

Что будет выведено в результате его работы?

Ответы:
- [x]
    10
- [ ]
    Ошибка
- [ ]
    0

---

Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?

class Point{
    char i;
public:
    Point(char val):i(val){}
};
 
int main(){
    Point p;
    std::cout << sizeof(p);
}

Ответы:
- [ ]
    2
- [ ]
    1
- [ ]
    4
- [x]
    Ошибка. Отсутствует конструктор по умолчанию
- [ ]
    0
- [ ]
    8

---

Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?

class SomeClass{
public:
    int value = 1;
    void method(int value){
        this->value = value;
    }
} s;

s.method(5);
std::cout << s.value;

Ответы:
- [x]
    5
- [ ]
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

func (d *Data) method(){
    d.i = 1
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
    0
- [x]
    Ошибка
- [ ]
    1
- [ ]
    Мусорное значение

---

Где можно объявить структуру в языке С++?

Ответы:
- [ ]
    Внутри списка параметров функции;
- [ ]
    Там, где указан возвращаемый тип функции;
- [x]
    Внутри тела функции;
- [x]
    Внутри других структур;
- [x]
    Вне функции;

---

Дан фрагмент кода на С++. Что будет содержать переменная container после его выполнения?

std::map<int, int> container;
int a = container[-1];

Ответы:
- [ ]
    Ошибка во время исполнения - под словарь не выделена память
- [ ]
    Ключ: -1 со значением: 1
- [x]
    Ключ: -1 со значением: 0
- [ ]
    Ошибка во время исполнения - попытка доступа к несуществующему ключу
- [ ]
    Ошибка компиляции - недопустимый тип
---

Дан фрагмент кода на С++. Что будет содержать переменная container2 после его выполнения?

std::vector<int> container1{4, 3, 2, 1, 2, 3, 4};
std::unordered_set<int> container2(container1.begin(), container1.end());

Ответы:
- [ ]
    1, 2, 3, 4
- [ ]
    4, 3, 2, 1, 2, 3, 4 но в порядке зависящем от хэш-функции
- [ ]
    4, 3, 2, 1, 2, 3, 4
- [ ]
    4, 3, 2, 1
- [x]
    1, 2, 3, 4 но в порядке зависящем от хэш-функции
---

Какое, из перечисленных, ключевых слов нужно использовать при объявлении структуры в Go?

Ответы:
- [ ]
    record
- [ ]
    Record
- [ ]
    structure
- [x]
    struct
- [ ]
    object
- [ ]
    Struct

---

Дан фрагмент кода на С++. Что будет содержать переменная container после его выполнения?

    std::vector<int> container{1, 2, 3, 2};
container[-1] = 5;

Ответы:
- [x]
    Ошибка доступа - указанного элемента не существует
- [ ]
    Пары: 1:2, 3:2, -1:5
- [ ]
    Ошибка компиляции - недопустимый тип
- [ ]
    Пары: -1:5, 1:2, 3:2
- [ ]
    Пары: 1:2, 3:2, 5:-1
---

Дан фрагмент кода на языке С++. Что выведется на экран в результате его работы?

enum Color {
    YELLOW,
    BLACK = 0,
    PINK,
    GREEN
};

Color color = Color::BLACK;
std::cout << color;

Ответы:
- [x]
    0
- [ ]
    Строка BLACK
- [ ]
    Ошибка. Для Color не определён оператор <<
- [ ]
    1
- [ ]
    Ошибка. Перечислителям нельзя задавать значения явно
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
    abc = append(abc, 4)
    change(abc)
    fmt.Println(abc)
}

Ответы:
- [ ]
    [4 4 4 4 4][1 2 3 4]
- [ ]
    [1 2 3 4][4 4 4 4 4]
- [ ]
    [4 4 4 4 4][4 4 4 4 4]
- [x]
    [4 4 4 4 4][4 4 4 4]
---

Дан код на языке Go:

package main
import "fmt"

func add(c map[int]int, value int){
    c[len(c)] = value
}

func main() {
    var container map[int]int = make(map[int]int)
    add(container, 10)
    fmt.Print(len(container))
}

В результате его исполнения:

Ответы:
- [ ]
    Переменная container не изменится;
- [x]
    Переменная container изменится;

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
    virtual void get(){
        std::cout << 'B';
    }
};

class C: public B{
public:
    virtual void get(){
        std::cout << 'C';
    }
};

int main(){
    C* obj = new A;
    obj->get();
}

Ответы:
- [x]
    Ошибка
- [ ]
    B
- [ ]
    C
- [ ]
    A

---

Язык Go. Дан фрагмент кода:

type A struct{
    value int
}

func (a *A) print(){
    fmt.Print("*")
}

type Printer interface{
    print()
}

func main() {
    var obj *A = nil
    p := Printer(obj)
    
    if p == nil{
        fmt.Print("+")
    } else {
        fmt.Print("-")
    }
}

Что будет выведено в результате его работы?

Ответы:
- [ ]
    0
- [ ]
    Ошибка
- [x]
    -
- [ ]
    +
- [ ]
    *

---

Дан фрагмент кода на С++:

    class MyClass{
public:
    double i = 1.0;
};

double operator+ (MyClass a, double b){
    return a.i + b;
}

MyClass obj;
double value = 2.0;

Выберите все выражения, которые НЕ вызовут ошибки:

Ответы:
- [ ]
    obj + obj;
- [x]
    obj + 2.0;
- [ ]
    value + obj;
- [x]
    obj + value;
- [x]
    value + value;
---

Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?

class Point{
    char i;
public:
    Point(char val=0):i(val){}
};
 
int main(){
    Point p;
    std::cout << sizeof(p);
}

Ответы:
- [ ]
    2
- [ ]
    4
- [x]
    1
- [ ]
    0
- [ ]
    8
- [ ]
    Ошибка. Отсутствует конструктор по умолчанию
---

Язык С++. Дан класс:

class SomeClass{
    int value = 0;
public:
    void one(){
        value = 1;
    }
    void one() const{
        std::cout << value;
    }
    
    void two(){
        value = 2;
    }
    
    void three() const {
        std::cout << 3;
    }
    
    void four() {
        std::cout << 4;
    }
};

и переменная созданная таким образом:

const SomeClass s;

Какие из перечисленных вызовов метода НЕ приведут к ошибке?

Ответы:
- [x]
    s.one();
- [ ]
    s.two();
- [ ]
    s.four();
- [x]
    s.three();

---

Каким образом можно создать переменную типа структура в языке С++?

Ответы:
- [x]
    struct Point{
    int x,y;
} p1, p2;
- [x]
    struct{
    int x,y;
} p1, p2;
- [ ]
    struct Point (p1, p2){
    int x,y;
};
- [x]
    struct Point{
    int x,y;
};

Point p1, p2;
- [ ]
    p1, p2: struct Point{
    int x,y;
};
- [ ]
    struct Point{
    int x,y;
};

Point;

---

Дан фрагмент кода на языке С++. Что выведется на экран в результате его работы?

    enum Color {
    YELLOW = 1,
    BLACK = 1,
    PINK,
    GREEN
};

Color color = Color::BLACK;
std::cout << color;

Ответы:
- [ ]
    Ошибка. Перечислителям нельзя задавать одинаковые значения
- [ ]
    0
- [x]
    1
- [ ]
    Ошибка. Для Color не определён оператор <<
- [ ]
    Строка BLACK

---

Язык Go. В текущий пакет из пакета other была импортирована структура:

type Book struct {
    Title       string
    author      string
    Description string
    Price       int
    pages       int
}

Какие поля будут доступны для использования в текущем пакете?

Ответы:
- [ ]
    author
- [x]
    Description
- [x]
    Price
- [ ]
    pages
- [x]
    Title

---

Дан фрагмент кода на Go. Что будет содержать переменная container после его выполнения?

var container map[int]int = make(map[int]int)
var a = container[-1]

Ответы:
- [ ]
    Ошибка во время исполнения - попытка доступа к несуществующему ключу
- [ ]
    Ключ: -1 со значением: 1
- [ ]
    Ошибка во время исполнения - под словарь не выделена память
- [ ]
    Ошибка компиляции - недопустимый тип
- [x]
    Ключ: -1 со значением: 0

---

Язык С++. Что будет напечатано в результате исполнения следующего кода?

#include <iostream>

class A{
    char value = 'a';
public:
    virtual void get(){
        std::cout << value;
    }
};

class B: public A{
    char value = 'b';
public:
    virtual void get(){
        std::cout << value;
    }
};

void print(A* obj){
    obj->get();
}

int main(){
    print(new B);
}

Ответы:
- [ ]
    Ошибка
- [x]
    b
- [ ]
    a

---

Дан фрагмент кода на С++:

    struct MyClass{
    double i = 1.0;
};

double operator+ (double a, MyClass b){
    return a + b.i;
}

MyClass obj;
double value = 2.0;

Выберите все выражения, которые НЕ вызовут ошибки:

Ответы:
- [ ]
    obj + obj;
- [x]
    value + value;
- [ ]
    obj + 2.0;
- [x]
    value + obj;
- [ ]
    obj + value;
---

Дан фрагмент кода на С++. Что отобразится на экране после его выполнения?

class Point{
    char i;
public:
    Point():i(0){}
    Point(char val=0):i(val){}
};
 
int main(){
    Point p;
    std::cout << sizeof(p);
}

Ответы:
- [x]
    Ошибка. Двусмысленность при вызове конструктора
- [ ]
    2
- [ ]
    0
- [ ]
    4
- [ ]
    1
- [ ]
    8
---

Язык С++. Дан класс:

class SomeClass{
    int non_static_value = 0;
    static const int static_value = 0;
public:
    static void static_method() {
    }
    static void other_static_method() {
    }    

    void non_static_method() {
    }
    void other_non_static_method() {
    }
};

Выберите все верные утверждения.

Ответы:
- [ ]
    Чтобы вызвать static_method обязательно нужно создать объект;
- [x]
    Чтобы вызвать static_method НЕ обязательно иметь объект;
- [ ]
    В static_method можно использовать non_static_method;
- [ ]
    В static_method можно использовать non_static_value;
- [x]
    В static_method можно использовать static_value;
- [x]
    В static_method можно использовать other_static_method;
---

Язык С++. Что будет напечатано в результате исполнения следующего кода?

#include <iostream>

class A{
    char value = 'a';
public:
    void get(){
        std::cout << value;
    }
};

class B: public A{
    char value = 'b';
public:
    void get(){
        std::cout << value;
    }
};

void print(A* obj){
    obj->get();
}

int main(){
    print(new B);
}

Ответы:
- [x]
    a
- [ ]
    b
- [ ]
    Ошибка

---

Язык С++. Дан класс:

class SomeClass{
    int non_static_value = 0;
    static const int static_value = 0;
public:
    static void static_method() {
    }
    static void other_static_method() {
    }    

    void non_static_method() {
    }
    void other_non_static_method() {
    }
};

Выберите все верные утверждения.

Ответы:
- [x]
    В non_static_method можно использовать static_value;
- [ ]
    Чтобы вызвать non_static_method НЕ обязательно иметь объект;
- [x]
    Чтобы вызвать non_static_method обязательно нужно создать объект;
- [x]
    В non_static_method можно использовать static_method;
- [x]
    В non_static_method можно использовать other_non_static_method;
- [x]
    В non_static_method можно использовать non_static_value;
---

Язык С++. Дана структура:

    struct Point{
    int x,y;
};

Каким образом можно создать переменную типа Point?

Ответы:
- [x]
    Point p = {};
- [ ]
    Point p();
- [x]
    Point p = {1, 1};
- [x]
    Point p {1, 2};
- [ ]
    Point p = [1, 1];
- [ ]
    Point(1, 2) p;
- [ ]
    Point p {x=1, y=1};
---

Язык С++. Что из перечисленного может быть использовано в качестве объявления конструктора по умолчанию для класса SomeClass?

Ответы:
- [ ]
    SomeClass(int a){}
- [ ]
    default SomeClass(){}
- [x]
    SomeClass(){}
- [x]
    SomeClass() = default;
- [x]
    SomeClass(int a=0, int b=0){}
- [ ]
    SomeClass(int a) = default;
---

Дан фрагмент кода на языке С++. Что выведется на экран в результате его работы?

enum Color {
    YELLOW = -2,
    BLACK,
    PINK = -1,
    GREEN = 0
};

Color color = Color::BLACK;
std::cout << color;

Ответы:
- [ ]
    1
- [ ]
    -3
- [x]
    -1
- [ ]
    Ошибка. Всем перечислителям должны быть заданы значения
- [ ]
    Ошибка. Для Color не определён оператор <<
---

Язык Go. Структуры A, B и С и переменные a, b, c объявлены следующим образом:

    type A struct {
    Title       string
    Author      string
}

type B struct {
    Title       string
    Author      string
}

type C = struct {
    Title       string
    Author      string
}
    
a := A{}
b := B{}
c := C{}

Выберите все допустимые выражения.

Ответы:
- [x]
    a = c
- [ ]
    b = a
- [ ]
    a = b
- [x]
    c = a
- [x]
    c = b
- [x]
    b = c
---

Дан фрагмент кода на С++:

class MyClass{
    double i = 1.0;
    friend double operator+ (MyClass a, double b);
};

double operator+ (MyClass a, double b){
    return a.i + b;
}

MyClass obj;
double value = 2.0;

Выберите все выражения, которые НЕ вызовут ошибки:

Ответы:
- [x]
    obj + value;
- [x]
    obj + 2.0;
- [x]
    value + value;
- [ ]
    value + obj;
- [ ]
    obj + obj;

---

Язык С++. Что из нижеперечисленного может быть полем структуры?

Ответы:
- [x]
    Структуры и Классы;
- [x]
    Указатели;
- [x]
    Фундаментальные типы (int, double, ...);
- [x]
    Строки;
- [x]
    Массивы;
---

Дан фрагмент кода на языке С++. Выберите верные утверждения.

enum Color {
    YELLOW = -2,
    BLACK,
    PINK = -2,
    GREEN
};

Ответы:
- [x]
    GREEN равно -1
- [x]
    BLACK равно -1
- [ ]
    Ошибка. Дублирование значений.
- [ ]
    GREEN и BLACK содержат мусорные значения
- [ ]
    GREEN равно -2
- [ ]
    BLACK равно -2

---

Язык Go. Какая структура называется анонимной?

Ответы:
- [ ]
    type anonymous struct {
    Title     string
    Author    string
}
- [x]
    var a struct {
    Title     string
    Author    string
}
- [ ]
    type struct {
    Title     string
    Author    string
}
- [ ]
    type {
    Title     string
    Author    string
}
- [ ]
    В Go нет анонимных структур

---

Язык С++. Для чего используется ключевое слово override?

Ответы:
- [ ]
    Если метод наследника отмечен этим ключевым словом, то он будет переопределять метод предка. Если не отмечен, то переопределения не будет;
- [ ]
    Это ключевое слово обязательно должно быть использовано если текущий метод переопределяет метод предка. Иначе будет ошибка компиляции;
- [x]
    Это ключевое слово НЕ обязательно использовать. Оно заставляет компилятор проверить, что у предка существует такой же метод как текущий и что он виртуальный. Если это не так, будет ошибка компиляции;
- [ ]
    Это ключевое слово используется в классе-предке, чтобы показать, что текущий метод необходимо переопределить в наследнике. Если в наследнике не будет такого метода, то компилятор кинет ошибку;
- [ ]
    Это ключевое слово ни на что не влияет и используется как своего рода комментарий, который показывает, что текущий метод переопределяет метод предка;

---

Дан фрагмент кода на С++. Каким образом можно создать один или несколько объектов класса Point?

struct Point{
    Point(){}
};

Ответы:
- [x]
    class Point p;
- [x]
    Point p;
- [x]
    Point p[10];
- [x]
    new Point;
- [ ]
    Point p();
- [x]
    new Point();
---

Дан фрагмент кода на С++. Что будет на экране в результате выполнения данного фрагмента?

class MyClass{
public:
    double i = 1.0;
};

MyClass obj;
if (obj) std::cout << 1;
else std::cout << 2;

Ответы:
- [x]
    Ошибка
- [ ]
    1
- [ ]
    2
---

Язык С++. Дана структура:

struct Point{
    int x,y;
};

Выберите фрагменты не вызывающие ошибки.

Ответы:
- [x]
    Point p = {1, 1}, p2;
p2 = p;
- [x]
    Point p;
p = {1, 1};
- [ ]
    Point p = {1, 1}, p2 = {2, 2};
p2 = p2 + p;
- [x]
    Point p = {1, 1}, p2 = {2, 2};
p2.x = p2.x + p.x;
p2.y = p2.y + p.y;
- [x]
    Point p = {1, 1}, p2;
p2 = {p.y, p.x};
---

Дан фрагмент кода на языке С++. Выберите верные утверждения.

enum Color {
    YELLOW = -1,
    BLACK = 0,
    PINK = 1,
    GREEN = 2
};

Ответы:
- [x]
    Color mix = Color(YELLOW + PINK); // mix будет равно BLACK
- [ ]
    Во всех остальных вариантах будет ошибка, т.к. для Color не определены операторы + и/или =
- [x]
    int i = YELLOW + PINK; // i будет равно 0
- [ ]
    Color mix = YELLOW + PINK; // mix будет равно BLACK
---

Код на С++. Требуется запретить доступ к конструктору класса Point из внешнего кода, как это можно сделать?

Ответы:
- [ ]
    __Point__();
- [ ]
    ~Point();
- [ ]
    Никак
- [x]
    private: Point();
- [ ]
    explicit Point();
- [ ]
    private Point();
---

Язык Go. Дан тип данных и функция:

type Point struct {
    x, y int
}

func foo(p Point){
    p.x = 10
    p.y = 10
}

Если передать переменную типа Point в функцию foo указанным выше образом, то:

Ответы:
- [ ]
    Ошибка. Т.к. структуры нельзя передавать в функции;
- [x]
    Внутри функции будет доступна копия структуры;
- [ ]
    Внутри функции будет создана пустая структура (т.е. поля содержат нули);
- [ ]
    Внутри функции будет доступен оригинал структуры;
---

Дан фрагмент кода на С++. Что будет на экране в результате выполнения данного фрагмента?

class MyClass{
public:
    double i = 1.0;
    operator bool(){
        return i > 1.0;
    }
};

MyClass obj;
if (obj) std::cout << 1;
else std::cout << 2;

Ответы:
- [x]
    2
- [ ]
    Ошибка
- [ ]
    1

---

Язык С++. Какая структура называется анонимной?

Ответы:
- [ ]
    struct Point{
    int x,y;
} s;
- [ ]
    struct anonymous{
    int x,y;
} s;
- [ ]
    anonymous struct Point{
    int x,y;
} s;
- [ ]
    В С++ нет анонимных структур
- [ ]
    struct Point{
    int x,y;
} anonymous;
- [x]
    struct {
    int x,y;
} s;
---

Дан фрагмент кода на языке С++. Выберите верные утверждения.

enum class Color {
    YELLOW = -1,
    BLACK = 0,
    PINK = 1,
    GREEN = 2
};

Ответы:
- [x]
    Во всех остальных вариантах будет ошибка, т.к. для Color не определены операторы + и/или =
- [ ]
    Color mix = Color(Color::YELLOW + Color::PINK); // mix будет равно BLACK
- [ ]
    int i = Color::YELLOW + Color::PINK; // i будет равно 0
- [ ]
    Color mix = Color::YELLOW + Color::PINK; // mix будет равно BLACK
---

Код на С++. Сколько конструкторов может быть у класса?

Ответы:
- [ ]
    Только 3
- [ ]
    Только 2
- [x]
    Сколько угодно
- [ ]
    Только 1
---

Дан фрагмент кода на С++. Что будет на экране в результате выполнения данного фрагмента?

class MyClass{
public:
    double i = 1.0;
    void operator*(double b){
        i * b;
    }
};

MyClass obj;
std::cout << obj * 1.0;

Ответы:
- [ ]
    2
- [ ]
    1
- [x]
    Ошибка
---

Язык С++. Дан тип данных и прототип функции:

    struct Point{
    int x,y;
};

void foo(Point p);

Если передать переменную типа Point в функцию foo указанным выше образом, то:

Ответы:
- [x]
    Внутри функции будет доступна копия структуры;
- [ ]
    Внутри функции будет создана пустая структура (т.е. поля содержат "мусор");
- [ ]
    Внутри функции будет доступен оригинал структуры;
- [ ]
    Ошибка. Т.к. структуры нельзя передавать в функции;
---

Язык С++. Что из перечисленного является правильным объявлением и определением класса?

Ответы:
- [x]
    class SomeClass{};
- [ ]
    class SomeClass{}
- [ ]
    struct SomeClass{}
- [x]
    struct SomeClass{};
- [ ]
    SomeClass class {};
- [ ]
    class SomeClass: {};
---

Дан фрагмент кода на языке С++:

enum class Color {
    YELLOW = 0,
    BLACK = 1,
    PINK = 2
};
Color color = Color::BLACK;

и функция с представленным ниже прототипом:

void foo(Color clr);

Какой вариант вызова функции НЕ приведёт к ошибке?

Ответы:
- [x]
    foo(Color(1));
- [x]
    foo(color);
- [ ]
    foo(1);
- [x]
    foo(Color::YELLOW);
- [ ]
    foo(YELLOW);
- [ ]
    foo("YELLOW");
---

Дан фрагмент кода на С++. Что будет на экране в результате выполнения данного фрагмента?

class MyClass{
public:
    double i = 1.0;
    double operator*(double b){
        return i * b;
    }
};

MyClass obj;
std::cout << obj * 1.0;

Ответы:
- [ ]
    2
- [ ]
    Ошибка
- [x]
    1
---

Дан фрагмент кода на языке С++:

struct One{
    int x,y;
} a;

struct Two{
    int x,y;
} b;

Допустим ли следующий код?

a = {1, 2};
b = a;

Ответы:
- [ ]
    Да, b получит копию полей a;
- [ ]
    Да, a и b будут ссылаться на одни и те же значения;
- [ ]
    Нет, для типа данных: структура, разрешено только почленное присваивание;
- [x]
    Нет, т.к. у a и b разные типы;

---

Язык С++. Где можно объявить/определить новый класс?

Ответы:
- [ ]
    В списке параметров функции
- [x]
    Внутри других классов
- [x]
    В теле функции
- [x]
    Внутри конструкции блок {}
- [x]
    В глобальной области видимости
---

Дан фрагмент кода на языке С++:

enum Color {
    YELLOW = 0,
    BLACK = 1,
    PINK = 2
};
Color color = Color::BLACK;

и функция с представленным ниже прототипом:

void foo(Color clr);

Какой вариант вызова функции НЕ приведёт к ошибке?

Ответы:
- [x]
    foo(color);
- [x]
    foo(Color::YELLOW);
- [ ]
    foo(1);
- [ ]
    foo("YELLOW");
- [x]
    foo(YELLOW);
- [x]
    foo(Color(1));
---

Дан фрагмент кода на языке С++:struct One{
    int x,y;
} a, b;

Допустим ли следующий код?

a = {1, 2};
b = a;

Ответы:
- [ ]
    Нет, для типа данных: структура, разрешено только почленное присваивание;
- [ ]
    Нет, т.к. у a и b разные типы;
- [ ]
    Да, a и b будут ссылаться на одни и те же значения;
- [x]
    Да, b получит копию полей a;
---

Язык С++.  Дано перечисление. Выберите все способы получения значения со стандартного ввода.

enum Color {
    YELLOW = 0,
    BLACK = 1,
    PINK = 2
} color;

Ответы:
- [x]
    int i;
std::cin >> i; // Пользователь вводит число: 0
color = static_cast<Color>(i);
- [ ]
    std::cin >> color; // Пользователь вводит строку: YELLOW
- [ ]
    std::string str;
std::cin >> str; // Пользователь вводит строку: YELLOW
color = static_cast<Color>(str);
- [ ]
    std::cin >> color; // Пользователь вводит число: 0
- [x]
    int i;
std::cin >> i; // Пользователь вводит число: 0
color = Color(i);

---

Дан фрагмент кода на языке С++. Что будет напечатано в результате его выполнения?

struct SomeClass{
    int i = 0;
    int j = 0;
    
    SomeClass(){
        i = 10;
    }
    
    SomeClass(int value):SomeClass(){
        j = value;
    }
};

SomeClass obj(10);
std::cout << obj.i << ' ' << obj.j;

Ответы:
- [ ]
    0 10
- [ ]
    10 0
- [ ]
    0 0
- [x]
    10 10
---

Дан фрагмент кода на языке С++. Что будет напечатано в результате его выполнения?

struct SomeClass{
    int i = 0;
    int j = 0;
    
    SomeClass(){
        i = 10;    
    }
    
    SomeClass(int value){
        SomeClass();
        j = value;
    }
};

SomeClass obj(10);
std::cout << obj.i << ' ' << obj.j;

Ответы:
- [ ]
    0 0
- [x]
    0 10
- [ ]
    10 10
- [ ]
    10 0
---

Дан фрагмент кода на языке С++. Что будет напечатано в результате его выполнения?

    struct SomeClass{
    int i = 0;
    
    SomeClass(int i){
        i = i;
    }
};

SomeClass obj(10);
std::cout << obj.i;

Ответы:
- [ ]
    Ошибка
- [x]
    0
- [ ]
    10
---

Дан фрагмент кода на языке С++. Что будет напечатано в результате его выполнения?

    struct SomeClass{
    int i = 0;
    
    SomeClass(int i){
        this->i = i;
    }
};

SomeClass obj(10);
std::cout << obj.i;

Ответы:
- [x]
    10
- [ ]
    0
- [ ]
    Ошибка
---

Дан фрагмент кода на языке С++. Что будет напечатано в результате его выполнения?

    struct SomeClass{
    int i = 0;
    
    SomeClass(int i):i(i){
    }
};

SomeClass obj(10);
std::cout << obj.i;

Ответы:
- [ ]
    0
- [x]
    10
- [ ]
    Ошибка
---

Язык С++. От чего зависит порядок инициализации полей класса, указанных в списке инициализаторов?

Ответы:
- [ ]
    Порядок случайный
- [ ]
    От того, в каком порядке эти поля перечислены в списке инициализаторов
- [x]
    От того, в каком порядке эти поля объявлены
- [ ]
    От того, как какие у полей модификаторы доступа

---

Дан фрагмент кода на языке С++. Что будет напечатано в результате его выполнения?

struct SomeClass{
    const int i = 0;
    
    SomeClass(int i):i(i){
    }
};

SomeClass obj(10);
cout << obj.i;

Ответы:
- [ ]
    Ошибка
- [x]
    10
- [ ]
    0

---

Дан фрагмент кода на языке С++. Что будет напечатано в результате его выполнения?

    struct SomeClass{
    const int i = 0;
    
    SomeClass(int i){
        this->i = i;
    }
};

SomeClass obj(10);
std::cout << obj.i;

Ответы:
- [x]
    Ошибка
- [ ]
    10
- [ ]
    0

---

Дан фрагмент кода на языке С++. Что будет напечатано в результате его выполнения?

struct SomeClass{
    int& i;
    
    SomeClass(int& i):i(i){
    }
};

int i = 0;
SomeClass obj(i);
std::cout << obj.i;

Ответы:
- [ ]
    Ошибка
- [x]
    0
- [ ]
    10
---

Дан фрагмент кода на языке С++. Что будет напечатано в результате его выполнения?

struct SomeClass{
    int& i;
    
    SomeClass(int& i){
        this->i = i;
    }
};

int i = 0;
SomeClass obj(i);
std::cout << obj.i;

Ответы:
- [ ]
    0
- [ ]
    10
- [x]
    Ошибка
