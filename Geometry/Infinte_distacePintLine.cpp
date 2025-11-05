#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

// 🔹 Distance between two points:
// Formula: √((x2 - x1)² + (y2 - y1)²)
double dist(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

// 🔹 Distance from point P(x0, y0) to infinite line passing through A(x1, y1) and B(x2, y2)
// Mathematical derivation:
//
// 1️ Line AB equation (vector form):  Q = A + t * (B - A),   t ∈ (-∞, ∞)
// 2️⃣ Perpendicular distance formula (from cross product):
//
//     d = |(B - A) × (P - A)| / |B - A|
//
//     Here cross product in 2D means:
//     (B - A) × (P - A) = (x2 - x1)*(y0 - y1) - (y2 - y1)*(x0 - x1)
//
// 3️⃣ Denominator |B - A| = √((x2 - x1)² + (y2 - y1)²)
//
// Final formula:
//
//     d = |(x2 - x1)*(y0 - y1) - (y2 - y1)*(x0 - x1)| / √((x2 - x1)² + (y2 - y1)²)

double pointToLineDist(Point A, Point B, Point P) {
    double numerator = fabs((B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x));
    double denominator = hypot(B.x - A.x, B.y - A.y);
    return numerator / denominator;
}

int main() {
    Point A = {0, 0}, B = {5, 0}, P = {7, 3};

    cout << fixed << setprecision(3)
         << "Infinite line distance = " << pointToLineDist(A, B, P) << endl;
}
