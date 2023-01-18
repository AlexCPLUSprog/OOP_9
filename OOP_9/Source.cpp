#include <iostream>
#include <string>


template<class T>
class Shape {
public:
	Shape(T width, T height) : _width(width), _height(height) {
		std::cout << "Constructor Shape()" << '\n';
	}

	~Shape() {
		std::cout << "Destructor ~Shape()" << '\n';
	}
	T calculateSquare() {
		return _width * _height;
	}


private:
	T _width;
	T _height;
};

template <class T>
// ����� �������� class Square : protected Shape<T>, ��� protected ����� �������� ����� ����, ��� � private � ������, �� ��� ����� ������������, � ������� �� private 
// ����� �������� class Square : private Shape<T>, ��� private ����� �������� ��, ��� �� �������� �� "��������" ��������� ������ � �������� �� ���� � private
class Square : public Shape<T> {	// ��������� ������������ ��������, ��� ��������� ������ "��������" ��������� ������ "����������"
public:
	Square(T width, T height) : Shape<T>(width, height), _width(width) {
		std::cout << "Constructor Square()" << '\n';
	}

	~Square() {
		std::cout << "Destructor ~Square()" << '\n';
	}

	T calculateSquare() {	// ��������������� ������� � ������ "����������"
		return _width * _width;
	}

private:
	T _width;	
};

// ����� ���������� � �������
// Variatic Templates - ������������ �������
template <typename ... Args>	// Args ������ ��������
// ����� ������ �������, ��������: void f(Args ... args);
// ������� ������:
// f(); - ��, ����� �� �������� ����������
// f(1); - ��, ����� �������� ���� �������� (int)
// f(1, 2.0) - ��, ����� �������� ��� ��������� (int, double)

class MyClass {
public:
	template <typename ... Types>
	void printAll(Types ... args) {
		std::cout << sizeof...(args) << std::endl;
		(std::cout << ... << args) << std::endl;
	}
};

template <typename ... T>
auto sum_all(T ... args) {
	return (args + ...);
}

template <typename ... T>
auto mult_all(T ... args) {
	return (args * ...);
}


// ������������ ��������� �������
int main() {

	/*Square<int> s(5, 4);
	std::cout << s.calculateSquare() << '\n';	// ������� ����� � "������������" �������, ���� �����: s.Shape<int>::calculateSquare()
	*/
	std::cout << sum_all(5,4,2,3,4,5,6) << '\n';
	std::cout << mult_all(5, 4, 2, 5, 6, 7) << "\n===========\n";
	int x = 5;
	double y = 5.6;
	float z = 22.1f;
	std::string str = "Hello world";
	MyClass<int, double, float,std::string> mc;
	mc.printAll(x,y,z,str);



}