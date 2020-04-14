const char digitos[10] = {
  //pgfedcba
  0b00111111, //0
  0b00000110, //1
  0b01011011, //2
  0b01001111, //3
  0b01100110, //4
  0b01101101, //5
  0b01111101, //6
  0b00000111, //7
  0b01111111, //8
  0b01101111 //9
};

#define TIME_REBOTE 100
int p1 = 14, p2 = 15, p3 = 16, p4 = 17;
int a = 6, f = 7, b = 8, e = 9, d = 10, dp = 11, c = 12, g = 13;
int d1 = 2, d2 = 3, d3 = 4, d4 = 5;
int var[4] = {0};
int rebote1, rebote2, rebote3, rebote4;

void setup() {
  pinMode(p1, INPUT_PULLUP);
  pinMode(p2, INPUT_PULLUP);
  pinMode(p3, INPUT_PULLUP);
  pinMode(p4, INPUT_PULLUP);

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

  pinMode(a, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(dp, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {

  display_run();

  pulsadores();

  delay(1);
}

void pulsadores(void) {
  if (!digitalRead(p4)) {
    if (++rebote1 > TIME_REBOTE) {
      rebote1 = 0;
      if (++var[0] > 9) {
        var[0] = 0;
      }
    }
  } else {
    rebote1 = 0;
  }

  if (!digitalRead(p3)) {
    if (++rebote2 > TIME_REBOTE) {
      rebote2 = 0;
      if (++var[1] > 9) {
        var[1] = 0;
      }
    }
  } else {
    rebote2 = 0;
  }

  if (!digitalRead(p2)) {
    if (++rebote3 > TIME_REBOTE) {
      rebote3 = 0;
      if (++var[2] > 9) {
        var[2] = 0;
      }
    }
  } else {
    rebote3 = 0;
  }

  if (!digitalRead(p1)) {
    if (++rebote4 > TIME_REBOTE) {
      rebote4 = 0;
      if (++var[3] > 9) {
        var[3] = 0;
      }
    }
  } else {
    rebote4 = 0;
  }
}

void display_run(void) {
  static int contador = 1;
  display_write(var[contador - 1], contador);
  if (++contador > 4) {
    contador = 1;
  }
}

void display_write(int dato, int digito) {
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
  if (digitos[dato] & (0x01)) {
    digitalWrite(a, HIGH);
  } else {
    digitalWrite(a, LOW);
  }
  if (digitos[dato] & (0x02)) {
    digitalWrite(b, HIGH);
  } else {
    digitalWrite(b, LOW);
  }
  if (digitos[dato] & (0x04)) {
    digitalWrite(c, HIGH);
  } else {
    digitalWrite(c, LOW);
  }
  if (digitos[dato] & (0x08)) {
    digitalWrite(d, HIGH);
  } else {
    digitalWrite(d, LOW);
  }
  if (digitos[dato] & (0x10)) {
    digitalWrite(e, HIGH);
  } else {
    digitalWrite(e, LOW);
  }
  if (digitos[dato] & (0x20)) {
    digitalWrite(f, HIGH);
  } else {
    digitalWrite(f, LOW);
  }
  if (digitos[dato] & (0x40)) {
    digitalWrite(g, HIGH);
  } else {
    digitalWrite(g, LOW);
  }
  if (digitos[dato] & (0x80)) {
    digitalWrite(dp, HIGH);
  } else {
    digitalWrite(dp, LOW);
  }
  switch (digito) {
    case 1:
      digitalWrite(d1, HIGH);
      break;
    case 2:
      digitalWrite(d2, HIGH);
      break;
    case 3:
      digitalWrite(d3, HIGH);
      break;
    case 4:
      digitalWrite(d4, HIGH);
      break;
  }
}
