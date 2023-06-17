#include <iostream>
#include <vectorBool.h>

int main() {
    vb::vector<bool> boolVector;
    
    boolVector.push_back(true); //boolVector.size();
    boolVector.push_back(false); //boolVector.size();
    boolVector.push_back(true); //boolVector.size();
    boolVector.push_back(false); //boolVector.size();
    boolVector.push_back(false); //boolVector.size();
    boolVector.push_back(true); //boolVector.size();
    boolVector.push_back(false); //boolVector.size();
    boolVector.push_back(true); //boolVector.size();
    boolVector.push_back(false); //boolVector.size();  
  //  std::cout << boolVector.lenghtVec();


    vb::vector<bool> bool2;
    bool2 = boolVector;
   
    for (int i = 0; i < boolVector.lenghtVec(); i++) {
        std::cout << boolVector[i] << " ";
    }
    boolVector.insert(4, true);
    std::cout << std::endl;
    for (int i = 0; i < boolVector.lenghtVec(); i++) {
        std::cout << boolVector[i] << " ";
    }

    std::cout << std::endl;
    boolVector.erase(1);

    for(int i = 0; i < boolVector.lenghtVec(); i++){
        std::cout << boolVector[i] << " ";
    }
    return 0;
}
