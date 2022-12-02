#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 55
#define BUFFER 12

typedef struct{
    int id;
    char marca[DIM];
    char modelo[DIM];
    float precio;
    float descuento;
}registro;

void getData(char* nomArchivo,registro* data){
    FILE* file=fopen(nomArchivo,"rt");
    int i=0;
    char titulos[150];
    char stringTokenizar[250];
    char* token;

    if(file==NULL){
        perror("Error");
    }
    else{
        fgets(titulos,150,file); //lo utilizo unicamente para poder empezar a leer los datos correctamente

        fgets(stringTokenizar,250,file);
        token=strtok(stringTokenizar,",");
        data[i].id=atoi(token);

        while(!feof(file)){

            while(token!=NULL){
                token=strtok(NULL,",");
                strcpy(data[i].marca,token);
                token=strtok(NULL,",");
                strcpy(data[i].modelo,token);
                token=strtok(NULL,",");
                data[i].precio=atof(token);
                //printf("Precio al cargarlo: %f \n",data[i].precio);
                token=strtok(NULL,",");
                data[i].descuento=atof(token);
                i++;
                token=strtok(NULL,",");
            }

            if(!feof(file)){
                fgets(stringTokenizar,250,file);
                token=strtok(stringTokenizar,",");
                data[i].id=atoi(token);
            }
        }
    }
    fclose(file);
}

int getMejorModelo(registro* data){
    int j;
    float mejorPrecio;
    int indiceMejor;
    for(j=0;j<BUFFER;j++){
        if(j==0){
            mejorPrecio=data[j].precio*(1-data[j].descuento);
            indiceMejor=j;
        }
        else{
            if(data[j].precio*(1-data[j].descuento)<mejorPrecio){
                mejorPrecio=data[j].precio*(1-data[j].descuento);
                indiceMejor=j;
            }
        }
        printf("ID:%d - MARCA:%s - MODELO:%s \nPRECIO:%.2f \nDESCUENTO:%%%.2f \nPrecio al Contado:$%.2f\n\n",data[j].id,data[j].marca,data[j].modelo,data[j].precio,data[j].descuento,data[j].precio*(1-data[j].descuento));
    }
    return data[indiceMejor].id;
}

void mostrarOrdenado(registro* data){
    int k,h,it1,it2;

    registro aux;
    float precios[BUFFER];

    for(k=0;k<BUFFER;k++){
        precios[k]=data[k].precio;
    }
    for(it1=0;it1<BUFFER;it1++){
        for(it2=0;it2<BUFFER-1;it2++){
            if(data[it2].precio>data[it2+1].precio){
                //printf("Cambio %.2f por %.2f \n",data[it2].precio,data[it2+1].precio);
                aux=data[it2+1];
                data[it2+1]=data[it2];
                data[it2]=aux;
            }
        }
    }

    printf("Precios ordenados de Menor a Mayor: \n");
    for(h=0;h<BUFFER;h++){
        printf("%.2f - %s - %s \n",data[h].precio,data[h].marca,data[h].modelo);
    }
}

int main(){
    int id;
    registro item[BUFFER];
    getData("productos.txt",item);
    id=getMejorModelo(item);
    printf("El mejor precio al contado es: %d \n\n",id);
    mostrarOrdenado(item);
    return 0;
}