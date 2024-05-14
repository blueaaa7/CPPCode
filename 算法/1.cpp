#include <iostream>
#include <cmath>

void drawCircle(int r1, int r2) {
    int w = 2 * r2 + 1;
    int h = 2 * r2 + 1;
    int center = r2;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int dist = std::sqrt((i - center) * (i - center) + (j - center) * (j - center));
            if (dist >= r1 && dist <= r2) {
                std::cout << "*";
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}

int main() {
    int r1 = 5;
    int r2 = 10;
    drawCircle(r1, r2);
    return 0;
}
