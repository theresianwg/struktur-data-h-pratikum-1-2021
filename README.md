# Genjil Ganap
## Verdict
AC saat revisi

## Bukti


## Penjelasan Soal
Di soal genjil ganap diminta untuk mengurutkan plat mobil dengan ketentuan plat nomor genap berada di depan dengan urutan terbalik dan ganjil dibelakang dengan urutan tetap. 

## Penjelasan Solusi
``` 
int main () {
	
	
    SinglyList myList;
    myList.init();
    
	int testcase, N;
    cin >> testcase;
        for (int i=0; i<testcase; i++) {
        	cin >> N;
        	myList.push(N);   
        }

    cout <<  "Urutan Mobil Roy : ";
    for (int i = 0; i < myList._size; i++) {
        printf("%d ", myList.getAt(i));
    }
    printf("\n");
    
    return 0;
}
```
Pertama, di soal ini kita menggunakan linked list dengan menginisialisasi ``` SinglyList myList; ``` Lalu ``` myList.init(); ``` berfungsi untuk menginisialisasi untuk list kosong. Lalu ``` cin >> testcase; ``` untuk menginputkan testcase jika di soal testcasenya yaitu 5, dilanjutkan dengan ``` cin >> N; ``` untuk menginputkan plat nomor ganjil dan genap. Untuk  mengeluarkan hasil genap di depan dengan urutan terbalik  dan ganjil dibelakang dengan urutan tetap menggunakan ``` void push ``` dilanjutkan jika genap menggunakan ``` push front ``` dan ganjil menggunakan ```push back```. ``` myList.push(N); ``` sebagai push yang telah diinputkan. ``` printf("%d ", myList.getAt(i)); ``` berfungsi untuk mengeluarkan hasil list.

## Visualisasi Solusi






