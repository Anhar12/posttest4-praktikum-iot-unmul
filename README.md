# POSTTEST 4 - PRAKTIKUM - IoT - UNMUL

Kelompok 6 Kelas B:
- 2109106051 - Reihan Al Sya'ban
- 2109106081 - Anhar Khoirun Najib
- 2109106104 - M. Rangga Yaqub Wijaya

## Rangkaian Kontrol LED Dalam Sebuah Rumah dan Monitoring Suhu dan Kelembapan Rumah Menggunakan 4 LED, dan DHT11 Dengan Bot Telegram
### Deskripsi 
Dalam sebuah rumah memiliki 4 buah LED yang dapat dikontrol melalui grup Telegram oleh masing masing anggota menggunakan Bot Telegram. Setiap anggota memiliki masing-masing 1 LED yang hanya dapat dikontrol oleh anggota tersebut dan 1 LED lagi yang dapat dikontrol oleh semua anggota. Anggota juga dapat melihat informasi dari suhu dan kelembapan rumah, serta informasi dari tiap-tiap LED melalui grup chat Telegram.

### Cara Kerja Alat
Tiap anggota memiliki akses untuk memulai aktivitas rangkaian dengan perintah "/start" yang kemudian akan menampilkan list command yang dapat digunakan, List command :
- /LedGeneralOn : to switch the Led General ON
- /LedAnharOn : to switch the Led Anhar ON
- /LedSabanOn : to switch the Led Saban ON
- /LedRanggaOn : to switch the Led Rangga ON
- /LedGeneralOff : to switch the Led General OFF
- /LedAnharOff : to switch the Led Anhar OFF
- /LedSabanOff : to switch the Led Saban OFF
- /LedRanggaOff : to switch the Led Rangga OFF
- /InfoLED : Returns current status of LED
- /InfoDHT : Returns temperature and humidity status of DHT1
Tiap anggota dapat mengontrol LED mereka masing-masing, contoh: Anhar hanya dapat mengontrol LED miliknya sendiri yaitu LED Anhar, jika Anhar mencoba menggunakan command "/LedSabanOn" maka Bot akan mengirimkan pesan peringatan dan Node MCU akan menolak permintaan tersebut. Kemudian terdapat command yang dapat digunakan oleh semua anggota, yaitu kontrol LED general "/LedGeneralOn" dan "/LedGeneralOff", Info LED "/InfoLED" yang akan menampilkan informasi LED dalam rumah, dan Info DHT "/InfoDHT" yang akan menampilkan informasi suhu dan kelembapan rumah.

### Pembagian Tugas 
- Sya'ban = Pembuatan rangkaian LED dan DHT11
- Anhar = Konfigurasi program perangkat IoT dan koneksi perangkat dengan Bot Telegram
- Rangga = Konfigurasi Bot Telegram dan grup chat Telegram

### Komponen Yang Digunakan 
1. 1 buah ESP8266(NodeMCU) => perangkat utama yang mengontrol rangkaian
2. 1 buah Bread Board => sebagai dasar sirkuit elektronik sementara
3. 1 buah Kabel Jumper male to male => penghubung listrik aliran ground
4. 3 buah Kabel Jumper male to female => penghubung listrik pin DHT11
5. 4 buah Resistor => penghambat tegangan listrik ke arah LED
6. 4 buah LED => 3 LED milik masing-masing anggota dan 1 LED general yang bisa digunakan oleh semuanya
7. 1 buah DHT11 => sensor untuk membaca suhu dan kelembapan ruangan

### Board Schematic
1. Design Schematic
![Design Schematic](https://github.com/Anhar12/posttest4-praktikum-iot-unmul/assets/92861249/e032dd26-185f-4918-9bfb-47a6366a9e5c)

2. Our Schematic

### Link Video
[Link Video Posttest 4 Kelompok 6](https://youtu.be/4M6Bm-o0Ql8)
