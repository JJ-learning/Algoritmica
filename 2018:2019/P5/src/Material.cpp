#include "Material.hpp"




Material &Material::operator=(const Material &M){
    this->setLabel(M.getLabel());
    this->setValue(M.getValue());
    this->setVolume(M.getVolume());

    return *this;
}