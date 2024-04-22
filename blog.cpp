//#include "set"


#include "queue"

int main() {
    std::queue<int> numbers;
    numbers.push(45);
    auto front_of_queue = numbers.front();
    auto back_of_queue = numbers.back();
    numbers.pop();// Removes elements from front of the queue
    return 0;
}