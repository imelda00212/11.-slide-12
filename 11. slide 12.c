#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    int pilihan;
    char nama[50];
    char nim[20];
    float ipk;
    char baris[100];
    int jumlah;

    do {
        printf("\n===== PROGRAM DATA MAHASISWA =====\n");
        printf("1. Membuat dan menulis file awal\n");
        printf("2. Menampilkan data mahasiswa\n");
        printf("3. Menambah data mahasiswa\n");
        printf("4. Menghitung jumlah mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        // MENU 1: Membuat dan menulis file awal
        if (pilihan == 1) {
            fp = fopen("mahasiswa.txt", "w");

            if (fp == NULL) {
                printf("File gagal dibuat!\n");
            } else {
                printf("\nMasukkan nama mahasiswa: ");
                scanf(" %49[^\n]", nama);

                printf("Masukkan NIM: ");
                scanf("%19s", nim);

                printf("Masukkan IPK: ");
                scanf("%f", &ipk);

                fprintf(fp, "Nama: %s\n", nama);
                fprintf(fp, "NIM : %s\n", nim);
                fprintf(fp, "IPK : %.2f\n", ipk);
                fprintf(fp, "---------------\n");

                fclose(fp);

                printf("Data awal berhasil disimpan!\n");
            }
        }

        // MENU 2: Menampilkan isi file
        else if (pilihan == 2) {
            fp = fopen("mahasiswa.txt", "r");

            if (fp == NULL) {
                printf("File belum tersedia!\n");
            } else {
                printf("\n===== DATA MAHASISWA =====\n");

                while (fgets(baris, sizeof(baris), fp) != NULL) {
                    printf("%s", baris);
                }

                fclose(fp);
            }
        }

        // MENU 3: Menambah data baru
        else if (pilihan == 3) {
            fp = fopen("mahasiswa.txt", "a");

            if (fp == NULL) {
                printf("File gagal dibuka!\n");
            } else {
                printf("\nMasukkan nama mahasiswa: ");
                scanf(" %49[^\n]", nama);

                printf("Masukkan NIM: ");
                scanf("%19s", nim);

                printf("Masukkan IPK: ");
                scanf("%f", &ipk);

                fprintf(fp, "Nama: %s\n", nama);
                fprintf(fp, "NIM : %s\n", nim);
                fprintf(fp, "IPK : %.2f\n", ipk);
                fprintf(fp, "---------------\n");

                fclose(fp);

                printf("Data mahasiswa berhasil ditambahkan!\n");
            }
        }

        // MENU 4: Menghitung jumlah mahasiswa
        else if (pilihan == 4) {
            fp = fopen("mahasiswa.txt", "r");

            if (fp == NULL) {
                printf("File belum tersedia!\n");
            } else {
                jumlah = 0;

                while (fgets(baris, sizeof(baris), fp) != NULL) {
                    if (strncmp(baris, "Nama:", 5) == 0) {
                        jumlah++;
                    }
                }

                fclose(fp);

                printf("\nJumlah mahasiswa: %d\n", jumlah);
            }
        }

        else if (pilihan == 5) {
            printf("Program selesai. Terima kasih!\n");
        }

        else {
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 5);

    return 0;
}