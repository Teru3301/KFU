# Список вопросов 5 теста Чабанова

Как запустить горутину в Go?

Отыет:
- [x] go funcName()
- [ ] go funcName
- [ ] defer funcName()
- [ ] funcName() as goroutine
- [ ] funcName() go

---


Что из перечисленного является объявлением конструктора копирования класса SomeClass?

Ответ:
- [x] SomeClass(const SomeClass& other);
- [ ] SomeClass(SomeClass&& other);
- [ ] SomeClass(SomeClass other);
- [ ] SomeClass& operator=(SomeClass&& other);
- [ ] SomeClass();

---


Выберите все выражения, которые не вызовут ошибку, при условии, что переменная a объявлена как: int a = 4;

Ответ:
- [x] int& r1 = a;
- [ ] int&& r2 = a;
- [ ] int& r3 = a + 1;
- [x] int&& r4 = a + 1;
- [x] int& r5 = r1;
- [ ] int&& r6 = r1;
- [x] int& r7 = r4;
- [ ] int&& r8 = r4;

---


Дан фрагмент кода на языке С++. Какой модификатор доступа у valueA в классе B ?
```cpp
class A{
public:
    int valueA = 1;
};

class B: private A{
public:
    int valueB = 5;
};
```

Ответ:
- [ ] public
- [x] private
- [ ] protected
- [ ] published
- [ ] поле не доступно

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    void get(){
        std::cout << 'A';
    }
};

class B{
public:
    void get(){
        std::cout << 'B';
    }
};

class C: public B, public A{
public:
    void get(){
        std::cout << 'C';
    }
};

C obj;
obj.get();
```

Ответ:
- [x] C
- [ ] CAB
- [ ] CBA
- [ ] ABC
- [ ] BAC
- [ ] Ничего

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    int value = 1;
};

class B{
public:
    int value = 5;
};

class C: public A, public B{
public:
    int value = 9;
};

C obj;
std::cout << obj.value;
```

Ответ:
- [ ] 1
- [ ] 5
- [x] 9
- [ ] Ошибка

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    int value = 1;
    A(){
    	value = 5;
    }
    A(int value){
    	this->value = 9;
    }
};

class B: public A{
public:
    B(int value):A(value){};
};

B obj(1);
std::cout << obj.value;
```

Ответ:
- [ ] 1
- [ ] 5
- [x] 9
- [ ] Ошибка

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    A(){
        std::cout << 'A';
    }
};

class B{
public:
    B(){
        std::cout << 'B';
    }
};

class C: public A, public B{
public:
    C(){
        std::cout << 'C';
    }
};

C obj;
```

Ответ:
- [ ] C
- [ ] CAB
- [ ] BAC
- [x] ABC
- [ ] CBA
- [ ] Ничего

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    A(){
        std::cout << 'A';
    }
};

class B{
public:
    B(){
        std::cout << 'B';
    }
};

class C: public B, public A{
public:
    C(){
        std::cout << 'C';
    }
};

C obj;
```

Ответ:
- [ ] C
- [ ] CAB
- [x] BAC
- [ ] ABC
- [ ] CBA
- [ ] Ничего

---


Как обозначается r-value ссылка на значение типа int в С++?

Ответ:
- [ ] int*
- [ ] int**
- [x] int&&
- [ ] int&
- [ ] int^
- [ ] int^^

---


Какие из следующих вариантов использования мьютекса в Go являются правильными (считаем, что в процессе работы с данными ошибки быть не может)?

Ответ:
- [x] 
  ```cpp
  func foo() {
      mutex.Lock()
      // работа с данными
      mutex.Unlock()
  }
  ```
- [x] 
  ```cpp
  func foo() {
      mutex.Lock()
      defer mutex.Unlock()
      // работа с данными
  }
  ```
- [ ] 
  ```cpp
  func foo() {
      mutex.Unlock()
      // работа с данными
      mutex.Lock()
  }
  ```
- [ ] 
  ```cpp
  func foo() {
      mutex.Lock()
      // работа с данными
  }
  ```
- [ ] 
  ```cpp
  func foo() {
      mutex.Unlock()
      // работа с данными
  }
  ```

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    int value = 1;
    A(){
    	value = 5;
    }
    A(int value){
    	value = 9;
    }
};

class B: public A{
public:
    B(int value){};
};

B obj(1);
std::cout << obj.value;
```

Ответ:
- [ ] 1
- [x] 5
- [ ] 9
- [ ] Ошибка

---


Что такое горутина в Go?

Ответ:
- [x] Легковесный поток выполнения
- [ ] Объект, который управляет памятью
- [ ] Переменная, хранящая данные
- [ ] Функция, которая может быть вызвана только один раз
- [ ] Поток с приоритетом

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
struct А{
    int value = 1;
};

struct B: A{
    int value = 1;
    B(int value){
        this->value = value;
    }
};

B obj(5);
std::cout << obj.value;
```

Ответ:
- [ ] 1
- [x] 5
- [ ] Ошибка

---


Как обозначается l-value ссылка на значение типа int в С++?

Ответ:
- [ ] int*
- [ ] int&&
- [ ] int^
- [ ] int^^
- [x] int&
- [ ] int**

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
struct А{
    int value = 1;
};

struct B: A{
    int value = 1;
    B(int value){
        this->A::value = value;
    }
};

B obj(5);
std::cout << obj.value;
```

Ответ:
- [x] 1
- [ ] 5
- [ ] Ошибка

---


Как разблокировать мьютекс в Go?

Ответ:
- [x] mutex.Unlock()
- [ ] mutex.Free()
- [ ] mutex.Delete()
- [ ] mutex.Exit()
- [ ] mutex.Release()

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    void get(){
        std::cout << 'A';
    }
};

class B{
};

class C: public B, public A{
};

C obj;
obj.get();
```

Ответ:
- [x] A
- [ ] B
- [ ] C
- [ ] AB
- [ ] BA
- [ ] Ошибка

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    int value = 1;
    void set_value(int value){
        this->value = value;
    }
};

class B: public A{
public:
    int value = 1;
    void set_value(int value){
        this->value = value;
    }
};

B obj;
obj.set_value(5);
std::cout << obj.value;
```

Ответ:
- [ ] 1
- [x] 5
- [ ] Ошибка

---


Как заблокировать мьютекс в Go?

Ответ:
- [x] mutex.Lock()
- [ ] mutex.Block()
- [ ] mutex.Capture()
- [ ] mutex.Wait()
- [ ] mutex.Claim()

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    void get(){
        std::cout << 'A';
    }
};

class B{
public:
    void get(){
        std::cout << 'B';
    }
};

class C: public B, public A{
public:
    void get(){
        B::get();
    }
};

C obj;
obj.get();
```

Ответ:
- [ ] A
- [x] B
- [ ] C
- [ ] AB
- [ ] BA
- [ ] Ошибка

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    int value = 1;
};

class B{
public:
    int value = 5;
};

class C: public A, public B{
};

C obj;
std::cout << obj.value;
```

Ответ:
- [ ] 1
- [ ] 5
- [ ] 9
- [x] Ошибка

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
struct А{
    A(int value){
        this->value = value;
    }
    int value = 1;
};

struct B: A{
    B(int value){
        this->value = value;
    }
};

B obj(5);
std::cout << obj.value;
```

Ответ:
- [ ] 1
- [ ] 5
- [x] Ошибка

---


Что будет выведено на экран в результате работы этого кода?
```cpp
#include <iostream>

void foo(int& a){
    std::cout << "+" << std::endl;
}

void foo(int&& a){
    std::cout << "-" << std::endl;
}

int main(){
    int a = 4;
    foo(a);
}
```

Ответ:
- [x] +
- [ ] -

---

Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    void get(){
        std::cout << 'A';
    }
};

class B{
public:
    void get(){
        std::cout << 'B';
    }
};

class C: public B, public A{
};

C obj;
obj.get();
```

Ответ:
- [ ] A
- [ ] B
- [ ] C
- [ ] AB
- [ ] BA
- [x] Ошибка

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
struct А{
    int value = 1;
};

struct B: A{
    B(int value){}
};

B obj(5);
std::cout << obj.value;
```

Ответ:
- [x] 1
- [ ] 5
- [ ] Ошибка

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    int value = 1;
    void set_value(int value){
        this->value = value;
    }
};

class B: public A{
public:
    int value = 1;
};

B obj;
obj.set_value(5);
std::cout << obj.value;
```

Ответ:
- [x] 1
- [ ] 5
- [ ] Ошибка

---


Что из перечисленного является объявлением конструктора перемещения класса SomeClass?

Ответ:
- [x] SomeClass(SomeClass&& other);
- [ ] SomeClass(SomeClass other);
- [ ] SomeClass();
- [ ] SomeClass(const SomeClass& other);
- [ ] SomeClass& operator=(SomeClass&& other);

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
struct А{
    int value = 1;
};

struct B: private A{
    B(int value){
        this->value = value;
    }
};

B obj(5);
std::cout << obj.value;
```

Ответ:
- [ ] 1
- [ ] 5
- [x] Ошибка

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
private:
    int valueA = 1;
};

class B: public A{
public:
    int valueB = 5;
};
```

Ответ:
- [x] поле не доступно
- [ ] public
- [ ] private
- [ ] protected
- [ ] published

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    ~A(){
        std::cout << 'A';
    }
};

class B{
public:
    ~B(){
        std::cout << 'B';
    }
};

class C: public B, public A{
public:
    ~C(){
        std::cout << 'C';
    }
};

C obj;
```

Ответ:
- [ ] ABC
- [ ] BAC
- [x] CAB
- [ ] CBA
- [ ] C
- [ ] Ничего

---


Что будет выведено на экран в результате работы этого кода?
```cpp
#include <iostream>

void foo(int& a){
    std::cout << "+" << std::endl;
}

void foo(int&& a){
    std::cout << "-" << std::endl;
}

int main(){
    int a = 4;
    foo(a + 1);
}
```

Ответ:
- [x] -
- [ ] +

---


Что такое мьютекс в Go?

Ответ:
- [x] Механизм синхронизации доступа горутин к общим ресурсам
- [ ] Структура данных для хранения результата работы горутины
- [ ] Тип переменной для передачи данных в горутину
- [ ] Интерфейс для работы с каналами
- [ ] Функция для создания горутин

---


Дан фрагмент кода на языке С++. Какой модификатор доступа у valueA в классе B ?
```cpp
struct A{
    int valueA = 1;
};

class B: protected A{
public:
    int valueB = 5;
};
```

Ответ:
- [ ] public
- [ ] private
- [x] protected
- [ ] published
- [ ] поле не доступно

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
struct А{
    int value = 1;
};

struct B: A{
    B(int value){
        this->value = value;
    }
};

B obj(5);
std::cout << obj.value;
```

Ответ:
- [ ] 1
- [x] 5
- [ ] Ошибка

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    int value = 1;
    A(){
    	value = 5;
    }
    A(int value){
    	value = 9;
    }
};

class B: public A{
public:
    B(int value):A(value){};
};

B obj(1);
std::cout << obj.value;
```

Ответ:
- [x] 1
- [ ] 5
- [ ] 9
- [ ] Ошибка

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    ~A(){
        std::cout << 'A';
    }
};

class B{
public:
    ~B(){
        std::cout << 'B';
    }
};

class C: public A, public B{
public:
    ~C(){
        std::cout << 'C';
    }
};

C obj;
```

Ответ:
- [ ] ABC
- [ ] BAC
- [ ] CAB
- [x] CBA
- [ ] C
- [ ] Ничего

---


Дан фрагмент кода на языке С++. Что будет на экране в результате выполнения данного фрагмента?
```cpp
class A{
public:
    void set_value(int value){
        this->value = value;
    }
};

class B: public A{
public:
    int value = 1;
};

B obj;
obj.set_value(5);
std::cout << obj.value;
```

Ответ:
- [ ] 1
- [ ] 5
- [x] Ошибка

---


