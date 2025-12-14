/*Sử dụng ngôn ngữ lập trình C++ để xây dựng chương trình (trong 1 file) theo các mô tả dưới đây:
Câu 1. (3.00 điểm):
Xây dựng lớp Media mô tả thông tin về phương tiện lưu trữ thông tin gồm các thuộc tính:
mã phương tiện, năm xuất bản, giá bán. Viết các phương thức cho lớp Media bao gồm:
- Các hàm tạo của lớp;
- Các phương thức thiết lập và lấy thông tin của các thuộc tính;
- Phương thức nhập dữ liệu cho các thuộc tính;
- Phương thức hiển thị thông tin về phương tiện bao gồm: mã phương tiện, năm sản xuất, giá
bán.
Câu 2. (3.50 điểm):
Xây dựng lớp Book mô tả thông tin về sách, lớp kế thừa từ lớp Media và bổ sung thêm các
thuộc tính: tên sách, tác giả, số trang. Viết các phương thức cho lớp Book bao gồm:
- Các hàm tạo của lớp;
- Các phương thức thiết lập và lấy thông tin của các thuộc tính;
- Phương thức nhập dữ liệu cho các thuộc tính;
- Phương thức hiển thị thông tin sách bao gồm: mã, tên sách, tác giả, số trang, năm xuất bản,
giá bán.
- Toán tử tải bội > để so sánh hai đối tượng của lớp Book (dựa vào tiêu chí số trang).
Câu 3. (3.50 điểm):
- Nhập vào một danh sách n đối tượng sách (n <= 50) thuộc lớp Book.
- Sắp xếp danh sách tăng dần theo tiêu chí số trang của sách sau đó hiển thị thông tin các
cuốn sách (theo mô tả ở phương thức hiển thị thông tin ở lớp Book) ra màn hình (thông tin mỗi
cuốn sách hiển thị trên một dòng).
- In ra màn hình những cuốn sách có giá bán cao nhất.
- Tính và in ra màn hình tổng số trang của các cuốn sách và tổng giá trị của các cuốn sách có
trong mảng.
- Nhập vào chuỗi ký tự tg và loại bỏ trong mảng những cuốn sách có tác giả là tg.*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/* =======================
   CÂU 1: LỚP MEDIA
   ======================= */
class Media {
protected:
    string maPhuongTien;
    int namXuatBan;
    double giaBan;

public:
    // Hàm tạo không tham số
    Media() {
        maPhuongTien = "";
        namXuatBan = 0;
        giaBan = 0;
    }

    // Hàm tạo có tham số
    Media(string ma, int nam, double gia) {
        maPhuongTien = ma;
        namXuatBan = nam;
        giaBan = gia;
    }

    // Setter và Getter
    void setMaPhuongTien(string ma) { maPhuongTien = ma; }
    string getMaPhuongTien() { return maPhuongTien; }

    void setNamXuatBan(int nam) { namXuatBan = nam; }
    int getNamXuatBan() { return namXuatBan; }

    void setGiaBan(double gia) { giaBan = gia; }
    double getGiaBan() { return giaBan; }

    // Nhập dữ liệu
    void nhap() {
        cout << "Nhap ma phuong tien: ";
        getline(cin, maPhuongTien);
        cout << "Nhap nam xuat ban: ";
        cin >> namXuatBan;
        cout << "Nhap gia ban: ";
        cin >> giaBan;
        cin.ignore();
    }

    // Hiển thị thông tin
    void hienThi() {
        cout << maPhuongTien << " | "
             << namXuatBan << " | "
             << giaBan;
    }
};

/* =======================
   CÂU 2: LỚP BOOK
   ======================= */
class Book : public Media {
private:
    string tenSach;
    string tacGia;
    int soTrang;

public:
    // Hàm tạo không tham số
    Book() : Media() {
        tenSach = "";
        tacGia = "";
        soTrang = 0;
    }

    // Hàm tạo có tham số
    Book(string ma, int nam, double gia,
         string ten, string tg, int trang)
        : Media(ma, nam, gia) {
        tenSach = ten;
        tacGia = tg;
        soTrang = trang;
    }

    // Setter và Getter
    void setTenSach(string ten) { tenSach = ten; }
    string getTenSach() { return tenSach; }

    void setTacGia(string tg) { tacGia = tg; }
    string getTacGia() { return tacGia; }

    void setSoTrang(int trang) { soTrang = trang; }
    int getSoTrang() { return soTrang; }

    // Nhập dữ liệu
    void nhap() {
        Media::nhap();
        cout << "Nhap ten sach: ";
        getline(cin, tenSach);
        cout << "Nhap tac gia: ";
        getline(cin, tacGia);
        cout << "Nhap so trang: ";
        cin >> soTrang;
        cin.ignore();
    }

    // Hiển thị thông tin
    void hienThi() {
        cout << maPhuongTien << " | "
             << tenSach << " | "
             << tacGia << " | "
             << soTrang << " | "
             << namXuatBan << " | "
             << fixed << setprecision(2) << giaBan << endl;
    }

    // Toán tử >
    bool operator>(const Book& other) {
        return this->soTrang > other.soTrang;
    }
};

/* =======================
   CÂU 3: HÀM MAIN
   ======================= */
int main() {
    int n;
    Book ds[50];

    cout << "Nhap so luong sach (n <= 50): ";
    cin >> n;
    cin.ignore();

    // Nhập danh sách sách
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sach thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // Sắp xếp tăng dần theo số trang
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i] > ds[j]) {
                swap(ds[i], ds[j]);
            }
        }
    }

    cout << "\nDANH SACH SACH SAU KHI SAP XEP:\n";
    for (int i = 0; i < n; i++) {
        ds[i].hienThi();
    }

    // Tìm giá bán cao nhất
    double maxGia = ds[0].getGiaBan();
    for (int i = 1; i < n; i++) {
        if (ds[i].getGiaBan() > maxGia)
            maxGia = ds[i].getGiaBan();
    }

    cout << "\nSACH CO GIA BAN CAO NHAT:\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].getGiaBan() == maxGia)
            ds[i].hienThi();
    }

    // Tính tổng số trang và tổng giá trị
    int tongTrang = 0;
    double tongGia = 0;
    for (int i = 0; i < n; i++) {
        tongTrang += ds[i].getSoTrang();
        tongGia += ds[i].getGiaBan();
    }

    cout << "\nTong so trang: " << tongTrang << endl;
    cout << "Tong gia tri sach: " << fixed << setprecision(2) << tongGia << endl;

    // Xóa sách theo tác giả
    string tg;
    cout << "\nNhap ten tac gia can loai bo: ";
    getline(cin, tg);

    for (int i = 0; i < n; ) {
        if (ds[i].getTacGia() == tg) {
            for (int j = i; j < n - 1; j++) {
                ds[j] = ds[j + 1];
            }
            n--;
        } else {
            i++;
        }
    }

    cout << "\nDANH SACH SAU KHI LOAI BO TAC GIA \"" << tg << "\":\n";
    for (int i = 0; i < n; i++) {
        ds[i].hienThi();
    }

    return 0;
}
