//Shape Area Calculator Using Function Overloading
#include <iostream>
double area(double radius){
    return 3.14159 * radius * radius;
}
double area(double width, double height, char type){
    return width * height;
}
double area(double base, double height){
    return 0.5 * base * height;
}

int area(int side) {
    return side * side; 
}

int main() {
    int choice;
    std::cout << "\n Select a shape \n" << std::endl;
    std::cout << "1. Circle" << std::endl;
    std::cout << "2. Rectangle" << std::endl;
    std::cout << "3. Triangle" << std::endl;
    std::cout << "4. Square" << std::endl;
    std::cin >> choice;
    switch(choice) {
        case 1:
            double radius;
            std::cout << "Enter the radius: " << std::endl;
            std::cin >> radius;
            std::cout << "Area of cicle: " << area(radius) << std::endl;
            break;

        case 2:
            double width;
            double height;
            char type;
            std::cout << "Enter width: ";
            std::cin >> width;
            std::cout << "Enter height: ";
            std::cin >> height;
            std::cout << "Enter type (e.g., 'r'): ";
            std::cin >> type;
            std::cout << "Area of Rectangle: " << area(width, height, type) << std::endl;
            break;

        case 3:
            double base;
            double he;
            std::cout << "Enter base: ";
            std::cin >> base;
            std::cout << "Enter height: ";
            std::cin >> he;
            std::cout << "Area of Triangle: " << area(base, he) << std::endl;
            break;
        
        case 4:
            int side;
            std::cout << "Enter side: ";
            std::cin >> side;
            std::cout << "Area of Square: " << area(side) << std::endl;
            break;
        
        default:
            std::cout << "Invalid choice." << std::endl;
    }
    return 0;
}
