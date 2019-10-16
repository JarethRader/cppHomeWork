#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Max # of players that can be stored
const int NO_OF_PLAYERS = 100;
	
struct playerStats
{
	string name;
	string teamName;
	double points;
	double rebounds;
	double assists;
};

//initalize player list
void initPlayerList(playerStats playerList[], int playerListSize);
//read player list from player.txt
void readPlayerList(ifstream& in, playerStats playerList[], int playerListSize);
//Display Menu with options
void displayMenu(playerStats playerList[], int playerListSize);
//search for specific player
int findPlayer(playerStats playerList[], int playerListSize, string playerName);
//Display player stats
void showPlayerStats(playerStats playerList[], int playerListSize, string playerName);
//add new players
void addPlayer(playerStats playerList[], int playerListSize);
//edit player info
int editPlayerInfo(playerStats playerList[], int playerListSize, string player);
//save changed into players.txt
void savePlayerList(ofstream& out, playerStats playerList[], int playerListSize);

int main()
{
	playerStats playerList[NO_OF_PLAYERS];
	int choiceList[NO_OF_PLAYERS];
	int choiceListLength;
	ifstream in;
	
	in.open("players.txt");
	if(!in)
	{
		cout << "File does not exist, program terminating";
		cin.get();
		return 1;
	}
	
	initPlayerList(playerList, NO_OF_PLAYERS);
	readPlayerList(in, playerList, NO_OF_PLAYERS);
	displayMenu(playerList, NO_OF_PLAYERS);

	cin.get();
	return 0;
};

void displayMenu(playerStats playerList[], int playerListSize)
{
	ofstream out;
	ifstream in;
	in.open("players.txt");
	int response;
	cout << "Menu\n 1. Show Player List\n 2. Find Player\n 3. Edit Player\n 4. Add Player\n 5. Sort Players\n 6. Save Player List" << endl;
	cin >> response;
	switch(response)
	{
		case 1: {
			cout << "1. Show Players" << endl;
			readPlayerList(in, playerList, playerListSize);
			break;
		}
		case 2: {
			cout << "2. Find Player" << endl;
			string playerName;
			cout << "Enter Player Name: ";
			cin >> playerName;
			showPlayerStats(playerList, playerListSize, playerName);
			cin.get();
			break;
		}
		case 3: {
			cout << "3. Edit Player" << endl;
			string editPlayer;
			cout << "Player Name: " << endl;
			cin >> editPlayer;
			editPlayerInfo(playerList, playerListSize, editPlayer);
		}
		case 4: {
			cout << "4. Add Player" << endl;
			addPlayer(playerList, playerListSize);
		}
		case 5: {
			cout << "Saveing player list" << endl;
			savePlayerList(out, playerList, playerListSize);
		}
	}
}

void initPlayerList(playerStats playerList[], int playerListSize)
{
	for( int i =0; i < playerListSize; i++)
	{
		playerList[i].name = "First Last";
		playerList[i].teamName = "Team";
		playerList[i].points = 0.0;
		playerList[i].rebounds = 0.0;
		playerList[i].assists = 0.0;
	}	
}

void readPlayerList(ifstream& in, playerStats playerList[], int playerListSize)
{
	char ch;
	string name, team, line;
	int points, rebounds, assists;
	for(int i = 0; i < playerListSize; i++)
	{
		getline(in, name);
		in.erase(in.find_last_not_of("\n\r") + 1);
		cout << name << '\n';
		playerList[i].name = name;
		getline(in, team);
		in.erase(in.find_last_not_of("\n\r") + 1);
		cout << team << '\n';
		playerList[i].teamName = team;
		in >> points;
		getline(in, line);
		cout << points << endl;
		playerList[i].points = points;
		in >> rebounds;
		getline(in, line);
		cout << rebounds << endl;
		playerList[i].rebounds = rebounds;
		in >> assists;
		getline(in, line);
		cout << assists << endl;
		playerList[i].assists = assists;
		if(in.eof())
			break;
	}
}

int findPlayer(playerStats playerList[], int playerListSize, string playerName)
{
	string checkName;
	int index = 7;
	for(int i = 0; i < playerListSize; i++)
	{
		checkName = playerList[index].name;
		if(!checkName == playerName)
			return index;
		else
			index++;
	}
	return 0;
}

void showPlayerStats(playerStats playerList[], int playerListSize, string playerName)
{
	int playerSpot = findPlayer(playerList, playerListSize, playerName);
	cout << playerSpot << endl;
	cout << "Name: " << playerList[playerSpot].name << endl;
	cout << "Team: " << playerList[playerSpot].teamName << endl;
	cout << "Points: " << playerList[playerSpot].points << endl;
	cout << "Rebounds: " << playerList[playerSpot].rebounds << endl;
	cout << "Assists: " << playerList[playerSpot].assists << endl;
}

void addPlayer(playerStats playerList[], int playerListSize)
{
	string name, teamName;
	double points, rebounds, assists;
	
	int spot = findPlayer( playerList, playerListSize, "First Last");
	cout << "Enter Name: " << endl;
	cin >> name;
	playerList[spot].name = name;
	cout << "Enter Team Name: " << endl;
	cin >> teamName;
	playerList[spot].teamName = teamName;
	cout << "Enter Points: " << endl;
	cin >> points;
	playerList[spot].points = points;
	cout << "Enter Rebounds: " << endl;
	cin >> rebounds;
	playerList[spot].rebounds = rebounds ;
	cout << "Enter Assists: " << endl;
	cin >> assists;
	playerList[spot].assists = assists;
	cout << "Player added" << endl;
	showPlayerStats(playerList, playerListSize, name);
}

int editPlayerInfo(playerStats playerList[], int playerListSize, string player)
{
	int playernum = findPlayer(playerList, playerListSize, player);
	char response = 'y';
	int var;
	string res;
	double resp;
	if (playernum == -1)
	{
		cout << "Player not found" << endl;
		return 0;
	}
	while(response != 'N' || response != 'n')
	{
		cout << "Select Stat to change\n(1)Name\n(2)Team Name\n(3)Points\n(4)Rebounds\n(5)Assists" << endl;
		cin >> var;
		switch (var) {
			case 1: {
				cout << "Enter new name: ";
				cin >> res;
				playerList[playernum].name = res;
				break;
			}
			case 2: {
				cout << "Enter new team name: ";
				cin >> res;
				playerList[playernum].teamName = res;
				break;
			}
			case 3: {
				cout << "Enter new value for points: ";
				cin >> resp;
				playerList[playernum].points = resp;
				break;
			}
			case 4: {
				cout << "Enter new value for rebounds: ";
				cin >> resp;
				playerList[playernum].rebounds = resp;
				break;
			}
			case 5: {
				cout << "Enter new value for assists: ";
				cin >> resp;
				playerList[playernum].assists = resp;
				break;
			}
		}
		cout << "Continue? Y/y (Yes), N/n (No)" << endl;
	}
	return 0;
}

void savePlayerList(ofstream& out, playerStats playerList[], int playerListSize)
{
	string fileName;
	cout << "Enter file name: " << endl;
	cin >> fileName;
	out.open((fileName+".out").c_str());
	out << setfill(' ') << setw(5) << "Name" << setw(8) << "Team" << setw(8) << "Points" << setw(8) << "Rebounds" << setw(10) << "Assists" << setw(10) << endl;
	for(int i = 0; i < playerListSize; i++)
	{
		if(playerList[i].name == "First Last")
			break;
		out << setfill(' ') << setw(5) << playerList[i].name << setw(8) << playerList[i].teamName << setw(8) << playerList[i].points << setw(8) << playerList[i].rebounds << setw(10) << playerList[i].assists << setw(10) << endl;
	}
	cout << "List saved to " << fileName << ".out" << endl;
}