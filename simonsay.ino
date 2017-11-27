int led = 8;
int button = 2;
int ledtwo = 9;
int buttontwo = 3;
 void setup() {
   pinMode(led, OUTPUT);
   pinMode(button, INPUT);
   pinMode(ledtwo, OUTPUT);
   pinMode(buttontwo, INPUT);
    }
    void mig(int a) {
      digitalWrite(led, LOW);
      digitalWrite(ledtwo, LOW);
      if (a == 1) {
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
      }
      if (a == 2){
        digitalWrite(ledtwo, HIGH);
        delay(1000);
        digitalWrite(ledtwo, LOW);
        delay(1000);
      }
    }
    void fullmig(int *a, int i){
      int b=0;
      int c=0;
      int d=0;
      while(b!=i){
        c=a[b];
        mig(c);
       b++;
      }
    }
    int sizearr(int *a){ //Этой функцией мы узнаем длинну массива
      int d=0;
      while(a[d] != 3){
        d++;
      }
      return d;
    }
    /*
    число для раунда. Для этого нужно ввеси указатель на массив 
    и номер раунда
     */
     int chislodc(int *a, int e){
      int d[e];
      int i;
      while (i!=e){
        d[i]=a[i];
        i++;
      }
      int *g=d;
      return g;
    }
    /*
    сбор с кнопок
     */
     int sbor(int a){ //вводится номер раунда
      int c[a];
      int b=0;
      int i=0;
      for (a;a>0;a--) {
        b=sborskn();
        c[i]=b;
        ++i;
        b=0;
      }
      int *d=c;
      return d;
    }
    int sborskn(){
      int x=0;
      while (x==0) {
        if (digitalRead(button) == HIGH) {
          x=1;
          while(digitalRead(button) == HIGH){}
        }
        if (digitalRead(buttontwo) == HIGH) {
          x=2;
          while(digitalRead(buttontwo) == HIGH){}
        }
      }
      delay (250);
      return x;
    }
    void (* resetFunc) (void) = 0;
    void prov(int *a, int *b){
        if(a==b){
          for (int i = 5; i!=0 ;i--){
            digitalWrite(led, HIGH);
            delay (250);
            digitalWrite(led, LOW);
            delay (250);
          }
        }
        else{
          for (int i = 5; i!=0 ;i--){
            digitalWrite(ledtwo, HIGH);
            delay (250);
            digitalWrite(ledtwo, LOW);
            delay (250);
          }
          resetFunc();
        }
    }
    /*
    начало проги
     */
void loop(){
  int a[]={2,1,1,1,1,1,1,3};
  int *c=a;
  int d=sizearr(c);
  int i=0;
  while(i<d){
    delay(1500);
    i++;
    int *ch=chislodc(c,i);
    fullmig(c,i);
    int *sb=sbor(i);
    //prov(ch,sb);
    delete ch;
    delete sb;
  }
}

