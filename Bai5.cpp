#include <stdio.h>

void nhapThongTin(int *maLo, int *soLuong, float *donGia, int *soNgay) {
    printf("Nhap ma lo hang: ");
    scanf("%d", maLo);
    
    printf("Nhap so luong kien hang: ");
    scanf("%d", soLuong);
    
    printf("Nhap don gia luu kho tren 1 kien trong 1 ngay: ");
    scanf("%f", donGia);
    
    printf("Nhap so ngay luu kho: ");
    scanf("%d", soNgay);
}

float tinhChiPhiLuuKho(int soLuong, float donGia, int soNgay, float *tyLeChietKhau) {
    float tongTien = (float)soLuong * donGia * (float)soNgay;
    
    if (soNgay > 30) {
        *tyLeChietKhau = 10.0f;
        tongTien = tongTien * 0.9f;
    } else {
        *tyLeChietKhau = 0.0f;
    }
    
    return tongTien;
}

void hienThiKetQua(int maLo, int soLuong, int soNgay, float tyLeChietKhau, float tongPhi) {
    printf("\n--- THONG TIN LO HANG %d ---\n", maLo);
    printf("So luong: %d kien\n", soLuong);
    printf("Thoi gian: %d ngay\n", soNgay);
    printf("Ty le chiet khau: %.0f%%\n", tyLeChietKhau);
    printf("Tong phi luu kho: %.2f VND\n", tongPhi);
}

int main() {
    int luaChon;
    int maLo, soLuong, soNgay;
    float donGia;
    float tyLeChietKhau = 0.0f;
    float tongPhi = 0.0f;

    do {
        printf("\n=== TRUNG TAM KHO VAN WAREHOUSE_LOGISTICS ===\n");
        printf("1. Tinh chi phi luu kho lo hang\n");
        printf("2. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapThongTin(&maLo, &soLuong, &donGia, &soNgay);

                if (soLuong <= 0 || donGia < 0 || soNgay < 0) {
                    printf("\nLoi: So luong kien hang phai lon hon 0, don gia va so ngay khong duoc am. Vui long thu lai!\n");
                } else {
                    tongPhi = tinhChiPhiLuuKho(soLuong, donGia, soNgay, &tyLeChietKhau);
                    hienThiKetQua(maLo, soLuong, soNgay, tyLeChietKhau, tongPhi);
                }
                break;

            case 2:
                printf("\nCam on ban da su dung he thong. Tam biet!\n");
                break;

            default:
                printf("\nLua chon khong hop le. Vui long chon lai tu 1 den 2!\n");
                break;
        }
    } while (luaChon != 2);

    return 0;
}
