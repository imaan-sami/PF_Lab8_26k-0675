#include <stdio.h>
void print_room_charges()
{
    printf("\n===Agha Khan Hospital Room Charges===\n");
    printf("1. General Ward:   Rs. 1500/day\n");
    printf("2. Semi-Private:   Rs. 3500/day\n");
    printf("3. Private:        Rs. 6000/day\n");
}

int getRoomType()
{
    int room_type;
    printf("Enter prefered room type(1-3): ");
    scanf("%d", &room_type);

    while (room_type < 1 || room_type > 3)
    {
        printf("Enter prefered room type (1-3): ");
        scanf("%d", &room_type);
    }

    return room_type;
}

int getStayDays()
{
    int days_stayed;
    printf("Enter number of days stayed(1-30): ");
    scanf("%d", &days_stayed);

    while (days_stayed < 1 || days_stayed > 30)
    {
        printf("Invalid! Re-Enter number of days stayed(1-30): ");
        scanf("%d", &days_stayed);
    }

    return days_stayed;
}

int cal_roomCharges(int room_type, int days)
{
    int total_charges;
    switch (room_type)
    {
    case 1:
        total_charges = 1500 * days;
        break;
    case 2:
        total_charges = 3500 * days;
        break;
    case 3:
        total_charges = 6000 * days;
        break;
    default:
        total_charges = 0;
    }
    return total_charges;

}

float cal_medicalCharges(){
    int medical_bill;
    float medicalCharges;

    printf("Enter medical bill: ");
    scanf("%d",&medical_bill);

    medicalCharges=medical_bill+(medical_bill*0.5);

    return medicalCharges;

}

float cal_discount(int amount, int days){
    float total_with_discount;
    if (days>=8){
        total_with_discount=amount-(amount*0.8);
        return total_with_discount;
    }
    else
    {return amount;}
}

void print_bill(int room_type, int days, float room_charges,float medicine_charges, float total){
    printf("\n===Agha Khan Billing Script===\n");


    switch (room_type)
    {
    case 1:
        printf("Room Name:%21s\n",  "General Ward");
        break;
    case 2:
        printf("Room Name:%21s\n",  "Semi-Private");
        break;
    case 3:
        printf("Room Name:%21s\n",  "Private");
        break;
    }

    printf("\nDays admitted:   %17d\n", days);

    printf("Room Charges:   %18.2f\n", room_charges);

    printf("Medical Charges:    %15.2f\n", medicine_charges);

    printf("Final Amount:   %18.2f\n", total);
    
}

int main(){
    char senior_citizen;
    int stay_days,room_type;
    float room_charge,medical_charges,total_amount,final_amount,new_final_amount=0;

    printf("Is the patient a senior citizen? (y/n):");
    scanf("%c",&senior_citizen);
    while (senior_citizen!='y' && senior_citizen!='n'){
        printf("Is the patient a senior citizen? (y/n):");
        scanf(" %c",&senior_citizen);
    }

    print_room_charges();
    room_type=getRoomType();
    stay_days=getStayDays();
    room_charge=cal_roomCharges(room_type, stay_days);
    medical_charges=cal_medicalCharges();
    total_amount=room_charge+medical_charges;
    final_amount=cal_discount(total_amount,stay_days);

    if (senior_citizen=='y'){
        new_final_amount=final_amount-1000;
        if (new_final_amount<0){
            new_final_amount=final_amount;
        }
    }
    else{
        new_final_amount=final_amount;
    }


    print_bill(room_type,stay_days,room_charge,medical_charges,new_final_amount);



}
