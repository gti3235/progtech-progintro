#include <iostream>
#include <stdexcept>
#include <string>

class Move
{ /*{{{*/
public:
    Move(int sh, int sc, int th, int tc)
    {
        SourceHeap = sh;
        SourceCoins = sc;
        TargetHeap = th;
        TargetCoins = tc;
    }

    int getSource() const
    {
        return SourceHeap;
    }
    int getSourceCoins() const
    {
        return SourceCoins;
    }
    int getTarget() const
    {
        return TargetHeap;
    }
    int getTargetCoins() const
    {
        return TargetCoins;
    }

    friend std::ostream &operator<<(std::ostream &out, const Move &move)
    {
        if (move.TargetCoins != 0)
            out << "takes " << move.SourceCoins << " coins from heap " << move.SourceHeap << " and puts " << move.TargetCoins << " coins to heap " << move.TargetHeap;
        else
            out << "takes " << move.SourceCoins << " coins from heap " << move.SourceHeap << " and puts nothing";
        return out;
    }

private:
    int SourceHeap, SourceCoins, TargetHeap, TargetCoins;
}; /*{{{*/

class State
{ /*{{{*/
public:
    State(int h, const int c[], int n)
    {
        sizeOfHeaps = h;
        heaps = new int[sizeOfHeaps];
        players = n;
        playingNow = 0;
        for (int i = 0; i < sizeOfHeaps; i++)
            heaps[i] = c[i];
    }
    ~State()
    {
        delete[] heaps;
    }

    void next(const Move &move) //throw(logic_error)
    {
        if (move.getSource() < 0 || move.getSource() >= sizeOfHeaps || move.getTarget() < 0 || move.getTarget() >= sizeOfHeaps || heaps[move.getSource()] - move.getSourceCoins() < 0 || move.getSourceCoins() < 0 || move.getTargetCoins() < 0 || move.getTargetCoins() >= move.getSourceCoins())
        {
            throw std::logic_error("invalid heap");
        }
        else
        {
            heaps[move.getSource()] -= move.getSourceCoins();
            heaps[move.getTarget()] += move.getTargetCoins();
        }

        if (players == 2)
        {
            if (playingNow == 1)
                playingNow = 0;
            else if (playingNow == 0)
                playingNow = 1;
        }
        else
        {
            if (playingNow == players - 1)
                playingNow = 0;
            else
                playingNow++;
        }
    }

    bool winning() const
    {
        int counter = 0;
        for (int i = 0; i < sizeOfHeaps; i++)
        {
            if (heaps[i] == 0)
                counter++;
        }
        if (counter == sizeOfHeaps)
            return true;
        return false;
    }

    int getHeaps() const
    {
        return sizeOfHeaps;
    }
    int getCoins(int h) const //throw(logic_error)
    {
        if (h < 0 || h >= sizeOfHeaps)
            throw std::logic_error("invalid heap");
        return heaps[h];
    }

    int getPlayers() const
    {
        return players;
    }
    int getPlaying() const
    {
        return playingNow;
    }

    friend std::ostream &operator<<(std::ostream &out, const State &state)
    {
        for (int i = 0; i < state.sizeOfHeaps - 1; i++)
            out << state.heaps[i] << ", ";
        out << state.heaps[state.sizeOfHeaps - 1] << " with " << state.getPlaying() << "/" << state.getPlayers() << " playing next";
        return out;
    }

private:
    int sizeOfHeaps;
    int *heaps;
    int players;
    int playingNow;
}; /*{{{*/

#ifndef SPECKER_V2
#ifndef CONTEST
int main()
{
}
#endif
#endif