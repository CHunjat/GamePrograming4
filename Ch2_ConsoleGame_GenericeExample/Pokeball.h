#pragma once

#include <iostream>
#include <string>

class PokeMon
{
private:
	int _number;
	std::string _name;

public:
	PokeMon(int number, std::string name)
		: _number(number), _name(name) {}

	int get_number() const
	{
		return _number;
	}

	std::string get_name() const
	{
		return _name;
	}

};
