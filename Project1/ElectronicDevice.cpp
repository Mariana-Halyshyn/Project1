#include "ElectronicDevice.h"

ElectronicDevice::ElectronicDevice()
    : name_(""), interface_(""), power_(0), weight_(0) {}

ElectronicDevice::ElectronicDevice(const std::string& name, const std::string& interface, double power, double weight)
    : name_(name), interface_(interface), power_(power), weight_(weight) {}

ElectronicDevice::ElectronicDevice(const ElectronicDevice& other)
    : name_(other.name_), interface_(other.interface_), power_(other.power_), weight_(other.weight_) {}

ElectronicDevice::ElectronicDevice(ElectronicDevice&& other) noexcept
    : name_(std::move(other.name_)), interface_(std::move(other.interface_)),
    power_(other.power_), weight_(other.weight_) {}

ElectronicDevice::~ElectronicDevice() {}

ElectronicDevice& ElectronicDevice::operator=(const ElectronicDevice& other) {
    if (this != &other) {
        name_ = other.name_;
        interface_ = other.interface_;
        power_ = other.power_;
        weight_ = other.weight_;
    }
    return *this;
}

ElectronicDevice& ElectronicDevice::operator=(ElectronicDevice&& other) noexcept {
    if (this != &other) {
        name_ = std::move(other.name_);
        interface_ = std::move(other.interface_);
        power_ = other.power_;
        weight_ = other.weight_;
    }
    return *this;
}

void ElectronicDevice::setName(const std::string& name) { name_ = name; }
void ElectronicDevice::setInterface(const std::string& interface) { interface_ = interface; }
void ElectronicDevice::setPower(double power) { power_ = power; }
void ElectronicDevice::setWeight(double weight) { weight_ = weight; }

std::string ElectronicDevice::getName() const { return name_; }
std::string ElectronicDevice::getInterface() const { return interface_; }
double ElectronicDevice::getPower() const { return power_; }
double ElectronicDevice::getWeight() const { return weight_; }

void ElectronicDevice::showMainInfo() const {
    std::cout << "Потужність: " << power_ << " Вт" << std::endl;
}

std::istream& operator>>(std::istream& in, ElectronicDevice& device) {
    in >> device.name_ >> device.interface_ >> device.power_ >> device.weight_;
    return in;
}

std::ostream& operator<<(std::ostream& out, const ElectronicDevice& device) {
    out << device.name_ << " " << device.interface_ << " " << device.power_ << " " << device.weight_;
    return out;
}