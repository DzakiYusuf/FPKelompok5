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
	//import data kedalam struct wh & ship
	warehouse[0] = (struct wh){"Minyak kelapa sawit", 1, 1000, 1, 7000, 12000};
	warehouse[1] = (struct wh){"Minyak kelapa", 2, 500, 0.5, 6000, 10000};
	warehouse[2] = (struct wh){"Rempah-rempah", 3, 2000, 0.25, 5000, 9000};
	warehouse[3] = (struct wh){"Perabotan", 4, 100, 50, 23000, 50000};
	warehouse[4] = (struct wh){"Tekstil", 5, 500, 10, 10000, 25000};
	warehouse[5] = (struct wh){"Elektronik", 6, 100, 2, 27000, 60000};
	warehouse[6] = (struct wh){"Kayu Mahoni", 7, 1000, 5, 9000, 20000};
	warehouse[7] = (struct wh){"Karet", 8, 2000, 1, 4000, 12000};
 	warehouse[8] = (struct wh){"Nikel", 9, 5000, 0.2, 3000, 9000};
	warehouse[9] = (struct wh){"Serabut Kelapa", 10, 1000, 1, 5000, 11000};
	warehouse[10] = (struct wh){"Minyak", 11, 100, 50, 27000, 50000};
	warehouse[11] = (struct wh){"Mineral", 12, 500, 10, 17000, 30000};
	warehouse[12] = (struct wh){"Kayu Jati", 13, 100, 2, 38000, 70000};
	warehouse[13] = (struct wh){"Kayu Rotan", 14, 1000, 5, 12000, 20000};
	warehouse[14] = (struct wh){"Biji Kopi", 15, 2000, 1, 3000, 10000};
	ship[0] = (struct shipping){"John Smith", "United States", 5000, 1, "Minyak kelapa sawit", 100, 0, 0, 0};
	ship[1] = (struct shipping){"Jane Doe", "China", 8000, 2, "Minyak kelapa", 50, 0, 0, 0};
	ship[2] = (struct shipping){"Robert Johnson", "India", 4000, 7, "Kayu Mahoni", 127, 0, 0, 0};
	ship[3] = (struct shipping){"Emily Williams", "Japan", 10000, 5, "Tekstil", 32, 0, 0, 0};
	ship[4] = (struct shipping){"Michael Brown", "France", 6000, 4, "Perabotan", 60, 0, 0, 0};
	ship[5] = (struct shipping){"Samantha Jones", "United Kingdom", 7000, 6, "Elektronik", 30, 0, 0, 0};
	ship[6] = (struct shipping){"Christopher Davis", "Germany", 9000, 3, "Rempah-rempah", 362, 0, 0, 0};
	ship[7] = (struct shipping){"Ashley Johnson", "Russia", 8000, 8, "Karet", 1005, 0, 0};
	ship[8] = (struct shipping){"Daniel Thompson", "Spain", 7000, 9, "Nikel", 1250, 0, 0, 0};
	ship[9] = (struct shipping){"Sarah Smith", "Brazil", 8000, 10, "Serabut Kelapa", 433, 0, 0, 0};
	ship[10] = (struct shipping){"Jason Davis", "Australia", 10000, 11, "Minyak", 33, 0, 0, 0};
	ship[11] = (struct shipping){"Laura Williams", "South Africa", 9000, 12, "Mineral", 50, 0, 0, 0};
	ship[12] = (struct shipping){"Michael Thompson", "Mexico", 7000, 13, "Kayu Jati", 30, 0, 0, 0};
	ship[13] = (struct shipping){"Emily Johnson", "Canada", 8000, 14, "Kayu Rotan", 200, 0, 0, 0};
	ship[14] = (struct shipping){"John Davis", "Argentina", 9000, 15, "Biji Kopi", 1100, 0, 0, 0};
	warehouseSize = 15;
	shippingSize = 15;

	mainmenu:
	//while(1) untuk infinite loop ke menu
	while(1){
	int pil;
	printf("\n1. Data warehouse\n2. Data Shipping\n3. Data Penjualan\n Input:");
	scanf("%d", &pil);		
	if (pil == 1){
		
		printWarehouse(warehouse,warehouseSize);
		int pil1_2;
		printf("[1]Search data menggunakan ID produk\n[2]Sort dari produk paling ringan\n[3]Sort dari produk paling berat\n[4]Sort dari jumlah stok terbanyak\n[5]Sort dari jumlah stok paling sedikit\n[6]Search Nama Produk\n[7]Kembali\nMasukkan Input: ");
		scanf("%d", &pil1_2);
		if(pil1_2 == 1){
			
		} else if (pil1_2 == 2){
			sortAscBerat(warehouse,warehouseSize);
			printWarehouse(warehouse,warehouseSize);
		} else if (pil1_2 == 3){
			sortDescBerat(warehouse,warehouseSize);
			printWarehouse(warehouse,warehouseSize);
		} else if (pil1_2 == 4){
			sortAscStok(warehouse,warehouseSize);
			printWarehouse(warehouse,warehouseSize);
		} else if (pil1_2 == 5){
			sortDescStok(warehouse,warehouseSize);
			printWarehouse(warehouse,warehouseSize);
		} else if (pil1_2 == 6){
			searchWarehouseNama(warehouse, warehouseSize);
		} else if (pil1_2 == 7){
			goto mainmenu;
			break;
		}
	} 
	else if (pil == 2){
		updatePenjualan(warehouse, ship, data, penjualanSize);
		printShipping(ship, shippingSize);
		printf("[1]Tambahkan data baru shipping\n[2]Sort Berdasarkan ID Produk\n[3]Sort dari paling ringan\n[4]Sort dari paling berat\n[5]Sort dari jumlah qty paling sedikit\n[6]Search Nama Pembeli\n[7]Kembali\nMasukkan Input: ");
		int pil2_2;
     	scanf("%d", &pil2_2);
	    if (pil2_2 == 1){
	    	
		} else if (pil2_2 == 2){
			sortAscIDTabel2(ship, shippingSize);
			printShipping(ship, shippingSize);
		} else if (pil2_2 == 3){
			sortAscTotalBerat(ship, shippingSize);
			printShipping(ship, shippingSize);
		} else if (pil2_2 == 4){
			sortDescTotalBerat(ship, shippingSize);
			printShipping(ship, shippingSize);
		} else if (pil2_2 == 5){
			sortAscQty(ship, shippingSize);
			printShipping(ship, shippingSize); 
		} else if (pil2_2 == 6){
			char namaPembeli[255];
			printf("Masukkan Nama Pembeli: ");
			scanf(" %[^\n]", &namaPembeli);
			sequentialSearchNamaPembeli(namaPembeli);
		}
	
}

	else if (pil == 3){
		updatePenjualan(warehouse, ship, data, penjualanSize);
		printPenjualan(data, penjualanSize);
		printf("1. Sort berdasarkan keuntungan terkecil\n2.Sort berdasarkan keuntungan tertinggi\n3. Sort berdasarkan jumlah terjual terendah\n4. Sort berdasarkan jumlah penjualan tertinggi\n5. Search Nama Produk\nMasukkan Input: ");
		int pil3_2;
		scanf("%d", &pil3_2);
	 if (pil3_2 == 1){
	 	sortAscProfit(data, penjualanSize);
	 	printPenjualan(data, penjualanSize);
	} else if (pil3_2 == 2){
		sortDescProfit(data, penjualanSize);
		printPenjualan(data, penjualanSize);
	} else if (pil3_2 == 3){
		sortAscJumlahTerjual(data, penjualanSize);
		printPenjualan(data, penjualanSize);
	} else if (pil3_2 == 4){
		sortDescJumlahTerjual(data, penjualanSize);
		printPenjualan(data, penjualanSize);
	} else if (pil3_2 == 5){
		char namaProduk[255];
		printf("Masukkan Nama Produk: ");
		scanf(" %[^\n]", &namaProduk);
		searchNamaProdukTabel3(namaProduk);
	}
   }
  }
}

int printWarehouse(struct wh warehouse[MAX_ENTRIES], int n){
	//dodek
}

int sortAscBerat(struct wh warehouse[MAX_ENTRIES], int n){
	//dodek
}

int sortDescBerat(struct wh warehouse[MAX_ENTRIES], int n){
	//dodek
}

int sortAscStok(struct wh warehouse[MAX_ENTRIES], int n){
	//mutiara
}

int sortDescStok(struct wh warehouse[MAX_ENTRIES], int n){
	//mutiara	
}

int sortAscID(struct wh warehouse[MAX_ENTRIES], int n){
	//dzaki
}

int binarySearchIDProduk(int id){
	//dzaki	
}

int searchWarehouseNama(char *namaProduk){
	//adinda
}

int printShipping(struct shipping ship[MAX_ENTRIES], int n) {
	//dodek
}

int sortAscIDTabel2(struct shipping ship[MAX_ENTRIES], int n){
	//mutiara
}

int sortAscTotalBerat(struct shipping ship[MAX_ENTRIES], int n){
	//mutiara
}

int sortDescTotalBerat(struct shipping ship[MAX_ENTRIES], int n){
	//adinda
}

int sortAscQty(struct shipping ship[MAX_ENTRIES], int n){
	//adinda
}

int sequentialSearchNamaPembeli(char nama_pembeli[255]) {
	//adinda
}

int updatePenjualan(struct wh warehouse[MAX_ENTRIES], struct shipping ship[MAX_ENTRIES], struct data_penjualan data[MAX_ENTRIES], int s){
	//dzaki
}

int printPenjualan(struct data_penjualan data[MAX_ENTRIES], int size) {
	//dzaki
}

int sortAscProfit(struct data_penjualan data[MAX_ENTRIES], int n){
	//varrel
}

int sortDescProfit(struct data_penjualan data[MAX_ENTRIES], int n){
	//varrel
}

int sortAscJumlahTerjual(struct data_penjualan data[MAX_ENTRIES], int n){
	//varrel
}

int sortDescJumlahTerjual(struct data_penjualan data[MAX_ENTRIES], int n){
	//varrel
}

int searchNamaProdukTabel3(char namaProduk){
	//varrel
}
