#include "Material.hpp"

Material::Material(int etiqueta, float precio, int volumen, string estado)
{
    this->etiqueta = etiqueta;
    this->precio = precio;
    this->volumen = volumen;
    this->state = estado;
}

Material::~Material()
{
}

Material& Material::operator=(const Material &M){
    this->setEtiqueta(M.getEtiqueta());
    this->setPrecio(M.getPrecio());
    this->setVolumen(M.getVolumen());
    this->setState(M.getState());

    return *this;
};