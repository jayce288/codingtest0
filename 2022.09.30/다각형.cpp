#include <iostream>
#include <vector>
#define ld long double
using namespace std;

struct loc {
    ld x, y;
};

void get_input(int& n, vector<loc>& points) {
    loc temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%Lf %Lf", &temp.x, &temp.y);
        points.push_back(temp);
    }

    return;
}

ld ex_product(loc stand, loc pa, loc pb) {
    ld result = 0;
    result = (pa.x - stand.x) * (pb.y - stand.y) - (pa.y - stand.y) * (pb.x - stand.x);
    return result / 2.0;
}

ld calc_area(int n, vector<loc>& points) {
    ld area = 0;
    loc standard_point = points[0];

    for (int i = 1; i < n - 1; i++) {
        area += ex_product(standard_point, points[i], points[i + 1]);
    }
    return area;
}

int main() {
    int n;
    vector<loc> points;

    get_input(n, points);
    ld result = calc_area(n, points);
    if (result < 0) result *= -1;
    printf("%.1Lf\n", result);

    return 0;
}