
#include <iostream>
#pragma once
namespace vb {

    template<typename type>
    class vector {

    };

    template<>
    class vector<bool> {
    private:
        size_t byte = 1;
        size_t lenght = 0;
        char* boolMas = nullptr;
    public:
        vector<bool>() = default; //base constr

        ~vector()
        {
            delete[] boolMas;
        }

        vector(const vector<bool>& copy) {  //copy constr
            if (this != &copy) {
                std::cout << "copy";
                lenght = copy.lenght;
                char* boolnew = new char[lenght];
                for (size_t i = 0; i < lenght; i++) {
                    boolnew[i] = copy.boolMas[i];
                }
                delete[] boolMas;
                boolMas = boolnew;
            }
        }

        vector<bool>& operator= (const vector<bool>& copy) { //constr prisvaiv
            std::cout << "prisvaiv\n";
            if (this != &copy) {
                lenght = copy.lenght;
                char* boolnew = new char[lenght];
                for (size_t i = 0; i < lenght; i++) {
                    boolnew[i] = copy.boolMas[i];
                }
                delete[] boolMas;
                boolMas = boolnew;
            }
            return *this;
        }

        bool operator[](unsigned int index) const {
            return static_cast<bool>(((boolMas[index / 8]) >> index) & 0b00000001);
        }

        void edit(size_t index, bool value) {
            char degree = 1;
            for (int i = 0; i < index; i++) {
                degree *= 2;
            }
            value ? boolMas[index / 8] |= degree : boolMas[index / 8] &= ~degree;
        }

        void push_back(bool value) {
            if (lenght % 8 == 0) { 
                if (lenght % 8 == 0 && lenght > 0) {
                    byte++;
                }
                char* temp = new char[lenght/8+1];
                for (int i = 0; i < lenght/8; i++) {
                    temp[i] = boolMas[i];
                }
                delete[] boolMas;
                boolMas = temp;
                edit(lenght, value);
            }
            else {
                edit(lenght, value);
            }
            lenght++;
        }

        void size() const {
            std::cout << "elements in vector: " << lenght << std::endl << "bytes of vector: " << byte << std::endl;
        }

        size_t lenghtVec() const {
            return lenght;
        }

        void insert(size_t index, bool value) {
            push_back(operator[](lenght - 1));
            for (size_t i = lenght; i != index; i--)
                edit(i, operator[](i - 1));

            edit(index, value);
        }

        void erase(size_t firstIndex, size_t lastIndex) {
            for (size_t i = lastIndex; i < lenght; i++) {
                edit(i - (lastIndex - firstIndex), operator[](i));
            }
            lenght -= lastIndex - firstIndex;
        }
        void erase(size_t index) {
            for (size_t i = index; i < lenght - 1; i++){
              edit(i, operator[](i + 1));
          }
            lenght--;
          }

        };
    

}