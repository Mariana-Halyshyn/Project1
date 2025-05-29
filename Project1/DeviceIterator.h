#pragma once
#include "DisplayDevice.h"
#include <vector>

class DeviceContainer;

class DeviceIterator {
private:
    std::vector<DisplayDevice>* devices_;
    size_t index_;
public:
    DeviceIterator(std::vector<DisplayDevice>* devices, size_t index = 0);
    DisplayDevice& operator*();
    DeviceIterator& operator++();
    bool operator!=(const DeviceIterator& other) const;
};
