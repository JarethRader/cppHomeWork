//Implementation of Players.harderr
#include <iostream>
#include <string>

//Must include the header file that is being implemented
#include "Player.h"

using namespace std;

//constructor
Players::Players(string name, string teamName, double points, double rebounds, double assists)
{
	//Data validation
	if(name == null)
		this->name = "First Last";
	else if(teamName = null)
		this->teamName = "Team Name";
	else if(points < 0)
		this->points = 0;
	else if(rebounds < 0)
		this->rebounds = 0;
	else if(assists < 0)
		this->assists = 0;
	
	this->name = name;
	this->teamName = teamName;
	this->points = points;
	this->rebounds = rebounds;
	this->assists = assists;
}

//Deconstructor
Players::~Players()
{
	
}

string Players::getName(){return this->name;}
string Players::getTeamName(){return this->teamName;}
double Players::getPoints(){return this->points;}
double Players::getRebounds(){return this->rebounds;}
double Players::getAssists(){return this->assists;}

void Players::setName(string name){this->name=name;}
void Players::setTeamName(string teamName){this->teamName=teamName;}
void Players::setpoints(int points){this->points=points;}
void Players::setrebounds(int rebounds){this->rebounds=rebounds;}
void Players::setpoints(int assists){this->assists=assists;}