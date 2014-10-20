#pragma once
#include "stdafx.h"
using namespace std;

class InputManager
{
private:
	bool validateAnswer(string answer, vector<string> *expectedAnswers);
	InputManager();
	static InputManager* instance;
public:
	~InputManager();

	static InputManager* getInstance();
	string requestInput(string question, vector<string> *expectedAnswers);
	string requestInput(string question);
};