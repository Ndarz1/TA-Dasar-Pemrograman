#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "../data/resetKamar.h"
#include "../strData.h"
#ifndef denpasar_h
#define denpasar_h
using namespace std;

void denpasar()
{
  // Struct
  strData date, pengunjung, room, data, dataPengunjung;

  // Tipe data
  string nama;

  // Array fasilitas
  room.hargaFas = 5;
  string fasilitas[room.hargaFas] = {"Antar jemput", "Makan malam", "Makan siang", "Makan pagi", "Tambah kasur"};
  int hargaFasilitas[room.hargaFas] = {230000, 300000, 150000, 180000, 100000};

  // Array room
  string kelas[] = {"Value room", "Deluxe room", "Executive room", "Suite room"};

  // Array bulan
  string bulan[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

  room.jumlah = sizeof(kelas) / sizeof(kelas[0]);

  // Jam
  time_t saatIni = time(0);
  tm *ltm = localtime(&saatIni);

  // Tanggal Booking
  cout << "================================================================" << endl;
  cout << "\t\t\tYogyakarta" << endl;
  cout << "================================================================" << endl;
  cout << "Tanggal melakukan booking" << endl;
  cout << endl;
  cout << "Masukkan tanggal awal boooking\t: ";
  cin >> date.tanggal;
  cout << "Masukkan bulan\t\t\t: ";
  cin >> date.month;
  cout << "Masukkan tahun\t\t\t: ";
  cin >> date.tahun;
  cout << "Masukkan jumlah hari memesan\t: ";
  cin >> date.nextDay;
  cout << "================================================================" << endl;

  cout << "\033[2J\033[H";

  // Kelas kamar
  cout << "================================================================" << endl;
  cout << "\t\t\tKelas kamar" << endl;
  cout << "================================================================" << endl;
  for (int i = 0; i < room.jumlah; ++i)
  {
    cout << "\t" << i + 1 << ". " << kelas[i] << endl;
  }
  cout << "Pilih tipe kamar: ";
  cin >> room.kamar;
  cout << "================================================================" << endl;
  cout << "\033[2J\033[H";

  // Tipe kamar
  if (room.kamar == 1)
  {
    room.total = room.harga = 350000;
    cout << "================================================================" << endl;
    cout << "\t\t\tValue Room" << endl;
    cout << "================================================================" << endl;
    cout << "\t1 Queen bed\t\t\t2 Guets" << endl;
    cout << "\tWithout Breakfast\t\tNon-refundable" << endl;
    cout << "\tFree Wifi\t\t\tNon-reschedule" << endl;
    cout << "\tNon-smoking" << endl;

    // No kamar
    ofstream fileKamar("kamarData.txt", ios::app);
    if (!fileKamar.is_open())
    {
      cout << "Tidak dapat membuka file!!" << endl;
    }
    for (int i = 100; i <= 110; ++i)
    {
      char tipeKamar = (i <= 110) ? 'A' : 'B';
      fileKamar << i << " " << tipeKamar << endl;
    }

    fileKamar.close();

    // Membaca no kamar
    ifstream bacaKamar("kamarData.txt");

    if (!bacaKamar.is_open())
    {
      cout << "Tidak dapat membuka file!!" << endl;
    }

    vector<int> nomorKamar;
    int nomor;
    char jenis;
    while (bacaKamar >> nomor >> jenis)
    {
      nomorKamar.push_back(nomor);
    }
    bacaKamar.close();

    // Memilih no kamar
    cout << "================================================================" << endl;
    cout << "Nomor kamar tersedia: " << endl;
    for (int i = 0; i < nomorKamar.size(); ++i)
    {
      cout << i + 1 << ". " << nomorKamar[i] << endl;
    }
    cout << endl;
    cout << "================================================================" << endl;
    cout << "Pilih no kamar (1-" << nomorKamar.size() << "): ";
    cin >> room.noKamar;
    if (room.noKamar >= 1 && room.noKamar <= nomorKamar.size())
    {
      cout << "Nomor kamar anda: " << nomorKamar[room.noKamar - 1] << endl;
    }

    cout << "\033[2J\033[H";

    // Pengunjung
    cout << "================================================================" << endl;
    cout << "\t\t\tJumlah pengunjung" << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan jumlah orang dewasa\t\t: ";
    cin >> pengunjung.dewasa;
    cout << "Masukkan jumlah anak-anak\t\t: ";
    cin >> pengunjung.anak;

    while ((pengunjung.dewasa > 2 && pengunjung.anak > 3) || (pengunjung.dewasa > 2 || pengunjung.anak > 3))
    {
      cout << "Anda harus menambah kamar (y/t) ?\t: ";
      cin >> room.ulang;
      if (room.ulang == 'y' || room.ulang == 'Y')
      {
        room.total = room.harga * 2;
        cout << "Harga total\t\t\t\t: " << room.total << endl;
        break;
      }
      else
      {
        cout << "Silahkan pilih menu lain" << endl;
        break;
      }
      cout << "================================================================" << endl;
    }

    // Fasilitas tambahan
    cout << "Memerlukan fasilitas tambahaan (y/t) ?\t: ";
    cin >> room.fasTam;
    cout << "\033[2J\033[H";

    if (room.fasTam == 'y' || room.fasTam == 'Y')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\t   Fasilitas" << endl;
      cout << "================================================================" << endl;
      cout << "\t\t\tDaftar fasilitas" << endl;
      cout << endl;
      for (int i = 0; i < room.hargaFas; ++i)
      {
        cout << i + 1 << ". "
             << "Fasilitas: " << fasilitas[i] << "\t\t Harga: Rp." << hargaFasilitas[i] << endl;
      }
      cout << "================================================================" << endl;
      cout << "Silakan pilih fasilitas: ";
      cin >> room.fas;
    }

    cout << "\033[2J\033[H";

    // Data kamar

    pengunjung.totalPengunjung = pengunjung.dewasa + pengunjung.anak;
    for (int i = 0; i < pengunjung.totalPengunjung; i++)
    {

      cout << "================================================================" << endl;
      cout << "Silakan lengakapi data dibawah ini" << endl;
      cout << "Pengunjung - " << i + 1 << endl;
      cout << "================================================================" << endl;
      cout << endl;
      cout << "Nama\t\t: ";
      cin.ignore();
      getline(cin, nama);
      cout << "NIK\t\t: ";
      cin >> data.nik;
      cout << "No HP\t\t: ";
      cin >> data.hp;
      cout << endl;
      cout << "================================================================" << endl;
      cout << endl;
      // Menyimpan data pengunjung
      ofstream file("dataPengunjung.txt", ios::app);
      if (!file.is_open())
      {
        cerr << "File tidak dapat terbuka!!" << endl;
      }
      file << "Data - " << i + 1 << endl;
      file << "================================================================" << endl;
      file << "Nama: " << nama << "\n";
      file << "NIK: " << data.nik << "\n";
      file << "No HP: " << data.hp << "\n";
      file << "No kamar: " << nomorKamar[room.noKamar - 1] << "\n";
      file << "Jam: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      file << "Tanggal cek-in: " << date.tanggal << " " << bulan[date.tanggal - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }
      file << "Tanggal cek-out: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      file << "================================================================" << endl;
      file << endl;

      file.close();
    }
    cout << "\033[2J\033[H";

    // Pembayaran 1

    while (room.fasTam == 'y' || room.fasTam == 'Y')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\tInformasi pembayaran" << endl;
      cout << "================================================================" << endl;
      cout << "Nama\t\t\t: " << nama << endl;
      cout << "Tipe kamar\t\t: " << room.kamar[kelas - 1] << endl;
      cout << "Fasilitas\t\t: " << fasilitas[room.hargaFas - 1] << endl;
      cout << "No kamar\t\t: " << nomorKamar[room.noKamar - 1] << endl;
      cout << "Dewasa\t\t\t: " << pengunjung.dewasa << endl;
      cout << "Anak-anak\t\t: " << pengunjung.anak << endl;
      cout << "Jam\t\t\t: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      cout << "Tanggal cek-in\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }

      cout << "Tanggal cek-out\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      cout << endl;
      cout << "\t\t\t\t\tHarga\t: " << (room.total * date.nextDay) + hargaFasilitas[room.fas - 1] << endl;
      cout << "================================================================" << endl;
      break;
    }
    while (room.fasTam == 't' || room.fasTam == 'T')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\tInformasi pembayaran" << endl;
      cout << "================================================================" << endl;
      cout << "Nama\t\t\t: " << nama << endl;
      cout << "Tipe kamar\t\t: " << room.kamar[kelas - 1] << endl;
      cout << "No kamar\t\t: " << nomorKamar[room.noKamar - 1] << endl;
      cout << "Dewasa\t\t\t: " << pengunjung.dewasa << endl;
      cout << "Anak-anak\t\t: " << pengunjung.anak << endl;
      cout << "Jam\t\t\t: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      cout << "Tanggal cek-in\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }

      cout << "Tanggal cek-out\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      cout << endl;
      cout << "\t\t\t\t\tHarga\t: " << (room.total * date.nextDay) << endl;
      cout << "================================================================" << endl;
      break;
    }
    // Melihat data
    cout << "================================================================" << endl;
    cout << "\t\tMenampilkan data pengunjung" << endl;
    cout << "1. Menampilkan" << endl;
    cout << "2. Langsung bayar" << endl;
    cout << endl;
    cout << "Masukkan pilihan\t\t: ";
    cin >> dataPengunjung.pilDat;
    cout << endl;
    cout << "================================================================" << endl;
    cout << "\033[2J\033[H";

    if (dataPengunjung.pilDat == 1)
    {
      string opFile = "dataPengunjung.txt";

      ifstream file(opFile);

      if (!file.is_open())
      {
        cout << "Gagal membuka file: " << opFile << endl;
        return;
      }

      file.seekg(0, ios::end);
      size_t fileSize = file.tellg();
      file.seekg(0, ios::beg);

      string fileContent;
      fileContent.resize(fileSize);
      file.read(&fileContent[0], fileSize);

      cout << "Data pengunjung "
           << "\n"
           << fileContent << endl;

      file.close();
    }
    else if (dataPengunjung.pilDat == 2)
    {
    }

    // reset file pengunjung
    const char *filePengunjung = "dataPengunjung.txt";
    resetKamar(filePengunjung);
    // reset file no kamar
    const char *dataKamar = "kamarData.txt";
    resetKamar(dataKamar);
    // Pembayaran 2
  }
  else if (room.kamar == 2)
  {
    room.total = room.harga = 650000;
    cout << "================================================================" << endl;
    cout << "\t\t\tDeluxe Room" << endl;
    cout << "================================================================" << endl;
    cout << "\t1 Twin bed\t\t\t2 Guets" << endl;
    cout << "\tFree Breakfast\t\tNon-refundable" << endl;
    cout << "\tFree Wifi\t\t\tNon-reschedule" << endl;
    cout << "\tNon-smoking" << endl;
    cout << "================================================================" << endl;
    // No kamar
    ofstream fileKamar("kamarData.txt", ios::app);
    if (!fileKamar.is_open())
    {
      cout << "Tidak dapat membuka file!!" << endl;
    }
    for (int i = 100; i <= 110; ++i)
    {
      char tipeKamar = (i <= 110) ? 'A' : 'B';
      fileKamar << i << " " << tipeKamar << endl;
    }

    fileKamar.close();

    // Membaca no kamar
    ifstream bacaKamar("kamarData.txt");

    if (!bacaKamar.is_open())
    {
      cout << "Tidak dapat membuka file!!" << endl;
    }

    vector<int> nomorKamar;
    int nomor;
    char jenis;
    while (bacaKamar >> nomor >> jenis)
    {
      nomorKamar.push_back(nomor);
    }
    bacaKamar.close();

    // Memilih no kamar
    cout << "================================================================" << endl;
    cout << "Nomor kamar tersedia: " << endl;
    for (int i = 0; i < nomorKamar.size(); ++i)
    {
      cout << i + 1 << ". " << nomorKamar[i] << endl;
    }
    cout << endl;
    cout << "================================================================" << endl;
    cout << "Pilih no kamar (1-" << nomorKamar.size() << "): ";
    cin >> room.noKamar;
    if (room.noKamar >= 1 && room.noKamar <= nomorKamar.size())
    {
      cout << "Nomor kamar anda: " << nomorKamar[room.noKamar - 1] << endl;
    }

    cout << "\033[2J\033[H";

    // Pengunjung
    cout << "================================================================" << endl;
    cout << "\t\t\tJumlah pengunjung" << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan jumlah orang dewasa\t\t: ";
    cin >> pengunjung.dewasa;
    cout << "Masukkan jumlah anak-anak\t\t: ";
    cin >> pengunjung.anak;

    while ((pengunjung.dewasa > 2 && pengunjung.anak > 3) || (pengunjung.dewasa > 2 || pengunjung.anak > 3))
    {
      cout << "Anda harus menambah kamar (y/t) ?\t: ";
      cin >> room.ulang;
      if (room.ulang == 'y' || room.ulang == 'Y')
      {
        room.total = room.harga * 2;
        cout << "Harga total\t\t\t\t: " << room.total << endl;
        break;
      }
      else
      {
        cout << "Silahkan pilih menu lain" << endl;
        break;
      }
      cout << "================================================================" << endl;
    }

    // Fasilitas tambahan
    cout << "Memerlukan fasilitas tambahaan (y/t) ?\t: ";
    cin >> room.fasTam;
    cout << "\033[2J\033[H";

    if (room.fasTam == 'y' || room.fasTam == 'Y')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\t   Fasilitas" << endl;
      cout << "================================================================" << endl;
      cout << "\t\t\tDaftar fasilitas" << endl;
      cout << endl;
      for (int i = 0; i < room.hargaFas; ++i)
      {
        cout << i + 1 << ". "
             << "Fasilitas: " << fasilitas[i] << "\t\t Harga: Rp." << hargaFasilitas[i] << endl;
      }
      cout << "================================================================" << endl;
      cout << "Silakan pilih fasilitas: ";
      cin >> room.fas;
    }

    cout << "\033[2J\033[H";

    // Data kamar

    pengunjung.totalPengunjung = pengunjung.dewasa + pengunjung.anak;
    for (int i = 0; i < pengunjung.totalPengunjung; i++)
    {

      cout << "================================================================" << endl;
      cout << "Silakan lengakapi data dibawah ini" << endl;
      cout << "Pengunjung - " << i + 1 << endl;
      cout << "================================================================" << endl;
      cout << endl;
      cout << "Nama\t\t: ";
      cin.ignore();
      getline(cin, nama);
      cout << "NIK\t\t: ";
      cin >> data.nik;
      cout << "No HP\t\t: ";
      cin >> data.hp;
      cout << endl;
      cout << "================================================================" << endl;
      cout << endl;
      // Menyimpan data pengunjung
      ofstream file("dataPengunjung.txt", ios::app);
      if (!file.is_open())
      {
        cerr << "File tidak dapat terbuka!!" << endl;
      }
      file << "Data - " << i + 1 << endl;
      file << "================================================================" << endl;
      file << "Nama: " << nama << "\n";
      file << "NIK: " << data.nik << "\n";
      file << "No HP: " << data.hp << "\n";
      file << "No kamar: " << nomorKamar[room.noKamar - 1] << "\n";
      file << "Jam: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      file << "Tanggal cek-in: " << date.tanggal << " " << bulan[date.tanggal - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }
      file << "Tanggal cek-out: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      file << "================================================================" << endl;
      file << endl;

      file.close();
    }
    cout << "\033[2J\033[H";

    // Pembayaran 1

    while (room.fasTam == 'y' || room.fasTam == 'Y')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\tInformasi pembayaran" << endl;
      cout << "================================================================" << endl;
      cout << "Nama\t\t\t: " << nama << endl;
      cout << "Tipe kamar\t\t: " << room.kamar[kelas - 1] << endl;
      cout << "Fasilitas\t\t: " << fasilitas[room.hargaFas - 1] << endl;
      cout << "No kamar\t\t: " << nomorKamar[room.noKamar - 1] << endl;
      cout << "Dewasa\t\t\t: " << pengunjung.dewasa << endl;
      cout << "Anak-anak\t\t: " << pengunjung.anak << endl;
      cout << "Jam\t\t\t: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      cout << "Tanggal cek-in\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }

      cout << "Tanggal cek-out\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      cout << endl;
      cout << "\t\t\t\t\tHarga\t: " << (room.total * date.nextDay) + hargaFasilitas[room.fas - 1] << endl;
      cout << "================================================================" << endl;
      break;
    }
    while (room.fasTam == 't' || room.fasTam == 'T')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\tInformasi pembayaran" << endl;
      cout << "================================================================" << endl;
      cout << "Nama\t\t\t: " << nama << endl;
      cout << "Tipe kamar\t\t: " << room.kamar[kelas - 1] << endl;
      cout << "No kamar\t\t: " << nomorKamar[room.noKamar - 1] << endl;
      cout << "Dewasa\t\t\t: " << pengunjung.dewasa << endl;
      cout << "Anak-anak\t\t: " << pengunjung.anak << endl;
      cout << "Jam\t\t\t: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      cout << "Tanggal cek-in\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }

      cout << "Tanggal cek-out\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      cout << endl;
      cout << "\t\t\t\t\tHarga\t: " << (room.total * date.nextDay) << endl;
      cout << "================================================================" << endl;
      break;
    }
    // Melihat data
    cout << "================================================================" << endl;
    cout << "\t\tMenampilkan data pengunjung" << endl;
    cout << "1. Menampilkan" << endl;
    cout << "2. Langsung bayar" << endl;
    cout << endl;
    cout << "Masukkan pilihan\t\t: ";
    cin >> dataPengunjung.pilDat;
    cout << endl;
    cout << "================================================================" << endl;
    cout << "\033[2J\033[H";

    if (dataPengunjung.pilDat == 1)
    {
      string opFile = "dataPengunjung.txt";

      ifstream file(opFile);

      if (!file.is_open())
      {
        cout << "Gagal membuka file: " << opFile << endl;
        return;
      }

      file.seekg(0, ios::end);
      size_t fileSize = file.tellg();
      file.seekg(0, ios::beg);

      string fileContent;
      fileContent.resize(fileSize);
      file.read(&fileContent[0], fileSize);

      cout << "Data pengunjung "
           << "\n"
           << fileContent << endl;

      file.close();
    }
    else if (dataPengunjung.pilDat == 2)
    {
    }

    // reset file pengunjung
    const char *filePengunjung = "dataPengunjung.txt";
    resetKamar(filePengunjung);
    // reset file no kamar
    const char *dataKamar = "kamarData.txt";
    resetKamar(dataKamar);
    // Pembayaran 2
  }
  else if (room.kamar == 3)
  {
    room.total = room.harga = 1200000;
    cout << "================================================================" << endl;
    cout << "\t\t\tExecutive Room" << endl;
    cout << "================================================================" << endl;
    cout << "\t1 King bed\t\t\t2 Guets" << endl;
    cout << "\tFree Breakfast\t\tNon-refundable" << endl;
    cout << "\tFree Wifi\t\t\tNon-reschedule" << endl;
    cout << "\tNon-smoking" << endl;
    cout << "================================================================" << endl;
    // No kamar
    ofstream fileKamar("kamarData.txt", ios::app);
    if (!fileKamar.is_open())
    {
      cout << "Tidak dapat membuka file!!" << endl;
    }
    for (int i = 100; i <= 110; ++i)
    {
      char tipeKamar = (i <= 110) ? 'A' : 'B';
      fileKamar << i << " " << tipeKamar << endl;
    }

    fileKamar.close();

    // Membaca no kamar
    ifstream bacaKamar("kamarData.txt");

    if (!bacaKamar.is_open())
    {
      cout << "Tidak dapat membuka file!!" << endl;
    }

    vector<int> nomorKamar;
    int nomor;
    char jenis;
    while (bacaKamar >> nomor >> jenis)
    {
      nomorKamar.push_back(nomor);
    }
    bacaKamar.close();

    // Memilih no kamar
    cout << "================================================================" << endl;
    cout << "Nomor kamar tersedia: " << endl;
    for (int i = 0; i < nomorKamar.size(); ++i)
    {
      cout << i + 1 << ". " << nomorKamar[i] << endl;
    }
    cout << endl;
    cout << "================================================================" << endl;
    cout << "Pilih no kamar (1-" << nomorKamar.size() << "): ";
    cin >> room.noKamar;
    if (room.noKamar >= 1 && room.noKamar <= nomorKamar.size())
    {
      cout << "Nomor kamar anda: " << nomorKamar[room.noKamar - 1] << endl;
    }

    cout << "\033[2J\033[H";

    // Pengunjung
    cout << "================================================================" << endl;
    cout << "\t\t\tJumlah pengunjung" << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan jumlah orang dewasa\t\t: ";
    cin >> pengunjung.dewasa;
    cout << "Masukkan jumlah anak-anak\t\t: ";
    cin >> pengunjung.anak;

    while ((pengunjung.dewasa > 2 && pengunjung.anak > 3) || (pengunjung.dewasa > 2 || pengunjung.anak > 3))
    {
      cout << "Anda harus menambah kamar (y/t) ?\t: ";
      cin >> room.ulang;
      if (room.ulang == 'y' || room.ulang == 'Y')
      {
        room.total = room.harga * 2;
        cout << "Harga total\t\t\t\t: " << room.total << endl;
        break;
      }
      else
      {
        cout << "Silahkan pilih menu lain" << endl;
        break;
      }
      cout << "================================================================" << endl;
    }

    // Fasilitas tambahan
    cout << "Memerlukan fasilitas tambahaan (y/t) ?\t: ";
    cin >> room.fasTam;
    cout << "\033[2J\033[H";

    if (room.fasTam == 'y' || room.fasTam == 'Y')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\t   Fasilitas" << endl;
      cout << "================================================================" << endl;
      cout << "\t\t\tDaftar fasilitas" << endl;
      cout << endl;
      for (int i = 0; i < room.hargaFas; ++i)
      {
        cout << i + 1 << ". "
             << "Fasilitas: " << fasilitas[i] << "\t\t Harga: Rp." << hargaFasilitas[i] << endl;
      }
      cout << "================================================================" << endl;
      cout << "Silakan pilih fasilitas: ";
      cin >> room.fas;
    }

    cout << "\033[2J\033[H";

    // Data kamar

    pengunjung.totalPengunjung = pengunjung.dewasa + pengunjung.anak;
    for (int i = 0; i < pengunjung.totalPengunjung; i++)
    {

      cout << "================================================================" << endl;
      cout << "Silakan lengakapi data dibawah ini" << endl;
      cout << "Pengunjung - " << i + 1 << endl;
      cout << "================================================================" << endl;
      cout << endl;
      cout << "Nama\t\t: ";
      cin.ignore();
      getline(cin, nama);
      cout << "NIK\t\t: ";
      cin >> data.nik;
      cout << "No HP\t\t: ";
      cin >> data.hp;
      cout << endl;
      cout << "================================================================" << endl;
      cout << endl;
      // Menyimpan data pengunjung
      ofstream file("dataPengunjung.txt", ios::app);
      if (!file.is_open())
      {
        cerr << "File tidak dapat terbuka!!" << endl;
      }
      file << "Data - " << i + 1 << endl;
      file << "================================================================" << endl;
      file << "Nama: " << nama << "\n";
      file << "NIK: " << data.nik << "\n";
      file << "No HP: " << data.hp << "\n";
      file << "No kamar: " << nomorKamar[room.noKamar - 1] << "\n";
      file << "Jam: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      file << "Tanggal cek-in: " << date.tanggal << " " << bulan[date.tanggal - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }
      file << "Tanggal cek-out: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      file << "================================================================" << endl;
      file << endl;

      file.close();
    }
    cout << "\033[2J\033[H";

    // Pembayaran 1

    while (room.fasTam == 'y' || room.fasTam == 'Y')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\tInformasi pembayaran" << endl;
      cout << "================================================================" << endl;
      cout << "Nama\t\t\t: " << nama << endl;
      cout << "Tipe kamar\t\t: " << room.kamar[kelas - 1] << endl;
      cout << "Fasilitas\t\t: " << fasilitas[room.hargaFas - 1] << endl;
      cout << "No kamar\t\t: " << nomorKamar[room.noKamar - 1] << endl;
      cout << "Dewasa\t\t\t: " << pengunjung.dewasa << endl;
      cout << "Anak-anak\t\t: " << pengunjung.anak << endl;
      cout << "Jam\t\t\t: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      cout << "Tanggal cek-in\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }

      cout << "Tanggal cek-out\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      cout << endl;
      cout << "\t\t\t\t\tHarga\t: " << (room.total * date.nextDay) + hargaFasilitas[room.fas - 1] << endl;
      cout << "================================================================" << endl;
      break;
    }
    while (room.fasTam == 't' || room.fasTam == 'T')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\tInformasi pembayaran" << endl;
      cout << "================================================================" << endl;
      cout << "Nama\t\t\t: " << nama << endl;
      cout << "Tipe kamar\t\t: " << room.kamar[kelas - 1] << endl;
      cout << "No kamar\t\t: " << nomorKamar[room.noKamar - 1] << endl;
      cout << "Dewasa\t\t\t: " << pengunjung.dewasa << endl;
      cout << "Anak-anak\t\t: " << pengunjung.anak << endl;
      cout << "Jam\t\t\t: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      cout << "Tanggal cek-in\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }

      cout << "Tanggal cek-out\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      cout << endl;
      cout << "\t\t\t\t\tHarga\t: " << (room.total * date.nextDay) << endl;
      cout << "================================================================" << endl;
      break;
    }
    // Melihat data
    cout << "================================================================" << endl;
    cout << "\t\tMenampilkan data pengunjung" << endl;
    cout << "1. Menampilkan" << endl;
    cout << "2. Langsung bayar" << endl;
    cout << endl;
    cout << "Masukkan pilihan\t\t: ";
    cin >> dataPengunjung.pilDat;
    cout << endl;
    cout << "================================================================" << endl;
    cout << "\033[2J\033[H";

    if (dataPengunjung.pilDat == 1)
    {
      string opFile = "dataPengunjung.txt";

      ifstream file(opFile);

      if (!file.is_open())
      {
        cout << "Gagal membuka file: " << opFile << endl;
        return;
      }

      file.seekg(0, ios::end);
      size_t fileSize = file.tellg();
      file.seekg(0, ios::beg);

      string fileContent;
      fileContent.resize(fileSize);
      file.read(&fileContent[0], fileSize);

      cout << "Data pengunjung "
           << "\n"
           << fileContent << endl;

      file.close();
    }
    else if (dataPengunjung.pilDat == 2)
    {
    }

    // reset file pengunjung
    const char *filePengunjung = "dataPengunjung.txt";
    resetKamar(filePengunjung);
    // reset file no kamar
    const char *dataKamar = "kamarData.txt";
    resetKamar(dataKamar);
    // Pembayaran 2
  }
  else if (room.kamar == 4)
  {
    room.total = room.harga = 2100000;
    cout << "================================================================" << endl;
    cout << "\t\t\tSuite Room" << endl;
    cout << "================================================================" << endl;
    cout << "\t1 King bed\t\t\t2 Guets" << endl;
    cout << "\tFree Breakfast\t\tNon-refundable" << endl;
    cout << "\tFree Wifi\t\t\tNon-reschedule" << endl;
    cout << "\tNon-smoking" << endl;
    cout << "================================================================" << endl;
    // No kamar
    ofstream fileKamar("kamarData.txt", ios::app);
    if (!fileKamar.is_open())
    {
      cout << "Tidak dapat membuka file!!" << endl;
    }
    for (int i = 100; i <= 110; ++i)
    {
      char tipeKamar = (i <= 110) ? 'A' : 'B';
      fileKamar << i << " " << tipeKamar << endl;
    }

    fileKamar.close();

    // Membaca no kamar
    ifstream bacaKamar("kamarData.txt");

    if (!bacaKamar.is_open())
    {
      cout << "Tidak dapat membuka file!!" << endl;
    }

    vector<int> nomorKamar;
    int nomor;
    char jenis;
    while (bacaKamar >> nomor >> jenis)
    {
      nomorKamar.push_back(nomor);
    }
    bacaKamar.close();

    // Memilih no kamar
    cout << "================================================================" << endl;
    cout << "Nomor kamar tersedia: " << endl;
    for (int i = 0; i < nomorKamar.size(); ++i)
    {
      cout << i + 1 << ". " << nomorKamar[i] << endl;
    }
    cout << endl;
    cout << "================================================================" << endl;
    cout << "Pilih no kamar (1-" << nomorKamar.size() << "): ";
    cin >> room.noKamar;
    if (room.noKamar >= 1 && room.noKamar <= nomorKamar.size())
    {
      cout << "Nomor kamar anda: " << nomorKamar[room.noKamar - 1] << endl;
    }

    cout << "\033[2J\033[H";

    // Pengunjung
    cout << "================================================================" << endl;
    cout << "\t\t\tJumlah pengunjung" << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan jumlah orang dewasa\t\t: ";
    cin >> pengunjung.dewasa;
    cout << "Masukkan jumlah anak-anak\t\t: ";
    cin >> pengunjung.anak;

    while ((pengunjung.dewasa > 2 && pengunjung.anak > 3) || (pengunjung.dewasa > 2 || pengunjung.anak > 3))
    {
      cout << "Anda harus menambah kamar (y/t) ?\t: ";
      cin >> room.ulang;
      if (room.ulang == 'y' || room.ulang == 'Y')
      {
        room.total = room.harga * 2;
        cout << "Harga total\t\t\t\t: " << room.total << endl;
        break;
      }
      else
      {
        cout << "Silahkan pilih menu lain" << endl;
        break;
      }
      cout << "================================================================" << endl;
    }

    // Fasilitas tambahan
    cout << "Memerlukan fasilitas tambahaan (y/t) ?\t: ";
    cin >> room.fasTam;
    cout << "\033[2J\033[H";

    if (room.fasTam == 'y' || room.fasTam == 'Y')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\t   Fasilitas" << endl;
      cout << "================================================================" << endl;
      cout << "\t\t\tDaftar fasilitas" << endl;
      cout << endl;
      for (int i = 0; i < room.hargaFas; ++i)
      {
        cout << i + 1 << ". "
             << "Fasilitas: " << fasilitas[i] << "\t\t Harga: Rp." << hargaFasilitas[i] << endl;
      }
      cout << "================================================================" << endl;
      cout << "Silakan pilih fasilitas: ";
      cin >> room.fas;
    }

    cout << "\033[2J\033[H";

    // Data kamar

    pengunjung.totalPengunjung = pengunjung.dewasa + pengunjung.anak;
    for (int i = 0; i < pengunjung.totalPengunjung; i++)
    {

      cout << "================================================================" << endl;
      cout << "Silakan lengakapi data dibawah ini" << endl;
      cout << "Pengunjung - " << i + 1 << endl;
      cout << "================================================================" << endl;
      cout << endl;
      cout << "Nama\t\t: ";
      cin.ignore();
      getline(cin, nama);
      cout << "NIK\t\t: ";
      cin >> data.nik;
      cout << "No HP\t\t: ";
      cin >> data.hp;
      cout << endl;
      cout << "================================================================" << endl;
      cout << endl;
      // Menyimpan data pengunjung
      ofstream file("dataPengunjung.txt", ios::app);
      if (!file.is_open())
      {
        cerr << "File tidak dapat terbuka!!" << endl;
      }
      file << "Data - " << i + 1 << endl;
      file << "================================================================" << endl;
      file << "Nama: " << nama << "\n";
      file << "NIK: " << data.nik << "\n";
      file << "No HP: " << data.hp << "\n";
      file << "No kamar: " << nomorKamar[room.noKamar - 1] << "\n";
      file << "Jam: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      file << "Tanggal cek-in: " << date.tanggal << " " << bulan[date.tanggal - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }
      file << "Tanggal cek-out: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      file << "================================================================" << endl;
      file << endl;

      file.close();
    }
    cout << "\033[2J\033[H";

    // Pembayaran 1

    while (room.fasTam == 'y' || room.fasTam == 'Y')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\tInformasi pembayaran" << endl;
      cout << "================================================================" << endl;
      cout << "Nama\t\t\t: " << nama << endl;
      cout << "Tipe kamar\t\t: " << room.kamar[kelas - 1] << endl;
      cout << "Fasilitas\t\t: " << fasilitas[room.hargaFas - 1] << endl;
      cout << "No kamar\t\t: " << nomorKamar[room.noKamar - 1] << endl;
      cout << "Dewasa\t\t\t: " << pengunjung.dewasa << endl;
      cout << "Anak-anak\t\t: " << pengunjung.anak << endl;
      cout << "Jam\t\t\t: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      cout << "Tanggal cek-in\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }

      cout << "Tanggal cek-out\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      cout << endl;
      cout << "\t\t\t\t\tHarga\t: " << (room.total * date.nextDay) + hargaFasilitas[room.fas - 1] << endl;
      cout << "================================================================" << endl;
      break;
    }
    while (room.fasTam == 't' || room.fasTam == 'T')
    {
      cout << "================================================================" << endl;
      cout << "\t\t\tInformasi pembayaran" << endl;
      cout << "================================================================" << endl;
      cout << "Nama\t\t\t: " << nama << endl;
      cout << "Tipe kamar\t\t: " << room.kamar[kelas - 1] << endl;
      cout << "No kamar\t\t: " << nomorKamar[room.noKamar - 1] << endl;
      cout << "Dewasa\t\t\t: " << pengunjung.dewasa << endl;
      cout << "Anak-anak\t\t: " << pengunjung.anak << endl;
      cout << "Jam\t\t\t: " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
      cout << "Tanggal cek-in\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      for (int i = 1; i < date.nextDay; ++i)
      {
        ++date.tanggal;

        if (date.tanggal > 31)
        {
          date.tanggal = 1;
          ++date.month;
        }

        if (date.month > 12)
        {
          date.month = 1;
          ++date.tahun;
        }
      }

      cout << "Tanggal cek-out\t\t: " << date.tanggal << " " << bulan[date.month - 1] << " " << date.tahun << endl;
      cout << endl;
      cout << "\t\t\t\t\tHarga\t: " << (room.total * date.nextDay) << endl;
      cout << "================================================================" << endl;
      break;
    }
    // Melihat data
    cout << "================================================================" << endl;
    cout << "\t\tMenampilkan data pengunjung" << endl;
    cout << "1. Menampilkan" << endl;
    cout << "2. Langsung bayar" << endl;
    cout << endl;
    cout << "Masukkan pilihan\t\t: ";
    cin >> dataPengunjung.pilDat;
    cout << endl;
    cout << "================================================================" << endl;
    cout << "\033[2J\033[H";

    if (dataPengunjung.pilDat == 1)
    {
      string opFile = "dataPengunjung.txt";

      ifstream file(opFile);

      if (!file.is_open())
      {
        cout << "Gagal membuka file: " << opFile << endl;
        return;
      }

      file.seekg(0, ios::end);
      size_t fileSize = file.tellg();
      file.seekg(0, ios::beg);

      string fileContent;
      fileContent.resize(fileSize);
      file.read(&fileContent[0], fileSize);

      cout << "Data pengunjung "
           << "\n"
           << fileContent << endl;

      file.close();
    }
    else if (dataPengunjung.pilDat == 2)
    {
    }

    // reset file pengunjung
    const char *filePengunjung = "dataPengunjung.txt";
    resetKamar(filePengunjung);
    // reset file no kamar
    const char *dataKamar = "kamarData.txt";
    resetKamar(dataKamar);
    // Pembayaran 2
  }
}

#endif // !denpasar_h