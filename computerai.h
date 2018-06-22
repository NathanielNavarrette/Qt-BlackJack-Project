#ifndef COMPUTERAI_H
#define COMPUTERAI_H

#include "player.h"
#include "gameoptions.h"

class ComputerAi : public Player
{
public:
    ComputerAi();

    void set_difficulty(int difficulty);
    int do_bet();
    bool do_hit();

private:
    void rng_bet();
    void hit_or_not();

};

#endif // COMPUTERAI_H
