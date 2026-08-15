#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void copyName(char dest[61], int *destLen, char src[61], int srcLen){
    int t = 0;
    while(t < srcLen){
        dest[t] = src[t];
        t++;
    }
    dest[t] = '\0';
    *destLen = srcLen;
}

bool isGreater(char a[61], int alen, char b[61], int blen){
    int until = 0;
    if(alen <= blen){
        until = alen;
    }else{
        until = blen;
    }

    int k = 0;
    while(k < until){
        if(a[k] > b[k]){
            return true;
        }else if(a[k] < b[k]){
            return false;
        }
        k++;
    }
    return false;
}

void merge(char name[20][61], int length[20], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    char L[20][61], R[20][61];
    int Llen[20], Rlen[20];

    for(int i = 0;i<n1;i++){
        copyName(L[i], &Llen[i], name[l+i], length[l+i]);
    }
    for(int j = 0;j<n2;j++){
        copyName(R[j], &Rlen[j], name[m+1+j], length[m+1+j]);
    }

    int i = 0, j = 0, k = l;
    while(i<n1 && j<n2){
        if(!isGreater(L[i], Llen[i], R[j], Rlen[j])){
            copyName(name[k], &length[k], L[i], Llen[i]);
            i++;
        }else{
            copyName(name[k], &length[k], R[j], Rlen[j]);
            j++;
        }
        k++;
    }
    while(i<n1){
        copyName(name[k], &length[k], L[i], Llen[i]);
        i++;
        k++;
    }
    while(j<n2){
        copyName(name[k], &length[k], R[j], Rlen[j]);
        j++;
        k++;
    }
}

void mergeSort(char name[20][61], int length[20], int l, int r){
    if(l>=r){
        return;
    }
    int m = l + (r-l)/2;
    mergeSort(name, length, l, m);
    mergeSort(name, length, m+1, r);
    merge(name, length, l, m, r);
}

int main(){

    int size;
    scanf("%d", &size);
    char name[20][61];
    int length[20];

    for(int i = 0;i<size;i++){
        scanf(" %[^\n]",name[i]);
        int j = 0;
        bool second = false;
        while(1){
        if(name[i][j] == '\0'){
            length[i] = j;
            break;
        }
        if(j==0){
            name[i][0] = toupper(name[i][0]);
            j++;
            continue;
        }
        if(name[i][j] == ' '){
            second = true;
            j++;
            continue;
        }
        if(second == true){
            name[i][j] = toupper(name[i][j]);
            second = false;
            j++;
            continue;
        }
        name[i][j] = tolower(name[i][j]);
        j++;
        }
    }

    mergeSort(name, length, 0, size-1);

    for(int i = 0;i<size;i++){
        printf("%s\n",name[i]);
    }

    return 0;
}
