#include <stdio.h>

void print_titleAndRoute()
{

    printf("\n===Title and Routes===  \n ");
    printf("\n1. Karachi to Hyderabad:    Rs. 800");
    printf("\n2. Karachi to Sukkur:       Rs. 2200");
    printf("\n3. Karachi to Multan:       Rs. 3500");
}

int get_routenum()
{
    int route_num;
    printf("\nEnter route number (1-3): ");
    scanf("%d", &route_num);

    while (route_num < 1 || route_num > 3)
    {
        printf("\nEnter route number (1-3): ");
        scanf("%d", &route_num);
    }

    return route_num;
}

int get_seatsNum()
{
    int seat_num;
    printf("\nEnter seat number (1-6): ");
    scanf("%d", &seat_num);

    while (seat_num < 1 || seat_num > 6)
    {
        printf("\nEnter seat number (1-6): ");
        scanf("%d", &seat_num);
    }

    return seat_num;
}

int single_seat_fare(int routenum)
{
    int fare;
    switch (routenum)
    {
    case 1:
        fare = 800;
        break;
    case 2:
        fare = 2200;
        break;
    case 3:
        fare = 3500;
        break;
    }
    return fare;
}

int total_seat_fare(int fare, int seat)
{

    int total_fare;
    total_fare = fare * seat;

    return total_fare;
}

float seat_type_charge(int total_fare, char seat_type)
{
    float new_fare = total_fare;

    if (seat_type == 'B' || seat_type == 'b')
    {
        new_fare = total_fare + (total_fare * 0.30);
    }
    else if (seat_type == 'E' || seat_type == 'e')
    {
        new_fare = total_fare;
    }

    return new_fare;
}

void print_ticket(int route_num, int seatnum, char seat_type, float final_fare)
{

    printf("\n");
    printf("\n===TICKET===\n");

    switch (route_num)
    {
    case 1:
        printf("Route Name: %21s\n", "Karachi to Hyderabad");
        break;
    case 2:
        printf("Route Name: %21s\n", "Karachi to Sukkur");
        break;
    case 3:
        printf("Route Name: %21s\n", "Karachi to Multan");
        break;
    }

    printf("Seats: %10d\n", seatnum);
    printf("Seat Type: %6c\n", seat_type);
    printf("Final Fare: %12.2f\n", final_fare);


}

int main(){
    int route_num,seat_num,fare,total_fare;
    float final_fare,company_total=0.0;
    char seat_type;
    for(int i=1;i<=2;i++){

        printf("\nPassenger %d of 2\n",i);
        print_titleAndRoute();
        route_num=get_routenum();
        seat_num=get_seatsNum();
        fare=single_seat_fare(route_num);
        total_fare=total_seat_fare(fare,seat_num);

        printf("\nEnter seat type (Economy-E, Business-B): ");
        scanf(" %c", &seat_type);

        final_fare= seat_type_charge( total_fare,seat_type);
        company_total=company_total+final_fare;

        print_ticket(route_num,seat_num,seat_type,final_fare);
    }
    printf("Total earning of company: %.2f",company_total);
    return 0;
}