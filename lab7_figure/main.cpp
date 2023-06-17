#include <iostream>
#include <shape.h>
#include <vector>

int main() {

    std::vector<Shape*> shapes;

    Circle test("blue", 0, 0, 10);
    Rectangle test2("white", 0, 0, 1, 2);
    Triangle test3("black", 0, 0, 10, 20, 30);
   
    shapes.push_back(&test);
    shapes.push_back(&test2);
    shapes.push_back(&test3);

    for (int i = 0; i < shapes.size(); i++) {
        std::cout << shapes[i]->getArea() << std::endl;
    }


    return 0;
}
