// Header file, Using structs, 2D arrays, and various string input functions to create a jedi fencing tournment 


  #ifndef FENCING_H
  #define FENCING_H

  #include <string>
  #include <iostream>
  using namespace std;

  // Jedi struct to store participant details
  struct Jedi {
    string lightsaberColor;
    string name;
    int skillLevel;
    int forceStrength;
    int age; // Add age attribute

    // Member Function to calculate age based on birth year
    int getAge() {
        int currentYear = 2023;
        int birthYear = currentYear - age;
        return birthYear;
    }

    // Member Function to get affiliation
    string getAffiliation() {
        if (forceStrength >= 70) {
            return "Jedi Order";
        } else {
            return "Sith Order";
        }
    }

    // Member Function to get force power level
    int getForcePowerLevel() {
        return skillLevel + forceStrength;
    }

  };

  const int MAX_COMPETITORS = 10; // Only have 10 participants
  const int MAX_ROUNDS = 5;


  // Desc: Displays the menu options for the user to start the tournament
  // Pre: Nothing
  // Post: Displays the menu
  void displayMenu();
  // Desc: Addes a new jedi particpant to the list of competitors
  // Pre: Nothing
  // Post: Adds the particpant
  void addJediParticipant(Jedi competitors[], int& numCompetitors);
  // Desc: Calculates the pairing score between two jedi paricpants
  // Pre: Numbers for the score must be between 0-10
  // Post: The particpants are paired
  int calculateScore(Jedi& jedi1, Jedi& jedi2);
  // Desc: Computes the score matrix based on the differences between jedi paricipants
  // Pre: Nothing
  // Post: Creates the matrix
  void createScoreMatrix(Jedi competitors[], int scoreMatrix[][MAX_COMPETITORS], int numCompetitors);
  // Desc: Finds final pairings of jedi participants based on the score matrix
  // Pre: Nothing
  // Post: Adds the pair to the matrix
  void pairingAlgorithm(Jedi competitors[], int scoreMatrix[][MAX_COMPETITORS], Jedi duelPairs[][2], int numCompetitors);
  // Desc: Prints the pairings of jedi participants 
  // Pre:  Nothing
  // Post: Iterates through the score
  void displayPairing(int scoreMatrix[][MAX_COMPETITORS], Jedi duelPairs[][2], int numCompetitors);

  #endif
