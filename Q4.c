#include <stdio.h>
void print_rules()

{
    printf("\n===Title and Fare Rules===\n");
    printf("Base Fare:      Rs. 150\n");
    printf("First 10 km:    Rs 60 per km\n");
    printf("After 10 km:    Rs 45 per km\n");
}

float get_dis()
{
    float distance;
    printf("\nEnter distance (0-200): ");
    scanf("%f", &distance);

    while (distance <= 0.0 || distance > 200.0)
    {
        printf("Re-Enter distance (0-200): \n");
        scanf("%f", &distance);
    }
    return distance;
}

float get_waitTime()
{

    float wait_time;
    printf("\nEnter waiting time (0-120): ");
    scanf(" %f", &wait_time);

    while (wait_time < 0.0 || wait_time > 120.0)
    {
        printf("\nRe-Enter waiting time (0-120): ");
        scanf(" %f", &wait_time);
    }
    return wait_time;
}

float cal_disCharge(float distance)
{
    float distance_charge = 0.0;
    int base_fare = 150;

    if (distance > 0 && distance <= 10)
    {
        distance_charge = distance_charge + (base_fare + distance * 60);
    }
    if (distance > 10)
    {
        distance_charge = distance_charge + base_fare + (10.0 * 60.0) + ((distance - 10.0) * 45.0);
        
    }

    return distance_charge;
}

float cal_waitingCharge(float waiting_time)
{
    float waiting_charge = 0.0;

    if (waiting_time >= 0 && waiting_time <= 5)
    {
        waiting_charge = 0.0;
    }
    else
    {
        waiting_charge = waiting_charge + (10 * (waiting_time-5));
    }

    return waiting_charge;

}

float cal_nightCharge(int trip_hour, float final_charge){

    if (trip_hour>=22 || trip_hour<6){
        final_charge=final_charge*1.25;
    }
    
    return final_charge;

}

void print_receipt(float distance, float waiting_time, float final_fare)
{
    printf("\n===Trip Receipt===\n");
    printf("Distance:       %-8.2f \n",distance);
    printf("Waiting Time:   %-8.2f \n",waiting_time);
    printf("Final Fare:     %-8.2f \n",final_fare);

}

int main(){
    float distance, waiting_time,distance_charge,wait_time_charge,total_charge,final_charge,total_earning=0.0;
    int trip_hour;
    float highest=-9999;

    for (int i=1;i<=3;i++){

        printf("\nTrip %d of 3", i);

        

        print_rules();
        distance=get_dis();
        waiting_time=get_waitTime();
        distance_charge=cal_disCharge(distance);
        wait_time_charge=cal_waitingCharge(waiting_time);

        total_charge=distance_charge+wait_time_charge;

        printf("\nEnter hour of the trip (0-23): ");
        scanf(" %d",&trip_hour);
        while (trip_hour<0 || trip_hour>23){
            printf("\nRe-Enter hour of the trip (0-23): ");
            scanf("%d",&trip_hour);
        }


        final_charge=cal_nightCharge(trip_hour,total_charge);

        total_earning=total_earning+final_charge;
        
        if (final_charge > highest){
            highest=final_charge;
        }

        print_receipt(distance,waiting_time,final_charge);

    }
    printf("===========================");
    printf("\nTotal Earning:  %-8.2f",total_earning);
    printf("\nHighest Earning: %-8.2f",highest);




}


