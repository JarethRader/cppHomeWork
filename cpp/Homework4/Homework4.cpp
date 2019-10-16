#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Player.h"
#include "listType.h"

using namespace std;

//define maximum number of players that can be stored
const int MAX_NO_PLAYERS = 10000;


//Read Player Stats from player.txt
void readPlayerList(ifstream &in, Player playerList[], int playerListSize);
//search for specific player
int findPlayer(Player playerList[], int playerListSize, string playerName);
//Display player stats
void showPlayer(Player playerList[], int playerListSize, string playerName);
//add new players
void addPlayer(Player playerList[], int playerListSize);
//edit player info
void editPlayerInfo(Player playerList[], int playerListSize, string player);
//save changed into players.txt
void savePlayerList(ofstream &out, Player playerList[], int playerListSize);


int main(int argc, char *argv[])
{
	ifstream in;							//Define file in and out streams
	ofstream out;
	char res;								//Char variable to be use as a placeholder
	listType<Player> playerList;
	
	//Set double precision to go out 1 decimal place
	cout << fixed << showpoint << setprecision(1);
	
	//Open input file 'players.txt'
	in.open("players.txt");
	//if file is not found, then terminate program
	if(!in)
	{
		cout << "Input file does not exist. Program Terminating" << endl;
		cin.get();
		return 0;
	}
	
	//read in data from file into Player array
	readPlayerList(in, playerList, playerListSize);
	
	//Start infinite loop to loop through menu and options
	while (true)
	{
	
		//menu driven
		// |-> add a player
		// |-> display all players' data in a nice tabular form  
		// |-> display individual profile
		// |-> edit specific player's data(teamName, points, rebounds, assists)	
		
		int response;				//int variable to be as a placeholder for the switch/case function
		//Print out menu options to user
		cout << "Menu\n 1. Show Player List\n 2. Find Player\n 3. Edit Player\n 4. Add Player\n 5. Save Player List" << endl;
		//store user response
		cin >> response;
		//Run case depending on the user input
		switch(response)
		{
			readPlayerList(in, playerList, playerListSize);
			case 1: {
				string name, team;						//Define variables for functions in this case to use
				double points, rebounds, assists;
				cout << "Show Players" << endl;			//Tell user what option is running
				//Print out table headers
				cout << setfill(' ') << setw(13) << "Name" << setw(13) << "|" << setw(14) << "Team" << setw(14) << "|" << setw(8) << "Points" << setw(3) << "|" << setw(8) << "Rebounds" << "|" << setw(8) << "Assists" << endl;
				//For loop to print out all players in playerList array
				for(int i = 0; i < playerListSize; i++)
				{
					//for loop checks for is playerList at index i has legitament data or not
					name = playerList[i].getName();
					//If index i is not filled with player Data and has only the default constuctor, break from case
					if(name == "First Last" || name.size() == 0)
						break;	
					//assign rest of the varaibles
					team = playerList[i].getTeamName();
					points = playerList[i].getPoints();
					rebounds = playerList[i].getRebounds();
					assists = playerList[i].getAssists();
					
					//Print out data in tabular format
					cout << setfill(' ') << setw(21) << name << setw(5) << "|" << setw(25) << team << setw(3) << "|" << setw(8) << points << setw(3) << "|" << setw(6) << rebounds << setw(3) << "|" << setw(5) << assists << endl;
					
					//this loop will run through playerList as long as it has legit data rad in from the file
				}
				//then break from the case
				break;
			}
			case 2: {
				cout << "Find Player" << endl;							//Tell user what option is running
				string playerName, first, last;							//Variables for case to use
				cout << "Enter Player Name: " << endl;					//Ask user for Player Name to find
				cin >> first;											//Store before the space
				getline(cin, last);										//then grabs last name after the space
				playerName = first+last;								//And combines them
				showPlayer(playerList, playerListSize, playerName);		//runs showPlayer function to display the players stats
				cin.get();												//waits for user
				break;													//breaks from case
			}
			case 3: {
				cout << "Edit Player" << endl;							//Tells user what option is running
				string editPlayer, first, last;							//variables to be used in case
				cout << "Enter Player Name: " << endl;					//askes player for Player Name
				cin >> first;											//Store before the space
				getline(cin, last);										//then grabs last name after the space
				editPlayer = first+last;								//And combines them
				showPlayer(playerList, playerListSize, editPlayer);		//Shows user current player stats
				editPlayerInfo(playerList, playerListSize, editPlayer);	//Runs editplayer Function
				out.open("players.txt");								//Saves data back into players.txt after any changes
				savePlayerList(out, playerList, playerListSize);
				out.close();
				break;													//breaks from case
			}
			case 4: {
				cout << "Add Player" << endl;							//Tells user what option is running
				addPlayer(playerList, playerListSize);					//Runs addPlayer function
				out.open("players.txt");								//Saves data back into players.txt after any changes
				savePlayerList(out, playerList, playerListSize);
				out.close();
				break;
			}
			case 5: {
				cout << "Saving player list" << endl;					//Tells user what optin is running
				out.open("players.txt");								//Saves current data in playerList array
				savePlayerList(out, playerList, playerListSize);
				out.close();
				break;													//break from case
			}
			break;														//break from switch statement
		}
	
		//
		cout << "Do you want to continue? ";							//Asks user if they want to continue the program, is yes, will rerun the switch statement
		cin >> res;
		if(res == 'N' || res == 'n')
			break;														//else breaks from infinite loop
	}
	
	in.close();															//close input file
	
	cin.get();
	return 0;															//ends program
	
}

//read in data from input file into playerList array
void readPlayerList(ifstream &in, Player playerList[], int playerListSize)
{
	//define some variables for function to use
	char ch;
	string name, team, line;
	double points, rebounds, assists;

	//for loop runs through input file 5 lines at a time and stores them into variables and assigns them into Player class at in playerList array at index i
	for(int i = 0; i < playerListSize; i ++)
	{
		getline(in, name);
		getline(in, team);
		in >> points;
		getline(in, line);
		in >> rebounds;
		getline(in, line);
		in >> assists;
		getline(in, line);
		Player temp = Player(name, team, points, rebounds, assists);
		playerList.insertEnd(temp)
		delete temp;
		//runs through file until at end
		if(in.eof())
			//breaks from loop and ends function
			break;
	}
}

//search for specific player
int findPlayer(Player playerList[], int playerListSize, string playerName)
{
	string checkName;							//string to store name from playerList array to check with name passed in the function
	for(int i = 0; i < playerListSize; i++)
	{
		checkName = playerList[i].getName();	//assigns checkName variable to name in playerList array at index i
		if(!(checkName).compare(playerName))	//if checkName and playerName passed in match, return the index number
			return i;
	}
	return -1;									//if name is not found, return -1
}

//Display player stats
void showPlayer(Player playerList[], int playerListSize, string playerName)
{
	int playerSpot = findPlayer(playerList, playerListSize, playerName);	//gets index of player through findplayer function
	playerList[playerSpot].print();
}

//add new players
void addPlayer(Player playerList[], int playerListSize)
{
	string first, last, name, teamName;								//Declare variables to be used in the function
	double points, rebounds, assists;
	string open = "First Last";										//defines string to be used to find next "open" spot in playerList array
	int spot = findPlayer(playerList, playerListSize, open);		//Finds index of next "open" spot in playerList array
	cout << "Enter Name: " << endl;									//Askes user for player stats and stors them into Player in playerList array at index 'spot'
	cin >> first;
	getline(cin, last);
	name = first+last;
	cout << "Enter Team Name: " << endl;
	cin >> first;
	getline(cin, last);
	teamName = first+last;
	cout << "Enter Points: " << endl;
	cin >> points;
	cout << "Enter Rebounds: " << endl;
	cin >> rebounds;
	cout << "Enter Assists: " << endl;
	cin >> assists;
	cout << "Player added" << endl;
	Player temp = Player(name, team, points, rebounds, assists);
	playerList.insertEnd(temp)
	showPlayer(playerList, playerListSize, name);					//Shows stats of newly added player
}

//edit player info
void editPlayerInfo(Player playerList[], int playerListSize, string player)
{
	int playernum = findPlayer(playerList, playerListSize, player);	//finds index of player to be edited by running findPlayer function with playerName passed in from function
	//declares some variables to be used by function
	char response;
	int var;
	string res;
	double resp;
	if (playernum == -1)											//validates that palyer does exist
	{
		cout << "Player not found" << endl;
		return;
	}
	while(true)														//runs infinite loop with switch statement
	{
		//gives user their options
		cout << "Select Stat to change\n(1)Team Name\n(2)Points\n(3)Rebounds\n(4)Assists" << endl;
		cin >> var;													//stores their choice in varible 'var' to be used in switch statement
		switch (var) {
			case 1: {
				cout << "Enter new team name: ";					//Askes user for new stat
				cin >> res;											//stores user input
				playerList[playernum].setTeamName(res);				//stores new stat in Player class at index found previously
				break;												//breaks from switch statement
			}
			case 2: {
				cout << "Enter new value for points: ";				//Askes user for new stat
				cin >> resp;										//stores user input
				playerList[playernum].setPoints(resp);				//stores new stat in Player class at index found previously
				break;												//breaks from switch statement
			}
			case 3: {
				cout << "Enter new value for rebounds: ";			//Askes user for new stat
				cin >> resp;										//stores user input
				playerList[playernum].setRebounds(resp);			//stores new stat in Player class at index found previously
				break;												//breaks from switch statement
			}
			case 4: {
				cout << "Enter new value for assists: ";			//Askes user for new stat
				cin >> resp;										//stores user input
				playerList[playernum].setAssists(resp);				//stores new stat in Player class at index found previously
				break;												//breaks from switch statement
			}
			break;													//breaks from infinite while loop
		}
		//asks user if they want to continue editing the players stats
		cout << "Continue to edit player? Y/y (Yes), N/n (No)" << endl;
		//stores users' response
		cin >> response;
		//if response if no, breakas from function
		if(response == 'N' || response == 'n')
			break;
	}
	return;
}

//save changed into players.txt
void savePlayerList(ofstream &out, Player playerList[], int playerListSize)
{
	int i = 0;				//int to be used as index position
	//checks to make sure it's not saving unused indexes of playerList array and saving then into output file
	while(playerList[i].getName() != "First Last" && playerList[i].getTeamName() != "Team Name" && playerList[i].getPoints() != 0 && playerList[i].getRebounds() != 0 && playerList[i].getAssists() != 0)
	{
		//writes player stats into output files
		out << playerList[i].getName() << '\n' << playerList[i].getTeamName() << '\n' << playerList[i].getPoints() << '\n' << playerList[i].getRebounds() << '\n' << playerList[i].getAssists() << endl;
		i++;
	}
	//gives user feedback that the file has been saved
	cout << "List saved to players.txt" << endl;
}