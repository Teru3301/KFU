
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
