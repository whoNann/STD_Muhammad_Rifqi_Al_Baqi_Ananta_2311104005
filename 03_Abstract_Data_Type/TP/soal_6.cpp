#include <iostream>
#include <cmath> // Untuk konstanta M_PI dan fungsi sqrt
using namespace std;

class Kerucut {
private:
    double radius;
    double height;

public:
    // Konstruktor
    Kerucut(double r, double h) : radius(r), height(h) {}

    // Getter untuk radius
    double getRadius() const {
        return radius;
    }

    // Getter untuk height
    double getHeight() const {
        return height;
    }

    // Setter untuk radius
    void setRadius(double r) {
        radius = r;
    }

    // Setter untuk height
    void setHeight(double h) {
        height = h;
    }

    // Fungsi untuk menghitung volume kerucut
    double volume() const {
        return (M_PI * radius * radius * height) / 3.0;
    }

    // Fungsi untuk menghitung luas permukaan kerucut
    double surfaceArea() const {
        double slantHeight = sqrt((radius * radius) + (height * height));
        return (M_PI * radius * slantHeight) + (M_PI * radius * radius);
    }
};

int main() {
    // Membuat objek kerucut dengan radius 3 dan height 5
    Kerucut kerucut(3, 5);

    // Menampilkan volume dan luas permukaan kerucut
    cout << "Volume kerucut: " << kerucut.volume() << endl;
    cout << "Luas permukaan kerucut: " << kerucut.surfaceArea() << endl;

    return 0;
}