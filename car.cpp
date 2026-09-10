#include "Car.h"
#include <cstdlib>
#include <ctime>
#include <set>
#include <algorithm>

// ---------- вспомогательное ----------
bool Car::isValidGosNumber(const str& number) {
    if (number.length() != 6) return false;
    str letters = "QWERTYUIOPASDFGHJKLZXCVBNMАБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЫЮЯ";
    str digits = "0123456789";
    return letters.find(number[0]) != str::npos &&
        digits.find(number[1]) != str::npos &&
        digits.find(number[2]) != str::npos &&
        digits.find(number[3]) != str::npos &&
        letters.find(number[4]) != str::npos &&
        letters.find(number[5]) != str::npos;
}

str Car::generateRandomGosNumber(const std::vector<str>& forbidden) {
    static const str letters = "QWERTYUIOPASDFGHJKLZXCVBNMАБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЫЮЯ";
    str result;
    do {
        result.clear();
        result += letters[rand() % letters.size()];
        for (int i = 0; i < 3; ++i) result += char('0' + rand() % 10);
        result += letters[rand() % letters.size()];
        result += letters[rand() % letters.size()];
    } while (std::find(forbidden.begin(), forbidden.end(), result) != forbidden.end());
    return result;
}

// ---------- конструкторы ----------
Car::Car() {
    car_name_ = "Default name";
    car_model_ = "Default model";
    Gos_number_ = "A000AA";
    trunk_ = {};
    std::cerr << "ctor default" << std::endl;
}

Car::Car(str name, str model, str gos, const std::vector<str>& things)
    : car_name_(name), car_model_(model), Gos_number_(gos), trunk_(things) {
    if (!isValidGosNumber(Gos_number_)) {
        throw str("Invalid GOS number: must be A000AA");
    }
    std::cerr << "ctor param" << std::endl;
}

Car::Car(const Car& other)
    : car_name_(other.car_name_),
    car_model_(other.car_model_),
    Gos_number_(other.Gos_number_),
    trunk_(other.trunk_) {
    std::cerr << "ctor copy" << std::endl;
}

Car& Car::operator=(const Car& other) {
    if (this == &other) return *this;
    car_name_ = other.car_name_;
    car_model_ = other.car_model_;
    Gos_number_ = other.Gos_number_;
    trunk_ = other.trunk_;
    std::cerr << "operator=" << std::endl;
    return *this;
}

Car::~Car() {
    trunk_.clear();               // обязательно по заданию
    trunk_.shrink_to_fit();
    std::cerr << "dtor" << std::endl;
}

// ---------- геттеры ----------
str Car::get_car_name()   const { return car_name_; }
str Car::get_car_model()  const { return car_model_; }
str Car::get_GOS_number() const { return Gos_number_; }
std::vector<str> Car::get_trunk() const { return trunk_; }

// ---------- сеттеры ----------
void Car::set_GOS_number(const str& number) {
    if (!isValidGosNumber(number)) {
        throw str("Gos number must be: A000AA (length 6)");
    }
    Gos_number_ = number;
}

void Car::set_trunk(const std::vector<str>& things) {
    trunk_ = things;
}

// ---------- вывод ----------
void Car::print_info() const {
    std::cout << "=============" << std::endl;
    std::cout << "Car info" << std::endl;
    std::cout << "Car name:   " << car_name_ << std::endl;
    std::cout << "Car model:  " << car_model_ << std::endl;
    std::cout << "GOS number: " << Gos_number_ << std::endl;
    std::cout << "Trunk: ";
    for (const auto& t : trunk_) std::cout << t << " ";
    std::cout << std::endl;
    std::cout << "=============" << std::endl;
}

// ---------- операторы ----------
// + : все вещи, повторы рядом
Car Car::operator+(const Car& other) const {
    Car result;
    result.car_name_ = (car_name_ == other.car_name_)
        ? car_name_
        : car_name_ + " или " + other.car_name_;
    result.car_model_ = car_model_;   // на своё усмотрение
    result.Gos_number_ = generateRandomGosNumber({ Gos_number_, other.Gos_number_ });

    result.trunk_ = trunk_;
    result.trunk_.insert(result.trunk_.end(),
        other.trunk_.begin(),
        other.trunk_.end());  // повторы "рядом"
    return result;
}

// - : только уникальные
Car Car::operator-(const Car& other) const {
    Car result;
    result.car_name_ = (car_name_ == other.car_name_)
        ? car_name_
        : car_name_ + " или " + other.car_name_;
    result.car_model_ = car_model_;
    result.Gos_number_ = generateRandomGosNumber({ Gos_number_, other.Gos_number_ });

    std::vector<str> all = trunk_;
    all.insert(all.end(), other.trunk_.begin(), other.trunk_.end());

    for (const auto& item : all) {
        if (std::find(result.trunk_.begin(), result.trunk_.end(), item)
            == result.trunk_.end()) {
            result.trunk_.push_back(item);
        }
    }
    return result;
}

// / : общие вещи
Car Car::operator/(const Car& other) const {
    Car result;
    result.car_name_ = (car_name_ == other.car_name_)
        ? car_name_
        : car_name_ + " или " + other.car_name_;
    result.car_model_ = car_model_;
    result.Gos_number_ = generateRandomGosNumber({ Gos_number_, other.Gos_number_ });

    for (const auto& item : trunk_) {
        bool inOther = std::find(other.trunk_.begin(), other.trunk_.end(), item)
            != other.trunk_.end();
        bool inResult = std::find(result.trunk_.begin(), result.trunk_.end(), item)
            != result.trunk_.end();
        if (inOther && !inResult) result.trunk_.push_back(item);
    }
    return result;
}
