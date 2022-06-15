//1817051067 - Zia Danisvara Pakpahan
//study kasus aplikasi gudang stroring (penyimpanan) dan antiran pengiriman barang.

//pada pilihan 1, admin dapat menginput barang untuk disimpan menggunakan konsep stack.
//pada pilihan 2, admin dapat memasukkan id barang dan dapat mengirimkan barang dengan konsep queue.


#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>

#define max 30

using namespace std;

	struct stack{		//struct
		int top;
		string barang[max];
	}
	stack;  
	void awal();
	int kosong();
	int penuh();


	void push(string data);		//prototype fungsi tumpukan (stack)
	void pop();
	void mencari(string c);
	void ubah(string c);
	void hapus();


	typedef struct queue {	//struct
		int head;
		int tail;
		char data [20][20];
	}
		antrian;						//prototype fungsi antrian (queue)
		queue antri;
		void inisialisasi();
		int isFull();
		int isEmpty();
		void enqueue(char d[20]);
		void dequeue();
		void cari(string d);
		void rubah(string d);
		void clear();


	
	int main(){			//Program utama
		int t;
		do{
			int pil;
			string d,c,data;
			system("cls");
			cout<<"--------- Penyimpanan Barang Logistik---------"<<endl;
			cout<<"\t1. Gudang Storing Barang"<<endl;
			cout<<"\t2. Antrian Pengiriman Barang "<<endl;
			cout<<"--------------------------------------------"<<endl;
			cout<<"Masukan pilihan : ";
			cin>>pil;
			system("cls");
		
		switch(pil){
			case 1: // Stack
			int pilih;
			awal();
			do{
				cout<<"\n=========================================="<<endl;
				cout<<"************ Storing Barang ************"<<endl;
				cout<<"=========================================="<<endl;
				cout<<"\t1. Input barang"<<endl;
				cout<<"\t2. Keluarkan barang"<<endl;
				cout<<"\t3. Cari barang"<<endl;
				cout<<"\t4. Rubah barang"<<endl;
				cout<<"\t5. Bersihkan barang"<<endl;
				cout<<"\t6. Exit"<<endl;
				cout<<"------------------------------------------"<<endl;
				cout<<"Tumpukan"<<endl;
				
				for(int i=stack.top;i>=0;i--){
					cout<<"\n["<<stack.barang[i]<<"]"<<endl;
				}
	
	
				cout<<"\nMasukan pilihan : ";
				cin>>pilih;
				switch(pilih){
					case 1:
						cout<<"Masukan barang : ";
						cin>>data;
						push(data);
					break;
					case 2:
						pop();
						break;
					case 3:
						cout<<"Masukan barang yang ingin dicari : ";
						cin>>c;
						mencari(c);
						break;
					case 4:
						cout<<"Masukan barang yang ingin di rubah : ";
						cin>>c;
						ubah(c);
						break;
					case 5:
						hapus();
						cout<<"\nSudah kosong!"<<endl;
					break;
				case 6:
					cout<<"Tekan enter untuk keluar";
					break;
				default:
					cout<<"Terjadi Kesalahan!";
					break;
					
				}
			}
	
		while(pilih!=6);
		break;
	//antrian (queue)
			case 2:
				int pil;
				inisialisasi();
				char dt[20];
				do{
					cout<<"\n========================================="<<endl;
					cout<<"************ Antrian Pengiriman Barang ************"<<endl;
					cout<<"========================================="<<endl;
					cout<<"\t1. Masukan antrian barang"<<endl;
					cout<<"\t2. Kirim barang"<<endl;
					cout<<"\t3. Cari antrian"<<endl;
					cout<<"\t4. Rubah antrian"<<endl;
					cout<<"\t5. Kosongkan Antrian"<<endl;
					cout<<"\t6. Keluar"<<endl;
					cout<<"------------------------------------------"<<endl;
					cout<<" Antrian"<<endl;
					cout<<"Exit | ";
					for(int i=0;i<=antri.tail;i++)
						cout<<"["<<antri.data[i]<<"] ";
						cout<<"|";
						cout<<"\nMasukan pilihan : ";
						cin>>pil;
					switch(pil){
						case 1:
							if(!isFull()){
								cout<<"Antrian = ";
								cin>>dt;
								enqueue(dt);
							}
							else
								cout<<"\nSudah penuh!"<<endl;
						break;
						case 2:
							if(!isEmpty())
								dequeue();
								else
								cout<<"\nMasih kosong!"<<endl;
						break;
						case 3:
							cout<<"Masukan antrian yang ingin dicari : ";
							cin>>d;
							cari(d);
						break;
						case 4:
							cout<<"Masukan antrian yang ingin di rubah : ";
							cin>>d;
							rubah(d);
						break;
						case 5:
							clear();
							cout<<"\nSudah kosong!"<<endl;
						break;
						case 6:
							cout<<"\nTekan enter untuk keluar"<<endl;
						break;
						default :
							system("cls");
							cout<<"Error!";
						break;
					}
				}
				
			while(pil !=6);
			break;
			
		}
	
			system("cls");
			cout<<"Apakah Ingin Kembali Ke Menu Awal?"<<endl;
			cout<<"\t1. Ya"<<endl;
			cout<<"\t2. Tidak"<<endl;
			cout<<" Masukan pilihan : ";
			cin>>t;
			cout<<"\nTekan enter untuk keluar"<<endl;
		}
		
		while(t!=2);
	}


//fungsi stack


	void awal(){
		stack.top=-1;
	}

	int kosong(){
		if(stack.top==-1)
			return 1;
		else
			return 0;
	}


	int penuh(){
		if(stack.top==max-1)
			return 1;
		else
			return 0;
	}
	
	
	void push(string data){
		system("cls");
		if(!penuh()){			
			stack.top=stack.top+1;
			stack.barang[stack.top]=data;
		}
		else
			cout<<"Tumpukan barang penuh";
	}
	
	
	void pop(){
	system("cls");
	if (!kosong()){
	stack.top--;
	cout<<"Barang pada tumpukan ke-"<<stack.top+2<<" sudah di ambil";
	}
	else
		cout<<"Tumpukan barang kosong";
	}
	
	void mencari(string c){
		
		
		system("cls");
		
		
		for(int i=0;i<=stack.top;i++){
			if(c==stack.barang[i]){
				cout<<"Barang "<<c<<" di temukan di tumpukan "<<i+1<<endl;
			}
		}
	}
	
	
	void ubah(string c)	{
		char u[20];
		system("cls");
		for(int i=0;i<=stack.top;i++){
			if(c==stack.barang[i]){
				cout<<"\nRubah dengan : ";
				cin>>u;
				stack.barang[i]=u;
				cout<<"Barang "<<c<<" dirubah dengan "<<u;
			}
		}
	}
	
	void hapus(){
		system("cls");
		stack.top=-1;
		cout<<"Semua barang terhapus";
	}
	
	
	//Fungsi Antrian (Quaue)
	
	
		void inisialisasi(){
			antri.head=antri.tail=-1;	
		}
	
		int isFull(){
			if(antri.tail==max-1)
				return 1;
			else
				return 0;
		}
		
		int isEmpty(){
			if(antri.tail==-1){
				antri.head=-1;
			return 1;
			}
		else
			return 0;
		}


	void enqueue(char d[20]){
		system("cls");
		antri.head=0;
		antri.tail++;
		strcpy(antri.data[antri.tail],d);
	}


	void dequeue(){
		system("cls");
		cout<<"Antrain "<<antri.data[antri.head]<<" sudah dilayani"<<endl;
		for(int i=antri.head;i<=antri.tail;i++)
		strcpy(antri.data[i],antri.data[i+1]);
		antri.tail--;
	}
		
	void cari(string d){
		system("cls");
		for(int i=antri.head;i<=antri.tail;i++){
			if(antri.data[i]==d){
				cout<<"Antrian "<<d<<" di temukan di urutan "<<i+1<<endl;
			}
		}
	}
	
	void rubah(string d){
		char s[20];
		int i;
		system("cls");
		
		for(i=0;i<=antri.tail;i++){
			if(antri.data[i]==d){
				cout<<"\nRubah dengan : ";
				cin>>s;
				strcpy(antri.data[i],s);
				cout<<"Antrian "<<d<<" dirubah dengan "<<antri.data[i];
			}
		}
	}

	void clear(){
		system("cls");
		antri.head=antri.tail=-1;
		cout<<"Semua data terhapus";
	}
