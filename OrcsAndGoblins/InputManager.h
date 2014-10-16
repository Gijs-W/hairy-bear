#pragma once
#include "stdafx.h"
using namespace std;

class InputManager
{
private:
	bool validateAnswer(string answer, vector<string> *params);
	InputManager();
	InputManager* instance;
public:
	~InputManager();

	InputManager* getInstance();
	string requestInput(string question, vector<string> params);
	string requestInput(string question);
};