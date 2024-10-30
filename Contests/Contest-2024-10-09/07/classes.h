#pragma once

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







