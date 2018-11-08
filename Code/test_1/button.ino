String button(decode_results *results){
  String val; 
  switch(results->value){
    case 0xFF629D: 
    val = "VOL+";
    break;
    case 0xFFA8F7: 
    val = "VOL-";
    break;
    case 0xFF9064: 
    val = "UP";
    break;
    case 0xFFE01F: 
    val = "DOWN";
    break;
    case 0xFF629B: 
    val = "POWER";
    break;
    case 0xFF629: 
    val = "1";
    break;
    case 0xFF62: 
    val = "2";
    break;
    default:
    val = "0";
    break;
  }
  return val;
}
