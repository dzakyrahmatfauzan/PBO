# PBO
Nama Kelompok : 
1. Dzaky Rahmat Fauzan (5223600082)
2. Ilham Fameidana (5223600063)
   
Deskripsi class
**1. Class Cucipiring**
   - digunakan untuk mewakili konsep permainan atau sistem di mana pemain dapat mencuci piring dan mendapatkan skor sebagai hasilnya
**2. Class Customer**
   - digunakan untuk mewakili customer dalam sistem order. Fungsi dari class ini adalah untuk menyimpan informasi tentang pelanggan, meja tempat mereka duduk, dan pemesanan mereka.
**3. Class GameManager**
   - berfungsi sebagai pengendali utama dalam mengelola interaksi antara berbagai komponen dalam sistem restoran, seperti customer, table, kitchen, dan cuci piring. Dengan ini, sistem restoran dapat berjalan             terorganisir, mulai dari antrean customer, penempatan di table, pembuatan dan pengiriman pesanan, hingga pencucian piring setelah pelanggan selesai.
**4. Class Kitchen**
   - digunakan untuk menangani sistem antrian dan pemrosesan pesanan di kitchen, seperti menambahkan pesanan, memasak, dan menandai pesanan sebagai selesai. Fungsi-fungsi yang terdapat dalam class ini memfasilitasi      interaksi antara kitchen dengan sistem permainan lainnya, seperti pesanan dari pelanggan yang ditempatkan oleh GameManager
**5. Class Order**
   - digunakan untuk merepresentasikan pesanan dalam sistem. Pesanan ini melibatkan informasi mengenai ID pesanan, ID table tempat pesanan dibuat, item yang dipesan, serta status apakah pesanan telah selesai atau        belum
**6. Class Table**
   - digunakan untuk melacak status table, baik itu ditempati pelanggan atau kosong. Ini memungkinkan sistem untuk memutuskan apakah meja tersedia untuk pelanggan baru atau tidak
**7. Fungsi Main**
     Secara keseluruhan, kegunaan utama dari fungsi main() adalah:
        - Menyediakan menu pilihan input bagi pengguna
        - Mengelola objek-objek yang terlibat dalam permainan (customer, table, kitchen, cucipiring).
        - Memproses pesanan dan menjaga alur permainan berjalan dengan lancar berdasarkan input pengguna.
