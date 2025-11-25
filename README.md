# Arduino
ProyectoClickerGameArduino
#  Juego de Pulso con Arduino - Tinkercad

## Objetivo del proyecto
Este proyecto esta inspirado en el concepto del juego Lucha de Brazos Electronica, donde dos jugadores compiten pulsando botones para empujar una luz hacia el lado opuesto. El objetivo es crear un minijuego dentro del juego de Unity Smack that Rooster. El primero que llega al lado opuesto gana el minijuego.



## Plan de Sprints



| 1 | Crear circuito y conectar LEDs, botones y buzzer  Enciende LEDs y prueba pulsadores en Tinkercard
| 2 | Crear el juego en Unity.
| 3 | Trasladarlo a circuito real con piezas reales.
| 4 | Conectar con unity.




## Bitacora de trabajo (Diario de desarrollo)

| Fecha | Trabajo realizado | Problemas / Decisiones |
|--------|----------------------|-------------------------------|
| 14/11/2025 | Primera version del circuito en Tinkercad. Encendido basico de LEDs. 
| 17/11/2025 | Implementacion logica del juego y movimiento de LED | Delay hacia el juego lento.Migracion a interrupciones con `attachInterrupt()`. Error con `IRAM_ATTR` a eliminado para compatibilidad con UNO|
| 18/11/2025 | Desarollo juego en Unity |
| 19/11/2025 | Desarollo juego en Unity |
| 25/11/2025 | Capturas, documentacion y estructura del repo | Preparacion para entrega |



##Estado actual del proyecto
 Circuito totalmente funcional en Tinkercard 
 Juego Hecho en Unity
 

###  Tareas pendientes / mejoras futuras
- [ ] Montar en fisico y posterior utilizacion en unity
- [ ] Modos de juego y aumento de velocidad progresivo
- [ ] Sonidos personalizados
- [ ] Conectar con Unity




##  Esquema 
Circuito con Arduino, 10 LEDs y 4 pulsadores.
*Capturas disponibles en `/Capturas`
*Codigo disponible en `/Codigos`
*Enlace Proyecto en `/Enlace Tinkercard`



