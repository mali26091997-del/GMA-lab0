#pragma once
#include <iostream>
#include <string>
#include <vector>

using str = std::string;

class Car {
private:
    str car_name_;                  // марка
    str car_model_;                 // модель
    str Gos_number_;                // гос. номер
    std::vector<str> trunk_;        // вещи в багажнике (дин. поле)

    // вспомогательная валидация
    static bool isValidGosNumber(const str& number);

public:
    // --- конструкторы / деструктор (правило трёх) ---
    Car();
    Car(str name, str model, str gos, const std::vector<str>& things);
    Car(const Car& other);                    // копирования
    Car& operator=(const Car& other);         // присваивания
    ~Car();

    // --- геттеры ---
    str get_car_name()   const;
    str get_car_model()  const;
    str get_GOS_number() const;
    std::vector<str> get_trunk() const;

    // --- сеттеры ---
    void set_GOS_number(const str& number);
    void set_trunk(const std::vector<str>& things);

    // --- служебное ---
    void print_info() const;
    static str generateRandomGosNumber(const std::vector<str>& forbidden);

    // --- операторы варианта 2 ---
    Car operator+(const Car& other) const;   // все вещи, повторы рядом
    Car operator-(const Car& other) const;   // только уникальные
    Car operator/(const Car& other) const;   // общие
};

