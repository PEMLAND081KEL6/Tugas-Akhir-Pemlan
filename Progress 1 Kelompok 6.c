#include<stdio.h>
#include<stdlib.h>

int pilih;

int main(){
    char username[20]= "pemlankel6", pass[20]= "pemlankel6";
   	char usr[10], pas[20];
   	int status = 0, salah = 0;
   	while(status < 3){
      printf("Masukkan Username : ");
      gets(usr);
      printf("Masukkan Password : ");
      gets(pas);

      if(strcmp(username, usr)==0 && strcmp (pass, pas)== 0){
         printf("Akses diterima. Selamat Datang\n");
         break;
      }else{
         printf("Username dan Password tidak match\n");
         salah++;
         if(salah == 3){
            printf("Akses ditolak\n");
         }
      }
      status++;
   	}
	
	menu:
    system("cls");
    printf("==================================\n");
    printf("        PROGRAM KASIR TOKO        \n");
    printf("==================================\n");
    printf("1.Masukkan Barang Baru\n");
    printf("2.Cari Barang\n");
    printf("3.Kalkulasi Barang\n");
    printf("4.Exit Program\n");
    printf("\nMasukkan Pilihan : ");
    scanf("%d", &pilih);
    
    
    
   	system("pause");
   return 0;
}
