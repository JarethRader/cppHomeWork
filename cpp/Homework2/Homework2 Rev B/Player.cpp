//Implementation of Players.harderr
#include <iostream>
#include <string>

//Must include the header file that is being implemented
#include "Player.h"

using namespace std;

//constructor
Player::Player(string name, string teamName, double points, double rebounds, double assists)
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
Player::~Player()
{
	
}

string Player::getName(){return this->name;}
string Player::getTeamName(){return this->teamName;}
double Player::getPoints(){return this->points;}
double Player::getRebounds(){return this->rebounds;}
double Player::getAssists(){return this->assists;}

void Player::setName(string name){this->name=name;}
void Player::setTeamName(string teamName){this->teamName=teamName;}
void Player::setpoints(int points){this->points=points;}
void Player::setrebounds(int rebounds){this->rebounds=rebounds;}
void Player::setassists(int assists){this->assists = assists;}