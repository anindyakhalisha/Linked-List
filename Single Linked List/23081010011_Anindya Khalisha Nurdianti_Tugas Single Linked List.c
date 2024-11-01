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
void tranverse(node *head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void jumlahData(node *head);
void hasilPenjumlahan(node *head);
void insertNode(node **head, node *pPre, node *pNew);

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
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("Masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = NULL;
      //add before first logical node or to an empty list
	  pNew -> next = *head;
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
     pNew->next = NULL;
     if (*head == NULL) {
         *head = pNew;
     	} else {
         	 pPre = *head;
         	 while (pPre -> next != NULL) {
             pPre = pPre -> next;
         	}
         pPre -> next = pNew;
		}
	} else {
	 	 printf("Alokasi memori gagal");
     	 getch();
    }
}

//========================================================

void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d\t", pWalker -> data);
   	pWalker = pWalker -> next;
      printf(" -> ");
	}
   printf("NULL");
}

//========================================================

void hapusAwal(node **head) {
  node *pCur;

  if (*head != NULL) {
     pCur = *head;
	 *head = (*head)->next;
	 free(pCur);
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
  int pos, count = 0;
  node *pPre = NULL, *pCur = *head;

  system("cls");
  tranverse(*head);
  printf("\nMasukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &pos);

  while (pCur != NULL && pCur -> data != pos) {
    pPre = pCur;
    pCur = pCur -> next;
  }

  if (pCur == NULL){
     printf("\nData tidak ditemukan");
     getch();
  }
  else{
     if (pPre == NULL) {
       // Node to be deleted is the head node
       *head = pCur -> next;
     } else {
	 pPre -> next = pCur -> next;
     }
     free(pCur);
  }
}

//========================================================

void hapusAkhir(node **head) {
  node *pCurrent = *head, *pPre = NULL;
	
  if (*head == NULL) {
     printf("List kosong\n");
     getch();
    }
	else if (pCurrent->next == NULL) {
     	 free(pCurrent);
    	 *head = NULL;
    	}
    	while (pCurrent->next != NULL) {
         	 pPre = pCurrent;
         	 pCurrent = pCurrent->next;
    	}
    	 free(pCurrent);
    	 pPre->next = NULL; 
    	 system("cls");
  	 	printf("\nData berhasil dihapus");
  	 	getch();
}

//========================================================

void cariData(node *head) {
  int target, found;
  node *pPre = NULL, *pCur = head;
  
  system("cls");
  printf("\Masukkan nilai yang dicari : ");
  fflush(stdin);
  scanf("%d", &target); 
  
  while (pCur != NULL && pCur -> data != target) {
     pPre = pCur;
     pCur = pCur -> next;
	} 
	
  if (pCur != NULL){
   	 found = 1;
   	 printf("Nilai ditemukan");
   	 getch();
  	}else{
   	 	 found = 0; 
   	 	 printf("Nilai tidak ditemukan");
   	 	 getch();
   	 	}
}

//========================================================

void jumlahData(node *head) {
  int count = 0;
  node *pCur = head; 
 
  while (pCur != NULL) {
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
 
  while (pCur != NULL) {
     sum += pCur -> data;
     pCur = pCur->next;
    } 
    
  system("cls");
  printf("Hasil penjumlahan seluruh data adalah: %d\n", sum);
  getch();
}
    
//========================================================

void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){
       //add before first logical node or to an empty list
	    pNew -> next = *head;
       *head = pNew;
    }
    else {
       //add in the middle or at the end
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}

//========================================================
