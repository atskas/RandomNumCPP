#include <iostream>
#include <random>
#include <chrono> 
#include <thread> 
#include <limits>

using namespace std;

void pause(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

int getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail()) {
            return value;
        }

        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int rng() {
    cout << "You could've just gone to google to generate a random number..\n";
    pause(1);
    cout << "But since you're here, let's do it anyway.\n";
    pause(1);

    int minNumber = getIntInput("Enter your minimum number: ");
    pause(1);

    int maxNumber;
    while (true) {
        maxNumber = getIntInput("Enter your maximum number: ");
        if (maxNumber >= minNumber) {
            break;
        }
        cout << "Maximum number must be greater than or equal to minimum number. Try again.\n";
    }

    pause(1);

    random_device rd; // Random device to seed the generator
    mt19937 gen(rd()); // Seed the random number generator with a random device
    uniform_int_distribution<> dist(minNumber, maxNumber); // Uniform distribution between minNumber and maxNumber

    int random_number = dist(gen);
    cout << "Your random number is:\n";
    pause(1);
    cout << "\n" << random_number << endl;
    pause(1);
    cout << "Press Enter to exit.\n";
    cin.ignore();
    cin.get();
    cout << "Exiting...\n";

    return 0;
}

int main() {
    rng();
    return 0;
}
