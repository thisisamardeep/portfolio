//#include "set"
#include "iostream"
#include "vector"

class Coord {
private:
    int x, y;
public:
    Coord(int i1, int i2) : x(i1), y(i2) {
    }

    friend Coord operator-(Coord const &c1, Coord const &c2) {
        return Coord(c1.x - c2.x, c1.y - c2.y);
    }

    Coord abs() {
        return Coord(std::abs(x), std::abs(y));
    }
};

class GeoObj {
public:
    virtual void draw() const = 0;
    virtual Coord center_of_gravity() const = 0;


};

class Circle : public GeoObj {
public:
    virtual void draw() const override;
    virtual Coord center_of_gravity() const override;

};

void Circle::draw() const {

}

class Line : public GeoObj {
public:
    virtual void draw() const override;
    virtual Coord center_of_gravity() const override;


};

void Line::draw() const {

}

using namespace std;

int main() {
    Coord rt{23, 45};
    Coord rt1{232, 45};
//    -rt;
    int tyy = 67;
//    TreeNode *root = new TreeNode{3};
//
//    root->left = new TreeNode{9};
//    root->right = new TreeNode{20};
//
//    root->right->left = new TreeNode{15};
//    root->right->right = new TreeNode{7};


    return 0;
}