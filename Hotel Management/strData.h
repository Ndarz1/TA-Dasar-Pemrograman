#include <string>
#include <string>
#ifndef strData_h
#define strData_h

struct strData
{
  // Kota & bulan
  int kotaLiburan, jumlah, month, tanggal, tahun, nextDay, totalHari;

  // Pengunjung
  int dewasa, anak, kamar, kasur, totalPengunjung;

  // Room
  int harga, total, noKamar;

  // Tipe char
  char ulang;

  // Akun login
  char ch;

  // data kamar
  long long int nik, hp;

  // Fasilitas
  int hargaFas;
  int fas;
  char fasTam;

  // pembayaran
  char bayar;
  double totalBayar;
  int hasil;

  // data pengunjung
  int pilDat;

 
  // diskon
  double diskon, hargaAwal, totalHarga, hargaPersen;
};
#endif // !strData_h
