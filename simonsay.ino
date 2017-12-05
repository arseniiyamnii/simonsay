/*
проба сделать без функций и указателей
 */
/*
Это вступление
 */
int led = 8;
int button = 2;
int ledtwo = 9;
int buttontwo = 3;
//testcommit1
   void setup() {
   pinMode(led, OUTPUT);
   pinMode(button, INPUT);
   pinMode(ledtwo, OUTPUT);
   pinMode(buttontwo, INPUT);
    }
/*
Реально нужные функции
 */
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
     /*int * chislodc(int *a, int e){
      int d[e];
      int i;
      while (i!=e){
        d[i]=a[i];
        i++;
      }
      int *g=d;
      return g;
    }*/
    /*
    сбор с кнопок
     */
    /* int * sbor(int a){ //вводится номер раунда
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
    }*/
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
    void prov(int a){
      /*int res=1;
      int t[f];
      int r[f];
      for (int qwe = 0; qwe < f; ++qwe)
    {
      t[qwe]=a[qwe];
      r[qwe]=b[qwe];
    }
      for (int i = 0; i < f; ++i)
      {
        if (a[i]!=b[i]){
          res=0;
        }
      }*/
        if(a==1){
          for (int p = 5; p!=0 ;p--){
            digitalWrite(led, HIGH);
            delay (250);
            digitalWrite(led, LOW);
            delay (250);
          }
        }
        else{
          for (int p = 5; p!=0 ;p--){
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
  int d=sizearr(c);//тут мы узнали длину массива
  int i=1;//тут начинается отсчет раундов
  while(i<d){
    delay(2000);
    //собираем число для раунда
    int ch[i];
    for (int k = 0; k < i; ++k)
    {
      ch[k]=a[k];
    }
    //промигаем это число
    int *chuk=ch;
    fullmig(chuk,i);
    //начинаем сбор с кнопок
    int sb[i];
    for (int k = 0; k < i; ++k)
    {
      sb[k]=sborskn();
    }
    //начинаем сравнение их
    int ans = 1;
    for (int k = 0; k < i; ++k)
    {
      if(ch[k]!=sb[k]){
        ans=0;
      }
    }
    prov(ans);
    ++i;
  }
 /////временно(проверяю, не выходит ли из цикла).
}