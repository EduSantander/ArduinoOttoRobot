# Proyecto Otto

Este proyecto fue desarrollado para controlar un robot Otto utilizando un módulo Bluetooth para recibir comandos y realizar diferentes movimientos. El robot Otto también cuenta con sensores ultrasónicos para evitar obstáculos y puede reproducir una melodía a través de un buzzer.

### Requisitos
- Arduino NANO o similar.
- Módulo Bluetooth (pines 10 y 11 para RX/TX).
- Módulo Buzzer (pin 13).
- 4 servomotores para las piernas y pies.
- Sensores ultrasónicos (para los pines definidos en el código).
- Biblioteca de Otto.

### Funcionalidades

- **Conexión Bluetooth**: Permite el control remoto del robot mediante comandos.
- **Evitación de obstáculos**: Usa tres sensores ultrasónicos para detectar obstáculos y modificar la dirección del robot.
- **Reproducción de melodías**: Reproduce "Cumpleaños Feliz" con un buzzer.
- **Movimientos**: El robot puede caminar hacia adelante, atrás, girar, y realizar diferentes bailes.

### Comandos disponibles
- `'a'`: Reproduce la melodía "Cumpleaños Feliz".
- `'b'`: Inicia una secuencia de baile.
- `'c'`: Activa el modo de evitación de obstáculos con sensores ultrasónicos.

### Créditos

Este proyecto fue realizado por estudiantes universitarios pertenecientes al capítulo de **Robotics and Automation Society (RAS), IEEE** de la **Escuela Superior Politécnica del Litoral (ESPOL)** durante el **primer período ordinario de 2024**.
