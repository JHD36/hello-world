//Pins
int IPin1 = //input  pin 1 at port#
int IPin2 = //input  pin 2 at port#

int OPin1 = //output pin1 at port#
int OPin2 = //output pin2 at port#

//global cariables
int High_threshold = 511

//Functions
void player1win(){}
void player2win(){}
void fail(){}
void pnt99win_player1(){}
void pnt99win_player2(){}
void reset(){}
void buzzer1(){}
void buzzer2(){}

void setup(){
    float time_to_complete = 5000;//5sec in ms
    int player1_pnts = 0;
    int player2_pnts = 0;
}

void loop() {
    //ROUND STARTS
    delay(3000);//wait 3secs before modules are picked

    curr_time = time();//time modules start
    time_to_complete *= 0.909; //time to complete gets 10% faster
    int selection = rand()%4; //rand value 0to3 (which module)

    buzzer1()
    //stab
    if selection == 0
    {
        //set output pins as 00 (OPin2,OPin1)
        digitalWrite(OPin1, LOW);
        digitalWrite(OPin2, LOW);

        //MODULE STARTS
        //complete if circuit is complete
        while True
        {
            if analogRead(IPin1) >= High_threshold
            {
                player1win()
                break
            }
            if analogRead(IPin2) >= High_threshold
            {
                player2win()
                break
            }
            If curr_time >= curr_time + time_to_complete
            {
                fail()
                break
            }
        }
    }

    //slash
    if selection == 1
    {   //set output pins as 01 (OPin2,OPin1)
        digitalWrite(OPin1, HIGH);
        digitalWrite(OPin2, LOW);

        //MODULE STARTS
        //complete if circuit is complete
        while True
        {
            if analogRead(IPin1) >= High_threshold
            {
                player1win()
                break
            }
            if analogRead(IPin2) >= High_threshold
            {
                player2win()
                break
            }
            If curr_time >= curr_time + time_to_complete
            {
                fail()
                break
            }
        }
    }

    //Grindstone
    if selection == 2
    {
        //getting state of module before round
        bool Player1_prev = analogRead(IPin1) >= High_threshold
        bool Player2_prev = analogRead(IPin2) >= High_threshold
        bool Player1_now = false
        bool Player2_now = false

        //set output pins as 10 (OPin2,OPin1)
        digitalWrite(OPin1, LOW);
        digitalWrite(OPin2, HIGH);
        
        //MODULE STARTS
        //complete if circuit is different then inital
        while True
        {
            Player1_now = analogRead(IPin1) >= High_threshold
            Player2_now = analogRead(IPin2) >= High_threshold
            
            //state changed
            if Player1_now != Player1_prev
            {
                player1win()
                break
            }
            //state changed
            if Player2_now != Player1_prev
            {
                player2win()
                break
            }
            If curr_time >= curr_time + time_to_complete
            {
                fail()
                break
            }
        }
    }


    //War Cry
    if selection == 3
    {
        //set output pins as 11 (OPin2,OPin1)
        digitalWrite(OPin1, HIGH);
        digitalWrite(OPin2, HIGH);
        
        //MODULE STARTS
        //complete if circuit is complete
        while True
        {
            if analogRead(IPin1) >= High_threshold
            {
                player1win()
                break
            }
            if analogRead(IPin2) >= High_threshold
            {
                player2win()
                break
            }
            If curr_time >= curr_time + time_to_complete
            {
                fail()
                break
            }
        }
    }

    //check if players points are at 99 before starting new round
    if player1_pnts == 99: pnt99win_player1()
    if player2_pnts == 99: pnt99win_player2()
}