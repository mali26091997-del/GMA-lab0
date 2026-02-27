#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <set>
#include <unordered_set>

using str = std::string;

class Car {
private:
    str car_number_;      // номер кузова
    str Gos_number_;      // гос номер
    int mileage_;         // пробег
    std::vector<str> items_;  // вещи в багажнике

protected:
    str car_name_;
    str car_model_;

    // Вспомогательные методы для генерации госномера
    static str generateRandomPlate();
    static bool isPlateUnique(const str& plate, const Car& other1, const Car& other2);

public:
    // Конструкторы
    Car();
    Car(str car_name, str car_model, str body_number, str GOS_number, int mileage,
        const std::vector<str>& items = {});
    Car(const Car& other); // копирующий конструктор

    // Деструктор
    ~Car();

    // Оператор присваивания
    Car& operator=(const Car& other);

    // Перегруженные операторы
    Car operator+(const Car& other) const;  // объединение с повторами
    Car operator-(const Car& other) const;  // объединение уникальных
    Car operator/(const Car& other) const;  // пересечение

    // Сеттеры
    void set_car_number_(str number);
    void set_GOS_number_(str number);

    // Геттеры
    str get_car_name_() const;
    str get_car_model_() const;
    str get_car_number_() const;
    str get_GOS_number_() const;
    int get_mileage_() const;
    const std::vector<str>& get_items() const;

    // Методы
    void twisting_mileage(int miles);
    void print_info() const;
    void add_item(const str& item);  // добавить вещь в багажник

    // Дружественная функция для вывода
    friend std::ostream& operator<<(std::ostream& os, const Car& car);
};
#endif