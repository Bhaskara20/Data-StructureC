#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct data{
	struct data *prev;
	char name[200];
	char gender[200];
	char choose[200];
	int age;
	struct data *portal;
};

struct data *first,*nodebaru,*scan,*last;

void buat(){
	int plh;
	char plhan[200];
	struct data *nodebaru; int gen;
	nodebaru=(struct data *)malloc(sizeof(struct data));
	
	printf("Selamat datang di aplikasi voting kami!!!\n");
	printf("Silahkan masukan data untuk pertama kali\n");
	printf("Masukan nama : "); scanf("%s",nodebaru->name);
	printf("\nJenis Kelamin Anda Adalah <1=cowok , 2=cewek: "); scanf("%d",&gen);
    if (gen==1)
    {
        strcpy(nodebaru->gender,"Laki");
    }else if (gen==2)
    {
        strcpy(nodebaru->gender,"Perempuan");
    }else{
        printf("\nGender tidak tersedia\n");
    }
    
    
	printf("\nUmur anda adalah : "); scanf("%d",&nodebaru->age);
	
	do{
		printf("Silahkan Pilih Calon Pilihan anda : ");
		printf("\n1.Andru");
		printf("\n2.Baskara");
		printf("\n3.Putra");
		printf("[1/2/3] >> "); scanf("%d",&plh);
		if(plh==1){
			strcpy(plhan, "Andru");
		}else if(plh==2){
			strcpy(plhan, "Baskara");
		}else if(plh==3){
			strcpy(plhan ,"Putra");
		}else if(plh<1 || plh>3){
			printf("\n---Pilihan salah bang---\n");
		}
	}while(plh<1 || plh>3);
	strcpy(nodebaru->choose, plhan);
	
	nodebaru->prev=0;
	nodebaru->portal=0;
	
	if(first==0){
		first=last=nodebaru;
	}else{
		last->portal=nodebaru;
		nodebaru->prev=last;
		last=nodebaru;
	}
}

void tambahDepan(){
	int plh;
	char plhan[200];
	struct data *nodebaru; int gen;
	nodebaru=(struct data *)malloc(sizeof(struct data));
	
	printf("\nMasukan nama : "); scanf("%s",nodebaru->name);
	printf("\nJenis Kelamin Anda Adalah <1=cowok , 2=cewek: "); scanf("%d",&gen);
    if (gen==1)
    {
        strcpy(nodebaru->gender,"Laki");
    }else if (gen==2)
    {
        strcpy(nodebaru->gender,"Perempuan");
    }else{
        printf("\nGender tidak tersedia\n");
    }
	printf("\nUmur anda adalah : "); scanf("%d",&nodebaru->age);
	
	do{
		printf("Silahkan Pilih Calon Pilihan anda : ");
		printf("\n1.Andru");
		printf("\n2.Baskara");
		printf("\n3.Putra");
		printf("[1/2/3] >> "); scanf("%d",&plh);
		if(plh==1){
			strcpy(plhan, "Andru");
		}else if(plh==2){
			strcpy(plhan, "Baskara");
		}else if(plh==3){
			strcpy(plhan ,"Putra");
		}else if(plh<1 || plh>3){
			printf("\n---Pilihan salah bang---\n");
		}
	}while(plh<1 || plh>3);
	strcpy(nodebaru->choose, plhan);
	
	nodebaru->prev=0;
	nodebaru->portal=0;
	
	if(!first){
		first=last=nodebaru;
	}else{
		first->prev=nodebaru;
		nodebaru->portal=first;
		first=nodebaru;
	}
	
	
}

void tambahAkhir(){
	int plh; char plhan[200];
	struct data *nodebaru; int gen;
	nodebaru=(struct data *)malloc(sizeof(struct data));
	printf("\nMasukan nama : "); scanf("%s",nodebaru->name);
	printf("\nJenis Kelamin Anda Adalah <1=cowok , 2=cewek: "); scanf("%d",&gen);
    if (gen==1)
    {
        strcpy(nodebaru->gender,"Laki");
    }else if (gen==2)
    {
        strcpy(nodebaru->gender,"Perempuan");
    }else{
        printf("\nGender tidak tersedia\n");
    }
	printf("\nUmur anda adalah : "); scanf("%d",&nodebaru->age);
	
	do{
		printf("Silahkan Pilih Calon Pilihan anda : ");
		printf("\n1.Andru");
		printf("\n2.Baskara");
		printf("\n3.Putra");
		printf("[1/2/3] >> "); scanf("%d",&plh);
		if(plh==1){
			strcpy(plhan, "Andru");
		}else if(plh==2){
			strcpy(plhan, "Baskara");
		}else if(plh==3){
			strcpy(plhan ,"Putra");
		}else if(plh<1 || plh>3){
			printf("\n---Pilihan salah bang---\n");
		}
	}while(plh<1 || plh>3);
	strcpy(nodebaru->choose, plhan);
	
	nodebaru->portal=0;
	
	if(!first){
		first=last=nodebaru;
	}else{
		last->portal=nodebaru;
		nodebaru->prev=last;
		last=nodebaru;
	}
	
	
	
}

int ukuran(){
	int count=0;
	
	scan=first;
	while(scan!=NULL){
		count++;
		scan=scan->portal;
	}
	return count;
}

void tambahKeinginan(){
	int plh; char plhan[200];
	int pos, i=1; int gen;
	printf("Mau tambah dimana? ");
	scanf("%d",&pos);
	
	int size=ukuran();
	
	if(pos<1 || (pos>(size+1))){
		printf("\nPosisi paan dah\n");
	}else if(pos==1){
		tambahDepan();
	}else if(pos==(size+1)){
		tambahAkhir();
	}else{
		struct data *nodebaru;
		
		nodebaru=(struct data *)malloc(sizeof(struct data));
		printf("\nMasukan nama : "); scanf("%s",nodebaru->name);
		printf("\nJenis Kelamin Anda Adalah <1=cowok , 2=cewek: "); scanf("%d",&gen);
    if (gen==1)
    {
        strcpy(nodebaru->gender,"Laki");
    }else if (gen==2)
    {
        strcpy(nodebaru->gender,"Perempuan");
    }else{
        printf("\nGender tidak tersedia\n");
    }
		printf("\nUmur anda adalah : "); scanf("%d",&nodebaru->age);
	
		do{
			printf("Silahkan Pilih Calon Pilihan anda : ");
			printf("\n1.Andru");
			printf("\n2.Baskara");
			printf("\n3.Putra");
			printf("[1/2/3] >> "); scanf("%d",&plh);
			if(plh==1){
				strcpy(plhan, "Andru");
			}else if(plh==2){
				strcpy(plhan, "Baskara");
			}else if(plh==3){
				strcpy(plhan ,"Putra");
			}else if(plh<1 || plh>3){
				printf("\n---Pilihan salah bang---\n");
			}
		}while(plh<1 || plh>3);
		strcpy(nodebaru->choose, plhan);
		
		scan=first;
		while(i<pos-1){
			scan=scan->portal;
			i++;
		}
		nodebaru->prev=scan;
		nodebaru->portal=scan->portal;
		scan->portal=nodebaru;
		nodebaru->portal->prev=nodebaru;
		
	}
}

void hapusDepan(){
	if(first==0){
		printf("\nKosong gan,mau hapus apa\n");
		return;
	}else if(first==last){
		free(first);
		first=last=NULL;
	}else{
		scan=first;
		first=first->portal;
		first->prev=0;
		free(scan);
	}
}

void hapusAkhir(){
	if(!first){
		printf("\nGaada data\n");
		return;
	}else if(first==last){
		free(first);
		first=last=NULL;
	}else{
		scan=last;
		last=scan->prev;
		last->portal=0;
		free(scan);
	}
}

void hapusKeinginan(){
	int pos, i=1;
	printf("\nMau hapus yg mana?\n");
	scanf("%d",&pos);
	
	if(pos>ukuran()){
		printf("\nGaada bang\n");
	}else if(pos==1){
		hapusDepan();
	}else if(pos==ukuran()){
		hapusAkhir();
	}else{
		scan=first;
		while(i<pos){
			scan=scan->portal;
			i++;
		}
		scan->prev->portal=scan->portal;
		scan->portal->prev=scan->prev;
		
		free(scan);
	}
}



void showlist(){
	struct data *scan;
	scan=first;
	int b=1;

	if(!scan){

    printf("====================================================================================\n" );
    printf("| No. |        name      |          Choose      | Age |          Gender            |\n");
    printf("====================================================================================\n" );
    printf("|                                                                                  |\n");
    printf("|                  --- No data here ---                                            |\n");
    printf("|                                                                                  |\n");
    printf("====================================================================================\n" );
	}
	printf("====================================================================================\n" );
    printf("| No. |        name      |          Choose      | Age |          Gender            |\n");
    printf("====================================================================================\n" );
	while(scan!=0){
		/*printf("Nama : %s\n",scan->name);
		printf("Umur : %d\n",scan->age);
		printf("Gender : %s\n",scan->gender);
		printf("Pilihan : %s\n",scan->choose);*/
		if (scan==first && scan==last)
		{
			printf("| %d.  |   %-13s   |   %-16s   | %d   |   %-18s   |<--head & tail\n",b++,scan->name,scan->choose,scan->age,scan->gender);
		}else if (scan==first)
		{
			printf("| %d.  |   %-13s   |   %-16s   | %d   |   %-18s   |<--head\n",b++,scan->name,scan->choose,scan->age,scan->gender);
		}else if (scan==last)
		{
			printf("| %d.  |   %-13s   |   %-16s   | %d   |   %-18s   |<--tail\n",b++,scan->name,scan->choose,scan->age,scan->gender);
		}else{
			printf("| %d.  |   %-13s   |   %-16s   | %d   |   %-18s   |\n",b++,scan->name,scan->choose,scan->age,scan->gender);
		}
		
		
		
		scan=scan->portal;
	}
	printf("\n");
}

void urutData(){
	struct data *var =first, *in=NULL;
	char scan1[200],scan2[200],scan3[200];
	int scan4;

	if (first==NULL)
	{
		printf("\nTidak ada data yang bisa diurut\n");
		return;
	}else{
		do
		{
			in=var->portal;
			while (in != NULL)
			{
				if (strcmp(var->name, in->name)>0)
				{
					strcpy(scan1,var->name);
					strcpy(var->name,in->name);
					strcpy(in->name,scan1);
                    strcpy(scan2,var->gender);
                    strcpy(var->gender,in->gender);
                    strcpy(in->gender,scan2);
                    strcpy(scan3,var->choose);
                    strcpy(var->choose,in->choose);
                    strcpy(in->choose,scan3);
					scan4=var->age;
					var->age=in->age;
					in->age=scan4;
				}
				in=in->portal;
				
			}
			var=var->portal;
			
		} while (var->portal != NULL);
		
	}
	
	
	
	
}

void votingres(){
	char winner[200];
	int l = 0;
	int a1=0, a2=0,a3=0;
	scan=first;
	if (!first)
	{
		printf("\nGaada yang menang\n");
	}else{
		while (scan)
		{
			l++;
			if (strcmp(scan->choose,"Andru")==0)
			{
				a1+=1;
			}else if (strcmp(scan->choose,"Baskara")==0)
			{
				a2+=1;
			}else{
				a3+=1;
			}
			scan=scan->portal;
			
			
		}
		printf("Hasil rekapitulasi suara\n");
		printf("Andru = %d orang\n",a1);
		printf("Baskara = %d orang\n",a2);
		printf("Putra = %d orang\n",a3);

		if (a1>a2 && a1>a3)
		{
			strcpy(winner,"Andru");
            printf("Berdasarkan perhitungan\n");
            printf("Pemenangnya adalah %s \n",winner);
		}else if (a2>a1 && a2>a3)
		{
			strcpy(winner,"Baskara");
            printf("Berdasarkan perhitungan\n");
            printf("Pemenangnya adalah %s \n",winner);
		}else if (a3>a1 && a3>a2)
		{
			strcpy(winner,"Putra");
            printf("Berdasarkan perhitungan\n");
            printf("Pemenangnya adalah %s \n",winner);
		}else{
			printf("Masih kosong\n");
		}
		
		
		
	}
	
}


void main(){
	int opsi;
	buat();
	do{
		showlist();
		printf("\n1.Tambah Depan\n2.Tambah Belakang\n3.Tambah Tengah\n4.Hapus Depan\n5.Hapus Akhir\n6.Hapus Tengah\n7.Hasil Voting\n8,Sorting Nama\n9.Kill Program\n");
		printf("Pilih >> ");
		scanf("%d",&opsi);
		
		switch(opsi)
		{
			case 1: tambahDepan();
					break;
			case 2: tambahAkhir();
					break;
			case 3: tambahKeinginan();
					break;
			case 4: hapusDepan();
					break;
			case 5: hapusAkhir();
					break;
			case 6: hapusKeinginan();
					break;
			case 7: votingres();
					break;
			case 8: urutData();
					break;
			case 9: exit(0);
					break;
			default: printf("\nSalah\n");
					break;
		}
	}while(opsi!=0);
}
