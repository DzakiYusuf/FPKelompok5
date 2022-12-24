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