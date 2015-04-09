PNG-Arduino-Framework - Versão Beta 0.1
=====================

Framework com objetivo de facilitar o desenvolvimento de projetos com Arduino

## Como instalar

Baixe os arquivos em https://github.com/ProgrammersOfNewGeneration/PNG-Arduino-Framework/archive/master.zip

Copie todos arquivos .cpp e .h na pasta de cada componente para a mesma pasta de seu arquivo .ino. 

## Como usar

No topo de seu arquivo .ino, adicione a linha
```c++
	#include "motor.h"
```

Crie o objeto motor:

```c++
	Motor *motor = new Motor();
```

Agora, adicione os métodos desejados no **void loop()**, exemplo:
```c++
	motor->irFrente();
	motor->irFrente();
	motor->irDireita();
	motor->irParar();
```

## Comandos disponíveis

**Motor();** - Cria o objeto motor

**Motor(byte m1_a, byte m1_b, byte m1_pwm, byte m2_a, byte m2_b, byte m2_pwm);** - Cria o objeto motor com pinos

**void setPinos(byte m1_a, byte m1_b, byte m1_pwm, byte m2_a, byte m2_b, byte m2_pwm);** - seta valor dos pinos

**void setVelocidade(byte v);** - seta velocidade dos motores - entre 0 e 255

**void setVelocidadeMotor1(byte v);** - seta velocidade do motor 1 - entre 0 e 255

**void setVelocidadeMotor2(byte v);** - seta velocidade do motor 2 - entre 0 e 255

**void irFrente();** - Movimento frente

**void irDireita();** - Movimento direita

**void irDireitaForte();** - Movimento direita forte

**void irEsquerda();** - Movimento esquerda

**void irEsquerdaForte();** - Movimento esquerda forte

**void irRe();** - Movimento ré

**void irParar();** - Parar



## Sobre

Framework para desenvolvimento facilitar o desenvolvimento de projetos com a plataforma Arduino. Foi desenvolvido objetivo proporcionar à FEB e ao CTI na Unesp de Bauru, pesquisas nas áreas de robótica com o microcontrolador Arduino e análise de imagens com Android. 

A Framework está em versão beta, com suporte a:
* Bluetooth
* Motor
* Sensores de luz
* Servo motores
* Ultrassom