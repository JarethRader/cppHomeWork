#include <iostream>
#include <string>
#inlcude <iomanip>
#include <iostream>

using namespace std;

//read in existing players anf their stats from player.txt
//menu driven
// |-> add a player
// |-> display all players' data in a nice tabular form  
// |-> display individual profile
// |-> edit specific player's data(teamName, points, rebounds, assists)
//search array for a player
//save changes made
//BONUS: option to display players' records in descending order based on player's average points

//define maximum number of players that can be stored
const int MAX_NO_PLAYERS = 100;

//initialize player list
void initPlayerList(Player playerList, int playerListSize);
//Read Player Stats from player.txt
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
	Player *playerList;
	playerList = new Player[MAX_NO_PLAYERS];
	int playerListSize = MAX_NO_PLAYERS;
	
	for(int i = 0; i < MAX_NO_PLAYERS; i++)
	{
		cout << playerList[i].getName() << endl;
	}
	
	ifstream in;
	in.open("players.txt");
	if(!in)
	{
		cout << "Input file does not exist. Program Terminating" << endl;
		cin.get();
		return 0;
	}
	out.open("players.txt");
	
	initPlayerList(playerList)
	
}

/*void initPlayerList(Player playerList, int playerListSize)
{
	for(int i = 0; i < playerListSize; i++)
	{
		playerList[i] = new Player();
	}
}*/

void readPlayerList(ifstream& in, playerStats playerList[], int playerListSize)
{
	
}

//menu driven
// |-> add a player
// |-> display all players' data in a nice tabular form  
// |-> display individual profile
// |-> edit specific player's data(teamName, points, rebounds, assists)
void displayMenu(playerStats playerList[], int playerListSize)
{
	int response;
	cout << "Menu\n 1. Show Player List\n 2. Find Player\n 3. Edit Player\n 4. Add Player\n 5. Sort Players\n 6. Save Player List" << endl;
	cin >> response;
	switch(response)
	{
		case 1: {
			cout << "Show Players" << endl;
			readPlayerList(in, playerList, playerListSize);
			break;
		}
		case 2: {
			cout << "Find Player" << endl;
			string playerName;
			cout << "Enter Player Name: ";
			cin >> playerName;
			showPlayerStats(playerList, playerListSize, playerName);
			cin.get();
			break;
		}
		case 3: {
			cout << "Edit Player" << endl;
			string editPlayer;
			cout << "Player Name: " << endl;
			cin >> editPlayer;
			editPlayerInfo(playerList, playerListSize, editPlayer);
		}
		case 4: {
			cout << "Add Player" << endl;
			addPlayer(playerList, playerListSize);
		}
		case 5: {
			cout << "Saveing player list" << endl;
			savePlayerList(out, playerList, playerListSize);
		}
	}
}

//search for specific player
int findPlayer(playerStats playerList[], int playerListSize, string playerName)
{
	
}

//Display player stats
void showPlayerStats(playerStats playerList[], int playerListSize, string playerName)
{
	
}

//add new players
void addPlayer(playerStats playerList[], int playerListSize)
{
	
}

//edit player info
int editPlayerInfo(playerStats playerList[], int playerListSize, string player)
{
	
}

//save changed into players.txt
void savePlayerList(ofstream& out, playerStats playerList[], int playerListSize)
{
	
}