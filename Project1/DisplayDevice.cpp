#include "DisplayDevice.h"

DisplayDevice::DisplayDevice()
    : ElectronicDevice(), diagonal_(0), resolution_(0), infoFile_("") {}

DisplayDevice::DisplayDevice(const std::string& name, const std::string& interface, double power, double weight,
    double diagonal, int resolution, const std::string& infoFile)
    : ElectronicDevice(name, interface, power, weight), diagonal_(diagonal), resolution_(resolution), infoFile_(infoFile) {}

void DisplayDevice::setDiagonal(double diagonal) { diagonal_ = diagonal; }
void DisplayDevice::setResolution(int resolution) { resolution_ = resolution; }
void DisplayDevice::setInfoFile(const std::string& filename) { infoFile_ = filename; }

double DisplayDevice::getDiagonal() const { return diagonal_; }
int DisplayDevice::getResolution() const { return resolution_; }
std::string DisplayDevice::getInfoFile() const { return infoFile_; }

void DisplayDevice::showMainInfo() const {
    std::cout << "Роздільна здатність: " << resolution_ << " пікселів" << std::endl;
}

std::istream& operator>>(std::istream& in, DisplayDevice& device) {
    in >> device.name_ >> device.interface_ >> device.power_ >> device.weight_
        >> device.diagonal_ >> device.resolution_;
    return in;
}

std::ostream& operator<<(std::ostream& out, const DisplayDevice& device) {
    out << device.name_ << " " << device.interface_ << " " << device.power_ << " "
        << device.weight_ << " " << device.diagonal_ << " " << device.resolution_;
    return out;
}