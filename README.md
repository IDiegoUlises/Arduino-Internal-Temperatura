# Arduino Internal Temperatura

La mayoria de los nuevos chips AVR (utilizados en el Arduino) incorpora un sensor de temperatura interno a dentro del chip mide la temperatura del microcontrolador y no del ambiente externo este se utiliza como una medicion donde se utiliza para evitar un sobrecalentamiento o enfriamento en condiciones extremas.  


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

## Rango de temperatura del Arduino
**Rango de temperatura del Arduino es de -40º a 85 grados centigrados**

Sin embargo, hay algunas cosas que pueden salir mal:

* La EEPROM podría no almacenarse tanto tiempo en temperaturas extremas. Tenga esto en cuenta si está almacenando datos críticos.

* El regulador de voltaje puede no funcionar tan bien en condiciones de calor.

* El oscilador de cristal puede no producir valores exactos. Sin embargo, me imagino que unos pocos hercios más o menos no afectarían a un procesador de 16 MHz. La tolerancia es en realidad un poco menos del 1%. Es posible que tenga algunos problemas con la serie (la velocidad en baudios no es correcta). Me gustaría ver en cualquier comunicación como I2C también. (No sé exactamente cómo funciona la línea del reloj ... podría estar bien para I2C).

* Las resistencias / condensadores pueden no producir los valores exactos . Me imagino que la tolerancia no será superior al 8% en resistencias: la mayoría de las resistencias tienen una clasificación de 5% para temperaturas normales. Depende del fabricante. Los condensadores tienen una mayor tolerancia, pero su objetivo principal es "suavizar" una señal.

* El enfriamiento / calentamiento extremo puede causar problemas menores de expansión. (Nota: está bien de vez en cuando, pero no cada hora bajando 30 grados).

* También se deben tener en cuenta otros componentes (LCD, etc.) cuando se observa la viabilidad de mantenerlo al aire libre.

por lo tanto, siempre que todos los demás componentes que no están en la placa funcionen con la temperatura que necesita, debería estar bien. Además, como con toda la ingeniería, los valores a menudo tienen un "relleno" incorporado (es decir, la tolerancia del 5% es a menudo del 3-4%, el máximo de 12V puede ejecutarse en 12.5V, etc.)

Lo que quiero decir con eso es que tu Arduino no explotará cuando esté a -41 grados C. No es bueno para eso, pero lo más probable es que estés bien siempre y cuando no sea algo habitual.
