#pragma once
class Room
{
public:
	Room();
	~Room();

	std::string getDescription();

private:
	std::string description;
};

