#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *left;
    struct node *right;
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
      pNew->left = NULL;
      pNew->right = *head;
      if (*head != NULL) {
          (*head)->left = pNew;
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
    pCur = pCur -> right;
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
     pNew->left = pCur;
     pNew->right = pCur->right;
     if (pCur->right != NULL) {
       pCur->right->left = pNew;
     }
     pCur->right = pNew;
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
     pNew->left = NULL;
     pNew->right = NULL;
     if (*head == NULL) {
         *head = pNew;
     	} else {
         	 pPre = *head;
         	 while (pPre -> right != NULL) {
             pPre = pPre -> right;
         	}
         pPre -> right = pNew;
         pNew -> left = pPre;
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
	printf("List Contains: \n");
	while (pWalker != NULL){
   	printf("%d ", pWalker -> data);
   	pWalker = pWalker -> right;
	}
	printf("\n");
}

//========================================================

void hapusAwal(node **head) {
  node *pCur = *head;

  if (*head == NULL) {
	system("cls");
    printf("List kosong\n");
	getch();
    }

  *head = pCur->right;
  if (*head != NULL) {
    (*head)->left = NULL;
    }
    free(pCur);
    system("cls");
	printf("\nData berhasil dihapus");
	getch();
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
  
    // Check if the list is empty
    if (*head == NULL) {
    printf("List kosong\n");
	getch();
    }

    // Find the node to be deleted
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->right;
    }

    // If the node is not found, return
    if (pCur == NULL) {
	printf("\nData tidak ditemukan");
    getch();
    }

    // Update the left and right pointers of the adjacent nodes
    if (pCur->left != NULL) {
        pCur->left->right = pCur->right;
    }
    if (pCur->right != NULL) {
        pCur->right->left = pCur->left;
    }

    // Update the head node if the node to be deleted is the head node
    if (pCur == *head) {
        *head = pCur->right;
    }

    // Free the memory of the node to be deleted
    free(pCur);
    system("cls");
	printf("Data berhasil dihapus\n");
}

//========================================================

void hapusAkhir(node** head) {
    node* pCur, *pPre;

    // Check if the list is empty
    if (*head == NULL) {
        system("cls");
        printf("List kosong\n");
        getch();
        return;
    }

    // Check if the list only has one node
    if ((*head)->right == NULL) {
        free(*head);
        *head = NULL;
        system("cls");
        printf("Data berhasil dihapus\n");
        getch();
        return;
    }

    // Find the last node
    pCur = *head;
    while (pCur->right != NULL) {
        pCur = pCur->right;
    }

    // Find the second last node
    pPre = *head;
    while (pPre->right != pCur) {
        pPre = pPre->right;
    }

    // Update the right pointer of the second last node
    pPre->right = NULL;

    // Free the memory of the last node
    free(pCur);
    system("cls");
    printf("Data berhasil dihapus\n");
    getch();
}
	
//========================================================

void cariData(node* head) {
    int target, found;
    node *pPre = NULL, *pCur = head;

    system("cls");
    printf("Masukkan nilai yang dicari : ");
    fflush(stdin);
    scanf("%d", &target);

    while (pCur != NULL && pCur->data != target) {
        pPre = pCur;
        pCur = pCur->right;
    }

    if (pCur != NULL) {
        found = 1;
        printf("Nilai ditemukan");
        getch();
    } else {
        found = 0;
        printf("Nilai tidak ditemukan");
        getch();
    }
}

//========================================================

void jumlahData(node* head) {
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->right;
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
     pCur = pCur->right;
    } 
    
  system("cls");
  printf("Hasil penjumlahan seluruh data adalah: %d\n", sum);
  getch();
}
    
//========================================================

void insertNode(node **head, node *pPre, node *pNew) {
    if (pPre == NULL) {
        // add before first logical node or to an empty list
        pNew->right = *head;
        pNew->left = NULL;
        if (*head != NULL) {
            (*head)->left = pNew;
        }
        *head = pNew;
    } else {
        // add in the middle or at the end
        pNew->right = pPre->right;
        pNew->left = pPre;
        if (pPre->right != NULL) {
            pPre->right->left = pNew;
        }
        pPre->right = pNew;
    }
}

//========================================================
