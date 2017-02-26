#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>

#include "Player.h"
#include "PlayerSorting.h"

bool DescOrderInt(int a, int b);

struct StrDescOrderInt
{
	bool operator()(int a, int b) const
	{
		return a > b;
	}
};

void PrintPlayerHeader();
void PrintPlayer(Player * p);

int main(int argc, char *argv[])
{
	const int array[] = { 10, 20, 5, 15, 0 };
	std::vector<int> vec(array, array + 5);

	// basic sort
	std::sort(vec.begin(), vec.end());

	// basic sort, descending
	std::sort(vec.begin(), vec.end(), DescOrderInt);

	// -- sort with std::function --
	std::function<bool(int, int)> sorter = StrDescOrderInt();
	
	std::sort(vec.begin(), vec.end(), sorter);

	for(int val : vec)
		std::cout << val << " ";
	std::cout << std::endl;

	// == PLAYER ==
	std::vector<Player *> players;

	players.push_back(new Player("Bastian Schweinsteiger", 23, 4));
	players.push_back(new Player("Xavi", 17, 5));
	players.push_back(new Player("Andres Iniesta", 15, 9));
	players.push_back(new Player("Lionel Messi", 21, 20));
	players.push_back(new Player("Wesley Sneijder ", 24, 6));
	players.push_back(new Player("Mesut Oezil", 19, 10));
	players.push_back(new Player("Asamoah Gyan", 22, 15));
	players.push_back(new Player("David Villa ", 13, 16));
	players.push_back(new Player("Diego Forlan", 20, 10));
	players.push_back(new Player("Arjen Robben", 11, 12));

	// raw data
	PrintPlayerHeader();

	for(Player * p : players)
		PrintPlayer(p);
	std::cout << std::endl;

	// -- SORTING FUNCTIONS --
	std::vector< std::function<bool(Player *, Player *)> > sorters;
	sorters.push_back(PlayerSorting::SortPlayerByNameAsc());
	sorters.push_back(PlayerSorting::SortPlayerByCapsAsc());
	sorters.push_back(PlayerSorting::SortPlayerByGoalsAsc());
	sorters.push_back(PlayerSorting::SortPlayerByNameDes());
	sorters.push_back(PlayerSorting::SortPlayerByCapsDes());
	sorters.push_back(PlayerSorting::SortPlayerByGoalsDes());

	// sort by goals, descending
	std::sort(players.begin(), players.end(), sorters[5]);

	PrintPlayerHeader();

	for(Player * p : players)
		PrintPlayer(p);
	std::cout << std::endl;

	// sort by name, ascending
	std::sort(players.begin(), players.end(), sorters[0]);

	PrintPlayerHeader();

	for(Player * p : players)
		PrintPlayer(p);
	std::cout << std::endl;

	// sort by caps, descending
	std::sort(players.begin(), players.end(), sorters[4]);

	PrintPlayerHeader();

	for(Player * p : players)
		PrintPlayer(p);
	std::cout << std::endl;

	return 0;
}

bool DescOrderInt(int a, int b)
{
	return a > b;
}

void PrintPlayerHeader()
{
	std::cout << std::endl << std::setw(25) << std::left << "NAME" << std::setw(6) << "CAPS" << std::setw(6) << "GOALS" << std::endl;
}

void PrintPlayer(Player * p)
{
	std::cout << std::setw(25) << std::left << p->GetName() << std::setw(6) << p->GetCaps() << std::setw(6) << p->GetGoals() << std::endl;
}

