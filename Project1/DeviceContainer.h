#pragma once
#include "DisplayDevice.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class DeviceIterator;

class DeviceContainer {
private:
    std::vector<DisplayDevice> devices_;
public:
    DeviceContainer() = default;

    void addDevice(const DisplayDevice& device);
    size_t size() const;

    DisplayDevice& operator[](size_t index);
    const DisplayDevice& operator[](size_t index) const;

    DeviceIterator begin();
    DeviceIterator end();

    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename);

    void showAllDevices() const;
};


