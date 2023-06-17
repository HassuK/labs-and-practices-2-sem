#include <iostream>
#include <vector>
#include <cmath>


class ReverseCinematica {
private:
    std::vector<float> links;
public:
    void setLinks(std::vector<float> links) {
        this->links = links;
    }
    std::vector<float> solve(float x, float y) {
        std::vector<float> angles;

        float b = sqrt(pow(x, 2) + pow(y, 2));
        float q1 = std::atan(y / x);
        float q2 = std::acos((pow(links[0], 2) - pow(links[1], 2) + pow(b, 2)) / (2 * b * links[0]));
        angles.push_back((q1 - q2)* 57.2958);
        angles.push_back(57.2958*(3.14 - std::acos((pow(links[0], 2) + pow(links[1], 2) - pow(b, 2)) / (2 * links[0] * links[1]))));   //57.2958 градусов в 1 радиане. Акос и прочие функции возвращают значение угла\
                                                                                                                                         в радианах. Чтобы было более читабельно и наглядно, перевожу в градусы
        return angles;
    }
};
int main() {
    ReverseCinematica cinematica;
    cinematica.setLinks({ 4, 7 });
    std::vector<float> angles = cinematica.solve(6, 6);
    
    std::cout << angles[0] << ' ' << angles[1] << std::endl;
   
    return 0;
}
