# Arduino Internal Temperatura

La mayoria de los nuevos chips AVR (utilizados en el Arduino) incorpora un sensor de temperatura interno adentro del chip que no se usa con frecuencia porque es la temperatura interna del microcontrolador y no del ambiente externo este se puede utilizar como un elemento de seguridad donde se utiliza para evitar un sobrecalentamiento o enfriamento.  


```c++
void setup()
{
  Serial.begin(9600);
  Serial.println("Internal Temperatura Sensor");
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
```

AVR chips que tienen internal temperatura sensor

* ATmega8 : No
* ATmega8L : No
* ATmega8A : No
* ATmega168 : No
* ATmega168A : Yes
* ATmega168P : Yes
* ATmega328 : Yes
* ATmega328P : Yes
* ATmega1280 (Arduino Mega) : No
* ATmega2560 (Arduino Mega 2560) : No
* ATmega32U4 (Arduino Leonardo) : Yes
