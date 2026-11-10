#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Weather {
    char outlook[9]; //outlook{overcast,sunny,rain}
    int temperature;
    int humidity;
    char wind; //wind{T,F}
};

void playing_decision(struct Weather* w){

    if(strcmp(w->outlook, "overcast") == 0){
        printf("yes\n");
    }else if(strcmp(w->outlook, "rain") == 0){
        if(w->wind == 'F'){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }else if(strcmp(w->outlook, "sunny") == 0){
        if(w->humidity > 77.5){
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
}

int main(){

    int n;
    scanf("%d", &n);

    struct Weather* days = (struct Weather*) malloc(sizeof(struct Weather) * n);

    for(int i = 0; i < n; i++){
        scanf(" %8s %d %d %c", days[i].outlook, &days[i].temperature, &days[i].humidity, &days[i].wind);
    }

    for(int i = 0; i < n; i++){
        playing_decision(&days[i]);
    }

    free(days);
    return 0;
}
