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
![verdict garasi mobil saha](https://user-images.githubusercontent.com/81666422/113583265-a2a36000-9653-11eb-8ff1-5ef950fd90c2.jpeg)

## Penjelasan Soal
Di soal garasi mobil saha diminta untuk memastikan apakah garasi saha dapat menampung semua mobil dan mobil pertama apakah bisa keluar.

## Penjelasan Solusi
Pada input pertama diminta untuk jumlah mobil dan kapasitas garasi, lalu untuk inputan kedua adalah jam masuk dan keluarnya mobil. Sesuai syarat mobil tidak bisa keluar dan masuk pada jam yang sama. Pertama membuat fungsi counter untuk menghitung jam keluar masuk mobil. Contoh mobil pertama masuk jam 3 dan keluar jam 8 maka yang tersimpan di counter adalah 3 4 5 6 7. Setelah data masuk dilanjutkan pada fungsi maixcounter, fungsi tersebut digunakan untuk menghitung data waktu yang masuk dengan kapasitas garasi. Mobil bisa masuk jika jam masuk mobil > jam masuk mobil sebelumnya, jam keluar mobil < jam keluar mobil sebelumnya atau jam masuk mobil < jam keluar mobil sebelumnya.



