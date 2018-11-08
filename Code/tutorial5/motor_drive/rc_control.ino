void remote_vals(decode_results *results){
  if(results->value == 0xFF629D || results-> value == 0x511DBB){
    Serial.print("VOL + PRESSED, motor speed: ");
    motor_speed += 20;
    motor_speed = constrain(motor_speed,100,255);
    Serial.println(motor_speed);
  }
  else if (results->value == 0xFFA857 || results->value == 0xA3C8EDDB){
    Serial.print("VOL - PRESSED, motor speed: ");
    motor_speed -= 20;
    motor_speed = constrain(motor_speed,100,255);
    Serial.println(motor_speed);
  }
  else if (results->value == 0xFF906F || results->value == 0xE5CFBD7F
){
    Serial.print("Up Arrow Pressed, motor speed: ");
    Serial.println(motor_speed);
    direc = 0;
    Serial.println("Direction = Forward");
  }
  else if (results->value == 0xFFE01F || results->value == 0xE5CFBD7F
){
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
