#include <iostream>
#include <cmath>
#include <string>

std::string to_new_sys(std::string num, int n1, int n2);

int main()
{
  setlocale(LC_ALL, "ru");

  int n1 = 0;
  std::string num1;
  
  int n2 = 0;
  std::string num2;

  std::cout << "Какое основание системы счисления у исходного числа? \t"; std::cin >> n1;
  std::cout << "Какое основание системы счисления у нового числа? \t"; std::cin >> n2;
  std::cout << "\nВведите число в " << n1 << "-ой системе счисления: "; std::cin >> num1;
  std::cout << "\nВаше число в системе с основанием " << n2 << ": \t" << to_new_sys(num1, n1, n2) << "\n\n";

  return 0;
}


double to_ten(std::string num, int n)
{
  // num    - число с основанием n
  // n    - основание системы числа num
  // ten_num  - новое число в десятичной системе
  // dagree  - степень
  
  double ten_num = 0;
  int dagree = num.size() - 1;

  bool is_negative = num[0] == '-';
  if (is_negative) num.erase(0, 1);

  for (int i = 0; i < num.size(); i++)
  {
    if (num[i] == '.')
    {
      dagree = i - 1;
      num.erase(i, 1);
      break;
    }
  }

  for (int i = 0; i < num.size(); i++)
  {
    if (num[i] <= '9')
      ten_num += (char(num[i]) - '0') * (pow(n, dagree));
    else
      ten_num += (char(num[i] - 'A' + 10)) * (pow(n, dagree));
    dagree--;

  }

  if (is_negative) ten_num *= -1;

  return ten_num;
}

std::string in_ten(double num, int n)
{
  // num    - дробная часть десятичного числа
  // n    - новое основание для числа new_num
  // new_num  - число с основанием n
  // num_whole- целая часть десятичного числа

  std::string new_num;
  int num_whole = num;
  num -= num_whole;

  bool is_negative = num < 0;
  if (is_negative)
  {
    num *= -1;
    num_whole *= -1;
  }

  if (n < 37)
  {
    while (num_whole)
    {
      num_whole % n <= 9 ? new_num = std::to_string(num_whole % n) + new_num : new_num = char((num_whole % n - 10) + 'A') + new_num;
      num_whole /= n;
    }
  }
  else
  {
    int i = 0;
    while (num_whole)
    {
      new_num = '(' + std::to_string(num_whole % n) + " * " + std::to_string(n) + '^' + std::to_string(i) + ')' + new_num;
      num_whole /= n;
      i++;
    }
  }

  if (num != 0.0) new_num.push_back('.');

  int whole = 0;
  for (int i = 0; (i < 10 && num != 0.0); i++)
  {
    num = num * static_cast<double>(n);
    whole = static_cast<int>(num);
    if (n < 37)
    {
      whole > 9 ? new_num = new_num + char('A' + (whole - 10)) : new_num = new_num + std::to_string(whole);
    }
    else
    {
      new_num = new_num + '(' + std::to_string(whole) + " * " + std::to_string(n) + "^(-" + std::to_string(i+1) + "))";
    }
    num -= whole;
  }

  if (is_negative) new_num = "-" + new_num;

  return new_num;
}

bool is_correct(std::string num, int n)
{
  // функция проверяет, допустимо ли такое число num в системе счисления с основанием n
  bool dot = false;

  for (int i = 0; i < num.size(); i++) 
    if (!((num[i] >= '0' && num[i] <= '9') || (num[i] >= 'A' && num[i] <= 'Z') || (num[i] == '.' && !dot) || (num[i] == '-'))) return false;
  return true;
}

std::string to_new_sys(std::string num, int n1, int n2)
{
  std::string new_num;

  if (is_correct(num, n1))
  {
    new_num = in_ten(to_ten(num, n1), n2);
  }
  else
  {
    new_num = "Ошибка! Значение \"" + num + "\" не возможно представить в " + std::to_string(n1) + "-ой системе счисления! Проверьте правильность введённого значения. Для записи числа можно использовать символы 0-9, A-Z, \'-\', \'.\'";
  }

  return new_num;
}

