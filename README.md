# C-Programing-1
This is a Final Exam I passed in Colleage in 2022.

La casa de electrónica ShangTsung dispone de un archivo productos.txt en cual lista el id de producto, 
marca, modelo, precio de lista y descuento por pago al contado. Se pide:
1) Desarrollar la función void getData(char* nomArchivo, registro* data); que reciba el nombre 
del archivo nomArchivo y el puntero a un vector data. La función debe abrir el archivo y cargarlo en el 
vector data.
2) Desarrollar la función int getMejorModelo(registro* data); que reciba el vector ya cargado y:
a. Muestre por pantalla el contenido del vector.
b. Devuelva el id del registro que es la mejor opción pagando al contado (es decir, la más barata
incluyendo el descuento por pago al contado).
3) Desarrollar la función void mostrarOrdenado(registro* data); que reciba el vector data y lo 
muestre ordenado según el precio de lista (mostrar con formato: precio de lista, marca,
modelo).
Para todos los puntos, utilizar la siguiente estructura:
#define DIM 55
typedef struct{
 int id;
 char marca[DIM];
 char modelo[DIM];
 float precio;
 float descuento;
} registro;
