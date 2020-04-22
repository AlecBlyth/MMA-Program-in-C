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

void trainerMenu(vector <Fighter> fighterVector);
void gameMenu(vector <Fighter> fighterVector); //Declaration of functions
void menu(vector <Fighter> fighterVector);
void fightFunction(vector<Fighter> fighterVector);

//Algorithmic functions  

bool gameMaths(float probabilityOfSuccess) { //Calcuates a random chance for fights based on input value. 
	return rand() % 100 < (probabilityOfSuccess * 100);
} 

void fightFunction(vector<Fighter>fighterVector) {

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
			fightFunction(fighterVector);
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


