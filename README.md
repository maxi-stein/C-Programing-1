# C-Programing-1
This is a Final Exam I passed in Colleage in 2022.

The electronic store ShangTsung has the text file 'productos.txt' which lists the following parameters:
Product ID 
Brand
Model
Price List
Discount Cash-In-Hand

It is asked to:

1) Create the function void getData(char* nameArchive, registry* data) that recieves the name of the file 
nameArchive and a pointer to a vector data. The function must open the file and load its information to the vector data

2) Create the function int getBestModel(registry* data) that recieves the loaded vector (from function 1) and   :
    a. Shows in screen the content of the entire vector.
    b. Returns the ID of the registry that has the best price if paid hand-on-cash (that is, the cheapest price
including the discount for paying cash-in-hand).

3) Create the function void showOrdered (registry* data) that recieves the vector data and 
shows it ordered by price list (the format shall be: price list, brand, model).

The following struct must be used in this exercise:
#define DIM 55
typedef struct{
 int id;
 char brand[DIM];
 char model[DIM];
 float price;
 float discount;
} registry;
