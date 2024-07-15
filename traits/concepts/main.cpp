//
// Created by amardeep on 15/07/24.
//
#include "iostream"

class widget {
public:
    int id;
    std::string name;

    std::ostream &write(std::ostream &os) const {
        os << id << ',' << name << std::endl;
        return os;
    }

};

class gardget {
public:
    int id;
    std::string name;

    friend std::ostream &operator<<(std::ostream &os, gardget const &o);
};

std::ostream &operator<<(std::ostream &os, gardget const &o) {
    os << o.id << ',' << o.name << '\n';
    return os;
}

template<typename T>
class uses_write {
public:
    static constexpr bool value = false;
};


template<>
class uses_write<widget> {
public:
    static constexpr bool value = true;
};

template<bool>
class serializer {
public:
    template<typename T>
    static void serialize(std::ostream &os, T const &value) {
        os << value;
    }
};

template<>
class serializer<true> {
public:
    template<typename T>
    static void serialize(std::ostream &os, T const &value) {
        value.write(os);
    }
};

template<typename T>
void serialize(std::ostream &os, T const &value) {

    serializer<uses_write<T>::value>::serialize(os, value);

};


int main() {
    widget w{1, "amar"};
//    w.write(std::cout);

    gardget g{2, "name"};
//    std::cout << g << std::endl;

    serialize(std::cout,w);
    serialize(std::cout,g);

    return 0;
};