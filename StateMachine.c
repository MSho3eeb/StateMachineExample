#include <stdio.h>

typedef enum{
    STATE_A = 0,
    STATE_B,
    STATE_C
}State_Type;

void state_a_func(void);
void state_b_func(void);
void state_c_func(void);
void stateMachineInit(void);

static void (*State_Table[]) (void) = {state_a_func, state_b_func, state_c_func};

static State_Type currentState;
static int clk = 0;


int main(){
    stateMachineInit();

    while(1){
        State_Table[currentState]();
        clk++;
    }



    return 0;
}


void stateMachineInit(void){
    currentState = STATE_A;
    clk = 0;
}
void state_a_func(void){
    if(clk == 2){
        currentState = STATE_B;
        printf("State A\n");
    }

}
void state_b_func(void){
    if(clk == 5){
        currentState = STATE_C;
        printf("State B\n");
    }
}
void state_c_func(void){
    if(clk == 9){
        currentState = STATE_A;
        clk = 0;
        printf("State C\n");
    }

}