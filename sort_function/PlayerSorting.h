class Player;

class PlayerSorting
{
public:
	// -- NAME --
	struct SortPlayerByNameAsc { bool operator()(Player * p1, Player * p2) const; };
	struct SortPlayerByNameDes { bool operator()(Player * p1, Player * p2) const; };

	// -- CAPS --
	struct SortPlayerByCapsAsc { bool operator()(Player * p1, Player * p2) const; };
	struct SortPlayerByCapsDes { bool operator()(Player * p1, Player * p2) const; };

	// -- GOALS --
	struct SortPlayerByGoalsAsc { bool operator()(Player * p1, Player * p2) const; };
	struct SortPlayerByGoalsDes { bool operator()(Player * p1, Player * p2) const; };
};
