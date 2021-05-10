#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>

struct tree{
    char name[200];
    int num;
    struct tree *kanan, *kiri;
};
typedef struct tree node;

node*buat(char nama[],int nomor){
    node*nodebaru = (node *)malloc(sizeof(node));
    strcpy(nodebaru->name,nama);
    nodebaru->num = nomor;
    nodebaru->kiri = NULL;
    nodebaru->kanan = NULL;
    return nodebaru;
}

void tambah(node **temp, char nama[], int nomor,int height){
    if (height<4)
    {
        if (*temp==NULL)
        {
            *temp = buat(nama,nomor);
            (*temp)->kiri=NULL;
            (*temp)->kanan=NULL;
            printf("\n Berhasil! \n");

        }else
        {
            char pos[200];
            do
            {
                printf("\nMau tambah di kiri atau kanan nya si %s?",(*temp)->name);
                scanf("%s",pos);
            } while (strcmp(pos,"kiri")!=0 && strcmp(pos,"kanan")!=0);

            if (strcmp(pos,"kiri")==0)
            {
                tambah(&(*temp)->kiri,nama,nomor,height+1);
            }else
            {
                tambah(&(*temp)->kanan,nama,nomor,height+1);
            }
            
            
            
        }


        
        
    }else
    {
        printf("\nGabisa dong bund, melebihi maksimal\n");
    }
    
    
}


node *cari(node *root, int nomor){
    if(root!=NULL){
        if(root->num==nomor) {
            return root;
        }
        else{
            node *temp;
            temp=cari(root->kiri,nomor);
            if(temp==NULL){
                temp=cari(root->kanan,nomor);
            }
            return temp;
        }
    }
    else{
        return 0;
    }
    
    

}

void showlist(node*root){
    if (root==NULL)
    {
        return;
    }else
    {
        printf("%-20s (%d)\n", root->name, root->num);
	    showlist(root->kiri);
	    showlist(root->kanan);
    }
    
    
}

void preorder(node *pohon){
    if (pohon==NULL)
    {
        return;
    }else
    {
        printf(" %d\n",pohon->num);
        preorder(pohon->kiri);
        preorder(pohon->kanan);
    }
    
    
}

void inorder(node *pohon){
    if (pohon==NULL)
    {
        return;
    }else
    {
        inorder(pohon->kiri);
        printf(" %d\n",pohon->num);
        inorder(pohon->kanan);
    }
    
    
}

void postorder(node *pohon){
    if (pohon==NULL)
    {
        return;
    }else
    {
        postorder(pohon->kiri);
        postorder(pohon->kanan);
        printf(" %d\n",pohon->num);
    }
    
    
}

node *hapusSemua(node *pohon){
    if (pohon!=NULL)
    {
        hapusSemua(pohon->kiri);
        hapusSemua(pohon->kanan);
        free(pohon);
    }
    return 0;
}

void hapus(node **temp, int nomor){
    if ((*temp)!=NULL && nomor==(*temp)->num)
    {
        hapusSemua(*temp);
        (*temp)=NULL;
    }else if ((*temp)!=NULL)
    {
        hapus(&(*temp)->kiri,nomor);
        hapus(&(*temp)->kanan,nomor);
    }
    
    
}


int main(){
    int opsi=0;
    char nama[200];
    int nomor;

    node *root=NULL; node *res;

    while (opsi < 5 ) {
        printf("======================================\n\n");
        printf("             DAFTAR PEMAIN            \n\n");
        printf("======================================\n");
        printf("1. Tampilkan Pemain\n");
        printf("2. Tambah Pemain\n");
        printf("3. Hapus Pemain\n");
        printf("4. Inorder, Preorder, Postorder\n");
        printf("5. Kill Program\n");
        scanf("%d", &opsi);
        if(opsi==1){
            if(!root){
                printf("\nGaada siapa2 bund\n");
            }else{
                showlist(root);
            }
        }else if(opsi==2){
            do{
		      printf("Tulis Nama Pemain: "); 
                scanf("%s",nama);
            }while(strlen(nama)<3 || strlen(nama)>20);
            while(1){
                printf("Tulis Nomor: "); 
                scanf("%d", &nomor);
                if(nomor>0 && nomor<100){
                    res = cari(root,nomor);
			        if(res){
                        printf("\nUdah ada bund :( cari nomor lain\n\n");
                    }else{
    			        break;
                    }
                }else{
				    printf("Nomor nya jangan di bawah 0 bund, juga jangan lebih dari 100\n");
                }	
            }
            tambah(&root,nama,nomor,0);
        }else if(opsi==3){
    
            if(!root){
                printf("\nGaada nama kayak gitu bund\n");
            }else{
             while(1){    
                showlist(root);
                printf("\nInput Nilai: ");
                scanf("%d",&nomor);
                if(nomor>0 && nomor<100){
                    node *temp;
                    res = cari(root,nomor);
                    if(!res){
                        printf("\n\nGaada nama kayak gitu bund\n");
                    }else{
                      hapus(&root,nomor);
                      printf("\n\nBerhasil dihapus\n");
                      break;
                    }
                }else{
                    printf("Nomor nya jangan di bawah 0 bund, juga jangan lebih dari 100\n");
                }
             }
           }
        
    }else if(opsi==4){
        if(!root){
            printf("\nMasih kosongan \n");
        }else{
            printf("\n Inorder :\n");
            inorder(root);
            printf("\n Preorder :\n");
            preorder(root);
            printf("\n Postorder :\n");
            postorder(root);
        }   
    }
  }
  exit(0);
    
}