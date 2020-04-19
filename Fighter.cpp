#include "Fighter.h"

Fighter::Fighter(int id, string firName, string surName, string nation, string fightOut, string style, int fightAge, int fightWeight, int fightHeight, int fightStrength, int fightSpeed, int fightEndurance, int subOff, int subDef, int win, int lost)
{
	setFighter(id, firName, surName, nation, fightOut, style, fightAge, fightWeight, fightHeight, fightStrength, fightSpeed, fightEndurance, subOff, subDef, win, lost);
}

void Fighter::setFighter(int id, string firName, string surName, string nation, string fightOut, string style, int fightAge, int fightWeight, int fightHeight, int fightStrength, int fightSpeed, int fightEndurance, int subOff, int subDef, int win, int lost)
{
	fighterID = id;
	firstName = firName;
	lastName = surName;
	nationality = nation;
	fightingOut = fightOut;
	fightStyle = style;
	age = fightAge;
	weight = fightWeight;
	height = fightHeight;
	strength = fightStrength;
	speed = fightSpeed;
	endurance = fightEndurance;
	subOffence = subOff;
	subDefence = subDef;
	wins = win;
	losses = lost; 
}




