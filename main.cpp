
  // Using structs, 2D arrays, and various string input functions to create a jedi fencing tournment 

  #include "Fencing.h"
  
  #include <iostream>
  #include <string>
  #include <cmath>
  using namespace std;

 // const int MAX_COMPETITORS = 10; // Only have 10 participants
 // const int MAX_ROUNDS = 5;

  int main() {
    Jedi competitors[MAX_COMPETITORS];
    int scoreMatrix[MAX_COMPETITORS][MAX_COMPETITORS];
    Jedi duelPairs[MAX_COMPETITORS/2][2];
    int numCompetitors = 0; // intialize jedi to 0

    // Display menu options to user
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch(choice) {
            case 1:
                addJediParticipant(competitors, numCompetitors);
                break;
            case 2:
                if(numCompetitors < 2 || numCompetitors % 2 != 0) {
                    cout << "There must be at least two Jedi participants and an even number of participants to calculate pairings.\n";
                    cout << "Please add more participants or remove existing ones.\n";
                    break;
                }
                createScoreMatrix(competitors, scoreMatrix, numCompetitors);
                pairingAlgorithm(competitors, scoreMatrix, duelPairs, numCompetitors);
                displayPairing(scoreMatrix, duelPairs, numCompetitors);
                break;
            case 3:
                cout << "May the force be with you! \n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while(choice != 3);

    return 0;
  }

