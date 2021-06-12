# Genjil Ganap
## Verdict
AC saat revisi

## Bukti
![bukti genjil genap](https://user-images.githubusercontent.com/81666422/113560165-c1dac700-962c-11eb-9614-6c599b5f04c6.jpg)

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
Pertama, di soal ini kita menggunakan linked list dengan menginisialisasi ``` SinglyList myList; ``` Lalu ``` myList.init(); ``` berfungsi untuk menginisialisasi untuk list kosong. Lalu ``` cin >> testcase; ``` untuk menginputkan testcase jika di soal testcasenya yaitu 5, dilanjutkan dengan ``` cin >> N; ``` untuk menginputkan plat nomor ganjil dan genap. Untuk  mengeluarkan hasil genap di depan dengan urutan terbalik  dan ganjil dibelakang dengan urutan tetap menggunakan ``` void push ``` dilanjutkan jika genap ``` if (value%2==0)``` menggunakan ``` push front ``` dan ganjil ``` if (value%2!=0) ``` menggunakan ```push back```. ``` myList.push(N); ``` sebagai push yang telah diinputkan. ``` printf("%d ", myList.getAt(i)); ``` berfungsi untuk mengeluarkan hasil list.

## Visualisasi Solusi
![visual genjil ganap](https://user-images.githubusercontent.com/81666422/113560300-fd759100-962c-11eb-9918-e7b348b4088e.jpeg)

# Nadut & Cayo
## Verdict
AC saat revisi

## Bukti
![bukti nadut cayo](https://user-images.githubusercontent.com/81666422/113560675-8bea1280-962d-11eb-972f-ee833c82edc6.jpg)

## Penjelasan Soal
Di soal nadut & cayo menyusun sebuah blok, jika pada blok terdapat angka yang lebih besar daripada angka pada susunan blok sebelumnya maka blok dengan angka sebelumnya dikeluarkan dari tumpukan.

## Penjelasan Solusi
```
int main () {
    Stack myStack;      
    myStack.init();
    
 int testcase, N,M;
    cin >> testcase;
        for (int i=0; i<testcase; i++) {
        cin >> N;

            for (int i=0; i<N; i++) {
            cin >> M;
            if (myStack.isEmpty()){
                myStack.push(M);
            }
            else {
                while (!myStack.isEmpty()){
                int top = myStack.top();
                if (M>top){
                    myStack.pop();
                }
                else{
                    break;
                }
            }
        myStack.push(M);
    }      
    
   }
    Stack temp;
    temp.init();
    while(!myStack.isEmpty()) {
        temp.push (myStack.top());        
        myStack.pop();                  
    }   

        cout<<"Susunan blok yang disusun Nadut dan Cayo adalah : ";
        while(!temp.isEmpty()) {         
            printf("%d ", temp.top());      
            temp.pop();                  
        }
        cout << endl;
    }
    return 0;
}
```
Pertama, di soal ini menggunakan stack dengan menginisialisasi ``` Stack myStack;  ```. Lalu ``` myStack.init (); ``` berfungsi untuk menginisialisasi untuk stack kosong. Lalu ``` cin >> testcase; ``` untuk menginputkan testcase jika di soal testcasenya yaitu 1, untuk ```  cin >> N; ``` berfungsi sebagai inputan banyaknya sususan. Dan ``` cin >> M; ``` berfungsi sebagai inputan angka-angka pada susunan balok. Lalu ``` if (myStack.isEmpty()){myStack.push(M);} ``` memasukkan input pada fungsi dan push pada stack. Selama stack tidak kosong maka akan berjalan terus, ``` top = myStack.top(); ``` berfungsi untuk menanpung nilai yang paling atas. Lalu jika M (angka pada susunan balok) lebih besar dari top maka angka yang lebih kecil akan terhapus, berhenti dan masuk pada stack lagi.```  Stack temp; ``` berfungsi untuk membuat stack baru. Setelah itu memasukkan nilai yang tepat pada temp sementara, ``` myStack.pop(); ``` menghapus nilai. ``` while(!temp.isEmpty()) ``` jika tidak kosong, lalu stack keluar dari ``` temp.top()); ```  Setelah itu nilai top  di myStack dihapus menggunakan  ``` temp.pop(); ```. 

## Visualisasi Solusi
![visual nadut cayo](https://user-images.githubusercontent.com/81666422/113579661-d0d27100-964e-11eb-8ac8-aeaa064f1474.jpeg)

# Garasi Mobil Saha 
## Verdict 
AC Perbaikan 

## Bukti
![bukti garasi saha](https://user-images.githubusercontent.com/81666422/121763308-18044300-cb65-11eb-9a1f-c1c29b71880d.png)

## Penjelasan Soal
Di soal garasi mobil saha diminta untuk memastikan apakah garasi saha dapat menampung semua mobil dan mobil pertama apakah bisa keluar.

## Penjelasan Solusi
```
int main() {
    
    int testcase, jumlah, kapasitas;
    scanf("%d\n", &testcase);
    while (testcase--) {
        scanf("%d %d", &jumlah, &kapasitas);
        
    int x[jumlah+10], y[jumlah+10]; 
    int total = 0; 
    bool bareng = 0; 
        for (int i = 1; i <= jumlah; i++) {
            scanf("%d %d", &x[i], &y[i]);
            if (x[i] == y[i]) 
            bareng = 1; 
            total += y[i]-x[i]; 
        }
 
        SinglyList nums; 
        slist_init(&nums);
        for (int j = 1; j <= jumlah; j++) 
        for (int i = x[j]; i < y[j]; i++) {
            slist_pushBack(&nums, i);
        } 
        
        if (isDobel(x, jumlah) || isDobel(y, jumlah) || Counter(&nums, total, kapasitas) > kapasitas || bareng) 
            printf("Hmm harus renovasi garasi nich\n"); 
        else 
            printf("Hore gausah renov garasi\n");
    }
    puts("");
    return 0;
}
```
Pertama menginputkan testcase dengan ``` scanf("%d\n", &testcase); ```, lalu ``` scanf("%d %d", &jumlah, &kapasitas); ``` untuk menginputkan jumlah mobil dan kapasitas garasi. 
Untuk menghitung waktu masuk dan keluar mobil menggunakan ``` int x[jumlah+10], y[jumlah+10]; ```. Lalu ``` int total = 0; ``` ```  total += y[i]-x[i];  ``` untuk menghitung waktu seluruh mobil, ``` bool bareng = 0; ``` ``` if (x[i] == y[i]) ``` untuk mengecek apakah waktu masuk dan keluar sama. ``` if (isDobel(x, jumlah) || isDobel(y, jumlah) || Counter(&nums, total, kapasitas) > kapasitas || bareng) ``` memasukkan semua kemungkinan, jika tidak bisa maka akan mengeluarkan dengan fungsi ```printf("Hmm harus renovasi garasi nich\n"); ``` dan sebaliknya ``` printf("Hore gausah renov garasi\n"); ```.

## Visualisasi Solusi
```
input 
1
2 1
1 5
3 8
```
![solusi_garasi_mobil_saha](https://user-images.githubusercontent.com/81666422/121763484-b5ac4200-cb66-11eb-8ca1-8ab8c325e131.jpg)

```
output
Hmm harus renovasi garasi nich
```

# Malur Rajin
## Verdict
AC Perbaikan

## Bukti
![bukti malur rajin](https://user-images.githubusercontent.com/81666422/121763492-d1174d00-cb66-11eb-8d2b-0f852ec235ec.png)

## Penjelasan Soal
Pada soal malur rajin diminta untuk memilih satu buku dari tumpukan dengan sisa soal paling sedikit. Untuk memilih buku itu, harus memisahkan semua buku yang ada di atasnya lalu meletakkan buku-buku tersebut ke lantai. Jika ada buku yang sama jumlah soalnya, maka akan memilih yang paling atas. Setelah dikerjakan, akan memilih buku lain dengan soal paling sedikit.

## Penjelasan Solusi
```
int main(){
    Stack myStack;
    myStack.init();
    
    int testcase, N;
    char buku [20];
    cin>>testcase;
		for(int i=1; i<=testcase; i++){
        	cin>>N;
        	if(N!=-1){
            	cin>>buku;
            if(N==0){
                continue;
            }
            myStack.push(N, buku);
        }
	else {
            myStack.tumpuk();
        }
    }
    return 0;
}
```
Pertama, di soal ini menggunakan stack dengan menginisialisasi ``` Stack myStack;  ```. Lalu ``` myStack.init (); ```. Lalu menginputkan testcase dengan ```cin>>testcase;```, dilanjutkan dengan memasukkan banyak jumlah soal yang tersisa pada sebuah buku dengan ``` cin>>N; ``` dan untuk menginputkan nama buku dan juga -1  artinya malur akan mengerjakan sebuah soal dengan inisiasi dibawah ini
```
if(N!=-1){
   cin>>buku;
        if(N==0){
           continue;
}
```
Lalu untuk menambahkan soal yang tersisa pada buku selanjutnya menggunakan push dengan ```  myStack.push(N, buku); ``` dan hasil akhir akan diinisiasi dengan ``` myStack.tumpuk(); ``` 

## Visualisasi Solusi
```
input
6
9 enggres
6 matematika
8 geo
-1
3 fisika
-1
```
![solusi_malur_rajin](https://user-images.githubusercontent.com/81666422/121763709-6109c680-cb68-11eb-851b-9401fc5962c9.jpg)
```
output
1 matematika
0 fisika
```


