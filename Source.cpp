/* By: Naszir Merritt 
* This project is part two of the original sky-net project.
* In this part we will implement a human, and two other A.I'
* inputs to the project. In puts being linear and completely random for the AI. 
* And just a guess given from the user for the human input.
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>




int main()
{
	
		using namespace std;

		srand(static_cast<unsigned int>(time(0))); // Seeds the random number givien the current time

		int EnemyLocation = rand() % 64 + 1; // number between 1 and 64 for EnemyLocation

		int BoxMax = 64; // Max guess place holder

		int BoxMin = 1; // Min guess place holder

		int Predictions = 0; // number of Binary predictions place holder 

		int RandPredictions = 0; // Random skynet number of  predictions 

		int LinearPredictions = 0; // Linear skynet number of predictions

		int HumanPredictions = 0; // human number of predictions

		int GuessLocation = rand() % 64 + 1; // number between 1 and 64 for BinarySkyNetGuess

		int RandGuessLocation = rand() % 64 + 1;

		int LinearGuessLocation = 0; // Linear answer variable 

		int HumanGuessLocation; // user answer variable 

		char again = 'Y'; // play again variable

		bool EnemyFound = false; // boolean for if enemy is found 

		while (again == 'y' || again == 'Y') // play again while loop
		{
			

			// Welcoming the user to the program
			cout << "\n\t\t\t\t\t Welcome to Skynet, This is just a test.\n\n";
			cout << "Together we will witness our models 1-3 of Skynet search, Binary Skynet, Random Skynet, and Linear Skynet.\n\n";
			cout << "Also you user will be given a chance to compete, don't fail.\n\n";
			cout << "Skynet models Initalizing...\n\n";
			cout << "User, this program will find anything in the 8x8 sector.\n";
			cout << "Skynet models, hunts down and tracks sectors of the program in order to find the target.\n";



			do // Human program
			{
				cout << "\n----------------------------------------------------------------------\n";// spacing
				cout << "\n----------------------------------------------------------------------\n";

				cout << "Human, ping # " << HumanPredictions << "\n";
				cout << "\nPlease input guess...\n";

				cin >> HumanGuessLocation; // User input for location

				if (HumanGuessLocation < EnemyLocation) // prompts user if guess is too low 
				{


					cout << "\nThe enemy location is not in box # " << HumanGuessLocation << ". The number is too low.\n";
					HumanPredictions++;

				}
				else if (HumanGuessLocation > EnemyLocation) // prompts user if guess is too high 
				{
					cout << "\nThe enemy location is not in box # " << HumanGuessLocation << ". The number is too high.\n";
					HumanPredictions++; // Human guess counter increments

				}
				else // promots user the location was found 
				{
					cout << "\n----------------------------------------------------------------------\n";
					cout << "\n----------------------------------------------------------------------\n";
					cout << "\nThe enemy was located in box # " << EnemyLocation << "\n";
					cout << "\nEnemy Location Spotted. Only took you " << HumanPredictions << " search attempts. Nice, for a human\n";



				}


			} while (EnemyLocation != HumanGuessLocation);




			// do loop for the BinarySkynet 
			do
			{
				cout << "\n----------------------------------------------------------------------\n";
				cout << "\n----------------------------------------------------------------------\n";

				cout << "'Binary Skynet' Sending out ping #" << Predictions << "\n";


				if (GuessLocation > EnemyLocation) // gives condition for if guessed location is too high
				{
					cout << "\nThe enemy location is not in the box #" << GuessLocation << ", the number is too high.\n"; // Tells the user that the guess is too high

					BoxMax = GuessLocation; // changes the max to last guessed

					GuessLocation = ((BoxMax - BoxMin) / 2) + BoxMin; // next guessed location 

					Predictions++; // increments the prediction counter
				}
				else if (GuessLocation < EnemyLocation) // gives condition if guessed location is too low 
				{
					cout << "\nThe enemy location is not in box #" << GuessLocation << ", the number is too low.\n"; // tells user that guess is too low 

					BoxMin = GuessLocation; // changes the min to last guessed location

					GuessLocation = ((BoxMax - BoxMin) / 2) + BoxMin;

					Predictions++;

				}
				else  // gives condition if the enemylocation is equal to guessed location
				{
					cout << "\n----------------------------------------------------------------------\n";
					cout << "\n----------------------------------------------------------------------\n";
					cout << "'Binary Skynet' Ping # " << Predictions << ".\n";
					cout << "\nThe enemy was located in box #" << EnemyLocation << "\n"; // tells user where enemy was found 

					cout << "\nEnemy Location spotted. Only took 'Binary Skynet' " << Predictions << " search attempts.\n"; // tells user number of attempts



				}
			} while (EnemyLocation != GuessLocation); // gives condition of until enemy is found, run the program




			do // do looop for random skynet
			{
				cout << "\n----------------------------------------------------------------------\n";
				cout << "\n----------------------------------------------------------------------\n";

				cout << "'Random Skynet' sending out ping # " << RandPredictions << "\n";
				if (RandGuessLocation != EnemyLocation)
				{
					cout << "\nThe # " << RandGuessLocation << " is not the enemy's location. Again!\n";

					RandGuessLocation = rand() % 64 + 1; // random skynet guess

					RandPredictions++; // prediction counter for Random Skynet increments


				}
				if (RandGuessLocation == EnemyLocation) // If random skynet finds enemy location
				{

					cout << "\n----------------------------------------------------------------------\n";
					cout << "\n----------------------------------------------------------------------\n";

					cout << "'Random Skynet' Ping # " << RandPredictions << ".\n";
					cout << "\n The enemy was located in box # " << EnemyLocation << "\n";
					cout << "\nEnemy location spotted in " << RandPredictions << " attempts.\n";


				}

			} while (EnemyLocation != RandGuessLocation);

			do
			{
				cout << "\n----------------------------------------------------------------------\n";
				cout << "\n----------------------------------------------------------------------\n";

				cout << "'Linear Skynet' Sending out Ping # " << LinearPredictions << "\n";
				if (LinearGuessLocation < EnemyLocation)
				{
					cout << "\nThe enemy location is not in box # " << LinearPredictions << ". Maybe its the next one.\n";

					LinearGuessLocation++; // increments linear skynets guess 

					LinearPredictions++; // increments linear skynets prediction counter

				}
				if (LinearGuessLocation == EnemyLocation) // linear skynet finds enemy 
				{
					cout << "\n----------------------------------------------------------------------\n";
					cout << "\n----------------------------------------------------------------------\n";
					cout << "'Linear Skynet' Ping #" << LinearPredictions << ".\n";
					cout << "\nThe enemy was located in box # " << EnemyLocation << "\n";
					cout << "\nEnemy Location Spotted. Only took 'Linear Skynet' " << LinearPredictions << " search attempts.\n";
					cout << "\n----------------------------------------------------------------------\n";
					cout << "\n----------------------------------------------------------------------\n";

				}

			} while (EnemyLocation != LinearGuessLocation);

			EnemyFound = true;  // boolean turned true 

			if (EnemyFound == true) // stats 
			{
				cout << "\n      Program Stats";
				cout << "\nLinear Skynet predictions:" << LinearPredictions;
				cout << "\nLinear Skynet Final Guess:" << LinearGuessLocation;
				cout << "\nRandom Skynet predictions:" << RandPredictions;
				cout << "\nRandom Skynet Final Guess:" << RandGuessLocation;
				cout << "\nBinary Skynet Predictions:" << Predictions;
				cout << "\nBinary Skynet Fianl Guess:" << GuessLocation;
				cout << "\nHuman Predictions:" << HumanPredictions;
				cout << "\nHuman Final Guess:" << HumanGuessLocation << "\n";
			}

			cout << "\nWould you like to go again? (Y/N)\n"; // play again prompt
			cin >> again;
		}
	
	

		cout << "\nThanks For Playing.\n"; // exit prompt











		return (0);
	
}