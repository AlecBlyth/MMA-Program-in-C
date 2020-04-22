// MMAFightingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Fighter.h"

using namespace std;

int input; //Input string for menu
int selection; //Selection int for fighter selection 
int s; //Fighter selection int for fighter selected
int x; //Opponent selection int

//Declaration of functions
void fightMenu(vector<Fighter>fighterVector);
void trainerMenu(vector <Fighter> fighterVector);
void gameMenu(vector <Fighter> fighterVector); 
void menu(vector <Fighter> fighterVector);
void fightFunction(vector<Fighter> fighterVector);


//Algorithmic functions  

bool gameMaths(float probabilityOfSuccess) { //Calcuates a random chance for fights based on input value. 
	return rand() % 100 < (probabilityOfSuccess * 100);
} 

void fightFunction(vector<Fighter>fighterVector) {

	//Player Attributes

	int wins_1 = fighterVector[s].getWins();
	int wins_2 = fighterVector[x].getWins();

	int losses_1 = fighterVector[s].getLoss();
	int losses_2 = fighterVector[x].getLoss();

	int str_1 = fighterVector[s].getStrength();
	int str_2 = fighterVector[x].getStrength();

	int end_1 = fighterVector[s].getEndurance();
	int end_2 = fighterVector[x].getEndurance();

	int sub_O1 = fighterVector[s].getSubOff();
	int sub_O2 = fighterVector[x].getSubOff();

	int sub_Def1 = fighterVector[s].getSubDef();
	int sub_Def2 = fighterVector[x].getSubDef();

	int hp_1 = 100 + end_1;
	int hp_2 = 100 + end_2;

	int ap_1 = 100 + str_1 / 10;
	int ap_2 = 100 + str_2 / 10;

	double speed_1 = fighterVector[s].getSpeed() / 100 / 5; 
	double speed_2 = fighterVector[x].getSpeed() / 100 / 5;

	//Fight Variables 

	bool fightOver = false; ///Boolean to check if fight is over 
	int fightCount = 5; //Emulates fight rounds 

	//Main Algorithm

	while (hp_1 > 0 && hp_2 > 0 && fightCount != 0 && fightOver == false) { //While the fighters still have hp and fight is not over 

		switch (gameMaths(0.10)) { //0.10 chance of submission take down 
		case true: //if true 
			if (sub_O1 > sub_Def2) { //if the selected player's offence is more than defence then 
				switch (gameMaths(0.25)) { //0.25% chance of take down
				case true:
					cout << fighterVector[s].getName() << " takes down " << fighterVector[x].getName() << endl;
					hp_2 = hp_2 - (sub_O1); //second fighter's health is deducted by first fighter's submission offence
				}
			}
			else {
				switch (gameMaths(0.10)) { //If the defence is higher then take down attempt is 0.01% chance of successful takedown 
				case true:
					cout << fighterVector[s].getName() << " takes down " << fighterVector[x].getName() << endl;
					hp_2 = hp_2 - (sub_O1);
				}
			}
			if (hp_2 <= 0) { //If the takedown is successful and fighter health is less than or equal to 0 then 
				cout << fighterVector[x].getName() << " taps out!" << endl; //prompt user
				fighterVector[x].setLosses(losses_2 + 1); //set losses plus one
				fighterVector[s].setWins(wins_1 + 1); // set win plus one
				fightOver = true; //set fight over to true
				gameMenu(fighterVector); //return to menu 
			}
		case false: // same as above but reversed for second fighter
			if (sub_O2 > sub_Def1) {
				switch (gameMaths(0.25)) {
				case true:
					cout << fighterVector[x].getName() << " takes down " << fighterVector[s].getName() << endl;
					hp_1 = hp_1 - (sub_O2);
				}
			}
			else {
				switch (gameMaths(0.10)) {
				case true:
					cout << fighterVector[x].getName() << " takes down " << fighterVector[s].getName() << endl;
					hp_1 = hp_1 - (sub_O2);
				}
				if (hp_1 <= 0) {
					cout << fighterVector[s].getName() << " taps out!" << endl;
					fighterVector[s].setLosses(losses_1 + 1);
					fighterVector[x].setWins(wins_2 + 1);
					fightOver = true;
					gameMenu(fighterVector);
				}
			}
		}

		while (gameMaths(0.25 + speed_1) == true && fightOver == false) { //While the fight is not over if true, fighter hits opponent
			cout << fighterVector[s].getName() << " hits " << fighterVector[x].getName() << endl;
			hp_2 = hp_2 - ap_1; //deduct health from attacker's action points 
		} if (gameMaths(0.25 + speed_1) == false) { // if false and second fighter's chance is true then do the reverse 
			while (gameMaths(0.25 + speed_2) == true) {
				cout << fighterVector[x].getName() << " hits " << fighterVector[s].getName() << endl;
				hp_1 = hp_1 - ap_2;
			}
		}
		else if (gameMaths(0.25 + speed_2) == false && fightOver == false) { //If second fighter's chance is false then both have missed
			cout << "Both fighters missed!" << endl;
		}

		if (hp_1 <= 0 && fightOver != true) { //If fighter's health is 0 then second fighter wins by KO/TKO 
			cout << fighterVector[x].getName() << " KO/TKOs " << fighterVector[s].getName() << endl;
			fighterVector[s].setLosses(losses_1 + 1);
			fighterVector[x].setWins(wins_2 + 1);
			fightOver = true;
			gameMenu(fighterVector);
		}
		else if (hp_2 <= 0 && fightOver != true) {
			cout << fighterVector[s].getName() << " KO/TKOs " << fighterVector[x].getName() << endl;
			fighterVector[x].setLosses(losses_2 + 1);
			fighterVector[s].setWins(wins_1 + 1);
			fightOver = true;
			gameMenu(fighterVector);
		}
		fightCount--; //After each function call, decrement counter

		if (fightCount == 0 && fightOver != true) { //Decision calculator 
			if (hp_2 - end_2 < hp_1 - end_1) { //If second fighter's hp is lower then first wins by decision. 
				cout << fighterVector[s].getName() << " wins by decision!" << endl;
				fighterVector[x].setLosses(losses_2 + 1);
				fighterVector[s].setWins(wins_1 + 1);
				fightOver = true;
				gameMenu(fighterVector);
			}
			else if (hp_1 - end_1 < hp_2 - end_2) {
				cout << fighterVector[x].getName() << " wins by decision!" << endl;
				fighterVector[s].setLosses(losses_1 + 1);
				fighterVector[x].setWins(wins_2 + 1);
				fightOver = true;
				gameMenu(fighterVector);
			}
			else if (hp_1 - end_1 == hp_2 - end_2) { //If both fighters hp is equal then no contest 
				cout << "No contest!" << endl;
				fightOver = true;
				gameMenu(fighterVector);
			}
		}
	}
}

//Main Functions

int main() //Initialise variables on start up 
{
	vector <Fighter> fighterVector; //Vector for fighter objects 
	ofstream fighterFile("fighters.txt"); //Creates and opens file

	Fighter f1(1000, "John", "Doe", "United Kingdom", "Edinburgh", "Kickboxing", 20, 60, 168, 95, 80, 75, 87, 70, 0, 0); //Creates fighter 1
	Fighter f2(1001, "Adam", "Doe", "United Kingdom", "Glasgow", "Kickboxing", 20, 60, 168, 85, 70, 65, 77, 60, 0, 0); //Creates fighter 2

	fighterFile << f1.getID() << "|" << f1.getName() << "|" << f1.getNation() << "|" << f1.getFightout() << "|" << f1.getStyle() << "|" << f1.getAge() << "|" << f1.getWeight() << "|" << f1.getHeight() << "|" << f1.getStrength() << "|" << f1.getSpeed() << "|" << f1.getEndurance() << "|" << +f1.getSubDef() << "|" << f1.getSubOff() << "|" << f1.getWins() << "|" << f1.getLoss() << endl; //Writes fighter 1 object to file
	fighterFile << f2.getID() << "|" << f2.getName() << "|" << f2.getNation() << "|" << f2.getFightout() << "|" << f2.getStyle() << "|" << f2.getAge() << "|" << f2.getWeight() << "|" << f2.getHeight() << "|" << f2.getStrength() << "|" << f2.getSpeed() << "|" << f2.getEndurance() << "|" << +f2.getSubDef() << "|" << f2.getSubOff() << "|" << f2.getWins() << "|" << f2.getLoss() << endl; //Writes fighter 2 object to file

	fighterVector.push_back(f1); //Adds fighter 1 to vector
	fighterVector.push_back(f2); //Adds fighter 2 to vector

	menu(fighterVector);

}

//Menu Functions 

void menu(vector <Fighter> fighterVector) {
 
	int i = 0; //Variable for view fighters 
	int lastID; //Variable for last ID

	int c_age; //age for creator
	int c_weight; //weight for creator
	int c_height; //height for creator
	int c_defaults = 30; // Default values for strength, speed, endurance, submission defence and submission offence

	string c_fname; //first name for creator
	string c_sname; //surname for creator
	string c_nationality; //nationality for creator
	string c_fightingOut; //fighting out of for creator
	string c_style; //fight style for creator 

	cout << "\n|==========================================================|\n|                   BunnyCorp MMA Game                     |\n|==========================================================|\n|     1. Add Fighters                                      |\n|     2. View Fighters                                     |\n|     3. Play Game                                         |\n|     0. Exit Game                                         |\n|==========================================================|" << endl; //Menu Screen : Change from Java (Reduced number of lines) 

	cin >> input;

	switch (input) {

	case 1:
	{
		for (unsigned i = 0; i < fighterVector.size(); i++) { //Gets last ID in vector 
			lastID = fighterVector[i].getID();
		}
		lastID++; //Increase ID by one 
		cout << "|==================== Create a Fighter ====================|\nFirst Name: ";
		cin >> c_fname; cout << "Second Name: ";
		cin >> c_sname; cout << "Nationality: ";
		cin >> c_nationality; cout << "Fighting out of: ";
		cin >> c_fightingOut; cout << "Style: ";
		cin >> c_style;
		cout << "Age: ";
		cin >> c_age;
		while (1) {
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Validates to only accept numbers (Need to add check for ages between 18 and 50)
				cout << "Incorrect Value!" << endl;
				cin >> c_age;
			}
			if (!cin.fail())
				break;
		}
		cout << "Weight: ";
		cin >> c_weight;
		while (1) {
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Incorrect Value!" << endl;
				cin >> c_weight;
			}
			if (!cin.fail())
				break;
		}
		cout << "Height: ";
		cin >> c_height;
		while (1) {
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Incorrect Value!" << endl;
				cin >> c_height;
			}
			if (!cin.fail())
				break;
		}
		Fighter c_Fighter(lastID, c_fname, c_sname, c_nationality, c_fightingOut, c_style, c_age, c_weight, c_height, c_defaults, c_defaults, c_defaults, c_defaults, c_defaults, 0, 0); //Creates new fighter object with inputted values
		fighterVector.push_back(c_Fighter); //Adds fighter to vector 
		menu(fighterVector); //Go back to menu 
	}

	break;
	case 2:
		for (const Fighter& Fighter : fighterVector) //For each fighter in vector print out fighter details in position of i 
		{
			cout << "|========================= Fighter ========================| \n Fighter Name: "
				<< fighterVector[i].getName() << "\n From: " << fighterVector[i].getNation() << "\n Fighting out of: "
				<< fighterVector[i].getFightout() << "\n Fight Style: " << fighterVector[i].getStyle() << "\n Age: "
				<< fighterVector[i].getAge() << "\n Weight: " << fighterVector[i].getWeight() << "\n Height: "
				<< fighterVector[i].getHeight() << "\n Strength: " << fighterVector[i].getStrength() << "\n Speed: " << fighterVector[i].getSpeed() << "\n Endurance: "
				<< fighterVector[i].getEndurance() << "\n Submission Defence: " << fighterVector[i].getSubDef() << "\n Submission Offence: "
				<< fighterVector[i].getSubOff() << "\n Wins: " << fighterVector[i].getWins() << "\n Losses: " << fighterVector[i].getLoss() << "\n Fighter ID: " << fighterVector[i].getID() << "\n";
			i++;
		}
		menu(fighterVector);

	case 3:
		gameMenu(fighterVector);
		break;
	case 0:
		break;
	default:
		menu(fighterVector);
	}
}
void gameMenu(vector<Fighter>fighterVector) {

	cout << "\n|==========================================================|\n|                   BunnyCorp MMA Game                     |\n|==========================================================|\n|     1. Pick Fighter                                      |\n|     2. Train Fighters                                    |\n|     3. Fight                                             |\n|     4. Main Menu                                         |\n|==========================================================|" << endl; //Game Menu Screen : Change from Java (Reduced number of lines) 
	cin >> input;

	switch (input) {
	case 1: { cout << "\nPick a Fighter (Enter ID)\n-----------------------------\n";
		s = 0; //Fixes exception when selecting a fighter out of vector range
		int playerCount = 0; //Fixes issue from Java where x continues to increment. 

		for (const Fighter& Fighter : fighterVector) { //For each fighter object in vector display object attributes 
			cout << playerCount << ": " << fighterVector[playerCount].getName() << "\n" << "| Strength: "
				<< fighterVector[playerCount].getStrength()
				<< " | Speed: " << fighterVector[playerCount].getSpeed()
				<< " | Endurance: " << fighterVector[playerCount].getEndurance()
				<< " | Submission Offence: " << fighterVector[playerCount].getSubOff()
				<< " | Submission Defence: " << fighterVector[playerCount].getSubDef()
				<< " | Fighter ID: " << fighterVector[playerCount].getID() << "\n \n";
			playerCount++;
		}
		cin >> selection;
		for (const Fighter& Fighter : fighterVector) {
			if (selection == fighterVector[s].getID()) {
				cout << "You have selected: " << fighterVector[s].getName() << "\n \n";
				gameMenu(fighterVector);
			else {
				s++;
			}
		}
	}
	case 2: cout << "\nTrain a Fighter\n";
		if (selection == 0) {
			cout << "Please select a fighter!" << endl;
			gameMenu(fighterVector);
		}
		else {
			cout << "Fighter: " << fighterVector[s].getName()  <<  "\n \n1 : Strength\n2 : Speed\n3 : Endurance\n4 : Submission Offence\n5 : Submission Defence" << endl;
			trainerMenu(fighterVector);
		}


	case 3: cout << "\nFight\n";
		 if (selection == 0) {
			cout << "Please select a fighter!" << endl;
			gameMenu(fighterVector);
		}
		else {
			fightMenu(fighterVector);
		}
	case 4: menu(fighterVector);
	}
}
void trainerMenu(vector<Fighter>fighterVector){ //Function that allows user to increase stats of fighters. 
	
	cout << "\n \n1 : Strength\n2 : Speed\n3 : Endurance\n4 : Submission Offence\n5 : Submission Defence \n6 : View Stats \n7 : Back \n" << endl;

	cin >> input;

	switch (input) {
	case 1: { //Increase strength
		if (fighterVector[s].getStrength() != 100) {
			int t_strength = fighterVector[s].getStrength();
			cout << "Strength increased from: " << t_strength << " to ";
			fighterVector[s].setStrength(t_strength + 1);
			cout << fighterVector[s].getStrength();
			trainerMenu(fighterVector);
		}
		else {
			cout << "\n Fighter has reached max strength! \n";
			trainerMenu(fighterVector);
		}
	}
	case 2: //Increase speed
		if (fighterVector[s].getSpeed() != 100) {
			int t_speed = fighterVector[s].getSpeed();
			cout << "Speed increased from: " << t_speed << " to ";
			fighterVector[s].setSpeed(t_speed + 1);
			cout << fighterVector[s].getSpeed();
			trainerMenu(fighterVector);
		}
		else {
			cout << "\n Fighter has reached max speed! \n";
			trainerMenu(fighterVector);
		}
	case 3: //Increase endurance
		if (fighterVector[s].getEndurance() != 100) {
			int t_endurance = fighterVector[s].getEndurance();
			cout << "Endurance increased from: " << t_endurance << " to ";
			fighterVector[s].setEndurance(t_endurance + 1);
			cout << fighterVector[s].getEndurance();
			trainerMenu(fighterVector);
		}
		else {
			cout << "\n Fighter has reached max endurance! \n";
			trainerMenu(fighterVector);
		}
	case 4: //Increase submission offence
		if (fighterVector[s].getSubOff() != 100) {
			int t_subOff = fighterVector[s].getSubOff();
			cout << "Submission Offence increased from: " << t_subOff << " to ";
			fighterVector[s].setSubOff(t_subOff + 1);
			cout << fighterVector[s].getSubOff();
			trainerMenu(fighterVector);
		}
		else {
			cout << "\n Fighter has reached max submission offence! \n";
			trainerMenu(fighterVector);
		}
		trainerMenu(fighterVector);
	case 5: //Increase submission defence 
		if (fighterVector[s].getSubDef() != 100) {
			int t_subDef = fighterVector[s].getSubDef();
			cout << "Submission Defence increased from: " << t_subDef << " to ";
			fighterVector[s].setSubDef(t_subDef + 1);
			cout << fighterVector[s].getSubDef();
			trainerMenu(fighterVector);
		}
		else {
			cout << "\n Fighter has reached max submission defence! \n";
			trainerMenu(fighterVector);
		}
		trainerMenu(fighterVector);

	case 6:
		cout << "Current Fighter Skills: \n Strength: " << fighterVector[s].getStrength() << "\n Speed: " << fighterVector[s].getSpeed() << "\n Endurance: " << fighterVector[s].getEndurance() << "\n Submission Offence: " << fighterVector[s].getSubOff() << "\n Submission Defence: " << fighterVector[s].getSubDef() << endl;
		trainerMenu(fighterVector);
	case 7: 
		gameMenu(fighterVector); //Back option 
	}
}
	void fightMenu(vector<Fighter> fighterVector) {
	
	int i = 0;
	int o = 0;
	x = 0;

	for (const Fighter& Fighter : fighterVector) { //For each fighter object in vector display object attributes 
		cout << i << "\n: " << fighterVector[i].getName() << "\n" << "| Strength: "
			<< fighterVector[i].getStrength()
			<< " | Speed: " << fighterVector[i].getSpeed()
			<< " | Endurance: " << fighterVector[i].getEndurance()
			<< " | Submission Offence: " << fighterVector[i].getSubOff()
			<< " | Submission Defence: " << fighterVector[i].getSubDef()
			<< " | Fighter ID: " << fighterVector[i].getID() << "\n \n";
		i++;
	}
	cin >> o;
	for (const Fighter& Fighter : fighterVector) {
		if (o == fighterVector[s].getID()) {
			cout << "\n You cannot select the same fighter!" << endl;
			fightMenu(fighterVector);
		} else if (o == fighterVector[x].getID()) {
			cout << "You have selected: " << fighterVector[x].getName() << "\n \n";
			fightFunction(fighterVector);
		}
		else {
			x++;
		}
	}
}


