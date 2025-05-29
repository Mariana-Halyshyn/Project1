#include "DeviceIterator.h"

DeviceIterator::DeviceIterator(std::vector<DisplayDevice>* devices, size_t index)
    : devices_(devices), index_(index) {}

DisplayDevice& DeviceIterator::operator*() {
    return devices_->at(index_);
}

DeviceIterator& DeviceIterator::operator++() {
    ++index_;
    return *this;
}

bool DeviceIterator::operator!=(const DeviceIterator& other) const {
    return index_ != other.index_ || devices_ != other.devices_;
}
