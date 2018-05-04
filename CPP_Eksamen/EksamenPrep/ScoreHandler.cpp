#include "ScoreHandler.h"
#include <string>

int ScoreHandler::readFile() {
	std::string line;
	std::string score;
	int converted;

	std::ifstream file("highscore.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			score = line;
		}
		file.close();
	}
	else {
		std::cout << "Can't open file" << std::endl;
	}

	converted = atoi(score.c_str());
	return converted;
}

void ScoreHandler::writeFile(const char* score) {
	file.open("highscore.txt");
	if (file.is_open()) {
		file << score;
		file.close();
	}
}

ScoreHandler::ScoreHandler()
{
}


ScoreHandler::~ScoreHandler()
{
}
