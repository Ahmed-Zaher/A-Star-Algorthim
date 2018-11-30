template<class T>
class Point {
public:
	T x, y;
	Point() {
		x = y = 0;
	}
	Point(T _x, T _y) :
			x(_x), y(_y) {
	}
	double dist(Point P) {
		return hypot(P.x - x, P.y - y);
	}
};
