---

# Robot Cartesian 3 DOF - Inverse Kinematics

## Deskripsi Proyek

Program ini mengimplementasikan algoritma **inverse kinematics** untuk robot **Cartesian 3 Degree of Freedom (DOF)** menggunakan bahasa pemrograman C++. Kode ini menggunakan konsep **Object-Oriented Programming (OOP)** dengan fitur seperti **Inheritance**, **Polymorphism**, **Encapsulation**, dan **Abstraction** untuk mengontrol posisi robot dan menghitung sudut yang dibutuhkan untuk mencapai posisi akhir yang diinginkan.

Robot dapat bergerak dalam sumbu **X**, **Y**, dan **Z**, dan posisi akhir ditentukan oleh pengguna. Program ini juga memungkinkan hasil perhitungan disimpan dalam file teks dan dapat dibaca kembali untuk dianalisis.

## Fitur Utama

- **Inverse Kinematics**: Hitung sudut untuk mencapai posisi yang ditentukan.
- **File Handling**: Simpan hasil perhitungan ke dalam file teks, tambahkan data ke file yang sudah ada, dan baca data dari file.
- **OOP Principles**: Penggunaan inheritance, polymorphism, encapsulation, dan abstraction untuk struktur kode yang modular dan mudah dipelihara.

## Struktur Kode

1. **Kelas `Robot`**: Kelas abstrak yang mendefinisikan kerangka dasar untuk berbagai jenis robot.
2. **Kelas `RobotCartesian3DOF`**: Kelas turunan dari `Robot` yang mengimplementasikan metode inverse kinematics untuk robot Cartesian dengan 3 DOF.
3. **Metode Utama**:
    - `inverseKinematics`: Menghitung sudut berdasarkan posisi akhir yang dimasukkan.
    - `saveToFile`: Menyimpan hasil perhitungan ke file.
    - `logSpeedsToFile`: Menyimpan data ke file untuk test case baru.
    - `appendSpeedsToFile`: Menambahkan hasil ke file yang sudah ada.
    - `readSpeedsFromFile`: Membaca data dari file.

## Cara Menjalankan Proyek

### Persyaratan

- Compiler C++ yang mendukung C++11 atau versi lebih baru.

### Langkah-langkah

1. Clone repositori ini ke direktori lokal Anda:

   ```bash
   git clone https://github.com/username/repo-name.git
   cd repo-name
   ```

2. Kompilasi kode menggunakan compiler C++:

   ```bash
   g++ -o robot_kinematics robot_kinematics.cpp
   ```

3. Jalankan program:

   ```bash
   ./robot_kinematics
   ```

4. Masukkan nilai untuk posisi X, Y, dan Z yang ingin Anda capai. Program akan menghitung sudut yang diperlukan dan memberikan opsi untuk menyimpan atau menambahkan hasil ke file teks.

### Contoh Penggunaan

Saat program dijalankan, Anda akan diminta untuk memasukkan posisi target untuk robot. Misalnya:

```plaintext
Masukkan posisi X: 30
Masukkan posisi Y: 40
Masukkan posisi Z: 50
```

Program akan menghitung sudut joint berdasarkan posisi ini dan menampilkan hasilnya. Anda juga bisa menyimpan hasil ke file atau menambahkannya ke data sebelumnya:

```plaintext
Solusi: X: 30, Y: 40, Z: 50
Sudut: X: 38.66°, Y: 30.96°, Z: 53.13°

Apakah Print Hasil Sebelumnya (iya = 1): 1
Data ditambahkan ke inverse_kinematic_result.txt
```

## Struktur File

- **robot_kinematics.cpp**: Kode sumber utama untuk proyek.
- **inverse_kinematic_result.txt**: File yang menyimpan hasil perhitungan inverse kinematics. File ini akan dibuat secara otomatis oleh program.

## Konsep OOP yang Digunakan

1. **Inheritance**: Kelas `RobotCartesian3DOF` mewarisi dari kelas `Robot`.
2. **Polymorphism**: Metode virtual `inverseKinematics` dan `saveToFile` memungkinkan perilaku yang berbeda tergantung pada kelas yang memanggilnya.
3. **Encapsulation**: Atribut posisi dan sudut di kelas `RobotCartesian3DOF` dibuat private dan hanya diakses melalui metode publik.
4. **Abstraction**: Kelas `Robot` mendefinisikan metode abstrak tanpa detail implementasi, sementara kelas turunan mengimplementasikan detailnya.


---
