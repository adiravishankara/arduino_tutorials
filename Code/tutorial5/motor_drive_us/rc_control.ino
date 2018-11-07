void remote_vals(decode_results *results){
  if(results->value == 0xFF629D){
    Serial.print("VOL + PRESSED, motor speed: ");
    motor_speed += 20;
    motor_speed = constrain(motor_speed,100,255);
    Serial.println(motor_speed);
  }
  else if (results->value == 0xFFA857){
    Serial.print("VOL - PRESSED, motor speed: ");
    motor_speed -= 20;
    motor_speed = constrain(motor_speed,100,255);
    Serial.println(motor_speed);
  }
  else if (results->value == 0xFF906F){
    Serial.print("Up Arrow Pressed, motor speed: ");
    Serial.println(motor_speed);
    direc = 0;
    Serial.println("Direction = Forward");
  }
  else if (results->value == 0xFFE01F){
    Serial.print("Down Arrow Pressed, motor speed: ");
    Serial.println(motor_speed);
    direc = 1;
    Serial.print("Direction = Reverse");
  }

  else{
    Serial.print("WRONG INPUT, motor speed: ");
    Serial.println(motor_speed);
  }
}
