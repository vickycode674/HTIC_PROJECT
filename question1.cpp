#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int current_number = 0;
bool is_even_turn = true;

void print_even() {
    while (current_number <= 10) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return is_even_turn; });

        if (current_number <= 10 && current_number % 2 == 0) {
            cout << "Even: " << current_number << endl;
            current_number++;
            is_even_turn = false; // Next turn is for odd
            cv.notify_all();
        }
    }
}

void print_odd() {
    while (current_number < 10) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !is_even_turn; });

        if (current_number < 10 && current_number % 2 != 0) {
            cout << "Odd: " << current_number << endl;
            current_number++;
            is_even_turn = true; // Next turn is for even
            cv.notify_all();
        }
    }
}

int main() {
    thread t1(print_even);
    thread t2(print_odd);

    t1.join();
    t2.join();

    return 0;
}