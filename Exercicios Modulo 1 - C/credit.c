#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    long Card_Number;
    int Digit_Number = 0, Current_Digit = 0, Even_x2_Product = 0, Even_Digits = 0, Odd_Digits = 0,
        Total_Digit_Sum = 0;
    bool is_even = false;

    do
    {
        Card_Number = get_long("Número do Cartão: ");// Seleção do cartão
    }
    while (Card_Number < 0);

    int Digits_MstrCrd = Card_Number / pow(10, 14);// Checar os primeiros digitos do cartão
    int Digits_Visa_16 = Card_Number / pow(10, 15);
    int Digits_AmEx = Card_Number / pow(10, 13);
    int Digits_Visa_13 = Card_Number / (pow(10, 12));


    while (Card_Number != 0)// Loop para determinar cada cartão
    {

        Current_Digit = (Card_Number % 10);

        Digit_Number += 1;// Acrescenta 1 ao cartão

        if (is_even == true)//Checar a posição de cada numero no cartão
        {

            Even_x2_Product = Current_Digit * 2; // Multiplicando por 2

            while (Even_x2_Product != 0)//Adicionando digitos ao cartão
            {
                Even_Digits += Even_x2_Product % 10;
                Even_x2_Product /= 10;
            }

            is_even = false;
        }
        else
        {

            Odd_Digits += Current_Digit;

            is_even = true;
        }

        Card_Number /= 10; //Removendo o cartão antigo
    }

    Total_Digit_Sum = Even_Digits + Odd_Digits;//Adicionando digitos ao proximo cartão

    if (Total_Digit_Sum % 10 == 0)//Loop para checar a validade do cartão
    {

        if (Digit_Number == 16)
        {
            if (Digits_MstrCrd <= 55 && Digits_MstrCrd >= 51)
            {
                printf("MASTERCARD\n");
            }

            else if (Digits_Visa_16 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else if (Digit_Number == 15)
        {
            if (Digits_AmEx == 34 || Digits_AmEx == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else if (Digit_Number == 13)
        {
            if (Digits_Visa_13 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}