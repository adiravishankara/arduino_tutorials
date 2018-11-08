void motor_control(String button, int direc,int motor_speed){
  if(button.equals("UP")){
    digitalWrite(inA, LOW);
    digitalWrite(inB,HIGH);
  }else if(button.equals("DOWN")){
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
  }
  if(button.equals("VOL+")){
    motor_speed += 20;
    motor_speed = constrain(motor_speed,100,255);
  }
  else if(button.equals("VOL-")){
    motor_speed -= 20;
    motor_speed = constrain(motor_speed,100,255);
  }
  analogWrite(enablePin,motor_speed);
    
}

