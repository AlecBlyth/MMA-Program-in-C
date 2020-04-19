#pragma once

#include <iostream>
using namespace std;

class Fighter
{
private:

	int fighterID;
	int age;
	int weight;
	int height;
	int wins;
	int losses;
	int strength;
	int speed;
	int endurance;
	int subDefence;
	int subOffence;

	string firstName;
	string lastName;
	string fullName;
	string nationality;
	string fightingOut;
	string fightStyle;

public:

	Fighter (int id, string firName, string surName, string nation, string fightOut, string style, int fightAge, int fightWeight, int fightHeight, int fightStrength, int fightSpeed, int fightEndurance, int subOff, int subDef, int win, int lost);

	void setFighter(int id, string firName, string surName, string nation, string fightOut, string style, int fightAge, int fightWeight, int fightHeight, int fightStrength, int fightSpeed, int fightEndurance, int subOff, int subDef, int win, int lost);

	//Getters

	int getID() {
		return fighterID;
	}
	string getName() {
		fullName = firstName + " " + lastName;
		return fullName;
	}
	string getNation() {
		return nationality;
	}
	string getFightout() {
		return fightingOut;
	}
	string getStyle() {
		return fightStyle;
	}
	int getWeight() {
		return weight;
	}
	int getAge() {
		return age;
	}
	int getHeight() {
		return height;
	}
	int getStrength() {
		return strength;
	}
	int getSpeed() {
		return speed;
	}
	int getEndurance() {
		return endurance;
	}
	int getSubDef() {
		return subDefence;
	}
	int getSubOff() {
		return subOffence;
	}
	int getWins() {
		return wins;
	}
	int getLoss() {
		return losses;
	}

	//Setters 
	void setStrength(int str) {
		strength = str;
	}
	void setEndurance(int end) {
		endurance = end;
	}
	void setSpeed(int spe) {
		speed = spe;
	}
	void setSubOff(int off) {
		subOffence = off;
	}
	void setSubDef(int def) {
		subDefence = def;
	}
	void setWins(int w) {
		wins = w;
	}
	void setLosses(int l) {
		losses = l;
	}

};
