#include <iostream>
#include <string>

class Student {
private:
    std::string ten;
    int tuoi;
    float diem;

public:
    // Constructor để khởi tạo thông tin của sinh viên
    Student(std::string iTen, int iTuoi, float iDiem) : ten(iTen), tuoi(iTuoi), diem(iDiem) {}

    // Phương thức để hiển thị thông tin sinh viên
    void displayInfo() {
        std::cout << "Ten: " << ten << std::endl;
        std::cout << "Tuoi: " << tuoi << std::endl;
        std::cout << "Diem: " << diem << std::endl;
    }
};

int main() {
    // Tạo đối tượng sinh viên và hiển thị thông tin
    Student student1("Diep Tu trung", 23, 8.5);
    student1.displayInfo();

    return 0;
}
