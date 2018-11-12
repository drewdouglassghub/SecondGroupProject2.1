// Spoiler-free walkthrough

#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Quest.h"
#pragma comment(lib, "user32")
using namespace std;

// This function populates all the values in each vector.
void createGame(Game gameArray[1], vector<string> categoryNameVector, vector<Quest> questVector, vector<string> stepVector, vector<string> additionalStepsVector, vector<string> hintVector);
// This function gives the category choices.
void categoryChoices(int userCategoryChoice, vector<Quest> questVector);
// This function gives the step choices.
void stepChoices(int userQuestChoice, int STEPS, int startSteps, vector<Quest> questVector, vector<string> stepVector);
// This function gives the hint choices.
void hintChoices(int hintCounter, int hintEnd, int userStepChoice, vector<string> stepVector, vector<string> hintVector);
// This function prints the additional step choices.
int additionalStepPrint(int userStepChoice, int STEPS, int startSteps, vector<string> additionalStepsVector);

//Constants for menu choices
const int MENUCHOICE0 = 0,
MENUCHOICE1 = 1,
MENUCHOICE2 = 2,
MENUCHOICE3 = 3,
MENUCHOICE4 = 4,
MENUCHOICE5 = 5,
MENUCHOICE6 = 6,
MENUCHOICE7 = 7,
MENUCHOICE8 = 8,
MENUCHOICE9 = 9,
MENUCHOICE10 = 10,
MENUCHOICE11 = 11,
MENUCHOICE12 = 12,
MENUCHOICE13 = 13,
MENUCHOICE14 = 14,
MENUCHOICE15 = 15,
MENUCHOICE16 = 16,
MENUCHOICE17 = 17,
MENUCHOICE18 = 18,
MENUCHOICE19 = 19,
MENUCHOICE20 = 20,
MENUCHOICE21 = 21,
MENUCHOICE22 = 22;

int main()
{
	system("mode 650"); // Make the console fullscreen.

	const int DEFAULTVALUE = 50; // Default value for all the vectors.
	const int DEFAULTVALUESTEPS = 234; // Default value for all the steps.
	const int DEFAULTVALUEHINTS = 857; // Default value for all the hints.

	// Create a gameArray, a categoryNameVector, a questVector, a stepVector, and a hintVecor. Then resize all of them to the default value.
	Game gameArray[1];
	vector<string> categoryNameVector = gameArray[0].getCategoryNameVector();
	categoryNameVector.resize(DEFAULTVALUE);

	vector<Quest> questVector = gameArray[0].getQuestVector();
	questVector.resize(DEFAULTVALUE);

	vector<string> stepVector(DEFAULTVALUESTEPS);
	questVector[0].setStepVector(stepVector);

	vector<string> additionalStepsVector(DEFAULTVALUE);
	questVector[0].setAdditionalStepsVector(additionalStepsVector);

	vector<string> hintVector(DEFAULTVALUEHINTS);
	questVector[0].setHintVector(hintVector);

	createGame(gameArray, categoryNameVector, questVector, stepVector, additionalStepsVector, hintVector); // This creates the game Skyrim from the vectors already created.

	// Get the vectors from the class.
	categoryNameVector = gameArray[0].getCategoryNameVector();
	questVector = gameArray[0].getQuestVector();
	stepVector = questVector[0].getStepVector();
	additionalStepsVector = questVector[0].getAdditionalStepsVector();
	hintVector = questVector[0].getHintVector();

	int userMenuChoice; // This is the user's input for the main menu.
	int userGameChoice; // This is the user's input for the game choice.
	int userCategoryChoice; // This is the user's input for the category.
	int userQuestChoice; // This is the user's input for the quest.
	int userStepChoice; // This is the user's input for the step.
	int startSteps; // This tells the program where to start the steps.
	int hintCounter = 0; // Counter used for the hint function.
	int hintEnd; // Value used to end the hint function.
	int userAdditionalChoice; // Value used to track the user's additional choice.

	// Welcome the user to the program and give a short description. 
	cout << "Welcome to the Spoiler-Free Walkthrough Program!\nThis program will allow you to view helpful walkthroughs without ruining your experience.\n";

	do // Do this.
	{
		// Prompt the user to choose one of the menu choices then print out the menu.
		cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\nPlease choose one of the menu choices to begin the program.. \n\n";
		cout << "1. Choose Game\n2. End Program\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
		cin >> userMenuChoice; // Set the user's input to userMenuChoice.
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.

		// If the user's choice is equal to one then do this.
		if (userMenuChoice == MENUCHOICE1)
		{
			cout << "Choose a game..\n\n1. " << gameArray[0].getGameName() << endl; // Output the game choices.
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
			cin >> userGameChoice; // Set the user's input to userGameChoice.
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
			// If the user chooses game one, then print out the categories for quests.
			if (userGameChoice == MENUCHOICE1)
			{
				cout << gameArray[0].getGameName() << " walkthrough\n"; // Print the game's name and walkthrough for the user.
				cout << "Choose a quest category..\n\n"; // Tell the user to pick a category.

				int categoryValues = 0; // Set a counter value.
				do // Print out each categoryName.
				{
					cout << categoryValues + 1 << ". " << categoryNameVector.at(categoryValues) << endl;
					categoryValues++; // Increase the counter value each loop.
				} while (categoryNameVector.at(categoryValues) != ""); // When the categoryName's value is "" then end the do-while loop.

				cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
				cin >> userCategoryChoice; // Set user's input to userCategoryChoice
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.

				if (userCategoryChoice == 1) // Main Quests
				{
					categoryChoices(userCategoryChoice, questVector); // Get the categories.

					cin >> userQuestChoice; // Set user's input to userQuestChoice.
					cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.

					do
					{
						int STEPS = 0;
						// Switch statement to take the user input and print the appropriate steps.
						switch (userQuestChoice)
						{
						case MENUCHOICE1: // Unbound.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1: // Make your way to the Keep.
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintEnd = 5;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2: // Enter the Keep with Hadvar or Ralof.
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 5;
								hintEnd = 8;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3: // Objectives for Hadvar's Path.
								// Set the amount of steps, then give the userQuestChoice, STEPS, and additionalStepsVector to the additional steps function.
								STEPS = 4;
								startSteps = 0;
								userAdditionalChoice = additionalStepPrint(userStepChoice, STEPS, startSteps, additionalStepsVector);
								// Switch statement holding all the additional choices.
								switch (userAdditionalChoice)
								{
								case MENUCHOICE1:
									// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
									hintCounter = 8;
									hintEnd = 18;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE2:
									hintCounter = 18;
									hintEnd = 22;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE3:
									hintCounter = 22;
									hintEnd = 25;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE4:
									hintCounter = 25;
									hintEnd = 30;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								}
								break;
							case MENUCHOICE4: // Objectives for Ralof's Path.
								// Set the amount of steps, then give the userQuestChoice, STEPS, and additionalStepsVector to the additional steps function.
								STEPS = 4; 
								startSteps = 4;
								userAdditionalChoice = additionalStepPrint(userStepChoice, STEPS, startSteps, additionalStepsVector);
								// Switch statement holding all the additional choices.
								switch (userAdditionalChoice)
								{
								case MENUCHOICE1:
									// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
									hintCounter = 30;
									hintEnd = 41;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE2:
									hintCounter = 41;
									hintEnd = 42;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE3:
									hintCounter = 42;
									hintEnd = 45;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								case MENUCHOICE4:
									hintCounter = 45;
									hintEnd = 50;
									hintChoices(hintCounter, hintEnd, userAdditionalChoice, additionalStepsVector, hintVector);
									break;
								}
								break;
							}
							break;
						case MENUCHOICE2: // Before the Storm.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3; 
							startSteps = 4;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 50;
								hintEnd = 54;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 54;
								hintEnd = 58;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 58;
								hintEnd = 67;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE3: // Bleak Falls Barrow.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 7;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 67;
								hintEnd = 69;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 69;
								hintEnd = 74;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 74;
								hintEnd = 79;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE4: // Dragon Rising.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							startSteps = 10;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 79;
								hintEnd = 82;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 82;
								hintEnd = 85;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 85;
								hintEnd = 88;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 88;
								hintEnd = 89;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 89;
								hintEnd = 91;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 91;
								hintEnd = 94;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE5: // The Way of the Voice.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 8;
							startSteps = 16;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 94;
								hintEnd = 102;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 102;
								hintEnd = 103;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 103;
								hintEnd = 105;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 105;
								hintEnd = 107;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 107;
								hintEnd = 110;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 110;
								hintEnd = 112;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 112;
								hintEnd = 115;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								hintCounter = 115;
								hintEnd = 116;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE6: // The Horn of Jurgen Windcaller.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							startSteps = 24;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 116;
								hintEnd = 119;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 119;
								hintEnd = 120;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 120;
								hintEnd = 126;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 126;
								hintEnd = 128;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 128;
								hintEnd = 130;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 130;
								hintEnd = 132;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE7: // A Blade in the Dark.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							startSteps = 30;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 132;
								hintEnd = 136;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 136;
								hintEnd = 141;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 141;
								hintEnd = 145;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 145;
								hintEnd = 147;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE8: // Diplomatic immunity.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 10;
							startSteps = 34;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 147;
								hintEnd = 148;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 148;
								hintEnd = 152;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 152;
								hintEnd = 153;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 153;
								hintEnd = 156;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 156;
								hintEnd = 159;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 159;
								hintEnd = 163;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 163;
								hintEnd = 165;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								hintCounter = 165;
								hintEnd = 176;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE9:
								hintCounter = 176;
								hintEnd = 181;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE10:
								hintCounter = 181;
								hintEnd = 184;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE9: // A Cornered Rat.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							startSteps = 44;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 184;
								hintEnd = 190;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 190;
								hintEnd = 193;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 193;
								hintEnd = 199;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 199;
								hintEnd = 201;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE10: // Alduin's Wall.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							startSteps = 48;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 201;
								hintEnd = 207;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 207;
								hintEnd = 208;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 208;
								hintEnd = 217;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 217;
								hintEnd = 223;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE11: // The Throat of the World.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 7;
							startSteps = 52;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 223;
								hintEnd = 227;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 227;
								hintEnd = 228;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 228;
								hintEnd = 230;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 230;
								hintEnd = 235;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 235;
								hintEnd = 236;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 236;
								hintEnd = 237;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 237;
								hintEnd = 240;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE12: // Elder Knowledge.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 59;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 240;
								hintEnd = 244;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 244;
								hintEnd = 246;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 246;
								hintEnd = 247;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE13: // Alduin's Bane.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 62;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 247;
								hintEnd = 250;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 250;
								hintEnd = 525;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 252;
								hintEnd = 258;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE14: // The Fallen.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 8;
							startSteps = 65;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 258;
								hintEnd = 260;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 260;
								hintEnd = 262;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 262;
								hintEnd = 263;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 263;
								hintEnd = 266;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 266;
								hintEnd = 268;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 268;
								hintEnd = 270;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE7:
								hintCounter = 270;
								hintEnd = 273;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE8:
								hintCounter = 273;
								hintEnd = 274;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE15: // Paarthurnax.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 2;
							startSteps = 73;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 274;
								hintEnd = 277;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 277;
								hintEnd = 278;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE16: // Season Unending.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 6;
							startSteps = 75;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 278;
								hintEnd = 281;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 281;
								hintEnd = 284;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 284;
								hintEnd = 288;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 288;
								hintEnd = 289;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE5:
								hintCounter = 289;
								hintEnd = 290;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE6:
								hintCounter = 290;
								hintEnd = 292;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE17: // The World-Eater's Eyrie.
							 // Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 4;
							startSteps = 81;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 292;
								hintEnd = 294;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 294;
								hintEnd = 295;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 295;
								hintEnd = 301;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE4:
								hintCounter = 301;
								hintEnd = 307;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE18: // Sovngarde.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 3;
							startSteps = 85;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 307;
								hintEnd = 308;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2:
								hintCounter = 308;
								hintEnd = 311;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE3:
								hintCounter = 311;
								hintEnd = 315;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						case MENUCHOICE19: // Dragonslayer.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 2;
							startSteps = 89;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								hintCounter = 315;
								hintEnd = 320;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							case MENUCHOICE2: 
								hintCounter = 320;
								hintEnd = 324;
								hintChoices(hintCounter, hintEnd, userStepChoice, stepVector, hintVector);
								break;
							}
							break;
						}

					} while (userStepChoice != MENUCHOICE0); // While the user's choice isn't 0.
				}
				if (userCategoryChoice == 2) // Side Quests.
				{
					categoryChoices(userCategoryChoice, questVector); // Get the categories

					cin >> userQuestChoice; // Set user's input to userQuestChoice.
					cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.

					do
					{
						int STEPS = 0;
						// Switch statement to take the user input and print the appropriate steps.
						switch (userQuestChoice)
						{
						case MENUCHOICE1: // The Blessings of Nature.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE2: // Blood on the Ice.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE3: // The Book of Love.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE4: // Delayed Burial.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE5: // Forbidden Legend.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE6: // The Forsworn Conspiracy.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE7: // The Golden Claw.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								break;
							}
							break;
						case MENUCHOICE8: // The Heart of Dibella.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE9: // In My Time of Need.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE10: // Kyne's Sacred Trials.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE11: // Laid to Rest.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE12: // Lights Out!
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE13: // The Man Who Cried Wolf.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE14: // Missing in Action.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE15: // No One Escapes Cidhna Mine.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE16: // Promises to Keep.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE17: // Repairing the Phial.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE18: // Rise in the East.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE19: // Rising at Dawn.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE20: // Unfathomable Depths.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE21: // The White Phial.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						case MENUCHOICE22: // The Wolf Queen Awakened.
							// Set the amount of steps, then give the userQuestChoice, STEPS, questVector, and stepVector to the steps function.
							STEPS = 0;
							startSteps = 0;
							stepChoices(userQuestChoice, STEPS, startSteps, questVector, stepVector);

							cin >> userStepChoice; // Set user's input to userStepChoice.
							// Switch statement to take the user input and print the appropriate hints.
							switch (userStepChoice)
							{
							case MENUCHOICE1:
								// Set the starting hint index, the ending hint index, and call the hint function with all the variables needed.
								break;
							}
							break;
						}
					} while (userStepChoice != MENUCHOICE0); // While the user's choice isn't 0.
				}
			}
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
			cout << "Returning to main menu.." << endl; // Tell the user they are returning to the game choice.
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		}
	} while (userMenuChoice != MENUCHOICE2); // While the user doesn't choose the menu choice two (which is the option 'End Program').

	return 0;
}

void createGame(Game gameArray[1], vector<string> categoryNameVector, vector<Quest> questVector, vector<string> stepVector, vector<string> additionalStepsVector, vector<string> hintVector)
{
	gameArray[0].setGameName("The Elder Scrolls V: Skyrim"); // Set the game name.

	// Set the category names.
	categoryNameVector[0] = "Main Quests";
	categoryNameVector[1] = "Side Quests";

	// MAIN QUESTS STARTS HERE
	// Set the quest names and descriptions (if they have them).
	// Main Quests (0-18).
	questVector[0].setQuestName("Unbound");
	questVector[0].setQuestDescription("After the cart ride is over and you choose your character's race, name, and detailed appearance attributes, wait through another non-interactive sequence to get this quest's first objective.");
	questVector[1].setQuestName("Before the Storm");
	questVector[2].setQuestName("Bleak Falls Barrow");
	questVector[3].setQuestName("Dragon Rising");
	questVector[4].setQuestName("The Way of the Voice");
	questVector[5].setQuestName("The Horn of Jurgen Windcaller");
	questVector[6].setQuestName("A Blade in the Dark\n");
	questVector[7].setQuestName("Diplomatic Immunity");
	questVector[8].setQuestName("A Cornered Rat");
	questVector[9].setQuestName("Alduin's Wall");
	questVector[10].setQuestName("The Throat of the World");
	questVector[11].setQuestName("Elder Knowledge");
	questVector[12].setQuestName("Alduin's Bane\n");
	questVector[13].setQuestName("The Fallen");
	questVector[14].setQuestName("Paarthurnax");
	questVector[14].setQuestDescription("This quest is entirely optional, and can only be gotten by talking to Esbern at the Sky Haven Temple.");
	questVector[15].setQuestName("Season Unending");
	questVector[16].setQuestName("The World - Eater's Eyrie");
	questVector[17].setQuestName("Sovngarde");
	questVector[18].setQuestName("Dragonslayer");

	// Unbound - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[0] = "Make your way to the Keep";
	stepVector[1] = "Enter the Keep with Hadvar or Ralof";
	stepVector[2] = "Objectives for Hadvar's Path";
	stepVector[3] = "Objectives for Ralof's Path";
	// Objectives for Hadvar's Path.
	additionalStepsVector[0] = "Escape Helgen";
	additionalStepsVector[1] = "Find some equipment";
	additionalStepsVector[2] = "(Optional)Search the barrel for potions";
	additionalStepsVector[3] = "(Optional)Attempt to pick the lock to the cage";
	// Objectives for Ralof's Path.
	additionalStepsVector[4] = "Escape Helgen";
	additionalStepsVector[5] = "Loot Gunjar's Body";
	additionalStepsVector[6] = "(Optional)Search the barrel for potions";
	additionalStepsVector[7] = "(Optional)Attempt to pick the lock to the cage";

	// Hints
	// Make your way to the Keep.
	hintVector[0] = "When you gain control, there'll be a guy standing nearby and talking to you. You can also identify him by the quest marker that's hanging over his head (provided you don't use the journal to set this quest as inactive).";
	hintVector[1] = "Follow him through a nearby door, then up the stairs until the dragon makes a big hole in the wall.";
	hintVector[2] = "You'll be instructed to jump through the wall hole, but it's best to just walk forward and drop down onto the edge of the inn's roof, then move to the right a bit so you can jump over the log railing without touching the nearby fire.";
	hintVector[3] = "Go to the other end of the inn and drop down through one of the big floor holes, then go through the doorway ahead and turn left to find the guy you're supposed to follow next.";
	hintVector[4] = "Stay close to him until you meet up with the guy you were following at first. After they split up, you'll get the next objective.";
	// Enter the Keep with Hadvar or Ralof.
	hintVector[5] = "This is the game's first bogus choice, meaning that your decision will have far-ranging consequences, all of which will lead to roughly equivalent outcomes.";
	hintVector[6] = "Hadvar is an Imperial soldier and Ralof is a Stormcloak operative. Which one you follow now will be seen as a choice as to which side you're taking in Skyrim's big civil war. It'll also affect who you travel with for the rest of this quest and the first part of the next one. However, this choice isn't an irrevocable commitment to either side, and you can choose to switch sides later on when it becomes more of an issue.";
	hintVector[7] = "If you'd rather go with Hadvar now, go a short way west to where he's standing, then move into the doorway next to him. If you want to follow Ralof, go a short way north and enter the doorway he's standing next to.";
	// Start of Objectives for Hadvar's Path
	// Escape Helgen.
	hintVector[8] = "Wait for Hadvar to follow you inside, then move up next to him when he says he can get your bonds off.";
	hintVector[9] = "After he cuts your bonds, you'll get the \"Find some equipment\" objective. Finish it, then follow Hadvar through two gates to reach your first combat of the game.";
	hintVector[10] = "After it's over, loot the two Stormcloaks and the dead guy named Gunjar for equipment. After checking to see if you want to equip any of it, follow Hadvar through a door.";
	hintVector[11] = "Look around past it for a lantern and some cheap food items, then follow Hadvar to the next combat area. It also has two fairly weak soldiers in it, so it shouldn't be any problem for you even if you lead the attack in order to get in some skill practice.";
	hintVector[12] = "After that's over, do the \"(Optional)Search the barrel for potions\" objective, then follow Hadvar to the torture chamber, where the torturer and his assistant are under attack by Stormcloak soldiers.";
	hintVector[13] = "You can charge in and practice some skills on the Stormcloaks, or you can hang back and let Hadvar and the torturers take care of business. In either case, start looking around for loot. Before long, you'll get the \"(Optional)Attempt to pick the lock to the cage\" objective.";
	hintVector[14] = "After it's done, move down the passage, watching for a couple of locked cells that you can pick open for more Lockpicking practice. You'll eventually come to a large room with several enemy soldiers in it, some of whom are using bows.";
	hintVector[15] = "Loot them to get a bow and some arrows, then follow Hadvar until you reach a large webby cave with several frostbite spiders in it. Either hang back and try out your new bow, or charge in and start hacking spiders.";
	hintVector[16] = "Loot the spiders and their egg and web sacs, then follow Hadvar along until he stops near a wagon and points out a bear ahead. After looking around the wagon for loot, decide how you want to handle the bear problem.";
	hintVector[17] = "Move on down the passage past the bear's cave until you reach an exit. Move toward it until you're taken outside, then wait until you get the next quest.";
	// Find some equipment.
	hintVector[18] = "All you have to do for this objective is loot the chest that's near the SW corner of the room, but it's best to put that off for a bit.";
	hintVector[19] = "First, look around for other chests and loose items, including two swords on wall racks.";
	hintVector[20] = "Wait until Hadvar walks over to a closed gate, after which you can get in some serious skill practice.";
	hintVector[21] = "When you're tired of that, loot the chest near the SW corner of the room and equip its armor items.";
	// (Optional)Search the barrel for potions.
	hintVector[22] = "As usual with this type of objective, it'll be completed when you search the one item that it's interested in, but you should first look all around for other items to take.";
	hintVector[23] = "You'll find the potion barrel near where the two enemy soldiers were. You'll also find lots of other items to take, not all of which are worth lugging around.";
	hintVector[24] = "After picking up everything, look through your inventory (especially the \"misc\" section) to see what all you can do without.";
	// (Optional)Attempt to pick the lock to the cage.
	hintVector[25] = "First, loot the small table for stuff, then check the large open cage for an iron shield.";
	hintVector[26] = "Next, go over to the three small locked cages and use your new lockpicks to try to get them open.";
	hintVector[27] = "The lockpicking minigame works just like the one in Fallout 3 and Fallout: New Vegas, except it's a bit more primitive and clumsy. Even those who (like me) played those two Fallout games endlessly will need a bit of practice to get used to it, so be sure to quicksave before every lockpick attempt and quickrestore whenever you break a lockpick or two without opening the lock.";
	hintVector[28] = "You only need to lockpick the middle cage open to finish the objective, but you should do all three for extra Lockpicking skill practice.";
	hintVector[29] = "And don't forget to get all the loot that's inside the central cage, including the dead mage's apparel and spell tome.";
	// End of Objectives for Hadvar's Path.
	// Start of Objectives for Ralof's Path
	// Escape Helgen.
	hintVector[30] = "Wait for Ralof to follow you inside, then move up next to him when he says he can get your bonds off.";
	hintVector[31] = "After he cuts your bonds, you'll get the \"Loot Gunjar's body\" objective. Finish it and follow Ralof over to a closed gate, then get ready for your first combat of the game.";
	hintVector[32] = "After it's over, quickly loot the enemy captain's body and take the key before Ralof can. That way, he'll stand near the locked door and let you get some easy skill practice with him.";
	hintVector[33] = "Go through the gate that the Imperials opened and down the passage to reach a room with lots of loot, then go back and open the locked door that Ralof is waiting next to.";
	hintVector[34] = "Look around past it for a lantern and some cheap food items, then follow Ralof to the next combat area. It also has two fairly weak soldiers in it, so it shouldn't be any problem for you even if you lead the attack in order to get in some skill practice.";
	hintVector[35] = "After that's over, do the \"(Optional)Search the barrel for potions\" objective, then follow Ralof to the torture chamber, where Stormcloak soldiers are attacking the torturer and his assistant.";
	hintVector[36] = "You can charge in and practice some skills on the torturers, or you can hang back and let Ralof and the Stormcloak soldiers take care of business. In either case, start looking around for loot. Before long, you'll get the \"(Optional)Attempt to pick the lock to the cage\" objective.";
	hintVector[37] = "After it's done, move down the passage, watching for a couple of locked cells that you can pick open for more Lockpicking practice. You'll eventually come to a large room with several enemy soldiers in it, some of whom are using bows.";
	hintVector[38] = "Loot them to get a bow and some arrows, then follow Ralof until you reach a large webby cave with several frostbite spiders in it. Either hang back and try out your new bow, or charge in and start hacking spiders.";
	hintVector[39] = "Loot the spiders and their egg and web sacs, then follow Ralof along until he stops near a wagon and points out a bear ahead. After looking around the wagon for loot, decide how you want to handle the bear problem.";
	hintVector[40] = "Move on down the passage past the bear's cave until you reach an exit. Move toward it until you're taken outside, then wait until you get the next quest.";
	// Find some equipment.
	hintVector[41] = "Loot the body of the dead guy named Gunjar to get an iron war axe and a couple of armor pieces.";
	// (Optional)Search the barrel for potions.
	hintVector[42] = "As usual with this type of objective, it'll be completed when you search the one item that it's interested in, but you should first look all around for other items to take.";
	hintVector[43] = "You'll find the potion barrel near where the two enemy soldiers were. You'll also find lots of other items to take, not all of which are worth lugging around.";
	hintVector[44] = "After picking up everything, look through your inventory (especially the \"misc\" section) to see what all you can do without.";
	// (Optional)Attempt to pick the lock to the cage.
	hintVector[45] = "First, loot the small table for stuff, then check the large open cage for an iron shield.";
	hintVector[46] = "Next, go over to the three small locked cages and use your new lockpicks to try to get them open.";
	hintVector[47] = "The lockpicking minigame works just like the one in Fallout 3 and Fallout: New Vegas, except it's a bit more primitive and clumsy. Even those who (like me) played those two Fallout games endlessly will need a bit of practice to get used to it, so be sure to quicksave before every lockpick attempt and quickrestore whenever you break a lockpick or two without opening the lock.";
	hintVector[48] = "You only need to lockpick the middle cage open to finish the objective, but you should do all three for extra Lockpicking skill practice.";
	hintVector[49] = "And don't forget to get all the loot that's inside the central cage, including the dead mage's apparel and spell tome.";
	// End of Objectives for Ralof's Path.
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Before the Storm - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps
	stepVector[4] = "Talk to Alvor in Riverwood.";
	stepVector[5] = "Talk to Gerdur in Riverwood.";
	stepVector[6] = "Talk to the Jarl of Whiterun.";

	// Hints
	// Talk to Alvor in Riverwood.
	hintVector[50] = "Even though he says you should split up, Hadvar will wait for you to follow him. You don't have to, but it would be a good idea to follow him to Riverwood, even if you don't plan on finishing this quest anytime soon.";
	hintVector[51] = "Look for harvestable plants and wolves to fight as you follow Hadvar, and check out the three Guardian Stones when you reach their area. You can examine them and choose which one to receive a blessing from.";
	hintVector[52] = "After you reach Riverwood, follow Hadvar into Alvor and Sigrid's house if you want to continue this quest right away.";
	hintVector[53] = "Wait until Alvor talks to you, then take any or all of the gift items he offers you. You'll then get the \"Talk to the Jarl of Whiterun\" objective. (If you went off and did other things before visiting Alvor, talk to him and ask about supplies in order to get the gifts and the objective.)";
	// Talk to Gerdur in Riverwood.
	hintVector[54] = "Even though he says you should split up, Ralof will wait for you to follow him.You don't have to, but it would be a good idea to follow him to Riverwood, even if you don't plan on finishing this quest anytime soon.";
	hintVector[55] = "Look for harvestable plants and wolves to fight as you follow Ralof, and check out the three Guardian Stones when you reach their area.You can examine them and choose which one to receive a blessing from. (See the Skill Practicing Tips for more details.)";
	hintVector[56] = "After you reach Riverwood, follow Ralof over to where his sister Gerdur is working.";
	hintVector[57] = "Listen to them and follow them around until Gerdur talks to you.Take any or all of the gift items she offers you, then go check out her house before starting on the new \"Talk to the Jarl of Whiterun\" objective.";
	// Talk to the Jarl of Whiterun.
	hintVector[58] = "TIP: Explore Riverwood for loot and skill-practicing opportunities before you start working on this objective.";
	hintVector[59] = "When you're ready to go to Whiterun, cross the bridge that's just NE of Riverwood, then turn right and follow the winding path until you reach an intersection with two bridges.";
	hintVector[60] = "Head down the path that leads west, passing the Honningbrew Meadery and then the Pelagia Farm. Turn right at the path split just past the farm and go past the Whiterun Stables.";
	hintVector[61] = "Continue down the path until you reach the guarded entrance to Whiterun. One of the guards will talk to you and say that the city is closed due to recent dragon activity.";
	hintVector[62] = "You can get the guard to let you pass by saying that Riverwood calls for the Jarl's aid, or you can try the persuade or intimidate option to get some Speech skill practice. In any case, use the big gate to enter Whiterun.";
	hintVector[63] = "Go east down the street until you reach a well near some market stalls, then turn left and go up the stairs to reach a large circular area with a big tree in the center.";
	hintVector[64] = "Go up the stairs north of the tree, then keep going until you discover Dragonsreach. That's where the Jarl of Whiterun lives, so use the big doors to go inside.";
	hintVector[65] = "Move up the stairs and toward the large log fire to get Irileth to talk to you. Say that you have news from Helgen, then approach the Jarl and talk to him.";
	hintVector[66] = "After you tell him what you saw in Helgen, he'll give you a leveled suit of armor and the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Bleak Falls Barrow - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[7] = "Talk to Farengar.";
	stepVector[8] = "Retrieve the Dragonstone.";
	stepVector[9] = "Deliver the Dragonstone to Farengar.";

	// Hints.
	// Talk to Farengar.
	hintVector[67] = "Follow the Jarl into Farengar's room, then wait for him to talk to you.";
	hintVector[68] = "Ask him about what he wants you to fetch to get the next objective, then check out his store inventory before you go.";
	// Retrieve the Dragonstone.
	hintVector[69] = "NOTE: This is where the main quests start getting harder and more combat-intensive, so low-level characters will probably want to go do some random exploring, skill practicing, optional quests, etc. Or go as far as you can on this quest, then go off and do other things for awhile.";
	hintVector[70] = "Exit Dragonsreach and fast-travel back to Riverwood, then go cross the bridge NE of it again.";
	hintVector[71] = "This time, go left instead of right, and start following the path up the mountain. You'll only encounter a wolf or two at first, but watch for several bandits when you get near an old watchtower.";
	hintVector[72] = "Move down the path past the watchtower until you discover the Bleak Falls Barrow, then be ready to fight more bandits after you go up some steps.";
	hintVector[73] = "Enter the Bleak Falls Temple area, then make your way through it and the sanctum area to find the Dragonstone.";
	// Deliver the DragonStone to Farengar.
	hintVector[74] = "Look south of the sarcophagus platform to find some stairs that lead to a cave tunnel.";
	hintVector[75] = "When it dead-ends, look on the top of the nearby fancy pedestal to find a handle.";
	hintVector[76] = "Use it to open up the passage, then go down it until you reach a drop-off.";
	hintVector[77] = "Not far past it is an exit you can use to get outside.";
	hintVector[78] = "Fast-travel back to Dragonsreach, then go inside and talk to Farengar in his room to get the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Dragon Rising - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[10] = "Talk to Jarl Balgruuf.";
	stepVector[11] = "Meet Irileth near the Western Watchtower.";
	stepVector[12] = "Kill the dragon.";
	stepVector[13] = "Investigate the dragon.";
	stepVector[14] = "(Optional)Use your new Shout power.";
	stepVector[15] = "Report back to Jarl Balgruuf.";

	// Hints.
	// Talk to Jarl Balgruuf.
	hintVector[79] = "Wait until Irileth shows up and reports a dragon sighting, then follow her to the Jarl.";
	hintVector[80] = "You'll get the next objective after the Jarl talks to you and gives you a reward for getting the Dragonstone.";
	hintVector[81] = "NOTE: The reward includes permission to buy a house in Whiterun, which you can do now if you have 5000 gold to spare. Find Proventus Avenicci (who's usually in Dragonsreach or the adjacent Jarl's quarters) and talk to him about it, then go find the house called Breezehome a bit east of Whiterun's main gate. Enter it and go upstairs to find a bed you can sleep in and a chest you can store stuff in. (If you want to buy more storage containers, an alchemy lab, or other decorations, talk to Avenicci about it.)";
	// Meet Irileth near the Western Watchtower.
	hintVector[82] = "Follow Irileth out of Dragonsreach and down to where she talks to some soldiers. After that, follow her outside and down to the western watchtower.";
	hintVector[83] = "NOTE: If you don't follow Irileth out of Whiterun, you can go meet up with her whenever you're ready. Check the world map to see where the Western Watchtower location is, then look just east of it for a quest marker that shows the rendezvous point. There'll be another quest marker showing Irileth's current location.";
	hintVector[84] = "After Irileth runs up the watchtower's large ramp, go past her and enter the tower. Quicksave, then wait for the next objective.";
	// Kill the dragon.
	hintVector[85] = "If you've taken cover inside the watchtower, you won't be able to see the dragon much since it flies around a lot. It does occasionally land, but not necessarily within sight of the tower's doorway.";
	hintVector[86] = "You could go outside and run around the tower, trying to use cover to avoid the dragon's fiery breath attacks while hitting it with your best ranged attacks. However, you'll probably get flamed sooner or later that way, and that'll kill you very quickly if you don't have any fire resistance from equipment or potions. The same problem applies to attacking the dragon from the tower's roof.";
	hintVector[87] = "Fortunately, your Whiterun allies will be out there doing the dragon some damage, so you can just stay near the top of the ramp and shoot off arrows or spells from there whenever the dragon lands nearby. Eventually, it'll die, and you'll get the next objective.";
	// Investigate the dragon.
	hintVector[88] = "Go over to the dragon's corpse and wait for it to burst into flames, which signifies that you're absorbing the power of its dragon-y soul. After that's done, you'll get the next two objectives.";
	// (Optional)Use your new Shout power.
	hintVector[89] = "Bring up your Spells menu and click on \"shouts,\" then click on the Unrelenting Force shout to equip it. (Note that this doesn't take up either of your hands like magic spells do. Consider it a \"mouth power.\")";
	hintVector[90] = "Close the Spells menu and face one or more of the nearby guards, then hit the Shout key. (Don't worry -- they won't turn hostile.)";
	// Report back to Jarl Balgruuf.
	hintVector[91] = "Search the dragon's body for loot, then fast-travel back to Whiterun.";
	hintVector[92] = "Wait until a loud voice says \"do vah keen\" then fast-travel to Dragonsreach and go inside.";
	hintVector[93] = "The Jarl is back on his throne, so go up to him to get him to talk to you and start the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Way of the Voice - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[16] = "Speak to the Greybeards.";
	stepVector[17] = "Demonstrate your \"Unrelenting Force\" Shout.";
	stepVector[18] = "Speak to Arngeir.";
	stepVector[19] = "Learn the Word of Power from Einarth.";
	stepVector[20] = "Demonstrate your \"Unrelenting Force\" Shout";
	stepVector[21] = "Learn the Word of Power from Borri.";
	stepVector[22] = "Demonstrate your \"Whirlwind Sprint\" Shout.";
	stepVector[23] = "Speak to Arngeir for further training.";

	// Hints.
	// Speak to the Greybeards.
	hintVector[94] = "Stand and wait until the Jarl rewards you with a magic weapon and the title of Thane of Whiterun.";
	hintVector[95] = "The first step to reaching High Hrothgar is traveling to Ivarstead.";
	hintVector[96] = "Cross the bridge that's at the north end of Ivarstead, then go up the stone steps to start on the long path to High Hrothgar.";
	hintVector[97] = "NOTE: Starting at the beginning of the steps, and ending up near the monastery, there's a series of ten little shrines with etched tablets in them. If you read all ten of them on your way up, you'll get a one-day blessing called Voice of the Sky that'll prevent any animals from attacking you or fleeing from you (unless you attack them). Now you can pet the deer and run with the wolves!";
	hintVector[98] = "When you get up to where snow is on the ground, you'll have a slightly harder time seeing the path at some points. Always look ahead for the next set of stone steps to help guide you.";
	hintVector[99] = "After you go a ways along the snowy path, you'll reach a narrow passage where a frost troll will attack you. If it's too much for you to handle, try to sprint on past it and leave it behind.";
	hintVector[100] = "A ways past it, you'll come to the entrance to High Hrothgar. Check the little shrine area with the big chest in it for items, including a disease-curing potion, then go up the steps on either side to find a door.";
	hintVector[101] = "Use it to enter the monastery, then move forward to meet Arngeir. Talking to him will get you the next objective.";
	// Demonstrate your "Unrelenting Force" Shout.
	hintVector[102] = "Make sure that your Unrelenting Force shout is selected, then hit the Shout key to give Arngeir the demonstration he wants.";
	// Speak to Arngeir.
	hintVector[103] = "Move up to Arngeir and wait for him to talk to you.";
	hintVector[104] = "Choose the dialogue topic about being ready to learn when it comes up, then wait a bit to get the next objective.";
	// Learn the Word of Power from Einarth.
	hintVector[105] = "Wait until Einarth shouts the word you're to learn onto the floor.";
	hintVector[106] = "Move up to it to learn the word, then wait to get the next objective.";
	// Demonstrate your "Unrelenting Force" Shout.
	hintVector[107] = "Turn to face the floor section that you learned Einarth's word from, and wait for a ghostly apparition to appear on it.";
	hintVector[108] = "When one does, face it and hit the Shout key. Don't just tap it for minimal effect, but hold it down to utter a more powerful version of the shout (which is possible now that you know more than one of its words).";
	hintVector[109] = "When you do that, the first number in the objective name should increase. Wait for another apparition to appear, then repeat the process until you've done all three.";
	// Learn the Word of Power from Borri.
	hintVector[110] = "Follow the monk named Borri to the courtyard, then wait for him to shout a word onto the ground.";
	hintVector[111] = "Move onto it to learn it, then wait to get the next objective.";
	// Demonstrate your "Whirlwind Sprint" Shout.
	hintVector[112] = "Follow Borri to a gate, then stand aside and watch as another monk uses the Whirlwind Sprint shout to zoom through the gate super-fast.";
	hintVector[113] = "Bring up your Spells menu and select Whirlwind Sprint as your current shout, then go stand next to Arngeir and face the gate.";
	hintVector[114] = "When the gate opens, hit the Shout key to be propelled quickly through it.";
	// Speak to Arngeir for further training.
	hintVector[115] = "Shout your way back over to Arngeir (or just walk over there) to get him to talk to you and start the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Horn of Jurgen Windcaller - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[24] = "Retrieve the Horn of Jurgen Windcaller.";
	stepVector[25] = "Read the note.";
	stepVector[26] = "Meet with whoever took the horn.";
	stepVector[27] = "Return the horn to Arngeir.";
	stepVector[28] = "Learn the Word of Power from Wulfgar.";
	stepVector[29] = "Receive the Greybeards' greeting.";

	// Hints.
	// Retrieve the Horn of Jurgen Windcaller.
	hintVector[116] = "Before you can start searching for the horn, you'll have to make the long trek to Ustengrav.";
	hintVector[117] = "Be ready to fight some bandits and a necromancer as you approach Ustengrav, then drop into the stone pit (or take its \"stairs\" down) and use the door.";
	hintVector[118] = "You'll need to make your way through Ustengrav's two areas to reach the tomb of Jurgen Windcaller.";
	// Read the note.
	hintVector[119] = "Go up to the tomb and read the mysterious note that's in the large stone hand.";
	// Meet with whoever took the horn.
	hintVector[120] = "Go through the door behind the tomb, then check for loot before using the cave tunnel to reach a door that leads back to the main Ustengrav area.";
	hintVector[121] = "Continue along the tunnel until it ends, then use the nearby lever to open up a secret panel.";
	hintVector[122] = "Go through it, then use the area map to help you navigate your way back to the door that leads outside.";
	hintVector[123] = "Fast-travel to Riverwood, then enter the inn and talk to Delphine.";
	hintVector[124] = "Say that you'd like to rent the attic room, then open the middle door in the west wall to enter the room that she sends you to.";
	hintVector[125] = "Wait inside the room until Delphine comes in and talks to you, which gives you the next objective (and the next quest).";
	// Return the horn to Arngeir.
	hintVector[126] = "Work on the \"A Blade in the Dark\" quest until Delphine leads you into her secret room, but don't talk to her. Instead, leave the inn and fast-travel back to High Hrothgar.";
	hintVector[127] = "Enter the monastery, then use the local area map and quest marker to find Arngeir. Talk to him to get the next objective.";
	// Learn the Word of Power from Wulfgar.
	hintVector[128] = "Follow Arngeir down to where Wulfgar is waiting.";
	hintVector[129] = "After he shouts a word onto the floor, move onto it to learn it and get the next objective.";
	// Receive the Greybeards' greeting.
	hintVector[130] = "Stand on the floor section that's between the monks and wait through their final test in order to finish the quest.";
	hintVector[131] = "TIP: Return to Ustengrav and make your way back to the tomb of Jurgen Windcaller. Activate it to replace the horn and gain a bonus dragon soul.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// A Blade in the Dark - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[30] = "Talk to Jarl Balgruuf.";
	stepVector[31] = "Meet Irileth near the Western Watchtower.";
	stepVector[32] = "Kill the dragon.";
	stepVector[33] = "Investigate the dragon.";

	// Hints.
	// Talk to Delphine.
	hintVector[132] = "Follow Delphine into another room, then close the door when she says to.";
	hintVector[133] = "She'll open up a secret panel and enter a secret room. Follow her in, but don't get close enough to her to trigger a conversation yet.";
	hintVector[134] = "First, loot the entire inn for items (it no longer counts as stealing) and finish up the \"The Horn of Jurgen Windcaller\" quest. Then come back and talk to Delphine.";
	hintVector[135] = "Ask her about everything to get the next objective.";
	// Locate the dragon burial site.
	hintVector[136] = "Even if you tell Delphine that you're not ready to go yet, she'll don her armor and start off for Kynesgrove. (That's why I advised you not to talk to her until after you went and finished the previous quest. It's more convenient to follow her to Kynesgrove than to make your own way there.)";
	hintVector[137] = "As you move into Kynesgrove, one of the residents will talk to you about the dragon at the burial mound. That's where you need to go next.";
	hintVector[138] = "Go up to the inn, then use the path that starts on its left side to get up to the burial mound, where you'll find Delphine hiding behind a large boulder.";
	hintVector[139] = "Quicksave, then go up and stand next to her.";
	hintVector[140] = "Get out your bow and move around the left side of the boulder so you can see the burial mound ahead. You could just hide and wait for the next objective, but it's best to get a few shots off at the newly resurrected dragon as soon as it rises from the mound.";
	// Kill the dragon Sahloknir.
	hintVector[141] = "If you started hitting Sahloknir with arrows as soon as it rose up, it may come toward you and start breathing fire. If so, take cover behind the boulder and hope it gets interested in Delphine or your follower (if you have one).";
	hintVector[142] = "If you're lucky, it'll stay on the ground and attack someone else, allowing you to approach it from the side and hit it with your best melee weapon. If you're *really* lucky, you'll be able to kill it before it takes to the air.";
	hintVector[143] = "If you're not so lucky, the dragon will start flying around and flaming you from the air. There's very little cover from aerial assaults, though you could try crouching down and moving around the large boulder until the dragon gets interested in someone else.";
	hintVector[144] = "If it gets too hard, quickrestore and try again. Maybe you'll get lucky next time and be able to kill the dragon before it starts flying around.";
	// Talk to Delphine.
	hintVector[145] = "Approach the dead dragon to absorb its soul, then check its body for items.";
	hintVector[146] = "Talk to Delphine about everything to get the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Diplomatic Immunity - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[34] = "Meet Delphine in Riverwood.";
	stepVector[35] = "Meet Malborn in Solitude.";
	stepVector[36] = "Give Malborn the equipment.";
	stepVector[37] = "Meet Delphine at the stables.";
	stepVector[38] = "Talk to Malborn.";
	stepVector[39] = "Create a distraction and get away from the party.";
	stepVector[40] = "(Optional)Retrieve your gear.";
	stepVector[41] = "Search for information about the dragons returning.";
	stepVector[42] = "Escape the Thalmor Embassy.";
	stepVector[43] = "Talk to Delphine.";

	// Hints.
	// Meet Delphine in Riverwood.
	hintVector[147] = "Return to Riverwood's inn and talk to Delphine in her secret room to get the next objective.";
	// Meet Malborn in Solitude.
	hintVector[148] = "If you don't mind spending a bit of gold, you can go to any stable (like the one in Whiterun) and pay the carriage driver to take you to Solitude.";
	hintVector[149] = "After entering Solitude, go a short way forward and look to your left for the Winking Skeever inn.";
	hintVector[150] = "Enter the inn and look for Malborn at a table near the back. Talk to him to get the next objective.";
	hintVector[151] = "NOTE: You shouldn't talk to Malborn to continue this quest unless your skills for fighting tough enemies or sneaking past them unseen are very high. Go practice them up and/or do other quests first if necessary.";
	// Give Malborn the equipment.
	hintVector[152] = "Use the inventory screen that comes up to give Malborn your best armor, weapons, potions, and other items that you'll need later on to aid you in fighting the Thalmor soldiers or sneaking past them.";
	// Meet Delphine at the stables.
	hintVector[153] = "Leave the inn and go back through Solitude's gate, then head down the path to Katja's Farm.";
	hintVector[154] = "You'll find Delphine next to the windmill. Talk to her to get an invitation and some suitable attire.";
	hintVector[155] = "Go to inventory and put the party boots and party clothes on, then talk to Delphine again and say you're ready to go.";
	// Talk to Malborn.
	hintVector[156] = "Go over to the nearby stairs and show the soldier your invitation.";
	hintVector[157] = "Go up the stairs and into the embassy building, where you'll be talked to briefly by Elenwen.";
	hintVector[158] = "After she wanders off, go up to Malborn's counter and talk to him to get the next objective.";
	// Create a distraction and get away from the party.
	hintVector[159] = "Malborn is going to let you into the kitchen, but he won't dare do it unless the party guests are all distracted first.";
	hintVector[160] = "One possibility for this is to find a guest that you're on good terms with (from other quests) and ask him to cause a distraction for you. This may or may not require you to succeed at a persuade dialogue option.";
	hintVector[161] = "Another option is to get Razelan or Erikur to cause a distraction.";
	hintVector[162] = "As soon as a distraction is started, run over to a spot near the door that's behind Malborn's counter and wait for him to open it. When he does, quickly run through it, then wait to get the next two objectives.";
	// (Optional)Retrieve your gear.
	hintVector[163] = "Follow Malborn through the kitchen and into a side room with a chest.";
	hintVector[164] = "Loot the chest to get all the gear you gave Malborn earlier when you were talking to him in the inn.";
	// Search for information about the dragons returning.
	hintVector[165] = "Go through the door near the equipment chest and close it behind you, then crouch down and sneak past the open door on the left while staying on the right side of the hallway.";
	hintVector[166] = "Enter the hallway's other open room and look near the doorway for three articles of Thalmor wizard clothing that you can take and wear as a disguise. The guards will still attack you if you get close to them, but it may help a bit in sneaking around.";
	hintVector[167] = "Sneak back to the open door with the guards just past it, and stop in a spot where you can see part of the nearest guard. When they're done talking, they'll walk away from the counter they're at, and you'll have a chance to sneak around the counter and up the stairs unseen.";
	hintVector[168] = "If you fight the guards instead of sneaking past them, the wizard who's upstairs will come down and join the battle. Otherwise, you'll have to sneak by him (or kill him with a powerful sneak attack) once you get up there.";
	hintVector[169] = "Check the upstairs rooms for loot if you want, then use the door that takes you to a small outdoor area. It also has several guards, which will make it very hard to sneak over to the door to the Elenwen's Solar area. If you're the stealthy type, you may want to use sneak attacks to eliminate the guards. (Or an Invisibility potion to skip combat.)";
	hintVector[170] = "When you enter the solar, you'll see a guard across the room from you with her back turned. If you can't sneak around without her hearing you, you'd better hit her with a sneaky arrow, then get ready to fight her and two other guys who will come running (one of whom is a mage).";
	hintVector[171] = "Go through the doorway in the NW corner of the entry room to find an office. Search the chest behind the desk to find a document called \"Dragon Investigation : Current Status.\"";
	hintVector[172] = "Take it and read it in the books section of your inventory, then go down the stairs at the other end of the office to find a door that leads to the dungeon.";
	hintVector[173] = "In the dungeon, sneak around to the top of some stairs, then sneak down them and take cover to the right of the doorway. Enter third-person mode so you can rotate your view around and see the patrolling guard without having to be in the doorway.";
	hintVector[174] = "You could sneak around without the guard seeing you, but it's much more convenient to kill her. After you do, there are two ways to get the second bit of information that you need.";
	hintVector[175] = "One is to get the \"Thalmor Dossier : Esbern\" from the chest that's in the area to the right of the prison cells, and the other is to talk to the guy who's chained up in the nearest prison cell. Either way, you'll get the next objective.";
	// Escape the Thalmor Embassy.
	hintVector[176] = "Soon after you get this objective, two Thalmor soldiers will enter the area with Malborn, having discovered that he was working with you.";
	hintVector[177] = "You're going to have to kill them, so it's best to weaken at least one of them with sneak attacks first. Also, try to keep Malborn alive, though doing so isn't essential.";
	hintVector[178] = "After they're down, search them to find a trap door key. Talk to Etienne Rarnis in the prison cell and free him, then follow him over to the trap door. (If your distraction at the party earlier involved Brelas, you can find her in another cell and free her, too.)";
	hintVector[179] = "Use the trap door to enter a cave, then go down the narrow passage to reach a drop-off that leads to a frost troll's lair. You could stay up on your ledge and shoot arrows or spells down at it, but your dumb companions will probably drop down there and get themselves killed.";
	hintVector[180] = "In any case, kill the troll and drop down (in either order), then find the passage on the other side of the cave that leads to an exit. (Note that there's a special gem near the drop-down point that you might want to take before you go.)";
	// Talk to Delphine.
	hintVector[181] = "Before you return to Riverwood, you might want to visit a couple of dragon mounds where Alduin has recently resurrected some dragons (if you feel like fighting the resurrected dragons).";
	hintVector[182] = "Fast-travel back to Riverwood, then enter the inn and find Delphine in her secret room.";
	hintVector[183] = "Talk to her about Esbern to get the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// A Cornered Rat - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[44] = "Talk to Brynjolf.";
	stepVector[45] = "Search the Ratway for Esbern's hideout. ";
	stepVector[46] = "Find Esbern in the Ratway Warrens.";
	stepVector[47] = "Talk to Esbern.";

	// Hints.
	// Talk to Brynjolf.
	hintVector[184] = "Reclaim your confiscated gear from one of the chests in the secret room, then leave the inn and go to Riften. (If you don't want to take a carriage, fast-travel to Ivarstead, then follow the river east.)";
	hintVector[185] = "When you approach Riften's gate, one of the guards will try to extort a \"visitor's tax\" from you (if this is your first visit). You can either pay it or try to persuade or intimidate your way out of paying.";
	hintVector[186] = "After you enter Riften, follow the quest arrow to find Brynjolf, who'll be inside the Bee and Barb inn (if it's night) or in his stall in the marketplace just south of the inn (daytime).";
	hintVector[187] = "Walk up to him to get him to talk to you, then say that you're looking for an old man who's hiding out in Riften.";
	hintVector[188] = "If you've already done the first Thieves Guild faction quest or can pass a persuade check, Brynjolf will help you right away.";
	hintVector[189] = "Otherwise, either do his quest or skip it by asking Keerava at the inn's counter about the old man you're looking for. Either way gets you the next objective.";
	// Search the Ratway for Esbern's hideout. 
	hintVector[190] = "See the \"Taking Care of Business\" Thieves Guild faction quest's first objective for directions on getting to the Ragged Flagon.";
	hintVector[191] = "If you did Brynjolf's quest, ask him about the old man again to get the next objective. Otherwise, try talking to someone else.";
	hintVector[192] = "You can ask both Dirge and Vekel the Man about the old man, but you'll have to either bribe them or pass a persuade option (or brawl, in the case of Dirge) if you're not a respected member of the Thieves Guild.";
	// Find Esbern in the Ratway Warrens.
	hintVector[193] = "Use the door that's to the right of the bar counter to enter the Ratway Vaults, then crouch down. There are several Thalmor soldiers and mages in the area.";
	hintVector[194] = "If you want to avoid combat, move straight forward and look down to see an open metal door on the lower floor. Quickly drop down there and go through the door, then turn right and run for the door to the Ratway Warrens area.";
	hintVector[195] = "In the warrens, move down the steps, then either pick open the door on the right or go around to get to the room that's past it.";
	hintVector[196] = "Go up the stone steps and watch out for a couple of crazy characters who may attack you as you make your way to the door that's at the south end of the upstairs area.";
	hintVector[197] = "Use the door to get Esbern to talk to you, then persuade him to open up.";
	hintVector[198] = "The only way to do that is to use the dialogue option about the 30th of Frostfall when it comes up.";
	// Talk to Esbern.
	hintVector[199] = "Wait until Esbern opens his door, then go inside and wait for him to talk to you.";
	hintVector[200] = "Choose whatever dialogue options you want until you get the next quest.";

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Alduin's Wall - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[48] = "Escort Esbern to Riverwood";
	stepVector[49] = "Talk to Esbern";
	stepVector[50] = "Gain entrance to Sky Haven Temple";
	stepVector[51] = "Learn the secret of Alduin's Wall";

	// Hints.
	// Escort Esbern to Riverwood. 
	hintVector[201] = "Wait as Esbern runs around and looks for stuff to take with him, then talk to him and ask if he knows the way out.";
	hintVector[202] = "Follow him back to the Ratway Vaults area, then help him kill the Thalmor soldiers and mages that attack.";
	hintVector[203] = "Follow him back to the Ragged Flagon, then over to a raised wooden bridge.";
	hintVector[204] = "Use the big lever on the wall to the right of the bridge to lower it, then cross it and kill the assassin named Shavari (if she appears there). Note that there may also be a couple of Thalmor nearby.";
	hintVector[205] = "Follow Esbern until he goes outside, then fast-travel to Riverwood and enter the inn.";
	hintVector[206] = "Wait while he talks to Delphine, then follow them into her secret room and wait until you get the next objective.";
	// Talk to Eszern.
	hintVector[207] = "Talk to Esbern about how to find Alduin's Wall to get the next objective.";
	// Gain Entrance to Sky Haven Temple
	hintVector[208] = "Wait until Delphine talks to you, then decide whether you'd like to travel to Karthspire with her and Esbern or alone.";
	hintVector[209] = "It's always better to have more companions along (unless you're still practicing your combat skills), so say you'll travel with them, then leave the inn.";
	hintVector[210] = "Before you continue with this quest, you may want to visit four dragon mounds that now have live dragons at them. Your two unkillable traveling companions will be a big help when fighting the dragons, as long as they don't run off on you.";
	hintVector[211] = "Assuming you decide to save those dragons for later, fast-travel to the Whiterun Stables, then use the carriage to travel to Markarth. (Or fast-travel straight there if you've already discovered it.)";
	hintVector[212] = "You can then talk to Delphine and say you'll meet her at Karthspire in order to get her to lead the way. Follow her and Esbern along, ready to help them kill two dragons along the way. (NOTE: The second dragon attacks near Karthspire, and may get distracted by the forsworn guys who are at the Karthspire Camp.)";
	hintVector[213] = "After the dragon and all the forsworn are dead, go up the path from the camp that leads to a dark cave entrance. Move into it to get Delphine and Esbern to catch up with you.";
	hintVector[214] = "Follow them into a forsworn camp, and then on to a large chamber with some stairs that lead to three small stone pillars.";
	hintVector[215] = "Cross the lowered bridge, then move on to a room with a large array of pressure plates on the floor.";
	hintVector[216] = "Follow Esbern until you discover the Sky Haven temple, then look for a way to open its large carved-face door.";
	// Learn the secrets of Anduin's Wall
	hintVector[217] = "Past the carved-face door, go up the steps and through a door to enter the main temple area, then run up some more steps.";
	hintVector[218] = "Look around the area for loot, including a full suit of Blades armor and a unique sword named Dragonbane, while waiting for Esbern to find Alduin's Wall.";
	hintVector[219] = "After he move up to its left end, move close to him and wait as he uses the wall to determine that Alduin was once defeated by some sort of shout.";
	hintVector[220] = "After that, Delphine will talk to you about it, and you'll get the next quest.";
	hintVector[221] = "TIP: Ask Esbern for advice on fighting dragons, then say you need the dragon-slaying blessing. That'll get you a magic effect that gives you a 10% higher critical hit chance against dragons for five game days. When it wears off, you can come back and talk to Esbern to get it again.";
	hintVector[222] = "TIP: You can also now talk to Delphine to start on the Blades Faction Quests.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Throat of the World - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[52] = "Talk to Arngeir";
	stepVector[53] = "Learn the \"Clear Skies\" Shout";
	stepVector[54] = "Use the \"Clear Skies\" Shout to open the path";
	stepVector[55] = "Talk to Paarthurnax";
	stepVector[56] = "Learn the Word of Power from Paarthurnax";
	stepVector[57] = "Use your \"Fire Breath\" Shout on Paarthurnax";
	stepVector[58] = "Talk to Paarthurnax";

	// Hints.
	// Talk to Arngeir
	hintVector[223] = "Use the stairs that are to the right of Alduin's Wall to get up to the top of the wall, then go up the stairs to the north to find an exit.";
	hintVector[224] = "Fast-travel to High Hrothgar, then enter the monastery and follow the quest arrow to Arngeir.";
	hintVector[225] = "Talk to him and say that you need to learn the shout that defeated Alduin. After he rants at you a bit, wait until he talks to you again.";
	hintVector[226] = "After that conversation is over, follow him outside and over to a log fire, after which you'll get the next objective.";
	// Learn the "Clear Skies" Shout. 
	hintVector[227] = "Wait until Arngeir shouts three words onto the ground, then step on them in the order that he did them to absorb them all.";
	// Use the "Clear Skies" Shout to open the path. 
	hintVector[228] = "After Arngeir shares his knowledge of the Clear Skies shout with you, go up the nearby stairs to reach a spot that you can't push your way past.";
	hintVector[229] = "Bring up the Spells menu and select the Clear Skies shout, then hit the Shout key to get the next objective.";
	// Talk to Paarthurnax.
	hintVector[230] = "As you run down the winding path, you'll have two hazards to watch out for.";
	hintVector[231] = "One is ice wraiths, which look like flying skeletal eels. Quickly hit them with fire spells and your best weapon to keep them from killing you with their cold damage attacks.";
	hintVector[232] = "The other hazard is the weather, which can sap your health and stamina. To prevent it from doing that, keep using the Clear Skies shout every time it recharges.";
	hintVector[233] = "You'll eventually make it to the Throat of the World location, where a dragon will land next to you.";
	hintVector[234] = "It's Paarthurnax, so don't attack it. Instead, talk to it and then wait to get the next objective.";
	// Learn the Word of Power from Paarthurnax.
	hintVector[235] = "Go over to the wrecked Word Wall that Paarthurnax shouted a word onto to learn it, then wait to get the next objective.";
	// Use your "Fire Breath" Shout on Paarthurnax. 
	hintVector[236] = "Go to the Spells menu and equip your new Fire Breath shout, then aim at Paarthurnax and hit the Shout key.";
	// Talk to Paarthurnax.
	hintVector[237] = "Go over to Paarthurnax to get him to talk to you, then say that you want to learn the Dragonrend shout.";
	hintVector[238] = "After a great deal of discourse, you'll get the next quest.";
	hintVector[239] = "TIP: Ask Paarthurnax if others come to him to train, then choose a word to meditate on. You can choose \"fus\" (the first word of Unrelenting Force), \"feim\" (the first word of Become Ethereal), or \"yol\" (the first word of Fire Breath). Meditating on \"fus\" makes you stagger 25% less and your opponents stagger 25% more, meditating on \"feim\" makes your health regenerate 25% faster while you're ethereal, and meditating on \"yol\" makes your Fire Breath shout do 25% more damage. You can return to Paarthurnax and change which meditation you have at any time.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Elder Knowledge - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[59] = "Learn the location of the Elder Scroll";
	stepVector[60] = "(Optional) Talk to Esbern or (Optional) Talk to Arngeir";
	stepVector[61] = "Recover the Elder Scroll";

	// Hints.
	// Learn the location of the Elder Scroll
	hintVector[240] = "Before you start on this quest, you can optionally go around and kill the last five dragons to be resurrected from dragon mounds.";
	hintVector[241] = "Do the \"(Optional)Talk to Esbern or (Optional)Talk to Arngeir\" objective if you want, then take a carriage to Winterhold if you haven't discovered it already.";
	hintVector[242] = "You'll need to get into the College of Winterhold and start on the \"Discerning the Transmundane\" Daedric quest. See it for all the details.";
	hintVector[243] = "You'll get this quest's \"Recover the Elder Scroll\" objective when you talk to Septimus Signus for that quest.";
	// (Optional) Talk to Esbern or (Optional) Talk to Arngeir
	hintVector[244] = "Fast-travel to either High Hrothgar and talk to Arngeir or to the Sky Temple and talk to Esbern.";
	hintVector[245] = "Either one of them will refer you to the magical college at Winterhold.";
	// Recover the Elder Scroll
	hintVector[246] = "There's nothing to do on this objective separate from the \"Discerning the Transmundane\" Daedric quest. Work on it until you get the Elder Scroll, at which time you'll get the next main quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Alduin's Bane - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[62] = "Read the Elder Scroll at the Time-Wound";
	stepVector[63] = "Learn the \"Dragonrend\" Shout from the Nord heroes";
	stepVector[64] = "Defeat Alduin";

	// Hints.
	// Read the Elder Scroll at the Time-Wound
	hintVector[247] = "WARNING: Don't go any farther if you're not ready for a very tough combat with a very tough dragon.Make sure you have a follower, a Conjuration spell that'll summon a powerful creature, potions and spells that give temporary fire resistance, and all of that sort of thing in addition to your best weapons and armor. Also, make a regular save at this point, just in case.";
	hintVector[248] = "Fast - travel to the Throat of the World, then go past the spot where Paarthurnax is waiting to find the shimmery \"time wound.\"";
	hintVector[249] = "Quicksave, then go to the books section of your inventory and click on the Elder Scroll to read it. If that doesn't get you the next objective, try doing so again in a slightly different position.";
	// Learn the "Dragonrend" Shout from the Nord heroes
	hintVector[250] = "The only thing you can do during this objective is rotate your view. Just watch and wait until the vision ends and you get the next objective.";
	hintVector[251] = "GLITCH NOTE: The game might permanently stall at some point during the vision. If that happens, load a recent save and try again.";
	// Defeat Alduin
	hintVector[252] = "As soon as you regain control, bring up the Spells menu and select the Dragonrend shout. If you have an Amulet of Talos, you'll probably want to equip it to shorten the time you have to wait between shouts.";
	hintVector[253] = "Look up and wait if necessary for Alduin to go into hover mode, then aim at him and lean on the Shout key. That won't immediately drop him down, but it should cause him to land near you soon.";
	hintVector[254] = "As soon as he does, lay into him with your best weapons, spells, and/or other shouts. You'll want to deal him as much damage as possible before he takes off again.";
	hintVector[255] = "If you want to keep fighting him continuously instead of letting him fly around between attacks, keep hitting him with Dragonrend every time it recharges. Even if he starts to take off, he should drop right back down. The disadvantage of this method is that you'll be under more or less constant attack, and will have to run around and use strong healing potions to stay alive.";
	hintVector[256] = "Another thing you could try is bringing him down and then taking cover behind the nearby damaged Word Wall. Peek out and shoot him with arrows or ranged spells (and Dragonrend to keep him down). Paarthurnax will occasionally attack him for some added damage. Watch out for him edging around to where he can get at you behind the wall. You'll probably want to let him take off and fly around a bit every now and then to prevent that from happening.";
	hintVector[257] = "Stop attacking Alduin when his health bar disappears. After he brags about how you can't kill him and flies away, you'll get the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Fallen - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[65] = "Talk to Paarthurnax or Talk to Arngeir or Talk to Esbern.";
	stepVector[66] = "Talk to the Jarl of Whiterun.";
	stepVector[67] = "Get Greybeards' help in negotiating a truce.";
	stepVector[68] = "Learn Shout to call Odahviing.";
	stepVector[69] = "Prepare trap for Odahviing.";
	stepVector[70] = "Call Odahviing to Dragonsreach.";
	stepVector[71] = "Defeat and trap Odahviing.";
	stepVector[72] = "Interrogate Odahviing.";

	// Hints.
	// Talk to Paarthurnax or Talk to Arngeir or Talk to Esbern.
	hintVector[258] = "Wait around for Paarthurnax to talk to you and give you the \"Talk to the Jarl of Whiterun\" objective, then optionally go talk to Arngeir at High Hrothgar and/or Esbern at Sky Haven Temple.";
	hintVector[259] = "They'll tell you pretty much the same thing that Paarthurnax did, though note that talking to Esbern is required if you want to get the optional \"Paarthurnax\" quest.";
	// Talk to the Jarl of Whiterun.
	hintVector[260] = "Travel to Dragonsreach and talk to the Jarl about trapping a dragon in his palace.";
	hintVector[261] = "Keep talking to him about it until you get the \"Get Greybeards\' help in negotiating a truce\" objective. (Note that you\'ll skip that objective if you\'ve done enough Civil War Quests to nearly or completely defeat one of the two sides.)";
	// Get Greybeards' help in negotiating a truce.
	hintVector[262] = "There's nothing to do on this objective separate from the \"Season Unending\" quest.";
	// Learn Shout to call Odahviing.
	hintVector[263] = "You can learn the shout you need from either Esbern or Paarthurnax (if you haven't killed him yet).";
	hintVector[264] = "If you did the negotiations at High Hrothgar, all you have to do is wait until Esbern talks to you and gives you the Call Dragon shout.";
	hintVector[265] = "Otherwise, go talk to him at Sky Haven Temple, or talk to Paarthurnax (if he's still alive) at the Throat of the World.";
	// Prepare trap for Odahviing.
	hintVector[266] = "Return to Dragonsreach and talk to the Jarl again.";
	hintVector[267] = "Ask if he's ready to trap the dragon, then say you're ready to get the next objective.";
	// Call Odahviing to Dragonsreach.
	hintVector[268] = "Follow the Jarl out to the Great Porch area, then get the Call Dragon shout ready to use.";
	hintVector[269] = "Move to the end of the porch and hit the Shout key, then switch to the Dragonrend shout and wait for the next objective.";
	// Defeat and trap Odahviing.
	hintVector[270] = "Wait and watch for Odahviing, ready to hit him with the Dragonrend shout as soon as you can. (It's easiest to wait until he's hovering nearby and flaming a guard.)";
	hintVector[271] = "Right after you successfully rend him, turn and sprint for the door that leads back into Dragonsreach.";
	hintVector[272] = "Don't go through the door -- just stand and wait for Odahviing to be trapped.";
	// Interrogate Odahviing.
	hintVector[273] = "Move up to Odahviing and talk to him until you get the \"The World - Eater's Eyrie\" quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Paarthurnax - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[73] = "Kill Paarthurnax.";
	stepVector[74] = "Talk to Delphine.";

	// Hints.
	// Kill Paarthurnax.
	hintVector[274] = "NOTE: Killing their revered leader will greatly annoy the Greybeards at High Hrothgar. They won't turn hostile to you, but they'll want nothing to do with you anymore.";
	hintVector[275] = "Travel back to the Throat of the World, then go over to where Paarthurnax is sitting.";
	hintVector[276] = "You're going to fight him pretty much like you did Alduin. Hit him with Dragonrend frequently to prevent him from flying around while either pelting him with arrows and spells or whacking him with a powerful melee weapon. Again, having a follower, a summoned creature, and some serious fire resistance and healing items is advised.";
	// Talk to Delphine.
	hintVector[277] = "Return to Sky Haven Temple and talk to Delphine to finish the quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Season Unending - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[75] = "Talk to Arngeir.";
	stepVector[76] = "Talk to Ulfric Stormcloak. ";
	stepVector[77] = "Talk to General Tullius.";
	stepVector[78] = "Talk to Arngeir.";
	stepVector[79] = "Take your seat.";
	stepVector[80] = "Negotiate a truce.";

	// Hints.
	// Talk to Arngeir.
	hintVector[278] = "Return to High Hrothgar and find Arngeir in the monastery.";
	hintVector[279] = "After he chews you out for killing Paarthurnax (if you did), talk to him and say you need his help to stop the war.";
	hintVector[280] = "That'll get you the next two objectives, which you can do in either order.";
	// Talk to Ulfric Stormcloak. 
	hintVector[281] = "Travel to Windhelm (by carriage if you've never been there before), then go to its north end and enter the Palace of the Kings.";
	hintVector[282] = "Talk to Ulfric Stormcloak and tell him you have a message from the Greybeards.";
	hintVector[283] = "Keep talking to him until he agrees to go to High Hrothgar for the negotiations.";
	// Talk to General Tullius.
	hintVector[284] = "Return to Solitude and follow the winding street around until you reach Castle Dour.";
	hintVector[285] = "Go through the guarded door that's unlocked, then move forward to find General Tullius in his war room.";
	hintVector[286] = "Talk to him (more than once if necessary) until you can tell him you have a message from the Greybeards.";
	hintVector[287] = "Keep talking to him until he agrees to go to High Hrothgar for the negotiations.";
	// Talk to Arngeir.
	hintVector[288] = "Return to High Hrothgar and talk to Arngeir to get the next objective.";
	// Take your seat.
	hintVector[289] = "Go east and around to the Great Hall, then sit on the chair that's at the south end of the round table. The next objective will start soon after you do that.";
	// Negotiate a truce.
	hintVector[290] = "During the long and tedious negotiations, you'll be called upon every now and then to make some sort of decision.";
	hintVector[291] = "Each decision you make will necessarily favor one side (Imperials or Stormcloaks) over the other. You can support whoever you want to, but it would make the most sense to stick with the side you've already been supporting if you've been doing the Civil War Quests. If you haven't, and don't plan to later on, it doesn't matter which side you choose.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The World-Eater's Eyrie - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[81] = "Set Odahviing free.";
	stepVector[82] = "Talk to Odahviing.";
	stepVector[83] = "Reach Alduin's portal to Sovngarde.";
	stepVector[84] = "Enter Sovngarde.";

	// Hints.
	// Set Odahviing free.
	hintVector[292] = "Go up either set of stairs near the door that leads back into Dragonsreach to find a guard near a pull chain.";
	hintVector[293] = "Either talk to the guard about opening the trap, or just use the pull chain yourself.";
	// Talk to Odahviing.
	hintVector[294] = "Follow Odahviing to the end of the porch, then talk to him and tell him you're ready to go to Skuldafn. (Note that after you go, you can't fast-travel back. You'll be committed to finishing the main quest series.)";
	// Reach Alduin's portal to Sovngarde.
	hintVector[295] = "After Odahviing takes off, get out your bow and see if you can sneak-attack any of the draugr that are wandering around the structures on the other side of the water. If you can't see any, fire some arrows over there in various spots to lure some into the open.";
	hintVector[296] = "After you kill several draugr or use the bridge to cross the water, a dragon will swoop down on you. It's best to use your shouts, weapons, etc. to kill it on your side of the water, then cross the bridge.";
	hintVector[297] = "Turn right past the bridge and watch for draugr as you move south. When you get near the Skudafn South Tower, another dragon will swoop down and attack. You can retreat into the tower for a break, but you'll have to fight several draugr inside.";
	hintVector[298] = "After the dragon is dealt with, go up the steps to the east and past a ruined tower, then turn north and go up some stairs to find a door that leads into the Skuldafn Temple. There will, of course, be several draugr to fight on the way.";
	hintVector[299] = "You'll need to make your way through two identically-named temple areas in order to reach the outdoor area with Alduin's portal.";
	hintVector[300] = "After you exit the second temple area, kill any nearby draugr, then turn left and go around to where you can climb some steps to reach the portal area.";
	// Enter Sovngarde.
	hintVector[301] = "Crouch down and sneak-attack the dragon priest named Nahkriin from a distance as much as possible before he starts attacking back.";
	hintVector[302] = "He's a very powerful mage, and you'll want to stay back and dodge as many of his spells as you can if your magic resistance is low.";
	hintVector[303] = "TIP: Even though he appears to be levitating, he'll still fall and take lots of damage if you knock him off the side of the temple.";
	hintVector[304] = "NOTE: There are two dragons perched nearby, but they probably won't join the battle unless you attack them. They didn't when I played, anyway.";
	hintVector[305] = "Loot Nahkriin to get his dragon priest staff, then go up to where he was using it earlier.";
	hintVector[306] = "Activate the dragon seal to place the staff and open the portal to Sovngarde, then jump into it to get the next quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Sovngarde - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[85] = "Find out how to defeat Alduin.";
	stepVector[86] = "Gain admittance to the Hall of Valor.";
	stepVector[87] = "Talk to the heroes of Sovngarde.";

	// Hints.
	// Find out how to defeat Alduin.
	hintVector[307] = "Go down the stone steps and along the path until you meet a Stormcloak soldier, then talk to him to get the next objective.";
	// Gain admittance to the Hall of Valor.
	hintVector[308] = "Continue down the path until it splits, then go either way to reach the large bony bridge that leads to the Hall of Valor.";
	hintVector[309] = "As you approach the bridge, a warrior named Tsun will talk to you. After a brief conversation, he'll require you to prove yourself in battle against him.";
	hintVector[310] = "Use all your best weapons, shouts, spells, etc. on him until he puts his weapon away. Do the same, then wait if necessary to get the next objective.";
	// Talk to the heroes of Sovngarde.
	hintVector[311] = "Carefully cross the bone bridge, then approach the Hall of Valor and use one of its doors to go inside.";
	hintVector[312] = "After Ysgramor talks to you, look around the hall for the three dead heroes that he mentioned.";
	hintVector[313] = "You'll find them all standing together near the NE corner of the central hall area.";
	hintVector[314] = "Go over to them and wait while they talk, after which you'll get the final main quest.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Dragonslayer - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[89] = "Help the heroes of Sovngarde dispel Alduin's mist.";
	stepVector[90] = "Defeat Alduin.";

	// Hints.
	// Help the heroes of Sovngarde dispel Alduin's mist.
	hintVector[315] = "Exit the Hall of Valor, then follow the heroes across the bone bridge.";
	hintVector[316] = "When they stop, move up next to them and get the Clear Skies shout ready.";
	hintVector[317] = "After one of them mentions that shout, fire it off, then wait as they do the same. ";
	hintVector[318] = "When one of them says \"again, \" use the shout again.";
	hintVector[319] = "Wait until they say to use the shout again, then do so and wait to get the next objective.";
	// Defeat Alduin.
	hintVector[320] = "Get the Dragonrend shout ready, then hit Alduin with it as soon as you can.";
	hintVector[321] = "Run over to a spot near where he lands so you can keep hitting him with Dragonrend every now and then to keep him on the ground and vulnerable.";
	hintVector[322] = "As for actually dealing him damage, the three heroes and other souls nearby can take care of that for you. Stay back and use arrows or long-range spells if you want to, but don't let Alduin get you, and don't forget about using Dragonrend.";
	hintVector[323] = "When Alduin's health reaches zero, he'll be utterly destroyed. 'Bout time!";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// MAIN QUESTS ENDS HERE.

	// SIDE QUESTS STARTS HERE.
	// Side Quests (22 | 19 - 40).
	questVector[19].setQuestName("The Blessings of Nature ");
	questVector[19].setQuestDescription("To get this quest, ask Danica Pure-Spring in Whiterun's Temple of Kynareth about the temple and the Gildergreen Tree.");
	questVector[20].setQuestName("Blood on the Ice");
	questVector[21].setQuestName("The Book of Love");
	questVector[21].setQuestDescription("To get this quest, talk to Dinya Balu in Riften's Temple of Mara.");
	questVector[22].setQuestName("Delayed Burial");
	questVector[23].setQuestName("Forbidden Legend");
	questVector[23].setQuestDescription("The easiest way to get this quest is to read a copy of the \"Lost Legends\" book.There's one under a flagon on one of the bookshelves in Farengar Secret-Fire's small study room in Dragonsreach.");
	questVector[24].setQuestName("The Forsworn Conspiracy");
	questVector[25].setQuestName("The Golden Claw ");
	questVector[26].setQuestName("The Heart of Dibella");
	questVector[27].setQuestName("In My Time of Need");
	questVector[27].setQuestDescription("When you return to Whiterun after finishing the \"Dragon Rising\" Main Quest, there should be two Alik'r guys talking to a city guard. If not, look for them to be there on a later visit. Talk to one of them to get this quest.");
	questVector[28].setQuestName("Kyne's Sacred Trials");
	questVector[28].setQuestDescription("Travel to Froki's Shack (see the Riften section of the World Map Exploration Guide) and talk to Froki Whetted-Blade to get this quest. (Note that you can do the first three objectives in any order.)");
	questVector[29].setQuestName("Laid to Rest");
	questVector[29].setQuestDescription("To get this quest, go to Morthal and ask Jonna in the inn about the burned - down house.");
	questVector[30].setQuestName("Lights Out!");
	questVector[30].setQuestDescription("To get this quest, go to Solitude and talk to Jaree-Ra, who's usually hanging around outside the Angeline's Aromatics store.");
	questVector[31].setQuestName("The Man Who Cried Wolf");
	questVector[31].setQuestDescription("The first time you enter Solitude's Blue Palace, someone will complain to the Jarl about Wolfskull Cave. Anytime after that, talk to Falk Firebeard about the cave to get this quest.");
	questVector[32].setQuestName("Missing in Action ");
	questVector[32].setQuestDescription("Enter and exit Whiterun's inn sometime during the day to get Fralia Gray-Mane to appear near a merchant stall and argue with a couple of guys. Anytime after the argument is over, talk to Fralia to get this quest.");
	questVector[33].setQuestName("No One Escapes Cidhna Mine");
	questVector[33].setQuestDescription("After you finish the \"The Forsworn Conspiracy\" quest by surrendering to a city guard, you'll get this quest.");
	questVector[34].setQuestName("Promises to Keep");
	questVector[34].setQuestDescription("Talk to Louis Letrush in Riften's inn to get this quest.");
	questVector[35].setQuestName("Repairing the Phial");
	questVector[35].setQuestDescription("At some point after finishing both the \"The White Phial\" side quest and the \"The Throat of the World\" Main Quest, a courier will approach you in a city and give you a letter from Quintus Navale.Read it to start this quest.");
	questVector[36].setQuestName("Rise in the East");
	questVector[36].setQuestDescription("To get this quest, go to Windhelm's docks (just east of the city) during the day and talk to Orthus Endario in the East Empire Company building.");
	questVector[37].setQuestName("Rising at Dawn");
	questVector[37].setQuestDescription("After becoming a vampire, you can get cured either by doing enough Companions faction quests to become a werewolf, or by doing this quest.To get it, talk to any innkeeper about rumors until you hear about Falion.");
	questVector[38].setQuestName("Unfathomable Depths");
	questVector[39].setQuestName("The White Phial");
	questVector[39].setQuestDescription("To get this quest, enter the White Phial shop near Windhelm's SW corner and ask Nurelion what he's arguing about.");
	questVector[40].setQuestName("The Wolf Queen Awakened");
	questVector[40].setQuestDescription("After you finish the \"The Man Who Cried Wolf\" quest and get to level 10 or higher, fast-travel around the major cities until a courier gives you a letter from Falk Firebeard. Go to the Blue Palace and talk to him about Wolfskull Cave to get this quest.");

	// The Blessings of Nature - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[91] = "Retrieve Nettlebane.";
	stepVector[92] = "Bring Nettlebane to Danica.";
	stepVector[93] = "Retrieve Eldergleam sap.";
	stepVector[94] = "Follow Maurice.";
	stepVector[95] = "Take sapling.";
	stepVector[96] = "Return to Danica.";

	// Hints.
	// Retrieve Nettlebane.
	hintVector[324] = "";
	hintVector[325] = "";
	hintVector[326] = "";
	hintVector[327] = "";
	// Bring Nettlebane to Danica.
	hintVector[328] = "";
	// Retrieve Eldergleam sap.
	hintVector[329] = "";
	hintVector[330] = "";
	hintVector[331] = "";
	hintVector[332] = "";
	hintVector[333] = "";
	hintVector[334] = "";
	// Follow Maurice.
	hintVector[335] = "";
	// Take sapling.
	hintVector[336] = "";
	// Return to Danica.
	hintVector[337] = "";
	hintVector[338] = "";
	hintVector[339] = "";
	hintVector[340] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Blood on the Ice - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[97] = "How can I get this quest ?";
	stepVector[98] = "Question the witnesses.";
	stepVector[99] = "Report to the guard.";
	stepVector[100] = "Talk to Jorleif.";
	stepVector[101] = "Get assistance from Jorleif.";
	stepVector[102] = "Examine the crime scene.";
	stepVector[103] = "Get access to Hjerim.";
	stepVector[104] = "Look for clues.";
	stepVector[105] = "Follow up on the clues from Hjerim.";
	stepVector[106] = "Investigate Hjerim with Viola.";
	stepVector[107] = "Talk to Jorleif.";
	stepVector[108] = "Speak to Wuunferth.";
	stepVector[109] = "Patrol the streets of the Stone Quarter at night.";
	stepVector[110] = "Catch the murderer.";
	stepVector[111] = "Talk to Jorleif.";

	// Hints.
	// How can I get this quest ?
	hintVector[341] = "";
	hintVector[342] = "";
	hintVector[343] = "";
	// Question the witnesses.
	hintVector[344] = "";
	// Report to the guard.
	hintVector[345] = "";
	// Talk to Jorleif.
	hintVector[346] = "";
	// Get assistance from Jorleif.
	hintVector[347] = "";
	// Examine the crime scene.
	hintVector[348] = "";
	hintVector[349] = "";
	hintVector[350] = "";
	hintVector[351] = "";
	hintVector[352] = "";
	hintVector[353] = "";
	// Get access to Hjerim.
	hintVector[354] = "";
	hintVector[355] = "";
	hintVector[356] = "";
	hintVector[357] = "";
	hintVector[358] = "";
	hintVector[359] = "";
	// Look for clues.
	hintVector[360] = "";
	hintVector[361] = "";
	// Follow up on the clues from Hjerim.
	hintVector[362] = "";
	hintVector[363] = "";
	hintVector[364] = "";
	hintVector[365] = "";
	hintVector[366] = "";
	hintVector[367] = "";
	hintVector[368] = "";
	// Investigate Hjerim with Viola.
	hintVector[369] = "";
	hintVector[370] = "";
	hintVector[371] = "";
	hintVector[372] = "";
	hintVector[373] = "";
	// Talk to Jorleif.
	hintVector[374] = "";
	hintVector[375] = "";
	hintVector[376] = "";
	hintVector[377] = "";
	// Speak to Wuunferth.
	hintVector[378] = "";
	hintVector[379] = "";
	hintVector[380] = "";
	// Patrol the streets of the Stone Quarter at night.
	hintVector[381] = "";
	hintVector[382] = "";
	hintVector[383] = "";
	// Catch the murderer.
	hintVector[384] = "";
	hintVector[385] = "";
	// Talk to Jorleif.
	hintVector[386] = "";
	hintVector[387] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Book of Love - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[112] = "Talk to Fastred.";
	stepVector[113] = "Talk to Fastred's parents.";
	stepVector[114] = "Talk to Bassianus or Klimmek.";
	stepVector[115] = "Return to Dinya Balu.";
	stepVector[116] = "Talk to Calcemo.";
	stepVector[117] = "Get advice from Yngvar.";
	stepVector[118] = "Deliver poem.";
	stepVector[119] = "Deliver Faleen's letter.";
	stepVector[120] = "Return to Dinya Balu.";
	stepVector[121] = "Put on the Amulet of Mara.";
	stepVector[122] = "Talk to the long - dead lover.";
	stepVector[123] = "Find Fenrig.";
	stepVector[124] = "Bring Fenrig to Ruki.";
	stepVector[125] = "Return to Dinya Balu.";

	// Hints.
	// Talk to Fastred.
	hintVector[388] = "";
	hintVector[389] = "";
	// Talk to Fastred's parents.
	hintVector[390] = "";
	// Talk to Bassianus or Klimmek.
	hintVector[391] = "";
	hintVector[392] = "";
	hintVector[393] = "";
	hintVector[394] = "";
	// Return to Dinya Balu.
	hintVector[395] = "";
	// Talk to Calcemo.
	hintVector[396] = "";
	hintVector[397] = "";
	hintVector[398] = "";
	// Get advice from Yngvar.
	hintVector[399] = "";
	hintVector[400] = "";
	// Deliver poem.
	hintVector[401] = "";
	hintVector[402] = "";
	// Deliver Faleen's letter.
	hintVector[403] = "";
	hintVector[404] = "";
	// Return to Dinya Balu.
	hintVector[405] = "";
	// Put on the Amulet of Mara.
	hintVector[406] = "";
	// Talk to the long - dead lover.
	hintVector[407] = "";
	hintVector[408] = "";
	// Find Fenrig.
	hintVector[409] = "";
	hintVector[410] = "";
	// Bring Fenrig to Ruki.
	hintVector[411] = "";
	hintVector[412] = "";
	// Return to Dinya Balu.
	hintVector[413] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Delayed Burial - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[126] = "No Steps - Select this for hints.";

	// Hints.
	hintVector[414] = "NOTE: You can't get this quest if you've already finished the \"With Friends Like These...\" Dark Brotherhood faction quest.";
	hintVector[415] = "Check the paved path that's just east of the Loreius Farm (a ways NE of Whiterun) to find a jester named Cicero and his broken-down cart. You can either talk to him or to Vantus Loreius at the farm to start this quest.";
	hintVector[416] = "Talk to Vantus Loreius if you haven't already to learn your two options, then decide which one you want to use.";
	hintVector[417] = "If you'd rather get Cicero the help he needs, talk to Vantus Loreius again and pass a persuade check. After that, you can talk to Cicero to finish the quest and get some gold.";
	hintVector[418] = "If you can't or don't want to do that, go back down to the path and wait near Cicero's wagon for a patrolling guard to walk by.";
	hintVector[419] = "Talk to him and say you'd like to report a crime, then mention Cicero and pass any of the persuade checks listed. After that, you can talk to Vantus Loreius to finish the quest and get some gold.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Forbidden Legend - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[127] = "Investigate the Gauldur legend.";
	stepVector[128] = "Learn the truth from Daynas Valen.";
	stepVector[129] = "Read Daynas Valen's notes.";
	stepVector[130] = "Find the Gauldur Amulet Fragment in Folgunthur.";
	stepVector[131] = "Find the Gauldur Amulet Fragment in Geirmund's Hall.";
	stepVector[132] = "Find the Gauldur Amulet Fragment in Saarthal.";
	stepVector[133] = "Reforge the Gauldur Amulet.";
	stepVector[134] = "Take the Gauldur Amulet.";

	// Hints.
	// Investigate the Gauldur legend.
	hintVector[420] = "";
	hintVector[421] = "";
	// Learn the truth from Daynas Valen.
	hintVector[422] = "";
	hintVector[423] = "";
	hintVector[424] = "";
	hintVector[425] = "";
	hintVector[426] = "";
	hintVector[427] = "";
	// Read Daynas Valen's notes.
	hintVector[428] = "";
	// Find the Gauldur Amulet Fragment in Folgunthur.
	hintVector[429] = "";
	hintVector[430] = "";
	hintVector[431] = "";
	hintVector[432] = "";
	hintVector[433] = "";
	hintVector[434] = "";
	hintVector[435] = "";
	hintVector[436] = "";
	// Find the Gauldur Amulet Fragment in Geirmund's Hall.
	hintVector[437] = "";
	hintVector[438] = "";
	hintVector[439] = "";
	hintVector[440] = "";
	hintVector[441] = "";
	hintVector[442] = "";
	hintVector[443] = "";
	hintVector[444] = "";
	hintVector[445] = "";
	hintVector[446] = "";
	// Find the Gauldur Amulet Fragment in Saarthal.
	hintVector[447] = "";
	// Reforge the Gauldur Amulet.
	hintVector[448] = "";
	hintVector[449] = "";
	hintVector[450] = "";
	hintVector[451] = "";
	hintVector[452] = "";
	hintVector[453] = "";
	// Take the Gauldur Amulet.
	hintVector[454] = "";
	hintVector[455] = "";
	hintVector[456] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Forsworn Conspiracy - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[135] = "How can I get this quest ?";
	stepVector[136] = "Go to the Shrine of Talos.";
	stepVector[137] = "Find evidence about Margret.";
	stepVector[138] = "(Optional)Obtain the key to Margret's room. ";
	stepVector[139] = "(Optional)Talk to Margret.";
	stepVector[140] = "Read Margret's Journal.";
	stepVector[141] = "Find evidence about Thonar.";
	stepVector[142] = "Read Thonar's Journal.";
	stepVector[143] = "Find evidence about Weylin.";
	stepVector[144] = "Read Weylin's Note.";
	stepVector[145] = "Find out who \"N\" is.";
	stepVector[146] = "Find evidence about Nepos.";
	stepVector[147] = "Read Nepos's Journal.";

	// Hints.
	// How can I get this quest ?
	hintVector[457] = "";
	hintVector[458] = "";
	hintVector[459] = "";
	hintVector[460] = "";
	// Go to the Shrine of Talos.
	hintVector[461] = "";
	hintVector[462] = "";
	hintVector[463] = "";
	// Find evidence about Margret.
	hintVector[464] = "";
	hintVector[465] = "";
	hintVector[466] = "";
	hintVector[467] = "";
	hintVector[468] = "";
	// (Optional)Obtain the key to Margret's room. 
	hintVector[469] = "";
	hintVector[470] = "";
	hintVector[471] = "";
	// (Optional)Talk to Margret.
	hintVector[472] = "";
	hintVector[473] = "";
	hintVector[474] = "";
	// Read Margret's Journal. 
	hintVector[475] = "";
	// Find evidence about Thonar.
	hintVector[476] = "";
	hintVector[477] = "";
	hintVector[478] = "";
	hintVector[479] = "";
	hintVector[480] = "";
	hintVector[481] = "";
	hintVector[482] = "";
	hintVector[483] = "";
	// Read Thonar's Journal. 
	hintVector[484] = "";
	// Find evidence about Weylin.
	hintVector[485] = "";
	hintVector[486] = "";
	hintVector[487] = "";
	hintVector[488] = "";
	// Read Weylin's Note. 
	hintVector[489] = "";
	// Find out who "N" is.
	hintVector[490] = "";
	hintVector[491] = "";
	hintVector[492] = "";
	hintVector[493] = "";
	// Find evidence about Nepos.
	hintVector[494] = "";
	hintVector[495] = "";
	hintVector[496] = "";
	hintVector[497] = "";
	hintVector[498] = "";
	hintVector[499] = "";
	hintVector[500] = "";
	hintVector[501] = "";
	// Read Nepos's Journal.
	hintVector[502] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Golden Claw - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[148] = "No Steps - Select this for hints.";

	// Hints.
	hintVector[503] = "Talk to Lucan Valerius in Riverwood's trader shop to get this quest.";
	hintVector[504] = "You can then optionally follow Camilla Valerius to the bridge that leads out of town, though it's easy enough to find the bridge yourself.";
	hintVector[505] = "The Golden Claw is obtained and used on the third Main Quest. After you finish it, return to the Riverwood Trader and talk to Lucan to get your reward.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Heart of Dibella - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[149] = "How can I get this quest ?";
	stepVector[150] = "Find the future Sybil of Dibella.";
	stepVector[151] = "Rescue Fjotra from the Forsworn.";
	stepVector[152] = "Bring Fjotra to the Temple.";
	stepVector[153] = "Pray at Dibella's Altar.";

	// Hints.
	// How can I get this quest ?
	hintVector[506] = "";
	hintVector[507] = "";
	hintVector[508] = "";
	hintVector[509] = "";
	hintVector[510] = "";
	// Find the future Sybil of Dibella.
	hintVector[511] = "";
	hintVector[512] = "";
	hintVector[513] = "";
	hintVector[514] = "";
	// Rescue Fjotra from the Forsworn.
	hintVector[515] = "";
	hintVector[516] = "";
	hintVector[517] = "";
	hintVector[518] = "";
	hintVector[519] = "";
	hintVector[520] = "";
	hintVector[521] = "";
	hintVector[522] = "";
	hintVector[523] = "";
	// Bring Fjotra to the Temple.
	hintVector[524] = "";
	hintVector[525] = "";
	hintVector[526] = "";
	// Pray at Dibella's Altar.
	hintVector[527] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// In My Time of Need - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[154] = "Find the Redguard woman.";
	stepVector[154] = "Speak with Saadia or Inform the Alik'r of Saadia's location.";
	stepVector[154] = "Talk to the Alik'r prisoner or Inform the Alik'r of Saadia's location.";
	stepVector[154] = "Kill Kematu.";
	stepVector[154] = "Kill Kematu or talk to him.";
	stepVector[154] = "Return to Saadia.";
	stepVector[154] = "Lead Saadia to the Whiterun Stables.";
	stepVector[154] = "Speak with Saadia.";

	// Hints.
	// Find the Redguard woman.
	hintVector[528] = "";
	hintVector[529] = "";
	hintVector[530] = "";
	// Speak with Saadia or Inform the Alik'r of Saadia's location.
	hintVector[531] = "";
	hintVector[532] = "";
	// Talk to the Alik'r prisoner or Inform the Alik'r of Saadia's location.
	hintVector[533] = "";
	hintVector[534] = "";
	hintVector[535] = "";
	hintVector[536] = "";
	hintVector[537] = "";
	// Kill Kematu.
	hintVector[538] = "";
	hintVector[539] = "";
	hintVector[540] = "";
	hintVector[541] = "";
	hintVector[542] = "";
	hintVector[543] = "";
	// Kill Kematu or talk to him.
	hintVector[544] = "";
	hintVector[545] = "";
	hintVector[546] = "";
	hintVector[547] = "";
	hintVector[548] = "";
	hintVector[549] = "";
	// Return to Saadia.
	hintVector[550] = "";
	// Lead Saadia to the Whiterun Stables.
	hintVector[551] = "";
	hintVector[552] = "";
	hintVector[553] = "";
	hintVector[554] = "";
	// Speak with Saadia.
	hintVector[555] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Kyne's Sacred Trials  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[155] = "Defeat the Guardian Mudcrab.";
	stepVector[156] = "Defeat the Guardian Skeever.";
	stepVector[157] = "Defeat the Guardian Wolf.";
	stepVector[158] = "Return to Froki.";
	stepVector[159] = "Defeat the Guardian Bear.";
	stepVector[160] = "Defeat the Guardian Mammoth.";
	stepVector[161] = "Defeat the Guardian Sabre Cat.";
	stepVector[162] = "Return to Froki.";
	stepVector[163] = "Defeat the Guardian Troll.";
	stepVector[164] = "Return to Froki.";

	// Hints. 
	// Defeat the Guardian Mudcrab.
	hintVector[556] = "";
	hintVector[557] = "";
	// Defeat the Guardian Skeever.
	hintVector[558] = "";
	hintVector[559] = "";
	// Defeat the Guardian Wolf.
	hintVector[560] = "";
	hintVector[561] = "";
	// Return to Froki.
	hintVector[562] = "";
	// Defeat the Guardian Bear.
	hintVector[563] = "";
	hintVector[564] = "";
	hintVector[565] = "";
	// Defeat the Guardian Mammoth.
	hintVector[566] = "";
	hintVector[567] = "";
	hintVector[568] = "";
	// Defeat the Guardian Sabre Cat.
	hintVector[569] = "";
	hintVector[570] = "";
	hintVector[571] = "";
	// Return to Froki.
	hintVector[572] = "";
	// Defeat the Guardian Troll.
	hintVector[573] = "";
	hintVector[574] = "";
	hintVector[575] = "";
	hintVector[576] = "";
	hintVector[577] = "";
	hintVector[578] = "";
	// Return to Froki.
	hintVector[579] = "";
	hintVector[580] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Laid to Rest - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[165] = "Talk to the Jarl.";
	stepVector[166] = "Investigate the burned house.";
	stepVector[167] = "Find Helgi after dark.";
	stepVector[168] = "Ask Thonnir about Laelette.";
	stepVector[169] = "Investigate Alva's house.";
	stepVector[170] = "Show Alva's Journal to the Jarl.";
	stepVector[171] = "Kill the master vampire.";
	stepVector[172] = "Return to Morthal's Jarl.";

	// Hints. 
	// Talk to the Jarl.
	hintVector[581] = "";
	// Investigate the burned house.
	hintVector[582] = "";
	hintVector[583] = "";
	// Find Helgi after dark.
	hintVector[584] = "";
	hintVector[585] = "";
	hintVector[586] = "";
	hintVector[587] = "";
	// Ask Thonnir about Laelette.
	hintVector[588] = "";
	// Investigate Alva's house.
	hintVector[589] = "";
	hintVector[590] = "";
	hintVector[591] = "";
	hintVector[592] = "";
	hintVector[593] = "";
	hintVector[594] = "";
	// Show Alva's Journal to the Jarl.
	hintVector[595] = "";
	// Kill the master vampire.
	hintVector[596] = "";
	hintVector[597] = "";
	hintVector[598] = "";
	hintVector[599] = "";
	hintVector[600] = "";
	hintVector[601] = "";
	hintVector[602] = "";
	hintVector[603] = "";
	// Return to Morthal's Jarl.
	hintVector[604] = "";
	hintVector[605] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Lights Out! - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[173] = "Put out the fire in the Solitude Lighthouse.";
	stepVector[174] = "Return to Jaree - Ra.";
	stepVector[175] = "Find Deeja at the Wreck of the Icerunner.";
	stepVector[176] = "Defeat Deeja.";
	stepVector[177] = "Find out where Jaree - Ra's bandits took the loot.";
	stepVector[178] = "Travel to Broken Oar Grotto.";
	stepVector[179] = "Defeat Jaree - Ra.";

	// Hints. 
	// Put out the fire in the Solitude Lighthouse.
	hintVector[606] = "";
	hintVector[607] = "";
	hintVector[608] = "";
	// Return to Jaree - Ra.
	hintVector[609] = "";
	hintVector[610] = "";
	// Find Deeja at the Wreck of the Icerunner.
	hintVector[611] = "";
	hintVector[612] = "";
	hintVector[613] = "";
	hintVector[614] = "";
	hintVector[615] = "";
	// Defeat Deeja.
	hintVector[616] = "";
	hintVector[617] = "";
	// Find out where Jaree - Ra's bandits took the loot.
	hintVector[618] = "";
	hintVector[619] = "";
	// Travel to Broken Oar Grotto.
	hintVector[620] = "";
	hintVector[621] = "";
	hintVector[622] = "";
	// Defeat Jaree - Ra.
	hintVector[623] = "";
	hintVector[624] = "";
	hintVector[625] = "";
	hintVector[626] = "";
	hintVector[627] = "";
	hintVector[628] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Man Who Cried Wolf - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[180] = "";
	stepVector[181] = "";

	// Hints. 
	// Clear out Wolfskull Cave.
	hintVector[629] = "";
	hintVector[630] = "";
	hintVector[631] = "";
	hintVector[632] = "";
	hintVector[633] = "";
	hintVector[634] = "";
	hintVector[635] = "";
	hintVector[636] = "";
	hintVector[637] = "";
	// Speak to Falk Firebeard.
	hintVector[638] = "";
	hintVector[639] = "";
	hintVector[640] = "";
	hintVector[641] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	
	// Missing in Action - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[182] = "Meet Fralia in her home.";
	stepVector[183] = "Find evidence of Thorald's fate.";
	stepVector[184] = "Deliver proof to Avulstein.";
	stepVector[185] = "Find a way to release Thorald from Thalmor custody.";
	stepVector[186] = "Meet Avulstein at Northwatch Keep.";
	stepVector[187] = "Rescue Thorald from Northwatch Keep.";
	stepVector[188] = "Lead Thorald to safety.";
	stepVector[189] = "Speak to Thorald Gray-Mane.";
	stepVector[190] = "Return to Fralia Gray-Mane.";

	// Hints.
	// Meet Fralia in her home.
	hintVector[642] = "Follow Fralia into House Gray-Mane, then wait until Avulstein Gray-Mane talks to you and gives you the next objective.";
	// Find evidence of Thorald's fate.
	hintVector[643] = "There are three ways to get the information you need.";
	hintVector[644] = "One way is to find it inside the House of Clan Battle-Born.";
	hintVector[645] = "Another way is to find Idolaf Battle-Born and persuade him to tell you where Thorald is. That requires you to pass a fairly tough persuade dialogue option.";
	hintVector[646] = "If you can't do either of those ways, find Jon Battle-Born and convince him to help you.";
	// Deliver proof to Avulstein.
	hintVector[647] = "Return to House Gray-Mane and talk to Avulstein about the proof you found.";
	hintVector[648] = "You can then say you'll join him in the assault on Northwatch Keep, or you can tell him to stay hidden.";
	hintVector[649] = "If you join the assault, you'll get the \"Meet Avulstein at Northwatch Keep\" objective. Otherwise, you'll get the \"Find a way to release Thorald from Thalmor custody\" objective.";
	// Find a way to release Thorald from Thalmor custody.
	hintVector[650] = "Rescuing Thorald without Avulstein's help works pretty much like it does in the \"Rescue Thorald from Northwatch Keep\" objective, with the exceptions that you won't have any combat support (unless you bring a follower) and sneaking around unseen will be a lot easier.";
	hintVector[651] = "Using stealth to enter the keep unseen is very difficult, even if you have the Muffle spell and Invisibility potions. Besides, you'll need all of the outdoor guards to be dead when you exit the keep with Thorald later.";
	hintVector[652] = "Bring a tough, well-equipped follower, and use sneaky ranged attacks and summoned creatures to help you kill off all of the keep's exterior guards. After that, enter the keep through its unlocked door and make your way through it as outlined in the above-mentioned objective.";
	// Meet Avulstein at Northwatch Keep.
	hintVector[653] = "Look for Avulstein and his men behind a large rock a short way east of the keep's entrance.";
	hintVector[654] = "Talk to Avulstein to get the next objective.";
	// Rescue Thorald from Northwatch Keep.
	hintVector[655] = "Lead Avulstein and the boys over to a spot near the keep's entrance, then stay back and use ranged attacks as they move in on the Northwatch guards.";
	hintVector[657] = "There are a lot of well-armed guards, and your group can be very easily overwhelmed. Try to lead any guard who comes after you away from the keep so they won't all get after you at once.";
	hintVector[658] = "At least Avulstein is unkillable, so he'll keep on being helpful -- when he's not temporarily disabled, anyway. After all of the guards are killed, enter the keep through its unlocked door.";
	hintVector[659] = "Crouch down and sneak down the steps in the first room so you can get the drop on the guard and mage in the second room, then go through a wooden door and sneak over to where you can ambush an archer who's at the bottom of some more steps.";
	hintVector[700] = "Sneak down the steps and try to sneak-attack the two guards in the next room. On past that, you'll find two more guards and a mage in a large two-floor room. (Note that the mage starts behind a door on the lower floor.)";
	hintVector[701] = "Use the passage on the upper floor of that room to move on to an area with a seated guard on the right and the Northwatch interrogator in a side room on the left. Try to sneak-attack both of them, then follow Avulstein as he walks up to Thorald.";
	hintVector[702] = "After he talks to Thorald, do so yourself to get the next objective.";
	// Lead Thorald to safety.
	hintVector[703] = "Wait for Thorald to free himself from his shackles and pick up a nearby weapon, then lead him out of the keep.";
	hintVector[704] = "You could retrace your steps and leave the keep the same way you entered it, but there is a shortcut exit available if you don't mind fighting two more guards.";
	hintVector[705] = "Leave the interrogator's room and go across to where there was a seated guard earlier.";
	hintVector[706] = "Open the nearby door, then sneak-attack the two guards in the area beyond. (Or sneak up to where you can use the two levers on the left to release some prisoners as a distraction.)";
	hintVector[707] = "After they're dead, go past them to find a locked door that leads outside.";
	hintVector[708] = "If you can't pick the lock, go back and loot the interrogator's body to get the key.";
	hintVector[709] = "You'll get the next objective when you exit the keep.";
	// Speak to Thorald Gray-Mane.
	hintVector[710] = "Talk to Thorald to get the next objective.";
	// Return to Fralia Gray-Mane.
	hintVector[711] = "Return to Whiterun and follow the quest arrow to Fralia, then tell her that Thorald is safe to finish the quest and get a random enchanted steel weapon.";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	
	// No One Escapes Cidhna Mine - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[191] = "Ask a prisoner about Madanach.";
	stepVector[192] = "Get past Borkul the Beast.";
	stepVector[193] = "Talk to Madanach.";
	stepVector[194] = "Hear Braig's story.";
	stepVector[195] = " Return to Madanach.";
	stepVector[196] = "Kill Grisvar the Unlucky.";
	stepVector[197] = " Return to Madanach.";
	stepVector[198] = "Follow Madanach.";
	stepVector[199] = "Kill Madanach.";
	stepVector[200] = "Search Madanach's body.";
	stepVector[201] = "Read Madanach's note.";
	stepVector[202] = "Escape Cidhna Mine.";

	// Hints.
	// Ask a prisoner about Madanach.
	hintVector[712] = "";
	hintVector[713] = "";
	// Get past Borkul the Beast.
	hintVector[714] = "";
	hintVector[715] = "";
	hintVector[716] = "";
	hintVector[717] = "";
	hintVector[718] = "";
	// Talk to Madanach.
	hintVector[719] = "";
	hintVector[720] = "";
	// Hear Braig's story.
	hintVector[721] = "";
	hintVector[722] = "";
	// Return to Madanach.
	hintVector[723] = "";
	// Kill Grisvar the Unlucky.
	hintVector[724] = "";
	hintVector[725] = "";
	hintVector[726] = "";
	hintVector[727] = "";
	hintVector[728] = "";
	// Return to Madanach.
	hintVector[729] = "";
	// Follow Madanach.
	hintVector[730] = "";
	hintVector[731] = "";
	hintVector[732] = "";
	hintVector[733] = "";
	hintVector[734] = "";
	hintVector[735] = "";
	hintVector[736] = "";
	// Kill Madanach.
	hintVector[737] = "";
	hintVector[738] = "";
	// Search Madanach's body.
	hintVector[739] = "";
	// Read Madanach's note.
	hintVector[740] = "";
	// Escape Cidhna Mine.
	hintVector[741] = "";
	hintVector[742] = "";
	hintVector[743] = "";
	hintVector[744] = "";
	hintVector[745] = "";
	hintVector[746] = "";
	hintVector[747] = "";
	hintVector[748] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Promises to Keep - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[203] = "Speak to Sibbi Black - Briar.";
	stepVector[204] = "Steal Frost's Lineage Papers.";
	stepVector[205] = "(Optional)Steal the Lodge Stash.";
	stepVector[206] = "Steal Frost.";
	stepVector[207] = "Return to Louis Letrush.";

	// Hints.
	// Speak to Sibbi Black - Briar.
	hintVector[749] = "";
	hintVector[750] = "";
	hintVector[751] = "";
	hintVector[752] = "";
	// Steal Frost's Lineage Papers.
	hintVector[753] = "";
	hintVector[754] = "";
	hintVector[755] = "";
	hintVector[756] = "";
	hintVector[757] = "";
	// (Optional)Steal the Lodge Stash.
	hintVector[758] = "";
	// Steal Frost.
	hintVector[759] = "";
	hintVector[760] = "";
	// Return to Louis Letrush.
	hintVector[761] = "";
	hintVector[762] = "";
	hintVector[763] = "";
	hintVector[764] = "";
	hintVector[765] = "";
	hintVector[766] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Repairing the Phial - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[208] = "Speak to Quintus Navale.";
	stepVector[209] = "Retrieve the Unmelting Snow.";
	stepVector[210] = "Find some Mammoth Tusk Powder.";
	stepVector[211] = "Take a Forsworn Heart.";
	stepVector[212] = "Return to Quintus Navale.";

	// Hints.
	// Speak to Quintus Navale.
	hintVector[767] = "";
	// Retrieve the Unmelting Snow.
	hintVector[768] = "";
	hintVector[769] = "";
	// Find some Mammoth Tusk Powder.
	hintVector[770] = "";
	hintVector[771] = "";
	hintVector[772] = "";
	// Take a Forsworn Heart.
	hintVector[773] = "";
	hintVector[774] = "";
	hintVector[775] = "";
	// Return to Quintus Navale.
	hintVector[776] = "";
	hintVector[777] = "";
	hintVector[778] = "";
	hintVector[779] = "";
	hintVector[780] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Rise in the East - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[213] = "Steal Suvaris Atheron's logbook.";
	stepVector[214] = "Give the logbook to Orthus.";
	stepVector[215] = "Talk to Stig Salt - Plank.";
	stepVector[216] = "Report back to Orthus.";
	stepVector[217] = "Depart for Japhet's Folly.";
	stepVector[218] = "Talk to Adelaisa.";
	stepVector[219] = "Kill Haldyn.";
	stepVector[220] = "Report back to Adelaisa.";
	stepVector[221] = "Speak to Adelaisa to return.";
	stepVector[222] = "Speak to Orthus.";

	// Hints.
	// Steal Suvaris Atheron's logbook.
	hintVector[781] = "";
	hintVector[782] = "";
	hintVector[783] = "";
	// Give the logbook to Orthus.
	hintVector[784] = "";
	// Talk to Stig Salt - Plank.
	hintVector[785] = "";
	hintVector[786] = "";
	hintVector[787] = "";
	// Report back to Orthus.
	hintVector[788] = "";
	hintVector[789] = "";
	// Depart for Japhet's Folly.
	hintVector[790] = "";
	hintVector[791] = "";
	// Talk to Adelaisa.
	hintVector[792] = "";
	// Kill Haldyn.
	hintVector[793] = "";
	hintVector[794] = "";
	hintVector[795] = "";
	hintVector[796] = "";
	hintVector[797] = "";
	hintVector[798] = "";
	hintVector[799] = "";
	// Report back to Adelaisa.
	hintVector[800] = "";
	hintVector[801] = "";
	hintVector[802] = "";
	// Speak to Adelaisa to return.
	hintVector[803] = "";
	// Speak to Orthus.
	hintVector[804] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Rising at Dawn - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[223] = "How can I become a vampire ?";
	stepVector[224] = "How do the stages of vampirism work ?";
	stepVector[225] = "Speak to Falion.";
	stepVector[226] = "Bring a filled Black Soul Gem to Morthal.";
	stepVector[227] = "Meet Falion at dawn.";
	stepVector[228] = "Speak to Falion.";
	stepVector[229] = "Wait for Falion to complete the ritual.";

	// Hints.
	// How can I become a vampire ?
	hintVector[805] = "";
	hintVector[806] = "";
	hintVector[807] = "";
	hintVector[808] = "";
	// How do the stages of vampirism work ?
	hintVector[809] = "";
	hintVector[810] = "";
	hintVector[811] = "";
	hintVector[812] = "";
	// Speak to Falion.
	hintVector[813] = "";
	hintVector[814] = "";
	// Bring a filled Black Soul Gem to Morthal.
	hintVector[815] = "";
	hintVector[816] = "";
	hintVector[817] = "";
	hintVector[818] = "";
	hintVector[819] = "";
	hintVector[820] = "";
	// Meet Falion at dawn.
	hintVector[821] = "";
	hintVector[822] = "";
	// Speak to Falion.
	hintVector[823] = "";
	// Wait for Falion to complete the ritual.
	hintVector[824] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Unfathomable Depths - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[230] = "No Steps - Select this for hints.";

	// Hints.
	hintVector[825] = "";
	hintVector[826] = "";
	hintVector[827] = "";
	hintVector[828] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The White Phial - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[231] = "Retrieve the White Phial.";
	stepVector[232] = "Bring the Phial to Nurelion.";
	stepVector[233] = "Speak to Quintus.";

	// Hints.
	// Retrieve the White Phial.
	hintVector[829] = "";
	hintVector[830] = "";
	hintVector[831] = "";
	hintVector[832] = "";
	hintVector[833] = "";
	hintVector[834] = "";
	hintVector[835] = "";
	hintVector[836] = "";
	hintVector[837] = "";
	hintVector[838] = "";
	// Bring the Phial to Nurelion.
	hintVector[839] = "";
	hintVector[840] = "";
	hintVector[841] = "";
	// Speak to Quintus.
	hintVector[842] = "";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// The Wolf Queen Awakened - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Steps.
	stepVector[233] = "Speak to Styrr.";
	stepVector[233] = "Defeat Potema.";
	stepVector[233] = "Retrieve Potema's remains.";
	stepVector[233] = "Give Potema's remains to Styrr.";
	stepVector[233] = "Return to Falk Firebeard.";

	// Hints.
	// Speak to Styrr.
	hintVector[843] = "";
	hintVector[844] = "";
	// Defeat Potema.
	hintVector[845] = "";
	hintVector[846] = "";
	hintVector[847] = "";
	hintVector[848] = "";
	// Retrieve Potema's remains.
	hintVector[849] = "";
	hintVector[850] = "";
	hintVector[851] = "";
	// Give Potema's remains to Styrr.
	hintVector[852] = "";
	hintVector[853] = "";
	hintVector[854] = "";
	hintVector[855] = "";
	// Return to Falk Firebeard.
	hintVector[856] = "test";
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// SIDE QUESTS ENDS HERE.

	// Set all the vectors to vectors in the classes.
	gameArray[0].setCategoryNameVector(categoryNameVector);
	questVector[0].setStepVector(stepVector);
	questVector[0].setAdditionalStepsVector(additionalStepsVector);
	questVector[0].setHintVector(hintVector);
	gameArray[0].setQuestVector(questVector);
}

void categoryChoices(int userCategoryChoice, vector<Quest> questVector)
{
	// Number of quests for each category.
	const int MAINNOQUESTS = 18, SIDENOQUESTS = 21;

	// Switch statement to take the user input and print the appropriate quests.
	switch (userCategoryChoice)
	{
	case MENUCHOICE1: // Main Quests.
		// Output the category name, the quests and spaces for output (this repeats until the end of the switch statement).
		cout << "Main Quests\n\nChoose a quest..\n" << endl;
		for (int i = 0; i <= MAINNOQUESTS; i++)
		{
			cout << i + 1 << ". " << questVector[i].getQuestName() << endl;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		break;
	case MENUCHOICE2: // Side Quests.
		int currentQuest = 19;
		cout << "Side Quests\n\nChoose a quest..\n" << endl;
		for (int i = 0; i <= SIDENOQUESTS; i++)
		{
			cout << i + 1 << ". " << questVector[currentQuest].getQuestName() << endl;
			currentQuest++;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		break;
	}
}

void stepChoices(int userQuestChoice, int STEPS, int startSteps, vector<Quest> questVector, vector<string> stepVector)
{
	// Output the name and description of the quest. 
	cout << questVector[userQuestChoice - 1].getQuestName() << endl;
	// Check if there is a description, if so then print it.
	if (questVector[userQuestChoice - 1].getQuestDescription() != "")
	{
		cout << questVector[userQuestChoice - 1].getQuestDescription() << endl;
	}
	// Prompt the user to choose a step then, output the exit variable, and then output all the steps.
	cout << "\nChoose a step..\n" << endl;
	cout << "0. Exit" << endl;
	for (int i = 0; i < STEPS; i++)
	{
		cout << i + 1 << ". " << stepVector[startSteps] << endl;
		startSteps++;
	}
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
}

void hintChoices(int hintCounter, int hintEnd, int userStepChoice, vector<string> stepVector, vector<string> hintVector)
{
	int userHintChoice; // This is the user's input for the hint.
	int stepNumber = 1; // This is the counter for the current step.

	cout << stepVector[userStepChoice - 1] << endl << endl;
	do // Do this.
	{
		// If the hintOutput is the maximum amount tell the user there is no more hints and break from the do-while loop.
		if (hintCounter == hintEnd)
		{
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
			cout << "No more hints. Returning to steps.." << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
			break;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		// For loop to print out each hint every loop.
		for (int i = hintCounter; i <= hintCounter; i++)
		{
			cout << stepNumber << ". " << hintVector[i] << endl;
			stepNumber++;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		cout << "Type '1' to request another hint and '2' to go back to steps." << endl; // Give the user the commands they can use.
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
		cin >> userHintChoice; // Set user's input to userHintChoice.
		// If the userHintChoice is equal to one increase the counter variable.
		if (userHintChoice == 1)
		{
			hintCounter++;
		}
	} while (userHintChoice != MENUCHOICE2); // While the user's choice isn't 2.
}

int additionalStepPrint(int userStepChoice, int STEPS, int startSteps, vector<string> additionalStepsVector)
{
	int userAdditionalChoice; // This is the user's input for the addition step.

	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
	cout << additionalStepsVector[userStepChoice - 1] << endl << endl;
	cout << "Choose a step..\n";
	for (int i = startSteps; i < STEPS; i++)
	{
		cout << i + 1 << ". " << additionalStepsVector[i] << endl;
	}
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl; // Space for output.
	cin >> userAdditionalChoice;
	return userAdditionalChoice;
}
