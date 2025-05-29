#pragma once
#include <string>
#ifndef ELECTRONIC_DEVICE_H
#define ELECTRONIC_DEVICE_H

#include <string>
#include <iostream>

class ElectronicDevice {
protected:
    std::string name_;
    std::string interface_;
    double power_;
    double weight_;

public:
    ElectronicDevice();
    ElectronicDevice(const std::string& name, const std::string& interface, double power, double weight);
    ElectronicDevice(const ElectronicDevice& other);
    ElectronicDevice(ElectronicDevice&& other) noexcept;
    virtual ~ElectronicDevice();

    ElectronicDevice& operator=(const ElectronicDevice& other);
    ElectronicDevice& operator=(ElectronicDevice&& other) noexcept;

    void setName(const std::string& name);
    void setInterface(const std::string& interface);
    void setPower(double power);
    void setWeight(double weight);

    std::string getName() const;
    std::string getInterface() const;
    double getPower() const;
    double getWeight() const;

    virtual void showMainInfo() const;

    friend std::istream& operator>>(std::istream& in, ElectronicDevice& device);
    friend std::ostream& operator<<(std::ostream& out, const ElectronicDevice& device);
};

#endif