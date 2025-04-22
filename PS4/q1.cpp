#include <iostream>

class Vector2D {
	private:
		int x;
		int y;

	public:
		Vector2D();
		Vector2D(int new_x, int new_y);
		int GetX() const{
			return x;
		}
		int GetY() const{
			return y;
		}
		void setXY(int new_x, int new_y);
		int operator*(const Vector2D &v2);
};

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(int new_x, int new_y) : x(new_x), y(new_y) {}

void Vector2D::setXY(int new_x, int new_y){
	x = new_x;
	y = new_y;
}

int Vector2D::operator*(const Vector2D &v2){
	return (x * v2.x) + (y * v2.y);
}


int main()
{
	Vector2D v1(10, 0), v2(0, 10), v3(10, 10), v4(5, 4);

	std::cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX()
			<< "," << v2.GetY() << ") = " << v1 * v2 << std::endl; 
	std::cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX()
			<< "," << v3.GetY() << ") = " << v2 * v3 << std::endl;
	std::cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX()
			<< "," << v4.GetY() << ") = " << v3 * v4 << std::endl;  
	return 0;
}
