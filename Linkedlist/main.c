/* 
 * File:   main.c
 * Author: fadime
 *
 * Created on November 15, 2016, 9:28 AM
 */

#include <stdio.h>
#include <stdlib.h>

struct nodeYapi{
    int data;
    struct nodeYapi *next; 
};
typedef struct nodeYapi node;  

node *basaekle(node *ls, int deger){ //listede basa ekleme 
    if(ls==NULL){
        ls=(node *)malloc(sizeof(node));
        ls->data=deger;
        ls->next=NULL;
        return ls;
    }
    node *yeni=(node *)malloc(sizeof(node));
    yeni->data=deger;
    yeni->next=ls;
    ls=yeni;
}
node *sonaekle(node *ls,int deger){ // listede sona ekleme
    node *pt=ls;
    if(pt==NULL){
        pt=(node *)malloc(sizeof(node));
        pt->data=deger;
        pt->next=NULL;
        return pt;
    }
    while(pt->next!=NULL)
        pt=pt->next;
    node *yeni=(node *)malloc(sizeof(node));
    yeni->data=deger;
    yeni->next=NULL;
    pt->next=yeni;
    return ls;
}
node *silme(node *ls,int silinecek){ // verilen degeri silinmesini saglar
    node *pt=ls;
    node *bas=ls;
    if(pt==NULL){
        printf("liste boş");
        return NULL;
    }
    if(pt->data==silinecek){
        ls=ls->next;
        free(pt);
        return ls;
    }
    while(ls->next!=NULL){
        if(ls->next->data==silinecek){
            node *ptr=ls->next;
            ls->next=ls->next->next;
            free(ptr);
            return bas;
            break;
        }
        if(ls->next->next==NULL && ls->next->data==silinecek){
            ls->next=NULL;
            return bas;
        }
        ls=ls->next;
    }
}
node *hepsiniSil(node *ls,int silinecek){//birden fazla ayni deger varsa hepsini siler
    node *pt=ls;
    node *bas=ls;
    if(pt==NULL)
        printf("boş liste");
    
    if(pt->data==silinecek){
        ls=ls->next;
        free(pt);
        return bas;
    }
    while(ls->next!=NULL){
        if(ls->next->data==silinecek){
            node *temp=ls->next;
            ls->next=ls->next->next;
            free(temp);
        }
        if(ls->next->next==NULL && ls->next->data==silinecek){
            ls->next=NULL;
            break;
            
        }
        ls=ls->next;
    }
    return bas;
}
node *arayaEkle(node *ls,int aranan,int eklenecek){ // listede verilen degerden sonra eklenecek degeri listeye dahil eder
    node *bas=ls;
    if(ls==NULL){
        printf("boş liste");
    }
    while(ls!=NULL){
        if(ls->data==aranan){
            node * temp = (node*)malloc(sizeof(node));
            temp->data=eklenecek;
            temp->next=ls->next;
            ls->next=temp;
           
            return bas;
        }
        ls=ls->next;
    }
    
}
node *indisarayaEkle(node *ls,int sira,int eklenecek){// verilen indisten sonra ekleme yapar
    node *bas=ls;
    int indis=0;
    if(ls==NULL){
        printf("boş liste");
    }
    while(ls!=NULL){
        if(indis==sira){
            node * temp = (node*)malloc(sizeof(node));
            temp->data=eklenecek;
            temp->next=ls->next;
            ls->next=temp;
           
            return bas;
        }
        indis++;
        ls=ls->next;
    }
    
}
int arananindisbul(node *ls,int aranan){ // parametre olarak verilen degerin indisini bulur
    int sayac=0;
    if(ls==NULL){
        printf("liste boş");
        return 0;
    }
    while(ls->next!=NULL){
        if(ls->data==aranan)
            break;
        sayac+=1;
        ls=ls->next;
    }
    return sayac;
}

node *dugumAl(int deger){ 
    node *yeni=(node*)malloc(sizeof(node));
    yeni->data=deger;
    yeni->next=NULL;
    return yeni;
}
node *dugumAlSonaEkle(node *ls,int deger){
    node *pt=ls;
    if(pt==NULL){
        /*pt=dugumAl(deger);
        return pt; 
        daha kısa olarak return ile direkt yazarız*/
        return dugumAl(deger);
    }
    while(pt->next!=NULL)
        pt=pt->next;
   /* node *yeni=dugumAl(deger);
    pt->next=yeni;
    burada da aynı şekilde  */
    pt->next=dugumAl(deger);
    return ls;
    
}

node *arananliste(node *ls, int aranan){ // birden fazla ayni deger varsa hepsini listeye atar
    node *arananlist=NULL;
    if(ls==NULL){
        printf("liste boş");
    }
    while(ls!=NULL){
        if(ls->data==aranan){
            arananlist=dugumAlSonaEkle(arananlist,ls->data);
        }
        ls=ls->next;
    }
    return arananlist;
}

void yaz(node *ls){ //listenin yazilmasini saglar
    while(ls!=NULL){
        printf("%d\n", ls->data);
        ls=ls->next;
    }
}
int main(int argc, char** argv) {
    node *liste=NULL;
   /*  list=basaekle(list,5);
    list=basaekle(list,3);
    list=basaekle(list,4);
    list=sonaekle(list,8);
    list=sonaekle(list,4);
    yaz(list);
    printf("silmeden sonra\n");
    //list=silme(list,5);
    //yaz(list);
    //printf("silmeden sonra\n");
    list=hepsiniSil(list,4);
    yaz(list);
    printf("silmeden sonra\n");
    list=silme(list,10);
    yaz(list);*/
    liste=dugumAlSonaEkle(liste,8);
    liste=dugumAlSonaEkle(liste,2);
    liste=dugumAlSonaEkle(liste,7);
    liste=dugumAlSonaEkle(liste,5);
    liste=dugumAlSonaEkle(liste,7);
    liste=dugumAlSonaEkle(liste,9);
    yaz(liste);
    //printf("arananliste\n");
    //node *aranacak=NULL;
   // aranacak=arananliste(liste,7);
    //yaz(aranacak);
     
    printf("\neklemeden sonra\n");
    liste=arayaEkle(liste,2,3);
    yaz(liste); 
    int deger=arananindisbul(liste,5);
    printf("%d\n", deger);
    
    return (EXIT_SUCCESS);
}

