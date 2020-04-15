# Arduino Internal Temperatura

La mayoria de los nuevos chips AVR (utilizados en el Arduino) incorpora un sensor de temperatura interno a dentro del chip mide la temperatura del microcontrolador y no del ambiente externo este se utiliza para una medicion donde se utiliza para evitar un sobrecalentamiento o enfriamento en condiciones extremas.  

**Obtener la temperatura del microcontrolador**
```c++
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

**AVR chips que incorporan un sensor de temperatura

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

## Temperatura en el Arduino
```El rango de temperatura del Arduino es de -40 a 85 grados centigrados```

* La EEPROM podria no guardar datos durante tiempos prolongados con temperaturas extremas, tenga esto en cuenta si esta almacenando datos criticos.

* El regulador de voltaje puede no funcionar adecuadamente en condiciones de calor.

* El oscilador de cristal puede no producir una frecuencia exacta. Sin embargo, unos pocos hercios mas o menos no afectarian a un procesador de 16 MHz. La tolerancia es del 1% es posible que tenga algunos problemas con el puerto serie (la velocidad en baudios no sera la correcta) cualquier comunicación como I2C funcionaria de manera desincronizadas.

* Las resistencias y condensadores pueden producir los valores no exactos, la tolerancia sera superior al 8%, en resistencias tienen una tolerancia de 5% para temperaturas normales, los condensadores tendrian una mayor tolerancia si aumenta su temperatura lo que puede producir valores del 8% inexactos.

* El enfriamiento y calentamiento extremo puede causar problemas menores de expansión.(está bien de vez en cuando, pero no cada hora disminuyendo 30 grados centigrados).

Por lo tanto, siempre que todos los demas componentes que no estan en la placa arduino funcionen con la temperatura que correspondiente, deberia estar bien.

