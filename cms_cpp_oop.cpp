#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    vector<string> participants;
    vector<string> remainingParticipants;

    // Get number of participants
    int numParticipants;
    cout << "Enter number of participants: ";
    if (!(cin >> numParticipants) || numParticipants < 2 || numParticipants > 100) {
        cout << "Invalid input. Please enter a number between 2 and 100.\n";
        return 1;
    }

    // Get participant names
    cout << "Enter " << numParticipants << " participant names:\n";
    for (int i = 0; i < numParticipants; i++) {
        string name;
        cout << "Participant " << i + 1 << ": ";
        cin >> name;
        participants.push_back(name);
    }

    remainingParticipants = participants;
    srand(time(0)); // Seed random number generator

    char choice;
    do {
        if (remainingParticipants.empty()) {
            cout << "\nAll participants have already won!\n";
            break;
        }

        // Select random winner
        int winnerIndex = rand() % remainingParticipants.size();
        string winner = remainingParticipants[winnerIndex];

        // Announce winner
        cout << "\nLucky Draw Result:\n";
        cout << "Congratulations " << winner << "! You win all funds!\n";

        // Remove winner from future draws
        remainingParticipants.erase(remainingParticipants.begin() + winnerIndex);

        // Display remaining participants for next draw
        if (!remainingParticipants.empty()) {
            cout << "\nRemaining participants for next draw:\n";
            for (const auto& participant : remainingParticipants) {
                cout << "- " << participant << endl;
            }

            cout << "\nPerform another draw? (y/n): ";
            cin >> choice;
        }
        else {
            cout << "\nAll funds have been distributed!\n";
            break;
        }
    } while (tolower(choice) == 'y');

    return 0;
}