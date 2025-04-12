#include"stdafx.h"
#pragma warning(disable:4996)




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const long long x = 1000000007;

void mul(long long **a, long long **b, long long **result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            long long aa = a[i][k] % x;
            for (int j = 0; j < n; j++) {
                result[i][j] = (result[i][j] + aa * (b[k][j] % x)) % x;
                if (result[i][j] < 0) result[i][j] += x;
            }
        }
    }
}

void copy(long long **a, long long **b, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
			 a[i][j] = b[i][j];
        }
    }
}

void show(long long **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
	long long k;
    scanf("%d %lld",&n,&k);
    long long **a = (long long **)malloc(n * sizeof(long long *));
    long long **res = (long long **)malloc(n * sizeof(long long *));
    long long **temp1 = (long long **)malloc(n * sizeof(long long *)); 
    long long **temp2 = (long long **)malloc(n * sizeof(long long *)); 
    for (int i = 0; i < n; i++) {
        a[i] = (long long *)malloc(n * sizeof(long long));
        res[i] = (long long *)malloc(n * sizeof(long long));
        temp1[i] = (long long *)malloc(n * sizeof(long long));
        temp2[i] = (long long *)malloc(n * sizeof(long long));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
            a[i][j]%=x;
            if (a[i][j]<0) a[i][j]+=x;
            res[i][j] = (i == j) ? 1 : 0;
        }
    }
    while (k>0) {
        if (k&1) {
            mul(res, a, temp1, n); 
            copy(res, temp1, n);
        }
        mul(a, a, temp2, n); 
        copy(a, temp2, n);
        k >>= 1;
    }
    show(res, n);
    return 0;
}