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
    void fullmig(long a) {
      int b;
      while (a!=0) {
        b = a % 10;
        a = a/10;
        mig(b);
      }
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
    long soed(long a, int b){
      long c;
      long d = 0;
      while(d == 0){
        d=(long)b;
      }
      c=a*10+d;
      return c;
    }
    long sbor(int a){
      long c=0;
      int b=0;
      int x;
      for (a;a>0;a--) {
        x=0;
        b=sborskn();
        c=soed(c,b);
        b=0;
      }
      return c;
    }
    int dlinc(long a){
      int b=0;
      while(a!=0){
        b++;
        a/=10;
      }
      return b;
    }
    long chislodc(int i,long c){
      int b;
      int a=0;
      for (i; i!=0; i--){
        a=a*10+c%10;
        c/=10;
      }
      return a;
    }
    void (* resetFunc) (void) = 0;
    void prov(long a, long b){
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
    long pere(long a){
        long b=0;
        while (a!=0){
          b=b*10+a%10;
          a/=10;
        }
        return b;
    }
  void loop(){
    long a=1222111221;
    int e=0;
    int c=dlinc(a);
    long b=0;
    long d=0;
    for (c;c!=0;c--){
      delay(2000);
      ++e;
      b=chislodc(e,a);
      fullmig(b);
      d=sbor(e);
      d=pere(d);
      prov(b,d);
    }
    ///committestpush23
  }