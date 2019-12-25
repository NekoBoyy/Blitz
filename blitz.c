#include <stdio.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
int n,m;

// A problems
int gcd(int a, int b); // 1 CMMDC a două numere. Algoritmul Euclid
int isPrime(int q); // 2 Algoritmul de verificare dacă un număr este prim sau compus
void firstPrimeNumbers(int n); // 3 Algoritmul de generare a primelor N numere prime
void decToX(int n, int x); // 6 Trecerea numerelor intregi din baza 10 in alta baza
int min_in_array(int *a, int len); // 12 Determinarea elementului de valoare minimă în tablou
int max_in_array(int *a, int len); // 12 Determinarea elementului de valoare maximă în tablou
void min_max_and_cout(int *a, int len, int k); //14  12+13 in one for
void move_arr_k_pos_right(int *a, int len, int k); // 17 Deplasarea elementelor din array cu k pozitii spre dreapta
void move_arr_k_pos_left(int *a, int len, int k); // 18 Deplasarea elementelor din array cu k pozitii spre stanga
void bubble_sort(int *a, int len); // 19 Sortare tablouri 1D - bubblesort
int longest_equal_seq(int *a, int len); // 22 Cea mai lungă secvență de numere egale dintr-un tablou
int longest_increasing_nr(int *a, int len); // 23 Cea mai lungă secvență de numere crescătoare dintr-un tablou
int nr_extremes(int *a, int len); // 24 Numărul de ”vârfuri” într-un tablou

// B problems
void sort_2d_arr(int *a, int i, int j); // 25 Sortarea elementelor într-un tablou 2D
void move_simetric_main(int a[n][m]); // 26 Deplasarea simetrică a elementelor dintr-un tablou 2D față de diagonala principală
void move_simetric_secondary(int a[n][m]); // 27 Deplasarea simetrică a elementelor dintr-un tablou 2D față de diagonala secundară
int max_sum_triangles(int a[n][n]); // 28 Diagonalele împart tabloul 2D în 4 triunghiuri. Să se determine triunghiul cu sumă maximală
char *big_sum(char *a, char* b); // 29 Scrieți un program pentru adunarea a 2 numere întregi. Numărul de  cifre - până la 1000

int main()
{
//    scanf("%d",&n);
//    int a[n][n];
//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++)
//            scanf("%d",&a[i][j]);
//    printf("%d ",max_sum_triangles(a));


    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++)
//            printf("%d ",a[i][j]);
//        printf("\n");
//    }
    return 0;
}

int gcd(int a,int b)
{
    int tmp;
    while(b != 0){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int isPrime(int q)
{
    if(q == 2)
        return 1;
    if(q < 2 || q % 2 == 0)
        return 0;
    for(int i=3;i*i<=q;i+=2)
        if(q % i == 0)
            return 0;
    return 1;

}

void firstPrimeNumbers(int n)
{
    int cc=0,num=2;
    while(cc!=n){
        if(isPrime(num)){
            printf("%d ",num);
            cc++;
        }
        num++;
    }
}

void decToX(int n,int x)
{
    int num=n;int i=0;
    int X[10000];
    while(num != 0){
        X[i]=num%x;
        num /= x;
        i++;
    }
    for(int j = i;i>=0;i--)
        printf("%d",X[j]);
}

int min_in_array(int *a, int len)
{
    int minn = INT_MAX;
    for(int i=0;i<len;i++){
        if(minn > a[i])
            minn = a[i];
    }
    return minn;
}

int max_in_array(int *a, int len)
{
    int maxx = INT_MIN;
    for(int i=0;i<len;i++){
        if(maxx < a[i])
            maxx = a[i];
    }
    return maxx;
}

void min_max_and_cout(int *a, int len, int k)
{
    int max = INT_MIN, min = INT_MAX, count = 0;
    for(int i=0;i<len;i++){
        if(min > a[i])
            min = a[i];
        if(max < a[i])
            max = a[i];
        if(a[i] == k)
            count++;
    }
    printf("Min: %d\nMax: %d\n%d elements with value %d",min,max,count,k);
}

void move_arr_k_pos_right(int *a, int len, int k)
{
    int tmp[len];
    int q = 0;
    for(int i=len-k;i<len;i++){
        tmp[q] = a[i];
        q++;
    }
    for(int i=len-1;i>k-1;i--){
        a[i] = a[i-k];
    }
    for(int i = 0;i<k;i++)
        a[i] =  tmp[i];
}

void move_arr_k_pos_left(int *a, int len, int k)
{
    int tmp[len];
    int q = 0;
    for(int i=0;i<k;i++){
        tmp[i] = a[i];
    }
    for(int i=0;i<len-k;i++){
        a[i] = a[i+k];
    }
    for(int i = len-k ;i<len;i++){
        a[i] =  tmp[q];
        q++;
    }
}

void bubble_sort(int *a, int len)
{
    int tmp;
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            if(a[i] < a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }

}

int longest_equal_nr(int *a, int len)
{
    int qq = 1, max = 1;
    for(int i=0;i<len;i++){
        if(a[i] == a[i+1]){
            qq++;
            if(qq > max)
                max = qq;
        }else{
            qq = 1;
        }
    }
    return max;
}

int longest_increasing_nr(int *a, int len)
{
    int qq = 1, max = 1;
    for(int i=0;i<len;i++){
        if(a[i] < a[i+1]){
            qq++;
            if(qq > max)
                max = qq;
        }else{
            qq = 1;
        }
    }
    return max;
}

int nr_extremes(int *a, int len)
{
    int qq = 0;
    for(int i=1;i<len-1;i++){
        if(a[i] > a[i-1] && a[i] > a[i+1])
            qq++;
    }
    return qq;
}

void sort_2d_arr(int *a, int i, int j)
{
    bubble_sort(a,i*j);
}

void move_simetric_main(int a[n][n])
{
    int tmp;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++){
            tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
    }
}

void move_simetric_secondary(int a[n][n])
{
    int tmp;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i;j++){
            tmp = a[i][j];
            a[i][j] = a[n-1-j][n-1-i];
            a[n-1-j][n-1-i] = tmp;
    }
}

int max_sum_triangles(int a[n][n])
{
    int sum[4] = {0,0,0};
    int q;
    if(n%2 == 0)
        q = n/2;
    else
        q = n/2;
    for(int i=0;i<q;i++){
        for(int j=1+i;j<n-i-1;j++)
            sum[0]+=a[i][j];
    }
    for(int i=q+1;i<n;i++){
        for(int j=n-i;j<i;j++)
            sum[1]+=a[i][j];
    }
//    for(int i=0;j<q;j++){
//        for(int i=1+j;i<n-j-1;i++)
//            sum[2]+=a[j][i];
//    }
//    for(int j=q+1;j<n;j++){
//        for(int i=n-j;i<j;i++)
//            printf("%d ",a[j][i]);
//            //sum[3]+=a[j][i];
//    }
    return min_in_array(sum,4);
}

char *big_sum(char *a, char* b)
{

}


