#include <iostream>
#include <random>
#include <chrono> 
#include <thread> 

using namespace std;

void pause(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

int rng() {
    int minNumber, maxNumber;
    cout << "You could've just gone to google to generate a random number.. \n";
    pause(1);
    cout << "But since you're here, let's do it anyway. \n";
    pause(1);
    cout << "Enter your minimum number: ";
    cin >> minNumber;
    pause(1);
    cout << "Enter your maximum number: ";
    cin >> maxNumber;
    pause(1);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(minNumber, maxNumber);

    int random_number = dist(gen);
    cout << "Your random number is: \n";
    for (int i = 5; i > 0; --i) {
        cout << i << "...\n";
        pause(1);
    }
    pause(1);
    cout << "\n" << random_number << endl;

    return 0;
}

int main() {
    rng(); // Call the function here
    return 0;
}
