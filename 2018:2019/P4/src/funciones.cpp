#include "funciones.hpp"

void showCambio(Monedas M, vector<int> solucion){
    vector<int> cantidades(M.sizeC());
    int cantidad = 0;
    for(int i = 0; i < M.sizeC(); i++){
        for(int j = 0; j < solucion.size(); j++){
            if(solucion[j] == M.getCambio(i)){
                cantidad++;
            }
        }
        cantidades[i] = cantidad;
        cantidad = 0;
    }

    for(int i = 0; i < cantidades.size(); i++){
        if(cantidades[i] != 0){
            cout<<"\t\t"<<cantidades[i]<<" monedas de "<<M.getCambio(i)<<endl;
        } 
    }   
};

void getCambio(Monedas M, int cantidad_user){
    vector<int> solucion;
    
    // Leemos todas las cantidades disponibles desde la mayor hasta la menor
    for(int i = M.sizeC()-1; i >= 0 ; --i){
        // Mientras que la cantidad del usuario sea mayor que la moneda i
        while(cantidad_user >= M.getCambio(i)){
            // Restamos la moneda a la cantidad del usuario
            cantidad_user -= M.getCambio(i);
            // Guardamos la moneda como solucion
            solucion.push_back(M.getCambio(i));
        }
    }

    showCambio(M, solucion);
};

void cambioMinimo(){
    Monedas M;
    int option=0;
    int moneda_user;

    cout<<"0. Salir del programa"<<endl;
    cout<<"\t1. Sistema monetario Europeo"<<endl;
    cout<<"\t2. Sistema monetario introducido por usuario"<<endl;
    cin >> option;
    
    switch(option){
        case 0:
            break;
        case 1:
            M.readFromFile("../src/monedas.txt");
            break;
        case 2:
            M.setCambio("../src/monedas_user.txt");
            break;
        default:
            cout<<"Error!. Option not recognised"<<endl;
            break;
    };
    int cantidad_user=0;
   
    cout<<"\tCambio disponible: ";
    M.showMonedas();

    cout<<"\tIntroduzca la cantidad para calcular el cambio: ";
    cin >> cantidad_user;

    cout<<"\tEl cambio final para "<<cantidad_user<<" es: "<<endl;
    getCambio(M, cantidad_user);

};

bool leerMateriales(string file, vector<Material> &materiales){
    ifstream File;
    int aux, ultimo_elemento = -1;
    Material auxM;

    File.open(file);
    if(File.is_open()){
        materiales.clear();
        while(!File.eof()){
            File >> aux;
            auxM.setEtiqueta(aux);

            File >> aux;
            auxM.setVolumen(aux);

            File >> aux;
            auxM.setPrecio(aux);

            auxM.setState("no_usado");

            if(ultimo_elemento != auxM.getEtiqueta()){
                materiales.push_back(auxM);
            }
            ultimo_elemento = auxM.getEtiqueta();
        }
        File.close();
        return true;
    }else{
        return false;
    }
};

void mochilaMinimo(){
    int capacidad;
    vector<Material> materiales;
    bool aux;
    string file = "../src/materiales.txt";

    do{
        cout<<"\t0. Salir.\n\tIntroduzca el volumen de la mochila: ";
        cin >> capacidad;

        Mochila M(capacidad);

        if(leerMateriales(file, materiales) == true){
            // Rellenamos la mochila con el maximo número de materiales posibles
            M.rellenarMochila(materiales);
            // Mostramos el precio total de la mochila (Volumen*Precio)
            cout<<"El precio de la mochila es: "<<M.getMochila()<<endl;
            // Mostramos los materiales usados
            cout<<"\nLos materiales que incluye son: "<<endl;
            M.getContenidoMochila();
        }else{
            cout<<"Error al leer el fichero con los materiales"<<endl;
        }
    }while(capacidad>0);
};