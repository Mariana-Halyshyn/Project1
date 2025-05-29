#include "DeviceContainer.h"
#include "DeviceIterator.h"
#include <fstream>
#include <sstream>
#include <iostream>

// DeviceContainer methods
void DeviceContainer::addDevice(const DisplayDevice& device) {
    devices_.push_back(device);
}

size_t DeviceContainer::size() const {
    return devices_.size();
}

DisplayDevice& DeviceContainer::operator[](size_t index) {
    return devices_.at(index);
}

const DisplayDevice& DeviceContainer::operator[](size_t index) const {
    return devices_.at(index);
}

DeviceIterator DeviceContainer::begin() {
    return DeviceIterator(&devices_, 0);
}

DeviceIterator DeviceContainer::end() {
    return DeviceIterator(&devices_, devices_.size());
}

void DeviceContainer::readFromFile(const std::string& filename) {
    devices_.clear();
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Не вдалося відкрити файл: " << filename << std::endl;
        return;
    }
    std::string line;
    while (getline(fin, line)) {
        std::istringstream iss(line);
        std::string name, interface;
        double power, weight, diagonal;
        int resolution;

        // Формат файлу: Ім'я Інтерфейс Потужність Вага Діагональ Роздільна здатність
        iss >> name >> interface >> power >> weight >> diagonal >> resolution;
        if (!iss.fail()) {
            // filename для deviceX.txt згенеруємо пізніше
            std::string infoFile = "device" + std::to_string(devices_.size() + 1) + ".txt";
            DisplayDevice device(name, interface, power, weight, diagonal, resolution, infoFile);
            devices_.push_back(device);
        }
    }
    fin.close();
}

void DeviceContainer::writeToFile(const std::string& filename) {
    std::ofstream fout(filename, std::ios::trunc);
    if (!fout) {
        std::cerr << "Не вдалося відкрити файл для запису: " << filename << std::endl;
        return;
    }
    for (size_t i = 0; i < devices_.size(); ++i) {
        // Пишемо у форматі: Ім'я Інтерфейс Потужність Вага Діагональ Роздільна здатність
        DisplayDevice& d = devices_[i];
        fout << d.getInterface() << " "
            << d.getPower() << " "
            << d.getWeight() << " "
            << d.getDiagonal() << " "
            << d.getResolution() << std::endl;
    }
    fout.close();
}

void DeviceContainer::showAllDevices() const {
    for (size_t i = 0; i < devices_.size(); ++i) {
        std::cout << i + 1 << ". ";
        std::cout << devices_[i] << std::endl;
    }
}
