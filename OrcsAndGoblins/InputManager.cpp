#include "stdafx.h"
#include "InputManager.h"
#include <iostream>

using namespace std;

bool InputManager::validateAnswer(string answer, vector<string> *params) {
	bool found = false;


	vector<string>::iterator it = params->begin();

	while (it != params->end() && !found) {

		if (*it == answer) {
			found = true;
		}
		it++;
	}

	return found;

}

	
string InputManager::requestInput(string question, vector<string> params) {

	string output = question.append(" [");

	for (vector<string>::iterator it = params.begin(); it != params.end(); it++) {

		if (it != params.begin()) {
			output.append(" | ");
		}

		output.append(*it);
	}

	output.append("]");

	string answer = "";

	do {


		cout << endl << output << endl;

		getline(cin, answer);
	} while (!validateAnswer(answer, &params));

	return answer;
}

string InputManager::requestInput(string question) {
	string answer = "";

	getline(cin, answer);

	return answer;
}

InputManager* InputManager::getInstance(){
	if (instance == nullptr)
		return new InputManager();
	else
		return instance;
}

InputManager::InputManager(){
	
}

InputManager::~InputManager(){
	delete instance;
}



