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
	
	mainmenu:
	//while(1) untuk infinite loop ke menu
	while(1){
	int pil;
	printf("\n1. Data warehouse\n2. Data Shipping\n3. Data Penjualan\n Input:");
	scanf("%d", &pil);		
	if (pil == 1){
		
		int pil1_2;
		printf("[1]Search data menggunakan ID produk\n[2]Sort dari produk paling ringan\n[3]Sort dari produk paling berat\n[4]Sort dari jumlah stok terbanyak\n[5]Sort dari jumlah stok paling sedikit\n[6]Search Nama Produk\n[7]Kembali\nMasukkan Input: ");
		scanf("%d", &pil1_2);
		if(pil1_2 == 1){
			
			
		} else if (pil1_2 == 2){
		
		
		} else if (pil1_2 == 3){
		
		
		} else if (pil1_2 == 4){
		
		
		} else if (pil1_2 == 5){
		
		
		} else if (pil1_2 == 6){
	
	
		} else if (pil1_2 == 7){
			goto mainmenu;
			break;
		}	
	} 
	
	else if (pil == 2){
		printf("[1]Tambahkan data baru shipping\n[2]Sort Berdasarkan ID Produk\n[3]Sort dari paling ringan\n[4]Sort dari paling berat\n[5]Sort dari jumlah qty paling sedikit\n[6]Search Nama Pembeli\n[7]Kembali\nMasukkan Input: ");
		int pil2_2;
     	scanf("%d", &pil2_2);
	    if (pil2_2 == 1){
	    	
	    	
		} else if (pil2_2 == 2){
			
			
		} else if (pil2_2 == 3){
		
		
		} else if (pil2_2 == 4){
			
			
		} else if (pil2_2 == 5){
	
	
		} else if (pil2_2 == 6){
			
			
		}
	
}

	else if (pil == 3){
		printf("1. Sort berdasarkan keuntungan terkecil\n2.Sort berdasarkan keuntungan tertinggi\n3. Sort berdasarkan jumlah terjual terendah\n4. Sort berdasarkan jumlah penjualan tertinggi\n5. Search Nama Produk\nMasukkan Input: ");
		int pil3_2;
		scanf("%d", &pil3_2);
	 if (pil3_2 == 1){
	 	
	 	
	} else if (pil3_2 == 2){
		
		
	} else if (pil3_2 == 3){
		
		
	} else if (pil3_2 == 4){
	
	
	} else if (pil3_2 == 5){
	
	
	}
   }
  }
}
