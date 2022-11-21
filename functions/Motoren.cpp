
int powerrel=10, directrel=11;

void motorbefehl(int signal)
{
if(signal==0){
    digitalWrite(powerrel, LOW);
}
if(signal==1){
    digitalWrite(directrel,HIGH);
    digitalWrite(powerrel,HIGH);
}
if(signal==2){
    digitalWrite(directrel,LOW);
    digitalWrite(powerrel,HIGH);
}
}