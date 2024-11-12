#include <stdio.h>
#include <math.h>

class Field {
protected:
	double* value;
public:
	Field() {
		value = new double[3] {0.0, 0.0, 0.0};
	}

	Field(double a, double b, double c) {
		value = new double[3] {a, b, c};
	}

	~Field() {
		delete[](value);
	}

	double calculateMagnitude() {
		return sqrt(value[0] * value[0] + value[1] * value[1] + value[2] + value[2]);

	};

	void printMagnitude() {
		printf("%e\n", calculateMagnitude());
	}
};

class Electric_Field: public Field {
private:
    double E;
public:
	Electric_Field() : Field() {}

    Electric_Field(double d, double e, double f) : Field (d, e, f) {}

    double getd() const { return value[0]; }
    double gete() const { return value[1]; }
    double getf() const { return value[2]; }

    void electric_setter(double d, double e, double f) {
        value[0] = d;
        value[1] = e;
        value[2] = f;
    }

    double calculateMagnitude() {
        return sqrt(value[0] * value[0] + value[1] * value[1] + value[2] + value[2]);
    }

    void calculateElectric(double Q, double r) {
        double e0 = 8.854e-12;
        E = Q / (4 * 3.141592 * pow(r, 2) * e0);

        printf("%e\n", E);
    }

    Electric_Field operator+(const Electric_Field& other) { 
        return Electric_Field(value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2]);
    }
    
    void print() {
        printf("(%e, %e, %e)\n", value[0], value[1], value[2]);
    }
};

class Magnetic_Field : Field {
private:
    double M;
public:
    Magnetic_Field() : Field() {}

    Magnetic_Field(double x, double y, double z) : Field(x, y, z) {}

    double getx() const { return value[0]; }
    double gety() const { return value[1]; }
    double getz() const { return value[2]; }

    void magnetic_setter(double x, double y, double z) {
        value[0] = x;
        value[1] = y;
        value[2] = z;
    }

    double calculateMagnitude() {
        return sqrt(value[0] * value[0] + value[1] * value[1] + value[2] + value[2]);
    }

    void calculateMagnetic(double I, double r) {
        double u0 = 4 * 3.141592 * 1e-7;
        M = I / (2 * 3.142592 * r * u0);

        printf("%e\n", M);
    }

    Magnetic_Field operator+(const Magnetic_Field& other) {
        return Magnetic_Field(value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2]);
    }

    void print() {
        printf("(%e, %e, %e)\n", value[0], value[1], value[2]);
    }
};

int main() {
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);
    Magnetic_Field M_default;
    Magnetic_Field M_components(2.0, 4.0, 6.0);

    E_default.electric_setter(1.0, 3.0, 5.0);
    M_default.magnetic_setter(1.0, 0.0, 0.0);

    printf("Magnitudes:\n");
    printf("Default Electric: %e\n", E_default.calculateMagnitude());
    printf("Electric with Components: %e\n", E_components.calculateMagnitude());
    printf("Default Magnetic: %e\n", M_default.calculateMagnitude());
    printf("Magnetic with Components: %e\n", M_components.calculateMagnitude());

    printf("\nCalculated Electric/Magnetic Fields:\n");
    printf("Electric: ");
    E_components.calculateElectric(1e-6, 0.1);
    printf("Magnetic: ");
    M_components.calculateMagnetic(10, 0.05);

    printf("\nOperator Overloads:\n");
    printf("+ Operator:\n");
    Electric_Field E_sum = E_default + E_components;
    printf("Electric Field Sum: ");
    E_sum.print();
    Magnetic_Field M_sum = M_default + M_components;
    printf("Magnetic Field Sum: ");
    M_sum.print();

    printf("<< Operator:\n");
    printf("Electric with Components: ");
    E_components.print();
    printf("Magnetic with Components: ");
    M_components.print();

	return 0;
}
