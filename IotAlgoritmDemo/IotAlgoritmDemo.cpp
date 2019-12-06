#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum class Position
{
	Goalie,
	Defence,
	Forward
};

class Player
{
	string name;
	Position position;
public:
	Position GetPosition() { return position; }
	string GetName() { return name; }
	Player(string name, Position position)
	{
		this->name = name;
		this->position = position;
	}
};



int main()
{
    std::cout << "Hello World!\n";
}
