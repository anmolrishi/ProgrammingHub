#include <iostream>
using namespace std; 

int main(){
srand(time(NULL));
int tam1 = 6, tam2 = 10, cont = 0, i, j;
int array1[tam1], array2[tam2];
int intersection[tam1]; /*I am using the size of the smallest array because it would be impossible to have more than that as an INTERSECTION.*/ 

for(i = 0; i<tam2; i++){
	if(i <= tam1){
		array1[i] = rand() % 20;  array2[i] = rand() % 20; 
	}else{
		array2[i] = rand() % 20; 
	}
}
for(i = 0; i < tam1; i++){
	for(j = 0; j < tam2; j++){
	/* If you want to see how they really are being compared, uncomment this:*/ 
	/* cout << array1[i] <<" is now being compared to " << array2[j] << endl; */
		if(array1[i] == array2[j]){
			intersection[cont] = array1[i]; /* There will be repeated elements. Improve that if you want :) */ 
			cont++;
		}
	}
}
cout << "The intersection between array1 = {";
		for(i = 0; i < tam1; i++){
			if(i == tam1-1){
				cout << array1[i];
			}else{
				cout << array1[i] << ", "; 
			}
		}
cout << "}"<< endl <<"and array2 = {";
		for(j = 0; j < tam2; j++){
			if(j == tam2-1){
				cout << array2[j];
			}else{
				cout << array2[j] << ", "; 
			}
		}
cout << "}\nis...{";
if(cont == 0){
	cout << "NULL";
}else{
		for(i = 0; i < cont; i++){
			if(i == cont-1){
				cout << intersection[i];
			}else{
				cout << intersection[i] << ", "; 
			}
		}
}
cout << "}" << endl;
}
