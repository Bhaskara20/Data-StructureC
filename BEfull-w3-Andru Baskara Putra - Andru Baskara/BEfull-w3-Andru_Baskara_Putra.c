#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct experimental
{
    int age;
    int rating;
    char customer[200]; 
	struct experimental* portal; 
};

typedef struct experimental node;

node *first = NULL;
node *last =NULL;

void line(){
    printf("_______________________________________________\n");
}

void tambahDepan(char nama[], int umur, int nilai){
    node *scan = (node *)malloc(sizeof(node));

    strcpy(scan->customer, nama);
    scan->age=umur;
    scan->rating=nilai;
    scan->portal=scan;

    if (first==NULL)
    {
        first=scan;
        last=scan;
    }else{
        scan->portal=first;
        last->portal=scan;
        first=scan;
    }
    



}

void tambahBelakang(char nama[], int umur, int nilai){

    node *scan=(node *) malloc(sizeof(node));
    
    strcpy(scan->customer, nama);
    scan->age=umur;
    scan->rating=nilai;
    scan->portal=scan;

    if (first==NULL)
    {
        first=scan;
        last=scan;
    }else{
        last->portal = scan;
        scan->portal= first;
        last=scan;
    }
    

}

void tambahSesuaiKeinginan(char nama[], int umur, int nilai, int pos){

    if (pos==1)
    {
        tambahDepan(nama,umur,nilai);
        return;
    }else if (pos>1 && first!=NULL)
    {
        node *curr=first;
        node *temp = (node *)malloc(sizeof(node));
        int thing = 0;

        do
        {
            thing++;
            temp = curr;
            curr=curr->portal;
        } while (curr->portal != first && thing<pos-1);

        if (thing==pos-1)
        {
            if (temp==last)
            {
                tambahBelakang(nama,umur,nilai);
            }else{
                node *scan = (node *)malloc(sizeof(node));
                strcpy(scan->customer, nama);
                scan->age=umur;
                scan->rating=nilai;

                temp->portal=scan;
                scan->portal=curr;
            }
            return;
            
            
        }
        
        
    }

    printf("Lokasi yang tidak valid!\n");
    
    

}

void hapusDepan(){

    if (first==NULL)
    {
        printf("\nHanya anak indigo yang bisa melihat dan menghapus data ini\n");
        return;
    }

    node *temp = first;
    if(first->portal==first){
    	first=NULL;
    	last=NULL;
	}
	else{
		first=first->portal;
		last->portal=first;
	}
    free(temp);
    
}

void hapusBelakang(){
   
    if (first==NULL)
    {
        printf("\nHanya anak indigo yang bisa melihat dan menghapus data ini\n");
        return;
    }

    node *temp = first;
    node *curr = first;

    while (curr->portal != first)
    {
        temp=curr;
        curr=curr->portal;
    }
    if(temp==first&&temp->portal==first){
    	first=NULL;
    	temp= NULL;
	}
	else{
	
    temp->portal= curr->portal;
    last = temp; //disambungin ke first
    last=last->portal;
    first->portal=last;
	}
    free(curr);
    
}

void hapusSesuaiKeinginan(int pos){

    if (first==NULL)
    {
        printf("\nHanya anak indigo yang bisa melihat dan menghapus data ini\n");
        return;
    }

    if (pos==1)
    {
        hapusDepan();
        return;
    }

    node *curr = first;
    node *temp;
    int thing= 0;

    do
    {
        thing++;
        temp=curr;
        curr=curr->portal;
    } while (curr->portal != first && thing<pos-1);

    if (thing==pos-1)
    {
        if (curr==last)
        {
            hapusBelakang();
            return;
        }

        temp->portal=curr->portal;
        free(curr);
        return;
        
    }

    printf("Lokasi tidak valid!\n");
    
    
    
    

}
//ascending
void urutUmur(){
    node *curr=first , *in=NULL;
    int scan;

    char scan1[1000];
    if (first==NULL)
    {
        printf("\nHanya anak indigo yang bisa melihat dan mengurut data ini\n");
    }else{
        do
        {
            in=curr->portal;
            while (in != first)
            {
                if (curr->age > in->age)
                {
                    scan=curr->age;
                    curr->age=in->age;
                    in->age=scan;
                    
                    strcpy(scan1,curr->customer);
                    strcpy(curr->customer,in->customer);
                    strcpy(in->customer,scan1);

                    scan=curr->rating;
                    curr->rating=in->rating;
                    in->rating=scan;
                }
                in=in->portal;
                
            }
            curr=curr->portal;
            
        } while (curr->portal != first);
        
    }
    
    
}

void urutUmurDescending(){
    node *curr=first , *in=NULL;
    int scan;

    char scan1[1000];
    if (first==NULL)
    {
        printf("\nHanya anak indigo yang bisa melihat dan mengurut data ini\n");
    }else{
        do
        {
            in=curr->portal;
            while (in != first)
            {
                if (curr->age < in->age)
                {
                    scan=curr->age;
                    curr->age=in->age;
                    in->age=scan;
                    
                    strcpy(scan1,curr->customer);
                    strcpy(curr->customer,in->customer);
                    strcpy(in->customer,scan1);

                    scan=curr->rating;
                    curr->rating=in->rating;
                    in->rating=scan;
                }
                in=in->portal;
                
            }
            curr=curr->portal;
            
        } while (curr->portal != first);
        
    }
}

void urutRating(){
    node *curr=first , *in=NULL;
    int scan;

    char scan1[1000];
    if (first==NULL)
    {
        printf("\nHanya anak indigo yang bisa melihat dan mengurut data ini\n");
    }else{
        do
        {
            in=curr->portal;
            while (in != first)
            {
                if (curr->rating > in->rating)
                {
                    scan=curr->age;
                    curr->age=in->age;
                    in->age=scan;
                    
                    strcpy(scan1,curr->customer);
                    strcpy(curr->customer,in->customer);
                    strcpy(in->customer,scan1);

                    scan=curr->rating;
                    curr->rating=in->rating;
                    in->rating=scan;
                }
                in=in->portal;
                
            }
            curr=curr->portal;
            
        } while (curr->portal != first);
        
    }
}

void urutRatingDescending(){
    node *curr=first , *in=NULL;
    int scan;

    char scan1[1000];
    if (first==NULL)
    {
        printf("\nHanya anak indigo yang bisa melihat dan mengurut data ini\n");
    }else{
        do
        {
            in=curr->portal;
            while (in != first)
            {
                if (curr->rating < in->rating)
                {
                    scan=curr->age;
                    curr->age=in->age;
                    in->age=scan;
                    
                    strcpy(scan1,curr->customer);
                    strcpy(curr->customer,in->customer);
                    strcpy(in->customer,scan1);

                    scan=curr->rating;
                    curr->rating=in->rating;
                    in->rating=scan;
                }
                in=in->portal;
                
            }
            curr=curr->portal;
            
        } while (curr->portal != first);
        
    }
}

void showlist(){//di cek

    if (first==NULL)
    {
        printf("Kode gaib\n");
        return;
    }

    node *curr = first;
    int i=0;
    printf ("| No.    | Nama      | Usia    | Rating   |\n");
    do
    {
        /*printf("\nNama : %s\n",curr->customer);
        printf("umur = %d\n",curr->age);
        printf("Rating = %d\n",curr->rating);*/
        i+=1;
        if (curr==first && curr->portal==first)
        {
            printf("| %0.2d.    | %-6s    |  %2d     |  %2d      |<-- Head <-- Tail \n",i, curr->customer, curr->age,curr->rating);
        }else if (curr==first)
        {
            printf("| %0.2d.    | %-6s    |  %2d     |  %2d      |<-- Head\n",i, curr->customer, curr->age,curr->rating);
        }else if (curr!=first && curr==last)
        {
            printf("| %0.2d.    | %-6s    |  %2d     |  %2d      |<-- Tail\n",i, curr->customer, curr->age,curr->rating);
        }else{
            printf("| %0.2d.    | %-6s    |  %2d     |  %2d      |\n",i, curr->customer, curr->age,curr->rating);
        }
        
        
        
        curr=curr->portal;

    } while (curr != first);// hrs di cek lg
    
    
}


int main(){

    int opsi;
    int usia; 
    char name[200]; 
    int rate;
    int position;
    int repeat;
    node *var;

    
    

   do
   {
        line();
        printf("KUMPULAN DATA PENILAIAN CUSTOMER\n");
	    line();
        printf("\n[1] Tambah data penilaian\n");
        printf("[2] Hapus data penilaian \n");
        printf("[3] Urut data\n");
        printf("[4] Kill Program\n");
        printf("Input Your Choice >> "); scanf("%d",&opsi);

        if (opsi<1 || opsi>4)
        {
            printf("\nOPSI TIDAK VALID!!\n");
        }   
       if (opsi==1)
        {
            
            int subopsi;
            ga:
            printf("\n1.tambah depan");
            printf("\n2.tambah belakang");
            printf("\n3.tambah sesuai keinginan\n");
            printf("Input Your Choice >> "); scanf("%d",&subopsi);

            if (subopsi<1 || subopsi>3)
            {
                printf("\nOPSI TIDAK VALID!!\n");
                goto ga;
            }
            

            if (subopsi==1)
            {
                ro:
                printf("\nSilahkan isi nama customer : "); scanf("%s",name);
                printf("\nSilahkan isi usia customer : "); scanf("%d",&usia);
                printf("\nSilahkan isi penilaian dari customer : "); scanf("%d",&rate);
                if (usia <1 || usia >100)
                {
                    printf("\nKisaran umur harus 1-100");
                    goto ro;
                }

                if (rate <1 || rate >5)
                {
                    printf("\nKisaran Rating hanya 1-5");
                    goto ro;
                }
                

                tambahDepan(name,usia,rate);
                showlist();
                
            }else if(subopsi==2){
                ra:
                printf("\nSilahkan isi nama customer : "); scanf("%s",name);
                printf("\nSilahkan isi usia customer : "); scanf("%d",&usia);
                printf("\nSilahkan isi penilaian dari customer : "); scanf("%d",&rate);

                if (usia <1 || usia >100)
                {
                    printf("\nKisaran umur harus 1-100");
                    goto ra;
                }

                if (rate <1 || rate >5)
                {
                    printf("\nKisaran Rating hanya 1-5");
                    goto ra;
                }
                

                tambahBelakang(name,usia,rate);
                showlist();
                
            }else if (subopsi==3)
            {
                ru:
                printf("\nSilahkan isi nama customer : "); scanf("%s",name);
                printf("\nSilahkan isi usia customer : "); scanf("%d",&usia);
                printf("\nSilahkan isi penilaian dari customer : "); scanf("%d",&rate);
                printf("\nDiposisi mana? : "); scanf("%d",&position);

                if (usia <1 || usia >100)
                {
                    printf("\nKisaran umur harus 1-100");
                    goto ru;
                }

                if (rate <1 || rate >5)
                {
                    printf("\nKisaran Rating hanya 1-5");
                    goto ru;
                }

                tambahSesuaiKeinginan(name,usia,rate,position);
                showlist();
                
            }
            
            
        }else if(opsi==2){
            
            int subopsi2;
            guk:
            printf("\n1.Hapus depan");
            printf("\n2.Hapus belakang");
            printf("\n3.Hapus sesuai keinginan\n");
            printf("Input Your Choice >> "); scanf("%d",&subopsi2);
            if (subopsi2<1 || subopsi2>3)
            {
                printf("\nOPSI TIDAK VALID!!\n");
                goto guk;
            }
            

            if (subopsi2==1)
            {
                hapusDepan();
                showlist();
               
            }else if (subopsi2==2){
                hapusBelakang();
                showlist();
             
            }else if (subopsi2==3){
                printf("\nHapus posisi mana : "); scanf("%d",&position);
                hapusSesuaiKeinginan(position);
                showlist();
                

            }
            
            

        
        }else if(opsi==4){
            exit(0);
        }else if(opsi==3)
        {
            
            int subopsi3;
            gag:
            printf("\n1.Urut berdasarkan usia");
            printf("\n2.Urut berdasarkan rating penilaian");
            printf("Input Your Choice >> "); scanf("%d",&subopsi3);

            if (subopsi3 <1 || subopsi3>2)
            {
                printf("\nOPSI TIDAK VALID!!\n");
                goto gag;
            }
            

            if (subopsi3==1)
            {
                
                int endopsi;
                grr:
                printf("\n1.Urut secara Ascending");
                printf("\n2.Urut secara Descending");
                printf("Input Your Choice >> "); scanf("%d",&endopsi);

                if (endopsi<1 || endopsi>2)
                {
                    printf("\nOPSI TIDAK VALID!!\n");
                    goto grr;
                }
                

                if (endopsi==1)
                {
                    urutUmur();
                    showlist();
                }else if(endopsi==2){
                    urutUmurDescending();
                    showlist();
                }

            }else if(subopsi3==2){

                
                int endopsi2;
                kill:
                printf("\n1.Urut secara Ascending");
                printf("\n2.Urut secara Descending");
                printf("Input Your Choice >> "); scanf("%d",&endopsi2);

                if (endopsi2<1 || endopsi2>2)
                {
                    printf("\nOPSI TIDAK VALID!!\n");
                    goto kill;
                }

                if (endopsi2==1)
                {
                    urutRating();
                    showlist();
                }else if(endopsi2==2){
                    urutRatingDescending();
                    showlist();
                }
                
            }
            
        }
        

        printf("\nmau lanjutkan program? [1=iya, 0=tidak]  1/0\n");
        scanf("%d",&repeat);
   } while (repeat ==1);
   exit(0);
   
     
}
