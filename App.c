#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_ENTRIES 30
struct wh
{
    char nama_produk[225];
    int id_produk;
    int stok;
    float berat;
    int base_price;
    int sell_price;
} warehouse[MAX_ENTRIES];

struct shipping
{
    char nama_pembeli[225];
    char *negara[225];
    float jarak;
    int id_produk;
    char nama_produk[225];
    int qty;
    float total_berat;
    int ongkir;
    int processed;
} ship[MAX_ENTRIES];

struct data_penjualan
{
    int id_produk;
    char nama_produk[225];
    int base_price;
    int sell_price;
    int jumlah_terjual;
    int total_profit;
} data[MAX_ENTRIES];

	int warehouseSize = 0;
	int shippingSize = 0;
	int penjualanSize = 0;
	
int main(){
	FILE *file1 = fopen("warehouse.txt", "r");
	if (file1 == NULL) {
		printf("Error: Tidak dapat membuka file input.txt\n");
		return 1;
	}
	int i;
	for (i = 0; i < 5; i++) {
		fscanf(file1, "%d  %[^\n] %f %d %d %d", &warehouse[i].id_produk, &warehouse[i].nama_produk, &warehouse[i].berat, &warehouse[i].stok, &warehouse[i].base_price, &warehouse[i].sell_price);
	warehouseSize++;
}// tutup file	
	fclose(file1);
	
	//input data penjualan dari notepad
		FILE *file2 = fopen("shipping.txt", "r");
	if (file2 == NULL) {
		printf("Error: Tidak dapat membuka file\n");
		return 1;
	}
	
	for (i = 0; i < 5; i++) {
		
		fscanf(file2, "  %[^\n]  %s %f %d %[^\n] %d", &ship[i].nama_pembeli, &ship[i].negara, &ship[i].jarak, &ship[i].id_produk, &ship[i].nama_produk, &ship[i].qty);
	shippingSize++;
	}
	fclose(file2);//tutup file
}
