Complex make_complex(std::string num)
{
    while (num.find(' ') != 18446744073709551615) num.replace(num.find(' '), 1, "");

    std::string n1 = "";
    std::string n2 = "";

    int it = 1;

    n1 += num[0];
    while (num[it] != '+' && num[it] != '-')
    {
        n1 += num[it];
        it++;
    }
    while (it < num.length())
    {
        n2 += num[it];
        it++;
    }

    Complex com;
    com.re = stod(n1);
    com.im = stod(n2);
    return com;
}

Complex sum(Complex c1, Complex c2)
{
    Complex com;
    com.re = c1.re + c2.re;
    com.im = c1.im + c2.im;
    return com;
}

Complex sub(Complex c1, Complex c2)
{
    Complex com;
    com.re = c1.re - c2.re;
    com.im = c1.im - c2.im;
    return com;
}

Complex mul(Complex c1, Complex c2)
{
    Complex com;
    com.re = c1.re * c2.re - c1.im * c2.im;
    com.im = c1.im * c2.re + c2.im * c1.re;
    return com;
}

Complex div(Complex c1, Complex c2)
{
    Complex com;
    double den = c2.re * c2.re + c2.im * c2.im;
    com.re = (c1.re * c2.re + c1.im * c2.im) / den;
    com.im = (c1.im * c2.re - c1.re * c2.im) / den;
    return com;
}

void print(Complex num)
{
    std::cout << num.re;
    if (num.im >= 0) std::cout << '+';
    std::cout << num.im;
    std::cout << 'j' << std::endl;
}
