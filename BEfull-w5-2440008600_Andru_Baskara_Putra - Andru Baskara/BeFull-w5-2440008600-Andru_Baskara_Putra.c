#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>



struct queue{
    char customer[200];
    struct queue *portal;
}*front,*rear,*scan,*fronted;

struct data{
    char nama[200];
    int no;
}datas[200];

int i,dpn=0, bkg=0, a=0, queue=0;




void baru(){
    front=rear=NULL;
}

void tambah(char nama[]){
    if (rear==NULL)
    {
        rear=(struct queue *)malloc(1*sizeof(struct queue));
        rear->portal=NULL;
        strcpy(rear->customer,nama);
        front=rear;
    }else{
        scan=(struct queue *)malloc(1*sizeof(struct queue));
        rear->portal=scan;
        strcpy(scan->customer,nama);
        scan->portal=NULL;
        rear=scan;
        
    }
    
    
    
    

}

void hapus(){
    fronted=front;

    if (fronted==NULL)
    {
        printf("\n-------------------tidak ada !!!--------------------------\n");
        return;
    }else{
        if (fronted->portal != NULL)
        {
            fronted=fronted->portal;
            printf("\n%s telah dilayani\n", front->customer);
            free(front);
            front=fronted;
        }else{
            printf("\n%s telah dilayani\n",front->customer);
            free(front);
            front=NULL;
            rear=NULL;
        }
       
        
    }
    
}

void tunjukdata(){
    if ((front != NULL) && (rear != NULL))
    {
        printf("----------------------depan : %s---------------------------\n",front->customer);
        printf("----------------------belakang : %s------------------------\n",rear->customer);
    }else
    {
        printf("\n--------------tidak ada !!------------------- \n");
    }
    
    
}

void showlist(){
    int a=1;
    fronted=front;

    if ((fronted == NULL) && (rear == NULL))
    {
        printf("\nMasih Kosong \n");
        printf("+-----+------------------+\n");
        printf("| No. |  Customer Name   |\n");
        printf("+-----+------------------+\n" );
        printf("|                        |\n");
        printf("|                        |\n");
        printf("|                        |\n");

        return;
    }
    printf("+-----+------------------+\n" );
    printf("| No. |  Customer Name   |\n");
    printf("+-----+------------------+\n");
    while (fronted != rear)
    {
        if (fronted==front && fronted!=rear)
        {
            //printf("%d. %s\n",i++,fronted->customer);
            printf("| %d   |   %-12s   |<---depan\n",a++,fronted->customer);
        }else{
            printf("| %d   |   %-12s   |\n",a++,fronted->customer);
        }
        
        fronted=fronted->portal;
    }

    if (fronted == rear && fronted!=front)
    {
    
        //printf("%d. %s\n",i++,fronted->customer);
        printf("| %d   |   %-12s   |<---blkg\n",a++,fronted->customer);
    }

    if (fronted==rear && fronted==front)
    {
        printf("| %d   |   %-12s   |<---sama\n",a++,fronted->customer);
    }
    
    
    
    
}

void tambahArray(int opsi){
    queue++;
    printf("\n---%d---\n",queue);
    datas[bkg].no=queue;
    printf("Masukan nama pelanggan : ");
    scanf("%s",datas[bkg].nama);
    bkg++;

}

void tunjukDataArray(int opsi){
    printf("\nfront : %s\n",datas[dpn].nama);
    printf("rear : %s",datas[bkg-1].nama);
}

void hapusArray(){
    printf("\n%s telah dilayani\n",datas[dpn].nama);
    dpn++;
}

void displayArray(){
    if (dpn==bkg)
    {
        printf("\nMasih Kosong \n");
        printf("+-----+------------------+\n");
        printf("| No. |  Customer Name   |\n");
        printf("+-----+------------------+\n" );
        printf("|                        |\n");
        printf("|                        |\n");
        printf("|                        |\n");
        return;
    }else{
        printf("+-----+------------------+\n" );
        printf("| No. |  Customer Name   |\n");
        printf("+-----+------------------+\n");
        for (i=dpn; i<bkg; i++)
        {
            if (i==dpn&&i==bkg-1)
            {
                //printf("%d. %s <--front & rear\n",datas[i].no,datas[i].nama);
                printf("| %d   |   %-12s   |<--front & rear\n",datas[i].no,datas[i].nama);
                
              
            }else if(i==dpn){
                printf("| %d   |   %-12s   |<--front\n",datas[i].no,datas[i].nama);
                
            }else if (i==bkg-1){
                printf("| %d   |   %-12s   |<--rear\n",datas[i].no, datas[i].nama);
               
            }else{
                printf("| %d   |   %-12s   |\n",datas[i].no,datas[i].nama);
                
            }
            
            
        }
        
    }
    

}


void linkedlistIm(){
    int opsi;
    char name[200];
    
    baru();

    while (1)
    {
        showlist();
        printf("\n1. tambah antrian");
        printf("\n2. tunjukan antrian terdepan/belakang");
        printf("\n3. layani");
        printf("\n4. kill program");
        printf("\nEnter your choice ");
        printf("\n>>>");
        scanf("%d",&opsi);
        switch (opsi)
        {
        case 1:
            printf("Masukan nama pelanggan : ");
            scanf("%s",name);
            tambah(name);
            break;
        
        case 2:
            tunjukdata();
            break;
        
        case 3:
            hapus();
            break;

        case 4:
            exit(0);
        default:
            printf("\nopsi tidak valid !!!!!\n");
            break;
        }
    }
}


void arrayimp(){
    int opsi,max;
    a:
    printf("\nKapasitas maksimal [max=100]: ");
    scanf("%d",&max);
    if (max>100||max<1)
    {
        printf("\n Njir jgn besar2 atau kekecilan juga \n");
        goto a;

    }else{
        b:
        displayArray();
        printf("\n1. tambah antrian");
        printf("\n2. tunjukan antrian terdepan/belakang");
        printf("\n3. layani");
        printf("\n4. kill program");
        printf("\nEnter your choice ");
        printf("\n>>>");
        scanf("%d",&opsi);

        if (opsi<1||opsi>4)
        {
            printf("\n\n opsi tidak valid!!!\n");
            goto b;
        }else if (opsi==4)
        {
            exit(0);
        }else if (opsi==1&& a!=max)
        {
            tambahArray(opsi);
            a++;
            goto b;

        }else if (opsi==1 && a==max)
        {
            printf("\nMELEBIHI KAPASITAS MAKSIMAL!!!\n");
            goto b;
        }else if (opsi==2 && a!=0)
        {
            tunjukDataArray(opsi);
            goto b;
        }else if (opsi==2 && a==0)
        {
            printf("\nTIDAK ADA YANG BISA DITAMPILKAN\n");
            goto b;
        }else if (opsi==3 && a!=0)
        {
            hapusArray(opsi);
            a--;
            goto b;
        }else if (opsi==3 && a==0)
        {
            printf("\nTIDAK ADA YANG BISA DIHAPUS\n");
            goto b;
        }
        
        
        
        
        
        
        
        
        
    }
}

void installcustom(){
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");
    printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");printf("downloading package...........\n");
    printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");printf("installing package............\n");
    printf("package installed!\n");



}

int main(){
    int cho;
    printf("--Pilih aplikasi untuk diinstall--\n");
    printf("1. DevilQueue lister (berbasis linkedlist)\n");
    printf("2. Queue Master (berbasis array)\n");
    printf("install >> "); scanf("%d",&cho);
    if (cho==1)
    {
        installcustom();
        linkedlistIm();
    }else if (cho==2)
    {
        installcustom();
        arrayimp();
    }
    
    

    
}