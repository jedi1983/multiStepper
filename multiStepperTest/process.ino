#line 1
#include <Arduino.h>

void process()
{
  
 if(strcmp("G0",Command)==0) // this is command set for Motor
 {
  positionsStepper[0] = 0;
  positionsStepper[1] = 0;
  positionsStepper[2] = 0;
  positionsStepper[3] = 0;
  Serial.println("Ready To Take Data Joint \n");
 }
 
 else if(strcmp("X1",Command)==0)
 {
  pos = 0;
  sscanf(Data,"%d",&pos);
  positionsStepper[0] = pos;
  memset(rep, 0, sizeof(rep));
  strcpy(rep,"X1: ");
  strcpy(rep+3,Data);
  Serial.println(rep);
  memset(Command, 0, sizeof(Command));  
  memset(Data, 0, sizeof(Data));  
 }
 
 else if(strcmp("X2",Command)==0)
 {
  pos = 0;
  sscanf(Data,"%d",&pos);
  positionsStepper[1] = pos;
  memset(rep, 0, sizeof(rep));
  strcpy(rep,"X2: ");
  strcpy(rep+3,Data);
  Serial.println(rep);
  memset(Command, 0, sizeof(Command));  
  memset(Data, 0, sizeof(Data));  
 }

 else if(strcmp("X3",Command)==0)
 {
  pos = 0;
  sscanf(Data,"%d",&pos);
  positionsStepper[2] = pos;
  memset(rep, 0, sizeof(rep));
  strcpy(rep,"X3: ");
  strcpy(rep+3,Data);
  Serial.println(rep);
  memset(Command, 0, sizeof(Command));  
  memset(Data, 0, sizeof(Data));  
 }

 else if(strcmp("X4",Command)==0)
 {
  pos = 0;
  sscanf(Data,"%d",&pos);
  positionsStepper[3] = pos;
  memset(rep, 0, sizeof(rep));
  strcpy(rep,"X4: ");
  strcpy(rep+3,Data);
  Serial.println(rep);
  memset(Command, 0, sizeof(Command));  
  memset(Data, 0, sizeof(Data));  
 }
  
 else if(strcmp("G1",Command)==0)
 {
  steppers.moveTo(positionsStepper);
  steppers.runSpeedToPosition();
  //steppers.runToPosition();
  Serial.println("|Done");
  memset(Command, 0, sizeof(Command));  
  memset(Data, 0, sizeof(Data));  
 }
  
}

void SerialParser(void) 
{
 ByteCount = -1;
 ByteCount =  Serial.readBytesUntil('\n',Buffer,bSize);  
  
   if (ByteCount  > 0) {
        strcpy(Command,strtok(Buffer,"|"));
                   
        strcpy(Data,strtok(NULL,","));             
   }
   memset(Buffer, 0, sizeof(Buffer));   // Clear contents of Buffer
   Serial.flush();
}
  


