////////////////////////Все переменные/////////////////////////////////
int button = 2;

int led1 = 8;
int button2 = 3;
int led2 = 9;
int(x);
int(y);
int(cifr);
int arraycifr[10]={1,2,1,2,1,1,1,2,1};
int (a);
int(timecifr);
int(b);
int(roundd);
int(c);
int(k);
int(pere);
int(nround);
int(rrr);
///////////////////////(Объявление переверии)////////////////////////////
void setup() {

pinMode(led1, OUTPUT);

pinMode(button, INPUT);

pinMode(led2, OUTPUT);

pinMode(button2, INPUT);
}
//////////////////////ф-я для переворота числа///////////////////////
int perevernut(int c, int k){
    while(c>0.1){
    k=k*10+c%10;
  c/=10;}
  return(k);
  }
int rround(int b, int r){
  while(b>0.1){
    b/=10;
    r=r+1;
  }
  return r;
}
int migan(int rrr){
      if (rrr==1){
              digitalWrite(led1, HIGH);
        delay(1000);
        digitalWrite(led1, LOW);
            }
            if (rrr==2)
            {
              digitalWrite(led2, HIGH);
        delay(1000);
        digitalWrite(led2, LOW);
                          }
}
/////////////////////Непосредственно программа////////////////////////
int main (){
  cifr=1212121212;
  roundd=rround(cifr,0);
  pere=perevernut(cifr,0);
    nround=0;
  while(roundd>0){   ////все раунды////
       nround++;       ////счетчик номера раунда////
       /////мигание///
       while(nround>0){
            rrr=pere%10;
            migan(rrr);
            pere/=10;
       nround--;
       }
       /////сбор данных с кнопок////
       /////проверка данных с кнопок////
       





    roundd--;    ////отсчет раунда//////
  }
}
