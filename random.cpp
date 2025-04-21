#include <iostream>
#include <random>
#include <chrono> 
#include <thread> 

using namespace std;

int maxNumber = 100; // Default maximum number for random generation
int minNumber = 1; // Default minimum number for random generation

int main() {
    random_device rd; // Obtain a random number from hardware
    mt19937 gen(rd());  // Seed the generator with a random device
    uniform_int_distribution<> dist(minNumber, maxNumber); // Define the range

    int random_number = dist(gen);
    cout << "Your random number is: \n";
    for (int i = 5; i > 0; --i) {
        cout << i << "...\n";
        this_thread::sleep_for(chrono::seconds(1)); // Sleep for 1 second
    }
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\n" << random_number << endl; // Output the random number

    return 0;
}
