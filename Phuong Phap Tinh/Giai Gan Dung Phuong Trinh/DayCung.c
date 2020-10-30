#include <stdio.h>
#include <conio.h>
#include <math.h>

#define eps 1E-3
//Thay doi ham f(x) o day
float f(float x) {
    return exp(x)+x+1;
}
void Daycung(float a, float b) {
    printf("Bang Ket Qua : \n");
    printf("a\tb\tx\tf(x)\n");
    float x = a - (b - a) * f(a) / (f(b) - f(a));
    printf("\n%.3f\t%.3f\t%.3f\t%.3f", a, b, x, f(x));
    if (f(x) * f(a) < 0) {
        do {
            b = x;
            x = a - ((b - a) * f(a) / (f(b) - f(a)));
            printf("\n%.3f\t%.3f\t%.3f\t%.3f", a, b, x, f(x));
        }
        while (fabs(x - b) > eps);
    }

    else {
        do {
            a = x;
            x = a - ((b - a) * f(a) / (f(b) - f(a)));
            printf("\n%.3f\t%.3f\t%.3f\t%.3f", a, b, x, f(x));
        }
        while (fabs(x - a) > eps);
    }

    printf("\nNghiem cua phuong trinh x = %.3f ", x);
}

int main()
{
    float a, b;
    char input;
    do {
        do {
            printf(" Nhap khoang nghiem : ");
            scanf("%f", &a);
            scanf("%f", &b);

            if (f(a)*f(b) > 0) printf("{ %.3f ; %.3f } khong phai Khoang Nghiem ! Nhap lai ! !\n", a, b );
        } while (f(a)*f(b) > 0);

        Daycung(a, b);
        printf("\n\n<< Nhan ESC de dung chuong trinh hoac Phim Khac de tim them nghiem ! >>\n");
        input = getch();
    } while (input != 27);
    return 0;
}