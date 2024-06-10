#include <unordered_map>
#include "iostream"
#include <cassert>
#include "map"
#include "vector"

using namespace std;


#include <vector>

class MyCalendar {
public:
    MyCalendar() {}

    std::vector<std::pair<int, int>> total;

    bool book(int start, int end) {
        std::pair<int, int> mypair{};
        if (this->total.size() == 0) {
            total.push_back(mypair);
            return true;
        }
        int count = 0;

        for (int i = 0; i < total.size(); i++) {
            auto left = this->total[i].first;
            auto right = this->total[i].second;
            if (end <= left || start >= right) {
                count = count + 1;
            } else {
                return false;
            }
        }

        if (count == total.size()) {
            this->total.push_back(mypair);
            return true;
        } else {
            return false;
        }
    }
};


int main() {
    MyCalendar *obj = new MyCalendar();
    bool param_1 = obj->book(10, 20);
    std::cout << param_1 << std::endl;
    return 0;
}