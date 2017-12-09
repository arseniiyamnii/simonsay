//Вступление
	#include "var.h"
	void setup() {
		pinMode(led, OUTPUT);
		pinMode(button, INPUT);
		pinMode(ledtwo, OUTPUT);
		pinMode(buttontwo, INPUT);
		Serial.begin(9600);
		randomSeed(analogRead(0));
		}
//Прога
	void loop(){
		/*начало поднастройки программы
			в настройке должны менятся:
			1.кол-во раундов
			2.скорость промигивания(несколько вариантов)
			3.время между раундами(несколько вариантов)*/
			int time=10000;
			int rtime=0;
			int kolr=11;
			int speedp=1000;
			int speedr=2000;
			while (rtime<time){
				rtime=millis();
				if (Serial.available()>0){
					rtime=0;}
				if (Serial.available()>0){
					rtime=0;
					Serial.flush();
					while(rtime==0){
						Serial.flush();
						Serial.println("Добро пожаловать в интерфейс редактирования игры!");
						Serial.println("Веедите номер настройки, которую хотите изменить");
						Serial.println("1 - Изменение кол-ва раундов");
						Serial.println("2 - Изменение скорости промигивания лампочек");
						Serial.println("3 - Изменение промежутка между раундами");
						Serial.println("4 - Выход из настройки");
						Serial.println("Жду команды");
						Serial.println("----------------------------");
						int a=sborc();
						int b=0;
						Serial.flush();
						if (a==1){//команда изменения раундов
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
						if (a==2){//команда изменения скорости промигивания
							Serial.println("Вы выбрали команду изменения скорости промигивания диодов");
							Serial.println("Сейчас режим с ускорением");
							Serial.println("Скорости начинается от 1с. и минимум который может быть,");
							Serial.println("это 0.25с.");
							Serial.println("Напишите свою скорость с которой начинать");
							b=0;
							while(b==0){
								b=sborc();
							}
							speedp=b;
							Serial.print("Теперь скорость будет ");
							Serial.print(speedp/1000);
							Serial.println(" секунд");
						}
						if (a==3){//команда изменения скорости раундов
						Serial.println("Настройка промежутка между раундами");
						Serial.println("По умолчанию промежуток 2с");
						Serial.println("Напиши свой вариант");
						b=0;
						while(b==0){
							b=sborc();
						}
						speedr=b;
						Serial.print("Теперь промежуток равен ");
						Serial.print(speedr/1000);
						Serial.println(" секунд");
						}
						if (a==4){//команда изменения скорости раундов
							Serial.println("Вы выбрали выход из настройки");
							Serial.println("Вы уверенны?");
							Serial.println("1=да");
							Serial.println("2=нет");
							b=0;
							while(b==0){
								b=sborc();
							}
							if (b==2){
								Serial.println("Продолжение настройки");
							}
							if (b==1){
								Serial.println("начинаем игру через 3 секунды");
								delay(3000);
								Serial.flush();
								rtime=20000;
							}
						}
					}
				}
			}
		//окончание поднастройки, и начало игры
			int d=kolr;
			int a[d];
			int cif=0;
			for (int q = 0; q < d; ++q){
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
				for (int k = 0; k < i; ++k){
					ch[k]=a[k];
				}
				//промигаем это число
				int *chuk=ch;
				fullmig(chuk,i,speedp);
				//начинаем сбор с кнопок
				int sb[i];
				for (int k = 0; k < i; ++k){
					sb[k]=sborskn();
				}
				//начинаем сравнение их
				int ans = 1;
				for (int k = 0; k < i; ++k){
					if(ch[k]!=sb[k]){
						ans=0;
					}
				}
				prov(ans,i);
				++i;
			}
	}