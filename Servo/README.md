PNG-Arduino-Framework - Versão Beta 0.1
=====================

Framework com objetivo de facilitar o desenvolvimento de projetos com Arduino

## Como instalar

Baixe os arquivos em https://github.com/ProgrammersOfNewGeneration/PNG-Arduino-Framework/archive/master.zip

Copie todos arquivos .cpp e .h na pasta de cada componente para a mesma pasta de seu arquivo .ino. 

## Como usar

No topo de seu arquivo .ino, adicione a linha
```c++
	#include "obj_servo.h"
```

Crie o objeto servo:

```c++
	ObjServo *servo = new ObjServo();
```
Adicione no **void setup()** para configurar o servo:
```c++
	servo->configura();
```

Agora, adicione os métodos desejados no **void loop()**, exemplo:
```c++
	servo->girar(90);
```

## Comandos disponíveis

**ObjServo();** - Cria ObjServo

**ObjServo(int P);** - Cria ObjServo com número do pino

**void setPin(int P);** - seta o pino do servo

**int getPin();** - retorna o pino do servo

**void girar(int d);** - gira para o ângulo desejado

**void configura();** - Configura e inicia o servo





## Sobre

Framework para desenvolvimento facilitar o desenvolvimento de projetos com a plataforma Arduino. Foi desenvolvido objetivo proporcionar à FEB e ao CTI na Unesp de Bauru, pesquisas nas áreas de robótica com o microcontrolador Arduino e análise de imagens com Android. 

A Framework está em versão beta, com suporte a:
* Bluetooth
* Motor
* Sensores de luz
* Servo motores
* Ultrassom