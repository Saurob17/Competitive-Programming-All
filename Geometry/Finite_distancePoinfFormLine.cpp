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

// 🔹 Distance from point P to finite line segment AB
// Mathematical steps:
// 1️⃣ Vector AB = (Bx - Ax, By - Ay)
// 2️⃣ Vector AP = (Px - Ax, Py - Ay)
// 3️⃣ Projection ratio (t) = (AP · AB) / |AB|²
//     where "·" = dot product
//     => t = ((Px - Ax)(Bx - Ax) + (Py - Ay)(By - Ay)) / ((Bx - Ax)² + (By - Ay)²)
// 4️⃣ If t < 0 → projection falls before A → distance = |P - A|
//     If t > 1 → projection falls after B → distance = |P - B|
//     If 0 ≤ t ≤ 1 → projection falls on segment → perpendicular distance
// 5️⃣ Projection point: Proj = A + t * AB = (Ax + t*(Bx - Ax), Ay + t*(By - Ay))
// 6️⃣ Distance = |P - Proj|

double pointToSegmentDist(Point A, Point B, Point P) {
    // Step 1-2: Build vectors
    double ABx = B.x - A.x, ABy = B.y - A.y;
    double APx = P.x - A.x, APy = P.y - A.y;

    // Step 3: Compute projection ratio (t)
    double t = (APx * ABx + APy * ABy) / (ABx * ABx + ABy * ABy);

    // Step 4: Check segment boundaries
    if (t < 0.0) return dist(P, A);   // Before A → nearest point is A
    if (t > 1.0) return dist(P, B);   // After B → nearest point is B

    // Step 5: Compute projection point
    Point proj = {A.x + t * ABx, A.y + t * ABy};

    // Step 6: Return perpendicular distance
    return dist(P, proj);
}

int main() {
    Point A = {0, 0}, B = {5, 0}, P = {7, 3};

    cout << fixed << setprecision(3)
         << "Finite segment distance = " << pointToSegmentDist(A, B, P) << endl;
}
