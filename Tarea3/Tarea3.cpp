
#include <iostream>

using namespace std;

void MostrarMatriz(int Matriz[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<Matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}

void LlenarMatriz(char* entradargC,int Matriz[][9]){
	bool var=true,var2=true;
	string entrada = entradargC;
	string token,token2,auxiliar;
	int largo = entrada.length(), pos,n=0,pos2,aux;
	int numero[2];
	char delimitador = ']',delimitador2= ';';
	while(n<largo){
		pos = entrada.find(delimitador);
		if(pos != -1 && var == true){
			if(pos == -1){
				var = false;
			}
			token = entrada.substr(1,pos-1);
			auxiliar = token;
			for(int i=0;i<3;i++){
				if(i!=2){
					pos2= auxiliar.find(delimitador2);
					token2 = auxiliar.substr(0,pos2);
					aux = stoi(token2);
					numero[i] = aux;
					auxiliar.erase(0,pos2+1);
				//cout<<token2<<endl;
				}else{
					//cout<<auxiliar<<endl;
					aux = stoi(auxiliar);
					if(numero[0] >= 0 && numero[0] <= 9 && numero[1] >= 0 && numero[1] <= 9 && aux >=1 && aux <=9){
						Matriz[numero[1]][numero[0]] = aux;
					}else{
						cout<<"Ingrese valor en los rangos correctos"<<endl;
						n=largo;
						var2=false;
					}
				}
			}
			entrada.erase(0,pos+1);
		//cout<<token<<endl;
			n++;
		}else{
			n=largo;

		}
	}
	if(var2== true){
	 MostrarMatriz(Matriz);
	}

}
void InicializarMatriz(int Matriz[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			Matriz[i][j] = 0;
		}
	}
}


int main(int argc, char* argv[]){
	int Matriz[9][9];
	InicializarMatriz(Matriz);
	LlenarMatriz(argv[1],Matriz);
}
