# Proyecto-Embebidos-G3
Proyecto correspondiente a la parte práctica de Sistemas Embebidos

Mediante una pantalla LCD y teclado, se realizará el ingreso de la contraseña en que el sistema detectará la clave de acceso a un edificio de departamentos y abrirá la puerta principal si la clave ingresada en correcta. La clave consta de 4 números pulsados uno a continuación del otro, la contraseña es igual para todos los que habiten en el edificio. Si ocurriera un error en cualquiera de los datos ingresados por teclado, se espera hasta el último ingreso y se activa inmediatamente una señal de error, puede ser un y aparecerá en la pantalla ¨Contraseña incorrecta¨. Si se ingresa incorrectamente la contraseña por 3 veces consecutivas se activará un sistema de alarma (Sirena) por un determinado tiempo. 
El acceso estará protegido, ya que en la puerta existirá un sensor (micro interruptor) el cual se activará cuando la puerta está abierta. Suponiendo que el usuario abrió la puerta con la clave, pero al ingresar deja la puerta mal cerrada dicho sensor permanecerá encendido indicando que la puerta continúa abierta. Si la puerta permanece abierta por más de 30 segundos se activará una alarma y se enviará un mensaje a los guardias de la ciudadela.

Las librerías adicionales correspondientes a los códigos son las siguientes:
  - Arduino
  - WiFi
  - WiFiClientSecure
  - UniversalTelegramBot
  - ArduinoJson
  - LiquidCrystal_I2C
  - Keypad
  - Servo
