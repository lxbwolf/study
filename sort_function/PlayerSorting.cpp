#include "PlayerSorting.h"

#include "Player.h"

// -- NAME --
bool PlayerSorting::SortPlayerByNameAsc::operator()(Player * p1, Player * p2) const
{
	return p1->GetName() < p2->GetName();
}

bool PlayerSorting::SortPlayerByNameDes::operator()(Player * p1, Player * p2) const
{
	return p1->GetName() > p2->GetName();
}

// -- CAPS --
bool PlayerSorting::SortPlayerByCapsAsc::operator()(Player * p1, Player * p2) const
{
	return p1->GetCaps() < p2->GetCaps();
}

bool PlayerSorting::SortPlayerByCapsDes::operator()(Player * p1, Player * p2) const
{
	return p1->GetCaps() > p2->GetCaps();
}

// -- GOALS --
bool PlayerSorting::SortPlayerByGoalsAsc::operator()(Player * p1, Player * p2) const
{
	return p1->GetGoals() < p2->GetGoals();
}

bool PlayerSorting::SortPlayerByGoalsDes::operator()(Player * p1, Player * p2) const
{
	return p1->GetGoals() > p2->GetGoals();
}

