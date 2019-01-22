#ifndef MATERIAL__
#define MATERIAL__

#include <list>
#include <iostream>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

class Material
{
    private:
        int label_;
        float value_;
        int volume_;
    public:
        Material(int label = 1,float value=1.0, int volume = -1 ){
            this->label_ = label;
            this->value_ = value;
            this->volume_ = volume;
        };

        inline int getLabel()const{return this->label_;};
        inline float getValue()const{return this->value_;};
        inline int getVolume()const{return this->volume_;};

        inline void setLabel(int label){this->label_ = label;};
        inline bool setValue(float value){if(value < 0){return false;}else{this->value_=value;return true;}};
        inline bool setVolume(int volume){if(volume < 0){return false;}else{this->volume_=volume;return true;}};

        Material &operator=(const Material &M);
};

#endif
