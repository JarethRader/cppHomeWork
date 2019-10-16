//Implementation of Players.harderr
#include <iostream>
#include <string>

//Must include the header file that is being implemented
#include "Player.h"

using namespace std;

//constructor
Player::Player()
{
	//default constructor for Player class
	this->name = "First Last";
	this->teamName = "Team Name";
	this->points = 0;
	this->rebounds = 0;
	this->assists = 0;
}

Player::Player(string name, string teamName, double points, double rebounds, double assists)
{
	//Data validation
	if(name.size() < 0)
		this->name = "First Last";
	else if(teamName.size() < 0)
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

//defines setter functions
string Player::getName(){return this->name;}
string Player::getTeamName(){return this->teamName;}
double Player::getPoints(){return this->points;}
double Player::getRebounds(){return this->rebounds;}
double Player::getAssists(){return this->assists;}


defines getter functions
void Player::setPlayer(string name, string teamName, double points, double rebounds, double assists)
{
	this->name = name;
	this->teamName = teamName;
	this->points = points;
	this->rebounds = rebounds;
	this->assists = assists;
}

void Player::setName(string name){this->name=name;}
void Player::setTeamName(string teamName){this->teamName=teamName;}
void Player::setPoints(double points){this->points=points;}
void Player::setRebounds(double rebounds){this->rebounds=rebounds;}
void Player::setAssists(double assists){this->assists = assists;}	