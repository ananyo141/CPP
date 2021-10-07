// Convert rectangular coordinates to polar coordinates
#include <iostream>
#include <cmath>
const double RAD_TO_DEG = 57.29577951;

// structure declarations
struct RectCoord {
    double x;
    double y;
};
struct PolarCoord {
    double distance;
    double angle_rad;
};

// function prototypes
PolarCoord convertRect_to_Polar(RectCoord rectCo);
void showPolar(PolarCoord polarCo);

int main() {
    RectCoord rectCo;
    PolarCoord polarCo;
    std::cout << "Enter the x and y value: ";
    while (std::cin >> rectCo.x >> rectCo.y) {
        polarCo = convertRect_to_Polar(rectCo);
        showPolar(polarCo);
        std::cout << "Next two numbers (q to quit): ";
    }
    char ch;
    std::cin.clear();
    std::cin >> ch;
    if (ch == 'q') std::cout << "Bye";
    else std::cout << "Unknown input";
    std::cout << std::endl;

    return 0;
}

PolarCoord convertRect_to_Polar(RectCoord rectCo) {
    PolarCoord resultPolar;
    resultPolar.distance = sqrt((rectCo.x*rectCo.x) + (rectCo.y*rectCo.y));
    resultPolar.angle_rad = atan2(rectCo.y, rectCo.x);
    return resultPolar;
}

void showPolar(PolarCoord polarCo) {
    std::cout << "Distance = " << polarCo.distance
              << ", angle = "  << polarCo.angle_rad * RAD_TO_DEG
              << " degrees\n";
}
