#include <iostream>
#include <stack>
#include <string>

// Функция возвращает оператор
bool isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

// Функция определяет приоритет оператора
int getPriority(char operation) 
{
    if (operation == '+' || operation == '-')
    {
        return 1;
    }
    else if (operation == '*' || operation == '/' || operation == '%')
    {
        return 2;
    }
    else if (operation == '^')
    {
        return 3;
    }
    return 0;
}

// Функция преобразует выражение в обратную польскую нотацию
std::string infixToPostfix(const std::string& infix) 
{
    std::string postfix;
    std::stack<char> operators;

    for (char c : infix) 
    {
        if (std::isdigit(c))
        {
            postfix += c;
        }
        else if (c == '(') 
        {
            operators.push(c);
        }
        else if (c == ')') 
        {
            while (!operators.empty() && operators.top() != '(') 
            {
                postfix += " ";
                postfix += operators.top();
                operators.pop();
            }

            operators.pop(); // remove '('
        }
        else if (isOperator(c)) 
        {
            // Условие должно учитывать, что все одинаковые операторы, кроме оператора возведения в степень,
            // могут идти между числами.
            while (!operators.empty() && (getPriority(operators.top()) > getPriority(c) 
                || (getPriority(operators.top()) == getPriority(c) && c != '^')))
            {
                postfix += " ";
                postfix += operators.top();
                operators.pop();
            }

            postfix += " ";
            operators.push(c);
        }
    }

    while (!operators.empty()) 
    {
        postfix += " ";
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() 
{
    std::string infixExpression;
    std::getline(std::cin, infixExpression);

    std::string postfixExpression = infixToPostfix(infixExpression);

    std::cout << postfixExpression << std::endl;
}
