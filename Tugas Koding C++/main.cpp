#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <limits>

#define PI 3.14159265359

class Robot {
public:
    virtual void inverseKinematics(double x_e, double y_e, double z_e) = 0;
    virtual void saveToFile(const std::string& filename) = 0;
    virtual void logSpeedsToFile(const std::string& filename, int testCaseNumber) = 0;
    virtual void appendSpeedsToFile(const std::string& filename, int testCaseNumber) = 0;
    virtual void readSpeedsFromFile(const std::string& filename) = 0;
};

class RobotCartesian3DOF : public Robot {
private:
    double max_length;
    double x, y, z;
    double angle_x, angle_y, angle_z;

public:
    RobotCartesian3DOF(double length) : max_length(length), x(0), y(0), z(0), angle_x(0), angle_y(0), angle_z(0) {}

    void inverseKinematics(double x_e, double y_e, double z_e) override {
        if (std::abs(x_e) <= max_length && std::abs(y_e) <= max_length && std::abs(z_e) <= max_length) {
            x = x_e;
            y = y_e;
            z = z_e;

            angle_x = atan2(y, z) * (180.0 / PI);
            angle_y = atan2(x, z) * (180.0 / PI);
            angle_z = atan2(y, x) * (180.0 / PI);

            std::cout << "Solusi: X: " << x << ", Y: " << y << ", Z: " << z << "\n";
            std::cout << "Sudut: X: " << angle_x << "°, Y: " << angle_y << "°, Z: " << angle_z << "°\n";
        } else {
            std::cout << "Error: Posisi di luar jangkauan. Maksimum " << max_length << " untuk setiap sumbu.\n";
        }
    }

    void saveToFile(const std::string& filename) override {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << "Solusi: X: " << x << ", Y: " << y << ", Z: " << z << "\n";
            file << "Sudut: X: " << angle_x << "°, Y: " << angle_y << "°, Z: " << angle_z << "°\n";
            std::cout << "Hasil disimpan ke " << filename << "\n";
        } else {
            std::cerr << "Gagal membuka file untuk menyimpan data.\n";
        }
    }

    void logSpeedsToFile(const std::string& filename, int testCaseNumber) override {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "Test Case Number: " << testCaseNumber << "\n";
            file << "Posisi: X: " << x << ", Y: " << y << ", Z: " << z << "\n";
            file << "Sudut: X: " << angle_x << "°, Y: " << angle_y << "°, Z: " << angle_z << "°\n";
            std::cout << "Data awal disimpan ke " << filename << "\n";
        } else {
            std::cerr << "Gagal membuka file untuk menyimpan data.\n";
        }
    }

    void appendSpeedsToFile(const std::string& filename, int testCaseNumber) override {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << "Test Case Number: " << testCaseNumber << "\n";
            file << "Posisi: X: " << x << ", Y: " << y << ", Z: " << z << "\n";
            file << "Sudut: X: " << angle_x << "°, Y: " << angle_y << "°, Z: " << angle_z << "°\n";
            std::cout << "Data ditambahkan ke " << filename << "\n";
        } else {
            std::cerr << "Gagal membuka file untuk menambahkan data.\n";
        }
    }

    void readSpeedsFromFile(const std::string& filename) override {
        std::ifstream file(filename);
        std::string line;
        if (file.is_open()) {
            std::cout << "Data dari file " << filename << ":\n";
            while (std::getline(file, line)) {
                std::cout << line << '\n';
            }
        } else {
            std::cerr << "Gagal membuka file untuk membaca.\n";
        }
    }
};

int main() {
    double max_length = 100.0;
    std::cout << "Panjang maksimum untuk setiap sumbu: " << max_length << '\n';

    RobotCartesian3DOF robot(max_length);

    double x_e, y_e, z_e;
    std::cout << "Masukkan posisi X: ";
    std::cin >> x_e;
    std::cout << "Masukkan posisi Y: ";
    std::cin >> y_e;
    std::cout << "Masukkan posisi Z: ";
    std::cin >> z_e;

    robot.inverseKinematics(x_e, y_e, z_e);

    int check;
    std::cout << "Apakah Print Hasil Sebelumnya (iya = 1): ";
    std::cin >> check;

    int testCaseNumber = 1;
    std::string filename = "inverse_kinematic_result.txt";
    if (check != 1) {
        robot.logSpeedsToFile(filename, testCaseNumber);
    } else {
        robot.appendSpeedsToFile(filename, testCaseNumber);
    }

    robot.readSpeedsFromFile(filename);

    return 0;
}
