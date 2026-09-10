#include "Car.h"
#include <iostream>
#include <ctime>

int main() {
    setlocale(LC_ALL, "Russian");

    srand(static_cast<unsigned>(time(nullptr)));

    try {
        // исходные машины из примера варианта
        Car carA("А", "модель1", "А777АА", {"а", "б", "в"});
        Car carB("Б", "модель2", "Б777ББ", {"в", "т", "к"});

        std::cout << "Исходные машины:" << std::endl;
        carA.print_info();
        carB.print_info();

        std::cout << "\n--- Оператор + (все, повторы) ---" << std::endl;
        Car plus = carA + carB;
        plus.print_info();

        std::cout << "\n--- Оператор - (уникальные вещи) ---" << std::endl;
        Car minus = carA - carB;
        minus.print_info();

        std::cout << "\n--- Оператор / (общие вещи) ---" << std::endl;
        Car div = carA / carB;
        div.print_info();
    }
    catch (str error) {
        std::cerr << "Error: " << error << std::endl;
    }

    return 0;
}