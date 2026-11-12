#include <stdio.h>

int main() {
    double costPrice, sellPrice, quantity;
    double *ptr_cost = &costPrice;
    double *ptr_sell = &sellPrice;
    double *ptr_qty = &quantity;

    printf("Enter cost price: ");
    scanf("%lf", ptr_cost);

    printf("Enter selling price: ");
    scanf("%lf", ptr_sell);

    printf("Enter quantity sold: ");
    scanf("%lf", ptr_qty);

    double total_cost, total_sales, profit_loss;
    double *ptr_tcost = &total_cost;
    double *ptr_tsales = &total_sales;
    double *ptr_pl = &profit_loss;

    *ptr_tcost = (*ptr_cost) * (*ptr_qty);
    *ptr_tsales = (*ptr_sell) * (*ptr_qty);
    *ptr_pl = (*ptr_tsales) - (*ptr_tcost);

    printf("\n=== Result ===\n");
    if (*ptr_pl > 0) {
        printf("Profit: Rs. %.2f\n", *ptr_pl);
        double profit_percent = ((*ptr_pl) / (*ptr_tcost)) * 100;
        printf("Profit Percentage: %.2f%%\n", profit_percent);
    }
    else if (*ptr_pl < 0) {
        printf("Loss: Rs. %.2f\n", (*ptr_tcost) - (*ptr_tsales));
    }
    else {
        printf("No profit no loss\n");
    }

    double *ptr_larger;
    if (*ptr_cost > *ptr_sell) {
        ptr_larger = ptr_cost;
        printf("\nLarger pointer points to costPrice: %.2f\n", *ptr_larger);
    }
    else if (*ptr_sell > *ptr_cost) {
        ptr_larger = ptr_sell;
        printf("\nLarger pointer points to sellPrice: %.2f\n", *ptr_larger);
    }
    else {
        ptr_larger = ptr_cost;
        printf("\nBoth prices are equal: %.2f\n", *ptr_larger);
    }

    printf("\n=== Address Table ===\n");
    printf("Variable/Pointer     Address\n");
    printf("costPrice            %p\n", &costPrice);
    printf("sellPrice            %p\n", &sellPrice);
    printf("quantity             %p\n", &quantity);
    printf("ptr_cost             %p\n", &ptr_cost);
    printf("ptr_sell             %p\n", &ptr_sell);
    printf("ptr_qty              %p\n", &ptr_qty);

    return 0;
}
