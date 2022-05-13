#include <iostream>
#include <stdexcept>
#include <string>
#include <climits>

#ifndef CONTEST
#define SPECKER_V2
#include "specker1n.cpp"
#endif

class Player
{ /*{{{*/
public:
	Player(const std::string &n)
	{
		PlayerName = n;
	}
	virtual ~Player()
	{
		PlayerName.clear();
	}

	virtual const std::string &getType() const = 0;
	virtual Move play(const State &s) = 0;

	friend std::ostream &operator<<(std::ostream &out, const Player &player)
	{
		out << player.getType() << " player " << player.PlayerName;
		return out;
	}

private:
	std::string PlayerName;
}; /*}}}*/

class GreedyPlayer : public Player
{
public:
	GreedyPlayer(const std::string &n) : Player(n){};
	virtual const std::string &getType() const override
	{
		return type;
	}
	virtual Move play(const State &s) override
	{
		int maxCoinHeap = 0;
		int CoinInHeap = 0;
		for (int i = 0; i < s.getHeaps(); i++)
		{
			if (CoinInHeap < s.getCoins(i))
			{
				maxCoinHeap = i;
				CoinInHeap = s.getCoins(i);
			}
		}
		return Move(maxCoinHeap, CoinInHeap, 0, 0);
	}

private:
	std::string type = "Greedy";
};

class SpartanPlayer : public Player
{
public:
	SpartanPlayer(const std::string &n) : Player(n){};
	virtual const std::string &getType() const override
	{
		return type;
	}
	virtual Move play(const State &s) override
	{
		int maxCoinHeap = 0;
		int CoinInHeap = 0;
		for (int i = 0; i < s.getHeaps(); i++)
		{
			if (CoinInHeap < s.getCoins(i))
			{
				maxCoinHeap = i;
				CoinInHeap = s.getCoins(i);
			}
		}
		return Move(maxCoinHeap, 1, 0, 0);
	}

private:
	std::string type = "Spartan";
};

class SneakyPlayer : public Player
{
public:
	SneakyPlayer(const std::string &n) : Player(n){};
	virtual const std::string &getType() const override
	{
		return type;
	}
	virtual Move play(const State &s) override
	{
		int minCoinHeap;
		int CoinInHeap;
		int counterForZero = 0;
		while (s.getCoins(counterForZero) == 0) counterForZero++;
		minCoinHeap = counterForZero;
		CoinInHeap = s.getCoins(counterForZero);
			for (int i = 0; i < s.getHeaps(); i++)
			{
				if (CoinInHeap > s.getCoins(i) && s.getCoins(i) != 0)
				{
					minCoinHeap = i;
					CoinInHeap = s.getCoins(i);
				}
			}
		return Move(minCoinHeap, CoinInHeap, 0, 0);
	}

private:
	std::string type = "Sneaky";
};

class RighteousPlayer : public Player
{
public:
	RighteousPlayer(const std::string &n) : Player(n){};
	virtual const std::string &getType() const override
	{
		return type;
	}
	virtual Move play(const State &s) override
	{
		int maxCoinHeap = 0;
		int minCoinHeap = 0;
		int xCoinInHeap = 0;
		int nCoinInHeap = s.getCoins(0);
		for (int i = 0; i < s.getHeaps(); i++)
		{
			if (xCoinInHeap < s.getCoins(i))
			{
				maxCoinHeap = i;
				xCoinInHeap = s.getCoins(i);
			}
			if (nCoinInHeap > s.getCoins(i))
			{
				minCoinHeap = i;
				nCoinInHeap = s.getCoins(i);
			}
		}
		xCoinInHeap -= xCoinInHeap / 2;
		return Move(maxCoinHeap, xCoinInHeap, minCoinHeap, xCoinInHeap - 1);
	}

private:
	std::string type = "Righteous";
};

#ifndef SPECKER_V3
#ifndef CONTEST
int main()
{
}
#endif
#endif