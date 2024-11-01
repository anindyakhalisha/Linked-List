#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void tranverse(node *pList);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void jumlahData(node *head);
void hasilPenjumlahan(node *head);
void insertNode(node **head, node *pPre, node *pNew, node *pcur);

//========================================================

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do{
     system("cls");
     printf("Masukkan Pilihan\n");
     printf("1. Tambah data di awal list\n");
     printf("2. Tambah data di tengah list\n");
     printf("3. Tambah data di akhir list\n");
	 printf("4. Cetak isi list\n");
	 printf("5. Hapus data di awal list\n");
     printf("6. Hapus data di tengah list\n");
	 printf("7. Hapus data di akhir list\n");
	 printf("8. Pencarian data dalam list\n");
	 printf("9. Tampilkan informasi jumlah data di list\n");
	 printf("0. Tampilkan hasil penjumlahan dari semua data di list\n");
     printf("MASUKKAN PILIHAN (Tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
	 if (pilih == '1'){
     		tambahAwal(&head);
     }else if (pilih == '2'){
			tambahData(&head);
	 }else if (pilih == '3'){
     		tambahAkhir(&head);
     }else if (pilih == '4'){
     		tranverse(head);
     }else if (pilih == '5'){
     		hapusAwal(&head);
	 }else if (pilih == '6'){
     		hapusData(&head);
     }else if (pilih == '7'){
     		hapusAkhir(&head);
     }else if (pilih == '8'){
     		cariData(head);
	 }else if (pilih == '9'){
     		jumlahData(head);
     }else if (pilih == '0'){
     		hasilPenjumlahan(head);
     }
      getch();
      
  } while (pilih != 'q');
  
  return 0;
}

//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================

void tambahAwal(node **head){
  int bil;
  node *pNew, *pList;

  system("cls");
  fflush(stdin);
  printf("Masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      if (*head == NULL) {
          pNew->next = pNew; // create a circular reference
      } else {
          node *pWalker = *head;
          while (pWalker->next != *head) {
              pWalker = pWalker->next;
          }
          pWalker->next = pNew;
          pNew->next = *head;
      }
      *head = pNew;
  }
  else{
      printf("Alokasi memori gagal");
        getch();
    }
}
 
//========================================================

void tambahData(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nPosisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nBilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nNode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nAlokasi memori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
}

//========================================================

void tambahAkhir(node **head) {
  int bil;
  node *pNew, *pPre;

  system("cls");
  fflush(stdin);
  printf("Masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL) {
     pNew->data = bil;
     if (*head == NULL) {
         pNew->next = pNew;
         *head = pNew;
     	} else {
         	 pPre = *head;
         	 while (pPre -> next != *head) {
             pPre = pPre -> next;
         	}
         pPre -> next = pNew;
          pNew->next = *head;
		}
	} else {
	 	 printf("Alokasi memori gagal");
     	 getch();
    }
}

//========================================================

void tranverse(node *pList){
   //traverse a linked list
  system("cls");
    if (pList == NULL) {
        printf("List kosong\n");
        getch();
    }
    node *pWalker;
    pWalker = pList;
    printf("List contains:\n");
    while (pWalker->next != pList){
        printf("%d ", pWalker->data);
        pWalker = pWalker->next;  
    }
    printf("%d ", pWalker->data);
    printf("\n");
}

//========================================================

void hapusAwal(node **head) {
  node *pPre, *pCur, *pList;

  if (*head != NULL) {
     if ((*head)->next == *head) {
         free(*head);
         *head = NULL;
     } else {
         pCur = *head;
         pPre = *head;
         while (pPre->next != *head) {
             pPre = pPre->next;
         }
         pPre->next = (*head)->next;
         *head = (*head)->next;
         free(pCur);
     }
     system("cls");
     printf("\nData berhasil dihapus");
     getch();
  } else {
     printf("List kosong\n");
     getch();
  }
}

//========================================================

void hapusData(node **head) {
  int pos;
  node *pCur = *head, *pPre = *head;

  system("cls");
  tranverse(*head);
  printf("\nMasukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &pos);

  while (pCur->next != *head && pCur->data != pos) {
    pPre = pCur;
    pCur = pCur->next;
  }

  if (pCur->data != pos){
     printf("\nData tidak ditemukan");
     getch();
  }
  else{
     if (pCur == *head) {
       // Node to be deleted is the head node
       node *pNext = pCur->next;
       while (pNext->next != *head) {
         pNext = pNext->next;
       }
       *head = pCur->next;
       pNext->next = *head;
     } else {
       pPre->next = pCur->next;
     }
     free(pCur);
  }
}
//========================================================

void hapusAkhir(node **head) {
  node *pCur = *head, *pPre = *head;

  if (*head == NULL) {
     printf("List kosong\n");
     getch();
    }
	else if (pCur->next == *head) {
     	 free(pCur);
    	 *head = NULL;
    	}
    	else {
    		while (pCur->next != *head) {
         	 pPre = pCur;
         	 pCur = pCur->next;
    		}
    	 free(pCur);
    	 pPre->next = *head; 
    	 system("cls");
  	 	printf("\nData berhasil dihapus");
  	 	getch();
    	}
}

//========================================================

void cariData(node *head) {
  int target, found;
  node *pPre = head, *pCur = head;
  
  system("cls");
  printf("\Masukkan nilai yang dicari : ");
  fflush(stdin);
  scanf("%d", &target); 
  
  found = 0;
  if (pCur->data == target) {
    found = 1;
    printf("Nilai ditemukan");
    getch();
    return;
  }
  while (pCur->next != head) {
     pPre = pCur;
     pCur = pCur -> next;
     if (pCur->data == target) {
       found = 1;
       printf("Nilai ditemukan");
       getch();
       return;
     }
  }
  
  printf("Nilai tidak ditemukan");
  getch();
}

//========================================================

void jumlahData(node *head) {
  int count = 0;
  node *pCur = head; 
 
  while (pCur != head || count == 0) {
     count++;
     pCur = pCur->next;
    } 
    
  system("cls");
  printf("Jumlah data sebanyak: %d\n", count);
  getch();
}
    
//========================================================

void hasilPenjumlahan(node *head) {
  int sum = 0;
  node *pCur = head; 
 
  while (pCur != head || sum == 0) {
     sum += pCur -> data;
     pCur = pCur->next;
    } 
    
  system("cls");
  printf("Hasil penjumlahan seluruh data adalah: %d\n", sum);
  getch();
}
    
//========================================================

void insertNode(node **head, node *pPre, node *pNew, node *pList){
    if (pPre == NULL){
       //add before first logical node or to an empty list
	    pNew -> next = pNew;
       pList = pNew;
    }
    else {
       //add in the middle or at the end
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}

//========================================================
