#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 55
#define BUFFER 12

typedef struct{
    int id;
    char brand[DIM];
    char model[DIM];
    float price;
    float discount;
}registry;


void getData(char* nameArchive,registry* data){
    FILE* file=fopen(nameArchive,"rt");
    int i=0;
    char title[150];
    char stringTokenize[250];
    char* token;

    if(file==NULL){
        perror("Error");
    }
    else{
        fgets(title,150,file); //used only to dump the first line and start reading the actual data

        fgets(stringTokenize,250,file);
        token=strtok(stringTokenize,",");
        data[i].id=atoi(token);

        while(!feof(file)){

            while(token!=NULL){
                token=strtok(NULL,",");
                strcpy(data[i].brand,token);
                token=strtok(NULL,",");
                strcpy(data[i].model,token);
                token=strtok(NULL,",");
                data[i].price=atof(token);
                token=strtok(NULL,",");
                data[i].discount=atof(token);
                i++;
                token=strtok(NULL,",");
            }

            if(!feof(file)){
                fgets(stringTokenize,250,file);
                token=strtok(stringTokenize,",");
                data[i].id=atoi(token);
            }
        }
    }
    fclose(file);
}

int getBestModel(registry* data){
    int j;
    float bestPrice;
    int bestIndex;
    for(j=0;j<BUFFER;j++){
        if(j==0){
            bestPrice=data[j].price*(1-data[j].discount);
            bestIndex=j;
        }
        else{
            if(data[j].price*(1-data[j].discount)<bestPrice){
                bestPrice=data[j].price*(1-data[j].discount);
                bestIndex=j;
            }
        }
        printf("ID:%d - BRAND:%s - MODEL:%s \nPRICE:$%.2f \nDISCOUNT:%%%.2f \nPRICE CASH-IN-HAND:$%.2f\n\n",data[j].id,data[j].brand,data[j].model,data[j].price,data[j].discount,data[j].price*(1-data[j].discount));
    }
    return data[bestIndex].id;
}

void showOrdered(registry* data){
    int k,h,it1,it2;

    registry aux;
    float prices[BUFFER];

    for(k=0;k<BUFFER;k++){
        prices[k]=data[k].price;
    }
    for(it1=0;it1<BUFFER;it1++){
        for(it2=0;it2<BUFFER-1;it2++){
            if(data[it2].price>data[it2+1].price){
                aux=data[it2+1];
                data[it2+1]=data[it2];
                data[it2]=aux;
            }
        }
    }

    printf("Prices ordered from lowest to highest: \n");
    for(h=0;h<BUFFER;h++){
        printf("%.2f - %s - %s \n",data[h].price,data[h].brand,data[h].model);
    }
}

int main(){
    int id;
    registry item[BUFFER];
    getData("productos.txt",item);
    id=getBestModel(item);
    printf("The best price for cash-in-hand is: %d \n\n",id);
    showOrdered(item);
    return 0;
}