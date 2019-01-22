#ifndef MOCHILA__
#define MOCHILA__

#include "Material.hpp"
#include <list>
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <assert.h>

using namespace std;

class Mochila
{
    private:
        int max_capacity_;
        int used_volume_;
        list<Material> material_set_;
    public:
        Mochila(int capacity=100){
            if(capacity > 0){
                this->max_capacity_ = capacity;
                this->used_volume_ = 0;
            }else{
                this->used_volume_ = 0;
            }
        };

        inline int getMaxCapacity()const{return this->max_capacity_;};
        inline int getUsedVolume()const{return this->used_volume_;};
        Material getMaterial(int i);

        float getValueBag();
        void bagElements();

        bool setMaximumCapacity(int max_capacity);

        bool addMaterial(Material &m);

        void fillBag(vector<Material> &materiales, vector<vector<int> > &tabla_materiales);

        void getSolution(vector<Material> &materiales, vector<vector<int> > &tabla_materiales);
};




#endif