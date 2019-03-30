#include <EEPROM.h>

String inputs;
#define relay1 2 //Connect relay1 to pin 9
#define relay2 3 //Connect relay2 to pin 8

void setup()
{
Serial.begin(9600); //Set rate for communicating with phone
pinMode(relay1, OUTPUT); //Set relay1 as an output
pinMode(relay2, OUTPUT); //Set relay2 as an output
digitalWrite(relay1, HIGH); //Switch relay1 off
digitalWrite(relay2, HIGH); //Swtich relay2 off
}
void loop()
{
while(Serial.available()) //Check if there are available bytes to read
{
delay(10); //Delay to make it stable
char c = Serial.read(); //Conduct a serial read
if (c == '#'){
break; //Stop the loop once # is detected after a word
}
inputs += c; //Means inputs = inputs + c
}
if (inputs.length() >0)
{
Serial.println(inputs);

if(inputs == "A")
{
digitalWrite(relay1, LOW);
}
else if(inputs == "a")
{
digitalWrite(relay1, HIGH);
}
else if(inputs == "B")
{
digitalWrite(relay2, LOW);
}
else if(inputs == "b")
{
digitalWrite(relay2, HIGH);
}
else if(inputs == "C")
{
digitalWrite(relay1, LOW);  
digitalWrite(relay2, LOW);
}
else if(inputs == "c")
{
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
}
inputs="";
}
}
