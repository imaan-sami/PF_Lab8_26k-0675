#include <stdio.h>

void PrintPack()
{
    printf("\n====Recharges a Prepaid Mobile Number Packages===\n");
    printf("1. 100Rs\n");
    printf("2. 200Rs\n");
    printf("3. 300Rs\n");
    printf("4. 400Rs\n");
}

int PackNum()
{

    int PackNum;
    printf("Enter pack number (1-4): ");
    scanf("%d", &PackNum);

    while (PackNum < 1 || PackNum > 4)
    {
        printf("Enter pack number (1-4): ");
        scanf("%d", &PackNum);
    }

    return PackNum;
}

long long MobileNum()
{
    long long mobile_num;
    printf("Enter 11-digit mobile number: ");
    scanf("%11d", &mobile_num);
    return mobile_num;
}

float pack_amount(int pack)
{
    switch (pack)
    {
    case 1:
        return 100.0;
    case 2:
        return 200.0;
    case 3:
        return 300.0;
    case 4:
        return 400.0;
    default:
        return 0.0;
    }
}

float new_amount(float amount)
{
    float new_amount;
    new_amount = amount + (amount * 0.15);

    return new_amount;
}

float balance_bonus(float amount)
{
    float bonus;
    if (amount >= 500)
    {
        bonus = amount * 0.10;
    }
    bonus = 0;
}

void print_slip(int mobile_num, float amount, float tax, float totalBalance)
{
    printf("\n==Recharge Slip==\n");
    printf("Mobile Number: %8d\n", mobile_num);
    printf("Amount: %8f\n", amount);
    printf("Tax: %8.2f\n", tax);
    printf("Total balance: %8.2f\n", totalBalance);
}

int main()
{
    float totalSpent = 0.0;
    int i;
    for (i = 1; i < 3; i++)
    {
        printf("\n Transaction %d of 3: \n", i);
        PrintPack();
        int pack = PackNum();
        long long mobile = MobileNum();

        float amount = pack_amount(pack);
        float amountWithTax = new_amount(amount);
        float bonus = balance_bonus(amount);
        float totalBalance = amount + bonus;

        print_slip(mobile, amount, amountWithTax, totalBalance);
        totalSpent += amountWithTax;
    }

    printf("\nTotal Money Spent across 3 recharges: Rs. %.2f\n", totalSpent);
    return 0;
}