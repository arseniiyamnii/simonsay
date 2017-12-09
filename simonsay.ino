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
	   void setup() {
	   pinMode(led, OUTPUT);
	   pinMode(button, INPUT);
	   pinMode(ledtwo, OUTPUT);
	   pinMode(buttontwo, INPUT);
	   Serial.begin(9600);
	   randomSeed(analogRead(0));
		}
/*
Реально нужные функции
 */
	void mig(int a, int i, int speedp){
	  digitalWrite(led, LOW);
	  digitalWrite(ledtwo, LOW);
	  int t=speedp;
	  if(t>200){
		t=t-i*50;
	  }
	  else{t=200;}
	  if (a == 1) {
		delay(t);
		digitalWrite(led, HIGH);
		delay(t);
		digitalWrite(led, LOW);
		
	  }
	  if (a == 2){
		delay(t);
		digitalWrite(ledtwo, HIGH);//
		delay(t);
		digitalWrite(ledtwo, LOW);
	  }
	}
	void fullmig(int *a, int i, int speedp){
	  int b=0;
	  int c=0;
	  int d=0;
	  while(b!=i){
		c=a[b];
		mig(c,i,speedp);
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
	сбор с кнопок
	 */
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
	/*
	Проверка
	 */
	void (* resetFunc) (void) = 0;
	void prov(int a, int t){
		int tm=285;
		if (tm>75){
			tm=tm-t*35;
		}
		if(a==1){
		  for (int p = 5; p!=0 ;p--){
			digitalWrite(led, HIGH);
			delay (tm);
			digitalWrite(led, LOW);
			delay (tm);
		  }
		}
		else{
		  for (int p = 5; p!=0 ;p--){
			digitalWrite(ledtwo, HIGH);
			delay (tm);
			digitalWrite(ledtwo, LOW);
			delay (tm);
		  }
		 resetFunc();
		}
	  }
	  int sborc(){
		int inc = 0;
		while(inc==0){
		inc=Serial.parseInt();}
		return inc;
	  }
	/*
	начало проги
	 */
void loop()
{
	//начало поднастройки программы
		//в настройке должны менятся:
		//1.кол-во раундов
		//2.скорость промигивания(несколько вариантов)
		//3.время между раундами(несколько вариантов)
  int time=10000;
  int rtime=0;
  int kolr=11;
  int speedp=1000;
  int speedr=2000;
  while (rtime<time)
  {
	rtime=millis();
	if (Serial.available()>0)
		{
	rtime=0;
	Serial.flush();
		}
	while(rtime==0){
		Serial.flush();
		Serial.println("Добро пожаловать в интерфейс редактирования игры!");
		Serial.println("Веедите номер настройки, которую хотите изменить");
		Serial.println("1 - Изменение кол-ва раундов");
		Serial.println("2 - Изменение скорости промигивания лампочек");
		Serial.println("3 - Изменение промежутка между раундами");
			Serial.println("Жду команды");
			Serial.println("----------------------------");
			int a=sborc();
			int b=0;
			Serial.flush();
			if (a==1)//команда изменения раундов
			{
				Serial.println("Вы выбрали ИЗМЕНЕНИЕ КОЛ-ВА РАУНДОВ");
				Serial.println("Автоматически стоит настройка 10 раундов");
				Serial.println("Чтобы ее не менять, напиши 10");
				Serial.println("Просто напиши число раундов");
				Serial.println("Жду");
				Serial.println("-----------------------------");
				b=0;
				while(b==0){
				b=sborc();}
				kolr=b+1;
				Serial.println("теперь в игре будет ");
				Serial.print(b);
				Serial.println(" раундов");
			}
			if (a==2)//команда изменения скорости промигивания
			{
				Serial.println("Вы выбрали команду изменения скорости промигивания диодов");
				Serial.println("Сейчас режим с ускорением");
				Serial.println("Скорости начинается от 1с. и минимум который может быть,");
				Serial.println("это 0.25с.");
				Serial.println("Напишите свою скорость с которой начинать");
				b=0;
				while(b==0){
				b=sborc();}
				speedp=b;
				Serial.print("Теперь скорость будет ");
				Serial.print(speedp/1000);
				Serial.println(" секунд");
			}
			if (a==3)//команда изменения скорости раундов
			{
				Serial.println("Настройка промежутка между раундами");
				Serial.println("По умолчанию промежуток 2с");
				Serial.println("Напиши свой вариант");
				b=0;
				while(b==0){
				b=sborc();}
				speedr=b;
				Serial.print("Теперь промежуток равен ");
				Serial.print(speedr/1000);
				Serial.println(" секунд");
			}
			if (a==4)//команда изменения скорости раундов
			{
				Serial.println("Вы выбрали выход из настройки");
				Serial.println("Вы уверенны?");
				Serial.println("1=да");
				Serial.println("2=нет");
				b=0;
				while(b==0){
				b=sborc();}
				if (b==0)
				{
					Serial.println("Продолжение настройки");
				}
				if (b==1)
				{
					Serial.println("начинаем игру через 3 секунды");
					delay(3000);
					Serial.flush();
					rtime=20000;
				}
			}
			}
  }
  //окончание поднастройки, и начало игры
  int d=kolr;
  int a[d];
  int cif=0;
  for (int q = 0; q < d; ++q)
  {
	cif=0;
	cif=random(1, 3);
	a[q]=cif;
	cif=0;
  }
  int i=1;//тут начинается отсчет раундов
  while(i<d){
	delay(speedr);
	//собираем число для раунда
	int ch[i];
	for (int k = 0; k < i; ++k)
	{
	  ch[k]=a[k];
	}
	//промигаем это число
	int *chuk=ch;
	fullmig(chuk,i,speedp);
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
	prov(ans,i);
	++i;}
}
 ////временно(проверяю, не выходит ли из цикла).
