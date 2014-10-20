#include "stdafx.h"
#include "InputManager.h"
#include <iostream>

using namespace std;
InputManager *InputManager::instance = nullptr;
bool InputManager::validateAnswer(string answer, vector<string> *expectedAnswers) {
	bool found = false;


	vector<string>::iterator it = expectedAnswers->begin();

	while (it != expectedAnswers->end() && !found) {

		if (*it == answer) {
			found = true;
		}
		it++;
	}

	return found;

}

	
string InputManager::requestInput(string question, vector<string> *expectedAnswers) {

	string output = question.append(" [");

	for (vector<string>::iterator it = expectedAnswers->begin(); it != expectedAnswers->end(); it++) {

		if (it != expectedAnswers->begin()) {
			output.append(" | ");
		}

		output.append(*it);
	}

	output.append("]");

	string answer = "";

	do {


		cout << endl << output << endl;

		getline(cin, answer);
	} while (!validateAnswer(answer,expectedAnswers));

	delete expectedAnswers;

	return answer;
}

string InputManager::requestInput(string question) {
	string answer = "";

	cout << question << endl;
	getline(cin, answer);

	return answer;
}

InputManager* InputManager::getInstance() {
	if (InputManager::instance == nullptr) {
		InputManager::instance = new InputManager;
	}
	return InputManager::instance;
}

InputManager::InputManager(){
	
}

InputManager::~InputManager(){
	delete instance;
}



