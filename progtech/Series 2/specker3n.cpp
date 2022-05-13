#ifndef CONTEST
#define SPECKER_V3
#include "specker2n.cpp"
#endif

class Game
{ /*{{{*/
public:
    Game(int heaps, int players) {
        Players = new Player*[players];
        Heaps = new int[heaps];
        playerSize = players;
        heapSize = heaps;
        AddedHeap = 0;
        AddedPlayer = 0;
    }
    ~Game() {
        delete[] Players;
        delete[] Heaps;
    }

    void addHeap(int coins) {
        if (coins < 0)
            throw std::logic_error("You can't add negative coins in a heap.");
        else if (AddedHeap >= heapSize)
            throw std::logic_error("There is no free heap."); 
        else {
            Heaps[AddedHeap++] = coins;
        }

    }

    void addPlayer(Player *player) {
        if (AddedPlayer >= playerSize)
            throw std::logic_error("You can't add another players in the table.");
        else {
            Players[AddedPlayer] = player;
            AddedPlayer++;
        }
    }
    
    void play(std::ostream &out) {
        State SpeckerGame(heapSize, Heaps, playerSize);
        PlayingNow = 0;
        while (!SpeckerGame.winning()) {
            out << "State: " << SpeckerGame << std::endl;
            out << *Players[PlayingNow];
            Move playerMove = Players[PlayingNow]->play(SpeckerGame);
            out << " " << playerMove << std::endl;
            SpeckerGame.next(playerMove);
            if (PlayingNow + 1 >= playerSize) PlayingNow = 0;
            else PlayingNow++;
        }
        if (SpeckerGame.winning()) out << "State: " << SpeckerGame << std::endl;
        if (PlayingNow == 0) PlayingNow = SpeckerGame.getPlayers();
        out << *Players[PlayingNow - 1] << " wins" << std::endl;
        
    }

    int getPlayers() const {
        return playerSize;
    }

    const Player *getPlayer(int p) const {
        return Players[p];
    }

private :
    Player** Players;
    int *Heaps;
    int playerSize;
    int heapSize;
    int AddedHeap;
    int AddedPlayer;
    int PlayingNow;
}; /*}}}*/

#ifndef CONTEST
int main()
{ /*{{{*/
    Game specker(7, 4);
    specker.addHeap(10);
    specker.addHeap(0);
    specker.addHeap(10);
    specker.addHeap(0);
    specker.addHeap(10);
    specker.addHeap(0);
    specker.addHeap(10);
    specker.addPlayer(new SneakyPlayer("Ontis"));
    specker.addPlayer(new SpartanPlayer("Tsosmilk"));
    specker.addPlayer(new GreedyPlayer("Siko"));
    specker.addPlayer(new RighteousPlayer("Isasko"));
    specker.play(std::cout);
} /*}}}*/
#endif