#ifndef _POKEMON_
#define _POKEMON_
#define POKECOUNT 150
#include <string>

struct Poke {
        int id;
	std::string name;
	std::string pose;
	std::string battle;
        int level;
        double health;
        double hp_per_lvl;
        double attack;
        double att_per_lvl;
        double defense;
        double def_per_lvl;
};

extern std::vector<Poke> monsters;
extern Poke party[6];
extern Poke EMPTY;

void pokemon_init();

#endif

