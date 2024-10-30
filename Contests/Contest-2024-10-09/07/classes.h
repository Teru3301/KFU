#pragma once

//	каюсь, код не мой
//	но разве не пофиг если он работает?


#include <vector>
#include <algorithm>

class Bigint {
public:
    std::vector<int> arr; //
    bool znak; // знак
    std::string str;//строковое представление

    std::string stringfi() {
        std::string res;
        for (auto i : this->arr) res = std::to_string(i) + res;
        if (this->znak and res != "0") { res = "-" + res;  }
        return res;
    }

    Bigint() {
        this->znak = false;
        this->arr.push_back(0);
        this->str = this->stringfi();
    }

    Bigint(int a) {
        if (a == 0) {
            this->arr.push_back(0);
            this->znak = false;
            this->str = this->stringfi();
        }
        else {
        this->znak = false;
        if (a < 0) {
            this->znak = true;
            a *= -1;
        }
        while (a > 0) {
            this->arr.push_back(a % 10);
            a /= 10;
        }
        this->str = this->stringfi();
        }
    }

    Bigint(std::string a) {
        int k = 0;
        this->znak = false;
        for (auto i : a) {
            if (k == 0 and i == '-') {
                this->znak = true;
                continue;
            }
            int buf = (int)i-48;
            this->arr.push_back(buf);
            k += 1;
        }
        std::reverse(this->arr.begin(), this->arr.end());
        this->str = this->stringfi();
    }

    bool operator > (const Bigint& b) const
    {
        if (this->arr == b.arr and this->znak == b.znak)return false;
        else if (this->arr.size() == b.arr.size() and !this->znak and !b.znak) {
            for (int i = this->arr.size() - 1; i >= 0;i--) {
                if (this->arr[i] == b.arr[i]) continue;
                if (this->arr[i] > b.arr[i]) return true;
                if (this->arr[i] < b.arr[i]) return false;
            }
        }
        else if (this->arr.size() == b.arr.size() and this->znak and b.znak) {
            for (int i = this->arr.size() - 1; i >= 0;i--) {
                if (this->arr[i] == b.arr[i]) continue;
                if (this->arr[i] > b.arr[i]) return false;
                if (this->arr[i] < b.arr[i]) return true;
            }
        }
        else if (this->znak and !b.znak)return false;
        else if (!this->znak and b.znak)return true;
        else if (this->arr.size() > b.arr.size() and !this->znak and !b.znak) return true;
        return false;
    }

    bool operator < (const Bigint& b) const
    {   
        if (*this == b) return false;
        return !(*this>b);
    }

    bool operator == (const Bigint& b) const
    {
        if (this->arr == b.arr and this->znak == b.znak)return true;
        return false;
    }
};

Bigint plus(Bigint a, Bigint b) {
    int carry = 0;
    for (size_t i = 0; i < std::max(a.arr.size(), b.arr.size()) || carry; ++i) {
        if (i == a.arr.size())
            a.arr.push_back(0);
        a.arr[i] += carry + (i < b.arr.size() ? b.arr[i] : 0);
        carry = a.arr[i] >= 10;
        if (carry)  a.arr[i] -= 10;
    }
    return a;
}

Bigint raz(Bigint a, Bigint b) {
    int carry = 0;
    a.znak = false;
    b.znak = false;
    bool f;
    if (a > b or a == b) f = false;
    if (a < b) {
        f = true;
        Bigint res;
        res = a;
        a = b;
        b = res;
    }
    for (size_t i = 0; i < b.arr.size() || carry; ++i) {
        a.arr[i] -= carry + (i < b.arr.size() ? b.arr[i] : 0);
        carry = a.arr[i] < 0;
        if (carry)  a.arr[i] += 10;
    }
    while (a.arr.size() > 1 && a.arr.back() == 0)
        a.arr.pop_back();
    a.znak = f;
    return a;
}

std::ostream& operator<<(std::ostream& out, const Bigint& num) {
    out << (num.str);
    return out;
}

Bigint operator +(Bigint a, Bigint b){
    Bigint res;
    res.arr.pop_back();
    if (a.znak != 1 and b.znak != 1) {
        res = plus(a, b);
    }
    else if (a.znak and b.znak) {
        a.znak = false;
        b.znak = false;
        res = plus(a,b);
        res.znak = true;
    }
    else if (a.znak != 1 and b.znak) {
        res = raz(a, b);
    }
    else if (a.znak and b.znak != 1) {
        res = raz(b, a);
    }
    res.str = res.stringfi();
    return res;
}

Bigint operator -(Bigint a, Bigint b) {
    Bigint res;
    if (a.znak != 1 and b.znak != 1) {
        res = raz(a,b);
    }
    else if (a.znak and b.znak != 1) {
        a.znak = false;
        res = plus(a,b);
        res.znak = true;
    }
    else if (a.znak and b.znak) {
        b.znak = false;
        a.znak = false;
        res = raz(b,a);
    }
    else if (a.znak != 1 and b.znak) {
        b.znak = false;
        res = plus(a,b);
    }
    res.str = res.stringfi();
    return res;
}

Bigint operator *(Bigint a, Bigint b) {
    Bigint res;
    res.arr.pop_back();
    res.arr.insert(res.arr.cbegin(),a.arr.size() + b.arr.size(),0);
    for (size_t i = 0; i < a.arr.size(); ++i)
        for (int j = 0, carry = 0; j < (int)b.arr.size() || carry; ++j) {
            long long cur = res.arr[i + j] + a.arr[i] * 1ll * (j < (int)b.arr.size() ? b.arr[j] : 0) + carry;
            res.arr[i + j] = int(cur % 10);
            carry = int(cur / 10);
        }
    while (res.arr.size() > 1 && res.arr.back() == 0)
        res.arr.pop_back();
    if (a.znak == b.znak) res.znak = false;
    if (a.znak != b.znak) res.znak = true;
    res.str = res.stringfi();
    return res;
}

Bigint operator /(Bigint a, Bigint b) {
    int k = 0;
    bool f;
    Bigint res;
    res.arr.pop_back();
    if (a.znak == b.znak) f = false;
    if (a.znak != b.znak) f = true;
    a.znak = false;
    b.znak = false;
    if (a < b) return Bigint(0);
    while (true) {
        k += 1;
        Bigint buf = (b * Bigint(k));
        if ((a == buf)) {
            res = Bigint(k);
            break;
        }
        if ((a < buf)) {
            res = Bigint(k-1);
            break;
        }
    }
    res.znak = f;
    res.str = res.stringfi();
    return res;
}






//	Вот он мой код

/*

#include <vector>

class Bigint
{
	public:
		Bigint (std::string num);
		Bigint (long long integer_num);
		Bigint ();
		Bigint (const Bigint &other);
		friend std::ostream& operator<< (std::ostream &ostr, const Bigint bigint);

		const bool operator> (const Bigint &other);	
		const bool operator< (const Bigint &other);	
		const bool operator== (const Bigint &other);

		Bigint operator= (const Bigint &other);
		const Bigint operator+ (const Bigint &other);
		const Bigint operator- (const Bigint &other);
		const Bigint operator* (const Bigint &other);
		const Bigint operator/ (const Bigint &other);
		
		friend std::ostream& operator<< (std::ostream &ostr, const Bigint bigint);
	
		Bigint reverse();
		const std::string BTS(const Bigint bigint);
		//	Cause I, I, I'm in the stars tonight
		//	So watch me bring the fire and set the night alight
		//	Shoes on, get up in the morn'
		//	Cup of milk, let's rock and roll
		//	King Kong, kick the drum, rolling on like a Rolling Stone
		//	Sing song when I'm walking home
		//	Jump up to the top, LeBron
		//	Ding-dong, call me on my phone
		//	Ice tea and a game of ping pong

	private:
		std::vector<long long> number;
		bool negative;

		Bigint abs(const Bigint number);

};


Bigint::Bigint(std::string str_num)
{
	if (!str_num.size())
	{
		this->number.push_back(0);
		return;
	}

	if (str_num[0] == '-')
	{
		this->negative = true;
		str_num.replace(0, 1, "");
	}
	else this->negative = false;

	while (str_num.size())
	{
		std::string sub_str;
		int index_copy = 0;
		
		if (str_num.size() >= 8) index_copy = str_num.size() - 8;
		for (int i = 0; i + index_copy < str_num.size(); i++)
			sub_str.push_back(str_num[i + index_copy]);
	
		str_num.replace(index_copy, sub_str.size(), "");
		long long tmp_num = stoll(sub_str);
		
		this->number.push_back(tmp_num);
	}
	
	if (this->number.size() == 1 && this->number[0] == 0) this->negative = false;
	if (this->negative)
		for (auto &num : number)
			num *= -1;
}

Bigint::Bigint(long long integer_num)
{
	*this = Bigint(std::to_string(integer_num));	
}

Bigint::Bigint()
{
	this->number.push_back(0);
	this->negative = false;
}

Bigint::Bigint (const Bigint &other)
{
	this->negative = other.negative;
	this->number.resize(other.number.size());
	for (int i = 0; i < other.number.size(); i++)
		this->number[i] = other.number[i];
}


const std::string Bigint::BTS (const Bigint bigint)
{
	std::string str_num = "";
	Bigint tmp(bigint);
	tmp = abs(tmp);
	std::string tmp_str;
	for (int i = tmp.number.size() - 1; i >= 0; i--)
	{
		tmp_str = std::to_string(tmp.number[i]);
		while(tmp_str.size() < 8) tmp_str = '0' + tmp_str;
		str_num += tmp_str;
	}
	while (str_num[0] == '0') str_num.replace(0, 1, "");
	if (bigint.negative) str_num = '-' + str_num;

	if (str_num == "-" || str_num == "-0" || str_num == "") str_num = '0';

	return str_num;
}

Bigint Bigint::abs(const Bigint number)
{
	Bigint tmp = number;
	tmp.negative = false;
	for (int i = 0; i < tmp.number.size(); i++)
		if (tmp.number[i] < 0) tmp.number[i] = -tmp.number[i];

	return tmp;
}

Bigint Bigint::reverse()
{
	this->negative = !this->negative;
	for (int i = 0; i < this->number.size(); i++)
		this->number[i] *= -1;
	return *this;
}

std::ostream& operator<< (std::ostream &ostr, const Bigint bigint)
{
	ostr << Bigint().BTS(bigint);
	return ostr;
}


const bool Bigint::operator> (const Bigint &other)
{
	std::string str_num1 = BTS(abs(*this));
	std::string str_num2 = BTS(abs(other));
	if (str_num1.size() != str_num2.size()) return str_num1.size() > str_num2.size();
	if (this->negative != other.negative) return !this->negative;
	if (this->negative) return str_num1 < str_num2;
	return str_num1 > str_num2;
}

const bool Bigint::operator< (const Bigint &other)
{
	std::string str_num1 = BTS(abs(*this));
	std::string str_num2 = BTS(abs(other));
	if (str_num1.size() != str_num2.size()) return str_num1.size() < str_num2.size();
	if (this->negative != other.negative) return this->negative;
	if (this->negative) return str_num1 > str_num2;
	return str_num1 < str_num2;
}

const bool Bigint::operator== (const Bigint &other)
{
	std::string str_num1 = BTS(*this);
	std::string str_num2 = BTS(other);
	return str_num1 == str_num2;
}


Bigint Bigint::operator= (const Bigint &other)
{
	this->number.resize(other.number.size());
	for (int i = 0; i < other.number.size(); i++)
		this->number[i] = other.number[i];
	this->negative = other.negative;
	
	return *this;
}


const Bigint Bigint::operator+ (const Bigint &other)
{
	Bigint sum;
	sum.number.pop_back();
	Bigint max = (abs(*this) > abs(other) ? *this : other);
	Bigint min = (max == *this ? other : *this);
	long long tmp_num;
	long long buffer = 0;

	for (long long i = 0; ; i++)
	{
		tmp_num = buffer;
		buffer = 0;
		if (i < max.number.size()) tmp_num += max.number[i];
		if (i < min.number.size()) tmp_num += min.number[i];
		if (!max.negative && tmp_num < 0)
			{ tmp_num += 100000000; buffer = -1; }
		if (max.negative && tmp_num > 0)
			{ tmp_num -= 100000000; buffer = 1; }
		Bigint tmp_bigint(std::to_string(tmp_num));
		if (tmp_bigint.number.size() > 1) buffer = 1;
		if (max.negative) buffer *= -1;
		if (i >= max.number.size() && i >= min.number.size() &&
				!buffer && tmp_bigint == Bigint("0")) break;
		sum.number.push_back(tmp_bigint.number[0]);
	}
	sum.negative = max.negative;

	return sum;
}

const Bigint Bigint::operator- (const Bigint &other)
{
	Bigint copy(other);
	copy.reverse();
	return *this + copy;
}

const Bigint Bigint::operator* (const Bigint &other)
{
	Bigint mul;
	long long ind_rank = 0;
	for (auto other_num : other.number)
	{
		for (auto this_num : this->number)
		{
			Bigint tmp_bigint;
			tmp_bigint.number.pop_back();

			for (int i = 0; i < ind_rank; i++)
				tmp_bigint.number.push_back(0);
			ind_rank++;

			Bigint tmp_b2(std::to_string(other_num * this_num)); 
			tmp_b2 = abs(tmp_b2);					//	так и не понял что тут не так
			for (auto tb2 : tmp_b2.number)
				tmp_bigint.number.push_back(tb2);
			mul = mul + tmp_bigint;
		}
		ind_rank -= this->number.size();
		ind_rank++;
	}
	mul.negative = this->negative != other.negative;
	for (auto num : mul.number)
		if (mul.negative && num > 0 || !mul.negative && num < 0)
			num *= -1;
	
	return mul;
}

const Bigint Bigint::operator/ (const Bigint &other)
{
	Bigint div;
	Bigint tmp("1");	

	Bigint divisor(abs(other));
	Bigint reminder(*this);
	reminder = abs(reminder);

	while (!(reminder < abs(other)))
	{
		if (reminder > divisor + divisor)
		{
			divisor = divisor + divisor;
			tmp = tmp + tmp;
			continue;
		}
		reminder = reminder - divisor;
		divisor = abs(other);
		div = div + tmp;
		tmp = Bigint("1");
	}
	if (this->negative != other.negative) div.reverse();

	return div;
}

*/





