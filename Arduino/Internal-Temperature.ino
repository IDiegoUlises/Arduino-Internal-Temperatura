void setup()
{
  Serial.begin(9600);
  Serial.println("Internal Temperature Sensor");
  Serial.println(GetTemp());
}

void loop()
{
}

double GetTemp()
{
  unsigned int wADC;
  double t;

  ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
  ADCSRA |= _BV(ADEN);
  delay(20);
  ADCSRA |= _BV(ADSC);
  while (bit_is_set(ADCSRA, ADSC));
  wADC = ADCW;

  //Convierte a grados Celcius
  t = (wADC - 324.31 ) / 1.22;

  //Devuelve la temperatura
  return (t);
}
