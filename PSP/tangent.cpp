// 문제해결기법 - 12

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

// === File Control ====
const std::string FILE_NAME = "tangent";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";
// types
using ll = long long;
using pii = std::pair<int, int>;

struct Vector2{
    Vector2() = default;
    Vector2(ll _x, ll _y) : x(_x), y(_y) { };
    
    bool operator<(const Vector2& rhs) const { return x != rhs.x ? x < rhs.x : y < rhs.y; }
    Vector2 operator+(const Vector2& rhs) const { return { x + rhs.x , y + rhs.y }; }
    Vector2 operator-(const Vector2& rhs) const { return { x - rhs.x , y - rhs.y }; }

    ll x, y;
};
// constants
constexpr int MAX_N = 10000 + 10;
// variables
Vector2 polygon1[MAX_N], polygon2[MAX_N];
int convex1[MAX_N], convex2[MAX_N];
Vector2 inner[MAX_N * 2];


inline ll cross(const Vector2& v, const Vector2& u) { return v.x * u.y - u.x * v.y; }
inline ll cross(const Vector2& p1, const Vector2& p2, const Vector2& p3) { return cross(p2 - p1, p3 - p1); }

inline ll sqrNorm(const Vector2& p) { return p.x * p.x + p.y * p.y; }
inline ll sqrDist(const Vector2& p1, const Vector2& p2) { return sqrNorm(p2 - p1); }

inline int leftMost(int n, const Vector2* points) { return std::min_element(points, points + n) - points; }
inline int rightMost(int n, const Vector2* points) { return std::max_element(points, points + n) - points; }

int getConvexHull(int n, const Vector2* points, int* out_convex){
    int start = leftMost(n, points);
    int prev = start;
    int next = -1;
    
    int k = 0;
    while(next != start){
        out_convex[k++] = prev;

        next = prev != 0 ? 0 : 1;
        for(int  i = 0; i < n; ++i){
            if(i != prev && i != next){
                ll ccw = cross(points[prev], points[next], points[i]);
                if(ccw < 0 || (ccw == 0 && sqrDist(points[prev], points[next]) < sqrDist(points[prev], points[i])) ){
                    next = i;
                }
            }
        }
        prev = next;
    }
    return k;
}

ll getDoubledArea(int n, Vector2* points){
    ll sum = 0LL;
    for(int i = 2; i < n; ++i) {
        sum += cross(points[0], points[i - 1], points[i]);
    }
    return std::abs(sum);
}

pii getUpperTangent(int pSizeA, Vector2* pointsA, int cSizeA, int* convexA,
    int pSizeB, Vector2* pointsB, int cSizeB, int* convexB){
    
    int rightMostA = 0, leftMostB = 0;
    for(int i = 1; i < cSizeA; ++i){
        if(pointsA[convexA[rightMostA]] < pointsA[convexA[i]]) rightMostA = i;
    }
    for(int i = 1; i < cSizeB; ++i){
        if(pointsB[convexB[i]] < pointsB[convexB[leftMostB]]) leftMostB = i;
    }
    
    int tangentA = rightMostA;
    int tangentB = leftMostB;

    bool repeat = true;
    while(repeat){
        repeat = false;
        while(cross(pointsA[convexA[tangentA]], pointsB[convexB[tangentB]], pointsB[convexB[(cSizeB + tangentB - 1) % cSizeB]]) > 0){
            tangentB = (cSizeB + tangentB - 1) % cSizeB;
        }
        while(cross(pointsB[convexB[tangentB]], pointsA[convexA[tangentA]], pointsA[convexA[(tangentA + 1) % cSizeA]]) < 0){
            tangentA = (tangentA + 1) % cSizeA;
            repeat = true;
        }
    }
    
    return {convexA[tangentA], convexB[tangentB]};
}
pii getLowerTangent(int pSizeA, Vector2* pointsA, int cSizeA, int* convexA,
    int pSizeB, Vector2* pointsB, int cSizeB, int* convexB){
    
    int rightMostA = 0, leftMostB = 0;
    for(int i = 1; i < cSizeA; ++i){
        if(pointsA[convexA[rightMostA]] < pointsA[convexA[i]]) rightMostA = i;
    }
    for(int i = 1; i < cSizeB; ++i){
        if(pointsB[convexB[i]] < pointsB[convexB[leftMostB]]) leftMostB = i;
    }

    int tangentA = rightMostA;
    int tangentB = leftMostB;

    bool repeat = true;
    while(repeat){
        repeat = false;
        while(cross(pointsA[convexA[tangentA]], pointsB[convexB[tangentB]], pointsB[convexB[(tangentB + 1) % cSizeB]]) < 0){
            tangentB = (tangentB + 1) % cSizeB;
        }
        while(cross(pointsB[convexB[tangentB]], pointsA[convexA[tangentA]], pointsA[convexA[(cSizeA + tangentA - 1) % cSizeA]]) > 0){
            tangentA = (cSizeA + tangentA - 1) % cSizeA;
            repeat = true;
        }
    }
    
    return {convexA[tangentA], convexB[tangentB]};
}

void sortPolygon(int& n1, Vector2*& polygon1, int& n2, Vector2*& polygon2){
    int rightMost1 = rightMost(n1, polygon1);
    int leftMost2 = leftMost(n2, polygon2);
    if(polygon2[leftMost2] < polygon1[rightMost1]) {
        std::swap(polygon1, polygon2);
        std::swap(n1, n2);
    }
}


int main(void){
#ifndef ONLINE_JUDGE
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    std::istream& in = fin;
    std::ostream& out = fout;
#else
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#endif

    int t;
    in >> t;

    while(t--){
        int n1, n2;
        in >> n1;
        for(int i = 0; i < n1; ++i) in >> polygon1[i].x >> polygon1[i].y;
        in >> n2;
        for(int i = 0; i < n2; ++i) in >> polygon2[i].x >> polygon2[i].y;

        // Sort polygon
        Vector2 *pPolygon1 = polygon1, *pPolygon2 = polygon2;
        sortPolygon(n1, pPolygon1, n2, pPolygon2);
        // Make Convex Hull
        int c1, c2;
        c1 = getConvexHull(n1, pPolygon1, convex1);
        c2 = getConvexHull(n2, pPolygon2, convex2);
        // Get Tangent
        auto upperTangent = getUpperTangent(n1, pPolygon1, c1, convex1, n2, pPolygon2, c2, convex2);
        auto lowerTangent = getLowerTangent(n1, pPolygon1, c1, convex1, n2, pPolygon2, c2, convex2);
        // Get Area
        int k = 0;
        int i, e;

        i = upperTangent.first, e = lowerTangent.first;
        inner[k++] = pPolygon1[i];
        i = (n1 + i - 1) % n1;
        while(true){
            inner[k++] = pPolygon1[i];
            if(i == e) break;
            i = (n1 + i - 1) % n1;
        }

        i = lowerTangent.second, e = upperTangent.second;
        inner[k++] = pPolygon2[i];
        i = (n2 + i - 1) % n2;
        while(true){
            inner[k++] = pPolygon2[i];
            if(i == e) break;
            i = (n2 + i - 1) % n2;
        }

        ll area = getDoubledArea(k, inner);
        out << area / 2 << (area % 2 ? ".5\n" : ".0\n");
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}