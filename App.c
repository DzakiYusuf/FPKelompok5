#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct wh {
  char nama_produk[225];
  int id_produk;
  int stok;
  float berat;
  int base_price;
  int sell_price;
}warehouse[30];

struct shipping {
	char nama_pembeli[225];
	char negara[225];
	float jarak;
	int id_produk;
	char nama_produk[225];
	int qty;
	float total_berat;
	int ongkir;
	int processed;
}ship[30];

struct data_penjualan {
	int id_produk;
	char nama_produk[225];
	int base_price;
	int sell_price;
	int jumlah_terjual;
	int total_profit;
	int processed;
}data[30];

	int warehouseSize = 0;
	int shippingSize = 0;
	int penjualanSize = 0;
	

void printWarehouse(){
	printf("\n");
	printf("===================  Data Warehouse  ==================\n");
	printf("|%-3s|    %-18s|   %-9s| %-6s|\n", "ID Produk", "Nama Produk", "Berat", "Qty");
	int i;
	for (i = 0; i < warehouseSize; i++) {
		printf("|    %-5d|  %-20s|  %-7.2f kg| %-6d|\n", warehouse[i].id_produk, &warehouse[i].nama_produk, warehouse[i].berat, warehouse[i].stok);
	}	printf("=======================================================\n");
}

//dodek
void sortAscBerat(){   
    int n = warehouseSize;
    int i;
    for(i=1; i<n; i++){ 
    struct wh temp = warehouse[i];   
    int j = i-1;
	while(warehouse[j].berat > temp.berat && j>=0){
        warehouse[j+1] = warehouse[j];  
        j--; 
    }
        warehouse[j+1]=temp;
   }
}

//dodek
void sortDescBerat(){	
	int i;
    int n = warehouseSize;
    for(i=1; i<n; i++){ 
    struct wh temp = warehouse[i];   
    int j = i-1;
        while(warehouse[j].berat < temp.berat && j>=0){
        warehouse[j+1] = warehouse[j];  
        j--; 
    }
        warehouse[j+1]=temp;
    }
}

void sortAscStok(){	//mutiara
	int n = warehouseSize;
	int z;
    	for(z=1; z<n; z++){ 
        	struct wh temp = warehouse[z];   
        	int j = z-1;
        	while(warehouse[j].stok > temp.stok && j>=0){
            		warehouse[j+1] = warehouse[j];  
            		j--; 
        	}
        warehouse[j+1]=temp;
   	}
}

void sortDescStok(){   //mutiara	
    int n = warehouseSize;
    int z;
    for(z=1; z<n; z++){ 
	    struct wh temp = warehouse[z];   
	    int j = z-1;
            while(warehouse[j].stok < temp.stok && j>=0){
            	warehouse[j+1] = warehouse[j];  
            	j--; 
            }
        warehouse[j+1]=temp;
   	}
}

int sortAscID(){ 
	//dodek
	
}


int binarySearchIDProduk(int id){
	 //

}

void updateStockWarehouse() {
  int id_produk, new_stok;
  while (1) {
    printf("Masukkan ID produk: ");
    if (scanf("%d", &id_produk) == 1 && id_produk >= 0) {
      break;
    }
    printf("Masukkan ID produk yang valid (angka positif)\n");
    while (getchar() != '\n');  // clear input buffer
  }
  while (1) {
    printf("Masukkan jumlah stock baru: ");
    if (scanf("%d", &new_stok) == 1 && new_stok >= 0) {
      break;
    }
    printf("Masukkan jumlah stock yang valid (angka positif)\n");
    while (getchar() != '\n');  // clear input buffer
  }
  int i;
  for (i = 0; i < warehouseSize; i++) {
    if (warehouse[i].id_produk == id_produk) {
      break;
    }
  }
  warehouse[i].stok = new_stok;
  printf("Data berhasil diubah");
}

void searchWarehouseNama(){
	//adinda
	//sequential search
	char namaProduk[255];
	printf("Masukkan Nama Produk: ");
	scanf(" %[^\n]", &namaProduk);
	int i;
	int found = 0;
    for (i = 0; i < warehouseSize; i++) {
	    //compare nama_pembeli yang dicari dengan setiap data ship[i].nama_pembeli, cari hingga ada yang sama ( == 0)
        if (strcmp(warehouse[i].nama_produk , namaProduk) == 0) {
            printf("Data nama produk %s ditemukan pada index %d: \n", namaProduk, i);
			printf("Nama Produk: %s\n", warehouse[i].nama_produk);
			printf("ID Produk: %d\n", warehouse[i].id_produk);
			printf("Stok: %d\n", warehouse[i].stok);
			printf("Berat: %.2fkg\n", warehouse[i].berat);
			printf("Harga Beli: Rp.%d\n", warehouse[i].base_price);
			printf("Harga Jual: Rp.%d\n", warehouse[i].sell_price);
			found = 1;
        }
     } if (found == 0) {
		printf("Produk dengan nama %s tidak ditemukan.\n", namaProduk);
	}
}

void printShipping() {
  int i;
  if (strcmp(ship[i].nama_pembeli, "") != 0){
  	printf("\n");
   printf("=================================================  Data Shipping  ===================================================\n");
  printf("| %-20s | %-15s | %-9s| %-2s | %-20s | %-6s| %-10s|%-16s|\n", "Nama Pembeli", "Negara", "Jarak", "ID", "Nama Produk", "Qty", "Berat", "Tarif Pengiriman");
  for (i = 0; i < shippingSize; i++) {
    	printf("| %-20s | %-15s | %-9.2f| %-2d | %-20s | %-6d| %-7.2f kg| Rp.%-12d|\n", &ship[i].nama_pembeli, &ship[i].negara, ship[i].jarak, ship[i].id_produk, &ship[i].nama_produk, ship[i].qty, ship[i].total_berat, ship[i].ongkir);
	} printf("=====================================================================================================================\n");
  }
}

void sortAscIDTabel2(){   //mutiara
	int n = shippingSize;
    	int z;
		for(z=1; z<n; z++){ 
        	struct shipping temp = ship[z];   
        	int j = z-1;
        	while(ship[j].id_produk > temp.id_produk && j>=0){
           		ship[j+1] = ship[j];  
            		j--; 
        	}
        ship[j+1]=temp;
   	}

}

void sortAscTotalBerat(){ //mutiara
	int z;
	int n = shippingSize;
    	for(z=1; z<n; z++){ 
        struct shipping temporary = ship[z];   
        int j = z-1;
        while(ship[j].total_berat > temporary.total_berat && j>=0){
            ship[j+1] = ship[j];  
            j--; 
        }
        ship[j+1] = temporary;
   	}
}

	//adinda
void sortDescTotalBerat(){
	//insertion sort
	int i;
	int n = shippingSize;
    for (i = 1; i < n; i++) {
    struct shipping temp = ship[i];
    int j = i - 1;
    while (j >= 0 && ship[j].total_berat < temp.total_berat) {
      ship[j+1] = ship[j];
      j--;
    }
    ship[j+1] = temp;
  }
}

void addShipping(){
		shippingSize++;
		int i = shippingSize - 1;
		if (i < 30){
		printf("%d. ", shippingSize);
		printf("Nama Pembeli: ");
		scanf(" %[^\n]", ship[i].nama_pembeli);
		printf("\nNegara tujuan: ");
		scanf(" %[^\n]", ship[i].negara);
		while (1) {
     	 printf("Estimasi Jarak (km): ");
     	 if (scanf("%f", &ship[i].jarak) == 1 && ship[i].jarak >= 0) {
        break;
     	 }
     	 printf("Masukkan jarak yang valid (angka positif)\n");
     	 while (getchar() != '\n');  // clear the input buffer
    	}
	
		int found = 0; // flag to keep track of whether the id_produk was found or not

	while (found != 1) { // outer loop to repeat the process until the id_produk is found
  		printf("ID Produk: ");
  		scanf("%d", &ship[i].id_produk);

  // inner loop to check if the entered id_produk exists in the warehouse struct
  		int j;
  		for (j = 0; j < warehouseSize; j++) {
    		if (ship[i].id_produk == warehouse[j].id_produk) {
     		found = 1; // id_produk was found
     		strcpy(ship[i].nama_produk, warehouse[j].nama_produk);
    		break;
  	  }
  }

  // if the id_produk was not found, ask the user to enter a different id_produk
 		 if (!found) {
   			 printf("ID produk tidak ditemukan. Silakan masukkan ID produk yang valid.\n");
 		 }	
	}
		
		
		printf("Jumlah barang: ");
		scanf("%d", &ship[i].qty);

		found = 0;

		while (found != 1) {
 		 // search for the product in the warehouse array
 		 int j;
  		 for (j = 0; j < warehouseSize; j++) {
   		 if (ship[i].id_produk == warehouse[j].id_produk) {
         // check if the quantity is valid (tidak melebihi stok warehouse)
         if (ship[i].qty <= warehouse[j].stok) {
         found = 1; // quantity is valid, exit the loop
         break;
         } else {
         printf("!!\t Jumlah pembelian melebihi stok yang ada\t !!\n");
         printf("Stok warehouse = %d\n", warehouse[j].stok);
         printf("Jumlah barang: ");
         scanf("%d", &ship[i].qty);
       }
     }
   }
 }
	 	printf("Data berhasil ditambahkan\n");
		} else {
		printf("Data shipping sudah penuh\n");
	   }
      }

void sortAscQty(){
	//adinda
	int i, j;
	int n = shippingSize;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (ship[j].qty > ship[j + 1].qty)
			{
				// Swap data data[j] dan data[j+1] jika diperlukan
				struct shipping temp = ship[j];
				ship[j] = ship[j + 1];
				ship[j + 1] = temp;
			}
		}
	}
}


void sequentialSearchNamaPembeli() {
	//adinda
	char nama_pembeli[255];
	printf("Masukkan Nama Pembeli: ");
	scanf(" %[^\n]", &nama_pembeli);
	int i;
	int found = 0;
    for (i = 0; i < shippingSize; i++) {
	    //compare nama_pembeli yang dicari dengan setiap data ship[i].nama_pembeli, cari hingga ada yang sama ( == 0)
        if (strcmp(ship[i].nama_pembeli, nama_pembeli) == 0) {
            printf("Shipping data untuk %s ditemukan pada index %d: \n", nama_pembeli, i);
			printf("Nama Pembeli: %s\n", ship[i].nama_pembeli);
			printf("Negara: %s\n", ship[i].negara);
			printf("Jarak: %.2f\n", ship[i].jarak);
			printf("ID Produk: %d\n", ship[i].id_produk);
			printf("Nama Produk: %s\n", ship[i].nama_produk);
			printf("Quantity: %d\n", ship[i].qty);
			printf("Berat Total: %.2fkg\n", ship[i].total_berat);
			printf("Biaya Kirim: Rp.%d\n", ship[i].ongkir);
			found = 1;
        }
     } if (found == 0) {
		printf("Shipping data atas nama %s tidak ditemukan.\n", nama_pembeli);
	}
}

void update(){
	int i, j;
	int found;
	for (i = 0; i < shippingSize; i++) {
    int found = 0;
    for (j = 0; j < penjualanSize; j++) {
    if (data[j].id_produk == ship[i].id_produk && !data[i].processed) {
      data[j].jumlah_terjual += ship[i].qty;
      found = 1;
      break;
    }
  }
  if (found == 0) {
    for (j = 0; j < warehouseSize; j++) {
      if (warehouse[j].id_produk == ship[i].id_produk && !data[i].processed) {
        data[penjualanSize] = (struct data_penjualan){warehouse[j].id_produk, warehouse[j].nama_produk, warehouse[j].base_price, warehouse[j].sell_price, ship[i].qty, 0, 0};
        penjualanSize++;
        break;
      }
    }
  }		int jumlah = data[i].jumlah_terjual;
  		int sell = data[i].sell_price;
  		int buy = data[i].base_price;
        data[i].total_profit = jumlah * (sell - buy);
        data[i].processed = 1;
  }
  
    		for (i = 0; i < shippingSize; i++){
    		//update berat dan stok
    	        if (ship[i].processed == 1) continue;{ //kalau data index sudah pernah diupdate, maka skip
  		for (j = 0; j < warehouseSize; j++) {
   	 	if (ship[i].id_produk == warehouse[j].id_produk) {
     		//perhitungan total_berat
     		float qty = ship[i].qty;
     		float brt = warehouse[j].berat;
		ship[i].total_berat = brt * qty;
		//update stok barang pada warehouse
		int stok = warehouse[j].stok;
		warehouse[j].stok = stok - qty;
		//processed = 1 untuk menandai tersebut sudah diupdate
		ship[i].processed = 1;
		ship[i].ongkir = (ship[i].total_berat*12800) + (ship[i].jarak*400);
		}
	 }
 	}
 }
}

int printPenjualan() {
  int i;
  printf("\n");
  printf("===============================  Data Penjualan  ================================\n");
  printf("|%-3s|     %-15s|%-11s|%-11s| %-9s| %-9s  |\n", "ID", "Nama Produk", "Harga Beli", "Harga Jual", "Total Terjual", "Total Profit" );
  for (i = 0; i < penjualanSize; i++) {
    if (data[i].id_produk == 0) {
      continue;  // skip this iteration and move on to the next one
    }
    printf("| %-2d| %-19s|Rp.%-8d|Rp.%-8d|      %-8d| Rp.%-11d|\n", data[i].id_produk, data[i].nama_produk, data[i].base_price, data[i].sell_price, data[i].jumlah_terjual, data[i].total_profit);
  }printf("=================================================================================\n");
}

//varrel
void sortAscProfit()
{
	int i, j;
	int n = penjualanSize;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (data[j].total_profit > data[j + 1].total_profit)
			{
				// Swap data data[j] dan data[j+1] jika diperlukan
				struct data_penjualan temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

//varrel
void sortDescProfit()
{
	int i, j;
	int n = penjualanSize;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (data[j].total_profit < data[j + 1].total_profit)
			{
				// Swap data data[j] and data[j+1] if needed
				struct data_penjualan temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

//varrel
// Fungsi untuk mengurutkan data penjualan berdasarkan jumlah produk yang terjual (ascending)
void sortAscJumlahTerjual()
{
	int i, j;
	int n = penjualanSize;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (data[j].jumlah_terjual > data[j + 1].jumlah_terjual)
			{
				// Swap data data[j] dan data[j+1] jika diperlukan
				struct data_penjualan temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

//varrel
void sortDescJumlahTerjual()
{
	int i;
	int j;
	int n = penjualanSize;
	for (i = 0; i < n - 1; i++)
	{
		// Find the maximum element in the unsorted array
		int max_index = i;
		for (j = i + 1; j < n; j++)
		{
			if (data[j].jumlah_terjual > data[max_index].jumlah_terjual)
			{
				max_index = j;
			}
		}
		// Swap the maximum element with the first element of the unsorted array
		struct data_penjualan temp = data[i];
		data[i] = data[max_index];
		data[max_index] = temp;
	}
}

//varrel
void searchNamaProdukTabel3(){
	//sequential search
	char namaProduk[255];
	printf("Masukkan Nama Produk: ");
	scanf(" %[^\n]", &namaProduk);
	int i;
	int found = 0;
    for (i = 0; i < penjualanSize; i++) {
	    //compare nama_pembeli yang dicari dengan setiap data ship[i].nama_pembeli, cari hingga ada yang sama ( == 0)
        if (strcmp(data[i].nama_produk, namaProduk) == 0) {
            printf("Data Penjualan Nama Produk %s ditemukan pada index %d: \n", namaProduk, i);
			printf("Id produk: %d\n", data[i].id_produk);
			printf("Nama produk: %s\n", data[i].nama_produk);
			printf("Harga Beli: %d\n", data[i].base_price);
			printf("Harga Jual: %d\n", data[i].sell_price);
			printf("Total Terjual: %d\n", data[i].jumlah_terjual);
			printf("Total Keuntungan: %d\n", data[i].total_profit);
			found = 1;
        }
     } if (found == 0) {
		printf("penjualan data atas nama %s tidak ditemukan.\n", namaProduk);
	}
}

int main(){
	//input data kedalam index struct wh & ship
	warehouse[0] = (struct wh){"Minyak kelapa sawit", 1, 1000, 0.92, 25000, 55000};
	warehouse[1] = (struct wh){"Minyak kelapa", 2, 1200, 0.92, 55000, 89000};
	warehouse[2] = (struct wh){"Rempah-rempah", 3, 20000, 0.25, 4000, 9000};
	warehouse[3] = (struct wh){"Udang", 4, 500, 1, 109000, 156000};
	warehouse[4] = (struct wh){"Tekstil", 5, 8000, 0.3, 10000, 25000};
	warehouse[5] = (struct wh){"Kakao", 6, 1000, 1, 20000, 55000};
	warehouse[6] = (struct wh){"Kayu Mahoni", 7, 1000, 8, 500000, 650000};
	warehouse[7] = (struct wh){"Karet", 8, 2000, 1, 18000, 36000};
 	warehouse[8] = (struct wh){"Nikel", 9, 5000, 1, 300000, 412000};
	warehouse[9] = (struct wh){"Sabut Kelapa", 10, 1000, 1, 5000, 11000};
	warehouse[10] = (struct wh){"Barel Minyak Mentah", 11, 20, 136, 1120000, 1372900};
	warehouse[11] = (struct wh){"Arang Briket", 12, 2500, 1, 6000, 18000};
	warehouse[12] = (struct wh){"Kayu Jati", 13, 100, 8, 38000, 70000};
	warehouse[13] = (struct wh){"Sarang Burung Walet", 14, 100, 1, 8000000, 10000000};
	warehouse[14] = (struct wh){"Biji Kopi", 15, 2000, 1, 3000, 10000};
	ship[0] = (struct shipping){"John Smith", "United States", 5000, 1, "Minyak kelapa sawit", 300, 0, 0, 0};
	ship[1] = (struct shipping){"Jane Doe", "China", 8000, 2, "Minyak kelapa", 500, 0, 0, 0};
	ship[2] = (struct shipping){"Robert Johnson", "India", 4000, 7, "Kayu Mahoni", 200, 0, 0, 0};
	ship[3] = (struct shipping){"Emily Williams", "Japan", 10000, 5, "Tekstil", 1200, 0, 0, 0};
	ship[4] = (struct shipping){"Michael Brown", "France", 6000, 4, "Udang", 120, 0, 0, 0};
	ship[5] = (struct shipping){"Samantha Jones", "United Kingdom", 7000, 6, "Kakao", 200, 0, 0, 0};
	ship[6] = (struct shipping){"Christopher Davis", "Germany", 9000, 3, "Rempah-rempah", 3600, 0, 0, 0};
	ship[7] = (struct shipping){"Ashley Johnson", "Russia", 8000, 8, "Karet", 1000, 0, 0};
	ship[8] = (struct shipping){"Daniel Thompson", "Spain", 7000, 9, "Nikel", 1250, 0, 0, 0};
	ship[9] = (struct shipping){"Sarah Smith", "Brazil", 8000, 10, "Sabut Kelapa", 433, 0, 0, 0};
	ship[10] = (struct shipping){"Jason Davis", "Australia", 10000, 11, "Barel Minyak Mentah", 10, 0, 0, 0};
	ship[11] = (struct shipping){"Laura Williams", "South Africa", 9000, 12, "Arang Briket", 120, 0, 0, 0};
	ship[12] = (struct shipping){"Michael Thompson", "Mexico", 7000, 13, "Kayu Jati", 7, 0, 0, 0};
	ship[13] = (struct shipping){"Emily Johnson", "Canada", 8000, 14, "Sarang Burung Walet", 12, 0, 0, 0};
	ship[14] = (struct shipping){"John Davis", "Argentina", 9000, 15, "Biji Kopi", 1100, 0, 0, 0};
	warehouseSize = 15;
	shippingSize = 15;
	int i;
	
	//copy data warehouse ke penjualan
  	for (i = 0; i < warehouseSize; i++) {
    data[i].id_produk = warehouse[i].id_produk;
    strcpy(data[i].nama_produk, warehouse[i].nama_produk);
    data[i].base_price = warehouse[i].base_price;
    data[i].sell_price = warehouse[i].sell_price;
    penjualanSize++;
    }
    
	mainmenu:
	//while(1) untuk infinite loop ke menu
	while(1){
		int pil;
		printf("\n===  Program Sistem Informasi Pergudangan & Shipping  ===\n\t\t1. Data Warehouse\n\t\t2. Data Shipping\n\t\t3. Data Penjualan\n\n\t\t0. Exit program\n\n Input:");
		while (1) {
  		if (scanf("%d", &pil) == 1 && pil >= 0 && pil <= 3) {
   		 break;
  		}
  		printf("Masukkan input yang valid (angka 0-3)\n");
  		while (getchar() != '\n');  // clear the input buffer
		}
		if (pil == 1){
		update();
		int i, j, id;
		printWarehouse();
		int menu;
		printf("\n[1]Search data menggunakan ID produk\n[2]Sort dari produk paling ringan\n[3]Sort dari produk paling berat\n[4]Sort dari jumlah stok paling sedikit\n[5]Sort dari jumlah stok terbanyak\n[6]Search Nama Produk\n[7]Update Stock\n[8]Kembali\n\n\tMasukkan Input: ");
			scanf("%d", &menu);
			switch (menu)
			{
			case 1:
				printf("Search by Product ID = ");
				scanf("%d", &id);
				int index = binarySearchIDProduk(id);
				if (index >= 0) {
  				printf("Found produk dengan ID %d terletak pada index %d:\n", id, index);
  				printf("  Nama Produk: %s\n", warehouse[index].nama_produk);
  				printf("  Berat: %.2fkg\n", warehouse[index].berat);
  				printf("  Stock: %d\n", warehouse[index].stok);
  				printf("  Harga beli: Rp.%d\n", warehouse[index].base_price);
  				printf("  Harga jual: Rp.%d\n", warehouse[index].sell_price);
				} else {
  				printf("Warehouse with id %d not found.\n", id);
				}
				system("pause");
				system("cls");
				break;
			case 2:
				sortAscBerat();
				printWarehouse();
				system("pause");
				system("cls");
				break;
			case 3:
				sortDescBerat();
				printWarehouse();
				system("pause");
				system("cls");
				break;
			case 4:
				sortAscStok();
				printWarehouse();
				system("pause");
				system("cls");
				break;
			case 5:
				sortDescStok();
				printWarehouse();
				system("pause");
				system("cls");
				break;
			case 6:
				searchWarehouseNama();
				system("pause");
				system("cls");
			break;
			case 7:
				updateStockWarehouse();
				break;
			case 8:
				system("cls");
				goto mainmenu;
				break;
			default: 
				break;
			}

	} 
	else if (pil == 2){
		update();
		printShipping();
		printf("\n[1]Tambahkan data baru shipping\n[2]Sort Berdasarkan ID Produk\n[3]Sort dari paling ringan\n[4]Sort dari paling berat\n[5]Sort dari jumlah qty paling sedikit\n[6]Search Nama Pembeli\n[7]Kembali\n\n\tMasukkan Input: ");
		int menu, index;
     	scanf("%d", &menu);
	    switch (menu)
		{
	    case 1:
	    	addShipping();
	   		break;
	    case 2:
	    	sortAscIDTabel2();
			printShipping();
			system("pause");
			system("cls");
			break;
	    case 3:
	    	sortAscTotalBerat();
			system("pause");
			system("cls");
			printShipping();
			break;
	    case 4:
	    	sortDescTotalBerat();
			system("pause");
			system("cls");
			printShipping();
			break;
	    case 5:
	    	sortAscQty();
	    	printShipping(); 
			system("pause");
			system("cls");
			break;
	    case 6:
			sequentialSearchNamaPembeli();
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			goto mainmenu;
			break;
	    default:
	    	break;
}

	}else if (pil == 3){
		update();
		update();
		printPenjualan();
		
		printf("\n1. Sort berdasarkan keuntungan terkecil\n2. Sort berdasarkan keuntungan tertinggi\n3. Sort berdasarkan jumlah terjual terendah\n4. Sort berdasarkan jumlah penjualan tertinggi\n5. Search Nama Produk\n6. Kembali\n\n\tMasukkan Input: ");
		int menu;
		scanf("%d", &menu);
		switch (menu){
			case 1:
				sortAscProfit();
	 			printPenjualan();
	 			system("pause");
				system("cls");
				break;
			case 2:
				sortDescProfit();
				printPenjualan();
				system("pause");
				system("cls");
				break;
			case 3:
				sortAscJumlahTerjual();
				printPenjualan();
				system("pause");
				system("cls");
				break;
			case 4:
				sortDescJumlahTerjual();
				printPenjualan();
				system("pause");
				system("cls");
				break;
			case 5:
				searchNamaProdukTabel3();
				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				goto mainmenu;
			default:
				break;
		}
   } else if (pil == 0){
   	exit (0);
   }
  }
}
