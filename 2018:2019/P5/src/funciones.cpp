#include "funciones.hpp"

void readFromFile(Cambio &c){
    ifstream file;
    int moneda;
    file.open("../src/monedas.txt");
    if(file.is_open()){
        while(!file.eof()){
            file >> moneda;
            c.setCambio(moneda);
        }
    }else{
        cout<<"Error al leer el fichero"<<endl;
        exit(-1);
    }
    file.close();

}

void showSolution(Cambio c, vector<vector<int> > tabla, int cantidad_user){
    // TODO
    vector<int> coins = c.getVector();
    vector<int> aux(coins.size(), 0);
    int i=coins.size();
    int j=cantidad_user;

    while(j != 0){
        if(tabla[i][j] == tabla[i-1][j]){
            i--;
        }else{
            aux[i-1] = aux[i-1]+1;
            j -= c.getCambio(i-1);
        }
    }

    for(int k=0; k<coins.size(); k++){
        if(aux[k] > 0){
            cout<<aux[k]<<" units of "<<coins[k]<<endl;
        }
    }
}

void getMinimo(Cambio c, vector<vector<int> > &tabla, int cantidad_user, int tam){
    // TODO
    for(int i=1; i<=c.getSizeC(); i++){
        for(int j=1; j<cantidad_user+1; j++){
            if(i==1 && j<c.getCambio(i-1)){
                tabla[i][j] = -1;
            }else{
                if(i==1){
                    tabla[i][j] = 1+tabla[i][j-c.getCambio(0)];
                }else{
                    if(j-c.getCambio(i-1) < 0){
                        tabla[i][j] = tabla[i-1][j];
                    }else{
                        tabla[i][j] = min(tabla[i-1][j], 1+tabla[i][j-c.getCambio(i-1)]);
                    }
                }
            }
        }
    }
    showSolution(c, tabla, cantidad_user);
}

void cambioMinimo(){

    int option=0;
    int numC;
    int cantidad_user = 0;
    Cambio c;
    readFromFile(c);
    do{ 
        c.showCambio();

        cout<<"\t0. Salir al menu.\n\tIntroduzca la cantidad para calcular el cambio: ";
        cin >> cantidad_user;

        if(cantidad_user > 0){
            vector<vector<int> > tabla(c.getSizeC()+1, vector<int>(cantidad_user+1, 0));

            getMinimo(c, tabla, cantidad_user, c.getSizeC());
        }else{
            cout<<"La cantidad a insertar ha de ser mayor que 0"<<endl;
        }

    }while(cantidad_user > 0);
}

bool readFromFileM(vector<Material> &material_vector){
    ifstream file;
    int aux, ultimo_elemento = -1;
    Material auxM;

    file.open("../src/materiales.txt");
    if(file.is_open()){
        material_vector.clear();
        while(!file.eof()){
            file >> aux;
            auxM.setLabel(aux);

            file >> aux;
            auxM.setVolume(aux);

            file >> aux;
            auxM.setValue(aux);

            if(ultimo_elemento != auxM.getLabel()){
                material_vector.push_back(auxM);
            }
            ultimo_elemento = auxM.getLabel();
        }
        file.close();
        return true;
    }else{
        return false;
    }
}

void mochilaMinimo(){
    int cantidad_user = 0;
    vector<Material> material_vector;
    do{
        cout<<"\n\t0. Salir al menu.\n\tIntroduzca la cantidad para calcular el volumen de la mochila: ";
        cin >> cantidad_user;

        if(cantidad_user > 0){
            Mochila m(cantidad_user);

            if(readFromFileM(material_vector)){
                vector<vector<int> > tabla_mochila;

                m.fillBag(material_vector, tabla_mochila);
                m.getSolution(material_vector, tabla_mochila);

                cout<<"\nEl precio de la mochila es: "<<m.getValueBag()<<endl;
                
                m.bagElements();
            }else{
                cout<<"Error! El fichero no se ha podido leer."<<endl;
            }
        }
    }while(cantidad_user > 0);
}