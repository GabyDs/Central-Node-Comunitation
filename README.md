# Nodo Central - Sistema de Comunicación

Este proyecto implementa el **nodo central de comunicación** para un sistema de robótica basado en **MQTT**.
El nodo central cumple dos funciones principales:

* Actuar como **punto de acceso WiFi** para los demás dispositivos.
* Conectarse a un **broker MQTT** que corre en la PC.

El firmware hasta ahora está orientado únicamente a este nodo central.

---

## Requisitos

### En la PC

* **Linux (probado en Arch)**
* [Mosquitto MQTT Broker](https://mosquitto.org/) para manejar la mensajería.
* [Visual Studio Code](https://code.visualstudio.com/) con la extensión [PlatformIO](https://platformio.org/).

Instalación rápida en Arch/Manjaro:

```bash
sudo pacman -S mosquitto mosquitto-clients
```

---

### En el nodo central (ESP32)

* Librerías necesarias en `platformio.ini`:

```ini
lib_deps =
  mlesniew/PicoMQTT@^1.3.0
```

---

## Configuración

1. Configurar Mosquitto en la PC editando el archivo de configuración:

   ```conf
   listener 1883
   allow_anonymous false
   password_file /etc/mosquitto/mosquitto_password_file
   ```

2. Crear usuario y contraseña para acceso al broker:

   ```bash
   sudo mosquitto_passwd -c /etc/mosquitto/mosquitto_password_file <usuario>
   sudo systemctl restart mosquitto
   ```

3. Configurar el ESP32 como **Access Point** en el código (`main.cpp`).

---

## Ejecución

1. Levantar broker en la PC:

   ```bash
   sudo systemctl start mosquitto
   ```
2. Compilar y cargar el firmware en el ESP32 usando PlatformIO desde Visual Studio Code.
3. Conectar la PC al Access Point del ESP32.