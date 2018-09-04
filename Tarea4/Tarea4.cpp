#include <iostream>
#include <string>

using namespace std;

void InicializarMatriz(int Matriz[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			Matriz[i][j] = 0;
		}
	}
}

void MostrarMatriz(int Matriz[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<Matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}

void LlenarMatriz(char* entradargc,int Matriz[][9]){
	bool var=true,var2=true;
	string input = entradargc;
	string token,token2,auxiliar;
	int largo = input.length(), posicion,n=0,posicion2,aux;
	int numero[2];
	char delimitador = ']',delimitador2= ';';
	while(n<largo){
		cout << "... ..." <<endl;
		posicion = input.find(delimitador);
		if(posicion != -1 && var == true){
			if(posicion == -1){
				cout << "aca no esta entrando" <<endl;
				var = false;
			}
			token = input.substr(1,posicion-1);
			auxiliar = token;
			for(int i=0;i<3;i++){
				if(i!=2){
					posicion2= auxiliar.find(delimitador2);
					token2 = auxiliar.substr(0,posicion2);
					aux = stoi(token2);
					cout << "no estoy pasando por aca" <<endl;
					numero[i] = aux;
					auxiliar.erase(0,posicion2+1);
				}else{
					aux = stoi(auxiliar);
					if(numero[0] >= 0 && numero[0] <= 9 && numero[1] >= 0 && numero[1] <= 9 && aux >=1 && aux <=9){
						Matriz[numero[1]][numero[i]] = aux;
						cout << "no hace esto en el else tampoco" <<endl;
					}else{
						cout<<"Ingrese valor en los rangos correctos"<<endl;
						n=largo;
						var2=false;
					}
				}
			}
			input.erase(0,posicion+1);
			n++;
		}else{
			n=largo;
		}
	}
	if(var2== true){
		cout << "Printeando Matriz inicializada: " <<endl;
	 	MostrarMatriz(Matriz);
	}
}

bool RevisarFila(int fila,int valor,int Matriz[][9]){
	for(int i=0;i<9;i++){
		if(Matriz[fila][i] == valor){
			cout<<"El Número "<<valor<<" se encuentra en la fila n°: "<<fila<<endl;
		  return true;
		}
	}
	cout<<"El Número "<<valor<<" no se encuentra en la fila n°: "<<fila<<endl;
	return false;
}
bool RevisarColumna(int columna,int valor,int Matriz[][9]){
	for(int i=0;i<9;i++){
		if(Matriz[i][columna] == valor){
			cout<<"El Número "<<valor<<" se encuentra en la columna n°: "<<columna<<endl;
		  return true;
		}
	}
	cout<<"El Número "<<valor<<" no se encuentra en la fila n°: "<<columna<<endl;
	return false;
}
/*
	EL número de las submatrices es el siguiente:
	1  2  3
	4  5  6
	7  8  9

	Siendo 1 la matriz de coordenadas 0,0 hasta 2,2 ...
*/
bool RevisarSubmatriz(int SubMatriz,int valor,int Matriz[][9]){
	int fila=0,columna=0;
	switch(SubMatriz){
		case 1: fila=0; columna=0;
				break;
		case 2: fila=0; columna=3;
				break;
		case 3: fila=0; columna=6;
				break;
		case 4: fila=3; columna=0;
				break;
		case 5: fila=3; columna=3;
				break;
		case 6: fila=3; columna=6;
				break;
		case 7: fila=6; columna=0;
				break;
		case 8: fila=6; columna=3;
				break;
		case 9: fila=6; columna=6;
				break;
	}
	for(int i=fila;i<fila+3;i++){
		for(int j=columna;j<columna+3;j++){
			if(Matriz[i][j] == valor){
				cout<<"El Número "<<valor<<" se encuentra en la SubMatriz n°: "<<SubMatriz<<endl;
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char* argv[]){
	int Matriz[9][9];
	InicializarMatriz(Matriz);
	LlenarMatriz(argv[9],Matriz);
	int fila, columna, SubMatriz, opcion, valor;
	bool var = true;
	while(var){
		cout<<"Opcion: "<<endl;
		cout<<"1)Funcion Revisar Fila: "<<endl;
		cout<<"2)Funcion Revisar Columna: "<<endl;
		cout<<"3)Funcion Submatriz: "<<endl;
		cout<<"Ingrese Opcion: "<<endl;
		cin>>opcion;
		switch(opcion){
			case 1: cout<<"Funcion Revisar Fila:"<<endl;
					cout<<"Ingrese fila a revisar: "<<endl;
					cin>>fila;
					cout<<"Ingrese valor a encontrar: "<<endl;
					cin>>valor;
					RevisarFila(fila,valor,Matriz);
					break;
			case 2: cout<<"Funcion Revisar Columna:"<<endl;
					cout<<"Ingrese columna a revisar: "<<endl;
					cin>>columna;
					cout<<"Ingrese valor a buscar"<<endl;
					cin>>valor;
					RevisarColumna(columna,valor,Matriz);
					break;
			case 3: cout<<"Funcion Submatriz"<<endl;
					cin>>SubMatriz;
					cout<<"Ingrese valor a buscar en la submatriz: "<<endl;
					cin>>valor;
					RevisarSubmatriz(SubMatriz,valor,Matriz);
					break;
			default: var=false;
					break;
		}
	}
}
