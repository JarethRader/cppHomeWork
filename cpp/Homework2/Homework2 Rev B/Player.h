#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
private:
	string name, teamName;
	double points, rebounds, assists;
public:
	Player(string name, string teamName, double points, double rebounds, double assists);
	~Player();
	
	//Setter and getter functions
	string getName();
	string getTeamName();
	double getPoints();
	double getRebounds();
	double getAssists();
	
	void setName(string name);
	void setTeamName(string teamName);
	void setpoints(int points);
	void setrebounds(int rebounds);
	void setassists(int assists);
};

#endif;