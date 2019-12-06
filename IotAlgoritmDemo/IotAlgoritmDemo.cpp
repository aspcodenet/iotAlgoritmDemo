#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

enum class Position
{
	Goalie,
	Defence,
	Forward
};

class Player
{
	string fornamn;
	string efternamn;
	Position position;
	int salary;
public:
	Position GetPosition() { return position; }
	string GetFornamn() { return fornamn; }
	string GetEfternamn() { return efternamn; }
	int GetSalary() { return salary; }
	void SetNewSalary(int s) { salary = s; }
	Player(string fornamn, string efternamn, Position position, int salary)
	{
		this->salary = salary;
		this->fornamn = fornamn;
		this->efternamn = efternamn;
		this->position = position;
	}
};




int main()
{
	vector<int> talLista = { 1,323,545,55,45,213,55, 231231,231 };
	
	auto result = minmax_element(begin(talLista), end(talLista));


	replace(talLista.begin(), talLista.end(), 55, 0);
	//replace(begin(talLista), end(talLista), 55, 0);

	//sort(talLista.begin(), talLista.end(), std::greater<int>());
	reverse(talLista.begin(),talLista.end());

	for (auto i : talLista)
	{
		cout << i << endl;
	}



	vector<Player> players = {
		Player("William", "Karlsson", Position::Forward,5000),
		Player("Mats", "Sundin", Position::Forward,4000),
		Player("Masken", "Karlsson", Position::Forward,3000),
		Player("Peter","Forsberg",  Position::Forward,3000),
		Player("Niklas", "Lidström", Position::Defence,4000)
	};

	int antal = count_if(begin(players), end(players), [](Player p) {
		if (p.GetPosition() == Position::Forward && p.GetSalary() > 4500) return true;
		return false;
		});

	bool foundGoalie = all_of(players.begin(), players.end(), [](Player& p) {
		if (p.GetPosition() == Position::Goalie) return true;
		return false;
		//return p.GetPosition() == Position::Goalie;
		});


	for_each(players.begin(), players.end(), [](Player& p) {
		p.SetNewSalary(p.GetSalary() + 10);
		});

	for (Player &p : players)
	{
		p.SetNewSalary(p.GetSalary() + 10);
	}

	for (auto pl : players)
	{
		cout << pl.GetFornamn() << " " << pl.GetSalary() << endl;
	}



	sort(players.begin(), players.end(), [](Player p1, Player p2) 
				{
					if (p1.GetEfternamn() == p2.GetEfternamn())
						return p1.GetFornamn() < p2.GetFornamn();
					return p1.GetEfternamn() < p2.GetEfternamn();
				}
	);
	for (auto pl : players)
	{
		cout << pl.GetFornamn() << endl;
	}











    std::cout << "Hello World!\n";
}
