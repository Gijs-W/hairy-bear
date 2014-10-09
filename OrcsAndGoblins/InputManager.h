#pragma once
#include "stdafx.h"
using namespace std;

class InputManager
{
private:
	bool validateAnswer(string answer, vector<string> *params);
public:
	InputManager();
	~InputManager();
	string requestInput(string question, vector<string> params);
	string requestInput(string question);
};