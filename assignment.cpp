#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // For usleep()

using namespace std;

// Class to represent a Team
class Team {
public:
    string name;
    string players[3];
    int totalRuns;

    Team(string teamName, string player1, string player2, string player3) {
        name = teamName;
        players[0] = player1;
        players[1] = player2;
        players[2] = player3;
        totalRuns = 0;
    }
};

// Function prototypes
void welcomeUsers();
void displayPlayers(const Team& teamA, const Team& teamB);
void selectBatsmanAndBowler(const Team& batTeam, const Team& bowlTeam, string& batsman, string& bowler);
void startInning(int inning, const Team& batTeam, const Team& bowlTeam, const string& batsman, const string& bowler);
int playInning();
void displayScore(const Team& team);
void decideWinner(int teamAScore, int teamBScore);

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Create teams
    Team teamA("TeamA", "PlayerA1", "PlayerA2", "PlayerA3");
    Team teamB("TeamB", "PlayerB1", "PlayerB2", "PlayerB3");

    // Welcome message
    welcomeUsers();

    // Display players of both teams
    displayPlayers(teamA, teamB);

    // Inning 1
    string batsman, bowler;
    selectBatsmanAndBowler(teamA, teamB, batsman, bowler);
    startInning(1, teamA, teamB, batsman, bowler);
    teamA.totalRuns = playInning();
    displayScore(teamA);

    // Inning 2
    selectBatsmanAndBowler(teamB, teamA, batsman, bowler);
    startInning(2, teamB, teamA, batsman, bowler);
    teamB.totalRuns = playInning();
    displayScore(teamB);

    // Decide the winner
    decideWinner(teamA.totalRuns, teamB.totalRuns);

    return 0;
}

// Function implementations
void welcomeUsers() {
    cout << "Welcome to the Gully Cricket App!" << endl;
    cout << "Let's start the cricket match!" << endl << endl;
}

void displayPlayers(const Team& teamA, const Team& teamB) {
    cout << "Team A Players:" << endl;
    for (const string& player : teamA.players) {
        cout << "- " << player << endl;
    }
    cout << endl;

    cout << "Team B Players:" << endl;
    for (const string& player : teamB.players) {
        cout << "- " << player << endl;
    }
    cout << endl;
}

void selectBatsmanAndBowler(const Team& batTeam, const Team& bowlTeam, string& batsman, string& bowler) {
    batsman = batTeam.players[rand() % 3];
    bowler = bowlTeam.players[rand() % 3];
}

void startInning(int inning, const Team& batTeam, const Team& bowlTeam, const string& batsman, const string& bowler) {
    cout << "Inning " << inning << ": " << endl;
    cout << batTeam.name << " is batting. Batsman: " << batsman << endl;
    cout << bowlTeam.name << " is bowling. Bowler: " << bowler << endl;
    usleep(5000000); // Sleep for 5 seconds delay
    cout << "Start of the inning!" << endl << endl;
}

int playInning() {
    int runs = 0;
    cout << "Playing the inning..." << endl;

    for (int ball = 1; ball <= 6; ++ball) {
        int run = rand() % 7; // Generate a random run between 0 and 6
        runs += run;
        cout << "Ball " << ball << ": " << run << " runs" << endl;
        usleep(5000000); // Sleep for 5 seconds ball delivery
    }

    cout << "End of the inning!" << endl;
    return runs;
}

void displayScore(const Team& team) {
    cout << team.name << " scored " << team.totalRuns << " runs." << endl << endl;
}

void decideWinner(int teamAScore, int teamBScore) {
    cout << "Final Scores:" << endl;
    cout << "Team A: " << teamAScore << endl;
    cout << "Team B: " << teamBScore << endl;

    if (teamAScore > teamBScore) {
        cout << "Team A wins!" << endl;
    } else if (teamAScore < teamBScore) {
        cout << "Team B wins!" << endl;
    } else {
        cout << "The match is a tie!" << endl;
    }
}