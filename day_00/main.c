#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int fraction_sum()
{
    int num1 = 0, denom1 = 0, num2 = 0, denom2 = 0,i = 0;
    
        printf("Enter first fraction : ");
        scanf("%d/%d", &num1, &denom1);

        printf("Enter second fraction : ");
        scanf("%d/%d", &num2, &denom2);

        int molecule = (num1 * denom2 + num2 * denom1) ;
        int denominator = (denom1 * denom2);

        do
        {
            i++;
            if (molecule % i == 0 && denominator % i == 0) {
                molecule = molecule / i;
                denominator = denominator / i;
               
            }
        } while (i < denominator);

        printf("The sum=%d/%d", molecule, denominator);

        return 0;
}
void f_to_c()
{
    int f = 0;
    scanf("%d", &f);
    float c = ((f - 32) * 5) / 9;
    printf("%.1f", c);
  

}
int main(void) {
   //f_to_c();//华氏温度和摄氏度
    fraction_sum();
    //int i = 40;
    //float x = 839.21f;
    //int k, j;
    //float z, y;
    //printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
    //printf("|%f|%10f|%10.2f|%-10.2f|\n", x, x, x, x);
    //scanf("%d%d%f%f", &k, &j, &z, &y);
    ////输入1-20.3-4.0e3，k=1，j=-20;z=0.3;y=-4000.00000
    return 0;
}