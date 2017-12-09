//Функции
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
	int sizearr(int *a){
		int d=0;
		while(a[d] != 3){
			d++;
		}
		return d;
	}
	int sborskn(){
		int x=0;
		while (x==0) {
			if (digitalRead(button) == HIGH){
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
			inc=Serial.parseInt();
		}
		return inc;
	}
void mig(int a, int i, int speedp){
		digitalWrite(led, LOW);
		digitalWrite(ledtwo, LOW);
		int t=speedp;
		if(t>200){
			t=t-i*50;
		}
		else{t=200;}
		if (a == 1){
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