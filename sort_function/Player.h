#include <string>

class Player
{
public:
	Player(const char * name, int caps, int goals);

	const std::string & GetName() const;

	int GetCaps() const;
	int GetGoals() const;

private:
	std::string mName;

	int mCaps;
	int mGoals;
};

inline Player::Player(const char * name, int caps, int goals) : mName(name), mCaps(caps), mGoals(goals) {}

inline const std::string & Player::GetName() const { return mName; }

inline int Player::GetCaps() const { return mCaps; }
inline int Player::GetGoals() const { return mGoals; }

