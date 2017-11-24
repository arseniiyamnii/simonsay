/*
qwerty
 */
/*Тупостарт. Объявляются Пины и тыры-пыры*/
int led1 = 8;
int button1 = 2;
int led2 = 9;
int button2 = 3;
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(button2, INPUT);
}
/*Начинаются функции*/
/*это функция мигания. В нее вводится цифра 1/2. Если 1, то мигает этим диодом. Если 2, то другим*/
void mig(int a) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  if (a == 1) {
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  delay(1000);
  }
  if (a == 2)
  {
  digitalWrite(led2, HIGH);
  delay(1000);
  digitalWrite(led2, LOW);
  delay(1000);
}}
/*вводится число из 1 и 2. Оно промигивает его при помощи предыдущей функции*/
void fullmig(long a) {
  int b;
  while (a!=0) {
  b = a % 10;
  a = a/10;
  mig(b);
}}
/*идет ожидание ввода кнопок. Если нажата 1, то в переменную вводится 1. 2 => 2.*/
int sborskn(){
  int x=0;
  while (x==0) {
  if (digitalRead(button1) == HIGH) {
  x=1;
  while(digitalRead(button1) == HIGH){}}
  if (digitalRead(button2) == HIGH) {
  x=2;
  while(digitalRead(button2) == HIGH){}
  }}
  delay (250);
  return x;}
/*соединяет цифры. К числу прибавляет одну цифру*/
long soed(long a, int b){
  long c;
  long d = 0;
  while(d == 0){
  d=(long)b;}
  c=a*10+d;
  return c;}
/*собирает данные с кнопок, и записывает их в число*/
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
/*узнает длинну первоначального числа. По сути равно колличеству раундов */
int dlinc(long a){
  int b=0;
  while(a!=0){
  b++;
  a/=10;
  }
  return b;
}
/*создает число для раунда, зная номер раунда(= длинна этого числа), и первоначальное число */
long chislodc(int i,long c){
  int b;
  int a=0;
  for (i; i!=0; i--)
  {
  a=a*10+c%10;
  c/=10;
  }
  return a;
}
/*функция перезагрузки программы, на случай если ошибся. Дабы начать игру заново*/
 void (* resetFunc) (void) = 0;
 /*
 это просто комент, чтобы свернуть эту функцию
*/
/*функция проверки чисел.Зная число раунда, и число, которое ввели с клавиатуры.Начнет игру заново, если ошибся */
void prov(long a, long b){
  if(a==b){
  for (int i = 5; i!=0 ;i--){
  digitalWrite(led1, HIGH);
  delay (250);
  digitalWrite(led1, LOW);
  delay (250);
  }}
  else{
  for (int i = 5; i!=0 ;i--){
  digitalWrite(led2, HIGH);
  delay (250);
  digitalWrite(led2, LOW);
  delay (250);
  }
  resetFunc();
  }
}
/*функция переворота числа. Она просто нужна, так как я говнокодер */
long pere(long a){
  long b=0;
  while (a!=0){
  b=b*10+a%10;
  a/=10;
  }
  return b;
}
/*начинается код игры*/
void loop(){
  long a=1212; //Это число, которое мы используем(= последний раунд)!!ВНИМАНИЕ!! максимум 10 цифр(тип LONG). В следующих версиях программы будет больше
  int e=0; //это номер раунда
  int c=dlinc(a); //количество раундов
  long b=0;//число для раунда
  long d=0;//число с кнопок
  for (c;c!=0;c--){ //остчет раундов
    delay(2000); //задержка перед началом раунда
    ++e; //номер раунда каждый раунд прибавляетя +1(логично)
    b=chislodc(e,a); //создание числа для раунда.
    fullmig(b); //промигивание числа раунда
    d=sbor(e); //сбор с кнопок
    d=pere(d); //переворот этого сбора(иначе оно перевернутое)
    prov(b,d); //проверка. Если верно, то следующий раунд
  }
}