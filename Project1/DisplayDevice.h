#ifndef DISPLAY_DEVICE_H
#define DISPLAY_DEVICE_H

#include "ElectronicDevice.h"

class DisplayDevice : public ElectronicDevice {
    double diagonal_;
    int resolution_;
    std::string infoFile_;

public:
    DisplayDevice();
    DisplayDevice(const std::string& name, const std::string& interface, double power, double weight,
        double diagonal, int resolution, const std::string& infoFile);

    void setDiagonal(double diagonal);
    void setResolution(int resolution);
    void setInfoFile(const std::string& filename);

    double getDiagonal() const;
    int getResolution() const;
    std::string getInfoFile() const;

    void showMainInfo() const override;

    friend std::istream& operator>>(std::istream& in, DisplayDevice& device);
    friend std::ostream& operator<<(std::ostream& out, const DisplayDevice& device);
};

#endif