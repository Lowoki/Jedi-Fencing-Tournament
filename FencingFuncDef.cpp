
  // Function Definition file, Using structs, 2D arrays, and various string input functions to create a jedi fencing tournment 
  
  #include "Fencing.h"

  #include <iostream>
  #include <string>
  #include <cmath>

  using namespace std;

  // Function to display menu options
  void displayMenu() {
    cout << "Select an option:\n";
    cout << "1. Add a Jedi participant\n";
    cout << "2. Calculate and display pairings\n";
    cout << "3. Exit the program\n";
  }

  // Function to add a Jedi participant to the list of competitors
  void addJediParticipant(Jedi competitors[], int& numCompetitors) {
    if(numCompetitors >= MAX_COMPETITORS) {
        cout << "The maximum number of Jedi participants has been reached.\n";
        return;
    }

    // Prompt user for Jedi details
    Jedi newJedi;
    cout << "Enter the Jedi's lightsaber color: ";
    cin >> newJedi.lightsaberColor;
    cin.get(); // discard newline character in input buffer
    cout << "Enter the Jedi's name: ";
  getline(cin, newJedi.name);
  cout << "Enter the Jedi's skill level (1-10): ";
  cin >> newJedi.skillLevel;
  cout << "Enter the Jedi's force strength (1-10): ";
  cin >> newJedi.forceStrength;

  // Validate input
  if(newJedi.skillLevel < 1 || newJedi.skillLevel > 10 || newJedi.forceStrength < 1 || newJedi.forceStrength > 10) {
    cout << "Invalid skill level or force strength. Please enter values between 1 and 10.\n";
    return;
  }

  // Add Jedi to list of competitors
  competitors[numCompetitors] = newJedi;
  numCompetitors++;
  cout << "Jedi participant added successfully.\n";
  }

  // Function to calculate score for a duel between two Jedi
  int calculateScore(Jedi& jedi1, Jedi& jedi2) {
  int skillDiff = abs(jedi1.skillLevel - jedi2.skillLevel);
  int forceDiff = abs(jedi1.forceStrength - jedi2.forceStrength);
  int totalDiff = skillDiff + forceDiff;
  int score = 10 - totalDiff;
  return score;
  }

  // Function to create score matrix for all pairs of Jedi competitors
  void createScoreMatrix(Jedi competitors[], int scoreMatrix[][MAX_COMPETITORS], int numCompetitors) {
  for(int i = 0; i < numCompetitors; i++) {
  for(int j = i+1; j < numCompetitors; j++) {
  int score = calculateScore(competitors[i], competitors[j]);
  scoreMatrix[i][j] = score;
  scoreMatrix[j][i] = score; // score matrix is symmetric
  }
  }
  }

  // Function to implement the pairing algorithm to determine duel pairs
  void pairingAlgorithm(Jedi competitors[], int scoreMatrix[][MAX_COMPETITORS], Jedi duelPairs[][2], int numCompetitors) {
  // Sort Jedi by force power level
  for(int i = 0; i < numCompetitors-1; i++) {
  for(int j = i+1; j < numCompetitors; j++) {
  if(competitors[i].getForcePowerLevel() < competitors[j].getForcePowerLevel()) {
  Jedi temp = competitors[i];
  competitors[i] = competitors[j];
  competitors[j] = temp;
  }
  }
  }


  // Pair Jedi for duels
  int i = 0;
  int j = numCompetitors-1;
  int pairCount = 0;
  while(i < j) {
    duelPairs[pairCount][0] = competitors[i];
    duelPairs[pairCount][1] = competitors[j];
    i++;
    j--;
    pairCount++;
  }
  }

  // Function to display pairings and corresponding scores
  void displayPairing(int scoreMatrix[][MAX_COMPETITORS], Jedi duelPairs[][2], int numCompetitors) {
  cout << "Pairings for the tournament:\n";
  for(int i = 0; i < numCompetitors/2; i++) {
  cout << duelPairs[i][0].name << " (Force power level: " << duelPairs[i][0].getForcePowerLevel() << ") vs. "
  << duelPairs[i][1].name << " (Force power level: " << duelPairs[i][1].getForcePowerLevel() << ") - Score: "
  << scoreMatrix[i][i+numCompetitors/2] << endl;
  }
  }
  
