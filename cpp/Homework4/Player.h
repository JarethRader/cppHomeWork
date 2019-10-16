//#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
private:
//class variables
	string name;
	string teamName;
	double points;
	double rebounds;
	double assists;

public:
	//constuctors
	Player();
	Player(string name, string teamName, double points, double rebounds, double assists);
	//destrcutor
	~Player();
	
	//Setter and getter functions
	string getName();
	string getTeamName();
	double getPoints();
	double getRebounds();
	double getAssists();
	
	void setPlayer(string name, string teamName, double points, double rebounds, double assists);
	
	void setName(string name);
	void setTeamName(string teamName);
	void setPoints(double points);
	void setRebounds(double rebounds);
	void setAssists(double assists);
	
	void print();
};

#endif