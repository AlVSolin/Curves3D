#include "classes.h"

#include <iostream>
#include <memory>
#include <random>
#include <vector>

bool compareCirclesByRadius(std::shared_ptr<Curve3DCircle> c1, std::shared_ptr<Curve3DCircle> c2);

int main() {
	const int numOfCurves = 100;
	const double random_max_number = static_cast<double>(RAND_MAX);
	double sumOfR = 0.0;

	std::vector<std::shared_ptr<Curve3D>> curves(numOfCurves);
	std::vector<std::shared_ptr<Curve3DCircle>> circles;
	circles.reserve(numOfCurves);

	std::srand(std::time(0));

	// �������� ����, � ������� ��������� ������, ����������� � ��������� �� ����� ����������� �������� � ����������� ����������� ������ ����������� circles.
	for (int i = 0; i < numOfCurves; ++i) {

		int random_number = std::rand();
		const double t = M_PI / 4;

		// �������������� ������ �� ���������� �����������.
		if (random_number % 3 == 0) {
			double r = 0.1 + std::rand() / random_max_number * (10.0 - 0.1);
			curves[i] = std::make_shared<Curve3DCircle>(r);
		}
		else if (random_number % 3 == 1) {
			double a = 0.1 + std::rand() / random_max_number * (10.0 - 0.1);
			double b = 0.1 + std::rand() / random_max_number * (10.0 - 0.1);
			curves[i] = std::make_shared<Curve3DEllipse>(a, b);
		}
		else if (random_number % 3 == 2) {
			double r = 0.1 + std::rand() / random_max_number * (10.0 - 0.1);
			double s = 0.1 + std::rand() / random_max_number * (10.0 - 0.1);
			curves[i] = std::make_shared<Curve3DHelix>(r, s);
		}

		// ������� ��� ������ ������ � ���, �������� ��������� � ����������� ��� ��������� ���� t.
		std::cout << "Curve " << i << " is " << curves[i]->getType() << ".\n";
		std::cout << "Its value at the point t = " << t << " is equal to \t" << curves[i]->getx(t) << " " << curves[i]->gety(t) << " " << curves[i]->getz(t) << "\n";
		std::cout << "Its derivative at the point" << " is equal to \t\t" << curves[i]->getdx(t) << " " << curves[i]->getdy(t) << " " << curves[i]->getdz(t) << "\n";

		// ��������� ������ ������, �������� �� ��� �����������, � ��������� � � ������ circles �� �������������.
		if (curves[i]->getType() == "circle") {

			circles.push_back(std::dynamic_pointer_cast<Curve3DCircle>(curves[i]));
			sumOfR += std::dynamic_pointer_cast<Curve3DCircle>(curves[i])->getR();
		}

	}

	// ������� �� ����� ����� �������� ���� �����������.
	std::cout << "\nSum of radii is equals to " << sumOfR << "\n";

	// ��������� ������ circles � ������� ������� ��� �������������� ��������� �� �������.
	std::sort(circles.begin(), circles.end(), compareCirclesByRadius);
	for (const auto c : circles) {
		std::cout << c->getR() << " ";
	}

	// ��������� ������ ������� main.
	return(0);
}




bool compareCirclesByRadius(const std::shared_ptr<Curve3DCircle> c1, const std::shared_ptr<Curve3DCircle> c2) {
	return (c1->getR() < c2->getR());
}