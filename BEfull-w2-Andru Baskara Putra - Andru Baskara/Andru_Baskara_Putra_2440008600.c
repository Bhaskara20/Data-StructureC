#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


//program masih kurang lengkap dan belum rapih dan ada sedikit bug sederhana, tp setidaknya sudah bisa berjalan dan meghasilkan output dengan baik..
//nanti saya perbarui di full submission karena jam 3 saya ada acara keluarga

char cuisine[200];
char origin[200];

struct food{
    int no;
    char makanan[200];
    char asal[200];
    struct food *portal;
};


struct food *start=NULL;

void line(){
    printf("_______________________________________________\n");

}

void showlist(){
	int i = 1;
    struct food* scan;

    line();
    printf("Tabel wishlist, jangan wishlist doang, beli juga yaa hehe :v \n");
	line();
    printf ("| No.    | Makanan     | Asal Makanan |\n");
    if (scan==NULL)
    {
        printf("\nMaaf, anda mau menampilkan apa? diisi aja belum\n");

    }else{
        scan=start;
        while (scan!=NULL)
        {
            
            printf("| %0.2d.    | %-6s      | %-12s |  \n", i++, scan->makanan, scan->asal);
            scan=scan->portal;
            
        }
        
    }
    
}

void tambahDepan(){
   
    struct food* scan;

    scan=malloc(sizeof(struct food));

    printf("Nama Makanan : ");
    scanf("%s",cuisine); 
    strcpy(scan->makanan,cuisine);
    printf("Asal Makanan : ");
    scanf("%s",origin);
    strcpy(scan->asal,origin);

    scan->portal=start;
    start=scan;

   

}

void tambahBelakang(){
    struct food *scan, *head;
    scan=malloc(sizeof(struct food));

    printf("Nama Makanan : ");
    scanf("%s",cuisine);
    printf("Asal Makanan :");
    scanf("%s",origin);

    scan->portal=0;
    strcpy(scan->makanan,cuisine);
    strcpy(scan->asal,origin);
    head=start;

    while (head->portal != NULL)
    {
        head=head->portal;
    }
    head->portal=scan;
    

    
}

void hapusDepan(){
    struct food *scan;
    if(start==NULL){
        printf("\nMau hapus apa coba? kosongan\n");
    }else{
        scan=start;
        start=start->portal;
        free(scan);
    }
}

void hapusBelakang(){
    struct food *scan, *prev;

    if(start==NULL){
        printf("\nJujur saya bingung, apa yang harus saya hapus?\n");

    }else{
        scan=start;
        while(scan->portal!=0){
            prev=scan;
            scan=scan->portal;
        }
        free(scan);
        prev->portal=0;
    }
}



int main(){
    
    char repeat,sure;
	int opsi;
	do{
	
    re:
    line();
    printf("SELAMAT DATANG DI FORUM KULINER ANAK EPEP\n");
	line();
    printf("\n[1] Tambah wishlist makanan \n");
    printf("[2] Hapus wishlist kuliner \n");
    printf("[3] Kill Program\n");
    printf("Input Your Choice >> "); 
    scanf("%d", &opsi);
	
    if(opsi<1 || opsi>3){
        printf("\nOpsi tak dikenal, mohon input ulang\n");
        goto re;

    }

    while(opsi!=3){

       
        if (opsi==1)
        {
            
            int subopsi;
            ga:
            printf("\n1.Ditambah di awal\n");
            printf("2.Ditambah di akhir\n");
            printf("Input Your Choice >> ");
            scanf("%d",&subopsi); 
            if (subopsi<1 || subopsi >2)
            {
                printf("\nOpsi tak dikenal, mohon input ulang\n");
                goto ga;
            }
            

            if (subopsi==1)
            {
                tambahDepan();
                showlist();
                goto re;
            }else
            {
                tambahBelakang();
                showlist();
                goto re;
            }
            
            
        }
        else if(opsi==2)
        {
            int subopsi2;
            ge:
            printf("\n1.Dihapus di awal\n");
            printf("2.Dihapus di akhir\n");
            printf("Input Your Choice >> ");
            scanf("%d",&subopsi2);
            if(subopsi2<1 || subopsi2 >2)
            {
                printf("\nOpsi tak dikenal, mohon input ulang\n");
                goto ge;
            }

            if(subopsi2==1){
                hapusDepan();
                showlist();
                goto re;
               
            }else{
                hapusBelakang();
                showlist();
                goto re;
                
            }

        }
    }
    exit(0);
    
    printf("Yakin sudah cukup? atau mau lagi? (n=cukup, y=mau lagi )");
    scanf("%s", &repeat);
} while (repeat == 'y' || repeat == "Y" || sure=='y' || sure=='Y');

}


