#include <iostream>
#include <cstdlib>
#include <ctime>

#define TOTAL_NUM 6
#define RANGE_MAX 59

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    int num = 0;
    int numbers[TOTAL_NUM];
    bool unique = false;

    for (int i = 0; i < TOTAL_NUM; i++) {
        do {
            // rand() -> 0 ... 999 % RANGE_MAX -> 0 ... RANGE_MAX-1
            // %RANGE_MAX: 10 -> 0-9, 59 -> 0-58
            num = (rand() % RANGE_MAX) + 1;
            unique = true;

            for (int j = 0; j < i; j++) {
                if (numbers[j] == num)
                    unique = false;
            }

        } while (!unique);

        numbers[i] = num;
        cout << "num" << (i + 1) << ": " << num << endl;
    }

    return 0;
}
