// 문제해결기법 - 12

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>

//#define ONLINE_JUDGE

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

    ll x = 0, y = 0;
};

// === Vector operation ===
// arithmetic
Vector2 operator+(const Vector2& lhs, const Vector2& rhs) { return { lhs.x + rhs.x, lhs.y + rhs.y }; }
Vector2 operator-(const Vector2& lhs, const Vector2& rhs) { return { lhs.x - rhs.x, lhs.y - rhs.y }; }
Vector2 operator*(int scalar, const Vector2& vector) { return { scalar * vector.x, scalar * vector.y }; }
Vector2 operator*(const Vector2& vector, int scalar) { return scalar * vector; }

Vector2& operator+=(Vector2& lhs, const Vector2& rhs) { lhs.x += rhs.x; lhs.y += rhs.y;  return lhs; }
Vector2& operator-=(Vector2& lhs, const Vector2& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y;  return lhs; }
Vector2& operator*=(Vector2& vector, int scalar) { vector.x *= scalar; vector.y *= scalar;  return vector; }
// compare
bool compareX(const Vector2& lhs, const Vector2& rhs) { return (lhs.x != rhs.x) ? lhs.x < rhs.x : lhs.y < rhs.y; }
bool compareY(const Vector2& lhs, const Vector2& rhs) { return (lhs.y != rhs.y) ? lhs.y < rhs.y : lhs.x < rhs.x; }
// product
inline Vector2 dot(const Vector2& v, const Vector2& u) { return { v.x * u.x, v.y * u.y }; }
inline Vector2 dot(const Vector2& p1, const Vector2& p2, const Vector2& p3) { return dot(p2 - p1, p3 - p1); }
inline ll cross(const Vector2& v, const Vector2& u) { return v.x * u.y - u.x * v.y; }
inline ll cross(const Vector2& p1, const Vector2& p2, const Vector2& p3) { return cross(p2 - p1, p3 - p1); }
inline int direction(const Vector2& v, const Vector2& u) { ll ret = cross(v, u);  return (ret == 0) ? 0 : (ret < 0 ? -1 : 1); }
inline int direction(const Vector2& p1, const Vector2& p2, const Vector2& p3) { return direction(p2 - p1, p3 - p1); }
// absoulte
inline ll sqrNorm(const Vector2& p) { return p.x * p.x + p.y * p.y; }
inline ll sqrDist(const Vector2& p1, const Vector2& p2) { return sqrNorm(p2 - p1); }

// === Polygon operation ===
inline int leftMost(int n, const Vector2* points) { return std::min_element(points, points + n, compareX) - points; }
inline int rightMost(int n, const Vector2* points) { return std::max_element(points, points + n, compareX) - points; }
inline int bottomMost(int n, const Vector2* points) { return std::min_element(points, points + n, compareY) - points; }
inline int topMost(int n, const Vector2* points) { return std::max_element(points, points + n, compareY) - points; }

ll getDoubledArea(int n, Vector2* points){
    ll sum = 0LL;
    const Vector2& origin = points[0];
    for(int i = 2; i < n; ++i) {
        sum += cross(origin, points[i - 1], points[i]);
    }
    return std::abs(sum);
}

// javis march
int getConvexHull(int n, const Vector2* points, int* out_convex){ 
    int start = leftMost(n, points);
    int prev = start;
    int next = -1;
    
    int k = 0;
    while(next != start){
        out_convex[k++] = prev;

        next = (prev + 1) % n;
        for(int  i = 0; i < n; ++i){
            if(i != prev && i != next){
                int ccw = direction(points[prev], points[next], points[i]);
                if(ccw < 0 || (ccw == 0 && sqrDist(points[prev], points[next]) < sqrDist(points[prev], points[i])) ){
                    next = i;
                }
            }
        }
        prev = next;
    }
    return k;
}

// === multiple polygon operation ===
// compare
bool comparePolygonX(int n1, const Vector2* polygon1, int n2, const Vector2* polygon2){
    return compareX(polygon1[leftMost(n1, polygon1)], polygon2[leftMost(n2, polygon2)]);
}
bool comparePolygonY(int n1, const Vector2* polygon1, int n2, const Vector2* polygon2){
    return compareY(polygon1[bottomMost(n1, polygon1)], polygon2[bottomMost(n2, polygon2)]);
}

// tangent
pii getUpperTangent(Vector2* polygon1, int c1, int* convex1,
    Vector2* polygon2, int c2, int* convex2){
    
    int rightMost1 = 0, leftMost2 = 0;
    for(int i = 1; i < c1; ++i){
        if(compareX(polygon1[convex1[rightMost1]], polygon1[convex1[i]]) ) rightMost1 = i;
    }
    for(int i = 1; i < c2; ++i){
        if(compareX(polygon2[convex2[i]], polygon2[convex2[leftMost2]]) ) leftMost2 = i;
    }
    
    int tangent1 = rightMost1, tangent2 = leftMost2;

    bool repeat = true;
    while(repeat){
        repeat = false;
        while(true){
            const Vector2 &p1 = polygon1[convex1[tangent1]], &p2 = polygon2[convex2[tangent2]], &p3 = polygon2[convex2[(c2 + tangent2 - 1) % c2]];
            int ccw = direction(p1, p2, p3);
            //if(ccw > 0 || (ccw == 0 && sqrDist(p1, p2) > sqrDist(p1, p3))){
            if(ccw > 0){
                tangent2 = (c2 + tangent2 - 1) % c2;
                continue;
            }
            break;
        }
        while(true){
            const Vector2 &p1 = polygon2[convex2[tangent2]], &p2 = polygon1[convex1[tangent1]], &p3 = polygon1[convex1[(tangent1 + 1) % c1]];
            int ccw = direction(p1, p2, p3);
            //if(ccw < 0 || (ccw == 0 && sqrDist(p1, p2) > sqrDist(p1, p3))){
            if(ccw < 0){
                tangent1 = (tangent1 + 1) % c1;
                repeat = true;
                continue;
            }
            break;
        }

        // while(direction(polygon1[convex1[tangent1]], polygon2[convex2[tangent2]], polygon2[convex2[(c2 + tangent2 - 1) % c2]]) > 0){
        //     tangent2 = (c2 + tangent2 - 1) % c2;
        // }
        // while(direction(polygon2[convex2[tangent2]], polygon1[convex1[tangent1]], polygon1[convex1[(tangent1 + 1) % c1]]) < 0){
        //     tangent1 = (tangent1 + 1) % c1;
        //     repeat = true;
        // }
    }
    
    return {convex1[tangent1], convex2[tangent2]};
}
pii getLowerTangent(Vector2* polygon1, int c1, int* convex1,
    Vector2* polygon2, int c2, int* convex2){
    
    int rightMost1 = 0, leftMost2 = 0;
    for(int i = 1; i < c1; ++i){
        if(compareX(polygon1[convex1[rightMost1]], polygon1[convex1[i]]) ) rightMost1 = i;
    }
    for(int i = 1; i < c2; ++i){
        if(compareX(polygon2[convex2[i]], polygon2[convex2[leftMost2]]) ) leftMost2 = i;
    }

    int tangent1 = rightMost1, tangent2 = leftMost2;

    bool repeat = true;
    while(repeat){
        repeat = false;
        while(true){
            const Vector2 &p1 = polygon1[convex1[tangent1]], &p2 = polygon2[convex2[tangent2]], &p3 = polygon2[convex2[(tangent2 + 1) % c2]];
            int ccw = direction(p1, p2, p3);
            //if(ccw < 0 || (ccw == 0 && sqrDist(p1, p2) > sqrDist(p1, p3))){
            if(ccw < 0){
                tangent2 = (tangent2 + 1) % c2;
                continue;
            }
            break;
        }
        while(true){
            const Vector2 &p1 = polygon2[convex2[tangent2]], &p2 = polygon1[convex1[tangent1]], &p3 = polygon1[convex1[(c1 + tangent1 - 1) % c1]];
            int ccw = direction(p1, p2, p3);
            //if(ccw > 0 || (ccw == 0 && sqrDist(p1, p2) > sqrDist(p1, p3))){
            if(ccw > 0){
                tangent1 = (c1 + tangent1 - 1) % c1;
                repeat = true;
                continue;
            }
            break;
        }

        // while(direction(polygon1[convex1[tangent1]], polygon2[convex2[tangent2]], polygon2[convex2[(tangent2 + 1) % c2]]) < 0){
        //     tangent2 = (tangent2 + 1) % c2;
        // }
        // while(direction(polygon2[convex2[tangent2]], polygon1[convex1[tangent1]], polygon1[convex1[(c1 + tangent1 - 1) % c1]]) > 0){
        //     tangent1 = (c1 + tangent1 - 1) % c1;
        //     repeat = true;
        // }
    }
    
    return {convex1[tangent1], convex2[tangent2]};
}
pii getLeftTangent(Vector2* polygon1, int c1, int* convex1,
    Vector2* polygon2, int c2, int* convex2){
    
    int topMost1 = 0, bottomMost2 = 0;
    for(int i = 1; i < c1; ++i){
        if(compareY(polygon1[convex1[topMost1]], polygon1[convex1[i]]) ) topMost1 = i;
    }
    for(int i = 1; i < c2; ++i){
        if(compareY(polygon2[convex2[i]], polygon2[convex2[bottomMost2]]) ) bottomMost2 = i;
    }
    
    int tangent1 = topMost1, tangent2 = bottomMost2;

    bool repeat = true;
    while(repeat){
        repeat = false;
        while(true){
            const Vector2 &p1 = polygon1[convex1[tangent1]], &p2 = polygon2[convex2[tangent2]], &p3 = polygon2[convex2[(c2 + tangent2 - 1) % c2]];
            int ccw = direction(p1, p2, p3);
            //if(ccw > 0 || (ccw == 0 && sqrDist(p1, p2) > sqrDist(p1, p3))){
            if(ccw > 0){
                tangent2 = (c2 + tangent2 - 1) % c2;
                continue;
            }
            break;
        }
        while(true){
            const Vector2 &p1 = polygon2[convex2[tangent2]], &p2 = polygon1[convex1[tangent1]], &p3 = polygon1[convex1[(tangent1 + 1) % c1]];
            int ccw = direction(p1, p2, p3);
            //if(ccw < 0 || (ccw == 0 && sqrDist(p1, p2) > sqrDist(p1, p3))){
            if(ccw < 0){
                tangent1 = (tangent1 + 1) % c1;
                repeat = true;
                continue;
            }
            break;
        }

        // while(direction(polygon1[convex1[tangent1]], polygon2[convex2[tangent2]], polygon2[convex2[(c2 + tangent2 - 1) % c2]]) > 0){
        //     tangent2 = (c2 + tangent2 - 1) % c2;
        // }
        // while(direction(polygon2[convex2[tangent2]], polygon1[convex1[tangent1]], polygon1[convex1[(tangent1 + 1) % c1]]) < 0){
        //     tangent1 = (tangent1 + 1) % c1;
        //     repeat = true;
        // }
    }
    
    return {convex1[tangent1], convex2[tangent2]};
}
pii getRightTangent(Vector2* polygon1, int c1, int* convex1,
    Vector2* polygon2, int c2, int* convex2){
    
    int topMost1 = 0, bottomMost2 = 0;
    for(int i = 1; i < c1; ++i){
        if(compareY(polygon1[convex1[topMost1]], polygon1[convex1[i]]) ) topMost1 = i;
    }
    for(int i = 1; i < c2; ++i){
        if(compareY(polygon2[convex2[i]], polygon2[convex2[bottomMost2]]) ) bottomMost2 = i;
    }

    int tangent1 = topMost1, tangent2 = bottomMost2;

    bool repeat = true;
    while(repeat){
        repeat = false;
        while(true){
            const Vector2 &p1 = polygon1[convex1[tangent1]], &p2 = polygon2[convex2[tangent2]], &p3 = polygon2[convex2[(tangent2 + 1) % c2]];
            int ccw = direction(p1, p2, p3);
            //if(ccw < 0 || (ccw == 0 && sqrDist(p1, p2) > sqrDist(p1, p3))){
            if(ccw < 0){
                tangent2 = (tangent2 + 1) % c2;
                continue;
            }
            break;
        }
        while(true){
            const Vector2 &p1 = polygon2[convex2[tangent2]], &p2 = polygon1[convex1[tangent1]], &p3 = polygon1[convex1[(c1 + tangent1 - 1) % c1]];
            int ccw = direction(p1, p2, p3);
            //if(ccw > 0 || (ccw == 0 && sqrDist(p1, p2) > sqrDist(p1, p3))){
            if(ccw > 0){
                tangent1 = (c1 + tangent1 - 1) % c1;
                repeat = true;
                continue;
            }
            break;
        }

        // while(direction(polygon1[convex1[tangent1]], polygon2[convex2[tangent2]], polygon2[convex2[(tangent2 + 1) % c2]]) < 0){
        //     tangent2 = (tangent2 + 1) % c2;
        // }
        // while(direction(polygon2[convex2[tangent2]], polygon1[convex1[tangent1]], polygon1[convex1[(c1 + tangent1 - 1) % c1]]) > 0){
        //     tangent1 = (c1 + tangent1 - 1) % c1;
        //     repeat = true;
        // }
    }
    
    return {convex1[tangent1], convex2[tangent2]};
}



// constants
constexpr int MAX_N = 100000 + 10;
// variables
Vector2 polygonA[MAX_N], polygonB[MAX_N];
int convexA[MAX_N], convexB[MAX_N];
Vector2 inner[MAX_N * 2];

ll solution(int n1, int n2){
    // init.
    Vector2 *polygon1 = polygonA, *polygon2 = polygonB;
    int *convex1 = convexA, *convex2 = convexB;
    int c1, c2;
    c1 = getConvexHull(n1, polygon1, convex1);
    c2 = getConvexHull(n2, polygon2, convex2);

    // Sort polygon
    Vector2 origin1, origin2;
    for(int i = 0; i < c1; ++i) origin1 += { polygon1[convex1[i]].x, polygon1[convex1[i]].y };
    for(int i = 0; i < c2; ++i) origin2 += { polygon2[convex2[i]].x, polygon2[convex2[i]].y };

    Vector2 delta = origin2 - origin1;

    pii upperTangent, lowerTangent;
    if(delta.x != 0 && std::abs((double)delta.y/ delta.x) <= 1){
        if(delta.x < 0) {
            std::swap(polygon1, polygon2);
            std::swap(n1, n2);
            
            std::swap(convex1, convex2);
            std::swap(c1, c2);
        }
        upperTangent = getUpperTangent(polygon1, c1, convex1, polygon2, c2, convex2);
        lowerTangent = getLowerTangent(polygon1, c1, convex1, polygon2, c2, convex2);
    } else{
        if(delta.y < 0){
            std::swap(polygon1, polygon2);
            std::swap(n1, n2);
            
            std::swap(convex1, convex2);
            std::swap(c1, c2);
        }
        upperTangent = getLeftTangent(polygon1, c1, convex1, polygon2, c2, convex2);
        lowerTangent = getRightTangent(polygon1, c1, convex1, polygon2, c2, convex2);
    }

    // Get Area
    int k = 0;
    int i, e;

    i = upperTangent.first, e = lowerTangent.first;
    inner[k++] = polygon1[i];
    i = (n1 + i - 1) % n1;
    while(true){
        inner[k++] = polygon1[i];
        if(i == e) break;
        i = (n1 + i - 1) % n1;
    }

    i = lowerTangent.second, e = upperTangent.second;
    inner[k++] = polygon2[i];
    i = (n2 + i - 1) % n2;
    while(true){
        inner[k++] = polygon2[i];
        if(i == e) break;
        i = (n2 + i - 1) % n2;
    }
    
    return getDoubledArea(k, inner);
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

    out << std::fixed;
    out.precision(1);
    while(t--){
        // input
        int n1, n2;
        in >> n1;
        for(int i = 0; i < n1; ++i) in >> polygonA[i].x >> polygonA[i].y;
        in >> n2;
        for(int i = 0; i < n2; ++i) in >> polygonB[i].x >> polygonB[i].y;

        ll area = solution(n1, n2);
        //out << area / 2 << (area % 2 ? ".5\n" : ".0\n");
        out << area * 0.5 << '\n';
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}