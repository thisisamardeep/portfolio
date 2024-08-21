#include <functional>
#include "iostream"
#include "thread"
#include "vector"
#include "queue"
#include "string"

using namespace std;


using namespace std;


class Solution {
public:
    string betterCompression(const string &compressed) {
        std::unordered_map<char, int> mymap{};
        int counter_string = 0;
        int counter_digit_first = 0;
        int counter_digit_second = 1;
        int new_counter_string = -1;

        while (counter_string < compressed.size()) {
            counter_digit_first = counter_string + 1;
            // Need to calculate counter_digit_second
            for (int i = counter_digit_first; i < compressed.size(); i++) {
                if (std::isdigit(compressed[i]) == 0) {
                    break;

                } else {
                    counter_digit_second = i;
                }
            }
            new_counter_string = counter_digit_second + 1;
            if (mymap.count(compressed.at(counter_string)) == 0) {
                mymap.insert(std::pair<char, int>{compressed.at(counter_string), 1});
            } else {
                mymap[compressed.at(counter_string)] = mymap[compressed.at(counter_string)] + ;
            }
            counter_string = new_counter_string;

        }


        return "34";
    }
};

int main() {
    Solution rer{};
    auto res = rer.betterCompression("a3c9b2c1");
    return 0;
}