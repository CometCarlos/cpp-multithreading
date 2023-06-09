#include <iostream>
#include <string>
#include <future>
#include <thread>

using namespace std;

float testLongMethod() {
    float result = 0;
    for (int i = 0; i < 2000000000; i++) {
        result += (float) i / 2;
    }
    result *= 0.2049;
    return result;
}

int main() {
    cout << "Hello world!" << endl;
    
    future<float> task = async(
        []() { return testLongMethod(); }
    );

    for (int i = 0; i < 10; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(300));
        if (task._Is_ready()) {
            cout << "    DONE!" << endl;
            break;
        }
    }

    string input;
    getline(cin, input);

    string result = to_string(task.get());
    cout << "The result calculated was " << result << endl;

    cout << "You entered: " << input << endl;
}
