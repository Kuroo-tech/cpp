//cau 1
#include<bits/stdc++.h>
using namespace std;
class Nguoi
{
	private:
		char hoDem[50];
		char Ten[30];
		char ngaySinh[30];
	public:
		void nhap(){
			cout<<"nhap ho dem:"<<endl;
			cin.getline(hoDem, 50);
			cout<<"nhap ten:"<<endl;
			cin.getline(Ten, 30);
			cout<<"nhap ngay sinh:"<<endl;
			cin.getline(ngaySinh, 30);
		}
		void xuat(){
			cout<<"ho dem:"<<hoDem<<endl;
			cout<<"ten:"<<Ten<<endl;
			cout<<"ngay sinh:"<<ngaySinh<<endl;
		}
		bool operator > (const Nguoi &b) const {
		    char tenA[30], tenB[30];
		    char hodemA[50], hodemB[50];
		    strcpy(tenA, Ten);
		    strcpy(tenB, b.Ten);
		    strcpy(hodemA, hoDem);
		    strcpy(hodemB, b.hoDem);
		    for (int i = 0; tenA[i]; i++) tenA[i] = tolower(tenA[i]);
		    for (int i = 0; tenB[i]; i++) tenB[i] = tolower(tenB[i]);
		    for (int i = 0; hodemA[i]; i++) hodemA[i] = tolower(hodemA[i]);
		    for (int i = 0; hodemB[i]; i++) hodemB[i] = tolower(hodemB[i]);

		    int cmp = strcmp(tenA, tenB);
		    if (cmp > 0) return true;
		    if (cmp < 0) return false;
		    return strcmp(hodemA, hodemB) > 0;
		}
};


// cau 2
class Sinhvien:public Nguoi{
	protected:
		char maSinhVien[50];
		float diemTrungBinh;
	public:
		void nhap(){
			Nguoi::nhap();
			cout<<"nhap ma sinh vien:"<<endl;
			cin.getline(maSinhVien, 50);
			cout<<"nhap diem trung binh:"<<endl;
			cin>>diemTrungBinh;
			cin.ignore();

		}
		void xuat(){
			Nguoi::xuat();
			cout<<maSinhVien<<endl;
			cout<<diemTrungBinh<<endl;
		}
		// =====du lieu kieu thuoc tinh =====
	    char* getmaSinhVien() {
	        return maSinhVien;
	    }

	    float getdiemTrungBinh() {
	        return diemTrungBinh;
	    }
};
//int main(){
//	Nguoi a,b;
//	cout<<" nhap thong tin a:"<<endl;
//	a.nhap();
//	cout<<"nhap thong tin b:"<<endl;
//	b.nhap();
//	Sinhvien s;
//	s.nhap();
//	a.xuat();
//	b.xuat();
//	s.xuat();
//	 if (a > b) cout << "a > b";
//    else cout << "a <= b\n";
//    return 0;
//}
int main() {
    int n;
    cout << "Nhap so sinh vien (<= 200): ";
    cin >> n;
    cin.ignore();

    Sinhvien ds[200];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

  	//sap xep tang dan
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i] > ds[j]) {
                swap(ds[i], ds[j]);
            }
        }
    }

    cout << "\nDanh sach sinh vien sau khi sap xep:\n";
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
        cout << "-----------------\n";
    }

	// tim diem cao nhat va in ra
    float maxDiem = ds[0].getdiemTrungBinh();
    for (int i = 1; i < n; i++) {
        if (ds[i].getdiemTrungBinh() > maxDiem) {
            maxDiem = ds[i].getdiemTrungBinh();
        }
    }

    cout << "\nSinh vien co diem trung binh cao nhat (" << maxDiem << "):\n";
    for (int i = 0; i < n; i++) {
        if (fabs(ds[i].getdiemTrungBinh() - maxDiem) < 1e-6) {
            ds[i].xuat();
            cout << "-----------------\n";
        }
    }

    return 0;
}
