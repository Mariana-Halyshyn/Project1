#include "DisplayDevice.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

void loadDevices(std::vector<DisplayDevice>& devices) {
    std::ifstream fin("info.txt");
    if (!fin) return;

    DisplayDevice device;
    while (fin >> device) {
        device.setInfoFile("device" + std::to_string(devices.size() + 1) + ".txt");
        devices.push_back(device);
    }
    fin.close();
}

void saveDevices(const std::vector<DisplayDevice>& devices) {
    std::ofstream fout("info.txt");
    for (const auto& d : devices) {
        fout << d << std::endl;
    }
    fout.close();
}

void showDevices(const std::vector<DisplayDevice>& devices) {
    int i = 1;
    for (const auto& d : devices) {
        std::cout << i++ << ". " << d << std::endl;
    }
}

void addDevice(std::vector<DisplayDevice>& devices) {
    std::string name, interface, fileName, model, os, material, color, description;
    double power, weight, diagonal;
    int resolution, year;

    std::cin.ignore();
    std::cout << "�����: "; std::getline(std::cin, name);
    std::cout << "���������: "; std::getline(std::cin, interface);
    std::cout << "���������: "; std::cin >> power;
    std::cout << "����: "; std::cin >> weight;
    std::cout << "ĳ�������: "; std::cin >> diagonal;
    std::cout << "�������� ��������: "; std::cin >> resolution;
    std::cin.ignore();

    int id = devices.size() + 1;
    fileName = "device" + std::to_string(id) + ".txt";

    std::cout << "����� �����: "; std::getline(std::cin, model);
    std::cout << "г� �������: "; std::cin >> year; std::cin.ignore();
    std::cout << "��: "; std::getline(std::cin, os);
    std::cout << "�������� �������: "; std::getline(std::cin, material);
    std::cout << "����: "; std::getline(std::cin, color);
    std::cout << "�������� ����:\n"; std::getline(std::cin, description);

    std::ofstream info(fileName);
    info << "���������� ��� " << name << ":\n����� �����: " << model
        << "\nг� �������: " << year << "\n���������� �������: " << os
        << "\n�������� �������: " << material << "\n����: " << color
        << "\n�������� ����:\n" << description << std::endl;
    info.close();

    DisplayDevice device(name, interface, power, weight, diagonal, resolution, fileName);
    devices.push_back(device);
    saveDevices(devices);
    std::cout << "������� ������!\n";
}

int main() {
    std::vector<DisplayDevice> devices;
    loadDevices(devices);

    while (true) {
        std::cout << "\n1. �������� �������\n2. ������ �������\n3. �����\n��� ����: ";
        int choice;
        std::cin >> choice;

        if (choice == 1)
            showDevices(devices);
        else if (choice == 2)
            addDevice(devices);
        else if (choice == 3)
            break;
    }

    return 0;
}