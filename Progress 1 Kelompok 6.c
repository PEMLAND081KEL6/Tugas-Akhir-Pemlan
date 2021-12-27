#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int main(){
	int pilih;
	int i;
	int num = 0;
	int total = 0;
	char read[100];
	FILE *pfile;
	char input[100];
    char string[50];
    char barang[100] = {0};
    char harga[1000];

   	char username[20]= "pemlankel6", password[20]= "pemlankel6";
   	char user[10], pass[10];
   	int status = 0, salah = 0;
   	while(status < 3){
   		system("color f8");
   		printf("[MENU LOGIN KASIR TOKO JAYA ABADI]\n\n");
   		printf("NOTE : HINDARI SALAH MELEBIHI 3x\n\n");
      	printf("USERNAME : ");
      	gets(user);
      	printf("PASSWORD : ");
      	gets(pass);
      	if(strcmp(username, user) == 0 && strcmp(password, pass) == 0){
      		system("cls");
		  	printf("AKSES LOGIN DITERIMA, SELAMAT DATANG!!!\n");
		  	printf("(TEKAN ENTER UNTUK MELANJUTKAN PROGRAM)");
		  	getch();
		  	break;
		  	}
		else{
			system("cls");
         	printf("USERNAME DAN PASSWORD SALAH!!!\n");
         	printf("(TEKAN ENTER UNTUK MENGULANGI LOGIN)");
         	getch();
         	system("cls");
         	salah++;
         	if(salah == 3){
         		system("cls");
            	printf("AKSES LOGIN DI TOLAK KARENA MELEBIHI DARI 3x SALAH, SILAHKAN ULANGI PROGRAM!!!\n");
				exit(0);
         		}
      		}
      			status++;
   		}
   		
		menu:
		system("color c0");
    		system("cls");
    		printf("[PROGRAM KASIR TOKO JAYA ABADI]\n\n");
    		printf("1.LIST BARANG\n");
    		printf("2.CARI BARANG\n");
   		printf("3.KALKULASI BARANG\n");
    		printf("4.EXIT PROGRAM\n");
    		printf("\nPILIH PROGRAM YANG AKAN DIJALANKAN : ");
    		scanf("%d", &pilih); fflush(stdin);
    		system("cls");
   			
   			if(pilih==1){
   				system("color e8");
   				printf("[LIST BARANG]\n\n");
   				pfile = fopen("ListBarang.txt", "r");

    			if(pfile){
        			while(fgets(read, sizeof(read), pfile)){
            			printf("%s", read);
        				}
        				fclose(pfile);
        				printf("\nTEKAN ENTER UNTUK KEMBALI KE MENU PROGRAM");
        				getch();
    					goto menu;
    				}
    			else{
        			printf("ERROR!");
    				}
			   	}
			if(pilih==2){
				system("color a0");
   				printf("[CARI BARANG]\n\n");
   				while(barang[0] != '0'){
            		FILE *in_file = fopen("ListBarang.txt", "r");
            		if(in_file == NULL){
                		printf("FILE HILANG DAN ERROR\n");
                		exit(-1);
            		}
            		printf("INPUT BARANG YANG DICARI (TULISKAN NAMA BARANG SESUAI DENGAN PENULISAN PADA LIST BARANG)\n\n");
        			scanf("%s", barang);
            		while(fscanf(in_file,"%s", string) == 1){ 
                		if(strstr(string, barang)!=0){
		                    fscanf(in_file, "%[^\n]", harga);
        		            printf("\nBARANG DITEMUKAN!!!\n");
        		            printf("\nDATA BERISI :\n");
    						printf("BARANG\t\t\tHARGA");
    						printf("\n-------------------------------");
    						printf("\n%s\t%s\n",barang, harga);
    						printf("\nTEKAN ENTER UNTUK KEMBALI KE MENU PROGRAM");
        					getch();
    						goto menu;
                	    }
                	}
                	i = strtol(harga, NULL, 10);
                	fclose(in_file);
           			printf("\n DATA TIDAK DITEMUKAN!!!\n");
           			printf("\nTEKAN ENTER UNTUK KEMBALI KE MENU PROGRAM");
        			getch();
    				goto menu;
        		}	
			}
			if(pilih==3){
				system("color b8");
   				printf("[KALKULASI BARANG]\n\n");
   				char add;
				printf("INPUT BARANG PELANGGAN (TEKAN y UNTUK TAMBAH BARANG, n UNTUK MENYELESAIKAN KALKULASI)\n");
				scanf("%s", &add);
				while (add == 'y'){
            		FILE *in_file = fopen("ListBarang.txt", "r");
            		if(in_file == NULL){
                		printf("FILE HILANG DAN ERROR\n");
                		exit(-1);
            		}
            		printf("\nMASUKKAN NAMA BARANG\n");
        			scanf("%s", barang);
            		while(fscanf(in_file,"%s", string) == 1){ 
                		if(strstr(string, barang)!=0){
		                    num++;
        		            fscanf(in_file, "%[^\n]", harga);
                	    }
                	}
    				printf("\nDATA BERISI :\n\nNama Barang\t\tHarga\n%s\t%s\n", barang, harga);
                	num = 0;
                	i = strtol(harga, NULL, 10);
                	total = total + i;
                	i = 0;
				printf("\nINPUT BARANG LAGI? (TEKAN y UNTUK TAMBAH BARANG, n UNTUK MENYELESAIKAN KALKULASI)\n");
				scanf("%s", &add);
				}
			   	printf("TOTAL HARGA ADALAH : RP%d", total);
			   	printf("\nTEKAN ENTER UNTUK KEMBALI KE MENU PROGRAM");
        		getch();
    			goto menu;
			}
			if(pilih==4){
				system("color d0");
   				printf("TERIMA KASIH TELAH MENJALANKAN PROGRAM");
			   }
	return 0;
}
